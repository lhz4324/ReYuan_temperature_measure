#pragma once
#include "afxcmn.h"

#include"LOGIN_SET_ZDBF.h"
#include"LOGIN_SET_TTSZ.h"
#include"LOGIN_SET_DLCL.h"
#include"LOGIN_SET_CJZH.h"

// LOGIN_SET 对话框

class LOGIN_SET : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN_SET)

public:
	LOGIN_SET(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LOGIN_SET();

// 对话框数据
	enum { IDD = IDD_LOGIN_SET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	//tab的四个子菜单

	LOGIN_SET_TTSZ* cTabDlg1;
	LOGIN_SET_DLCL* cTabDlg2;
	LOGIN_SET_ZDBF* cTabDlg3;
	LOGIN_SET_CJZH* cTabDlg4;

	CTabCtrl r_tab1;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
