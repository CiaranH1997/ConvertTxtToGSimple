#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h> 
#include "TFile.h"
#include "TTree.h"
#include "TRandom3.h"
#include "GSimpleNtpEntry.h"
#include "GSimpleNtpMeta.h"

// Executable for converting flux text files to GSimple files that are compatible with GENIE in LArSoft

// A lot of assumptions used to get creat a flux window and assess the vtx position of the neutrino ray
// origin on that flux window.

using namespace genie::flux;

std::vector<GSimpleNtpEntry> readGsimpleFile(const std::string& filename, int pdg) {
  std::vector<GSimpleNtpEntry> neutrinos;
  std::ifstream infile(filename);
  std::string line;

  // Generate a metakey
  TRandom3 *rand = new TRandom3(0);
  auto random_metakey = rand->Rndm() * 1000;
  delete rand;

  while (std::getline(infile, line)) {
    if (line.empty() || line[0] == '#') {
      continue; // Skip comments and empty lines
    }

    std::istringstream iss(line);
    GSimpleNtpEntry nu;
    iss >> nu.haddec_x >> nu.haddec_y >> nu.haddec_z >> nu.px >> nu.py >> nu.pz >> nu.E >> nu.theta >> nu.phi >> nu.br_p >> nu.pot_f >> nu.xd >> nu.yd >> nu.zd >> nu.vtxx >> nu.vtxy >> nu.vtxz;
    nu.pdg = pdg;
    // Should I be doing something with the weights? Like weighting for the branching ratio? Probably...
    nu.wgt = nu.br_p;
    // New window placed at 718.9
    nu.dist = 718.9 - nu.haddec_z;

	  nu.metakey = (int)random_metakey;
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

void writeRootFile(const std::string& filename, const std::vector<GSimpleNtpEntry>& neutrinos, const std::vector<GSimpleNtpMeta>& metas) {
  TFile* file = new TFile(filename.c_str(), "RECREATE");
    
  TTree* tree = new TTree("flux", "Neutrino Flux");
  TTree* metatree = new TTree("meta", "Flux Meta Data"); 

  GSimpleNtpEntry entry;
  tree->Branch("entry", &entry);

  for (const auto& n : neutrinos) {
    entry = n;
    tree->Fill();
  }

  GSimpleNtpMeta meta;
  metatree->Branch("meta", &meta);
  for (const auto& m : metas) {
    meta = m;
    metatree->Fill();
  }

  tree->Write();
  metatree->Write();
  file->Close();
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
  
  std::vector<GSimpleNtpEntry> allNeutrinos;
    
  std::vector<GSimpleNtpMeta> allMeta;

  for (int i = 3; i < argc; ++i) {
    std::string inputFilename = argv[i];
	  if (inputFilename.find(".txt") == std::string::npos) {
	    std::cout << "[ERROR] Must input txt file." << std::endl;
		  return 1;
		}
	  std::cout << "READING: " << inputFilename << std::endl;
		size_t found_numu = inputFilename.find("14");
		size_t found_nue = inputFilename.find("12");
		size_t found_numubar = inputFilename.find("-14");
		size_t found_nuebar = inputFilename.find("-12");
		int pdg(-999);
		if (found_numu != std::string::npos) {
	    std::cout << "Numu flavour." << std::endl;
			pdg = 14;
		} else if (found_nue != std::string::npos) {
			std::cout << "Nue flavour." << std::endl;
			pdg = 12;
		} else if (found_numubar != std::string::npos) {
	    std::cout << "Numubar flavour." << std::endl;
			pdg = -14;
		} else if (found_nuebar != std::string::npos) {
			std::cout << "Nuebar flavour." << std::endl;
			pdg = -12;
		} else {
			std::cout << "[ERROR] no recognised neutrino pdg in file " << inputFilename << std::endl;
			continue;
		}

    std::vector<GSimpleNtpEntry> neutrinos = readGsimpleFile(inputFilename, pdg);
    allNeutrinos.insert(allNeutrinos.end(), neutrinos.begin(), neutrinos.end());
    
    GSimpleNtpMeta file_meta = buildFileMetaData(inputFilename, neutrinos);
    allMeta.emplace_back(file_meta);
  }

  writeRootFile(outputFilename, allNeutrinos, allMeta);

  return 0;
}

