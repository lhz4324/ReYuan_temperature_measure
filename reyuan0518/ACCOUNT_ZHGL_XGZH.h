#pragma once
#include "afxwin.h"


// ACCOUNT_ZHGL_XGZH 对话框

class ACCOUNT_ZHGL_XGZH : public CDialogEx
{
	DECLARE_DYNAMIC(ACCOUNT_ZHGL_XGZH)

public:
	ACCOUNT_ZHGL_XGZH(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ACCOUNT_ZHGL_XGZH();

// 对话框数据
	enum { IDD = IDD_ACCOUNT_ZHGL_XGZH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();

	CString ACCOUNT_ZHGL_XGZH_juese;
	CString ACCOUNT_ZHGL_XGZH_password;
};
