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




#ifndef _SmCalloutBlocks_h_Included_
#define _SmCalloutBlocks_h_Included_

#include "../Sm/SmComponent.h"
#include "../Sm/SmNamedDbObjectReference.h"
#include "../Sm/SmEnum.h"

/** Description: 
  
    {group:TD_Namespaces}
*/
namespace dst
{
  typedef OdSmEnum<OdSmDbBlockRecordReference>OdSmEnumDbBlockRecordReference;
  typedef OdSmartPtr<OdSmEnumDbBlockRecordReference> OdSmEnumDbBlockRecordReferencePtr;

/** Description:

     
*/
  struct SMDLL_EXPORT OdSmCalloutBlocks : OdSmComponent
  {
    ODRX_DECLARE_MEMBERS(OdSmCalloutBlocks);
    virtual void add( OdSmDbBlockRecordReference* pBlkRef ) = 0;
    virtual void remove( OdSmDbBlockRecordReference* pBlkRef ) = 0;
    virtual OdSmEnumDbBlockRecordReferencePtr getEnumerator() const = 0;
  };
  typedef OdSmartPtr<OdSmCalloutBlocks> OdSmCalloutBlocksPtr;
}

#endif //_SmCalloutBlocks_h_Included_
