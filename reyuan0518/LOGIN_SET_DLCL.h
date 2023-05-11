#pragma once


// LOGIN_SET_DLCL 对话框

class LOGIN_SET_DLCL : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN_SET_DLCL)

public:
	LOGIN_SET_DLCL(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LOGIN_SET_DLCL();

// 对话框数据
	enum { IDD = IDD_LOGIN_SET_DLCL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
