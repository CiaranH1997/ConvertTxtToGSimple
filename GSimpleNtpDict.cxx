// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME GSimpleNtpDict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "GSimpleNtpEntry.h"
#include "GSimpleNtpMeta.h"
#include "NeutrinoFileID.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace genie {
   namespace ROOTDict {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *genie_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("genie", 0 /*version*/, "GSimpleNtpEntry.h", 6,
                     ::ROOT::Internal::DefineBehavior((void*)nullptr,(void*)nullptr),
                     &genie_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_DICT_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *genie_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace genie {
   namespace flux {
   namespace ROOTDict {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *geniecLcLflux_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("genie::flux", 0 /*version*/, "GSimpleNtpEntry.h", 7,
                     ::ROOT::Internal::DefineBehavior((void*)nullptr,(void*)nullptr),
                     &geniecLcLflux_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_DICT_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *geniecLcLflux_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}
}

namespace ROOT {
   static void *new_geniecLcLfluxcLcLGSimpleNtpEntry(void *p = nullptr);
   static void *newArray_geniecLcLfluxcLcLGSimpleNtpEntry(Long_t size, void *p);
   static void delete_geniecLcLfluxcLcLGSimpleNtpEntry(void *p);
   static void deleteArray_geniecLcLfluxcLcLGSimpleNtpEntry(void *p);
   static void destruct_geniecLcLfluxcLcLGSimpleNtpEntry(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::flux::GSimpleNtpEntry*)
   {
      ::genie::flux::GSimpleNtpEntry *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::genie::flux::GSimpleNtpEntry >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("genie::flux::GSimpleNtpEntry", ::genie::flux::GSimpleNtpEntry::Class_Version(), "GSimpleNtpEntry.h", 9,
                  typeid(::genie::flux::GSimpleNtpEntry), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::genie::flux::GSimpleNtpEntry::Dictionary, isa_proxy, 4,
                  sizeof(::genie::flux::GSimpleNtpEntry) );
      instance.SetNew(&new_geniecLcLfluxcLcLGSimpleNtpEntry);
      instance.SetNewArray(&newArray_geniecLcLfluxcLcLGSimpleNtpEntry);
      instance.SetDelete(&delete_geniecLcLfluxcLcLGSimpleNtpEntry);
      instance.SetDeleteArray(&deleteArray_geniecLcLfluxcLcLGSimpleNtpEntry);
      instance.SetDestructor(&destruct_geniecLcLfluxcLcLGSimpleNtpEntry);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::flux::GSimpleNtpEntry*)
   {
      return GenerateInitInstanceLocal(static_cast<::genie::flux::GSimpleNtpEntry*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::genie::flux::GSimpleNtpEntry*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_geniecLcLfluxcLcLGSimpleNtpMeta(void *p = nullptr);
   static void *newArray_geniecLcLfluxcLcLGSimpleNtpMeta(Long_t size, void *p);
   static void delete_geniecLcLfluxcLcLGSimpleNtpMeta(void *p);
   static void deleteArray_geniecLcLfluxcLcLGSimpleNtpMeta(void *p);
   static void destruct_geniecLcLfluxcLcLGSimpleNtpMeta(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::flux::GSimpleNtpMeta*)
   {
      ::genie::flux::GSimpleNtpMeta *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::genie::flux::GSimpleNtpMeta >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("genie::flux::GSimpleNtpMeta", ::genie::flux::GSimpleNtpMeta::Class_Version(), "GSimpleNtpMeta.h", 12,
                  typeid(::genie::flux::GSimpleNtpMeta), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::genie::flux::GSimpleNtpMeta::Dictionary, isa_proxy, 4,
                  sizeof(::genie::flux::GSimpleNtpMeta) );
      instance.SetNew(&new_geniecLcLfluxcLcLGSimpleNtpMeta);
      instance.SetNewArray(&newArray_geniecLcLfluxcLcLGSimpleNtpMeta);
      instance.SetDelete(&delete_geniecLcLfluxcLcLGSimpleNtpMeta);
      instance.SetDeleteArray(&deleteArray_geniecLcLfluxcLcLGSimpleNtpMeta);
      instance.SetDestructor(&destruct_geniecLcLfluxcLcLGSimpleNtpMeta);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::flux::GSimpleNtpMeta*)
   {
      return GenerateInitInstanceLocal(static_cast<::genie::flux::GSimpleNtpMeta*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::genie::flux::GSimpleNtpMeta*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_geniecLcLfluxcLcLNeutrinoFileID(void *p = nullptr);
   static void *newArray_geniecLcLfluxcLcLNeutrinoFileID(Long_t size, void *p);
   static void delete_geniecLcLfluxcLcLNeutrinoFileID(void *p);
   static void deleteArray_geniecLcLfluxcLcLNeutrinoFileID(void *p);
   static void destruct_geniecLcLfluxcLcLNeutrinoFileID(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::genie::flux::NeutrinoFileID*)
   {
      ::genie::flux::NeutrinoFileID *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::genie::flux::NeutrinoFileID >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("genie::flux::NeutrinoFileID", ::genie::flux::NeutrinoFileID::Class_Version(), "NeutrinoFileID.h", 15,
                  typeid(::genie::flux::NeutrinoFileID), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::genie::flux::NeutrinoFileID::Dictionary, isa_proxy, 4,
                  sizeof(::genie::flux::NeutrinoFileID) );
      instance.SetNew(&new_geniecLcLfluxcLcLNeutrinoFileID);
      instance.SetNewArray(&newArray_geniecLcLfluxcLcLNeutrinoFileID);
      instance.SetDelete(&delete_geniecLcLfluxcLcLNeutrinoFileID);
      instance.SetDeleteArray(&deleteArray_geniecLcLfluxcLcLNeutrinoFileID);
      instance.SetDestructor(&destruct_geniecLcLfluxcLcLNeutrinoFileID);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::genie::flux::NeutrinoFileID*)
   {
      return GenerateInitInstanceLocal(static_cast<::genie::flux::NeutrinoFileID*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::genie::flux::NeutrinoFileID*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace genie {
   namespace flux {
//______________________________________________________________________________
atomic_TClass_ptr GSimpleNtpEntry::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *GSimpleNtpEntry::Class_Name()
{
   return "genie::flux::GSimpleNtpEntry";
}

//______________________________________________________________________________
const char *GSimpleNtpEntry::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::flux::GSimpleNtpEntry*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int GSimpleNtpEntry::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::flux::GSimpleNtpEntry*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GSimpleNtpEntry::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::flux::GSimpleNtpEntry*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GSimpleNtpEntry::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::flux::GSimpleNtpEntry*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace genie::flux
} // namespace genie::flux
namespace genie {
   namespace flux {
//______________________________________________________________________________
atomic_TClass_ptr GSimpleNtpMeta::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *GSimpleNtpMeta::Class_Name()
{
   return "genie::flux::GSimpleNtpMeta";
}

//______________________________________________________________________________
const char *GSimpleNtpMeta::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::flux::GSimpleNtpMeta*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int GSimpleNtpMeta::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::flux::GSimpleNtpMeta*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GSimpleNtpMeta::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::flux::GSimpleNtpMeta*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GSimpleNtpMeta::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::flux::GSimpleNtpMeta*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace genie::flux
} // namespace genie::flux
namespace genie {
   namespace flux {
//______________________________________________________________________________
atomic_TClass_ptr NeutrinoFileID::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *NeutrinoFileID::Class_Name()
{
   return "genie::flux::NeutrinoFileID";
}

//______________________________________________________________________________
const char *NeutrinoFileID::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::flux::NeutrinoFileID*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int NeutrinoFileID::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::genie::flux::NeutrinoFileID*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *NeutrinoFileID::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::flux::NeutrinoFileID*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *NeutrinoFileID::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::genie::flux::NeutrinoFileID*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace genie::flux
} // namespace genie::flux
namespace genie {
   namespace flux {
//______________________________________________________________________________
void GSimpleNtpEntry::Streamer(TBuffer &R__b)
{
   // Stream an object of class genie::flux::GSimpleNtpEntry.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(genie::flux::GSimpleNtpEntry::Class(),this);
   } else {
      R__b.WriteClassBuffer(genie::flux::GSimpleNtpEntry::Class(),this);
   }
}

} // namespace genie::flux
} // namespace genie::flux
namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLfluxcLcLGSimpleNtpEntry(void *p) {
      return  p ? new(p) ::genie::flux::GSimpleNtpEntry : new ::genie::flux::GSimpleNtpEntry;
   }
   static void *newArray_geniecLcLfluxcLcLGSimpleNtpEntry(Long_t nElements, void *p) {
      return p ? new(p) ::genie::flux::GSimpleNtpEntry[nElements] : new ::genie::flux::GSimpleNtpEntry[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLfluxcLcLGSimpleNtpEntry(void *p) {
      delete (static_cast<::genie::flux::GSimpleNtpEntry*>(p));
   }
   static void deleteArray_geniecLcLfluxcLcLGSimpleNtpEntry(void *p) {
      delete [] (static_cast<::genie::flux::GSimpleNtpEntry*>(p));
   }
   static void destruct_geniecLcLfluxcLcLGSimpleNtpEntry(void *p) {
      typedef ::genie::flux::GSimpleNtpEntry current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::genie::flux::GSimpleNtpEntry

namespace genie {
   namespace flux {
//______________________________________________________________________________
void GSimpleNtpMeta::Streamer(TBuffer &R__b)
{
   // Stream an object of class genie::flux::GSimpleNtpMeta.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(genie::flux::GSimpleNtpMeta::Class(),this);
   } else {
      R__b.WriteClassBuffer(genie::flux::GSimpleNtpMeta::Class(),this);
   }
}

} // namespace genie::flux
} // namespace genie::flux
namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLfluxcLcLGSimpleNtpMeta(void *p) {
      return  p ? new(p) ::genie::flux::GSimpleNtpMeta : new ::genie::flux::GSimpleNtpMeta;
   }
   static void *newArray_geniecLcLfluxcLcLGSimpleNtpMeta(Long_t nElements, void *p) {
      return p ? new(p) ::genie::flux::GSimpleNtpMeta[nElements] : new ::genie::flux::GSimpleNtpMeta[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLfluxcLcLGSimpleNtpMeta(void *p) {
      delete (static_cast<::genie::flux::GSimpleNtpMeta*>(p));
   }
   static void deleteArray_geniecLcLfluxcLcLGSimpleNtpMeta(void *p) {
      delete [] (static_cast<::genie::flux::GSimpleNtpMeta*>(p));
   }
   static void destruct_geniecLcLfluxcLcLGSimpleNtpMeta(void *p) {
      typedef ::genie::flux::GSimpleNtpMeta current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::genie::flux::GSimpleNtpMeta

namespace genie {
   namespace flux {
//______________________________________________________________________________
void NeutrinoFileID::Streamer(TBuffer &R__b)
{
   // Stream an object of class genie::flux::NeutrinoFileID.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(genie::flux::NeutrinoFileID::Class(),this);
   } else {
      R__b.WriteClassBuffer(genie::flux::NeutrinoFileID::Class(),this);
   }
}

} // namespace genie::flux
} // namespace genie::flux
namespace ROOT {
   // Wrappers around operator new
   static void *new_geniecLcLfluxcLcLNeutrinoFileID(void *p) {
      return  p ? new(p) ::genie::flux::NeutrinoFileID : new ::genie::flux::NeutrinoFileID;
   }
   static void *newArray_geniecLcLfluxcLcLNeutrinoFileID(Long_t nElements, void *p) {
      return p ? new(p) ::genie::flux::NeutrinoFileID[nElements] : new ::genie::flux::NeutrinoFileID[nElements];
   }
   // Wrapper around operator delete
   static void delete_geniecLcLfluxcLcLNeutrinoFileID(void *p) {
      delete (static_cast<::genie::flux::NeutrinoFileID*>(p));
   }
   static void deleteArray_geniecLcLfluxcLcLNeutrinoFileID(void *p) {
      delete [] (static_cast<::genie::flux::NeutrinoFileID*>(p));
   }
   static void destruct_geniecLcLfluxcLcLNeutrinoFileID(void *p) {
      typedef ::genie::flux::NeutrinoFileID current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::genie::flux::NeutrinoFileID

namespace ROOT {
   static TClass *vectorlEstringgR_Dictionary();
   static void vectorlEstringgR_TClassManip(TClass*);
   static void *new_vectorlEstringgR(void *p = nullptr);
   static void *newArray_vectorlEstringgR(Long_t size, void *p);
   static void delete_vectorlEstringgR(void *p);
   static void deleteArray_vectorlEstringgR(void *p);
   static void destruct_vectorlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<string>*)
   {
      vector<string> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<string>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<string>", -2, "vector", 423,
                  typeid(vector<string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEstringgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<string>) );
      instance.SetNew(&new_vectorlEstringgR);
      instance.SetNewArray(&newArray_vectorlEstringgR);
      instance.SetDelete(&delete_vectorlEstringgR);
      instance.SetDeleteArray(&deleteArray_vectorlEstringgR);
      instance.SetDestructor(&destruct_vectorlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<string> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<string>","std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<string>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<string>*>(nullptr))->GetClass();
      vectorlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEstringgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string> : new vector<string>;
   }
   static void *newArray_vectorlEstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<string>[nElements] : new vector<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEstringgR(void *p) {
      delete (static_cast<vector<string>*>(p));
   }
   static void deleteArray_vectorlEstringgR(void *p) {
      delete [] (static_cast<vector<string>*>(p));
   }
   static void destruct_vectorlEstringgR(void *p) {
      typedef vector<string> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<string>

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = nullptr);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 423,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<int>","std::vector<int, std::allocator<int> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr))->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete (static_cast<vector<int>*>(p));
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] (static_cast<vector<int>*>(p));
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace {
  void TriggerDictionaryInitialization_GSimpleNtpDict_Impl() {
    static const char* headers[] = {
"GSimpleNtpEntry.h",
"GSimpleNtpMeta.h",
"NeutrinoFileID.h",
nullptr
    };
    static const char* includePaths[] = {
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_28_12/Linux64bit+3.10-2.17-e26-p3915-prof/include/",
"/exp/dune/app/users/chasnip/CERN_Fellowship/ConvertTxtToGSimple/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "GSimpleNtpDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace genie{namespace flux{class __attribute__((annotate("$clingAutoload$GSimpleNtpEntry.h")))  GSimpleNtpEntry;}}
namespace genie{namespace flux{class __attribute__((annotate("$clingAutoload$GSimpleNtpMeta.h")))  GSimpleNtpMeta;}}
namespace genie{namespace flux{class __attribute__((annotate("$clingAutoload$NeutrinoFileID.h")))  NeutrinoFileID;}}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "GSimpleNtpDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "GSimpleNtpEntry.h"
#include "GSimpleNtpMeta.h"
#include "NeutrinoFileID.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"genie::flux::GSimpleNtpEntry", payloadCode, "@",
"genie::flux::GSimpleNtpMeta", payloadCode, "@",
"genie::flux::NeutrinoFileID", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("GSimpleNtpDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_GSimpleNtpDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_GSimpleNtpDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_GSimpleNtpDict() {
  TriggerDictionaryInitialization_GSimpleNtpDict_Impl();
}
