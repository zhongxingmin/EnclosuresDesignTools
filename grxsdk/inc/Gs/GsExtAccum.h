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

#ifndef ODGSEXTACCUM_INC
#define ODGSEXTACCUM_INC

#include "../TD_PackPush.h"

#include "../OdArray.h"

#include "../Ge/GeExtents3d.h"

#include "../Gi/GiExtAccum.h"

#include "../Gs/GsExport.h"
#include "../Gs/Gs.h"

class OdGsBaseVectorizeView;

/** Description:
    Base class for Gs conveyor node implementations.

    Library: TD_Gs

    {group:OdGs_Classes}
*/
class GS_TOOLKIT_EXPORT OdGsConveyorNodeBase : public OdGiConveyorInput,
                                               public OdGiConveyorOutput
{
protected:
  typedef OdArray<OdGiConveyorOutput*, OdMemoryAllocator<OdGiConveyorOutput*> > SourceNodeArray;
  SourceNodeArray m_sources;
  OdGiConveyorGeometry *m_pDestGeom;

  class update_geometry
  {
    OdGiConveyorGeometry* m_pGeometry;
  public:
    update_geometry(OdGiConveyorGeometry* pGeometry) : m_pGeometry(pGeometry) {}
    void operator ()(OdGiConveyorOutput* pSourceNode)
    {
      pSourceNode->setDestGeometry(*m_pGeometry);
    }
  };
public:
  OdGsConveyorNodeBase();

  void addSourceNode(OdGiConveyorOutput& sourceNode);
  void removeSourceNode(OdGiConveyorOutput& sourceNode);

  void setDestGeometry(OdGiConveyorGeometry& destGeometry);
  OdGiConveyorGeometry& destGeometry() const;

  void updateLink();
  void updateLink(OdGiConveyorGeometry* pGeometry);

  virtual OdGiConveyorGeometry* optionalGeometry() = 0;
};

/** Description:
    Wrapper extensions accumulator class adopted for Gs.

    Library: TD_Gs

    {group:OdGs_Classes}
*/
class GS_TOOLKIT_EXPORT OdGsExtAccum : public OdGiExtAccum,
                                       public OdGsConveyorNodeBase,
                                       public OdGiConveyorGeometry
{
  OdGiExtAccumPtr m_pExtAccum;
  OdGsBaseVectorizeView *m_pBaseVV;
  int m_maxLineweight;
  OdGiConveyorContext *m_pConContext;
protected:
  OdGsExtAccum();
public:
  ODRX_DECLARE_MEMBERS(OdGsExtAccum);

  // OdGsExtAccum functions

  OdGiConveyorGeometry* optionalGeometry();

  OdGiExtAccum *giExtAccum() { return m_pExtAccum.get(); }
  const OdGiExtAccum *giExtAccum() const { return m_pExtAccum.get(); }

  /** Description:
    Setup current OdGsBaseVectorizeView object for optional use of additional information into extents calculations.
    Arguments:
    pBaseVV (I) Pointer to the base vectorize view
  */
  virtual void setBaseVectorizeView(OdGsBaseVectorizeView *pBaseVV);

  // OdGiExtAccum functions

  virtual void setDrawContext(OdGiConveyorContext* pDrawContext);
  virtual OdGiConveyorGeometry& geometry();
  virtual bool getExtents(OdGeExtents3d& extents) const;
  virtual void resetExtents(const OdGeExtents3d& newExtents = OdGeExtents3d());
  virtual void addExtents(const OdGeExtents3d& extents);

  virtual void setDeviation(const OdGeDoubleArray& deviations)
  {
    m_pExtAccum->setDeviation(deviations);
  }
  virtual void setDeviation(const OdGiDeviation* pDeviation)
  {
    m_pExtAccum->setDeviation(pDeviation);
  }

  int getLineweight() const;
  void addLineweight(int lwd);
  OdDb::LineWeight getOdDbLineWeight() const;

  // OdGiConveyorNode functions

  virtual OdGiConveyorInput& input();
  virtual OdGiConveyorOutput& output();

  // OdGiConveyorGeometry functions

  virtual void plineProc(const OdGiPolyline& polyline,
    const OdGeMatrix3d* pXfm = 0,
    OdUInt32 fromIndex = 0,
    OdUInt32 numSegs = 0);
  virtual void polylineProc(
    OdUInt32 numPoints, const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0,
    const OdGeVector3d* pExtrusion = 0,
    OdLongPtr baseSubEntMarker = -1);
  virtual void polygonProc(
    OdInt32 numPoints, const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0,
    const OdGeVector3d* pExtrusion = 0);
  virtual void polyPointsProc(const OdUInt32 numVertices, const OdGePoint3d* vertexList , OdLongPtr baseSubEntMarker = -1);
  virtual void lineSegsProc(const OdUInt32 numSegs , const OdGePoint3d * vertexList , const OdGeVector3d* pNormal = 0, OdLongPtr baseSubEntMarker = -1);

  bool dashLineEnable();
  virtual void dashLineSegsProc(const OdUInt32 numSegs, const OdGeDashLine3d* dlList, const OdGeVector3d* pNormal = 0, OdLongPtr baseSubEntMarker = -1);
  virtual void dashLineSegsProc(const OdGeMultiDashLine3d* pMDLine, const OdGeVector3d* pNormal = 0, OdLongPtr baseSubEntMarker = -1);

  virtual void xlineProc(
    const OdGePoint3d& firstPoint, const OdGePoint3d& secondPoint);
  virtual void rayProc(
    const OdGePoint3d& basePoint, const OdGePoint3d& throughPoint);
  virtual void meshProc(
    OdInt32 numRows, 
    OdInt32 numColumns,
    const OdGePoint3d* vertexList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0);
  virtual void shellProc(
    OdInt32 numVertices, const OdGePoint3d* vertexList,
    OdInt32 faceListSize, const OdInt32* faceList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0);
  virtual void circleProc(
    const OdGePoint3d& center, 
    double radius, 
    const OdGeVector3d& normal, 
    const OdGeVector3d* pExtrusion = 0);
  virtual void circleProc(
    const OdGePoint3d& firstPoint, 
    const OdGePoint3d& secondPoint, 
    const OdGePoint3d& thirdPoint, 
    const OdGeVector3d* pExtrusion = 0);
  virtual void circularArcProc(
    const OdGePoint3d& center,
    double radius,
    const OdGeVector3d& normal,
    const OdGeVector3d& startVector,
    double sweepAngle,
    OdGiArcType arcType = kOdGiArcSimple, const OdGeVector3d* pExtrusion = 0);
  virtual void circularArcProc(
    const OdGePoint3d& firstPoint,
    const OdGePoint3d& secondPoint,
    const OdGePoint3d& thirdPoint,
    OdGiArcType arcType = kOdGiArcSimple, const OdGeVector3d* pExtrusion = 0);
  virtual void ellipArcProc(
    const OdGeEllipArc3d& ellipArc,
    const OdGePoint3d* endPointOverrides = 0,
    OdGiArcType arcType = kOdGiArcSimple, const OdGeVector3d* pExtrusion = 0);
  virtual void nurbsProc(
    const OdGeNurbCurve3d& nurbsCurve, const OdGeVector3d* pNormal = 0);
  virtual void textProc(
    const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    const OdChar* msg, 
    OdInt32 numBytes, 
    bool raw, 
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion = 0);
  virtual void textProc2(
    const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    const OdChar* msg, 
    OdInt32 numBytes, 
    bool raw, 
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion = 0,
    const OdGeExtents3d* extentsBox = 0);
  virtual void ttfTextProc(
    const OdGePoint3d& position,
    const OdGeVector3d& u, const OdGeVector3d& v,
    const OdChar* pText, OdInt32 nLen,
    double height, double allWidth,
    const OdArray<double>& charWidths,
    const void* pLOGFONT);
  virtual void shapeProc(
    const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    int shapeNumber, 
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion = 0);
  virtual void rasterImageProc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiRasterImage* pImage, 
    const OdGePoint2d* uvBoundary,
    OdUInt32 numBoundPts,
    bool transparency = false,
    double brightness = 50.0,
    double contrast = 50.0,
    double fade = 0.0);
  virtual void metafileProc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiMetafile* pMetafile,
    bool dcAligned = true,
    bool allowClipping = false);
  virtual void polylineExProc(
    OdUInt32 numPoints, const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0,
    const OdGeVector3d* pExtrusion = 0,
    OdLongPtr baseSubEntMarker = -1,
    int flags = 0);
  virtual void polypointProc(
    OdInt32 numPoints,
    const OdGePoint3d* vertexList,
    const OdCmEntityColor* pColors,
    const OdCmTransparency* pTransparency = 0,
    const OdGeVector3d* pNormals = 0,
    const OdGeVector3d* pExtrusions = 0,
    const OdGsMarker* pSubEntMarkers = 0,
    OdInt32 nPointSize = 0);
protected:
  void CheckLineweight();
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGsExtAccum object pointers.
*/
typedef OdSmartPtr<OdGsExtAccum> OdGsExtAccumPtr;

#include "../TD_PackPop.h"

#endif // ODGSEXTACCUM_INC
