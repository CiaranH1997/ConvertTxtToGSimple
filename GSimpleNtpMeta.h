#ifndef GSIMPLENTPMETA_H
#define GSIMPLENTPMETA_H

#include <string>
#include <vector>

#include "TObject.h"

namespace genie {
    namespace flux {

        class GSimpleNtpMeta : public TObject {
        public:
            std::vector<int> pdglist;
            double maxEnergy;
            double minWgt;
            double maxWgt;
            double protons;
	    double windowBase[3];
	    double windowDir1[3];
	    double windowDir2[3];
            std::vector<std::string> infiles;
	    int metakey;

            GSimpleNtpMeta() : maxEnergy(0), minWgt(0), maxWgt(0), protons(0), metakey(0) {
	        for (int i = 0; i < 3; ++i) {
	            windowBase[i] = 0.0;
	            windowDir1[i] = 0.0;
	            windowDir2[i] = 0.0;
                }
	    }
            
	    // copy constructor
	    GSimpleNtpMeta(const GSimpleNtpMeta& other)
                : maxEnergy(other.maxEnergy),
                  minWgt(other.minWgt),
                  maxWgt(other.maxWgt),
                  protons(other.protons),
                  metakey(other.metakey) 
            {
	        for (int i = 0; i < 3; ++i) {
	            windowBase[i] = other.windowBase[i];
	            windowDir1[i] = other.windowDir1[i];
	            windowDir2[i] = other.windowDir2[i];
                }
            }

	    // copy assignment operator
	    GSimpleNtpMeta& operator=(const GSimpleNtpMeta& other) {
                if (this == &other) {
		    return *this; // Handle self-assignmen
		}

		pdglist = other.pdglist;
	        maxEnergy = other.maxEnergy;
	        minWgt = other.minWgt;
	        maxWgt = other.maxWgt;
	        protons = other.protons;
	        infiles = other.infiles;
	        metakey = other.metakey;

	        for (int i = 0; i < 3; ++i) {
	            windowBase[i] = other.windowBase[i];
	            windowDir1[i] = other.windowDir1[i];
	            windowDir2[i] = other.windowDir2[i];
                }

                return *this;
	    }

            virtual ~GSimpleNtpMeta() {}

            ClassDef(GSimpleNtpMeta, 2);
        };

    } // flux
} // genie

#endif

