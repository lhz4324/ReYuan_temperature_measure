#pragma once
#include "afxcmn.h"
#include "Tab_DATA_CDBRYSYJG_BZ.h"
#include "Tab_DATA_CDBRYSYJG_CXDY.h"
// FV_DATA_CDBRYSYJG 窗体视图

class FV_DATA_CDBRYSYJG : public CFormView
{
	DECLARE_DYNCREATE(FV_DATA_CDBRYSYJG)

protected:
	FV_DATA_CDBRYSYJG();           // 动态创建所使用的受保护的构造函数
	virtual ~FV_DATA_CDBRYSYJG();

public:
	enum { IDD = IDD_DATA_CDBRYSYJG };
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

	Tab_DATA_CDBRYSYJG_CXDY* cTabDlg1;
	Tab_DATA_CDBRYSYJG_BZ* cTabDlg2;

	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl r_tab1;
	virtual void OnInitialUpdate();

};


