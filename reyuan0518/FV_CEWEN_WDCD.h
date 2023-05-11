#pragma once
#include "Tab_CEWEN_WDCD_SYPC.h"
#include "Tab_CEWEN_WDCD_YPDL.h"
#include "Tab_CEWEN_WDCD_SSCWQX.h"

#include "afxcmn.h"
//#include"CEWEN_WDCD_SYPC.h"
//#include "afxcmn.h"

// FV_CEWEN_WDCD 窗体视图

class FV_CEWEN_WDCD : public CFormView
{
	DECLARE_DYNCREATE(FV_CEWEN_WDCD)

protected:
	FV_CEWEN_WDCD();           // 动态创建所使用的受保护的构造函数
	virtual ~FV_CEWEN_WDCD();

public:
	enum { IDD = IDD_CEWEN_WDCD };
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
	//CEWEN_WDCD_SYPC* cTabDlg1;

	Tab_CEWEN_WDCD_SYPC* cTabDlg1;
	Tab_CEWEN_WDCD_YPDL* cTabDlg2;
	Tab_CEWEN_WDCD_SSCWQX* cTabDlg3;

	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl r_tab1;
	virtual void OnInitialUpdate();
};



