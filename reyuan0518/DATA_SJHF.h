#pragma once
#include "afxwin.h"


// DATA_SJHF �Ի���

class DATA_SJHF : public CDialogEx
{
	DECLARE_DYNAMIC(DATA_SJHF)

public:
	DATA_SJHF(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DATA_SJHF();

// �Ի�������
	enum { IDD = IDD_DATA_SJHF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit SJHF_ml_control;
	afx_msg void OnBnClickedButton2();
};
