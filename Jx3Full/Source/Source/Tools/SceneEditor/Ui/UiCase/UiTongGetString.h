// -------------------------------------------------------------------------
//	�ļ���		��	UiTongGetString.h
//	������		��	Wooy(Wu yue)
//	����ʱ��	��	2003-3-18
//	��������	��	����ִ�����
// -------------------------------------------------------------------------
#ifndef __UiTongGetString_H__
#define __UiTongGetString_H__

#include "../Elem/WndButton.h"
#include "../Elem/WndEdit.h"


class KUiTongGetString : protected KWndImage
{
public:
	//----�������ͳһ�Ľӿں���----
	static KUiTongGetString*	OpenWindow(const char* pszTitle,
				const char* pszInitString,				
				KWndWindow* pRequester, unsigned int uParam,
				int nMinLen = 4, int nMaxLen = 16);	//�򿪴��ڣ�����Ψһ��һ�������ʵ��
	static KUiTongGetString*	GetIfVisible();
	static void			LoadScheme(const char* pScheme);	//������淽��
	static void			CloseWindow(bool bDestroy);		//�رմ���
private:
	KUiTongGetString();
	~KUiTongGetString() {}
	void	Initialize();								//��ʼ��
	void	Show();
	void	Hide();
	int		WndProc(unsigned int uMsg, unsigned int uParam, int nParam);
	void	OnCancel();
	void	OnOk();
private:
	static KUiTongGetString*	m_pSelf;
	KWndText32			m_Title;
	short				m_nMinLen, m_nMaxLen;
	KWndText32			m_StringEdit;
	KWndButton			m_OkBtn;
	KWndButton			m_CancelBtn;
	KWndWindow*			m_pRequester;
	unsigned int		m_uRequesterParam;
};


#endif // __UiTongGetString_H__