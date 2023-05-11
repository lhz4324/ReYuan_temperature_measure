// FV_DATA_CKLXJT.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "FV_DATA_CKLXJT.h"


// FV_DATA_CKLXJT

IMPLEMENT_DYNCREATE(FV_DATA_CKLXJT, CFormView)

FV_DATA_CKLXJT::FV_DATA_CKLXJT()
	: CFormView(FV_DATA_CKLXJT::IDD)
{

}

FV_DATA_CKLXJT::~FV_DATA_CKLXJT()
{
}

void FV_DATA_CKLXJT::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, DATA_CKLXJT_list1);
	DDX_Control(pDX, IDC_LIST3, DATA_CKLXJT_list2);
}

BEGIN_MESSAGE_MAP(FV_DATA_CKLXJT, CFormView)
END_MESSAGE_MAP()


// FV_DATA_CKLXJT 诊断

#ifdef _DEBUG
void FV_DATA_CKLXJT::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FV_DATA_CKLXJT::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FV_DATA_CKLXJT 消息处理程序


void FV_DATA_CKLXJT::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();


	DATA_CKLXJT_list1.SetExtendedStyle(DATA_CKLXJT_list1.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	CString head[] = { TEXT("日期"), TEXT("探头号"), TEXT("兔号"), TEXT("体重"), TEXT("试验方法") };
	DATA_CKLXJT_list1.InsertColumn(0, head[0], LVCFMT_LEFT, 100);
	DATA_CKLXJT_list1.InsertColumn(1, head[1], LVCFMT_LEFT, 100);
	DATA_CKLXJT_list1.InsertColumn(2, head[2], LVCFMT_LEFT, 100);
	DATA_CKLXJT_list1.InsertColumn(3, head[3], LVCFMT_LEFT, 100);
	DATA_CKLXJT_list1.InsertColumn(4, head[4], LVCFMT_LEFT, 100);


	DATA_CKLXJT_list2.SetExtendedStyle(DATA_CKLXJT_list2.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	CString head1[] = { TEXT("顺序号"), TEXT("时间"), TEXT("温度") };
	DATA_CKLXJT_list2.InsertColumn(0, head1[0], LVCFMT_LEFT, 100);
	DATA_CKLXJT_list2.InsertColumn(1, head1[1], LVCFMT_LEFT, 100);
	DATA_CKLXJT_list2.InsertColumn(2, head1[2], LVCFMT_LEFT, 100);
	// TODO:  在此添加专用代码和/或调用基类
}
