#ifndef _UI_REACTOR_H_
#define _UI_REACTOR_H_

#include "..\OdMutex.h"
#include "..\RxEvent.h"
//#include <map>

//������ط�Ӧ������  �������ܣ����������������˷�Ӧ������

class CGcadUiReactor : public GcRxObject
{
public:
  /*
    ��ʽ�л�ʱ�����ķ�Ӧ���ӿ�themeStyleChanged
    @nThemeIndex ��ʽ����
  */
  virtual ~CGcadUiReactor() {}
  virtual void themeStyleChanged(HcInt32 nThemeIndex) = 0;

};


typedef OdSmartPtr<CGcadUiReactor> GcRxGcadUiReactorPtr;

#define DEFINE_UIEVENT(method, params)\
virtual void fire##method params

/*
  UI ��Ӧ��������ʹ�����
  ����Ӧ������ӣ� �Ƴ�������
*/
enum em_UITYPE
{
  em_Gcad = 0,
  em_Cmd,
  em_Layman,
  em_sheetSet,
};

typedef std::map<em_UITYPE, HINSTANCE> MAPUI2ICONSRC;
typedef std::map<HcInt32, MAPUI2ICONSRC> MAPTHEME2UISRC;


class CGcadUiEvent : public GcRxObject
{
public:
  CGcadUiEvent() {}
  virtual ~CGcadUiEvent() {}
  /*
    getCurThemeIndex ��ȡ��ǰ���������
    ����ֵ: ����������� 50000+
  */
  virtual HcInt32 getCurThemeIndex() = 0;
  /*
    getIconSrc ��ȡ��ǰ�������Դ���
    ����ֵ: ��Դ���
  */
  virtual HINSTANCE getIconSrcInstance(const em_UITYPE& emType) = 0;

public:
  /*
    addReactor ��ӷ�Ӧ��
    @pReactor ��Ҫ��ӵ��б�ķ�Ӧ��
  */
  virtual void addReactor(CGcadUiReactor* pReactor) = 0;
  /*
    removeReactor �Ƴ���Ӧ��
    @pReactor ��Ҫ���б����Ƴ��ķ�Ӧ��
  */
  virtual void removeReactor(CGcadUiReactor* pReactor) = 0;

  /*
    ThemeStyleChanged �����б��е����з�Ӧ��
    @nThemeIndex ��ǰ������ʽ������
  */
  DEFINE_UIEVENT(ThemeStyleChanged, (HcInt32 nThemeIndex)) = 0;

};

class CGcadUiEvents : public CGcadUiEvent
{
private:
  CGcadUiEvents();
  virtual ~CGcadUiEvents();

public:
  /*
    getCurThemeIndex ��ȡ��ǰ��������� 
    ����ֵ: ����������� 50000+
  */
  HcInt32 getCurThemeIndex();
  /*
    getIconSrc ��ȡ��ǰ�������Դ���
    ����ֵ: ��Դ���*/
  HINSTANCE getIconSrcInstance(const em_UITYPE& emType);

public:
  /*
    addReactor ��ӷ�Ӧ��
    @pReactor ��Ҫ��ӵ��б�ķ�Ӧ��
  */
  virtual void addReactor(CGcadUiReactor* pReactor);
  /*
    removeReactor �Ƴ���Ӧ��
    @pReactor ��Ҫ���б����Ƴ��ķ�Ӧ��
  */
  virtual void removeReactor(CGcadUiReactor* pReactor);

  /*
    ThemeStyleChanged �����б��е����з�Ӧ��
    @nThemeIndex ��ǰ������ʽ������
  */
  DEFINE_UIEVENT(ThemeStyleChanged, (HcInt32 nThemeIndex));

private:
  void initData();
  HINSTANCE loadSrcInstance(const em_UITYPE& emType);
  GcString getSrcName(const em_UITYPE& emType);

public:
  /*
    GcadUiEventInstance ��ȡ����UI��Ӧ����Ψһʵ��
    ����ֵ: UI��Ӧ����Ψһʵ��
  */
  static CGcadUiEvent* GcadUiEventInstance();
  /*
    releaseUiEvent �ͷ�����UI��Ӧ����Ψһʵ��
  */
  static void releaseUiEvent();
protected:
  GcArray<GcRxGcadUiReactorPtr> m_arrUiReactor;   //��Ӧ������
  OdMutex                       m_Mutex;          //�ٽ�������
  HcInt32                       m_nCurThemeIndex; //��ǰ���������
  MAPTHEME2UISRC                m_mapThemeSrc;    //�����Ӧ��Դ���

protected:
  static CGcadUiEvents* m_pGcadEvent;             //����UI��Ӧ��Ψһʵ��
};

GCUI_DLL_DECL CGcadUiEvent* gcrxUiEvent();       //��ȡ����UI��Ӧ����ʵ��

#define FIRE_UIEVENT(method)\
{  CGcadUiEvent* pEvt = gcrxUiEvent();\
  if (NULL != pEvt){pEvt->fire##method;}}

#endif//_UI_REACTOR_H_