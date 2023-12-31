/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////

#ifndef _ODA_COMMON_INCLUDED_
#define _ODA_COMMON_INCLUDED_

#ifdef _MSC_VER
#pragma warning(disable: 4710)  // 'function' : function not inlined
#pragma warning(disable: 4100)  // unreferenced formal parameter
#endif

#define ODA_AC27_SUPPORT

#include "TDVersion.h"
#include "DbExport.h"

#include  "OdSysCall.h"
#include  "DebugStuff.h"
#include  "OdaDefs.h"
#include  "RxDefs.h"
#include  "OdPlatform.h"
#include  "OdAllocX.h"
#include  <assert.h>
#include  "OdModuleNames.h"

#define OdaPI 3.14159265358979323846
#define OdaPI2 (OdaPI / 2.0)
#define OdaPI4 (OdaPI / 4.0)
#define Oda2PI (OdaPI+OdaPI)
#define OdaDegree (OdaPI / 180.0)

#define OdaToDegree(rad) ((rad)/OdaPI*180.0)
#define OdaToRadian(deg) ((deg)*OdaPI/180.0)
#define OdaNormalAng(rad) ((rad) - floor((rad) / Oda2PI) * Oda2PI)
#define OdaNormalDegree(deg) ((deg) - floor((deg) / 360.0) * 360.0)

// SSL:
// from http://www.ex.ac.uk/cimt/dictunit/dictunit.htm
//
// Even as late as the middle of the 20th century there were some differences in UK
// and US measures which were nominally the same. The UK inch measured 2.53998 cm while
// the US inch was 2.540005 cm. Both were standardised at 2.54 cm in July 1959.

const double kMmPerInch = 25.4;

#endif


