// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME NeutrinoDict
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
#include "Neutrino.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_Neutrino(void *p = nullptr);
   static void *newArray_Neutrino(Long_t size, void *p);
   static void delete_Neutrino(void *p);
   static void deleteArray_Neutrino(void *p);
   static void destruct_Neutrino(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Neutrino*)
   {
      ::Neutrino *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Neutrino >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Neutrino", ::Neutrino::Class_Version(), "Neutrino.h", 6,
                  typeid(::Neutrino), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Neutrino::Dictionary, isa_proxy, 4,
                  sizeof(::Neutrino) );
      instance.SetNew(&new_Neutrino);
      instance.SetNewArray(&newArray_Neutrino);
      instance.SetDelete(&delete_Neutrino);
      instance.SetDeleteArray(&deleteArray_Neutrino);
      instance.SetDestructor(&destruct_Neutrino);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Neutrino*)
   {
      return GenerateInitInstanceLocal(static_cast<::Neutrino*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Neutrino*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr Neutrino::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Neutrino::Class_Name()
{
   return "Neutrino";
}

//______________________________________________________________________________
const char *Neutrino::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Neutrino*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Neutrino::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Neutrino*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Neutrino::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Neutrino*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Neutrino::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Neutrino*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void Neutrino::Streamer(TBuffer &R__b)
{
   // Stream an object of class Neutrino.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Neutrino::Class(),this);
   } else {
      R__b.WriteClassBuffer(Neutrino::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Neutrino(void *p) {
      return  p ? new(p) ::Neutrino : new ::Neutrino;
   }
   static void *newArray_Neutrino(Long_t nElements, void *p) {
      return p ? new(p) ::Neutrino[nElements] : new ::Neutrino[nElements];
   }
   // Wrapper around operator delete
   static void delete_Neutrino(void *p) {
      delete (static_cast<::Neutrino*>(p));
   }
   static void deleteArray_Neutrino(void *p) {
      delete [] (static_cast<::Neutrino*>(p));
   }
   static void destruct_Neutrino(void *p) {
      typedef ::Neutrino current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Neutrino

namespace {
  void TriggerDictionaryInitialization_NeutrinoDict_Impl() {
    static const char* headers[] = {
"Neutrino.h",
nullptr
    };
    static const char* includePaths[] = {
"/opt/homebrew/Cellar/root/6.32.02/include/root",
"/Users/ciaranhasnip/CERN_Code/MakeGSimpleFlux/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "NeutrinoDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$Neutrino.h")))  Neutrino;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "NeutrinoDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "Neutrino.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"Neutrino", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("NeutrinoDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_NeutrinoDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_NeutrinoDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_NeutrinoDict() {
  TriggerDictionaryInitialization_NeutrinoDict_Impl();
}
