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

#ifndef _ODSYSVARINFO_H_
#define _ODSYSVARINFO_H_


#include "RxObject.h"

class OdDbDatabase;
class OdDbCommandContext;


/** Description:
    {group:Other_Classes}
*/
class OdSysVarInfo : public OdRxObject
{
protected:
  OdSysVarInfo()
    : m_getFn(0)
    , m_setFn(0)
	, m_setRoFn(0)
    , m_mapTypeFn(0)
  {}
public:
  typedef OdResBufPtr (*GetFn)(const OdDbDatabase* pDb);
  typedef void (*SetFn)(OdDbDatabase* pDb, const OdResBuf* pRbValue);

  enum
  {
    kToAcadType = 0,
    kToDDType   = 1
  };
  typedef void (*MapTypeFn)(OdDbDatabase* pDb, OdResBuf* pVal, int opt);

  GetFn       m_getFn;
  SetFn       m_setFn;
  SetFn		  m_setRoFn;

  MapTypeFn   m_mapTypeFn;
};

/** Description:
    {group:Other_Classes}
*/
class OdSetVarInfo : public OdRxObject
{
protected:
  OdSetVarInfo()
    : m_formatFn(0)
    , m_promptFn(0)
  {}
public:
  typedef OdString (*FormatFn)(OdDbDatabase* pDbCmdCtx, const OdResBuf* pRbValue);
  typedef void (*PromptFn)(OdDbCommandContext* pDbCmdCtx, const OdString& varName, OdResBuf* pVal);

  FormatFn  m_formatFn;
  PromptFn  m_promptFn;
};

#endif //#ifndef _ODSYSVARINFO_H_
