#pragma once
#include "afxcmn.h"


// LOGIN_SET_TTSZ �Ի���

class LOGIN_SET_TTSZ : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN_SET_TTSZ)

public:
	LOGIN_SET_TTSZ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LOGIN_SET_TTSZ();

// �Ի�������
	enum { IDD = IDD_LOGIN_SET_TTSZ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	CSpinButtonCtrl m_Spin;
	CString m_Edit1;
};
