# Convert .txt flux files to gsimple format for LArSoft compatability.

- Create a Neutrino.h and Neutrino.cxx files to define custom class
- Create a LinkDef.h file

```
// LinkDef.h
#ifdef __CINT__

#pragma link C++ class g++ GSimpleNtpEntry+;

#endif
```

- Generate the dictionary
```
rootcling -f GSimpleNtpEntryDict.cxx -c GSimpleNtpEntry.h LinkDef.h
```

- Compile script (you made need to repeat the above step if you have altered Neutrino):
```
g++ GSimpleNtpEntryDict.cxx GSimple_LArSoftConvert.C -o GSimple_LArSoftConvert `root-config --cflags --libs`
```

- Execute script (amend path to input files to whatever you are using)
```
./GSimple_LArSoftConvert protodune_neutrino.root ~/Documents/NeutrinoFluxes_ProtoDUNEBSM/lightnu_fluxes_*
```

