#pragma once

//{{Struct && Union && Typedef
#define ads_real	gds_real
#define ads_point	gds_point
#define ads_matrix	gds_matrix
#define ads_name	gds_name
#define ads_resbuf	gds_resbuf
#define	ads_binary	gds_binary
#define	ads_u_val	gds_u_val
#define	ads_hdlg	gds_hdlg
#define	ads_htile	gds_htile
#define	ads_callback_packet	gds_callback_packet
//}}

//{{Function
//Ed
#define acrx_abort		gcedAbort
#define acedGetAppName	gds_getappname
#define acedUpdate		gds_update
#define adsw_acadMainWnd	gds_getmainhwnd
#define adsw_acadDocWnd		gds_getviewhwnd
#define adsw_hwndAcad	gdsw_hwndGcad
#define acedCommand		gds_command
#define acedCmd			gds_cmd
#define acedRegFunc		gds_regfunc
#define acedUsrBrk		gds_usrbrk
#define acedDefun		gds_defun
#define acedSetFunHelp	gds_setfunhelp
#define acedUndef		gds_undef
#define acedGetFunCode	gds_getfuncode
#define acedGetArgs		gds_getargs
#define acedGetAcadWinApp gcedGetGcadWinApp
#define acedRetList		gds_retlist
#define acedRetVal		gds_retval
#define acedRetPoint	gds_retpoint
#define acedRetStr		gds_retstr
#define acedRetName		gds_retname
#define acedRetInt		gds_retint
#define acedRetReal		gds_retreal
#define acedRetT		  gds_rett
#define acedRetNil		gds_retnil
#define acedRetVoid		gds_retvoid

#define acedEntSel		gds_entsel
#define acedNEntSel		gds_nentsel
#define acedNEntSelP	gds_nentselp
#define acedSSGet		  gds_ssget
#define acedSSGetFirst	gds_ssgetfirst
#define acedSSSetFirst	gds_sssetfirst
#define acedSSFree		  gds_ssfree
#define acedSSLength	  gds_sslength
#define acedSSAdd		  gds_ssadd
#define acedSSDel		  gds_ssdel
#define acedSSMemb		gds_ssmemb
#define acedSSName		gds_ssname
#define acedSSNameX		gds_ssnamex
#define acedSSGetKwordCallbackPtr	gcedSSGetKwordCallbackPtr
#define acedSSSetKwordCallbackPtr	gcedSSSetKwordCallbackPtr
#define acedSSGetOtherCallbackPtr	gcedSSGetOtherCallbackPtr
#define acedSSSetOtherCallbackPtr	gcedSSSetOtherCallbackPtr

#define acedTrans		gds_trans

#define acedGetVar		gds_getvar
#define acedSetVar		gds_setvar
#define acedGetCfg		gds_getcfg
#define acedSetCfg		gds_asetcfg
#define acedGetEnv		gds_agetenv
#define acedSetEnv		gds_asetenv

#define acedInitGet		gds_initget
#define acedGetAngle	gds_getangle
#define acedGetCorner	gds_getcorner
#define acedGetDist		gds_getdist
#define acedGetOrient	gds_getorient
#define acedGetPoint	gds_getpoint
#define acedGetInt		gds_getint
#define acedGetKword	gds_getkword
#define acedGetReal		gds_getreal
#define acedGetInput	gds_getinput
#define acedGetString	gds_getstring
#define acedGetStringB	gds_getstringb
#define acedVports		gds_vports
#define acedGetFullInput	gds_getfullinput
#define acedGetFullKword	gds_getfullkword
#define acedGetFullString	gds_getfullstring
#define acedSSNameXEx		gcedSSNameXEx

#define acedTextScr		gds_textscr
#define acedTextPage	gds_textpage
#define acedGraphScr	gds_graphscr
#define acedRedraw		gds_redraw
#define acedOsnap		gds_osnap
#define acedGrRead		gds_grread
#define acedGrText		gds_grtext
#define acedGrDraw		gds_grdraw
#define acedGrVecs		gds_grvecs
#define acedXformSS		gds_xformss
#define acedDragGen		gds_draggen
#define acedTextBox		gds_textbox
#define acedTablet		gds_tablet
#define acedSetView		gds_setview

#define acedGetCName	gds_getcname
#define acedGetSym		gds_getsym
#define acedPutSym		gds_putsym

#define acedHelp		gds_help
#define acedArxLoaded	gds_arxloaded
#define acedArxLoad		gds_arxload
#define acedArxUnload	gds_arxunload
#define acedInvoke		gds_invoke
#define acedFindFile	gds_findfile
#define acedFNSplit		gds_fnsplit

#define acedIsDragging	gcedIsDragging

#define ads_init		gds_init
#define ads_abort		gds_abort
#define ads_exit		gds_exit
#define ads_link		gds_link

#define acedMenuCmd		gds_menucmd
#define acedPrompt		gds_prompt
#define acedAlert		gds_alert

#define acedGetFileD	gds_getfiled
#define acedGetFileNavDialog gds_getfilenavdialog

//Db
#define	acdbAngToS		gds_angtos
#define acdbRToS		gds_rtos
#define acdbAngToF		gds_angtof
#define acdbDisToF		gds_distof
#define acdbInters		gds_inters
#define acdbSNValid		gds_snvalid

#define	acdbFail		gds_fail
#define acdbXdRoom		gds_xdroom
#define acdbXdSize		gds_xdsize
#define acdbHandEnt		gds_handent
#define acdbXStrSave	gds_xstrsave	
#define acdbXStrCase	gds_xstrcase
#define acdbNameSet		gds_name_set
#define acdbPointSet	gds_point_set
#define acdbNameClear	gds_name_clear
#define acdbNameNil		gds_name_nil
#define acdbNameEqual	gds_name_equal

#define acdbEntDel		gds_entdel
#define acdbEntGetX		gds_entgetx
#define acdbEntGet		gds_entget
#define acdbEntLast		gds_entlast
#define acdbEntNext		gds_entnext
#define acdbEntUpd		gds_entupd
#define acdbEntMod		gds_entmod
#define acdbEntMake		gds_entmake
#define acdbEntMakeX	gds_entmakex
#define acdbRegApp		gds_regapp
#define acdbTblNext		gds_tblnext
#define acdbTblSearch	gds_tblsearch
#define acdbTblObjName	gds_tblobjname
#define acdbDictSearch	gds_dictsearch
#define acdbDictNext	gds_dictnext
#define acdbDictRename	gds_dictrename
#define acdbDictRemove	gcdbDictRemove
#define acdbDictAdd		gds_dictadd
#define acdbNamedObjDict gds_namedobjdict

//Memory
#define acad_malloc		gcad_malloc
#define acad_free		  gcad_free
#define acad_realloc	gcad_realloc
#define acad_calloc		gcad_calloc
#define acad__msize		gcad__msize
#define acad__strdup	gcad__strdup

//Util
#define	acad__assert	gcad__assert
#define	acutCvUnit		gcutCvUnit
#define	acutWcMatch		gcutWcMatch
#define acutWcMatchEx   gcutWcMatchEx

#define	acutPrintf		gcutPrintf
#define	acutSPrintf		gcutSPrintf

#define	acutNewRb		gcutNewRb
#define	acutRelRb		gcutRelRb
#define	acutBuildList	gcutBuildList

#define	acutAngle		gcutAngle
#define	acutDistance	gcutDistance
#define	acutPolar		gcutPolar

#define	acutIsAlpha		gcutIsAlpha
#define	acutIsUpper		gcutIsUpper
#define	acutIsLower		gcutIsLower
#define	acutIsDigit		gcutIsDigit
#define	acutIsXDigit	gcutIsXDigit
#define	acutIsSpace		gcutIsSpace
#define	acutIsPunct		gcutIsPunct
#define	acutIsAlNum		gcutIsAlNum
#define	acutIsPrint		gcutIsPrint
#define	acutIsGraph		gcutIsGraph
#define	acutIsCntrl		gcutIsCntrl
#define	acutToUpper		gcutToUpper
#define	acutToLower		gcutToLower


//acutil
#define acutSplitString     gcutSplitString
#define	acutTrimWhiteSpace  gcutTrimWhiteSpace
#define acutXStrLength      gcutXStrLength
#define acutXStrNormalize   gcutXStrNormalize
#define acutXStrUppercase   gcutXStrUppercase
//Dcl
#define ads_load_dialog		dlg_load_dialog
#define ads_unload_dialog	dlg_unload_dialog
#define ads_new_dialog		dlg_new_dialog
#define ads_new_positioned_dialog	dlg_new_positioned_dialog
#define ads_start_dialog	dlg_start_dialog
#define ads_done_dialog		dlg_done_dialog
#define ads_done_positioned_dialog	dlg_done_positioned_dialog
#define ads_term_dialog		dlg_term_dialog
#define ads_action_tile		dlg_action_tile
#define ads_set_tile		dlg_set_tile
#define ads_client_data_tile	dlg_client_data_tile
#define ads_get_tile		dlg_get_tile
#define ads_get_attr		dlg_get_attr
#define ads_get_attr_string	dlg_get_attr_string
#define ads_start_list		dlg_start_list
#define ads_add_list		dlg_add_list
#define ads_end_list		dlg_end_list
#define ads_get_list_string	dlg_get_list_string
#define ads_mode_tile		dlg_mode_tile
#define ads_dimensions_tile	dlg_dimensions_tile
#define ads_start_image		dlg_start_image
#define ads_vector_image	dlg_vector_image
#define ads_fill_image		dlg_fill_image
#define ads_slide_image		dlg_slide_image
#define ads_end_image		dlg_end_image
//}}
