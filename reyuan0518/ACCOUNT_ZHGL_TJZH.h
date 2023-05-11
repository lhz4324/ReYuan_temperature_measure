#pragma once


// ACCOUNT_ZHGL_TJZH 对话框

class ACCOUNT_ZHGL_TJZH : public CDialogEx
{
	DECLARE_DYNAMIC(ACCOUNT_ZHGL_TJZH)

public:
	ACCOUNT_ZHGL_TJZH(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ACCOUNT_ZHGL_TJZH();

// 对话框数据
	enum { IDD = IDD_ACCOUNT_ZHGL_TJZH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString ACCOUNT_ZHGL_TJZH_username;
	CString ACCOUNT_ZHGL_TJZH_password;
	CString ACCOUNT_ZHGL_TJZH_juese;
	CString ACCOUNT_ZHGL_TJZH_quanxian;
	virtual BOOL OnInitDialog();
	 
	afx_msg void OnBnClickedCheck1();
	BOOL m_ccdlggmm;
};
