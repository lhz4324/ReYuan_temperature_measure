// FV_CEWEN_WDCD.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "FV_CEWEN_WDCD.h"


// FV_CEWEN_WDCD

IMPLEMENT_DYNCREATE(FV_CEWEN_WDCD, CFormView)

FV_CEWEN_WDCD::FV_CEWEN_WDCD()
	: CFormView(FV_CEWEN_WDCD::IDD)
{

}

FV_CEWEN_WDCD::~FV_CEWEN_WDCD()
{
}

void FV_CEWEN_WDCD::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, r_tab1);
	DDX_Control(pDX, IDC_TAB1, r_tab1);
}

BEGIN_MESSAGE_MAP(FV_CEWEN_WDCD, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &FV_CEWEN_WDCD::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// FV_CEWEN_WDCD ���

#ifdef _DEBUG
void FV_CEWEN_WDCD::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FV_CEWEN_WDCD::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FV_CEWEN_WDCD ��Ϣ�������


void FV_CEWEN_WDCD::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	 
	 //TODO:  �ڴ���ӿؼ�֪ͨ����������
	switch (r_tab1.GetCurSel())
	{
	case 0:
		cTabDlg1->ShowWindow(SW_SHOW);
		cTabDlg2->ShowWindow(SW_HIDE);
		cTabDlg3->ShowWindow(SW_HIDE);

		break;
	case 1:
		cTabDlg2->ShowWindow(SW_SHOW);
		cTabDlg1->ShowWindow(SW_HIDE);
		cTabDlg3->ShowWindow(SW_HIDE);

		break;
	case 2:
		cTabDlg3->ShowWindow(SW_SHOW);
		cTabDlg1->ShowWindow(SW_HIDE);
		cTabDlg2->ShowWindow(SW_HIDE);

		break;

	}

	*pResult = 0;
}


void FV_CEWEN_WDCD::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CRect tabRect;
	r_tab1.GetClientRect(&tabRect);

	tabRect.DeflateRect(2, 30, 5, 5);
	r_tab1.InsertItem(0, L"�����ų�");
	r_tab1.InsertItem(1, L"��Ʒ����");
	r_tab1.InsertItem(2, L"ʵʱ��������");


	cTabDlg1 = new Tab_CEWEN_WDCD_SYPC();
	cTabDlg2 = new Tab_CEWEN_WDCD_YPDL();
	cTabDlg3 = new Tab_CEWEN_WDCD_SSCWQX();

	
	cTabDlg1->Create(IDD_CEWEN_WDCD_SYPC, &r_tab1);
	cTabDlg2->Create(IDD_CEWEN_WDCD_YPDL, &r_tab1);
	cTabDlg3->Create(IDD_CEWEN_WDCD_SSCWQX, &r_tab1);

	
	cTabDlg1->MoveWindow(tabRect);
	cTabDlg2->MoveWindow(tabRect);
	cTabDlg3->MoveWindow(tabRect);

	
	cTabDlg1->ShowWindow(SW_SHOW);
	cTabDlg2->ShowWindow(SW_SHOW);
	cTabDlg3->ShowWindow(SW_SHOW);


	//	return TRUE;  // return TRUE unless you set the focus to a control
	//	// �쳣:  OCX ����ҳӦ���� FALSE

	// TODO:  �ڴ����ר�ô����/����û���
}
