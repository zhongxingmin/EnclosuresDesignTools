#ifndef ASI_ASISYS_H
#define ASI_ASISYS_H asisysh

#pragma once
#include <tchar.h>

#ifndef DLL_EXPORT
#define DLLScope __declspec( dllexport )
#else
#define DLLScope __declspec( dllimport )
#endif

#ifdef DBINITCONSTANTS
#define GLOBAL_(type, name, val)  type name = val
#else
#define GLOBAL_(type, name, val)  extern type name
#endif

#ifndef  MAX
# define MIN(a,b)  ( (a) < (b) ? (a) : (b) )
# define MAX(a,b)  ( (a) > (b) ? (a) : (b) )
#endif

#ifndef NUMELEM
# define NUMELEM(x) (sizeof(x)/sizeof(*x))
#endif

// Error processing macros

#define RETURN_IF_FAILED(hr)  {\
  HRESULT tmpHr;  \
  tmpHr = (hr);  \
  if(FAILED((tmpHr))) return tmpHr; \
  }

#define THROW_IF_FAILED(hr) {  \
  HRESULT tmpHr;  \
  tmpHr = (hr);  \
  if(FAILED((tmpHr))) throw (tmpHr);	\
  }


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#pragma pack (push, 8)
/* Memory functions */
DLLScope long AsiObjectsInUse (void);
DLLScope void* AsiMemoryMalloc (size_t);
DLLScope void AsiMemoryFree (void*);
DLLScope void* AsiMemoryRealloc (void*,size_t);
DLLScope void* AsiMemoryAddMsg (void*,const TCHAR *);
#pragma pack (pop)
#ifdef __cplusplus
}
#endif

#endif
