#pragma once


// SET_JLGS_XT �Ի���

class SET_JLGS_XT : public CDialogEx
{
	DECLARE_DYNAMIC(SET_JLGS_XT)

public:
	SET_JLGS_XT(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SET_JLGS_XT();

// �Ի�������
	enum { IDD = IDD_SET_JLGS_XT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
