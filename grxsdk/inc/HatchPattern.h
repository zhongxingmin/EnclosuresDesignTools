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




#ifndef OD_HATCHPATTERN_H
#define OD_HATCHPATTERN_H

#include "TD_PackPush.h"

#include "Ge/GePoint2d.h"
#include "Ge/GeVector2d.h"
#include "Ge/GeDoubleArray.h"

/** Description:
    This class implements a single line of an OdDbHatchPattern object.
    Library: TD_Db
    {group:Other_Classes}
*/
class OdHatchPatternLine
{
public:
  double            m_dLineAngle;
  OdGePoint2d       m_basePoint;
  OdGeVector2d      m_patternOffset;
  OdGeDoubleArray   m_dashes;

  OdHatchPatternLine()
    : m_dLineAngle(0.0)
  {
  }
  void transformBy(const OdGeMatrix2d& ocsXform)
  {
    m_basePoint.transformBy(ocsXform);
    m_patternOffset.transformBy(ocsXform);

    OdGeVector2d pO(OdGeVector2d::kXAxis);
    pO.rotateBy(m_dLineAngle);
    pO.transformBy(ocsXform);
    m_dLineAngle = pO.angle();

    OdGeDoubleArray::iterator pDash;
    for(pDash = m_dashes.begin(); pDash != m_dashes.end(); ++ pDash)
    {
      (*pDash) *= pO.length();
    }
  }
};

/** Description:
  This template class is a specialization of the OdArray class for OdHatchPatternLine objects.
*/
typedef OdArray<OdHatchPatternLine> OdHatchPattern;

#include "TD_PackPop.h"

#endif //#ifndef OD_HATCHPATTERN_H
