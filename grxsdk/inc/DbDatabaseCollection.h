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

#ifndef _DBDATABASECOLLECTION_H_INCLUDED_
#define _DBDATABASECOLLECTION_H_INCLUDED_

#include "RxObject.h"

/** Description:
    This class is a container class for OdDbDatabase objects.

    Library: TD_Db
    {group:OdDb_Classes} 
*/
class ODRX_ABSTRACT TOOLKIT_EXPORT OdDbDatabaseCollection : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbDatabaseCollection);

  /** Description:
    Creates an Iterator *object* that provides access to the OdDbDatabase objects in this collection *object*.
    
    Remarks:
    Returns a SmartPointer to the Iterator *object*.
  */
  virtual OdRxIteratorPtr newIterator() = 0;
  
  /** Description:
    Returns the number of OdDbDatabase objects in this Collection object.
  */
  virtual int count() const = 0;
};

TOOLKIT_EXPORT OdDbDatabaseCollection* oddbDatabaseCollection();

#endif //#ifndef _DBDATABASECOLLECTION_H_INCLUDED_
