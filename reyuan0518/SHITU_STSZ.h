#pragma once


// SHITU_STSZ 对话框

class SHITU_STSZ : public CDialogEx
{
	DECLARE_DYNAMIC(SHITU_STSZ)

public:
	SHITU_STSZ(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SHITU_STSZ();

// 对话框数据
	enum { IDD = IDD_SHITU_STSZ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
