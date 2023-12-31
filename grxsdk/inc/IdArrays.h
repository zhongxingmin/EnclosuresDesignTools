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

#ifndef _IDARRAY_H_
#define _IDARRAY_H_

#include "OdArray.h"
#include "DbTypedId.h"

/** Description:
    This template class is a specialization of the OdArray class for OdDbSoftPointerId objects.
*/
typedef OdArray<OdDbSoftPointerId, OdMemoryAllocator<OdDbSoftPointerId> > OdSoftPtrIdArray;

/** Description:
    This template class is a specialization of the OdArray class for OdDbHardPointerId objects.
*/
typedef OdArray<OdDbHardPointerId, OdMemoryAllocator<OdDbHardPointerId> > OdHardPtrIdArray;

/** Description:
    This template class is a specialization of the OdArray class for OdDbSoftOwnershipId objects.
*/
typedef OdArray<OdDbSoftOwnershipId, OdMemoryAllocator<OdDbSoftOwnershipId> > OdSoftOwnIdArray;

/** Description:
    This template class is a specialization of the OdArray class for OdDbHardOwnershipId objects.
*/
typedef OdArray<OdDbHardOwnershipId, OdMemoryAllocator<OdDbHardOwnershipId> > OdHardOwnIdArray;

/** Description:
    This template class is a specialization of the OdArray class for OdDbObjectId objects.
*/
typedef OdArray<OdDbObjectId/*, OdMemoryAllocator<OdDbObjectId> */> OdDbObjectIdArray;

/** Description:
    This template class is a specialization of the OdArray class for OdDbTypedId objects.
*/
typedef OdArray<OdDbTypedId, OdMemoryAllocator<OdDbTypedId> > OdTypedIdsArray;


#endif //_IDARRAY_H_
