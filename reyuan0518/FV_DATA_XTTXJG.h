#pragma once
#include "afxcmn.h"



// FV_DATA_XTTXJG 窗体视图

class FV_DATA_XTTXJG : public CFormView
{
	DECLARE_DYNCREATE(FV_DATA_XTTXJG)

protected:
	FV_DATA_XTTXJG();           // 动态创建所使用的受保护的构造函数
	virtual ~FV_DATA_XTTXJG();

public:
	enum { IDD = IDD_DATA_XTTXJG };
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
	virtual void OnInitialUpdate();
private:
	CListCtrl DATA_XTTXJG_list;
};


