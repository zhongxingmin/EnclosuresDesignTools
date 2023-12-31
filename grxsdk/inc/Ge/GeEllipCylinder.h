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


#ifndef OD_GEELLIPCYLNDR_H
#define OD_GEELLIPCYLNDR_H /* {Secret} */

#include "../Ge/GeSurface.h"
#include "../Ge/GeInterval.h"
#include "../OdPlatformSettings.h"

class OdGeCircArc3d;

#include "../TD_PackPush.h"

/**
    Description:
    This class represents cylinders with an elliptical cross-section.

    Remarks:
    An eliptical cylinder is defined by:

    o   major and minor radii
    o   origin (a point on the axis of symmetry)
    o   axis of symmetry
    o   major axis
    o   height

    It is generated by a line parallel to the axis of symmetry,
    along an eliptical path. 

    Parameter V is the angle of revolution, measured from the major axis
    to the axis of symmetry. The right hand rule is applied along the 
    direction of the axis of symmetry for positive
    angles. For a closed cylinder, V defaults to [-OdaPI, OdaPI).

    Parameter U varies along the axis of symmetry. U is dimensionless
    and increases in the direction of the axis of symmetry. 
    U = 0 corresponds to the center of the cylinder base, 
    and U = 1 corresponds to the center of the cylinder top.  

    The surface of the cylinder is perodic in V with a period of Oda2PI.

    [umin, umax] x [vmin, vmax] defines a four-sided cylindrical
    patch bounded by two straight lines (at vmin and vmax) and
    two circular arcs (at umin and umax). The following constraints
    apply to the definition of a cylindrical patch:

    o umin < umax
    o |vmax - vmin| <= Oda2PI
    o majorRadius > 0.0
    o minorRadius > 0.0
 
    The angle of a point on an ellipse is measured by projecting
    the point along a vector perpendicular to the major axis onto a
    circle whose center is the center of this ellipse and whose
    radius is the major radius of this ellipse.

    The angle between the major axis of the ellipse, and a vector from
    the center of the ellipse to the intersection point with the circle, 
    measured counterclockwise, is the angle of the point on the ellipse.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeEllipCylinder : public OdGeSurface
{
public:


  /**
    Arguments:
    majorRadius (I) Major radius of the elliptical cylinder.
    minorRadius (I) Minor radius of the elliptical cylinder.
    origin (I) Origin of the elliptical cylinder.
    axisOfSymmetry (I) Axis of symmetry (rotation).
    majorAxis (I) Major axis of the elliptical cylinder.
    height (I) Height interval of the cylinder.
    startAng (I) Start angle of the elliptical cylinder.
    endAng (I) End angle of the elliptical cylinder.
    
	Note:
    All angles are expressed in radians.
  */
  OdGeEllipCylinder ();
  OdGeEllipCylinder (const OdGeEllipCylinder& );
  OdGeEllipCylinder (
    double minorRadius, 
    double majorRadius,
    const OdGePoint3d& origin,
    const OdGeVector3d& axisOfSymmetry);
  OdGeEllipCylinder (
    double minorRadius, 
    double majorRadius,
    const OdGePoint3d& origin,
    const OdGeVector3d& axisOfSymmetry,
    const OdGeVector3d& majorAxis,
    const OdGeInterval& height,
    double startAng, 
    double endAng);

  // Geometric properties.
  //

  /**
    Description:
    Returns the ratio of the minor to major radius of the cylinder.
  */
  double radiusRatio () const ;

  /**
    Description:
    Returns the minor radius of the cylinder.
  */
  double minorRadius () const ;


  /**
    Description:
    Returns the major radius of the cylinder.
  */
  double majorRadius () const ;

  /**
    Description:
    Returns the origin of the cylinder.
  */
  OdGePoint3d origin () const ;

  /**
    Description:
    Returns the start and end angles of the cylinder.

    Arguments:
    startAng (O) Receives the start angle.
    endAng (O) Receives the end angle.
    
	Note:
    All angles are expressed in radians.

  */
  void getAngles (
    double& startAng, 
    double& endAng) const ;

  /**
    Description:
    Returns the interval of the axis of symmetry.

    Arguments:
    height (O) Receives the interval of the axis of symmetry.
  */
  void getHeight (
    OdGeInterval& height) const ;

  /**
    Description:
    Returns the cylinder height that corresponds to
    the specified position on the U-axis.
    
	Remarks:
    Parameter U varies along the axis of symmetry. U is dimensionless
    and increases in the direction of the axis of symmetry. 

    Arguments:
    u (I) Position of the cylinder on the U-axis.
  */
  double heightAt (
    double u) const ;

  /**
    Description:
    Returns the axis of symmetry of the cylinder.
  */
  OdGeVector3d axisOfSymmetry () const ;

  /**
    Description:
    Returns the major axis of the cylinder.
  */
  OdGeVector3d majorAxis () const ;

  /**
    Description:
    Returns the minor axis of the cylinder.
  */
  OdGeVector3d minorAxis () const;

  /**
    Description:
    Returns true if and only if the normal to the cylinder
    is pointing outward.
  */
  bool isOuterNormal () const;    

  /**
    Description
    Returns true if and only if the cylinder
    is a full ellipse within the specified tolerance.

    Arguments:
    tol (I) Geometric tolerance.
  */
  bool isClosed (
    const OdGeTol& tol = OdGeContext::gTol) const;

  /** Description:
    Sets OuterNormal according to the parameter.

    Arguments:
    isOuterNormal (I) Sets OuterNormal.
  */
  void setIsOuterNormal (
    bool isOuterNormal);

  /** Description:
    Sets the minor radius of the elliptical cylinder.

    Arguments:
    minorRadius (I) The minor radius of the elliptical cylinder.
  */
  OdGeEllipCylinder& setMinorRadius (
    double minorRadius);

  /** Description:
    Sets the major radius of the elliptical cylinder.

    Arguments:
    majorRadius (I) The major radius of the elliptical cylinder.
  */
  OdGeEllipCylinder& setMajorRadius (
    double majorRadius);

  /** Description:
    Sets the start and end angles of the elliptical cylinder.

    Arguments:      
    startAng (I) Start angle.
    endAng (I) End angle.
    
	Note:
    All angles are expressed in radians.

  */
  OdGeEllipCylinder& setAngles (
    double startAng, 
    double endAng);

  /**
    Description:
    Sets the height of the elliptical cylinder.

    Arguments:      
    height (I) Height of the elliptical cylinder.
  */
  OdGeEllipCylinder& setHeight (
    const OdGeInterval& height);

  /**
    Description:
    Sets the parameters for the cylinder and returns a reference to the cylinder.

    Arguments:
    majorRadius (I) Major radius of the elliptical cylinder.
    minorRadius (I) Minor radius of the elliptical cylinder.
    origin (I) Origin of the elliptical cylinder.
    axisOfSymmetry (I) Axis of symmetry (rotation).
    majorAxis (I) Major axis of the elliptical cylinder.
    height (I) Height interval of the cylinder.
    startAng (I) Start angle of the elliptical cylinder.
    endAng (I) End angle of the elliptical cylinder.
    
	Note:
    All angles are expressed in radians.
  */
  OdGeEllipCylinder& set (
    double minorRadius,
    double majorRadius, 
    const OdGePoint3d& origin, 
    const OdGeVector3d& axisOfSymmetry);
  OdGeEllipCylinder& set (
    double minorRadius, 
    double majorRadius,
    const OdGePoint3d& origin,
    const OdGeVector3d& axisOfSymmetry,
    const OdGeVector3d& majorAxis,
    const OdGeInterval& height,
    double startAng, 
    double endAng);


  /**
    Description:
    Returns True if the cylinder intersects with the specified line entity,
    and returns the number of intersections and the points of intersection.

    Arguments:
    lineEnt (I) Any 3D line entity.
    numInt (O) Receives the number of intersections.
    p1 (O) Receives the first intersection point.
    p2 (O) Receives the second intersection point.
    tol (I) Geometric tolerance.

    Remarks:
    o p1 is valid only if numInt > 0.
    o p2 is valid only if numInt > 1.
  */
  bool intersectWith (
    const OdGeLinearEnt3d& linEnt, 
    int& numInt,
    OdGePoint3d& p1, 
    OdGePoint3d& p2,
    const OdGeTol& tol = OdGeContext::gTol) const;

  OdGeEllipCylinder& operator =(const OdGeEllipCylinder& );
};



#include "../TD_PackPop.h"

#endif // OD_GEELLIPCYLNDR_H
// AE - End 
