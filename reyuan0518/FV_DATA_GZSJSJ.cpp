// FV_DATA_GZSJSJ.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "FV_DATA_GZSJSJ.h"


// FV_DATA_GZSJSJ

IMPLEMENT_DYNCREATE(FV_DATA_GZSJSJ, CFormView)

FV_DATA_GZSJSJ::FV_DATA_GZSJSJ()
	: CFormView(FV_DATA_GZSJSJ::IDD)
{

}

FV_DATA_GZSJSJ::~FV_DATA_GZSJSJ()
{
}

void FV_DATA_GZSJSJ::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, DATA_GZSJSJ_list);
}

BEGIN_MESSAGE_MAP(FV_DATA_GZSJSJ, CFormView)
END_MESSAGE_MAP()


// FV_DATA_GZSJSJ 诊断

#ifdef _DEBUG
void FV_DATA_GZSJSJ::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FV_DATA_GZSJSJ::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FV_DATA_GZSJSJ 消息处理程序


void FV_DATA_GZSJSJ::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	DATA_GZSJSJ_list.SetExtendedStyle(DATA_GZSJSJ_list.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);//设置数据—跟踪审计数据的列表

	CString head[] = { TEXT("日期"), TEXT("账户"), TEXT("权限等级"), TEXT("角色"), TEXT("操作"), TEXT("原因") };//设置数据—跟踪审计数据的列表
	DATA_GZSJSJ_list.InsertColumn(0, head[0], LVCFMT_LEFT, 100);
	DATA_GZSJSJ_list.InsertColumn(1, head[1], LVCFMT_LEFT, 100);
	DATA_GZSJSJ_list.InsertColumn(2, head[2], LVCFMT_LEFT, 100);
	DATA_GZSJSJ_list.InsertColumn(3, head[3], LVCFMT_LEFT, 100);
	DATA_GZSJSJ_list.InsertColumn(4, head[4], LVCFMT_LEFT, 100);
	DATA_GZSJSJ_list.InsertColumn(5, head[5], LVCFMT_LEFT, 100);
}
