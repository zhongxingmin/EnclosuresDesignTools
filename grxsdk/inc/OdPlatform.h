/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2018, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) Copyright (C) 2002-2018 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////




#ifndef _OD_PLATFORM_H_
#define _OD_PLATFORM_H_


#include "OdPlatformSettings.h"

// Moved from OdaCommon.h, to be used in string functions
#define odmin(X,Y) ((X) < (Y) ? (X) : (Y))
#define odmax(X,Y) ((X) > (Y) ? (X) : (Y))

#if defined(ODA_WINDOWS)
#include <math.h>
#include <float.h>
#define Odisnan ::_isnan
#define Odfinite ::_finite
#ifndef OD_USE_EXTENDED_FUNCTIONS
#define GETSS(s,n) ::fgets(s, n, stdin)
#define OdWprintf wprintf
#define OdPrintf printf
#else
#define GETSS(s,n) ::gets_s(s,n)
#define OdWprintf _wprintf_p
#define OdPrintf _printf_p
#endif

#ifdef ODA_WINDOWS_GCC
#include <ctype.h>
#endif

#if defined(_MSC_VER) && (_MSC_VER < 1400)
#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lParam)	((int)(short)LOWORD(lParam))
#endif
#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lParam)	((int)(short)HIWORD(lParam))
#endif
#endif

#else
#include <stdio.h>
#include <limits.h>
#define GETSS(s, n) fgets(s, n, stdin)

#ifndef MAX_PATH
#define MAX_PATH PATH_MAX
#endif

#define OdWprintf wprintf
#define OdPrintf printf

#if defined(__APPLE__)
#include <math.h>
#define Odisnan std::isnan
#define Odfinite std::isfinite
#else
#if defined(__sun)
#include <ieeefp.h>
#else
#include <math.h>
#endif
#define Odisnan isnan
#define Odfinite finite
#endif
#endif

#ifdef ANDROID
  //r9d have disabled acosl function
  #ifndef acosl
    #define acosl acos
  #endif
#endif

#ifdef ANDROID_WCHAR
#include "../../ThirdParty/wchar/stdlib_.h"
#include "../../ThirdParty/wchar/wchar_.h"
#define Od_atof       Citrus::atof
#define Od_abs        Citrus::abs
#define Od_labs       Citrus::labs
#define Od_llabs      Citrus::llabs
#define Od_srand      Citrus::srand
#define Od_rand       Citrus::rand
#define Od_wcstombs   Citrus::wcstombs
#define Od_wcscpy     Citrus::wcscpy
#define Od_wcscmp     Citrus::wcscmp
#define Od_wcscat     Citrus::wcscat
#define Od_wcschr     Citrus::wcschr
#define Od_wcscpy     Citrus::wcscpy
#define Od_wcslen     Citrus::wcslen
#define Od_wcsncpy    Citrus::wcsncpy  
#else

#if defined(_MSC_VER) && (_MSC_VER < 1600)
#include <stdlib.h>
#else
#include <cstdlib>
#include <cmath>
#endif

#if defined(__BCPLUSPLUS__) || defined(__BORLANDC__) || defined(__sun)
inline long  Od_abs(OdInt64 val) { return std::labs(val); }
inline int  Od_abs(OdInt32 val) { return std::abs(val); }
#if OD_SIZEOF_LONG == 4
inline int  Od_abs(int val) { return std::abs(val); }
#endif
inline double  Od_abs(double val) { return std::fabs(val); }
#else
#define Od_abs        std::abs
#endif

#define Od_atof       atof
#define Od_labs       std::labs
#define Od_llabs      std::llabs
#define Od_srand      srand
#define Od_rand       rand
#define Od_wcstombs   wcstombs
#define Od_wcscpy     wcscpy
#define Od_wcscmp     wcscmp
#define Od_wcscat     wcscat
#define Od_wcschr     wcschr
#define Od_wcslen     wcslen
#define Od_wcsncpy    wcsncpy
#endif

#ifdef OD_STRING_FNS


extern int Od_stricmp(const OdChar*str, const OdChar* str2);
extern int Od_strnicmp(const OdChar *s1, const OdChar *s2, int len);
extern OdChar* Od_strupr(OdChar* str);
extern OdChar* Od_strlwr(OdChar* str);
extern OdChar* Od_strrev(OdChar* str);
extern int Od_strnicmpA(const char *s1, const char *s2, int len);
extern int Od_stricmpA(const char* str, const char* str2);
extern char* Od_struprA(char* str);
extern char* Od_strlwrA(char* str);
extern char* Od_strrevA(char* str);

#define odStrICmp(str, str2) Od_stricmp(str, str2)
#define odStrnICmp(str, str2, n) Od_strnicmp(str, str2, n)
#define odStrnICmpA Od_strnicmpA
#define odStrUpr(str) Od_strupr(str)
#define odStrLwr(str) Od_strlwr(str)
#define odStrRev(str) Od_strrev(str)
#define odStrICmpA(str, str2) Od_stricmpA(str, str2)
#define odStrUprA(str) Od_struprA(str)
#define odStrLwrA(str) Od_strlwrA(str)
#define odStrRevA(str) Od_strrevA(str)


#endif  /*  OD_STRING_FNS  */

/*   strings functions  */

#include <wchar.h>

#ifndef odStrLen
#define odStrLen(str)         wcslen(str)
#endif

#ifndef odStrLenA
#define odStrLenA(str)        strlen(str)
#endif

#ifndef odStrCmp
#define odStrCmp(str, str2)   wcscmp(str, str2)
#endif

#ifndef odStrCmpA
#define odStrCmpA(str, str2)  strcmp(str, str2)
#endif

#if defined(_WIN32) ||defined(_WIN64) || defined(_WIN32_WCE)
#include <Windows.h>
#endif


#ifndef odStrICmp
#if defined(_WIN32) ||defined(_WIN64) || defined(_WIN32_WCE)
inline int Od_stricmpW(const OdChar* str, const OdChar* str2){ return CompareStringW( LOCALE_NEUTRAL, NORM_IGNORECASE, (const wchar_t*)str, -1, (const wchar_t*)str2, -1) - 2; }
#elif (defined ( __BORLANDC__ ) && (__BORLANDC__) >= 0x530) ||(defined(_MSC_VER) && _MSC_VER > 1200)
inline int Od_stricmpW(const OdChar* str, const OdChar* str2){ return _wcsicmp(str, str2); }
#else
inline int Od_stricmpW(const OdChar* str, const OdChar* str2){ return wcsicmp(str, str2); }
#endif
#define odStrICmp Od_stricmpW
#endif

#ifndef odStrICmpA
#define odStrICmpA(str, str2) stricmp(str, str2)
#endif

#ifndef odStrnICmp
#if defined(_WIN32) ||defined(_WIN64) || defined(_WIN32_WCE)
inline int Od_stricmpW(const OdChar* str, const OdChar* str2, size_t n){ return CompareStringW( LOCALE_NEUTRAL, NORM_IGNORECASE, (const wchar_t*)str, (int)odmin(wcslen((const wchar_t*)str), n), (const wchar_t*)str2, (int)odmin(wcslen((const wchar_t*)str2), n))-2;}
#elif (defined ( __BORLANDC__ ) && (__BORLANDC__) >= 0x530) || (defined(_MSC_VER) && _MSC_VER > 1200)
inline int Od_stricmpW(const OdChar* str, const OdChar* str2, size_t n){ return _wcsnicmp(str, str2, n);}
#else
inline int Od_stricmpW(const OdChar* str, const OdChar* str2, size_t n){ return wcsnicmp(str, str2, n);}
#endif
#define odStrnICmp Od_stricmpW
#endif

#ifndef odStrnICmpA
#define odStrnICmpA(str, str2, n) strnicmp(str, str2, n)
#endif


#ifndef odStrUpr
#if defined(_WIN32) ||defined(_WIN64) || defined(_WIN32_WCE)
inline OdChar* Od_struprW(OdChar* str){return (OdChar*)CharUpperW((wchar_t*)str);}
#elif (defined ( __BORLANDC__ ) && (__BORLANDC__) >= 0x530)  || (defined(_MSC_VER) && _MSC_VER > 1200)
inline OdChar* Od_struprW(OdChar* str){return (OdChar*)_wcsupr((OdChar*)str);}
#else
inline OdChar* Od_struprW(OdChar* str){return (OdChar*)wcsupr((OdChar*)str);}
#endif
#define odStrUpr(str) Od_struprW(str)
#endif

#ifndef odStrUprA
#define odStrUprA(str) strupr(str)
#endif

#ifndef odStrLwr
#if defined(_WIN32) ||defined(_WIN64)
inline OdChar* Od_strlwrW(OdChar* str){return (OdChar*)CharLowerW((wchar_t*)str);}
#elif (defined ( __BORLANDC__ ) && (__BORLANDC__) >= 0x530)  || (defined(_MSC_VER) && _MSC_VER > 1200)
inline OdChar* Od_strlwrW(OdChar* str){return (OdChar*)_wcslwr((OdChar*)str);}
#else
inline OdChar* Od_strlwrW(OdChar* str){return (OdChar*)wcslwr((OdChar*)str);}
#endif
#define odStrLwr(str) Od_strlwrW(str)
#endif

#ifndef odStrLwrA
#define odStrLwrA(str) strlwr(str)
#endif

#ifndef odStrRev
#if (defined ( __BORLANDC__ ) && (__BORLANDC__) >= 0x530)  || (defined(_MSC_VER) && _MSC_VER > 1200)
inline OdChar* Od_strrevW(OdChar* str) {return (OdChar*)_wcsrev((wchar_t*)str);}
#else
inline OdChar* Od_strrevW(OdChar* str) {return (OdChar*)wcsrev((wchar_t*)str);}
#endif
#define odStrRev(str) Od_strrevW(str)
#endif

#ifndef odStrRevA
#define odStrRevA(str) strrev(str)
#endif

#ifndef odStrToInt
inline long Od_strtoint(const OdChar* str){ return wcstol((const wchar_t*)str, 0, 10);}
#define odStrToInt(str) Od_strtoint(str)
#endif

#if (defined(sgi) || defined(_AIX) || defined(sparc)) && !defined(__GNUC__)
#define TD_NEED_SWFNS
#endif

#if !defined(odSScanf) && (defined(TD_NEED_SWFNS) || defined(__APPLE__))
#include <wchar.h>
#include <stdio.h>
#include <stdarg.h>
#include <string>
FIRSTDLL_EXPORT int Od_vswscanfV(const wchar_t* buffer, const wchar_t* lpszFormat, va_list argList);
inline int ddswscanf(const wchar_t* buffer, const wchar_t* format, ...)
{
  va_list argList;
  va_start(argList, format);
  int count = Od_vswscanfV(buffer, format, argList);
  va_end(argList);
  return count;
}
#define odSScanf ddswscanf
#else
#define odSScanf swscanf
#endif

#ifndef odSprintf
  #if defined(WIN32) || defined(WIN64) || defined(_WIN32_WCE)
    #define odSprintf _snwprintf
  #elif defined(TD_NEED_SWFNS)
    #include <stdio.h>
    #include <stdarg.h>
    #include <string>
    extern std::wstring Od_vswprintfV(const wchar_t* lpszFormat, va_list argList);
    inline int ddswprintf(wchar_t *buffer, size_t count, const wchar_t *format, ...)
    {
      va_list argList;
      va_start(argList, format);
      std::wstring ws = Od_vswprintfV(format, argList);
      va_end(argList);
      int toCopy = ws.length() < count - 1 ? ws.length() : count - 1;
      wcsncpy(buffer, ws.c_str(), toCopy);
      buffer[toCopy] = '\0';
      return 0;
    }
    #define odSprintf ddswprintf
  #else
    #define odSprintf swprintf
  #endif
#endif

#ifndef odStrToF
#define odStrToF _wtof
#endif


#ifndef OD_TYPENAME
#define OD_TYPENAME
#endif

#ifndef OD_TYPENAME2
#define OD_TYPENAME2
#endif

#ifndef OD_TYPENAME3
#define OD_TYPENAME3
#endif

#ifndef OD_BSEARCH
#define OD_BSEARCH ::bsearch
#endif

#ifndef TD_USING
#define TD_USING(a) using a
#endif

#ifndef OD_LINKEDARRAY_SCOPE
#define OD_LINKEDARRAY_SCOPE
#endif

#ifdef TD_NEED_WCSSTR
// This is missing on some older HP compiler versions.
extern wchar_t *wcsstr(const wchar_t* wcs1, const wchar_t* wcs2);
#endif



////////////////////////////////////////////////////////////////////////////////////////////////
#define OD_MAKEWORD(a, b)      ((OdUInt16)(((OdUInt8)(a)) | ((OdUInt16)((OdUInt8)(b))) << 8))
#define OD_MAKELONG(a, b)      ((OdInt32)(((OdUInt16)(a)) | ((OdUInt32)((OdUInt16)(b))) << 16))
#define OD_LOWORD(l)           ((OdUInt16)(l))
#define OD_HIWORD(l)           ((OdUInt16)(((OdUInt32)(l) >> 16) & 0xFFFF))
#define OD_LOBYTE(w)           ((OdUInt8)(w))
#define OD_HIBYTE(w)           ((OdUInt8)(((OdUInt16)(w) >> 8) & 0xFF))

// Gcad(Add)
#define OD_MAKEQWORD(l, h)    ((OdUInt64)(((OdUInt32)(l)) | ((OdUInt64)((OdUInt32)(h))) << 32))
#define OD_MAKELONGLONG(l, h) ((OdInt64)(((OdUInt32)(l)) | ((OdInt64)((OdUInt32)(h))) << 32))
#define OD_LODWORD(qw)        ((OdUInt32)(qw))
#define OD_HIDWORD(qw)        ((OdUInt32)(((OdUInt64)(qw) >> 32) & 0xFFFFFFFF))
// Gcad(Add)

inline void odSwapBytes(OdUInt8& xX, OdUInt8& yY) { xX ^= yY; yY ^= xX; xX ^= yY; }
inline void odSwapWords(OdUInt16& xX, OdUInt16& yY) { xX ^= yY; yY ^= xX; xX ^= yY; }

#ifdef ODA_BIGENDIAN

inline void odSwap2BytesNumber(OdInt16& W) 
{ 
  odSwapBytes(((OdUInt8*)&(W))[0], ((OdUInt8*)&(W))[1]); 
}

inline void odSwap4BytesNumber(OdUInt32& DW)
{
  odSwapWords(((OdUInt16*)&(DW))[0], ((OdUInt16*)&(DW))[1]);
  odSwapBytes(((OdUInt8*)&(DW))[0], ((OdUInt8*)&(DW))[1]);
  odSwapBytes(((OdUInt8*)&(DW))[2], ((OdUInt8*)&(DW))[3]);
}

inline void odSwap4BytesNumber(OdInt32& DW)
{
  // NOTE: Using above unsigned version on AIX results in runtime errors.
  // Macro version also causes errors on AIX.
  OdInt8* p = (OdInt8*)&DW;
  OdInt8 tmp;
  tmp = p[0]; p[0] = p[3]; p[3] = tmp;
  tmp = p[1]; p[1] = p[2]; p[2] = tmp;
}

inline void odSwap8Bytes(void* pBytes)
{
  odSwapBytes(((OdUInt8*)(pBytes))[0], ((OdUInt8*)(pBytes))[7]);
  odSwapBytes(((OdUInt8*)(pBytes))[1], ((OdUInt8*)(pBytes))[6]);
  odSwapBytes(((OdUInt8*)(pBytes))[2], ((OdUInt8*)(pBytes))[5]);
  odSwapBytes(((OdUInt8*)(pBytes))[3], ((OdUInt8*)(pBytes))[4]);
}

inline void odSwapInt64(void* pBytes)
{
  odSwapBytes(((OdUInt8*)(pBytes))[0], ((OdUInt8*)(pBytes))[4]);
  odSwapBytes(((OdUInt8*)(pBytes))[1], ((OdUInt8*)(pBytes))[5]);
  odSwapBytes(((OdUInt8*)(pBytes))[2], ((OdUInt8*)(pBytes))[6]);
  odSwapBytes(((OdUInt8*)(pBytes))[3], ((OdUInt8*)(pBytes))[7]);
}

#else

#define odSwap2BytesNumber(n)
#define odSwap4BytesNumber(n)
#define odSwap8Bytes(bytes)

inline void odSwapInt64(void* pBytes)
{
  odSwapBytes(((OdUInt8*)(pBytes))[0], ((OdUInt8*)(pBytes))[7]);
  odSwapBytes(((OdUInt8*)(pBytes))[1], ((OdUInt8*)(pBytes))[6]);
  odSwapBytes(((OdUInt8*)(pBytes))[2], ((OdUInt8*)(pBytes))[5]);
  odSwapBytes(((OdUInt8*)(pBytes))[3], ((OdUInt8*)(pBytes))[4]);
}

#endif // ODA_BIGENDIAN

/** Description
  Checks if 8 bytes buffer represents a valid non-zero IEEE double value.
  (In this format doubles are stored in .dwg files.)
*/
inline bool isValidNonZeroIEEEDouble(const OdUInt8 * buf)
{
#ifdef ODA_BIGENDIAN
  int nExponent = (buf[0] & 0x7F) << 4 | (buf[1] & 0xF0) >> 4;
#else
  int nExponent = (buf[7] & 0x7F) << 4 | (buf[6] & 0xF0) >> 4;
#endif
  switch (nExponent)
  {
  case 0:     // The value is zero or possibly denormalized
  case 2047:  // -INF, +INF or Nan
    return false;
  }
  return true;
}

inline void fixDouble(double * pD)
{
  ODA_ASSUME(sizeof(double) == 8)
  odSwap8Bytes(pD);
  if (!isValidNonZeroIEEEDouble((OdUInt8 *)pD))
  { // if unnormalized or NaN or infinity, set it to 0.0
    //*pD = 0.;
    ::memset((void*)pD, 0, sizeof(double)); // Support TD_STRICT_ALIGNMENT (#8352)
  }
}


#define OD_INT8_FROM_BUFFPTR(pBuffPtr) *(pBuffPtr++)

inline OdUInt64 OD_INT64_FROM_BUFFPTR(const OdUInt8 *pBuffPtr)
{
  OdUInt32 low(*pBuffPtr++);
  low |= ((OdUInt32)*pBuffPtr++) << 8;
  low |= ((OdUInt32)*pBuffPtr++) << 16;
  low |= ((OdUInt32)*pBuffPtr++) << 24;

  OdUInt32 high(*pBuffPtr++);
  high |= ((OdUInt32)*pBuffPtr++) << 8;
  high |= ((OdUInt32)*pBuffPtr++) << 16;
  high |= ((OdUInt32)*pBuffPtr++) << 24;

  OdUInt64 res(high);
  res <<= 32;
  res |= low;
  return res;
}

#define OD_BYTES_FROM_BUFFPTR(pBuffPtr, ResBuff, nCount) (pBuffPtr+=nCount, ::memcpy(ResBuff, pBuffPtr-nCount, nCount))

#define OD_INT8_TO_BUFFPTR(pBuffPtr, val) (++pBuffPtr, pBuffPtr[-1] = OdUInt8(val))
#define OD_BYTES_TO_BUFFPTR(pBuffPtr, FromBuff, nCount) (pBuffPtr+=nCount, ::memcpy(pBuffPtr-nCount, FromBuff, nCount))



#ifndef ODA_BIGENDIAN

#ifdef TD_STRICT_ALIGNMENT

extern double getStrictDouble(OdUInt8** ppBuff);
extern void setStrictDouble(OdUInt8** ppBuff, double d);
extern void setStrictInt16(OdUInt8** ppBuff, OdInt16 val);
extern void setStrictInt32(OdUInt8** ppBuff, OdInt32 val);
extern void setStrictInt64(OdUInt8** ppBuff, OdInt64 val);

#define OD_INT16_FROM_BUFFPTR(pBuffPtr) (pBuffPtr += 2,   (OdInt16)(   *(pBuffPtr - 2)          \
                                                                    | (*(pBuffPtr - 1) << 8)))
#define OD_INT32_FROM_BUFFPTR(pBuffPtr) (pBuffPtr += 4,   (OdInt32)(   *(pBuffPtr - 4)          \
                                                                    | (*(pBuffPtr - 3) << 8)    \
                                                                    | (*(pBuffPtr - 2) << 16)   \
                                                                    | (*(pBuffPtr - 1) << 24)))
#define OD_INT64_FROM_BUFFPTR(pBuffPtr) (pBuffPtr += 8,   (OdInt64)(   *(pBuffPtr - 8)          \
                                                                    | (*(pBuffPtr - 7) << 8)    \
                                                                    | (*(pBuffPtr - 6) << 16)   \
                                                                    | (*(pBuffPtr - 5) << 24)   \
                                                                    | (*(pBuffPtr - 4) << 32)   \
                                                                    | (*(pBuffPtr - 3) << 40)   \
                                                                    | (*(pBuffPtr - 2) << 48)   \
                                                                    | (*(pBuffPtr - 1) << 56)))

#define OD_DOUBLE_FROM_BUFFPTR(pBuffPtr) getStrictDouble(&pBuffPtr)

#define OD_INT16_TO_BUFFPTR(pBuffPtr, val) setStrictInt16(&pBuffPtr, val)
#define OD_INT32_TO_BUFFPTR(pBuffPtr, val) setStrictInt32(&pBuffPtr, val)
#define OD_INT64_TO_BUFFPTR(pBuffPtr, val) setStrictInt64(&pBuffPtr, val)

#define OD_DOUBLE_TO_BUFFPTR(pBuffPtr, val) setStrictDouble(&pBuffPtr, val)


#else

inline double getValidDouble(OdUInt8** ppBuff)
{
  double d = isValidNonZeroIEEEDouble(*ppBuff) ? *((double*)(*ppBuff)) : 0.0;
  *ppBuff+=8;
  return d;
}

#define OD_INT16_FROM_BUFFPTR(pBuffPtr) (pBuffPtr += 2, *((OdInt16*)(pBuffPtr - 2)))
#define OD_INT32_FROM_BUFFPTR(pBuffPtr) (pBuffPtr += 4, *((OdInt32*)(pBuffPtr - 4)))
#define OD_INT64_FROM_BUFFPTR(pBuffPtr) (pBuffPtr += 8, *((OdInt64*)(pBuffPtr - 8)))

#define OD_DOUBLE_FROM_BUFFPTR(pBuffPtr) getValidDouble(&pBuffPtr)
//#define OD_POINT3D_FROM_BUFFPTR(pBuffPtr) (pBuffPtr+=24, *((OdGePoint3d*)(pBuffPtr-24)))

#define OD_INT16_TO_BUFFPTR(pBuffPtr, val) (pBuffPtr+=2, *((OdInt16*)(pBuffPtr-2)) = OdInt16(val))
#define OD_INT32_TO_BUFFPTR(pBuffPtr, val) (pBuffPtr+=4, *((OdInt32*)(pBuffPtr-4)) = OdInt32(val))
#define OD_INT64_TO_BUFFPTR(pBuffPtr, val) (pBuffPtr+=8, *((OdInt64*)(pBuffPtr-8)) = OdInt64(val))

#define OD_DOUBLE_TO_BUFFPTR(pBuffPtr, val) (pBuffPtr+=8, *((double*)(pBuffPtr-8)) = double(val))
//#define OD_POINT3D_TO_BUFFPTR(pBuffPtr, val) (pBuffPtr+=24, *((OdGePoint3d*)(pBuffPtr-24)) = val)

#endif // TD_STRICT_ALIGNMENT


#else


extern double getBeDouble(OdUInt8** ppBuff);
//extern OdGePoint3d getBePnt3d(OdUInt8** ppBuff);
extern void setStrictInt16(OdUInt8** ppBuff, OdInt16 val);
extern void setStrictInt32(OdUInt8** ppBuff, OdInt32 val);
extern void setStrictInt64(OdUInt8** ppBuff, OdInt64 val);
extern void setBeDouble(OdUInt8** ppBuff, double d);
//extern void setBePnt3(OdUInt8** ppBuff, const OdGePoint3d& p);


// SGI doesn't like these versions.
//#define OD_INT16_FROM_BUFFPTR(pBuffPtr) ((OdInt16)(*pBuffPtr++ | (*pBuffPtr++ << 8)))
//#define OD_INT32_FROM_BUFFPTR(pBuffPtr) ((OdInt32)(*pBuffPtr++ | (*pBuffPtr++ << 8) | (*pBuffPtr++ << 16) | (*pBuffPtr++ << 24)))
// So use these instead
#define OD_INT16_FROM_BUFFPTR(pBuffPtr) (pBuffPtr += 2, (OdInt16)(   *(pBuffPtr - 2)          \
                                                                  | (*(pBuffPtr - 1) << 8)))
#define OD_INT32_FROM_BUFFPTR(pBuffPtr) (pBuffPtr += 4, (OdInt32)(   *(pBuffPtr - 4)          \
                                                                  | (*(pBuffPtr - 3) << 8)    \
                                                                  | (*(pBuffPtr - 2) << 16)   \
                                                                  | (*(pBuffPtr - 1) << 24)))
#define OD_INT64_FROM_BUFFPTR(pBuffPtr) (pBuffPtr += 8, (OdInt64)(   *(pBuffPtr - 8)          \
                                                                  | (*(pBuffPtr - 7) << 8)    \
                                                                  | (*(pBuffPtr - 6) << 16)   \
                                                                  | (*(pBuffPtr - 5) << 24)   \
                                                                  | (*(pBuffPtr - 4) << 32)   \
                                                                  | (*(pBuffPtr - 3) << 40)   \
                                                                  | (*(pBuffPtr - 2) << 48)   \
                                                                  | (*(pBuffPtr - 1) << 56)))

#define OD_DOUBLE_FROM_BUFFPTR(pBuffPtr) getBeDouble(&pBuffPtr)
//#define OD_POINT3D_FROM_BUFFPTR(pBuffPtr) getBePnt3d(&pBuffPtr)

#define OD_INT16_TO_BUFFPTR(pBuffPtr, val) setStrictInt16(&pBuffPtr, val)
#define OD_INT32_TO_BUFFPTR(pBuffPtr, val) setStrictInt32(&pBuffPtr, val)
#define OD_INT64_TO_BUFFPTR(pBuffPtr, val) setStrictInt64(&pBuffPtr, val)

#define OD_DOUBLE_TO_BUFFPTR(pBuffPtr, val) setBeDouble(&pBuffPtr, val)
//#define OD_POINT3D_TO_BUFFPTR(pBuffPtr, val) setBePnt3(&pBuffPtr, val)

#endif // ODA_BIGENDIAN


#if defined(_WIN32) || defined(WIN64)
#include "WINDOWS.H"
#include "WINGDI.H"
#endif

#if defined(_WIN32) && !defined(WIN64)
// COLORREF on WIN64 is 8 bytes
#define ODCOLORREF COLORREF
#define ODRGB(r,g,b) RGB(r,g,b)
#define ODRGBA(r,g,b,a) (((ODCOLORREF)ODRGB(r,g,b))|(((DWORD)(BYTE)(a))<<24))
#define ODGETRED(rgb) GetRValue(rgb)
#define ODGETGREEN(rgb) GetGValue(rgb)
#define ODGETBLUE(rgb) GetBValue(rgb)
#define ODGETALPHA(rgba) ((BYTE)((rgba)>>24))

#else //#ifdef _WIN32

#define ODCOLORREF OdUInt32
#define ODRGB(r,g,b) ((ODCOLORREF)(((OdUInt8)(r)|((OdUInt16)((OdUInt8)(g))<<8))|(((OdUInt32)(OdUInt8)(b))<<16)))
#define ODRGBA(r,g,b,a) (((ODCOLORREF)ODRGB(r,g,b))|(((OdUInt32)(OdUInt8)(a))<<24))

#define ODGETRED(rgb)     ((OdUInt8)(rgb))
#define ODGETGREEN(rgb)   ((OdUInt8)(((OdUInt16)(rgb)) >> 8))
#define ODGETBLUE(rgb)    ((OdUInt8)((rgb)>>16))
#define ODGETALPHA(rgba)  ((OdUInt8)((rgba)>>24))

#ifndef WIN64
/** Description:
  {group:Structs}
*/      
typedef struct tagRGBQUAD 
{
  OdUInt8  rgbBlue;
  OdUInt8  rgbGreen;
  OdUInt8  rgbRed;
  OdUInt8  rgbReserved;
} RGBQUAD, *LPRGBQUAD;

/** Description:
  {group:Structs}
*/      
typedef struct tagBITMAPINFOHEADER {
  OdUInt32  biSize;
  OdInt32   biWidth;
  OdInt32   biHeight;
  OdUInt16  biPlanes;
  OdUInt16  biBitCount;
  OdUInt32  biCompression;
  OdUInt32  biSizeImage;
  OdInt32   biXPelsPerMeter;
  OdInt32   biYPelsPerMeter;
  OdUInt32  biClrUsed;
  OdUInt32  biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

/** Description:
  {group:Structs}
*/      
typedef struct tagBITMAPFILEHEADER 
{
  OdUInt16 bfType;
  OdUInt32 bfSize;
  OdUInt16 bfReserved1;
  OdUInt16 bfReserved2;
  OdUInt32 bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;
#endif

#endif //#ifdef _WIN32

#define ODTOCMCOLOR(colorref) OdCmEntityColor( ODGETRED(colorref), ODGETGREEN(colorref), ODGETBLUE(colorref) )
#define ODTOCOLORREF(cmColor) ODRGB( cmColor.red(), cmColor.green(), cmColor.blue() )

//////////////////////////////////////////////////////////////////////////
//  IR.111706. MacOS X dynamic library loading.
//  Some code taken from Dlcompat open source library.
//  www.opendarwin.org/projects/dlcompat/

#if defined(_TOOLKIT_IN_DLL_) && defined(__GNUC__) && defined(__APPLE__) // GNU compiler MacOS X

#include <mach-o/dyld.h>

#   ifndef RTLD_LAZY
#     define RTLD_LAZY	0x1
#   endif
#   ifndef RTLD_NOW
#     define RTLD_NOW	0x2
#   endif
#   ifndef RTLD_LOCAL
#     define RTLD_LOCAL	0x4
#   endif
#   ifndef RTLD_GLOBAL
#     define RTLD_GLOBAL	0x8
#   endif
#   ifndef RTLD_NOLOAD
#     define RTLD_NOLOAD	0x10
#   endif
#   ifndef RTLD_NODELETE
#     define RTLD_NODELETE	0x80
#   endif

class OdString;
void* LoadSharedLibrary(const OdString& path, int mode = 2);
void *GetFunction(void *handle, char *symbol);
bool FreeSharedLibrary(void *handle);

#endif //defined(__GNUC__) && defined(__APPLE__) // GNU compiler MacOS X

#if defined(_TOOLKIT_IN_DLL_) && defined(__GNUC__) && !defined(__APPLE__) // GNU compiler Linux

#include <dlfcn.h>

#endif // defined(_TOOLKIT_IN_DLL_) && defined(__GNUC__) && !defined(__APPLE__) // GNU  compiler Linux

#include <time.h>

size_t od_strftime(char *s, size_t maxsize, const char *format, const struct tm *t);


//////////////////////////////////////////////////////////////////////////

#endif // _OD_PLATFORM_H_

