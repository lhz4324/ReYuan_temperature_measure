#pragma once


// Tab_DATA_CDBRYSYJG_BZ �Ի���

class Tab_DATA_CDBRYSYJG_BZ : public CDialogEx
{
	DECLARE_DYNAMIC(Tab_DATA_CDBRYSYJG_BZ)

public:
	Tab_DATA_CDBRYSYJG_BZ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Tab_DATA_CDBRYSYJG_BZ();

// �Ի�������
	enum { IDD = IDD_DATA_CDBRYSYJG_BZ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
