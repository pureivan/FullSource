#ifndef KINGSOFT_UNITTEST_ICLASSUNITTEST_H
#define KINGSOFT_UINITEST_ICLASSUNITTEST_H

/***************************************************
Filename:KingsoftUnitTest.H
CreatedBy: WilsonWei
CreatedOn: 2005��7��29�� 14:21:34.6882784
Description:
�������ר��Ϊ��Ԫ���Է����,���ڲ�����"��"Ϊ��С��λ
���е�Ԫ���Եķ���.��ĳ�Ա���ݱ����ķ����Ƿǳ�Ƶ����
�����.���ÿ����Ĳ��Ժ������Ա�����������ݳ�Ա����
�������ﵽ���ݱȽϵ�Ŀ��,����ȱ©,��Ϊ���ǲ����ܱ�֤
һ����ķ��������޸ĵ������������ݳ�Ա.�������ǲ�����
���ݳ�Աȫƥ��/�Ƚϵķ���.���ڽ���һ������(����)֮ǰ,
�ȰѸ�������б�Ҫ�ĳ�Ա��������һ������,���������(����)
֮��,�ٱ���һ������,�������θ�������ȫ�Ƚ�,���Դﵽ��
���Ŀ��.

����ΪʲôҪʹ���������,���Բ���������������۸�:
http://192.168.27.31/qcweb/pmwiki.php?n=XSJQC.XSJ-QC-SPEC-UnitTestWorkflow

**************************************************/


namespace KingsoftUnitTest
{
    // -------------------------------------------------------------------------
	// ����		: ���������ʹ�õĲ��Խӿ�
	// ��ע		: 
	// -------------------------------------------------------------------------
    #ifdef _UNIT_TEST
    #define EXPORT_TEST(classname) friend class classname##_Test
    #else // #ifdef _UNIT_TEST
    #define EXPORT_TEST(classname)
    #endif
	
	// -------------------------------------------------------------------------
	// ��		: _UT_CLS_HEAD_BEGIN
	// ����		: �����д�ڲ������ͷ�ļ���ͷ��
	// ��ע		: 
	// -------------------------------------------------------------------------
	#define _UT_CLS_HEAD_INCLUDE()						    					\
			#include "cppunit/extensions/HelperMacros.h" 	    				\
			#include "cppunit/TestFixture.h" 									\
			#include "KSUnitTest/ClassDataCopyBuffer.H"
	
	// -------------------------------------------------------------------------
	// ��		: _UT_CLS_HEAD_END
	// ����		: �����д�ڲ�����Ĵ����ļ��Ŀ�ͷ��
	// ��ע		: 
	// -------------------------------------------------------------------------
	#define _UT_CLS_IMP_NEEDED(ClassName) 										\
		CPPUNIT_TEST_SUITE_REGISTRATION(ClassName##_Test);
				
	//-------------------------------------------------------------------------
    /*��������ݳ�Ա,��Щ���ݳ�Ա��������"ȫ�Ƚ�"��,һ���Ӧ��
    //������������ݳ�Ա(�����෽��).
    */
    struct _TestData;
	/*
	�������Ա���ݲ��ԵĽӿ�
	*/
	class IClassUnitTest
	{
	public:
  		/*������ڴ�������Ƶ���һ�ݿ���(_TestData��)*/
		virtual void DummyClassForFirstCopy(void* pvClassBeingTest)     = 0;
        /*������ڴ�������Ƶ��ڶ��ݿ���(_TestData��)*/
        virtual void DummyClassForSecondCopy(void* pvClassBeingTest)    = 0;
		/*������ڴ�������浽ָ�����ļ�*/
		virtual void DummyClassToFile( LPCSTR szFilename)               = 0;
        /*�Ƚ����ݿ���,��ָ���ڱȽ����֮��,�Ƿ��Զ��ͷ��ڴ����ݿ���*/
        virtual void CompareCopy(bool bAutoReleaseCopy)                 = 0;
	};
}

#endif