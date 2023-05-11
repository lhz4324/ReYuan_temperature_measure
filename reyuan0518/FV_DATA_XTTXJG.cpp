// FV_DATA_XTTXJG.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "FV_DATA_XTTXJG.h"


// FV_DATA_XTTXJG

IMPLEMENT_DYNCREATE(FV_DATA_XTTXJG, CFormView)

FV_DATA_XTTXJG::FV_DATA_XTTXJG()
	: CFormView(FV_DATA_XTTXJG::IDD)
{

}

FV_DATA_XTTXJG::~FV_DATA_XTTXJG()
{
}

void FV_DATA_XTTXJG::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, DATA_XTTXJG_list);
}

BEGIN_MESSAGE_MAP(FV_DATA_XTTXJG, CFormView)
END_MESSAGE_MAP()


// FV_DATA_XTTXJG 诊断

#ifdef _DEBUG
void FV_DATA_XTTXJG::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FV_DATA_XTTXJG::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FV_DATA_XTTXJG 消息处理程序


void FV_DATA_XTTXJG::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	DATA_XTTXJG_list.SetExtendedStyle(DATA_XTTXJG_list.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	CString head[] = { TEXT("日期"), TEXT("探头号"), TEXT("兔号"), TEXT("体重"), TEXT("试验方法"), TEXT("温度1"), TEXT("温度2"), TEXT("温度3"), TEXT("温度4"), TEXT("温度5"), TEXT("温度6"), TEXT("温度7"), TEXT("温度8"), TEXT("温度9"), TEXT("最大值"), TEXT("最小值"), TEXT("温差"), TEXT("结论") };
	DATA_XTTXJG_list.InsertColumn(0, head[0], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(1, head[1], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(2, head[2], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(3, head[3], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(4, head[4], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(5, head[5], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(6, head[6], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(7, head[7], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(8, head[8], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(9, head[9], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(10, head[10], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(11, head[11], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(12, head[12], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(13, head[13], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(14, head[14], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(15, head[15], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(16, head[16], LVCFMT_LEFT, 100);
	DATA_XTTXJG_list.InsertColumn(17, head[17], LVCFMT_LEFT, 100);
}
