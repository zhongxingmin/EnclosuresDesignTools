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


#ifndef __OD_GS_BACKGROUND_PROPERTIES__
#define __OD_GS_BACKGROUND_PROPERTIES__

#include "Gs/GsProperties.h"
#include "Gi/GiEnvironmentTraitsData.h"
#include "Gs/GsBackground.h"

// Viewports is not entities or nodes (this is objects with one attributes set per scene)

/** 
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsBackgroundProperties : public OdGsProperties
                                                 , protected OdGsNestedBackground
{
  OdGiBackgroundTraitsData* m_pBackgroundTraits;
  OdGsBackgroundPtr m_pBackgroundPainter;
  OdSmartPtr<OdGsBackgroundProperties> m_pSecondaryBackground;

protected:
  virtual void nestedBackgroundDisplay(OdGsBaseVectorizeView& view,
    const OdGiDrawable *pDrawable,
    OdGiBackgroundTraitsData* pBackgroundTraits,
    OdGsPropertiesDirectRenderOutput *pdro = NULL);

public:
  ODRX_DECLARE_MEMBERS(OdGsBackgroundProperties);

  OdGsBackgroundProperties();
  ~OdGsBackgroundProperties();

  OdGiSolidBackgroundTraitsData* solidBackgroundTraitsData() const { return (OdGiSolidBackgroundTraitsData*)m_pBackgroundTraits; }
  OdGiGradientBackgroundTraitsData* gradientBackgroundTraitsData() const { return (OdGiGradientBackgroundTraitsData*)m_pBackgroundTraits; }
  OdGiImageBackgroundTraitsData* imageBackgroundTraitsData() const { return (OdGiImageBackgroundTraitsData*)m_pBackgroundTraits; }
  OdGiGroundPlaneBackgroundTraitsData* groundPlaneBackgroundTraitsData() const { return (OdGiGroundPlaneBackgroundTraitsData*)m_pBackgroundTraits; }
  OdGiSkyBackgroundTraitsData* skyBackgroundTraitsData() const { return (OdGiSkyBackgroundTraitsData*)m_pBackgroundTraits; }
  OdGiIBLBackgroundTraitsData* iblBackgroundTraitsData() const { return (OdGiIBLBackgroundTraitsData*)m_pBackgroundTraits; }
  OdGiBackgroundTraitsData* backgroundTraitsData() const { return m_pBackgroundTraits; }

  OdGiDrawable::DrawableType backgroundType() const { return (m_pBackgroundTraits) ? m_pBackgroundTraits->type() : OdGiDrawable::kGeometry; }
  const OdGsBackgroundProperties *secondaryBackground() const { return m_pSecondaryBackground.get(); }
  OdGsBackgroundProperties *secondaryBackground() { return m_pSecondaryBackground.get(); }

  bool isTraitsModified();

  void clearTraits();

  // OdGsProperties virtual overrides
  
  virtual PropertiesType propertiesType() const
  {
    return kBackground;
  }

  virtual OdSmartPtr<OdGsProperties> propertiesForType(PropertiesType type) const;

  virtual void update(const OdGiDrawable* pUnderlyingDrawable, OdGsBaseVectorizeView* view, OdUInt32 incFlags = kAll);

  virtual void display(OdGsBaseVectorizeView& view, OdGsPropertiesDirectRenderOutput *pdro = NULL, OdUInt32 incFlags = kAll);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGsBackgroundProperties object pointers.
*/
typedef OdSmartPtr<OdGsBackgroundProperties> OdGsBackgroundPropertiesPtr;

#endif // __OD_GS_BACKGROUND_PROPERTIES__
