#pragma once
#include "afxcmn.h"


// SET_JLGS_RY �Ի���

class SET_JLGS_RY : public CDialogEx
{
	DECLARE_DYNAMIC(SET_JLGS_RY)

public:
	SET_JLGS_RY(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SET_JLGS_RY();

// �Ի�������
	enum { IDD = IDD_SET_JLGS_RY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked1002();
	afx_msg void OnBnClicked1003();
	CListCtrl RY_list_control;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);

	int m_listSelPos;//��ȡѡ�еĵ�ǰ��
};
