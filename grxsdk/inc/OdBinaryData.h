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




#ifndef _ODBINARYDATA_INCLUDED_
#define _ODBINARYDATA_INCLUDED_

#include "TD_PackPush.h"

#include "OdArray.h"

class OdDbDwgFiler;

/** Description:
    This class is a specialization of the OdArray class for OdUInt8 (byte) objects.
    Library: TD_Db
    {group:Other_Classes}
*/
class OdBinaryData : public OdArray<OdUInt8, OdMemoryAllocator<OdUInt8> >
{
};


/** Description:
    This Class is a specialization of the OdBinaryData class for BitBinary data.

    {group:Other_Classes}
*/
class OdBitBinaryData : public OdBinaryData
{
  OdUInt32 m_nBitSize;
public:
  OdBitBinaryData() : m_nBitSize(0) {}

  /**Description:
    Returns the *size* in bits of this BitBinaryData object.
  */
  OdUInt32 getBitSize() const { return m_nBitSize; }

  /**Description:
    Resizes this BitBinaryData object to the specified number of bits.
    
    Arguments:
    bitSize (I) Bit *size*.
  */
  void setBitSize(OdUInt32 value) { m_nBitSize = value; resize((m_nBitSize+7)/8); }

  /**Description:
    Sets the *size* in bits of this BitBinaryData object to be 8 * its current *size* in bytes.
    
    Arguments:
    bitSize (I) Bit *size*.
  */
  void updateBitSize() {setBitSize( size() * 8 );}
};

#include "TD_PackPop.h"

#endif //_ODBINARYDATA_INCLUDED_

