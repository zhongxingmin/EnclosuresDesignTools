#pragma once

#include "gcadstd.h"
#include "../Gs/Gs.h"
#include "../Gs/GsDefs.h"
#include "../Gs/GsBaseModel.h"
#include "../Gs/GsBaseVectorizer.h"
#include "../Gs/GsBitMap.h"
#include "../Gs/GsBMPDevice.h"
#include "../Gs/GsContainerNode.h"
#include "../Gs/GsDCPointArray.h"
#include "../Gs/GsEntityNode.h"
#include "../Gs/GsExport.h"
#include "../Gs/GsLayerNode.h"
#include "../Gs/GsLight.h"
#include "../Gs/GsLightNode.h"
#include "../Gs/GsModel.h"
#include "../Gs/GsNode.h"
#include "../Gs/GsSelectionReactor.h"
#include "../Gs/GsViewProps.h"
#include "../Gs/LineWtIndex.h"


//////////////////////////////////////////////////////////////////////////
// 
namespace GCGS
{
  typedef enum 
  {
    kSuccess = 0,
    kOutOfRange,
    kInvalidInput
  } ErrorStatus;

  typedef enum 
  {
    kScreenDevice = 0,
    kOffScreenDevice,
    kSelectionDevice
  } DeviceType;

  typedef enum  {
    kHighlightDashed            = 0, // Ĭ�ϸ�������
    kHighlightThicken           = 1, // �Ӻ�(����)
    kHighlightDashedAndThicken  = 2, // �м��������Ӻ� (�����������ȵ���ʾ�õ�)
    kHighlightCustom            = 3, // �Զ��� (ͼֽ�ռ���м����� ��̬�����е��� �ȵ�)
    kHighlightDim               = 4, // 
    kHighlightThickDim          = 5, // (����������2012 ������ ���幦��δ֪)
    kHighlightTransparency      = 99
  }HighlightStyle;

  // �ο� OdGsView::RenderMode

  typedef enum 
  {
    kWCS = 0,
    kOCS,     // Object, or Entity, or Model
    kECS,     // Eye (View)
    kDCS,     // Display (Projection)
    kUCS      // User
  } CoordnateSystem;

  typedef enum 
  {
    kNotCare = 0, // use last
    kDraw,
    kUndraw,
    kXOR,
    kHighlight,
    kXORHighlight,
    kXORFill,
  } DrawMode;

  typedef enum 
  {
    kModelSpace = 0,
    kPaperSpace
  } SpaceType;
};

typedef unsigned long GcGsDrawModeFlag;
#define GcGsMakeDMF(drawmode, highlightstyle) ((drawmode) | ((highlightstyle)<<8))
#define GcGsGetDrawMode(dmf)                  ((dmf) & 0xff)
#define GcGsGetDrawHLFlag(dmf)                (((dmf)>>8) & 0xff)

//////////////////////////////////////////////////////////////////////////
// 
typedef OdGiDrawable* (* GcGsGetInterfaceFunc)     (LONG_PTR objectId, bool bNeedsValidation);
typedef void          (* GcGsReleaseInterfaceFunc) (OdGiDrawable*);
class OdGiContextForDbDatabase;
typedef OdSmartPtr<OdGiContextForDbDatabase> OdGiContextForDbDatabasePtr;

class GcGsConfig;

class GcGsClassFactory
{
public:
  virtual ~GcGsClassFactory(void) { }

  //////////////////////////////////////////////////////////////////////////
  // ����7�������ڲ������ã���Ϊ����ARX�ӿڴ���
  virtual OdGsModel *  createModel   (OdGsModel::RenderType) { return NULL; }
  virtual void         deleteModel   (OdGsModel * model)         = 0;

  virtual OdGsModel *  createModel   (OdGsModel::RenderType, 
    LONG_PTR databaseId, 
    GcGsGetInterfaceFunc, 
    GcGsReleaseInterfaceFunc ) = 0;

  virtual OdGsView *   createView    (const OdGsClientViewInfo * pInfo = NULL,
    bool bEnableLayerVisibilityPerView = false) = 0;
  virtual void         deleteView    (OdGsView * view)           = 0;

  virtual OdGsDevice * createDevice  (OdGsWindowingSystemID id,
    GCGS::DeviceType deviceType = GCGS::kScreenDevice) = 0;
  virtual OdGsDevice * createOffScreenDevice(void)               = 0;
  virtual void         deleteDevice  (OdGsDevice * device)       = 0;

public:
  virtual OdGiContextForDbDatabasePtr createContext() = 0;

public:
  virtual GcGsConfig * getConfig     (void)                      = 0;
  virtual void         releaseConfig (GcGsConfig * config)       = 0;

  virtual void         addReactor    (OdGsReactor * pReactor)    = 0;
  virtual void         removeReactor (OdGsReactor * pReactor)    = 0;
};
