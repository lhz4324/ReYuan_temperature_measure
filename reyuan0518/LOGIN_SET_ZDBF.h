#pragma once


// LOGIN_SET_ZDBF �Ի���

class LOGIN_SET_ZDBF : public CDialogEx
{
	DECLARE_DYNAMIC(LOGIN_SET_ZDBF)

public:
	LOGIN_SET_ZDBF(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LOGIN_SET_ZDBF();

// �Ի�������
	enum { IDD = IDD_LOGIN_SET_ZDBF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
