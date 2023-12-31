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

#ifndef ODDBMATCHPROPERTIES_H
#define ODDBMATCHPROPERTIES_H

#include "RxObject.h"

class OdDbEntity;

/** Description:
    This class is an abstract base class for classes which 
    to copy properties between entities.
    
    Library: TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT ODRX_ABSTRACT OdDbMatchProperties : public OdRxObject
{
public:
  enum Flags
  {
    kColorFlag          = 0x00001,    // Color
    kLayerFlag          = 0x00002,    // Layer
    kLtypeFlag          = 0x00004,    // Linetype
    kThicknessFlag      = 0x00008,    // Thickness
    kLtscaleFlag        = 0x00010,    // Linetype Scale
    kTextFlag           = 0x00020,    // Text
    kDimensionFlag      = 0x00040,    // Dimension
    kHatchFlag          = 0x00080,    // Hatch
    kLweightFlag        = 0x00100,    // Lineweight
    kPlotstylenameFlag  = 0x00200,    // Plotstyle Name
    kPolylineFlag       = 0x00400,    // 
    kViewportFlag       = 0x00800,
    kTableFlag          = 0x01000,
    kMaterialFlag       = 0x02000,
    kShadowDisplayFlag  = 0x04000,
    kMultileaderFlag    = 0x08000,
    kTransparencyFlag   = 0x10000,
    kSetAllFlagsOn      = 0x1FFFF     // All
  };

  ODRX_DECLARE_MEMBERS(OdDbMatchProperties);

  /** Description:
  Copies the specified properties from the source entity to the destination entity.
  Arguments:
  pSource (I) Pointer to the source.
  pDestination (I) Pointer to the destination.
  flags (I) Properties to copy.

  Remarks:
  flags must be a combination of one or more of the following:

  @table
  Name                  Value   Property
  kColorFlag          0x00001   Color
  kLayerFlag          0x00002   Layer
  kLtypeFlag          0x00004   Linetype
  kThicknessFlag      0x00008   Thickness
  kLtscaleFlag        0x00010   Linetype Scale
  kTextFlag           0x00020   Text
  kDimensionFlag      0x00040   Dimension
  kHatchFlag          0x00080   Hatch
  kLweightFlag        0x00100   Lineweight
  kPlotstylenameFlag  0x00200   Plotstyle Name
  kPolylineFlag       0x00400    
  kViewportFlag       0x00800
  kTableFlag          0x01000
  kMaterialFlag       0x02000
  kShadowDisplayFlag  0x04000
  kMultileaderFlag    0x08000
  kTransparencyFlag   0x10000
  kSetAllFlagsOn      0x1FFFF   All
  */
  virtual void copyProperties(
    OdDbEntity* pSource, 
    OdDbEntity* pDestination, 
    unsigned int flags) const = 0;
};

#endif // ODDBMATCHPROPERTIES_H

