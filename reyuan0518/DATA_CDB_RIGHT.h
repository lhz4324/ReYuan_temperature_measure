#pragma once


// DATA_CDB_RIGHT �Ի���

class DATA_CDB_RIGHT : public CDialogEx
{
	DECLARE_DYNAMIC(DATA_CDB_RIGHT)

public:
	DATA_CDB_RIGHT(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DATA_CDB_RIGHT();

// �Ի�������
	enum { IDD = IDD_FV_DATA_CDB_RIGHT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
