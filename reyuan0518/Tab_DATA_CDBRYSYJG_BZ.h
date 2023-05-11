#pragma once


// Tab_DATA_CDBRYSYJG_BZ 对话框

class Tab_DATA_CDBRYSYJG_BZ : public CDialogEx
{
	DECLARE_DYNAMIC(Tab_DATA_CDBRYSYJG_BZ)

public:
	Tab_DATA_CDBRYSYJG_BZ(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Tab_DATA_CDBRYSYJG_BZ();

// 对话框数据
	enum { IDD = IDD_DATA_CDBRYSYJG_BZ };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
