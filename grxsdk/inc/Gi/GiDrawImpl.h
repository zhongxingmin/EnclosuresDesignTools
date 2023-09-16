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


#ifndef _GIDRAWIMPL_INCLUDED_
#define _GIDRAWIMPL_INCLUDED_


#include "../Gi/GiExport.h"
#include "../Gi/GiViewportDraw.h"
#include "../Gi/GiWorldDraw.h"

/** Description:
    This class provides an implementation of the OdGiWorldDraw::geometry() function.

    Library:
    TD_Gi
    
    {group:OdGi_Classes}
*/
class ODGI_EXPORT ODRX_ABSTRACT OdGiWorldDraw_ : public OdGiWorldDraw
                                               , public OdGiWorldGeometry
{
protected:
  ODRX_USING_HEAP_OPERATORS(OdGiWorldDraw);
public:
  OdGiWorldGeometry& geometry() const;
};


/** Description:
    This class provides an implementation of the OdGiViewportDraw::geometry() function.

    Library: TD_Gi
    {group:OdGi_Classes}
*/
class ODGI_EXPORT ODRX_ABSTRACT OdGiViewportDraw_ : public OdGiViewportDraw
                                                  , public OdGiViewportGeometry
{
protected:
  ODRX_USING_HEAP_OPERATORS(OdGiViewportDraw);
public:
  OdGiViewportGeometry& geometry() const;
};

#endif // #ifndef _GIDRAWIMPL_INCLUDED_
