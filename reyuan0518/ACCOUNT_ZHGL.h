#pragma once


// ACCOUNT_ZHGL 对话框

class ACCOUNT_ZHGL : public CDialogEx
{
	DECLARE_DYNAMIC(ACCOUNT_ZHGL)

public:
	ACCOUNT_ZHGL(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ACCOUNT_ZHGL();

// 对话框数据
	enum { IDD = IDD_ACCOUNT_ZHGL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked1002();
	afx_msg void OnBnClicked1003();
};
