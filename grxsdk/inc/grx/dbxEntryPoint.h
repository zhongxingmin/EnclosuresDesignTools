#pragma once

#include <rxdlinkr.h>

struct _DBX_REGISTER_OBJECT_ENTRY
{
  GcRxClass* (*desc)() ;
  void (*rxInit) () ;
  bool bRegistered ;
  struct _DBX_REGISTER_OBJECT_ENTRY * next;
} ;

#define GCDB_REGISTER_OBJECT_ENTRY_AUTO(classname) \
  _DBX_REGISTER_OBJECT_ENTRY    __DbxCustObjMap_##classname = { classname::desc, classname::rxInit , false , NULL} ; \
  _CGcRxRegisterObjectEntryAuto __DbxRegisterObjectAuto_##classname(& __DbxCustObjMap_##classname);

#define DISPATCH_PKTMSG(pktmsg) case GcRx::pktmsg: return (On_ ##pktmsg (pkt))
#define DECLARE_PKTMSG_FUNC(pktmsg) virtual GcRx::AppRetCode On_ ##pktmsg (void* /*pkt*/) { return (GcRx::kRetOK) ; }

extern HINSTANCE _hdllInstance ;

class GcRxDbxApp
{
protected:
  HINSTANCE m_hdllInstance ;
  bool m_bUnlocked ;
  bool m_bMDIAware ;

public:
  GcRxDbxApp ()
    : m_hdllInstance(NULL)
    , m_bUnlocked(true)
    , m_bMDIAware(true)
    , m_pRegisterObjectEntryFirst(NULL)
    , m_pRegisterObjectEntryLast(NULL)
  {
  }

  virtual GcRx::AppRetCode On_kInitAppMsg (void *pkt)
  {

    m_hdllInstance =_hdllInstance ;
    if ( m_bUnlocked )
    {
      gcrxDynamicLinker->unlockApplication (pkt) ;
    }

    if ( m_bMDIAware )
    {
      gcrxDynamicLinker->registerAppMDIAware (pkt) ;
    }

    RegisterServerComponents () ;

    int nDbxCustObjCount =0 ;

    for (struct _DBX_REGISTER_OBJECT_ENTRY * pNode =m_pRegisterObjectEntryFirst ; pNode != NULL ; pNode = pNode->next )
    {
      pNode->rxInit();
      pNode->bRegistered = true ;
      nDbxCustObjCount ++;
    }

    if ( nDbxCustObjCount > 0 )
    {
      gcrxBuildClassHierarchy () ;
    }

    return (GcRx::kRetOK) ;
  }

  virtual GcRx::AppRetCode On_kUnloadAppMsg (void* /*pkt*/)
  {

    for (struct _DBX_REGISTER_OBJECT_ENTRY * pNode =m_pRegisterObjectEntryFirst ; pNode != NULL ; pNode = pNode->next )
    {
      if (pNode->bRegistered )
      {
        DeleteClassAndDescendant (pNode) ;
      }
    }
    return (GcRx::kRetOK) ;
  }

  DECLARE_PKTMSG_FUNC(kLoadDwgMsg)
  DECLARE_PKTMSG_FUNC(kUnloadDwgMsg)
  DECLARE_PKTMSG_FUNC(kInvkSubrMsg)
  DECLARE_PKTMSG_FUNC(kCfgMsg)
  DECLARE_PKTMSG_FUNC(kEndMsg)
  DECLARE_PKTMSG_FUNC(kQuitMsg)
  DECLARE_PKTMSG_FUNC(kSaveMsg)
  DECLARE_PKTMSG_FUNC(kDependencyMsg)
  DECLARE_PKTMSG_FUNC(kNoDependencyMsg)
  DECLARE_PKTMSG_FUNC(kOleUnloadAppMsg)
  DECLARE_PKTMSG_FUNC(kPreQuitMsg)
  DECLARE_PKTMSG_FUNC(kInitDialogMsg)
  DECLARE_PKTMSG_FUNC(kEndDialogMsg)
  DECLARE_PKTMSG_FUNC(kNullMsg)

  GcRx::AppRetCode gcrxEntryPoint (GcRx::AppMsgCode msg, void *pkt)
  {
    switch ( msg )
    {
      DISPATCH_PKTMSG (kInitAppMsg) ;
      DISPATCH_PKTMSG (kUnloadAppMsg) ;
      DISPATCH_PKTMSG (kLoadDwgMsg) ;
      DISPATCH_PKTMSG (kUnloadDwgMsg) ;
      DISPATCH_PKTMSG (kInvkSubrMsg) ;
      DISPATCH_PKTMSG (kCfgMsg) ;
      DISPATCH_PKTMSG (kEndMsg) ;
      DISPATCH_PKTMSG (kQuitMsg) ;
      DISPATCH_PKTMSG (kSaveMsg) ;
      DISPATCH_PKTMSG (kDependencyMsg) ;
      DISPATCH_PKTMSG (kNoDependencyMsg) ;
      DISPATCH_PKTMSG (kOleUnloadAppMsg) ;
      DISPATCH_PKTMSG (kPreQuitMsg) ;
      DISPATCH_PKTMSG (kInitDialogMsg) ;
      DISPATCH_PKTMSG (kEndDialogMsg) ;
      DISPATCH_PKTMSG (kNullMsg) ;
    }
    return (GcRx::kRetOK) ;
  }

  virtual void RegisterServerComponents () = 0 ;

  HINSTANCE &GetModuleInstance ()
  {
    return (m_hdllInstance) ;
  }

private:
  void DeleteClassAndDescendant (_DBX_REGISTER_OBJECT_ENTRY *pEntry)
  {
    for ( struct _DBX_REGISTER_OBJECT_ENTRY *pNode = m_pRegisterObjectEntryFirst ; pNode != NULL ; pNode = pNode->next )
    {
      if ( (pNode != pEntry) && (pNode->bRegistered ) )
      {
        if ( pNode->desc()->myParent () == pNode->desc () )
        {
          DeleteClassAndDescendant (pNode) ;
        }
      }
    }

    deleteGcRxClass (pEntry->desc ());
    pEntry->bRegistered =false ;
  }

public:
  struct _DBX_REGISTER_OBJECT_ENTRY * m_pRegisterObjectEntryFirst;
  struct _DBX_REGISTER_OBJECT_ENTRY * m_pRegisterObjectEntryLast;
};


GcRxDbxApp *gcrxGetApp () ;

class _CGcRxRegisterObjectEntryAuto
{
public:
  _CGcRxRegisterObjectEntryAuto( struct _DBX_REGISTER_OBJECT_ENTRY * pNode)
  {
    GcRxDbxApp *pApp = gcrxGetApp();
    if (pApp->m_pRegisterObjectEntryFirst == NULL)
    {
      pApp->m_pRegisterObjectEntryFirst = pNode;
    }

    if (pApp->m_pRegisterObjectEntryLast != NULL)
    {
      pApp->m_pRegisterObjectEntryLast->next = pNode;
    }

    pApp->m_pRegisterObjectEntryLast = pNode;
  }
};

#define IMPLEMENT_GRX_ENTRYPOINT_STD(classname) \
  HINSTANCE _hdllInstance =NULL ; \
  class classname entryPointObject ; \
  GcRxDbxApp *gcrxGetApp () { return (&entryPointObject) ; } \
  extern "C" GcRx::AppRetCode __declspec(dllexport) gcrxEntryPoint (GcRx::AppMsgCode msg, void *pkt) \
  { \
    return (entryPointObject.gcrxEntryPoint (msg, pkt)) ; \
  }

#define IMPLEMENT_GRX_ENTRYPOINT_CLR(classname) IMPLEMENT_GRX_ENTRYPOINT_STD(classname)
#define IMPLEMENT_GRX_ENTRYPOINT(classname)     IMPLEMENT_GRX_ENTRYPOINT_STD(classname)

