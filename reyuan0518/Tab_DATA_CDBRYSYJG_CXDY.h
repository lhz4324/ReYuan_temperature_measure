#pragma once


// Tab_DATA_CDBRYSYJG_CXDY �Ի���

class Tab_DATA_CDBRYSYJG_CXDY : public CDialogEx
{
	DECLARE_DYNAMIC(Tab_DATA_CDBRYSYJG_CXDY)

public:
	Tab_DATA_CDBRYSYJG_CXDY(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Tab_DATA_CDBRYSYJG_CXDY();

// �Ի�������
	enum { IDD = IDD_DATA_CDBRYSYJG_CXDY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
