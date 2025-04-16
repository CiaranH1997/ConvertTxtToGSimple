# Convert .txt flux files to gsimple format for LArSoft compatability.

- Create a GSimpleNtpEntry.h and GSimpleNtpMeta.h files to define custom classes that handle entry and meta trees.
- Create a LinkDef.h file

```
// LinkDef.h
#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ namespace genie;
#pragma link C++ namespace genie::flux;
#pragma link C++ class genie::flux::GSimpleNtpEntry+;
#pragma link C++ class genie::flux::GSimpleNtpMeta+;
#pragma link C++ class genie::flux::NeutrinoFileID+;

#endif
```

- Generate the dictionary
```
rootcling -f GSimpleNtpDict.cxx -c GSimpleNtpEntry.h GSimpleNtpMeta.h NeutrinoFileID.h LinkDef.h

```

- Compile script (you made need to repeat the above step if you have altered Neutrino):
```
g++ GSimpleNtpDict.cxx GSimple_LArSoftConvert.C NeutrinoFileID.cxx -o GSimple_LArSoftConvert `root-config --cflags --libs`
```

Or just run the `build.sh` script to run the above two steps.

- Execute script (amend path to input files and wobbling configuration to whatever you are using)
```
./GSimple_LArSoftConvert $WOB /out/path/to/protodune_neutrinoflux.root ~/in/path/to/lightnu_fluxes_*
```

There is a helper bash script for running the executable: `runNewProtoDUNEFluxProd.sh`.
