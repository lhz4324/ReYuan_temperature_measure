#pragma once

#include "Quanjv.h"
//#include "instrument_self_check.h"

// LOGIN �Ի���

class LOGIN : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN)

public:
	LOGIN(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LOGIN();

// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString username;
	CString password;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBnClickedButton2();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

};
