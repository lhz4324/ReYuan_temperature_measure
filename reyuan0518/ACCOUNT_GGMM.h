#pragma once


// ACCOUNT_GGMM 对话框

class ACCOUNT_GGMM : public CDialogEx
{
	DECLARE_DYNAMIC(ACCOUNT_GGMM)

public:
	ACCOUNT_GGMM(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ACCOUNT_GGMM();

// 对话框数据
	enum { IDD = IDD_ACCOUNT_GGMM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked1002();
	virtual BOOL OnInitDialog();
	CString STATIC_username_now;//显示当前用户名到静态文本框
	CString current_password;//接收当前密码
	CString new_password;//接收新密码
	CString new_password_again;//接收第二次的新密码
	
};
