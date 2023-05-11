// FV_POINT_QR.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "FV_POINT_QR.h"


// FV_POINT_QR

IMPLEMENT_DYNCREATE(FV_POINT_QR, CFormView)

FV_POINT_QR::FV_POINT_QR()
	: CFormView(FV_POINT_QR::IDD)
{

}

FV_POINT_QR::~FV_POINT_QR()
{
}

void FV_POINT_QR::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(FV_POINT_QR, CFormView)
END_MESSAGE_MAP()


// FV_POINT_QR 诊断

#ifdef _DEBUG
void FV_POINT_QR::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FV_POINT_QR::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FV_POINT_QR 消息处理程序
