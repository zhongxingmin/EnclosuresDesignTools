#ifndef _GCUIDOCK_H
#define _GCUIDOCK_H
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class GCUI_PORT CGcUiDockControlBar : public CGdUiDockControlBar {
    DECLARE_DYNCREATE(CGcUiDockControlBar);

public:
    CGcUiDockControlBar () {}

protected:
    virtual bool CanFrameworkTakeFocus ();
};

#pragma pack (pop)
#endif