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




// GiBaseVectorizer.h: interface for the OdGiBaseVectorizer class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _ODGITRANSFORMED_INCLUDED_
#define _ODGITRANSFORMED_INCLUDED_


#include "Gi/GiBaseVectorizer.h"
#include "OdStack.h"

#include "TD_PackPush.h"

/** Description:
This class is an implementation of transformation stack.
Library: TD_Gi
{group:OdGi_Classes}
*/
template <class T> class OdGiTransformed : public T
{
  struct Transforms
  {
    Transforms() : bWorldToModelValid(false) {}
    OdGeMatrix3d          xModelToWorld;
    mutable OdGeMatrix3d  xWorldToModel;
    mutable bool          bWorldToModelValid;
  };
  OdStack<Transforms>      m_TransformStack;

  public:

    OdBool pushModelTransform(const OdGeMatrix3d& xMat)
    {
      const Transforms* pPrev = m_TransformStack.top();
      Transforms* pNew = m_TransformStack.push();
      if(pPrev)
      {
        pNew->xModelToWorld.setToProduct(pPrev->xModelToWorld, xMat);
      }
      else
      {
        pNew->xModelToWorld = xMat;
      }

      return ::kTrue;
    }
  
    OdBool pushModelTransform(const OdGeVector3d& vNormal)
    {
      return pushModelTransform(OdGeMatrix3d::planeToWorld(vNormal));
    }
  
    OdBool popModelTransform()
    {
      m_TransformStack.pop();
      return ::kTrue;
    }

    OdGeMatrix3d getModelToWorldTransform() const
    {
      if(m_TransformStack.top())
        return m_TransformStack.top()->xModelToWorld;
      return OdGeMatrix3d::kIdentity;
    }

    OdGeMatrix3d getWorldToModelTransform() const
    {
      const Transforms* pTop = m_TransformStack.top();
      if(pTop)
      {
        if(!pTop->bWorldToModelValid)
        {
          pTop->xWorldToModel = pTop->xModelToWorld.inverse();
          pTop->bWorldToModelValid = true;
        }
        return pTop->xWorldToModel;
      }
      return OdGeMatrix3d::kIdentity;
    }

    void getModelToWorldTransform(OdGeMatrix3d& unnamed) const
    {
      unnamed = getModelToWorldTransform();
    }
    void getWorldToModelTransform(OdGeMatrix3d& unnamed) const
    {
      unnamed = getWorldToModelTransform();
    }
};

#include "TD_PackPop.h"

#endif // #ifndef _ODGITRANSFORMED_INCLUDED_
