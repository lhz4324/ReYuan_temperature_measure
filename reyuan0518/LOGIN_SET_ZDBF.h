#pragma once


// LOGIN_SET_ZDBF 对话框

class LOGIN_SET_ZDBF : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN_SET_ZDBF)

public:
	LOGIN_SET_ZDBF(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LOGIN_SET_ZDBF();

// 对话框数据
	enum { IDD = IDD_LOGIN_SET_ZDBF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
