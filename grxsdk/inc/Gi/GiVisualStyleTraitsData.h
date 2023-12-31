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


#ifndef __OD_GI_VISUALSTYLE_TRAITS_DATA__
#define __OD_GI_VISUALSTYLE_TRAITS_DATA__

#include "../TD_PackPush.h"

#include "../Gi/GiVisualStyle.h"

/** Description:
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class OdGiVisualStyleTraitsData
{
  const OdGiVisualStyle*    m_visualStylePtr;

public:

  OdGiVisualStyleTraitsData()
    : m_visualStylePtr(NULL)
  {}
  
  OdGiDrawable::DrawableType type() const { return OdGiDrawable::kGeometry; }

  void setOdGiVisualStyle(const OdGiVisualStyle& visualStyle)
  {
    m_visualStylePtr = &visualStyle;
  }
  const OdGiVisualStyle& odgiVisualStyle() const
  {
    return *m_visualStylePtr;
  }

  bool isOdGiVisualStyleSet() const
  {
    return m_visualStylePtr != NULL;
  }
  void resetOdGiVisualStyle()
  {
    m_visualStylePtr = NULL;
  }
};                          

#include "../TD_PackPop.h"

#endif // __OD_GI_VISUALSTYLE_TRAITS_DATA__
