/*****************************************************************************
***     �ļ���: GcPlot.h
*****************************************************************************/

#ifndef __GCAD__GS_PLOT__INTERFACE__H__
#define __GCAD__GS_PLOT__INTERFACE__H__

#include "../GcGraphicSystemService.h"
#include "GcPlotDataDumpper.h"


class GcGePoint2d;
class GcDbObject;
class GcDbObjectId;
class GcApDocument;

struct GcPlotParameters
{
  /* ��ӡ�ռ�
   0: ��ǰtilemodeָ�� Model_Space or Paper_Space
   1: ģ�� Model_Space
   2: ͼֽ Paper_Space
   3: ���� Model_Space, Paper_Space, Paper_Space0, Paper_Space1, ...
  */
  int  pltSpace; // Ĭ��ֵ: 0(��ǰtilemodeָ��)
  GcDbObjectId blkSpaceId;  // ���� pltSpace=3 ʱ��Ч

  /* ��ӡ����
   0: "��ʾ"����ǰ��ͼ�Ŀɼ���Χ����ͼ�ɼ���Χ��Ĳ���ӡ�����ܲü���
   1: "����"��"����"����Ե�ǰ��ͼ��ģ�Ϳռ�Ϊ"����"��ͼֽ�ռ�Ϊ"����"
      "����"��ͼֽ�ռ����趨�Ĵ�ӡͼֽ��С��ͼֽ��Ĳ���ӡ�����ܲü���
      "����"��ģ�Ϳռ����趨��LIMMIN,LIMMAXϵͳָ���������÷�Χ�Ĳ���ӡ�����ܲü���
   2: "����"����ǰ��ͼָ���Ĵ��ڷ�Χ�������÷�Χ�Ĳ���ӡ�����ܲü���
   3: "��Χ"����Ե�ǰ��ͼ����ǰ�ռ���������ʵ���ͼ�η�Χ���޲ü�
   4: "��ͼ"��ָ����ͼ�Ŀɼ���Χ���������Ӧ��ͼ����ͼ�ɼ���Χ��Ĳ���ӡ�����ܲü���
  */
  int  pltArea;  // Ĭ��ֵ: 0("��ʾ")
  GcGePoint2d lower_left, upper_right; // DCS������ pltArea=2 ʱ��Ч
  GcDbObjectId pltViewId; // ���� pltArea=4 ʱ��Ч

  GcGePoint2d pltRealArea;	//��ӡ����ȣ����أ�

  /* ��ӡ���ĵ�
   plotCenter: ����ֵ���������ã����ⲿ�����ã�����ֵ������
     pltArea=0: ��ǰ��ͼ�����ĵ�
     pltArea=1: ͼ�ν��޵����ĵ� ���� ���ֿռ��´�ӡͼֽ�����ĵ�
     pltArea=2: ָ�����ڵ����ĵ�
     pltArea=3: ͼ�η�Χ�����ĵ�
     pltArea=4: ��ǰ��ͼ(pltViewId)�����ĵ�
     viewCenter!=NULL: viewCenter
   viewCenter: ��ΪNULL����ʾ�Զ������ĵ�
  */
  GcGePoint2d plotCenter;
  const GcGePoint2d* pltViewCenter; // Ĭ��ֵ: NULL

  /* ��ӡ����ģʽ
   0: Ĭ�ϣ�ʹ�ô�ӡ��ͼ�Ļ���ģʽ
   1: ��׼���߿� (Wireframe)
   2: ����, Hidden Lines Removed
   3: ��ɫ, Shaded
   4: �Ӿ���ʽ, Visual Style
  */
  int  pltViewMode; // Ĭ��ֵ: 0

  /* ��ӡ˳��
   0: Ĭ�ϣ�ʹ�õ�ǰ�ռ�Ļ���˳��
   1: ���棬ʹ��ʵ��Ĵ���˳��
   2: ͼֽ���, �Ի���˳����д�ӡ���������������ͼֽ�ռ��ڵ�ʵ�����
  */
  bool pltOrder;  // Ĭ��ֵ: 0

  /* ��ӡʵ�壨���������ã�
   0: ����ʵ��
   1: ָ�� GcDbObjectId ����
   2: ָ�� GcDbObject ����
   3: ָ��ѡ��
   x: ������չ�������޶���ӡĳ��ʵ�壬�ȵ�
  */
  int  pltEntities; // Ĭ��ֵ: 0(all entities)
  struct _PlotIds
  {
    OdInt32 num;
    const GcDbObjectId* ids;
  } plotIds;   // ���� pltEntities=1 ʱ��Ч
  struct _PlotObjs
  {
    OdInt32 num;
    const GcDbObject** objs;
  } plotObjs;  // ���� pltEntities=2 ʱ��Ч
  //GcEdSelectionSet* ss; //???

  /* ��������
  */
  GcDbObjectId vstyleId; // �Ӿ���ʽID����pltViewMode==4������

  GcString     pltStyleFilePath;

  bool pltLineweights;
  bool pltPlotStyles;
  double pltScaleLineweights;

  GcPlotParameters()
  {
    pltSpace = 0;
    pltArea = 0;
    pltViewCenter = NULL;
    pltViewMode = 0;
    pltOrder = 0;
    pltEntities = 0;
    plotIds.num = 0;
    plotIds.ids = NULL;
    plotObjs.num = 0;
    plotObjs.objs = NULL;
    pltLineweights = true;
    pltPlotStyles = true;
    pltScaleLineweights = 1.0;
  }
};

class GcPlotInterface
{
public:
  virtual OdInt32 genPlotData(GcDbObjectId blockTableRecordId, // NULL => curDocument()
    GcPlotDataDumpper* pDumpper,
    GcPlotParameters* pParams,
    GcPlotProgressMeter* pProgress = NULL) = 0;
  virtual void clearPlotData() = 0;
};

inline GcPlotInterface* gcgsPlotInterface()
{
  GcadGraphicSystemService* pGsSrv = gcadGraphicSysService();
  return pGsSrv ? pGsSrv->plotInterface() : NULL;
}


#endif //__GCAD__GS_PLOT__INTERFACE__H__

