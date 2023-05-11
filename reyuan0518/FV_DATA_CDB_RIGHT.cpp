// FV_DATA_CDB_RIGHT.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "FV_DATA_CDB_RIGHT.h"


// FV_DATA_CDB_RIGHT

IMPLEMENT_DYNCREATE(FV_DATA_CDB_RIGHT, CFormView)

FV_DATA_CDB_RIGHT::FV_DATA_CDB_RIGHT()
	: CFormView(FV_DATA_CDB_RIGHT::IDD)
{

}

FV_DATA_CDB_RIGHT::~FV_DATA_CDB_RIGHT()
{
}

void FV_DATA_CDB_RIGHT::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(FV_DATA_CDB_RIGHT, CFormView)
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// FV_DATA_CDB_RIGHT 诊断

#ifdef _DEBUG
void FV_DATA_CDB_RIGHT::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FV_DATA_CDB_RIGHT::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FV_DATA_CDB_RIGHT 消息处理程序


void FV_DATA_CDB_RIGHT::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类

	
}





void FV_DATA_CDB_RIGHT::OnPaint()
{
	CPaintDC dc(this); // device context for painting



}


void FV_DATA_CDB_RIGHT::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
}


void FV_DATA_CDB_RIGHT::OnDraw(CDC* pDC)
{

}
