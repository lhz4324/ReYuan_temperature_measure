#pragma once


// SET_JLGS_JT �Ի���

class SET_JLGS_JT : public CDialogEx
{
	DECLARE_DYNAMIC(SET_JLGS_JT)

public:
	SET_JLGS_JT(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SET_JLGS_JT();

// �Ի�������
	enum { IDD = IDD_SET_JLGS_JT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
