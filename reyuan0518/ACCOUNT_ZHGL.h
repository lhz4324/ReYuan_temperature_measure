#pragma once


// ACCOUNT_ZHGL �Ի���

class ACCOUNT_ZHGL : public CDialogEx
{
	DECLARE_DYNAMIC(ACCOUNT_ZHGL)

public:
	ACCOUNT_ZHGL(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ACCOUNT_ZHGL();

// �Ի�������
	enum { IDD = IDD_ACCOUNT_ZHGL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked1002();
	afx_msg void OnBnClicked1003();
};
