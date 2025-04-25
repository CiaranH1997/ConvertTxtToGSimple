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

        NeutrinoFileID(const NeutrinoFileID& other)
          : filepath(other.filepath), pdg(other.pdg), decay_mode(other.decay_mode),
          br(other.br), nevents(other.nevents), pot(other.pot), initialised(other.initialised) {}

        virtual ~NeutrinoFileID() {}

        void initialize_fileid(const std::string &file);

        friend std::ostream& operator<<(std::ostream& os, const NeutrinoFileID& id) {
          os << "Filepath: " << id.filepath << "\n"
            << "PDG: " << id.pdg << "\n"
            << "Decay Mode: " << id.decay_mode << "\n"
            << "Branching Ratio: " << id.br << "\n"
            << "Number of Events: " << id.nevents << "\n"
            << "POT: " << id.pot << "\n"
            << "Initialised: " << std::boolalpha << id.initialised << "\n";
            return os;
        }

        ClassDef(NeutrinoFileID, 1);

      protected:
        std::pair<int, double> getFilePOT(const std::string& filename);
    };

  }
}

#endif
