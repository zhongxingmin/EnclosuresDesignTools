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




#ifndef _ODSMARTCLSIDPTR_INCLUDED_
#define _ODSMARTCLSIDPTR_INCLUDED_

#include "TD_PackPush.h"
#include "SmartPtr.h"

class OdRxObject;

#define ODRX_DEFINE_CLSID_RETRIEVER(Class) \
class OdRxClsIdHolderFor_##Class\
{\
public:\
  static inline const OdRxClass* classId()\
  {\
    OdRxClass* pClass = static_cast<OdRxClass*>(::odrxClassDictionary()->getAt(OD_T(#Class)).get());\
    if(!pClass)\
      throw OdError(eNotInitializedYet);\
    return pClass;\
  }\
}

#define ODRX_DEFINE_CLSID_SMARTPTR(Class) \
ODRX_DEFINE_CLSID_RETRIEVER(Class);\
typedef OdClsIdSmartPtr<OdRxClsIdHolderFor_##Class, Class> Class##ClsIdPtr


/** Description:
    This template class implements SmartPointers for Class ID objects.
    This class is the Teigha ClassIdSmartPointer template class.

    {group:Other_Classes}
*/
template <class ClsIdRetriever, class T> class OdClsIdSmartPtr : public OdBaseObjectPtr
{
  /** Description:
      Increments the reference count for the object referenced by this SmartPointer object.
  */
  inline void internalAddRef() { if(m_pObject) { static_cast<T*>(m_pObject)->addRef(); } }
  
  /** Description:
    Assigns the specified object to this SmartPointer object.  
      
    Remarks:
    The reference count of the specified object is incremented.

    If this SmartPointer is currently referencing another object, that object 
    is released prior to the assignment.  

    Arguments:
    pObject (I) Pointer to the object to be assigned.
  */
  inline void assign(const T* pObject)
  {
    release();
    m_pObject = (OdRxObject*)pObject;
    internalAddRef();
  }
  
  /** Description:
    Performs a "safe" assignment of the specified object to this SmartPointer object. 
      
    Arguments:
    pObject (I) Pointer to the object to be assigned.

    Throws:
    eNotThatKindOfClass if not successful. 
  */
  inline void internalQueryX(const OdRxObject* pObject)
  {
    if(pObject)
    {
      OdRxObject* pX = pObject->queryX(ClsIdRetriever::classId());
      if(pX)
        m_pObject = pX;
      else
        throw OdError(eNotThatKindOfClass);
    }
  }
  
  inline void assign(const OdRxObject* pObject)
  {
    release();
    internalQueryX(pObject);
  }
  
  // Note: Using of SmartPtr<T> as bool expression produce ambiguous call with some compilers.
  // Use isNull() method instead.

  /** Description:
      Declared private to prevent use. */
  bool operator !() const { ODA_FAIL(); return false; }
  
  /** Description:
      Declared private to prevent use. */
  operator bool() const { ODA_FAIL(); return false; }

  /** Description:
      Declared private to prevent use. */
  operator bool() { ODA_FAIL(); return false; }
  
public:
  /** Description:
    Arguments:
    pObject (I) Pointer to the object to be assigned to the new SmartPointer object.

    Remarks:
    If pObject is specified, the specified object is assigned to this SmartPointer object.
    
    Remarks:
    If OdRxObjMod or const OdBaseObjectPtr& are specified, the reference count of the referenced object 
    is *not* incremented. 
  */
  inline OdClsIdSmartPtr() { }
  
  inline OdClsIdSmartPtr(const T* pObject, OdRxObjMod) {m_pObject = (OdRxObject*)pObject; }
  
  inline OdClsIdSmartPtr(const T* pObject) {m_pObject = (OdRxObject*)pObject; internalAddRef(); }
  
  inline OdClsIdSmartPtr(const OdRxObject* pObject) { internalQueryX(pObject); }
  
  /** Description:
    Returns the OdRxClass of the object referenced by this SmartPointer object.
  */
  static inline const OdRxClass* classId()
  {
    return ClsIdRetriever::classId();
  }

  inline OdClsIdSmartPtr(OdRxObject* pObject, OdRxObjMod)
  {
    internalQueryX(pObject);
    if(pObject)
      pObject->release();
  }
  
  inline OdClsIdSmartPtr(const OdClsIdSmartPtr& pObject)
  {
    m_pObject = const_cast<T*>(static_cast<const T*>(pObject.get()));
    internalAddRef();
  }

  inline OdClsIdSmartPtr(const OdRxObjectPtr& pObject) { internalQueryX(pObject.get()); }
  
  inline OdClsIdSmartPtr(const OdBaseObjectPtr& pObject) { internalQueryX(pObject.get()); }

  static inline OdClsIdSmartPtr cast(ODSYSDEF , const OdRxObject* pObject)
  {
    OdClsIdSmartPtr pRes;
    if (pObject)
      pRes.attach(static_cast<T*>(pObject->queryX(ClsIdRetriever::classId())));
    return pRes;
  }
  
  /** Description:
    Assigns the specified object to this SmartPointer object.  
      
    Arguments:
    pObject (I) Pointer to the object to be assigned.

    Remarks:
    The reference count of the specified object is not incremented.

    If this SmartPointer is currently referencing another object, that object 
    is released prior to the assignment.
  */
  inline void attach(const T* pObject) { release(); m_pObject = const_cast<T*>(pObject); }
  
  inline void attach(OdRxObject* pObject)
  {
    release();
    internalQueryX(pObject);
    if(pObject)
      pObject->release();
  }
  
  /**
    Remarks:
    Decrements the reference count of the object referenced by this
    SmartPointer object.

    When the reference count reaches zero, the referenced object is deleted.
  */
  inline ~OdClsIdSmartPtr() { release(); }
  
  /** Description:
    Releases this SmartPointer's reference to the referenced object.
    
    Remarks:
    Decrements the reference count of the referenced object. 
    
    When the reference count reaches zero, the referenced object is deleted.
  */
  inline void release()
  {
    if (m_pObject)
    {
      static_cast<T*>(m_pObject)->release();
      m_pObject = 0;
    }
  }
  
  /** Description:
    Releases this SmartPointer's reference to the referenced object.
      
    Remarks:
    Returns the object referenced by this SmartPointer object.
    
    The referenced object's reference count is not modified.
  */
  inline T* detach()
  {
    T* res = static_cast<T*>(m_pObject);
    m_pObject = 0;
    return res;
  }
  
  inline OdClsIdSmartPtr& operator = (const OdClsIdSmartPtr& pObject)
  { assign(pObject); return *this; }
    
  inline OdClsIdSmartPtr& operator = (const OdBaseObjectPtr& pObject)
  { assign(pObject.get()); return *this; }
  
  inline OdClsIdSmartPtr& operator = (const T* pObject)
  { assign(pObject); return *this; }
  
  /** Description:
    Returns the object referenced by this SmartPointer object.  

    Remarks:
    This SmartPointer maintains its reference to the referenced object.
    
    The reference count of the referenced object is unchanged.
  */
  inline const T* get() const { return const_cast<T*>(static_cast<const T*>(m_pObject)); }
  
  inline T* get() { return static_cast<T*>(m_pObject); }
  
  /** Description:
    Returns the object referenced by this SmartPointer object.
      
    Remarks:
    The reference count of the referenced object is unchanged.
  */
  inline T* operator ->() { return static_cast<T*>(m_pObject); }
  
  inline const T* operator ->() const { return const_cast<T*>(static_cast<const T*>(m_pObject)); }
  
#ifdef ODA_GCC_2_95
  /** Description:
    Returns the object referenced by this SmartPointer object.
    
    Remarks:
    This SmartPointer maintains its reference to the referenced object.
    
    The reference count of the referenced object is unchanged.
  */
  inline operator T*() const { return static_cast<T*>(m_pObject); }
  
#else
  /** Description:
    Returns the object referenced by this SmartPointer object.
      
    Remarks:
    This SmartPointer maintains its reference to the referenced object.

    The reference count of the referenced object is unchanged.
  */
  inline operator T*() { return static_cast<T*>(m_pObject); }
  
  /** Description:
    Returns the object referenced by this SmartPointer object.
      
    Remarks:
    The reference count of the referenced object is unchanged.
  */
  inline operator const T*() const { return static_cast<const T*>(m_pObject); }
#endif
    
  inline bool operator==(const void* p) const { return (m_pObject==p); }

  inline bool operator==(const OdClsIdSmartPtr& ptr) const { return operator==((void*)ptr.get()); }
  
  inline bool operator!=(const void* p) const { return (m_pObject!=p); }

  inline bool operator!=(const OdClsIdSmartPtr& ptr) const { return operator!=((void*)ptr.get()); }
};

#include "TD_PackPop.h"

#endif //_ODSMARTCLSIDPTR_INCLUDED_
