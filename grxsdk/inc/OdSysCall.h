///////////////////////////////////////////////////////////////////////////////
// TODO
// 
// ���ļ��������� "OdaCommon.h" ����
// 
///////////////////////////////////////////////////////////////////////////////


#ifndef _OD_SYSTEM_INTERNAL_CALL_H_INCLUDED_
#define _OD_SYSTEM_INTERNAL_CALL_H_INCLUDED_

// �����Ƿ�ʹ���ڲ�����
#define USE_SYSTEM_INTERNAL_CALL


#ifdef  USE_SYSTEM_INTERNAL_CALL

// ע�⣺�����ڲ�������������ʹ�� OdSystemInteral
class OdSystemInternal;
#define ODGETSYSCALLER  (*(OdSystemInternal*)0)

#define ODMAKEPARAM0()  ODGETSYSCALLER
#define ODMAKEPARAM(p)  ODGETSYSCALLER,(p)

#else

#define ODMAKEPARAM0()  
#define ODMAKEPARAM(p)  (p)

#endif //USE_SYSTEM_INTERNAL_CALL


#define ODSYSDEF     const OdSystemInternal&
#define ODSYSNAME    si
#define ODSYSDEFNAME ODSYSDEF ODSYSNAME

#define ODARXDEF

#define ODSYSCALL0(FN)                  FN(ODMAKEPARAM0())
#define ODSYSCALL1(FN, p1)              FN(ODMAKEPARAM(p1))
#define ODSYSCALL2(FN, p1, p2)          FN(ODMAKEPARAM(p1), (p2))
#define ODSYSCALL3(FN, p1, p2, p3)      FN(ODMAKEPARAM(p1), (p2), (p3))
#define ODSYSCALL4(FN, p1, p2, p3, p4)  FN(ODMAKEPARAM(p1), (p2), (p3), (p4))

#define ODSYSCALL5(FN, p1, p2, p3, p4, p5) \
        FN(ODMAKEPARAM(p1), (p2), (p3), (p4), (p5))

#define ODSYSCALL6(FN, p1, p2, p3, p4, p5, p6) \
        FN(ODMAKEPARAM(p1), (p2), (p3), (p4), (p5), (p6))

#define ODSYSCALL7(FN, p1, p2, p3, p4, p5, p6, p7) \
        FN(ODMAKEPARAM(p1), (p2), (p3), (p4), (p5), (p6), (p7))

#define ODSYSCALL8(FN, p1, p2, p3, p4, p5, p6, p7, p8) \
        FN(ODMAKEPARAM(p1), (p2), (p3), (p4), (p5), (p6), (p7), (p8))

#define ODSYSCALL9(FN, p1, p2, p3, p4, p5, p6, p7, p8, p9) \
        FN(ODMAKEPARAM(p1), (p2), (p3), (p4), (p5), (p6), (p7), (p8), (p9))

// ���ṩ�ɱ������ ODSYSCALL (�ο�TRACE, TRACE0, ...)


// ʹ�÷���(ע��: ODSYSCALLx Ҫ���ݲ�������ѡ��)
// fo()         ->  ODSYSCALL0(fo)            -> fo ( == ODSYSCALL0(fo
// foa(p)       ->  ODSYSCALL1(foa, p)        -> foa( == ODSYSCALL1(foa, 
// fob(p, t, x) ->  ODSYSCALL3(fob, p, t, x)  -> fob( == ODSYSCALL3(fob, 


/************************ Gcad(Code) - �쳣ת����ֵ**********************************/

#ifndef OD_ERR_RESULT

  #define OD_ERR_RESULT  od_internal_error_result

  // �쳣ת����ֵ-��ʼ(I=init, ָ��Ҫָ�������ʼֵ)
  #define OD_TRY_I(def)  OdResult OD_ERR_RESULT = def; try {

  // �쳣ת����ֵ-����(I=set to Init, ָ���ô���ֵ����ʼ������)
  #define OD_CATCH_I()   } catch(OdError& oderr) { OD_ERR_RESULT = oderr.code(); }


  // �쳣ת����ֵ-��ʼ(0=�մ���, ����������ͬһ�﷨��Χ�ڲ�����һ���쳣)
  #define OD_TRY_0()     try {

  // �쳣ת����ֵ-����(0=�մ���, �쳣����󲻴���)
  #define OD_CATCH_0()   } catch(OdError&) { }


  // �쳣ת����ֵ-��ʼ(���ó�ʼֵΪ eOk, Ĭ��)
  #define OD_TRY()       OD_TRY_I(Oda::eOk)

  // �쳣ת����ֵ-����(���� OD_ERR_RESULT, Ĭ��)
  #define OD_CATCH()     OD_CATCH_I() return OD_ERR_RESULT;


  // �쳣ת����ֵ(N=No return, ָû�з���)
  #ifdef _DEBUG

    #define OD_TRY_N()   OD_TRY_I(Oda::eOk)
    #define OD_CATCH_N() OD_CATCH_I()

  #else

    #define OD_TRY_N()   OD_TRY_0()
    #define OD_CATCH_N() OD_CATCH_0()

  #endif

#endif //OD_ERR_RESULT

/************************ Gcad(Code) - �쳣ת����ֵ**********************************/


#endif // _OD_SYSTEM_INTERNAL_CALL_H_INCLUDED_

