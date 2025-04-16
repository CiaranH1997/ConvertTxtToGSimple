#ifndef NEUTRINOFILEID_H
#define NEUTRINOFILEID_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "GSimpleNtpEntry.h"

#include "TObject.h"

namespace genie {
  namespace flux {
    
    class NeutrinoFileID : public TObject {
      public:

        std::string filepath;
        int pdg;
        std::string decay_mode;
        double br;
        int nevents;
        double pot;
        bool initialised;
        
        NeutrinoFileID() : filepath(""), pdg(0), decay_mode(""), br(0), nevents(0), pot(0), initialised(false) {} 

        virtual ~NeutrinoFileID() {}

        void initialize_fileid(const std::string &file);
        
        ClassDef(NeutrinoFileID, 1);

      protected:
        std::pair<int, double> getFilePOT(const std::string& filename);
    };

  }
}

#endif
