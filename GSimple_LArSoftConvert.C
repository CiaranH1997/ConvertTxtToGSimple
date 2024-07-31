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

    double surface = 6. * 7.;

    // Generate a metakey
    TRandom3 *r = new TRandom3(0);
    auto random_metakey = r->Rndm() * 1000;
    delete r;

    while (std::getline(infile, line)) {
        if (line.empty() || line[0] == '#') {
            continue; // Skip comments and empty lines
        }

        std::istringstream iss(line);
        GSimpleNtpEntry nu;
	double haddec_x, haddec_y, haddec_z;
        iss >> nu.haddec_x >> nu.haddec_y >> nu.haddec_z >> nu.px >> nu.py >> nu.pz >> nu.E >> nu.theta >> nu.phi >> nu.width_p >> nu.br_p >> nu.pot_f;
        nu.pdg = pdg;
	// Should I be doing something with the weights? Like weighting for the branching ratio? Probably...
        //nu.wgt = nu.br_p / (surface * nu.pot_f);
        nu.wgt = 1;
	// separation between T2 and NP04 centre is 723m, but dist is to flux window, so go ~4m back - very rough!
	nu.dist = 719. - haddec_z;

	double r = nu.dist / std::cos(nu.theta);
	// Displacement between beam and and neutrino at window
	double x_beamdisp = r*std::sin(nu.theta)*std::cos(nu.phi - 0.5*M_PI) + haddec_x;
	double y_beamdisp = r*std::sin(nu.theta)*std::sin(nu.phi - 0.5*M_PI) + haddec_y;
	// Convert displacement from beam to detector coordinates
	// beam axis displacement is [x, y] = (-7.5, 0) - transform by this
	double det_beam_disp_x = 7/2;
	double det_beam_disp_y = 0.;
	nu.vtxx = x_beamdisp - det_beam_disp_x;
	nu.vtxy = y_beamdisp - det_beam_disp_y;
	// In detector coords, y-origin is at the bottom of the detector, so shift vtxy up by 3m
	nu.vtxy += 3.;
	// beam window placed at z = -2. It is flat perpendicular to beam and parallel to
	// front face of ProtoDUNE. Assumption as angular distribution of neutrinos is very tight.
	// WARNING: be careful to change if flux woindow changes!
	nu.vtxz = -2.;

	nu.metakey = (int)random_metakey;
        neutrinos.push_back(nu);
    }

    return neutrinos;
}

GSimpleNtpMeta buildFileMetaData(const std::string& filename, const std::vector<GSimpleNtpEntry>& neutrinos) {


    // TODO: make more sophisticated to sort the pdgs present in object
    // TODO: get a proper flux window for protodune. This is for the dune FD

    GSimpleNtpMeta ret;

    std::vector<double> vE;
    std::vector<double> vWgt;
    for (const auto& n : neutrinos) {
        vE.push_back(n.E);
        vWgt.push_back(n.wgt);
    }

    ret.pdglist.push_back(12);
    ret.pdglist.push_back(14);
    ret.maxEnergy = *std::max_element(vE.begin(), vE.end());
    ret.minWgt = *std::min_element(vWgt.begin(), vWgt.end());
    ret.maxWgt = *std::max_element(vWgt.begin(), vWgt.end());
    vE.clear();
    vWgt.clear();
    ret.protons = neutrinos.at(0).pot_f;
    // ### Start Flux Window ###
    // Guess a flux window (det. coordinates)
    // 10m wide and 10m tall positioned ~2m upstream from cryostat wall
    // Hopefully this is good enough for now
    // Assume that all the neutrinos are already perpendicular to detector front face - this 
    // means that the flux window is parallel to detector front face - maybe an okay assumption
    ret.windowBase[0] = -5.;
    ret.windowBase[1] = -1.;
    ret.windowBase[2] = -2.;
    ret.windowDir1[0] = -5.;
    ret.windowDir1[1] = 9.;
    ret.windowDir1[2] = -2.;
    ret.windowDir2[0] = 5.;
    ret.windowDir2[1] = -1.;
    ret.windowDir2[2] = -2.;
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
        std::cerr << "Usage: " << argv[0] << " output.root input1.gsimple [input2.gsimple ... inputN.gsimple]" << std::endl;
        return 1;
    }

    std::string outputFilename = argv[1];
	if (outputFilename.find(".root") == std::string::npos) {
		std::cout << "[ERROR] Must output root file." << std::endl;
		return 1;
	}
    std::vector<GSimpleNtpEntry> allNeutrinos;
    
    std::vector<GSimpleNtpMeta> allMeta;

    for (int i = 2; i < argc; ++i) {
        std::string inputFilename = argv[i];
		if (inputFilename.find(".txt") == std::string::npos) {
			std::cout << "[ERROR] Must input txt file." << std::endl;
			return 1;
		}
		std::cout << "READING: " << inputFilename << std::endl;
		size_t found_numu = inputFilename.find("numu");
		size_t found_nue = inputFilename.find("nue");
		int pdg(-999);
		if (found_numu != std::string::npos) {
			std::cout << "Numu flavour." << std::endl;
			pdg = 14;
		}
		else if (found_nue != std::string::npos) {
			std::cout << "Nue flavour." << std::endl;
			pdg = 12;
		}
		else {
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

