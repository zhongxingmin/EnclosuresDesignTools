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

#ifndef __ODGICONVEYORCONNECTOR__
#define __ODGICONVEYORCONNECTOR__

#include "../Gi/GiConveyorNode.h"
#include "../OdArray.h"

#include "../TD_PackPush.h"


/** Description:
    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiConveyorConnector : public OdGiConveyorInput, public OdGiConveyorOutput
{
  /** Description:
    This template class is a specialization of the OdArray class for OdGiConveyorOutput object pointers.
  */
  typedef OdArray<OdGiConveyorOutput*, OdMemoryAllocator<OdGiConveyorOutput*> > NodeArray;

  NodeArray             m_sources;
  OdGiConveyorGeometry* m_pDestGeom;
public:
  OdGiConveyorConnector();

  void addSourceNode(OdGiConveyorOutput& sourceNode);
  void removeSourceNode(OdGiConveyorOutput& sourceNode);
  void setDestGeometry(OdGiConveyorGeometry& destGeometry);
  OdGiConveyorGeometry& destGeometry() const;
  /** Description:
    Returns a reference to the OdGiConveyorGeometry object associated with this object.  
  */
  OdGiConveyorGeometry& geometry();
};

inline OdGiConveyorGeometry& OdGiConveyorConnector::geometry() { return *m_pDestGeom; }

#include "../TD_PackPop.h"


#endif // __ODGICONVEYORCONNECTOR__
