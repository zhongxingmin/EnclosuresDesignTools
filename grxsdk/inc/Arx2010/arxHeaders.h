#pragma once

//-----------------------------------------------------------------------------

#include "dbxHeaders.h"

#pragma pack (push, 8)

#include "accmd.h"
#include "aced.h"
#include "acdocman.h"
#include "actrans.h"
#include "acedsel.h"
#include "acedxref.h"
#include "lngtrans.h"
#include "dbltrans.h"
#include "acaplmgr.h"
#include "acedinet.h"
#include "acedinpt.h"
#include "AcDblClkEdit.h"
#include "AcGradThumbEng.h"

#include "dbjig.h"
#include "dbmatch.h"
#include "dbInterferencePE.h"
#include "dbosnap.h"
#include "xreflock.h"
#include "clipdata.h"

#ifdef _AFXEXT
#include "gs.h"
#endif

#include "AcGsManager.h"
#include "AcPl.h"
#include "AcPlDSDData.h"
#include "AcPlDSDEntry.h"
#include "AcPlHostAppServices.h"
#include "AcPlObject.h"
#include "AcPlPlotConfig.h"
#include "AcPlPlotConfigMgr.h"
#include "AcPlPlotEngine.h"
#include "AcPlPlotErrorHandler.h"
#include "AcPlPlotErrorHandlerLock.h"
#include "AcPlPlotFactory.h"
#include "AcPlPlotInfo.h"
#include "AcPlPlotInfoValidator.h"
#include "AcPlPlotLogger.h"
#include "AcPlPlotLoggingErrorHandler.h"
#include "AcPlPlotProgress.h"
#include "acplplotreactor.h"
#include "acplplotreactormgr.h"
#include "acpublishreactors.h"
#include "acpublishuireactors.h"
#include "acdmmapi.h"
#include "acdmmeplotproperties.h"
#include "acdmmeplotproperty.h"
#include "acdmmutils.h"

#ifdef _AFXEXT
#pragma warning (disable: 4275)
#include "adui.h"
#include "AcExtensionModule.h"
#include "aduiBaseDialog.h"
#include "aduiButton.h"
#include "aduiComboBox.h"
#include "aduiDialog.h"
#include "aduiDialogBar.h"
#include "aduiDialogWorksheet.h"
#include "aduiDock.h"
#include "aduiDropTarget.h"
#include "aduiEdit.h"
#include "aduiFileDialog.h"
#include "aduiHeaderCtrl.h"
#include "aduiListBox.h"
#include "aduiListCtrl.h"
#include "aduiMessage.h"
#include "aduiPalette.h"
#include "aduiPaletteSet.h"
#include "aduiPathname.h"
#include "aduiRegistryAccess.h"
#include "aduiTabChildDialog.h"
#include "aduiTabCtrl.h"
#include "aduiTabExtension.h"
#include "aduiTabMainDialog.h"
#include "aduiTextTip.h"
#include "aduiTheme.h"
#include "aduiThemeManager.h"
#include "aduiVolumeDescriptor.h"
#include "aduiCoupledGroupCtrl.h"
#include "aduiGroupCtrl.h"
#include "aduipathenums.h"

#include "acui.h"
#include "rxmfcapi.h"		//----- ARX MFC API.
#include "AcStatusBar.h"
#include "acuiButton.h"
#include "acuiComboBox.h"
#include "acuiDialog.h"
#include "acuiDialogWorksheet.h"
#include "acuidock.h"
#include "acuiEdit.h"
#include "acuiHeaderCtrl.h"
#include "acuiListBox.h"
#include "acuiListCtrl.h"
#include "acuiNavDialog.h"
#include "acuiPathname.h"
#include "acuiString.h"
#include "acuiTabCtrl.h"
//----- navigation dialog
#include "aNav.h"
#include "aNavArray.h"
#include "aNavData.h"
#include "aNavDataArray.h"
#include "aNavDialog.h"
#include "aNavFilter.h"
#include "aNavFilterArray.h"
#include "aNavListCtrl.h"

//----- Tool Palette API
#include "AcTc.h"
#include "AcTcUiManager.h"
#include "AcTcUI.h"
#include "AcTcUiCatalogView.h"
#include "AcTcUiCatalogViewItem.h"
#include "AcTcUiPaletteView.h"
#include "AcTcUiToolPalette.h"
#include "AcTcUiToolPaletteSet.h"
#include "AcTcUiToolPaletteGroup.h"
#include "AcTcUiScheme.h"
#include "dcdispid.h"

//- Field API
#include "AcFdUi.h"
#include "AcFdUiFieldDialog.h"
#include "AcFdUiFieldDialogHook.h"
#include "AcFdUiFieldFormatDialog.h"
#include "AcFdUiFieldFormatList.h"
#include "AcFdUiFieldManager.h"
#include "AcFdUiFieldOptionDialog.h"
#include "AcFdUtil.h"
#endif

#include "adsdlg.h"
#include "adsrxdef.h"
#include "adslib.h"

#include "acssgetfilter.h"
#include "acutasrt.h"
#include "arxEntryPoint.h"
#include "AcApDMgr.h"

//----- COM extensions
#ifdef __ATLCOM_H__
#include "dynpropmgr.h"
#endif

#include "ol_errno.h"

//----- ASI/ASE extensions
#ifdef _ASE_SUPPORT_
#include "asisys.h"
#include "asiappl.h"
#include "avoidtry.h"
#include "asiucode.h"
#include "asiconst.h"
#include "asisdata.h"
#include "asiclass.h"
#include "aseconst.h"
#include "aseclass.h"
#endif

//----- Render
//#include "averror.h"
//#include "avlib.h"

#pragma pack (pop)