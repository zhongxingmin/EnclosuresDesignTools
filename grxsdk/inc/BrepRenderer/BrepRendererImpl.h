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


#ifndef _ODBREPRENDERERIMPL_INCLUDED_
#define _ODBREPRENDERERIMPL_INCLUDED_

#include "../Wr/wrExport.h"
#include "../BrepRenderer.h"

class OdBrBrep; 

class wrRenderCache;
class OdGiCommonDraw ;
class OdGiViewportDraw;
class wrTriangulationParams;
class OdGeMatrix3d;

#include "../TD_PackPush.h"

/** Description:
    This class implements platform-dependent ACIS rendering for Teigha.
    Library: TD_BrepRenderer
    {group:Other_Classes}
*/
class RENDER_EXPORT OdBrepRendererImpl : public OdBrepRenderer
{
  const OdBrBrep              *m_pBrep;
  bool                         m_enableCache;
  const wrTriangulationParams *m_pTriangulationParams;
  wrRenderCache               *m_pCache;

public:

  OdBrepRendererImpl();
  virtual ~OdBrepRendererImpl();

  virtual void setBrep(const OdBrBrep& brep);

  virtual void enableCaching();
  virtual void disableCaching(bool clearCache = true);
  virtual bool isCachingEnabled() const;

  virtual void setTriangulationParams(const wrTriangulationParams *pTriangulationParams);

  virtual const wrTriangulationParams * getTriangulationParams() const;

  virtual bool draw(OdGiCommonDraw * pWd, OdUInt32 geomType, const NumIsolines *pNumIsolines = 0);

  virtual bool drawSilhouettes(OdGiViewportDraw* pVd);

  virtual void transformBy(const OdGeMatrix3d &xfm);
};

#include "../TD_PackPop.h"

#endif //_ODBREPRENDERERIMPL_INCLUDED_
