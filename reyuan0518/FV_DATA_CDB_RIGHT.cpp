// FV_DATA_CDB_RIGHT.cpp : ʵ���ļ�
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


// FV_DATA_CDB_RIGHT ���

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


// FV_DATA_CDB_RIGHT ��Ϣ�������


void FV_DATA_CDB_RIGHT::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���

	
}





void FV_DATA_CDB_RIGHT::OnPaint()
{
	CPaintDC dc(this); // device context for painting



}


void FV_DATA_CDB_RIGHT::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
}


void FV_DATA_CDB_RIGHT::OnDraw(CDC* pDC)
{

}
