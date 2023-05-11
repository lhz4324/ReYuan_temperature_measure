#pragma once


// Tab_DATA_CDBRYSYJG_CXDY 对话框

class Tab_DATA_CDBRYSYJG_CXDY : public CDialogEx
{
	DECLARE_DYNAMIC(Tab_DATA_CDBRYSYJG_CXDY)

public:
	Tab_DATA_CDBRYSYJG_CXDY(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Tab_DATA_CDBRYSYJG_CXDY();

// 对话框数据
	enum { IDD = IDD_DATA_CDBRYSYJG_CXDY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
