#pragma once
#include "afxcmn.h"


// LOGIN_SET_CJZH 对话框

class LOGIN_SET_CJZH : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN_SET_CJZH)

public:
	LOGIN_SET_CJZH(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LOGIN_SET_CJZH();

// 对话框数据
	enum { IDD = IDD_LOGIN_SET_CJZH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CListCtrl mlist_control;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	int m_listSelPos;//获取选中的当前行
};
