#pragma once


// SET_JLGS_XT 对话框

class SET_JLGS_XT : public CDialogEx
{
	DECLARE_DYNAMIC(SET_JLGS_XT)

public:
	SET_JLGS_XT(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SET_JLGS_XT();

// 对话框数据
	enum { IDD = IDD_SET_JLGS_XT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
