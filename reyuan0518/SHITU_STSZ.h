#pragma once


// SHITU_STSZ �Ի���

class SHITU_STSZ : public CDialogEx
{
	DECLARE_DYNAMIC(SHITU_STSZ)

public:
	SHITU_STSZ(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SHITU_STSZ();

// �Ի�������
	enum { IDD = IDD_SHITU_STSZ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
