/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2012, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) for .dwg files Copyright (C) 2003-2012 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef OdExpression_INCLUDED_
#define OdExpression_INCLUDED_ /* {Secret} */

#include "OdArray.h"
#include "OdString.h"
#include "DbEvalVariant.h"
#include "StringArray.h"

/*!DOM*/
namespace OdExpression {

class ImpParser;

/*!DOM*/
class Parser {
public:
  Parser();
  ~Parser();

  OdResult setName(const OdString& name);
  OdResult addVariable(const OdString& name, OdDbEvalVariantPtr value);
  OdResult fixVariable(const OdString& name, OdDbEvalVariantPtr value);
  OdResult renameVariable(const OdString& oldName, const OdString& newName);

  OdResult setExpression(const OdString& expression);

  OdDbEvalVariantPtr evaluate();
  bool isConstExpression();
  OdResult getVariables(OdStringArray& usedVars);

  OdString getTranslated();

private:
  Parser(const Parser&);
  void operator=(const Parser&);
  ImpParser* m_pImpl;
};

OdString createExpression(OdDbEvalVariantPtr value);
} // namespace OdExpression

#endif
