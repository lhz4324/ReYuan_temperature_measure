#pragma once
#include "afxcmn.h"
#include "afxwin.h"

#include "./listbutton/ListCtrlCl.h"

#include "./CyAPI.h"//导入头文件，
#pragma comment(lib,"./CyAPI.lib")//指定路径，导入静态链接库

// Tab_CEWEN_WDCD_SYPC 对话框

class Tab_CEWEN_WDCD_SYPC : public CDialogEx
{
	DECLARE_DYNAMIC(Tab_CEWEN_WDCD_SYPC)

public:
	Tab_CEWEN_WDCD_SYPC(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Tab_CEWEN_WDCD_SYPC();

// 对话框数据
	enum { IDD = IDD_CEWEN_WDCD_SYPC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	int m_listSelPos;//获取选中的当前行

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();

	CString TTH_cstring;
	CEdit TTH_control;
	CComboBox SYFF_combobox_control;
	CString TH_cstring;
	CString TZ_cstring;
	CEdit TH_control;
	CEdit TZ_control;
	afx_msg void OnBnClickedButton4();
	CString SYFF_cstring;


	CButton *p_MyBut[128];



	afx_msg void OnSize(UINT nType, int cx, int cy);
	

	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
	afx_msg void OnKillFocus(CWnd* pNewWnd);

	CListCtrlCl m_ListCtrl;
	

	afx_msg LRESULT OnListCtrlButtonClicked(WPARAM wParam, LPARAM lParam);
	afx_msg void OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult);


	CCyUSBDevice *mCCyUsbDevice;
	CCyUSBEndPoint *OutEndpt;
	CCyUSBEndPoint *InEndpt;

	bool bLooping;
	CWinThread *XferThread;//线程




	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox GSPMC_comboxcontrol;

	afx_msg void OnBnClickedButton5();
	virtual void PostNcDestroy();




	afx_msg LRESULT OnChlidFrameDBClick(WPARAM wParam, LPARAM lParam);//两窗口间消息传递
};
