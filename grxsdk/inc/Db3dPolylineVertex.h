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




#ifndef _OD_DB_3DPOLYLINE_VERTEX_
#define _OD_DB_3DPOLYLINE_VERTEX_

#include "TD_PackPush.h"

#include "DbVertex.h"

/** Description:
    This class represents OdDb3dPolyline vertices in an OdDbDatabase instance.
  
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDb3dPolylineVertex : public OdDbVertex
{
public:

  ODDB_DECLARE_MEMBERS(OdDb3dPolylineVertex);

 /**
    Remarks:
    Newly created vertices are of type OdDb::k3dSimpleVertex.
  */
  OdDb3dPolylineVertex();

  /** 
  Gcad(Add):增加兼容接口	
  */
  OdDb3dPolylineVertex(const OdGePoint3d&);
  /** 
  Gcad(Add):增加兼容接口	
  */
  ~OdDb3dPolylineVertex();
  
  /** Description:
    Returns the type of this Vertex entity.  
    
    Remarks:
    vertexType() returns one of the following:

    @table
    Name                     Value   DXF 70   Description
    OdDb::k3dSimpleVertex    0       0x40     Standard vertex.
    OdDb::k3dControlVertex   1       0x10     Spline-fit or curve-fit control point.
    OdDb::k3dFitVertex       2       0x08     Spline-fit or curve-fit generated vertex.
  */
  OdDb::Vertex3dType vertexType() const;

  /** Description:
    Sets the type of this Vertex entity.

    Arguments:
    vertexType (I) Vertex type.

    Remarks:
    vertexType type must be one of the following:

    @table
    Name                     Value   DXF 70   Description
    OdDb::k3dSimpleVertex    0       0x40     Standard vertex.
    OdDb::k3dControlVertex   1       0x10     Spline-fit or curve-fit control point.
    OdDb::k3dFitVertex       2       0x08     Spline-fit or curve-fit generated vertex.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setVertexType(
    OdDb::Vertex3dType vertexType);

  /** Description:
    Returns the WCS *position* of this entity (DXF 10).
  */
  OdGePoint3d position() const;

  /** Description:
    Sets the WCS *position* of this entity (DXF 10).
    Arguments:
    position (I) Position.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setPosition(
    const OdGePoint3d& position);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subGetGeomExtents( // Gcad(Modify)
    OdDbExtents& extents) const ODRX_OVERRIDE;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm) ODRX_OVERRIDE;


  /*
     OdDb3dPolylineVertex(const OdGePoint3d&);
  */
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDb3dPolylineVertex object pointers.
*/
typedef OdSmartPtr<OdDb3dPolylineVertex> OdDb3dPolylineVertexPtr;

#include "TD_PackPop.h"

#endif

