#pragma once
#include "afxcmn.h"


// LOGIN_SET_CJZH �Ի���

class LOGIN_SET_CJZH : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN_SET_CJZH)

public:
	LOGIN_SET_CJZH(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LOGIN_SET_CJZH();

// �Ի�������
	enum { IDD = IDD_LOGIN_SET_CJZH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CListCtrl mlist_control;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	int m_listSelPos;//��ȡѡ�еĵ�ǰ��
};
