#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <random>
#include <utility>
#include "TFile.h"
#include "TTree.h"
#include "TRandom3.h"
#include "GSimpleNtpEntry.h"
#include "GSimpleNtpMeta.h"
#include "NeutrinoFileID.h"

// Executable for converting flux text files to GSimple files that are compatible with GENIE in LArSoft

using namespace genie::flux;

std::vector<GSimpleNtpEntry> readGsimpleFile(const NeutrinoFileID &scaled_fileID, 
    double &targetPOT, int metakey_allfiles = -1) {

  // The important weighting!
  // targetPOT = the smallest POT out of all the input flux files
  // br is the branching ratio of the hadronic parent
  // pot is the POT of the file that is being read
  double pot_weight = targetPOT * scaled_fileID.br / scaled_fileID.pot;

  std::vector<GSimpleNtpEntry> neutrinos;
  std::ifstream infile(scaled_fileID.filepath);
  std::string line;

  std::cout << ">>> PDG = " << scaled_fileID.pdg << std::endl;

  // Generate a metakey if it has not been set in argument
  if (metakey_allfiles < 0) {
    TRandom3 *rand = new TRandom3(0);
    auto random_metakey = rand->Rndm() * 1000;
    metakey_allfiles = (int)random_metakey;
    delete rand;
  }

  std::cout << "readGsimpleFile: Max events for " << scaled_fileID.decay_mode << " = " << scaled_fileID.nevents * pot_weight << std::endl;
  
  while (std::getline(infile, line)) {
    if (line.empty() || line[0] == '#') {
      continue; // Skip comments and empty lines
    }

    std::istringstream iss(line);
    GSimpleNtpEntry nu;
    iss >> nu.haddec_x >> nu.haddec_y >> nu.haddec_z >> nu.px >> nu.py >> nu.pz >> nu.E >> nu.theta 
      >> nu.phi >> nu.br_p >> nu.pot_f >> nu.xd >> nu.yd >> nu.zd >> nu.vtxx >> nu.vtxy >> nu.vtxz;
    nu.pdg = scaled_fileID.pdg;
    // Assign each neutrino a weight based on POT and branching ratio
    nu.wgt = pot_weight;

    double POT_b = nu.pot_f;
    nu.pot_f = targetPOT;
    
    // New window placed at 718.9
    nu.dist = 718.9 - nu.haddec_z;

	  nu.metakey = metakey_allfiles;
    neutrinos.push_back(nu);
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

// Function to shuffle the neutrinos randomly and split them up into nsplit files for writing
// Too many neutrinos for ROOT TTree buffer without this splitting
std::vector<std::vector<GSimpleNtpEntry>> shuffleAndSplitNeutrinos(std::vector<GSimpleNtpEntry> neutrinos, int nsplit = 1) {

  auto rng = std::default_random_engine {};
  std::shuffle(std::begin(neutrinos), std::end(neutrinos), rng);

  int filesize = (int)neutrinos.size() / nsplit;

  int nu(0);

  std::vector<std::vector<GSimpleNtpEntry>> ret;

  for (int i = 0; i < nsplit; i++) {

    std::vector<GSimpleNtpEntry> split_neutrinos;
    
    while (split_neutrinos.size() < filesize && nu < (int)neutrinos.size()) {
      split_neutrinos.emplace_back(neutrinos.at(nu));
      // get a unique metakey for each split file....
      split_neutrinos.back().metakey += i;
      // Account for the fact you have split up the neutrinos in to nsplit files
      // This is because GENIE weights by 1/nfiles - so correct for this in advance
      split_neutrinos.back().wgt *= nsplit;
      nu++;
    }
    std::cout << "At neutrino " << nu << " out of " << (int)neutrinos.size() << std::endl;
    ret.push_back(split_neutrinos);

  }
  if (nu < (int)neutrinos.size()) {
    while (nu < (int)neutrinos.size()) {
      ret.back().emplace_back(neutrinos.at(nu));
      nu++;
    }
  }
  std::cout << "Ret split nu v size = " << ret.size() << std::endl;
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

// Main executable function
int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cerr << "Usage: " << argv[0] << "wobbling_code output.root noutputs input1.gsimple [input2.gsimple ... inputN.gsimple]" << std::endl;
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

  std::istringstream ss(argv[3]);
  int noutputs;
  if (!(ss >> noutputs)) {
      std::cout << "[ERROR] Invalid number: " << argv[3] << '\n';
  } else if (!ss.eof()) {
      std::cerr << "[ERROR] Trailing characters after number: " << argv[3] << '\n';
  } else {
    std::cout << "Will split " << outputFilename << " into " << noutputs << " output files." << std::endl;
  }
  
  // First get factors for POT per file correction
  std::vector<NeutrinoFileID> vNuFileIDs;
  for (int i = 4; i < argc; ++i) {
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
      // Need to double contribution from neutral hadrons for anti-neutrinos
      if (inputfileid.pdg == 12 && (inputfileid.decay_mode == "130_3body" || inputfileid.decay_mode == "310_3body")) {
        std::cout << "Copying " << inputfileid.pdg << " decay mode " << inputfileid.decay_mode << std::endl;
        NeutrinoFileID inputfileid_nubar_copy = inputfileid;
        inputfileid_nubar_copy.pdg = -12;
        vNuFileIDs.push_back(inputfileid_nubar_copy);
      } else if (inputfileid.pdg == 14 && (inputfileid.decay_mode == "130_3body" || inputfileid.decay_mode == "310_3body")) {
        std::cout << "Copying " << inputfileid.pdg << " decay mode " << inputfileid.decay_mode << std::endl;
        NeutrinoFileID inputfileid_nubar_copy = inputfileid;
        inputfileid_nubar_copy.pdg = -14;
        vNuFileIDs.push_back(inputfileid_nubar_copy);
      }
    } else {
      std::cout << "[WARNING] NeutrinoFileID object not initialised." << std::endl;
    }
  }

  for (const auto &fileid : vNuFileIDs) {
    std::cout << ">>> Neutrino File IDs." << std::endl;
    std::cout << fileid;
  }

  // Scale the number of events in each file down to the min # events
  // Then scale the POT in each file to match
  auto fMinFilePOT = *std::min_element(vNuFileIDs.begin(), vNuFileIDs.end(), [](const auto &lhs, const auto &rhs) {
      return lhs.pot < rhs.pot;
      });
  
  std::cout << "fMinFilePOT for decay mode " << fMinFilePOT.decay_mode << " = " << fMinFilePOT.pot << std::endl;

  // Single massive vector for all neutrino rays
  std::vector<GSimpleNtpEntry> allNeutrinos;

  // Generate a metakey
  TRandom3 *rand = new TRandom3(0);
  auto random_metakey = rand->Rndm() * 1000;
  int metakey_allfiles = (int)random_metakey;
  delete rand;
 
  // Go through each of the input file IDs
  // (includes the re-used neutral hadrons for anti neutrinos)
  for (const auto &fileid : vNuFileIDs) {
    std::vector<GSimpleNtpEntry> neutrinos = readGsimpleFile(fileid, 
        fMinFilePOT.pot, metakey_allfiles);
    allNeutrinos.insert(allNeutrinos.end(), neutrinos.begin(), neutrinos.end());
  }

  // Split up allNeutrinos into smaller vectors for writing
  // ROOT TTree buffer cannot handle trees as large as allNeutrinos
  auto vSplitNeutrinos = shuffleAndSplitNeutrinos(allNeutrinos, noutputs);
  // Get metadata for each of split neutrino samples
  std::vector<GSimpleNtpMeta> vMetaData;
  for (const auto &snu : vSplitNeutrinos) {
    GSimpleNtpMeta splitMeta = buildFileMetaData("total", snu);
    vMetaData.push_back(splitMeta);
  }

  if ((int)vMetaData.size() != noutputs) {
    std::cout << "[ERROR] number of meta objects should match number of output files." << std::endl;
    return 1;
  }

  // for each of the sub groups of neutrinos, write an output file
  for (int i = 0; i < (int)vMetaData.size(); i++) {
    
    size_t found_last_slash = outputFilename.find_last_of("/");
    size_t found_last_dot = outputFilename.find_last_of(".");
    
    std::string substr_outputFilename = outputFilename.substr(found_last_slash + 1);
    std::string substr_outputFilename_noroot = substr_outputFilename.substr(0, substr_outputFilename.length() - 5);
    std::string substr_outpath = outputFilename.substr(0, found_last_slash + 1);

    // Get final output file name
    std::string output_sub_file = substr_outpath + substr_outputFilename_noroot + "_" + std::to_string(i) + ".root";
   
    std::cout << "Outputting: " << output_sub_file << std::endl;

    writeRootFile(output_sub_file, vSplitNeutrinos.at(i), vMetaData.at(i)); 
  }

  return 0;
}

