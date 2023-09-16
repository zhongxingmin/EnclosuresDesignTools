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

#ifndef _OD_GEBOUNDBLOCK3D_H
#define _OD_GEBOUNDBLOCK3D_H /* {Secret} */

#include "../Ge/GeEntity3d.h"
#include "../Ge/GeExtents3d.h"

#include "../TD_PackPush.h"

/**
    Description:
    This class implements 3D bounding volumes.

    Library: TD_Ge

    {group:OdGe_Classes}
*/
class GE_TOOLKIT_EXPORT OdGeBoundBlock3d : public OdGeEntity3d
{
public: 


  /**
  Arguments:
    point1 (I) First *point* of a coordinate-aligned *block*.
    point2 (I) Second *point* of a coordinate-aligned *block*.
    base (I) Base of parallelepiped bounding *block*.
    side1 (I) First side of parallelepiped bounding *block*.
    side2 (I) Second side of parallelepiped bounding *block*.
    side3 (I) Third side of parallelepiped bounding *block*.
    source (I) Object to be cloned.

    Remarks:
    The default constructor constructs a parallelepiped reduced to the coordinate origin.
    
    A parallelepiped is a parallelogram extruded in an arbitrary direction. 
  */
  OdGeBoundBlock3d();
  OdGeBoundBlock3d(
    const OdGePoint3d& base, 
    const OdGeVector3d& side1,
    const OdGeVector3d& side2, 
    const OdGeVector3d& side3);
  // TD Special
  OdGeBoundBlock3d(
    const OdGePoint3d& point1, 
    const OdGePoint3d& point2);
  //
  OdGeBoundBlock3d(
    const OdGeBoundBlock3d& source);

  /**
    Description
    Returns the extents of the bounding *block*.

    Arguments:
    p1 (O) Receives the first corner of the extents.
    p2 (O) Receives the second corner of the extents.
    
    Note:
    The returned values are meaningful if and only if this object is a coordinate-aligned box.
    
  */
   void getMinMaxPoints(
    OdGePoint3d& p1, 
    OdGePoint3d& p2) const;

  /**
    Description:
    Returns base and sides of bounding *block*.

    Arguments:
    base (O) Receives the *base* of the bounding box.
    side1 (O) Receives the first side.
    side2 (O) Receives the second side.
    side3 (O) Receives the third side.
  */
   void get(
    OdGePoint3d& base,
    OdGeVector3d& side1,
    OdGeVector3d& side2,
    OdGeVector3d& side3) const;

  /**
    Description:
    Sets the bounding *block* to a coordinate-aligned box or to
    a parallelepiped bounding *block*.

    Arguments:
    p1 (I) First *point* of a coordinate-aligned box.
    p2 (I) Second *point* of a coordinate-aligned box.
    base (I) Base of parallelepiped bounding *block*.
    side1 (I) First side of parallelepiped bounding *block*.
    side2 (I) Second side of parallelepiped bounding *block*.
    side3 (I) Third side of parallelepiped bounding *block*.
  */
   OdGeBoundBlock3d& set(
    const OdGePoint3d& p1,
    const OdGePoint3d& p2);
   OdGeBoundBlock3d& set(
    const OdGePoint3d& base,
    const OdGeVector3d& side1,
    const OdGeVector3d& side2,
    const OdGeVector3d& side3);

  /**
  Description:
    Extends the bounding *block* to contain
    the specified *point*.

    Arguments:
    point (I) Any 3D *point*.
  */
   OdGeBoundBlock3d& extend(
    const OdGePoint3d& point);

  /**
    Description:
    Moves the walls of the bounding *block* the specified *distance*.

    Arguments:
    distance (I) Distance.
  */
   OdGeBoundBlock3d& swell(
    double distance);

  /**
    Description:
    Returns kTrue if and only if this *point* is
    contained in the bounding *block*.

    Arguments:
    point (I) Any 3D *point*.
  */
  OdBool contains (
    const OdGePoint3d& point, 
    const OdGeTol& tol = OdGeContext::gTol) const;

  /**
  Description:
  Returns kTrue if and only if specified bounding *block*
  does not intersect this bounding *block*.

  Arguments:
    block (I) Any 3D bounding *block*.
  */
  OdBool isDisjoint (
    const OdGeBoundBlock3d& block,
    const OdGeTol& tol = OdGeContext::gTol) const;

  OdBool isDisjoint (
    const OdGeExtents3d& extents,
    const OdGeTol& tol = OdGeContext::gTol) const;
  /**
    Description:
    Returns kTrue if and only if this bounding *block* is a
    coordinate-aligned box.
  */
  OdBool isBox () const;

  /**
    Description:
    Sets this bounding *block* to a coordinate-aligned box, or a
    parallelogram bounding *block*. Returns a reference to this 
    bounding *block*. Not implemented for third-party use only.

    Arguments:
    toBox (I) If kTrue, sets this bounding *block* to a 
    coordinate-aligned box; otherwise, sets it to a 
    parallelepiped bounding *block*.
  */
  OdGeBoundBlock3d&  setToBox (
    OdBool toBox);

  OdGeBoundBlock3d& operator =(const OdGeBoundBlock3d& block);

  //////////////////////////////////////////////////////////////////////////
  // DD Special :

   OdGePoint3d minPoint() const;
   OdGePoint3d maxPoint() const;

  /**
    Description:
    Returns the *center* of the bounding *block*.
  */
   OdGePoint3d center() const;
};

#include "../TD_PackPop.h"

#endif

