#pragma once
#include "afxwin.h"


// ACCOUNT_ZHGL_XGZH �Ի���

class ACCOUNT_ZHGL_XGZH : public CDialogEx
{
	DECLARE_DYNAMIC(ACCOUNT_ZHGL_XGZH)

public:
	ACCOUNT_ZHGL_XGZH(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ACCOUNT_ZHGL_XGZH();

// �Ի�������
	enum { IDD = IDD_ACCOUNT_ZHGL_XGZH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();

	CString ACCOUNT_ZHGL_XGZH_juese;
	CString ACCOUNT_ZHGL_XGZH_password;
};
