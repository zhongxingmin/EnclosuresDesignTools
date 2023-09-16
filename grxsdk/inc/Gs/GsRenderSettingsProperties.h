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


#ifndef __OD_GS_RENDERSETTINGS_PROPERTIES__
#define __OD_GS_RENDERSETTINGS_PROPERTIES__

#include "Gs/GsProperties.h"
#include "Gi/GiEnvironmentTraitsData.h"

// Manages:
// OdRenderEnvironment
// OdRenderSettings
// OdMentalRayRenderSettings

/**
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsRenderEnvironmentProperties : public OdGsProperties
{
  OdGiRenderEnvironmentTraitsData* m_pRenderEnvironmentTraits;

public:
  ODRX_DECLARE_MEMBERS(OdGsRenderEnvironmentProperties);

  OdGsRenderEnvironmentProperties();
  ~OdGsRenderEnvironmentProperties();

  OdGiRenderEnvironmentTraitsData* renderEnvironmentTraitsData() const { return m_pRenderEnvironmentTraits; }

  bool isTraitsModified();

  void clearTraits();

  // OdGsProperties virtual overrides
  
  virtual PropertiesType propertiesType() const
  {
    return kRenderEnvironment;
  }

  virtual OdSmartPtr<OdGsProperties> propertiesForType(PropertiesType type) const;

  virtual void update(const OdGiDrawable* pUnderlyingDrawable, OdGsBaseVectorizeView* view, OdUInt32 incFlags = kAll);

  virtual void display(OdGsBaseVectorizeView& view, OdGsPropertiesDirectRenderOutput *pdro = NULL, OdUInt32 incFlags = kAll);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGsRenderEnvironmentProperties object pointers.
*/
typedef OdSmartPtr<OdGsRenderEnvironmentProperties> OdGsRenderEnvironmentPropertiesPtr;

/**
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsRenderSettingsProperties : public OdGsProperties
{
  OdGiMentalRayRenderSettingsTraitsData* m_pRenderSettingsTraits;

public:
  ODRX_DECLARE_MEMBERS(OdGsRenderSettingsProperties);

  OdGsRenderSettingsProperties();
  ~OdGsRenderSettingsProperties();

  OdGiRenderSettingsTraitsData* renderSettingsTraitsData() const { return m_pRenderSettingsTraits; }
  OdGiMentalRayRenderSettingsTraitsData* mentalRayRenderSettingsTraitsData() const { return m_pRenderSettingsTraits; }

  bool isTraitsModified();

  void clearTraits();

  // OdGsProperties virtual overrides
  
  virtual PropertiesType propertiesType() const
  {
    return kRenderSettings;
  }

  virtual OdSmartPtr<OdGsProperties> propertiesForType(PropertiesType type) const;

  virtual void update(const OdGiDrawable* pUnderlyingDrawable, OdGsBaseVectorizeView* view, OdUInt32 incFlags = kAll);

  virtual void display(OdGsBaseVectorizeView& view, OdGsPropertiesDirectRenderOutput *pdro = NULL, OdUInt32 incFlags = kAll);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGsRenderSettingsProperties object pointers.
*/
typedef OdSmartPtr<OdGsRenderSettingsProperties> OdGsRenderSettingsPropertiesPtr;

#endif // __OD_GS_RENDERSETTINGS_PROPERTIES__
