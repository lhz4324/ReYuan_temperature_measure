#pragma once

#include "Quanjv.h"

// SET_YL_JLGS_RIGHT 窗体视图

class SET_YL_JLGS_RIGHT : public CFormView
{
	DECLARE_DYNCREATE(SET_YL_JLGS_RIGHT)

protected:
	SET_YL_JLGS_RIGHT();           // 动态创建所使用的受保护的构造函数
	virtual ~SET_YL_JLGS_RIGHT();

public:
	enum { IDD = IDD_SET_YL_JLGS_RIGHT };
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
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnInitialUpdate();

	int a4w_in_pixel;
	int a4h_in_pixel;

	afx_msg LRESULT OnLEFTPREVIEWClick(WPARAM wParam, LPARAM lParam);//两窗口间消息传递
};


