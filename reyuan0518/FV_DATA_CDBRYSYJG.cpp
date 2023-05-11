// FV_DATA_CDBRYSYJG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "FV_DATA_CDBRYSYJG.h"


// FV_DATA_CDBRYSYJG

IMPLEMENT_DYNCREATE(FV_DATA_CDBRYSYJG, CFormView)

FV_DATA_CDBRYSYJG::FV_DATA_CDBRYSYJG()
	: CFormView(FV_DATA_CDBRYSYJG::IDD)
{

}

FV_DATA_CDBRYSYJG::~FV_DATA_CDBRYSYJG()
{
}

void FV_DATA_CDBRYSYJG::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, r_tab1);
}

BEGIN_MESSAGE_MAP(FV_DATA_CDBRYSYJG, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &FV_DATA_CDBRYSYJG::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// FV_DATA_CDBRYSYJG ���

#ifdef _DEBUG
void FV_DATA_CDBRYSYJG::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FV_DATA_CDBRYSYJG::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FV_DATA_CDBRYSYJG ��Ϣ�������


void FV_DATA_CDBRYSYJG::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	switch (r_tab1.GetCurSel())
	{
	case 0:
		cTabDlg1->ShowWindow(SW_SHOW);
		cTabDlg2->ShowWindow(SW_HIDE);
		break;
	case 1:
		cTabDlg2->ShowWindow(SW_SHOW);
		cTabDlg1->ShowWindow(SW_HIDE);
		break;


	}
	*pResult = 0;
}


void FV_DATA_CDBRYSYJG::OnInitialUpdate()
{

	CFormView::OnInitialUpdate();
	CRect tabRect;
	r_tab1.GetClientRect(&tabRect);

	tabRect.DeflateRect(2, 30, 5, 5);
	r_tab1.InsertItem(0, L"��ѯ����ӡ");
	r_tab1.InsertItem(1, L"����");


	cTabDlg1 = new Tab_DATA_CDBRYSYJG_CXDY();
	cTabDlg2 = new Tab_DATA_CDBRYSYJG_BZ();



	cTabDlg1->Create(IDD_DATA_CDBRYSYJG_CXDY, &r_tab1);
	cTabDlg2->Create(IDD_DATA_CDBRYSYJG_BZ, &r_tab1);



	cTabDlg1->MoveWindow(tabRect);
	cTabDlg2->MoveWindow(tabRect);



	cTabDlg1->ShowWindow(SW_SHOW);
	cTabDlg2->ShowWindow(SW_SHOW);

	
}



