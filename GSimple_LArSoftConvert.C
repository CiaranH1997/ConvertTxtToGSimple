#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "TFile.h"
#include "TTree.h"
#include "Neutrino.h"
/*
struct Neutrino {
    int pdg_code;
    double energy;
    double weight;
    double px;
    double py;
    double pz;
    double x;
    double y;
    double z;
	double theta;
	double phi;
	double width_p;
	double br_p;
	double pot_f;
};
*/
/*class Neutrino : public TObject {
public:
    int pdg_code;
    double energy;
    double weight;
    double px;
    double py;
    double pz;
    double x;
    double y;
    double z;
	double theta;
	double phi;
	double width_p;
	double br_p;
	double pot_f;

    Neutrino() : pdg_code(0), energy(0), weight(0), px(0), py(0), pz(0), x(0), y(0), z(0), theta(0), phi(0), width_p(0), br_p(0), pot_f(0) {}
    virtual ~Neutrino() {}

    ClassDef(Neutrino, 1);
};

ClassImp(Neutrino);
*/
//std::vector<Neutrino> readGsimpleFile(const std::string& filename) {
std::vector<Neutrino> readGsimpleFile(const std::string& filename, int pdg) {
    std::vector<Neutrino> neutrinos;
    std::ifstream infile(filename);
    std::string line;

	double surface = 6. * 7.;

    while (std::getline(infile, line)) {
        if (line.empty() || line[0] == '#') {
            continue; // Skip comments and empty lines
        }

        std::istringstream iss(line);
        Neutrino nu;
        iss >> nu.vtxx >> nu.vtxy >> nu.vtxz >> nu.px >> nu.py >> nu.pz >> nu.E >> nu.theta >> nu.phi >> nu.width_p >> nu.br_p >> nu.pot_f;
		nu.pdg = pdg;
		nu.wgt = nu.br_p / (surface * nu.pot_f);
		neutrinos.push_back(nu);
    }

    return neutrinos;
}

void writeRootFile(const std::string& filename, const std::vector<Neutrino>& neutrinos) {
    TFile* file = new TFile(filename.c_str(), "RECREATE");
    TTree* tree = new TTree("flux", "Neutrino Flux");

    //TTree* entryBranch = fluxBranch->Branch("entry", nullptr, "entry/I");

	//tree->Branch("entry", "Int_t", nullptr);
	
	Neutrino nu;
	tree->Branch("entry", &nu);

	for (const auto& n : neutrinos) {
        nu = n;
        tree->Fill();
    }

    //int pdg_code;
    //double energy, weight, px, py, pz, x, y, z;

    /*entryBranch->Branch("pdg", &pdg_code, "pdg/I");
    entryBranch->Branch("E", &energy, "E/D");
    entryBranch->Branch("wgt", &weight, "wgt/D");
    entryBranch->Branch("px", &px, "px/D");
    entryBranch->Branch("py", &py, "py/D");
    entryBranch->Branch("pz", &pz, "pz/D");
    entryBranch->Branch("vtxx", &x, "vtxx/D");
    entryBranch->Branch("vtxy", &y, "vtxy/D");
    entryBranch->Branch("vtxz", &z, "vtxz/D");*/

    /*tree->Branch("pdg", &pdg_code, "pdg/I");
    tree->Branch("E", &energy, "E/D");
    tree->Branch("wgt", &weight, "wgt/D");
    tree->Branch("px", &px, "px/D");
    tree->Branch("py", &py, "py/D");
    tree->Branch("pz", &pz, "pz/D");
    tree->Branch("vtxx", &x, "vtxx/D");
    tree->Branch("vtxy", &y, "vtxy/D");
    tree->Branch("vtxz", &z, "vtxz/D");
    for (const auto& nu : neutrinos) {
        pdg_code = nu.pdg_code;
        energy = nu.energy;
        weight = nu.weight;
        px = nu.px;
        py = nu.py;
        pz = nu.pz;
        x = nu.x;
        y = nu.y;
        z = nu.z;
        tree->Fill();
    }*/

    tree->Write();
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
    std::vector<Neutrino> allNeutrinos;

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
			pdg = 13;
		}
		else if (found_nue != std::string::npos) {
			std::cout << "Nue flavour." << std::endl;
			pdg = 11;
		}
		else {
			std::cout << "[ERROR] no recognised neutrino pdg in file " << inputFilename << std::endl;
			continue;
		}
        std::vector<Neutrino> neutrinos = readGsimpleFile(inputFilename, pdg);
        allNeutrinos.insert(allNeutrinos.end(), neutrinos.begin(), neutrinos.end());
    }

    writeRootFile(outputFilename, allNeutrinos);

    return 0;
}

