#pragma once

#include "dbxEntryPoint.h"
#ifdef __ATLCOM_H__
#include "dynpropmgr.h"
#endif

struct _GRXCOMMAND_ENTRY
{
  const GCHAR *pszCmdGroupName ;
  const GCHAR *pszCmdGlobalName ;
  const GCHAR *pszCmdLocalName ;
  Hccad::Int32 commandFlags ;
  GcRxFunctionPtr pCmdFct ;
  GcEdUIContext *pUIContext ;
  UINT localNameID ;
  struct _GRXCOMMAND_ENTRY *next;
} ;



#define GCED_GRXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext) \
  _GRXCOMMAND_ENTRY __GrxCmdMap_##group##globCmd = { L#group, L#globCmd, L#locCmd, cmdFlags, classname::##group ##globCmd, UIContext, (UINT)-1 , NULL} ; \
  _CGcRxAddCommandEntryAuto __GrxAddCommandAuto_##group##globCmd(& __GrxCmdMap_##group##globCmd) ;

#define GCED_GRXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext) \
  _GRXCOMMAND_ENTRY __GrxCmdMap_##group##globCmd = { L#group, L#globCmd, NULL, cmdFlags, classname::##group ##globCmd, UIContext, locCmdId , NULL } ; \
  _CGcRxAddCommandEntryAuto __GrxAddCommandAuto_##group##globCmd(& __GrxCmdMap_##group##globCmd) ;


struct _GDSSYMBOL_ENTRY
{
  const GCHAR *pszName ;
  int (*fptr) () ;
  bool bRegFunc ;
  UINT nameID ;
  struct _GDSSYMBOL_ENTRY *next;
} ;


#define GCED_GDSSYMBOL_ENTRY_AUTO(classname, name, regFunc) \
  _GDSSYMBOL_ENTRY __GdsSymbolMap_##name = { L#name, classname::gds_ ##name, regFunc, (UINT)-1 , NULL } ; \
  _CGcRxAddSymbolEntryAuto __GrxAddSymbolAuto_##name(& __GdsSymbolMap_##name) ;

#define GCED_GDSCOMMAND_ENTRY_AUTO(classname, name, regFunc) \
  _GDSSYMBOL_ENTRY __GdsSymbolMap_##name = { L"C:" L#name, classname::gds_ ##name, regFunc, (UINT)-1 , NULL } ; \
  _CGcRxAddSymbolEntryAuto __GrxAddSymbolAuto_##name(& __GdsSymbolMap_##name) ;

#define GCED_GDSSYMBOL_ENTRYBYID_AUTO(classname, name, nameId, regFunc) \
  _GDSSYMBOL_ENTRY __GdsSymbolMap_##name = { NULL, classname::gds_ ##name, regFunc, nameId , NULL } ; \
  _CGcRxAddSymbolEntryAuto __GrxAddSymbolAuto_##name(& __GdsSymbolMap_##name) ;

#define GCED_GDSCOMMAND_ENTRYBYID_AUTO(classname, name, nameId, regFunc) \
  GCED_GDSSYMBOL_ENTRYBYID_AUTO(classname, name, nameId, regFunc)


class GcRxArxApp : public GcRxDbxApp
{
#ifdef __ATLCOM_H__
protected:
  GcRxDynPropManager *m_pDynPropManager ;
#endif

public:
  GcRxArxApp ()
    : GcRxDbxApp ()
#ifdef __ATLCOM_H__
    , m_pDynPropManager(NULL)
#endif
    , m_pCommandEntryFirst(NULL)
    , m_pCommandEntryLast(NULL)
    , m_pSymbolEntryFirst(NULL)
    , m_pSymbolEntryLast(NULL)
  {
  }


  virtual GcRx::AppRetCode On_kInitAppMsg (void *pkt)
  {
    GcRx::AppRetCode retCode =GcRxDbxApp::On_kInitAppMsg (pkt) ;
#ifdef __ATLCOM_H__
    m_pDynPropManager =new GcRxDynPropManager ;
#endif

    GCHAR buffer [133] ;
    for ( struct _GRXCOMMAND_ENTRY *pEntry = m_pCommandEntryFirst ; pEntry != NULL ; pEntry = pEntry->next )
    {
      if ( pEntry->pszCmdLocalName == NULL )
      {
        ::LoadString (m_hdllInstance, pEntry->localNameID, buffer, 132) ;
      }

      gcedRegCmds->addCommand(
        pEntry->pszCmdGroupName,
        pEntry->pszCmdGlobalName,
        pEntry->pszCmdLocalName == NULL ? buffer : pEntry->pszCmdLocalName,
        pEntry->commandFlags,
        pEntry->pCmdFct,
        pEntry->pUIContext,
        -1,
        (pEntry->commandFlags & GCRX_CMD_SESSION) ? NULL : m_hdllInstance,
        NULL ) ;
    }
    return (retCode) ;
  }

  virtual GcRx::AppRetCode On_kUnloadAppMsg (void *pkt)
  {
    GcRx::AppRetCode retCode =GcRxDbxApp::On_kUnloadAppMsg (pkt) ;
#ifdef __ATLCOM_H__
    if ( m_pDynPropManager != NULL )
    {
      delete m_pDynPropManager ;
      m_pDynPropManager =NULL ;
    }
#endif

    for ( struct _GRXCOMMAND_ENTRY *pEntry =m_pCommandEntryFirst ; pEntry != NULL ; pEntry = pEntry->next )
    {
      gcedRegCmds->removeCmd (pEntry->pszCmdGroupName , pEntry->pszCmdGlobalName ) ;
    }
    return (retCode) ;
  }

  virtual GcRx::AppRetCode On_kLoadDwgMsg (void *pkt)
  {
    GcRx::AppRetCode retCode =GcRxDbxApp::On_kLoadDwgMsg (pkt) ;

    GCHAR buffer [133] ;
    short param =0 ;
    for ( struct _GDSSYMBOL_ENTRY *pEntry =m_pSymbolEntryFirst ; pEntry != NULL ; pEntry = pEntry->next )
    {
      if ( pEntry->pszName == NULL )
      {
        ::LoadString (m_hdllInstance, pEntry->nameID, buffer, 132) ;
      }
      
      gcedDefun ( (pEntry->pszName) == NULL ? buffer : pEntry->pszName , param ) ;
      if ( pEntry->bRegFunc )
      {
        gcedRegFunc (pEntry->fptr, param) ;
      }
      param++ ;
    }
    return (retCode) ;
  }

  virtual GcRx::AppRetCode On_kUnloadDwgMsg (void *pkt)
  {
    GcRx::AppRetCode retCode = GcRxDbxApp::On_kUnloadDwgMsg (pkt) ;

    GCHAR buffer [133] ;
    short param =0 ;
    for ( struct _GDSSYMBOL_ENTRY *pEntry = m_pSymbolEntryFirst ; pEntry != NULL ; pEntry = pEntry->next )
    {
      if ( pEntry->pszName == NULL )
      {
        ::LoadString (m_hdllInstance, pEntry->nameID, buffer, 132) ;
      }

      gcedUndef ( (pEntry->pszName == NULL) ? buffer : pEntry->pszName, param++ ) ;
    }
    return (retCode) ;
  }

  virtual GcRx::AppRetCode On_kInvkSubrMsg (void *pkt)
  {
    GcRx::AppRetCode retCode = GcRxDbxApp::On_kInvkSubrMsg (pkt) ;
 
    int param = gcedGetFunCode () ;

    int paramIter = 0 ;
    for ( struct _GDSSYMBOL_ENTRY *pEntry = m_pSymbolEntryFirst; pEntry != NULL ; pEntry = pEntry->next )
    {
      if ( paramIter++ == param )
      {
        (*(pEntry->fptr)) () ;
        break ;
      }
    }
    return (retCode) ;
  }

public:
  struct _GRXCOMMAND_ENTRY * m_pCommandEntryFirst;
  struct _GRXCOMMAND_ENTRY * m_pCommandEntryLast;
  struct _GDSSYMBOL_ENTRY  * m_pSymbolEntryFirst;
  struct _GDSSYMBOL_ENTRY  * m_pSymbolEntryLast;
} ;

class _CGcRxAddCommandEntryAuto
{
public:
  _CGcRxAddCommandEntryAuto( struct _GRXCOMMAND_ENTRY * pNode)
  {
    GcRxArxApp *pApp = (GcRxArxApp *)gcrxGetApp();
    if (pApp->m_pCommandEntryFirst == NULL)
    {
      pApp->m_pCommandEntryFirst = pNode;
    }

    if (pApp->m_pCommandEntryLast != NULL)
    {
      pApp->m_pCommandEntryLast->next = pNode;
    }

    pApp->m_pCommandEntryLast = pNode;
  }
};

class _CGcRxAddSymbolEntryAuto
{
public:
  _CGcRxAddSymbolEntryAuto( struct _GDSSYMBOL_ENTRY * pNode)
  {
    GcRxArxApp *pApp = (GcRxArxApp *)gcrxGetApp();
    if (pApp->m_pSymbolEntryFirst == NULL)
    {
      pApp->m_pSymbolEntryFirst = pNode;
    }

    if (pApp->m_pSymbolEntryLast != NULL)
    {
      pApp->m_pSymbolEntryLast->next = pNode;
    }
    pApp->m_pSymbolEntryLast = pNode;
  }
};