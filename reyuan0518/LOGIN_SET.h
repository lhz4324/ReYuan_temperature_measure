#pragma once
#include "afxcmn.h"

#include"LOGIN_SET_ZDBF.h"
#include"LOGIN_SET_TTSZ.h"
#include"LOGIN_SET_DLCL.h"
#include"LOGIN_SET_CJZH.h"

// LOGIN_SET �Ի���

class LOGIN_SET : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN_SET)

public:
	LOGIN_SET(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LOGIN_SET();

// �Ի�������
	enum { IDD = IDD_LOGIN_SET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	//tab���ĸ��Ӳ˵�

	LOGIN_SET_TTSZ* cTabDlg1;
	LOGIN_SET_DLCL* cTabDlg2;
	LOGIN_SET_ZDBF* cTabDlg3;
	LOGIN_SET_CJZH* cTabDlg4;

	CTabCtrl r_tab1;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
