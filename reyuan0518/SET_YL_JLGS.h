#pragma once


// SET_YL_JLGS 对话框

class SET_YL_JLGS : public CDialogEx
{
	DECLARE_DYNAMIC(SET_YL_JLGS)

public:
	SET_YL_JLGS(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SET_YL_JLGS();

// 对话框数据
	enum { IDD = IDD_SET_YL_JLGS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
public:
	CFrameWnd *m_pMyFrame;
	CSplitterWnd m_cSplitter;
	virtual BOOL OnInitDialog();
};
