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




#ifndef OD_DBMLINESTYLE_H
#define OD_DBMLINESTYLE_H

#include "TD_PackPush.h"

#include "DbObject.h"

class OdDbMlineStyleImpl;

#define MSTYLE_NAME_LENGTH 32
#define MSTYLE_DESCRIPTION_LENGTH 256
#define LTYPE_LENGTH 32
#define MLINE_MAX_ELEMENTS 16

// 10 degrees
//
#define MIN_ANGLE (10.0 * PI / 180.0)

// 170 degrees
//
#define MAX_ANGLE (170.0 * PI / 180.0)

#define MSTYLE_DXF_FILL_ON           (0x1)
#define MSTYLE_DXF_SHOW_MITERS       (0x2)
#define MSTYLE_DXF_START_SQUARE_CAP  (0x10)
#define MSTYLE_DXF_START_INNER_ARCS  (0x20)
#define MSTYLE_DXF_START_ROUND_CAP   (0x40)
#define MSTYLE_DXF_END_SQUARE_CAP    (0x100)
#define MSTYLE_DXF_END_INNER_ARCS    (0x200)
#define MSTYLE_DXF_END_ROUND_CAP     (0x400)
#define MSTYLE_DXF_JUST_TOP          (0x1000)
#define MSTYLE_DXF_JUST_ZERO         (0x2000)
#define MSTYLE_DXF_JUST_BOT          (0x4000)

/** Description:
    This class represents *Mline* Style objects in an OdDbDatabase instance.
    
    Library:
    TD_Db

    OdDbMlineStyle objects are stored in the ACAD_MLINESTYLE dictionary 
    in the Named Object Dictionary of an OdDbDatabase.
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbMlineStyle: public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbMlineStyle);

  OdDbMlineStyle();
  virtual ~OdDbMlineStyle();

  /** Description:
    Initializes or re-initializes this *Mline* Style object.

    Remarks:
    Initialization is done as follows:
  
    @table
    Property      Value
    Name          Empty string
    Description   Empty string
    FillColor     0
    StartAngle    90?
    EndAngle      90?
    ElementList   Empty
  */
  void initMlineStyle();

  /** Description:
    Copies the specified OdDdMlineStyle object to this *Mline* Style object. 

    Arguments:
    source (I) Object to be cloned.
    checkIfReferenced (I) Currently ignored.
    
  */
  void set(
    const OdDbMlineStyle & source, 
    bool checkIfReferenced = true);

  /** Description:
    Sets the *description* for this *Mline* Style object (DXF 3).

    Arguments:
    description (I) Description.
  */
  OdResult setDescription(
    const OdChar * description);

  /** Description:
    Returns the *description* for this *Mline* Style object (DXF 3).
  */
  const OdChar * description() const;

  /** Description:
    Sets the *name* for this *Mline* Style object (DXF 2).

    Arguments:
    name (I) Name.
  */
  OdResult setName(
    const OdChar* name);

  /** Description:
    Returns the *name* for this *Mline* Style object (DXF 2).
  */
  const OdChar * name() const;

  /** Description:
    Controls the display of Miters for this *Mline* Style object (DXF 70, bit 0x02).

    Arguments:
    showThem (I) True if and only if miters are to be displayed.  
  */
  void setShowMiters(
    bool showThem);

  /** Description:
    Returns the display of Miters for this *Mline* Style object (DXF 70, bit 0x02).
    
    Remarks:
    Returns true if and only if miters are displayed.
  */
  bool showMiters() const;

  /** Description:
    Controls the display of Start Square Caps for this *Mline* Style object (DXF 70, bit 0x01).

    Arguments:
    showThem (I) True if and only if Start Square Caps are to be displayed.  
  */
  void setStartSquareCap(
    bool showThem);

  /** Description:
    Returns the display of Start Square Caps for this *Mline* Style object (DXF 70, bit 0x01).

    Remarks:
    Returns true if and only if Start Square Caps are to be displayed.
  */
  bool startSquareCap() const;

  /** Description:
    Controls the display of Start Round Caps for this *Mline* Style object (DXF 70, bit 0x40).

    Arguments:
    showThem (I) True if and only if Start Round Caps are to be displayed.  
  */
  void setStartRoundCap(
    bool showThem);

  /** Description:
    Returns the display of Start Round Caps for this *Mline* Style object (DXF 70, bit 0x40).
    Remarks:
    Returns true if and only if Start Round Caps are to be displayed.
  */
  bool startRoundCap() const;

  /** Description:
    Controls the display of Start Inner Arcs for this *Mline* Style object (DXF 70, bit 0x20).

    Arguments:
    showThem (I) True if and only if Start Inners Arcs are to be displayed.  
  */
  void setStartInnerArcs(
    bool showThem);

  /** Description:
    Returns the display of Start Inner Arcs for this *Mline* Style object (DXF 70, bit 0x20).

    Remarks:
    Returns true if and only if Start Inners Arcs are to be displayed.
  */
  bool startInnerArcs() const;

  /** Description:
    Controls the display of End Square Caps for this *Mline* Style object (DXF 70, bit 0x80).

    Arguments:
    showThem (I) True if and only if End Square Caps are to be displayed.
      
  */
  void setEndSquareCap(
    bool showThem);

  /** Description:
    Returns the display of End Square Caps for this *Mline* Style object (DXF 70, bit 0x80).
    Remarks:
    True if and only if End Square Caps are to be displayed.
  */
  bool endSquareCap() const;

  /** Description:
    Controls the display of End Round Caps for this *Mline* Style object (DXF 70, bit 0x200).

    Arguments:
    showThem (I) True if and only if End Round Caps are to be displayed.  
  */
  void setEndRoundCap(
    bool showThem);

  /** Description:
    Returns the display of End Round Caps for this *Mline* Style object (DXF 70, bit 0x200).
    
    Remarks:
    Returns true if and only if End Round Caps are to be displayed.
  */
  bool endRoundCap() const;


  /** Description:
    Controls the display of End Inner Arcs for this *Mline* Style object (DXF 70, bit 0x100).

    Arguments:
    showThem (I) True if and only if End Inner Arcs are to be displayed.  
  */
  void setEndInnerArcs(bool showThem);

  /** Description:
    Returns the display of End Inner Arcs for this *Mline* Style object (DXF 70, bit 0x100).
    Remarks:
    Returns true if and only if End Inner Arcs are to be displayed.
  */
  bool endInnerArcs() const;

  /** Description:
    Sets the fill color for this *Mline* Style object (DXF 62).
    
    Arguments:
    fillColor (I) Fill Color.
  */
  OdResult setFillColor(
    const OdCmColor& fillColor);

  /** Description:
    Returns the fill color for this *Mline* Style object (DXF 62).
  */
  const OdCmColor& fillColor() const;

  /** Description:
    Controls the *filled* flag for this *Mline* Style object (DXF 70, bit 0x01).
    
    Arguments
    filled (I) True for *filled*, false for not *filled*.
  */
  void setFilled(
    bool filled);

  /** Description:
    Returns the *filled* flag for this *Mline* Style object (DXF 70, bit 0x01).
  */
  bool filled() const;

  /** Description:
    Sets the start angle for this *Mline* Style object (DXF 51).
    
    Arguments:
    startAngle (I) Start angle.
  */
  OdResult setStartAngle(
    double startAngle);
  
  /** Description:
    Returns the start angle for this *Mline* Style object (DXF 51).
  */
  double startAngle() const;

  /** Description:
    Sets the end angle for this *Mline* Style object (DXF 52).
    
    Arguments:
    endAngle (I) End angle.
  */
  OdResult setEndAngle(
    double endAngle);

  /** Description:
      Returns the end angle for this *Mline* Style object (DXF 52).
  */
  double endAngle() const;

  /** Description:
    Adds an element to this MLine Style object.

    Arguments:
    offset (I) Offset of this element.
    color (I) Color of this element.
    linetypeId (I) Object ID of the linetype of this element.
    checkIfReferenced (I) Currently ignored.

    Remarks:
    Returns the index of the newly added element.
  */
  int addElement(
    double offset, 
    const OdCmColor& color,
    OdDbObjectId linetypeId, 
    bool checkIfReferenced = true);

  OdResult addElement(
	int& elem,
    double offset, 
    const OdCmColor& color,
    OdDbObjectId linetypeId, 
    bool checkIfReferenced = true);
  
  /** Description:
    Removes the specified element from this MLine Style object.

    Arguments:
    elementIndex (I) Index of element to be removed.  
  */
  OdResult removeElementAt(
    int elem);

  /** Description:
      Returns the number of elements in this MLine Style (DXF 71).
  */
  int numElements() const;

  /** Description:
    Sets the specified element of this MLine Style object.

    Arguments:
    elementIndex (I) Index of element to modify.  
    offset (I) Offset of this element.
    color (I) Color of this element.
    linetypeId (I) Object ID of the linetype of this element.

    Remarks:
    Returns the index of the newly added element.
  */
  OdResult setElement(
    int& elementIndex, 
    double offset, 
    const OdCmColor& color,
    OdDbObjectId linetypeId);

  /** Description:
    Returns the values for the specified element of this MLine Style.

    Arguments:
    elementIndex (I) Index of element to return.  
    offset (O) Receives the *offset* of this element.
    color (O) Receives the *color* of this element.
    linetypeId (O) Receives the Object ID for the linetype of this element.

  */
  OdResult getElementAt(
    int elementIndex, 
    double& offset, 
    OdCmColor& color,
    OdDbObjectId& linetypeId) const;

  virtual OdResult subErase(OdBool pErasing = true);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields( // Gcad(Modify)
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields( // Gcad(Modify)
    OdDbDxfFiler* pFiler) const;

  OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual void appendToOwner(
    OdDbIdPair& idPair,
    OdDbObject* pOwnerObject,
    OdDbIdMapping& ownerIdMap);

  virtual OdResult copyFrom(const OdRxObject* other);
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbMlineStyle object pointers.
*/
typedef OdSmartPtr<OdDbMlineStyle> OdDbMlineStylePtr;

#include "TD_PackPop.h"

#endif

