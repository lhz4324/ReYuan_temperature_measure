#pragma once


// ACCOUNT_ZHGL_TJZH �Ի���

class ACCOUNT_ZHGL_TJZH : public CDialogEx
{
	DECLARE_DYNAMIC(ACCOUNT_ZHGL_TJZH)

public:
	ACCOUNT_ZHGL_TJZH(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ACCOUNT_ZHGL_TJZH();

// �Ի�������
	enum { IDD = IDD_ACCOUNT_ZHGL_TJZH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
