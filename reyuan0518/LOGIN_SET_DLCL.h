#pragma once


// LOGIN_SET_DLCL �Ի���

class LOGIN_SET_DLCL : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN_SET_DLCL)

public:
	LOGIN_SET_DLCL(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LOGIN_SET_DLCL();

// �Ի�������
	enum { IDD = IDD_LOGIN_SET_DLCL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
