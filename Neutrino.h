#ifndef NEUTRINO_H
#define NEUTRINO_H

#include "TObject.h"

class Neutrino : public TObject {
public:
    int pdg;
    double E;
    double wgt;
    double px;
    double py;
    double pz;
    double vtxx;
    double vtxy;
    double vtxz;
	double theta;
	double phi;
	double width_p;
	double br_p;
	double pot_f;

    Neutrino() : pdg(0), E(0), wgt(0), px(0), py(0), pz(0), vtxx(0), vtxy(0), vtxz(0), theta(0), phi(0), width_p(0), br_p(0), pot_f(0) {}
    virtual ~Neutrino() {}

    ClassDef(Neutrino, 1);
};

#endif
