#pragma once
#include "afxwin.h"


// DATA_SJBF �Ի���

class DATA_SJBF : public CDialogEx
{
	DECLARE_DYNAMIC(DATA_SJBF)

public:
	DATA_SJBF(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DATA_SJBF();

// �Ի�������
	enum { IDD = IDD_DATA_SJBF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CEdit SJBF_ml_control;
	CString SJBF_ml_cstring;
};
