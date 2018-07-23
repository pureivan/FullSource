// -------------------------------------------------------------------------
//	�ļ���		��	����ȷ�Ͽ�
//	������		��	Wooy(Wu yue)
//	����ʱ��	��	2003-5-28
// -------------------------------------------------------------------------
#ifndef __UiTradeConfirm_H__
#define __UiTradeConfirm_H__

#include "../Elem/WndButton.h"
#include "../Elem/WndText.h"
#include "../Elem/wndedit.h"
#include "../../../core/src/gamedatadef.h"

enum TRADE_CONFIRM_ACTION
{
	TCA_BUY,
	TCA_SALE,
	TCA_REPAIR,
};

class KUiTradeConfirm : protected KWndImage
{
public:
	//----�������ͳһ�Ľӿں���----
	static KUiTradeConfirm*	OpenWindow(KUiObjAtContRegion* pObj,
			KUiItemBuySelInfo* pPriceInfo, TRADE_CONFIRM_ACTION eAction);	//�򿪴��ڣ�����Ψһ��һ�������ʵ��
	static KUiTradeConfirm*	GetIfVisible();				//�������������ʾ���򷵻�ʵ��ָ��
	static void			CloseWindow(bool bDestroy);		//�رմ���
private:
	KUiTradeConfirm();
	~KUiTradeConfirm() {}
	int		Initialize();								//��ʼ��
	void	Show();
	void	Hide();
	void	LoadScheme(const char* pScheme);			//������淽��
	int		WndProc(unsigned int uMsg, unsigned int uParam, int nParam);
	void	OnCancel();
	void	OnBuy();
	void	OnSale();
	void	OnRepair();
	void	OnModifyCount(bool bAdd);
	void	OnCountInputChanged();
private:
	static KUiTradeConfirm*	m_pSelf;
	KWndText32			m_ItemName;
	KWndText32			m_Money;
	KWndEdit32          m_BuyCount;
	KWndImage			m_BuyImg, m_SaleImg, m_RepairImg;
	KWndButton			m_OkBtn;
	KWndButton			m_CancelBtn;
	KWndButton          m_BtnIncrease, m_BtnDecrease;   //���Ӻͼ��ٵ�Hold�Ͱ�ť
	KUiObjAtContRegion	m_ItemInfo;
	KUiItemBuySelInfo	m_PriceInfo;
	unsigned int		m_uNormalPriceColor;
	unsigned int		m_uNotEnoughMoneyPriceColor;
};


#endif // __UiTradeConfirm_H__