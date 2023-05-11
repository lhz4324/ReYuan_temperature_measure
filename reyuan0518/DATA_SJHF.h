#pragma once
#include "afxwin.h"


// DATA_SJHF 对话框

class DATA_SJHF : public CDialogEx
{
	DECLARE_DYNAMIC(DATA_SJHF)

public:
	DATA_SJHF(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DATA_SJHF();

// 对话框数据
	enum { IDD = IDD_DATA_SJHF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit SJHF_ml_control;
	afx_msg void OnBnClickedButton2();
};
