#pragma once



// FV_DATA_CDB 窗体视图

class FV_DATA_CDB : public CFormView
{
	DECLARE_DYNCREATE(FV_DATA_CDB)

protected:
	FV_DATA_CDB();           // 动态创建所使用的受保护的构造函数
	virtual ~FV_DATA_CDB();

public:
	enum { IDD = IDD_DATA_CDB };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

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
};


