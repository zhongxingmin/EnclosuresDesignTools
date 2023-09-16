#pragma once
#include "stdafx.h"
#include "gduiDock.h"
#include <afxpriv.h>

class  CGcUiDockFrame : public CMiniDockFrameWnd
{
  DECLARE_DYNCREATE(CGcUiDockFrame);
public:
  CGcUiDockFrame() {}
  virtual         ~CGcUiDockFrame() {}
};

class CGcUiPaletteSetDockFrame : public CMiniDockFrameWnd {
  DECLARE_DYNCREATE(CGcUiPaletteSetDockFrame);
public:
  CGcUiPaletteSetDockFrame() {}
  virtual         ~CGcUiPaletteSetDockFrame() {}
};


