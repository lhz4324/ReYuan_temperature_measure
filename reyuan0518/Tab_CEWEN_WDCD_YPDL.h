#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// Tab_CEWEN_WDCD_YPDL 对话框

class Tab_CEWEN_WDCD_YPDL : public CDialogEx
{
	DECLARE_DYNAMIC(Tab_CEWEN_WDCD_YPDL)

public:
	Tab_CEWEN_WDCD_YPDL(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Tab_CEWEN_WDCD_YPDL();

// 对话框数据
	enum { IDD = IDD_CEWEN_WDCD_YPDL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl YPDL_list_control;
	virtual BOOL OnInitDialog();

	int m_listSelPos;//获取选中的当前行


	// 供试品名称下拉框
	CComboBox GSPMC_comboxcontrol;

	CEdit YPDL_ph_control;
	CEdit YPDL_yptgdw_control;
	CEdit YPDL_ypbh_control;

	CString YPDL_ph_CString;
	CString YPDL_yptgdw_CString;
	CString YPDL_ypbh_CString;

	CEdit YPDL_GG_control;
	CEdit YPDL_JL_control;
	CString YPDL_GG_CString;
	CString YPDL_JL_CString;

	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnCbnSelchangeCombo2();

	CEdit* NewMyEdit(int nID, CRect rect, int nStyle);	
	CStatic* NewMyText(int nID, CRect rect, int nStyle);
	CStatic *p_Mytext[10];
	CEdit *p_Myedit[10];

	CString YPDL_GSPMC_CString;
	CString YPDL_SYFF_CString;
	CComboBox SYFF_comboxcontrol;
};
