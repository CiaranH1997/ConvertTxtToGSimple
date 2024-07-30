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
#include "RConfig.h"
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
      return GenerateInitInstanceLocal((::genie::flux::GSimpleNtpEntry*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::flux::GSimpleNtpEntry*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
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
      return GenerateInitInstanceLocal((::genie::flux::GSimpleNtpMeta*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::genie::flux::GSimpleNtpMeta*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
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
      delete ((::genie::flux::GSimpleNtpEntry*)p);
   }
   static void deleteArray_geniecLcLfluxcLcLGSimpleNtpEntry(void *p) {
      delete [] ((::genie::flux::GSimpleNtpEntry*)p);
   }
   static void destruct_geniecLcLfluxcLcLGSimpleNtpEntry(void *p) {
      typedef ::genie::flux::GSimpleNtpEntry current_t;
      ((current_t*)p)->~current_t();
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
      delete ((::genie::flux::GSimpleNtpMeta*)p);
   }
   static void deleteArray_geniecLcLfluxcLcLGSimpleNtpMeta(void *p) {
      delete [] ((::genie::flux::GSimpleNtpMeta*)p);
   }
   static void destruct_geniecLcLfluxcLcLGSimpleNtpMeta(void *p) {
      typedef ::genie::flux::GSimpleNtpMeta current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::genie::flux::GSimpleNtpMeta

namespace {
  void TriggerDictionaryInitialization_GSimpleNtpDict_Impl() {
    static const char* headers[] = {
"GSimpleNtpEntry.h",
"GSimpleNtpMeta.h",
nullptr
    };
    static const char* includePaths[] = {
"/cvmfs/larsoft.opensciencegrid.org/products/root/v6_26_06b/Linux64bit+3.10-2.17-e26-p3913-prof/include/",
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
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "GSimpleNtpDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "GSimpleNtpEntry.h"
#include "GSimpleNtpMeta.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"genie::flux::GSimpleNtpEntry", payloadCode, "@",
"genie::flux::GSimpleNtpMeta", payloadCode, "@",
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