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


#ifndef OD_GE_LINE_2D_H
#define OD_GE_LINE_2D_H /* {Secret} */

#include "../Ge/GeLinearEnt2d.h"

#include "../TD_PackPush.h"

class OdGeLine3dImpl;
/**
    Description:
    This class represents infinite lines in 2D space.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeLine2d : public OdGeLinearEnt2d
{
public:
  

  /**
    Arguments:
    line (I) Any 2D *line*.
    point (I) Any 2D *point*.
    point1 (I) Any 2D *point*.
    point2 (I) Any 2D *point*.
    source (I) Object to be cloned.
    vect (I) Any 2D vector.

    Remarks:
    point and vect construct an infinite *line* passing through point with 
    a *direction* of vect. vect cannot have a zero *length*.

    point1 and point2 construct an infinite *line* passing through both points. The 
    points cannot be coincident.

    If called with no arguments, constructs in infinite *line* coincident with the X-axis.
  */
  OdGeLine2d();
  OdGeLine2d(OdGeLine3dImpl* );
  OdGeLine2d(
    const OdGeLine2d& source);
  OdGeLine2d(
    const OdGePoint2d& point, 
    const OdGeVector2d& vect);
  OdGeLine2d(
    const OdGePoint2d& point1, 
    const OdGePoint2d& point2);

  GE_STATIC_EXPORT static const OdGeLine2d kXAxis; // X-axis *line*.
  GE_STATIC_EXPORT static const OdGeLine2d kYAxis; // Y-axis *line*.

  /**
    Description:
    Sets the parameters for this *line* according to the arguments, and returns a reference to this *line*.

    Arguments:
    point (I) Any 2D *point*.
    vect (I) Any 2D vector
    point1 (I) Any 2D *point*.
    point2 (I) Any 2D *point*.

    Remarks:
    point and vect construct an infinite *line* passing through point with 
    a *direction* of vect. vect cannot have a zero *length*.

    point1 and point2 construct an infinite *line* passing through both points. The 
    points should no be coincident.
  */
  OdGeLine2d& set(
    const OdGePoint2d& point, 
    const OdGeVector2d& vect);
  OdGeLine2d& set(
    const OdGePoint2d& point1, 
    const OdGePoint2d& point2);

  OdGeLine2d& operator =(const OdGeLine2d& line);

private:
  OdGeLine2d(OdGeEntity3dImpl*);
};

#include "../TD_PackPop.h"

#endif // OD_GE_LINE_2D_H


