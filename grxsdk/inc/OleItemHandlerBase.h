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

#ifndef _OLEITEMDATAHEADER_INCLUDED_
#define _OLEITEMDATAHEADER_INCLUDED_

#include "TD_PackPush.h"
#include "OleItemHandler.h"
#include "UInt8Array.h"
#include "DbRootExport.h"


/** Description:
    This class is intended to be used in implementing custom OLE handlers.

    Remarks:
    This class represents header of OdDbOle2Frame binary data.
    
    The header is an MFC COleClientItem object's fields serialized
    through MFC CArchive object. See MFC source code for details.

    {group:Other_Classes}
*/
class DBROOT_EXPORT OdOleItemHandlerBase : public OdOleItemHandler
{
protected:
  /* FROM MFC SOURCE:
  enum OLE_OBJTYPE
  {
    OT_UNKNOWN  = 0,

    // These are OLE 1.0 types and OLE 2.0 types as returned from GetType().
    OT_LINK     = 1,
    OT_EMBEDDED = 2,
    OT_STATIC   = 3,
    
    // All OLE2 objects are written with this tag when serialized.  This
    //  differentiates them from OLE 1.0 objects written with MFC 2.0.
    //  This value will never be returned from GetType().
    OT_OLE2     = 256,
  };
  */
  
  //OdUInt32  m_nOleVer;    // (enum OLE_OBJTYPE) must be always OT_OLE2
  //OdUInt32  m_nItemId;    // id in COleDocument
  //DvAspect  m_adviseType; // view advise type (DVASPECT)
  //OdUInt16  m_bMoniker;   // flag indicating whether to create moniker upon load
  //DvAspect  m_drawAspect; // current default display aspect

  OdUInt32  m_nOleVer;  
  OdUInt32  m_nItemId;   
  DvAspect  m_adviseType; 
  OdUInt16  m_bMoniker;   
  DvAspect  m_drawAspect; 


  OdOleItemHandlerBase();
public:
  ODRX_DECLARE_MEMBERS(OdOleItemHandlerBase);

  /** Description:
    Reads the header of the OdDbOle2Frame object.
    Arguments:
    streamBuf (I) StreamBuf object from which the data are to be read.
  */
  void load(OdStreamBuf& streamBuf);

  /** Description:
    Writes the header of the OdDbOle2Frame object.
    Arguments:
    streamBuf (I) StreamBuf object to which which the data are to be written.
  */
  void save(OdStreamBuf& streamBuf) const;

  /** Note:
    The default implementation of this function does nothing but return.
  */
  void draw(const OdGiCommonDraw& drawObj, void* hdc, const OdGsDCRect& screenRect) const;

  /** Note:
      The default implementation of this function returns kUnknown.
  */
  Type type() const;

  /** Note:
      The default implementation of this function returns an empty string.
  */
  OdString linkName() const;

  /** Note:
      The default implementation of this function returns an empty string.
  */
  OdString linkPath() const;

  /** Note:
      The default implementation of this function returns an empty string.
  */
  OdString userType() const;

  DvAspect drawAspect() const;

  void setDrawAspect(DvAspect drawAspect);

  OdUInt32 itemId() const;

  void setItemId(OdUInt32 nId);

  DvAspect adviseType() const;

  void setAdviseType(DvAspect at);

  bool monikerAssigned() const;

  void setMonikerAssigned(bool assigned);

  OdUInt32 oleVersion() const;

  void setOleVersion(OdUInt32 oleVer);
  
   virtual void* GetOleObject(){return NULL;}
  virtual void  setOdDbObject(OdDbObject*){}

  int GetLinkUpdateOption();

  void setLinkPath(OdString newPath);
};

/** Description:
    This class provides an interface to OLE compound documents.
    {group:Other_Classes}
*/
class DBROOT_EXPORT OdOleItemSimplestHandler : public OdOleItemHandlerBase
{
  OdUInt8Array  m_compDocData;
public:
  OdUInt32 getCompoundDocumentDataSize() const;

  void getCompoundDocument(OdStreamBuf& streamBuf) const;

  void setCompoundDocument(OdUInt32 numBytes, OdStreamBuf& streamBuf);
};


#include "TD_PackPop.h"

#endif // #ifndef _OLEITEMDATAHEADER_INCLUDED_
