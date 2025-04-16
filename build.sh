#!/bin/bash

# direct ROOT compilation

rootcling -f GSimpleNtpDict.cxx -c GSimpleNtpEntry.h GSimpleNtpMeta.h NeutrinoFileID.h LinkDef.h

g++ GSimpleNtpDict.cxx GSimple_LArSoftConvert.C NeutrinoFileID.cxx -o GSimple_LArSoftConvert `root-config --cflags --libs`
