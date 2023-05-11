#pragma once
#include "MyDatabase.h"

// SYPC_XZGSP 对话框

class SYPC_XZGSP : public CDialogEx
{
	DECLARE_DYNAMIC(SYPC_XZGSP)

public:
	SYPC_XZGSP(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SYPC_XZGSP();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SYPC_XZGSP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl LISTCTRL_XZGSP;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	int m_listSelPos;
};
