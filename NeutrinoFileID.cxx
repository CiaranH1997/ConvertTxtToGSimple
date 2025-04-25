#include "NeutrinoFileID.h"

ClassImp(genie::flux::NeutrinoFileID);

namespace genie {
namespace flux {

std::pair<int, double> NeutrinoFileID::getFilePOT(const std::string& filename) {
 
  double filePOT(-1);
  int nevents(0);
  std::ifstream infile(filename);
  std::string line;
  
  while (std::getline(infile, line)) {
    if (line.empty() || line[0] == '#') {
      continue; // Skip comments and empty lines
    }

    std::istringstream iss(line);
    GSimpleNtpEntry nu;
    iss >> nu.haddec_x >> nu.haddec_y >> nu.haddec_z >> nu.px >> nu.py >> nu.pz >> nu.E >> nu.theta 
      >> nu.phi >> nu.br_p >> nu.pot_f >> nu.xd >> nu.yd >> nu.zd >> nu.vtxx >> nu.vtxy >> nu.vtxz;

    if (filePOT < 0) filePOT = nu.pot_f;
    nevents++;
  }
  return {nevents, filePOT};
}

void NeutrinoFileID::initialize_fileid(const std::string &file) {
  
  size_t found_last_slash = file.find_last_of("/");
  std::string substr_file = file.substr(found_last_slash+1);
	
  if (substr_file.find(".txt") == std::string::npos) {
	  std::cout << "[ERROR] Must input txt file." << std::endl;
	}
  std::cout << "READING: " << substr_file << std::endl;
	
  auto pair_nevents_filePOT = getFilePOT(file);

  size_t found_numu = substr_file.find("14");
	size_t found_nue = substr_file.find("12");
	size_t found_numubar = substr_file.find("-14");
	size_t found_nuebar = substr_file.find("-12");
	int pdg(-999);

	if (found_numu != std::string::npos) {
	  std::cout << "Numu flavour." << std::endl;
		pdg = 14;
	} else if (found_nue != std::string::npos) {
		std::cout << "Nue flavour." << std::endl;
		pdg = 12;
	} 

  if (found_numubar != std::string::npos) {
	  std::cout << "Numubar flavour." << std::endl;
		pdg = -14;
	} else if (found_nuebar != std::string::npos) {
		std::cout << "Nuebar flavour." << std::endl;
		pdg = -12;
	} 

  size_t found_nu_decay0 = substr_file.find("130_3body");
  size_t found_nu_decay1 = substr_file.find("211_2body");
  size_t found_nu_decay2 = substr_file.find("310_3body");
  size_t found_nu_decay3 = substr_file.find("321_2body");
  size_t found_nu_decay4 = substr_file.find("321_3body");

  size_t found_nub_decay0 = substr_file.find("-211_2body");
  size_t found_nub_decay1 = substr_file.find("-321_2body");
  size_t found_nub_decay2 = substr_file.find("-321_3body");

  std::string hadron_decay("");
  double br = 1.;

  if (pdg == 14) {
    if (found_nu_decay0 != std::string::npos) {
      std::cout << "numu decay 0" << std::endl;
      hadron_decay = "130_3body";
      br = 0.2704 * 0.5; // 0.2704 is the BR to either numu or numubar
    } else if (found_nu_decay1 != std::string::npos) {
      std::cout << "numu decay 1" << std::endl;
      hadron_decay = "211_2body";
      br = 0.999877;
    } else if (found_nu_decay2 != std::string::npos) {
      std::cout << "numu decay 2" << std::endl;
      hadron_decay = "310_3body";
      br = 4.56e-4 * 0.5; // 4.56e-4 is the BR to either numu or numubar
    } else if (found_nu_decay3 != std::string::npos) {
      std::cout << "numu decay 3" << std::endl;
      hadron_decay = "321_2body";
      br = 0.6356;
    } else if (found_nu_decay4 != std::string::npos) {
      std::cout << "numu decay 4" << std::endl;
      hadron_decay = "321_3body";
      br = 0.03352;
    }
  } else if (pdg == 12) {
    if (found_nu_decay0 != std::string::npos) {
      std::cout << "nue decay 0" << std::endl;
      hadron_decay = "130_3body";
      br = 0.4055 * 0.5; // 0.4055 is the BR to either nue or nuebar
    } else if (found_nu_decay1 != std::string::npos) {
      std::cout << "nue decay 1" << std::endl;
      hadron_decay = "211_2body";
      br = 1.23e-4;
    } else if (found_nu_decay2 != std::string::npos) {
      std::cout << "nue decay 2" << std::endl;
      hadron_decay = "310_3body";
      br = 7.14e-4 * 0.5; // 7.14e-4 is the BR to either nue or nuebar
    } else if (found_nu_decay3 != std::string::npos) {
      std::cout << "nue decay 3" << std::endl;
      hadron_decay = "321_2body";
      br = 1.582e-5;
    } else if (found_nu_decay4 != std::string::npos) {
      std::cout << "nue decay 4" << std::endl;
      hadron_decay = "321_3body";
      br = 0.0507;
    }
  } else if (pdg == -14) {
    if (found_nub_decay0 != std::string::npos) {
      std::cout << "numubar decay 0" << std::endl;
      hadron_decay = "-211_2body";
      br = 0.999877;
    } else if (found_nub_decay1 != std::string::npos) {
      std::cout << "numubar decay 1" << std::endl;
      hadron_decay = "-321_2body";
      br = 0.6356;
    } else if (found_nub_decay2 != std::string::npos) {
      std::cout << "numubar decay 2" << std::endl;
      hadron_decay = "-321_3body";
      br = 0.03352;
    }
  } else if (pdg == -12) {
    if (found_nub_decay0 != std::string::npos) {
      std::cout << "nuebar decay 0" << std::endl;
      hadron_decay = "-211_2body";
      br = 1.23e-4;
    } else if (found_nub_decay1 != std::string::npos) {
      std::cout << "nuebar decay 1" << std::endl;
      hadron_decay = "-321_2body";
      br = 1.582e-5;
    } else if (found_nub_decay2 != std::string::npos) {
      std::cout << "nuebar decay 2" << std::endl;
      hadron_decay = "-321_3body";
      br = 0.0507;
    }
  }

  this->filepath = file;
  this->pdg = pdg;
  this->decay_mode = hadron_decay;
  this->br = br;
  this->nevents = pair_nevents_filePOT.first;
  this->pot = pair_nevents_filePOT.second;
  this->initialised = true;
}

} // flux
} // genie
