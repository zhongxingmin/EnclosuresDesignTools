/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2014, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2003-2014 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef ODDGNLS_DBLSCOMPOUNDCOMPONENT_H
#define ODDGNLS_DBLSCOMPOUNDCOMPONENT_H

#include "DbLSComponent.h"

#include "TD_PackPush.h"

/** Description:
    Dgn Line Style Compound Component.
    Library:
    TD_Db
    {group:OdDbLS_Classes} 
*/
class ODDGNLS_EXPORT OdDbLSCompoundComponent : public OdDbLSComponent
{
  public:
    ODDB_DECLARE_MEMBERS(OdDbLSCompoundComponent);

    OdDbLSCompoundComponent();

    /**
      Description:
      Append new component to compound component.

      Arguments:
      comId (I) Identifier of component to add.
      compOffset (I) Component offset to add.
    */
    void appendComponent(const OdDbObjectId &compId, double compOffset = 0.0);
    /**
      Description:
      Remove existing component from this compound component.

      Arguments:
      nComponent (I) Index of component to remove.
    */
    void deleteComponent(OdUInt32 nComponent);

    /**
      Description:
      Returns count of components in this compound component.
    */
    OdUInt32 numberComponents() const;

    /**
      Description:
      Returns component identifier from this compound component.

      Arguments:
      nComponent (I) Index of component to retreive identifier.
    */
    OdDbObjectId component(OdUInt32 nComponent) const;

    /**
      Description:
      Returns component offset from this compound component.

      Arguments:
      nComponent (I) Index of component to retreive offset.
    */
    double offsetToComponent(OdUInt32 nComponent) const;
    /**
      Description:
      Reset component offset of existing component in this compound component.

      Arguments:
      nComponent (I) Index of component to reset offset.
      newOffset (I) New component offset.
    */
    void setOffsetToComponent(OdUInt32 nComponent, double newOffset);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLSCompoundComponent object pointers.
*/
typedef OdSmartPtr<OdDbLSCompoundComponent> OdDbLSCompoundComponentPtr;

#include "TD_PackPop.h"

#endif // ODDGNLS_DBLSCOMPOUNDCOMPONENT_H