#pragma once
#include "afxwin.h"


// SET_SJGS �Ի���

class SET_SJGS : public CDialogEx
{
	DECLARE_DYNAMIC(SET_SJGS)

public:
	SET_SJGS(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SET_SJGS();

// �Ի�������
	enum { IDD = IDD_SET_SJGS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox TZ_duiyingcombo_control;
	CComboBox JL_duiyingcombo_control;
	CComboBox WD_duiyingcombo_control;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClicked1003();
	afx_msg void OnBnClicked1002();
	CString tz_geshi_cstring;
	CString jl_geshi_cstring;
	CString wd_geshi_cstring;
};
