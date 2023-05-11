#pragma once
#include "afxcmn.h"



// FV_DATA_GZSJSJ 窗体视图

class FV_DATA_GZSJSJ : public CFormView
{
	DECLARE_DYNCREATE(FV_DATA_GZSJSJ)

protected:
	FV_DATA_GZSJSJ();           // 动态创建所使用的受保护的构造函数
	virtual ~FV_DATA_GZSJSJ();

public:
	enum { IDD = IDD_DATA_GZSJSJ };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl DATA_GZSJSJ_list; //设置数据—跟踪审计数据的列表
public:
	virtual void OnInitialUpdate();//重载虚函数
};


