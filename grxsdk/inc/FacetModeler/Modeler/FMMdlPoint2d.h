#ifndef __FMMDL_POINT2D_H__
#define __FMMDL_POINT2D_H__

#include <math.h>
#include "../FacetModeler/Modeler/FMMdlBase.h"
#include "../FacetModeler/Modeler/FMMdlVector2d.h"

namespace FacetModeler
{
  class FMGEOMETRY_API Point2d
  {
  public:

    Point2d() : x(0.), y(0.){}
    Point2d(double xx, double yy) : x(xx), y(yy) {}

    Point2d  operator  +(Point2d  p) const { return Point2d (x+p.x, y+p.y); }
    Point2d  operator  +(Vector2d v) const { return Point2d (x+v.x, y+v.y); }
    Vector2d operator  -(Point2d  p) const { return Vector2d(x-p.x, y-p.y); }
    Point2d  operator  -(Vector2d v) const { return Point2d (x-v.x, y-v.y); }
    Point2d  operator  -()           const { return Point2d(-x, -y);        }

    Point2d  operator  *(double scalar) const { return Point2d(x*scalar, y*scalar); }
    Point2d  operator  /(double scalar) const { return Point2d(x/scalar, y/scalar); }

    double   operator  %(Vector2d v) const { return x*v.x+y*v.y;     }

    double   operator [](int index) const  { return (&x)[index];     }
    double&  operator [](int index)        { return (&x)[index];     }

    double   length     ()          const  { return sqrt(x*x+y*y);   }
    double   lengthSqrd ()          const  { return x*x+y*y;         }
    double   lengthRect ()          const  { return fabs(x)+fabs(y); }

    double   dist       (Point2d p) const  { return sqrt(sqr(x-p.x)+sqr(y-p.y)); }
    double   distSqrd   (Point2d p) const  { return sqr(x-p.x)+sqr(y-p.y);       }
    double   distRect   (Point2d p) const  { return fabs(x-p.x)+fabs(y-p.y);     }

    bool     isEqual    (Point2d p, double epsSqrd = epsAbsSqrd()) const { return (distSqrd(p) <= epsSqrd); }
    bool     isEqualRect(Point2d p, double epsRect = epsAbs    ()) const { return (distRect(p) <= epsRect); }

    void     operator +=(Point2d  p)       { x += p.x; y += p.y;       }
    void     operator +=(Vector2d v)       { x += v.x; y += v.y;       }
    void     operator -=(Point2d  p)       { x -= p.x; y -= p.y;       }
    void     operator -=(Vector2d v)       { x -= v.x; y -= v.y;       }
    void     operator *=(double scalar)    { x *= scalar; y *= scalar; }
    void     operator /=(double scalar)    { x /= scalar; y /= scalar; }

    bool     isValid() const { return fabs(x) < kMaxReal && fabs(y) < kMaxReal; }

    Vector2d toVector2d () const { return *(Vector2d*)this; }

    operator       OdGePoint2d& ()       { return *((OdGePoint2d*)this);       }
    operator const OdGePoint2d& () const { return *((const OdGePoint2d*)this); }

    static Point2d& cast(OdGePoint2d& p) { return *(Point2d*)&p; }

    Point2d(const OdGePoint2d& p)        { *this = *(Point2d*)&p; }

    double x, y;

    static const Point2d kNull;

  };



  inline Point2d operator *(double scalar, Point2d p) 
  { 
    return Point2d(scalar*p.x, scalar*p.y); 
  }


  inline double det(Point2d a, Point2d b)
  {
    return (a.x * b.y - a.y * b.x);
  } 


  FMGEOMETRY_API Point2d intersect(const Point2d& p1, const Vector2d v1, 
    const Point2d& p2, const Vector2d v2,
    bool& succeeded);


  FMGEOMETRY_API bool doIntersect(const Point2d& p1, 
    const Point2d& p2, 
    const Point2d& q1, 
    const Point2d& q2);


  Point2d projectPointOnLine(Point2d p, Point2d lpoint, Vector2d lvector);

}

#endif //__FMMDL_POINT2D_H__
