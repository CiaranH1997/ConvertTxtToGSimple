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

#endif
```

- Generate the dictionary
```
rootcling -f GSimpleNtpDict.cxx -c GSimpleNtpEntry.h GSimpleNtpMeta.h LinkDef.h

```

- Compile script (you made need to repeat the above step if you have altered Neutrino):
```
g++ GSimpleNtpDict.cxx GSimple_LArSoftConvert.C -o GSimple_LArSoftConvert `root-config --cflags --libs`
```

- Execute script (amend path to input files to whatever you are using)
```
./GSimple_LArSoftConvert /out/path/to/protodune_neutrinoflux.root ~/in/path/to/lightnu_fluxes_*
```

