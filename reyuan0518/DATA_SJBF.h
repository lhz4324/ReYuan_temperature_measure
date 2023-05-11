#pragma once
#include "afxwin.h"


// DATA_SJBF 对话框

class DATA_SJBF : public CDialogEx
{
	DECLARE_DYNAMIC(DATA_SJBF)

public:
	DATA_SJBF(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DATA_SJBF();

// 对话框数据
	enum { IDD = IDD_DATA_SJBF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CEdit SJBF_ml_control;
	CString SJBF_ml_cstring;
};
