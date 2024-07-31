#ifndef GSIMPLENTPENTRY_H
#define GSIMPLENTPENTRY_H

#include "TObject.h"

namespace genie {
    namespace flux {

        class GSimpleNtpEntry : public TObject {
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
            double haddec_x;
            double haddec_y;
            double haddec_z;
	    double dist;
            double theta;
            double phi;
            double width_p;
            double br_p;
            double pot_f;
	    int metakey;

            GSimpleNtpEntry() : pdg(0), E(0), wgt(0), px(0), py(0), pz(0), vtxx(0), vtxy(0), 
	    vtxz(0), haddec_x(0), haddec_y(0), haddec_z(0), dist(0), theta(0), phi(0), 
	    width_p(0), br_p(0), pot_f(0), metakey(0) {}

            virtual ~GSimpleNtpEntry() {}

            ClassDef(GSimpleNtpEntry, 1);
        };

    } // flux
} // genie

#endif
