#pragma once


// ACCOUNT_GGMM �Ի���

class ACCOUNT_GGMM : public CDialogEx
{
	DECLARE_DYNAMIC(ACCOUNT_GGMM)

public:
	ACCOUNT_GGMM(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ACCOUNT_GGMM();

// �Ի�������
	enum { IDD = IDD_ACCOUNT_GGMM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked1002();
	virtual BOOL OnInitDialog();
	CString STATIC_username_now;//��ʾ��ǰ�û�������̬�ı���
	CString current_password;//���յ�ǰ����
	CString new_password;//����������
	CString new_password_again;//���յڶ��ε�������
	
};
