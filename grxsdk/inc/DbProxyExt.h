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




#ifndef _OD_DB_PROXY_EXT_
#define _OD_DB_PROXY_EXT_

#include "TD_PackPush.h"

#include "RxObject.h"
#include "IdArrays.h"

class OdDbObject;

/** Description:
    This class defines in interface for 
    proxy entities and proxy objects in an OdDbDatabase instance.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbProxyExt : public OdRxObject
{
protected:
  /** Description:
      Constructor (no arguments).
  */
  OdDbProxyExt();

public:
  ODRX_DECLARE_MEMBERS(OdDbProxyExt);

  /** Description:
      Returns the edit flags for the class associated with this proxy.
  */
  virtual int proxyFlags(const OdDbObject* pProxy) const = 0;

  /** Description:
      Returns the class name of the entity stored in this proxy.
  */
  virtual OdString originalClassName(const OdDbObject* pProxy) const = 0;

  /** Description:
      Returns the DXF name of the entity stored in this proxy.
  */
  virtual OdString originalDxfName(const OdDbObject* pProxy) const = 0;

  /** Description:
      Returns the application description for the class associated with this proxy.
  */
  virtual OdString applicationDescription(const OdDbObject* pProxy) const = 0;

  /** Description:
      Returns the references maintained by this proxy.

      Arguments:
      ids (O) Object ID array of references contained in this proxy.
      types (O) Reference type array, where each entry is associated with the 
      corresponding entry in the ids array.
  */
  virtual void getReferences(const OdDbObject* pProxy, OdTypedIdsArray& ids) const = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbProxyExt object pointers.
*/
typedef OdSmartPtr<OdDbProxyExt> OdDbProxyExtPtr;

#include "TD_PackPop.h"

#endif

