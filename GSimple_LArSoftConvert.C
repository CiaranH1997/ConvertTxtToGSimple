#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
#include "TFile.h"
#include "TTree.h"
#include "TRandom3.h"
#include "GSimpleNtpEntry.h"
#include "GSimpleNtpMeta.h"
#include "NeutrinoFileID.h"

// Executable for converting flux text files to GSimple files that are compatible with GENIE in LArSoft

using namespace genie::flux;

std::vector<GSimpleNtpEntry> readGsimpleFile(const std::string& filename, int pdg, 
    double &targetPOT, const NeutrinoFileID &scaled_fileID, int metakey_allfiles = -1) {
 
  double pot_weight = targetPOT * scaled_fileID.br / scaled_fileID.pot;

  std::vector<GSimpleNtpEntry> neutrinos;
  std::ifstream infile(filename);
  std::string line;

  std::cout << ">>> PDG = " << pdg << std::endl;

  // Generate a metakey if it has not been set in argument
  if (metakey_allfiles < 0) {
    TRandom3 *rand = new TRandom3(0);
    auto random_metakey = rand->Rndm() * 1000;
    metakey_allfiles = (int)random_metakey;
    delete rand;
  }

  int nEvents(0);
  std::cout << "readGsimpleFile: Max events for " << scaled_fileID.decay_mode << " = " << scaled_fileID.nevents * pot_weight << std::endl;
  while (std::getline(infile, line) && nEvents <= scaled_fileID.nevents * pot_weight) {
    if (line.empty() || line[0] == '#') {
      continue; // Skip comments and empty lines
    }

    // Count number of events
    nEvents++;

    std::istringstream iss(line);
    GSimpleNtpEntry nu;
    iss >> nu.haddec_x >> nu.haddec_y >> nu.haddec_z >> nu.px >> nu.py >> nu.pz >> nu.E >> nu.theta 
      >> nu.phi >> nu.br_p >> nu.pot_f >> nu.xd >> nu.yd >> nu.zd >> nu.vtxx >> nu.vtxy >> nu.vtxz;
    nu.pdg = pdg;
    // Should I be doing something with the weights? Like weighting for the branching ratio? Probably...
    nu.wgt = 1.;

    double POT_b = nu.pot_f;
    nu.pot_f = targetPOT;
    
    // New window placed at 718.9
    nu.dist = 718.9 - nu.haddec_z;

	  nu.metakey = metakey_allfiles;
    neutrinos.push_back(nu);
    if (nEvents == scaled_fileID.nevents * pot_weight) {
      std::cout << "reached max events: " << nEvents << std::endl;
      std::cout << "pot BEFORE = " << POT_b << ", pot AFTER = " << nu.pot_f << std::endl;
    }
  }
  return neutrinos;
}

GSimpleNtpMeta buildFileMetaData(const std::string& filename, const std::vector<GSimpleNtpEntry>& neutrinos) {

  GSimpleNtpMeta ret;

  std::vector<double> vE;
  std::vector<double> vWgt;
  for (const auto& n : neutrinos) {
    vE.push_back(n.E);
    vWgt.push_back(n.wgt);
  }

  ret.pdglist.push_back(12);
  ret.pdglist.push_back(14);
  ret.pdglist.push_back(-12);
  ret.pdglist.push_back(-14);
  ret.maxEnergy = *std::max_element(vE.begin(), vE.end());
  ret.minWgt = *std::min_element(vWgt.begin(), vWgt.end());
  ret.maxWgt = *std::max_element(vWgt.begin(), vWgt.end());
  vE.clear();
  vWgt.clear();
  ret.protons = neutrinos.at(0).pot_f;
  // ### Start Flux Window ###
  // Guess a flux window (det. coordinates)
  // window of (w+3)*(h+3) m² placed at 0 of LArSoft reference frame.
  // Assume that all the neutrinos are already perpendicular to detector front face - this 
  // means that the flux window is parallel to detector front face - maybe an okay assumption
  ret.windowBase[0] = 5.;
  ret.windowBase[1] = -1.5;
  ret.windowBase[2] = 0.;
  ret.windowDir1[0] = 5.;
  ret.windowDir1[1] = 7.5;
  ret.windowDir1[2] = 0.;
  ret.windowDir2[0] = -5;
  ret.windowDir2[1] = -1.5;
  ret.windowDir2[2] = 0.;
  // #### End Flux Window ###
  ret.infiles.push_back(filename);
  ret.metakey = neutrinos.at(0).metakey;

  return ret;
}

void writeRootFile(const std::string& filename, const std::vector<GSimpleNtpEntry>& neutrinos, GSimpleNtpMeta& meta) {
  TFile* file = new TFile(filename.c_str(), "RECREATE");
    
  TTree* tree = new TTree("flux", "Neutrino Flux");
  TTree* metatree = new TTree("meta", "Flux Meta Data"); 
  tree->SetDirectory(0);
  metatree->SetDirectory(0);

  GSimpleNtpEntry entry;
  tree->Branch("entry", &entry);

  for (const auto& n : neutrinos) {
    entry = n;
    tree->Fill();
  }

  metatree->Branch("meta", &meta);
  metatree->Fill();

  tree->Write();
  metatree->Write();
  file->Close();
}

void writeRootFile(const std::string& filename, const std::vector<std::string>& voutfiles, const std::vector<std::vector<GSimpleNtpEntry>>& neutrinos, const std::vector<GSimpleNtpMeta>& metas) {
  
  size_t found_last_slash = filename.find_last_of("/");
  std::string substr_filename = filename.substr(0, found_last_slash+1);
  
  for (int i = 0; i < (int)voutfiles.size(); i++) { 

    std::string filepath = substr_filename + voutfiles.at(i);
    std::cout << "outfile = " << filepath << std::endl;

    TFile* file = new TFile(filepath.c_str(), "RECREATE");
    
    TTree* tree = new TTree("flux", "Neutrino Flux");
    TTree* metatree = new TTree("meta", "Flux Meta Data"); 

    GSimpleNtpEntry entry;
    tree->Branch("entry", &entry);

    for (const auto& n : neutrinos.at(i)) {
      entry = n;
      tree->Fill();
    }

    GSimpleNtpMeta meta;
    metatree->Branch("meta", &meta);
    meta = metas.at(i);
    metatree->Fill();

    tree->Write();
    metatree->Write();
    file->Close();
  }
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << "wobbling_code output.root input1.gsimple [input2.gsimple ... inputN.gsimple]" << std::endl;
    return 1;
  }

  std::string wobbling_code = argv[1];
  if (wobbling_code != "000" && wobbling_code != "133" && wobbling_code != "np04") {
    std::cout << "[ERROR] wobbling configuration code not recognised. Must be 000, 133 or np04." << std::endl;
    return 1;
  }

  std::string outputFilename = argv[2];
  if (outputFilename.find(".root") == std::string::npos) {
		std::cout << "[ERROR] Must output root file." << std::endl;
		return 1;
	}
   
  size_t found_last_slash = outputFilename.find_last_of("/");
  std::string substr_outputFilename = outputFilename.substr(found_last_slash+1);
  std::cout << "substr_outputFilename = " << substr_outputFilename << std::endl;

  size_t found_wobblingconf = substr_outputFilename.find(wobbling_code);
  if (found_wobblingconf != std::string::npos) {
    std::cout << ">>> Found file with wobbling configuration " << wobbling_code << std::endl;
  } else {
    std::cout << ">>> Not correct wobbling configuration." << std::endl;
    return 0;
  }
  
  // First get factors for POT per file correction
  std::vector<NeutrinoFileID> vNuFileIDs;
  for (int i = 3; i < argc; ++i) {
    std::string inputFilename = argv[i];
	  if (inputFilename.find(".txt") == std::string::npos) {
	    std::cout << "[ERROR] Must input txt file." << std::endl;
		  return 1;
		}
	  std::cout << "READING: " << inputFilename << std::endl;
	
    NeutrinoFileID inputfileid;
    inputfileid.initialize_fileid(inputFilename);

    if (inputfileid.initialised) {
      vNuFileIDs.push_back(inputfileid);
    } else {
      std::cout << "[WARNING] NeutrinoFileID object not initialised." << std::endl;
    }
    std::cout << "Number events in file " << inputfileid.filepath << " = " << inputfileid.nevents << std::endl
      << "POT in file = " << inputfileid.pot << ", PDG = " << inputfileid.pdg << std::endl;
  }

  // Scale the number of events in each file down to the min # events
  // Then scale the POT in each file to match
  auto fMinNEvents = *std::min_element(vNuFileIDs.begin(), vNuFileIDs.end(), [](const auto &lhs, const auto &rhs) {
      return lhs.nevents < rhs.nevents;
      });

  auto fMinFilePOT = *std::min_element(vNuFileIDs.begin(), vNuFileIDs.end(), [](const auto &lhs, const auto &rhs) {
      return lhs.pot < rhs.pot;
      });
  
  std::cout << "fMinNEvents for decay mode " << fMinNEvents.decay_mode << " = " << fMinNEvents.nevents << std::endl;
  std::cout << "fMinFilePOT for decay mode " << fMinFilePOT.decay_mode << " = " << fMinFilePOT.pot << std::endl;
  
  // Use fMinNEvents and vFilePOTScalingFactors to have a consistent number of
  // flux rays and POT across all flux input files

  std::vector<GSimpleNtpEntry> allNeutrinos;

  int filenum(0);
  // Generate a metakey
  TRandom3 *rand = new TRandom3(0);
  auto random_metakey = rand->Rndm() * 1000;
  int metakey_allfiles = (int)random_metakey;
  delete rand;
  
  for (int i = 3; i < argc; ++i) {
    std::string inputFilename = argv[i];
	  if (inputFilename.find(".txt") == std::string::npos) {
	    std::cout << "[ERROR] Must input txt file." << std::endl;
		  return 1;
		}
	  std::cout << "READING: " << inputFilename << std::endl;
    
    std::string outfile = "gsimple_" + std::to_string(vNuFileIDs.at(filenum).pdg) + "_" + vNuFileIDs.at(filenum).decay_mode + "_wnp04.root";

    std::vector<GSimpleNtpEntry> neutrinos = readGsimpleFile(inputFilename, vNuFileIDs.at(filenum).pdg, 
        fMinFilePOT.pot, vNuFileIDs.at(filenum), metakey_allfiles);
    allNeutrinos.insert(allNeutrinos.end(), neutrinos.begin(), neutrinos.end());

    filenum++;
  }
    
  GSimpleNtpMeta totalMeta = buildFileMetaData("total", allNeutrinos);

  writeRootFile(outputFilename, allNeutrinos, totalMeta);

  return 0;
}

