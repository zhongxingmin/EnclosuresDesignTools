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

#ifndef ODDB_DBTORUS_H
#define ODDB_DBTORUS_H

#include "../TD_PackPush.h"
#include "DbShPrimitive.h"

/** \details

    \sa
    TD_Db
    <group OdDbSh_Classes> 
*/
class DB3DSOLIDHISTORY_EXPORT OdDbShTorus : public OdDbShPrimitive
{
public:
  ODDB_DECLARE_MEMBERS(OdDbShTorus);
  OdDbShTorus();

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);  
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);  
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  double majorRadius() const;
  double minorRadius() const;
  OdResult setMajorRadius(double dMajorRadius);
  OdResult setMinorRadius(double dMinorRadius);
};

/** \details
    This template class is a specialization of the OdSmartPtr class for OdDbShTorus object pointers.
*/
typedef OdSmartPtr<OdDbShTorus> OdDbShTorusPtr;

#include "../TD_PackPop.h"

#endif

