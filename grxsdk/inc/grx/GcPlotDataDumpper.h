/*****************************************************************************
***     �ļ���: GcPlotDataDumpper.h
*****************************************************************************/

#ifndef __GCAD__PLOT_DUMPPER__INTERFACE__H__
#define __GCAD__PLOT_DUMPPER__INTERFACE__H__

#pragma once
class OdGsView;
class OdGiCommonDraw;
class OdCmEntityColor;


enum PlotGenResult
{
  //Ҫ������
  eContinueSimplification = 0x1,
  //����REGN
  eAbortSimplification = 0x2,
  //��������ȷ��ӡ���
  ePlotOk = 0x0
};

enum PlotGenSupportType
{
  plNothing   = 0,      // ��֧��ֱ�ߺ�������� 

  plFillPath  = 0x0001, // ·�����֧�֣�����֧�֣�����������������ʷ�(�ڴ���ٶ���)
  plCircle    = 0x0002, // ֧��Բ
  plCircleArc = 0x0004, // ֧��Բ��
  plEllipArc  = 0x0008, // ֧����Բ/��Բ��
  plNurbs     = 0x0010, // ֧��Nurbs
  plPlineCW   = 0x0020, // �̶��߿��PLine(�Ż�ͼԪ����ʡ�ڴ棬�ӿ�����)
  plRasterExt = 0x0040, // ֧�ֹ�դͼ���ڲ�ת��(������͸�������ȣ��Աȶȣ���ɫ)

  plGdiText   = 0x0100, // GDI ����֧��
  plGdiDraw   = 0x0200, // ֧�� GDI ���ƣ�����(OLE,WMF)
  plGradient  = 0x0400, // ֧�ֽ������

  plUseDeviation = 0x1000,     // �Զ��徫�ȣ��ص�deviation()������֧�֣���ͨ��DPI����

  plDefault      = plFillPath, // Ĭ��֧����ʽ
  plSupportAll   = 0xFFFF      // ȫ����չ֧��
};


class GcPlotDataDumpper
{
public:
  virtual ~GcPlotDataDumpper(void) {}

public:
  enum 
  {
    Maximal_Simplification,
    Minimal_Simplification
  };
  virtual void setDumpLevel(int dumpLevel) = 0;
  virtual int dumpLevel() const = 0;

public: // query
  // dpi (���ƾ���)
  virtual double dot_per_inch() const = 0;
  virtual double dot_per_mm() const = 0;

  // ʵ�ʴ�ӡ�����С��С�ڻ����ҳ���С (�漰�ü�)
  virtual void plot_size_inch(OdGePoint2d& sz) const = 0;
  virtual void plot_size_mm(OdGePoint2d& sz) const = 0;
  virtual double logic_per_pixel() const = 0;
  // ����ɫ (RGB)
  virtual COLORREF backgroundColor() const = 0;

  // �任����(DCS->PCS)��Ŀǰ����
  // �������(setViewportCenter, setViewportField)���
  virtual OdGeMatrix3d plotMatrix() const = 0;

  // ֧������
  virtual OdUInt32 supportTypes() const = 0;

  // ���߾���
  virtual double deviation(const OdGiDeviationType dtype) const = 0;

  // �ӿ����ĵ�(DCS)
  virtual void setViewportCenter(const OdGePoint2d& centerOffset) = 0;
  // �ӿڹ۲췶Χ(DCS)
  virtual void setViewportField(double fieldWidth, double fieldHeight) = 0;

  // �ӿڲü����򣨽�ͼֽ�ռ䣩
  // numPolygons=1, pointCounts[0]=2 ʱΪ���βü�����(points[0]���� points[1]����)
  // �������Ϊ�Ǿ��βü��������� PolyPolygon ����
  virtual DWORD_PTR pushViewportClip(const OdGePoint2d* points,
    const int *pointCounts,
    int numPolygons) = 0;
  virtual void popViewportClip(DWORD_PTR status) = 0;

  //ѹ��һ��ģ�;���Ŀǰ����
  virtual void push_model_matrix(const OdGeMatrix2d &model) = 0;
  //����һ��ģ�;����У�Ŀǰ����
  virtual void pop_model_matrix(const OdGeMatrix2d &model) = 0;

public: // event
  //����TRUE����ʾ��ӡȡ��
  virtual bool regenAbort() const = 0;

  // ��ʼ����ӡ
  virtual void beginPlot() = 0;
  // ������ӡ
  virtual void endPlot(bool bAborted = false) = 0;

  // ��ʼ��ͼ
  virtual void beginView(OdGsView* pView, const OdGeMatrix3d *xVport2Overall = NULL) = 0;
  // ������ͼ
  virtual void endView(OdGsView* pView) = 0;

  // ��ʼ��ӡʵ��ǰ���ã�����falseʱ����ʵ�岻�����
  virtual bool beginDrawable(const OdGiDrawable *pDrawable) = 0;
  // ����һ��ʵ������
  virtual void endDrawable(const OdGiDrawable *pDrawable) = 0;

public: // attribs setting
  // ���� backgroundColor(), ���õ�ǰ��ɫ��
  virtual void loadLogicalPalette(COLORREF* pPalette, OdUInt16 nColors) = 0;

#if defined(PROCESS_TRAITS) && 0 // ����������
  // ���õ�ǰ������ɫ
  // ��Ҫ���� ColorMethod��ʶ��ǰ��ɫ������ɫ������ɫ(pPalette[index])�����ɫ
  virtual void setDrawColor(const OdCmEntityColor& color) = 0;
  // ���õ�ǰ������ɫ(RGB)
  virtual void setDrawColor(COLORREF color) = 0;
  
  // �����߿� (����ֵ)
  virtual void setLineWeight(OdDb::LineWeight weight) = 0;

  // ���ģʽ (�Ƿ����)
  virtual void setFillMode(OdGiFillType fillMode) = 0;

  // ����ʵ���ӡ��ʽ����(Null => default plot style(normal))
  virtual void setPlotStyleName(const OdDbObjectId& plotStyleNameId = GcDbObjectId::kNull) = 0;
#endif

  virtual void onTraitsChanged(const OdGiSubEntityTraitsData& currTraits) = 0;
  virtual void onSwitchPlotStyleTranslation(bool bTrans) = 0;

public:
  //virtual void pushViewportClip(const OdGsDCPoint* points, const int *pointCounts, int numPolygons);
  //virtual void pushViewportClip(const OdGsDCPoint& min, const OdGsDCPoint& max);
  //virtual void popViewportClip();

public: // ����ͼԪ���

  virtual void polylineOut(OdInt32 numPoints, 
    const OdGePoint3d* vertexList) = 0;

  virtual void polygonOut(OdInt32 numPoints, 
    const OdGePoint3d* vertexList, 
    const OdGeVector3d* pNormal = 0) = 0;

  // ��չ�ӿ�
  virtual PlotGenResult polylineOut(OdInt32 numPoints, 
    const OdInt32* vertexIndexList,
    const OdGePoint3d* vertexList) = 0;

  virtual PlotGenResult triangleOut(const OdInt32* vertices,
    const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0) = 0;

public: // ��ͨͼԪ

  virtual PlotGenResult polylineProc(OdInt32 numPoints, 
    const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0,
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult polygonProc(OdInt32 nbPoints, 
    const OdGePoint3d* pVertexList,
    const OdGeVector3d* pNormal = 0,
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult circleProc(const OdGePoint3d& center, 
    double radius, 
    const OdGeVector3d& normal, 
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult circleProc(const OdGePoint3d& firstPoint, 
    const OdGePoint3d& secondPoint, 
    const OdGePoint3d& thirdPoint, 
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult circularArcProc(const OdGePoint3d& center,
    double radius,
    const OdGeVector3d& normal,
    const OdGeVector3d& startVector,
    double sweepAngle,
    OdGiArcType arcType = kOdGiArcSimple, 
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult circularArcProc(const OdGePoint3d& firstPoint,
    const OdGePoint3d& secondPoint,
    const OdGePoint3d& thirdPoint,
    OdGiArcType arcType = kOdGiArcSimple, 
    const OdGeVector3d* pExtrusion = 0) = 0;

  // return eContinueSimplification: convert to polylineOut polygonOut
  virtual PlotGenResult ellipArcProc(const OdGeEllipArc3d& ellipArc,
    const OdGePoint3d* endPointsOverrides,
    OdGiArcType arcType = kOdGiArcSimple, 
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult nurbsProc(const OdGeNurbCurve3d& nurbs) = 0;

  virtual PlotGenResult xlineProc(const OdGePoint3d& firstPoint, 
    const OdGePoint3d& secondPoint) = 0;

  virtual PlotGenResult rayProc(const OdGePoint3d& basePoint,
    const OdGePoint3d& throughPoint) = 0;

  // new
  virtual PlotGenResult polyPointsProc(OdUInt32 numPoints,
    const OdGePoint3d* vertexList) = 0;

  virtual PlotGenResult plineConstWidthProc(OdUInt32 numPoints, 
    const OdGePoint3d* vertexList,
    double consWidth,
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult meshProc(OdInt32 rows,
    OdInt32 columns,
    const OdGePoint3d* pVertexList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0) = 0;

  virtual PlotGenResult shellProc(OdInt32 numVertices,
    const OdGePoint3d* vertexList,
    OdInt32 faceListSize,
    const OdInt32* faceList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0) = 0;

  // 2 font text(SHX, TTF), test pTextStyle->isShxFont()
  // SHX: return eContinueSimplification
  // TTF: return eContinueSimplification, then try-output by follow order
  //      ttfTextProc(GDI����), ttfPolyDrawProc(��������), shellProc(�����ʷ�)
  virtual PlotGenResult textProc(const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    const OdChar* msg, 
    OdInt32 length, 
    bool raw, 
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion = 0) = 0;

  // GDI text: ExtTextOut(...)
  // return eContinueSimplification: continue try ttfPolyDrawProc()
  virtual PlotGenResult ttfTextProc(const OdGePoint3d& base,
    const OdGeVector3d& u, // direction
    const OdGeVector3d& v,
    double width, // width of all chars
    double height,
    const LOGFONT& lf, // to recompute lfHeight by height, lfEscapement&lfOrientation by u
    const OdChar* text,
    OdInt32 length, 
    const double* pCellX) = 0;

  // GDI contour: BeginPath EndPath FillPath
  // return eContinueSimplification: continue try shellProc()
  virtual PlotGenResult ttfPolyDrawProc(OdInt32 nbVertex, 
    const OdGePoint3d* pVertexList,
    OdInt32 faceListSize, 
    const OdInt32* pFaceList,
    const OdUInt8* pBezierTypes, 
    const OdGiFaceData* pFaceData = 0) = 0;

  // SHAPE: MUST return eContinueSimplification
  virtual PlotGenResult shapeProc(const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    int shapeNumber, 
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion = 0) = 0;

  // all images, or converted from OLE, EMF, GradientFill, shade output(3d)
  // return eContinueSimplification: discarded
  virtual PlotGenResult rasterImageProc(const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiRasterImage* pImage,
    const OdGePoint2d* uvBoundary, // may not be null
    OdUInt32 numBoundPts,
    bool transparency = false,
    double brightness = 50.0,
    double contrast = 50.0,
    double fade = 0.0) = 0;

  // EMF(WMF)
  // return eContinueSimplification: convert to raster image
  virtual PlotGenResult metafileDc(const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiMetafile* pMetafile,
    bool dcAligned = true,
    bool allowClipping = false) = 0;

  // OLE, or other OdGiSelfGdiDrawable(such as GradientFill, EMF, ...)
  // return eContinueSimplification: convert to raster image
  virtual PlotGenResult ownerDrawDc(const OdGiCommonDraw& toDraw,
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiSelfGdiDrawable* pDrawable,
    bool dcAligned = true,
    bool allowClipping = false) = 0;

  // GradientFill
  // return eContinueSimplification: convert to raster image
  virtual PlotGenResult gradientFillProc(OdInt32 nVertex,
    const OdGePoint3d* pVertexes,  // size==nVertex
    const OdCmEntityColor* pVertexColors,  // size==nVertex
    OdInt32 nTriangle,
    const OdInt32* pTriangles) = 0; //size==nTriangle*3
};

// ��ӡ����������
class GcPlotProgressMeter
{
public:
  virtual void start() = 0;

  virtual void stop() = 0;

  virtual void step(int nAdvance = 1) = 0;

  virtual void setLimit(int max) = 0;
};

#endif //__GCAD__PLOT_DUMPPER__INTERFACE__H__

