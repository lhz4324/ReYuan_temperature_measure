// LOGIN_SET.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "LOGIN_SET.h"
#include "afxdialogex.h"


// LOGIN_SET �Ի���

IMPLEMENT_DYNAMIC(LOGIN_SET, CDialogEx)

LOGIN_SET::LOGIN_SET(CWnd* pParent /*=NULL*/)
	: CDialogEx(LOGIN_SET::IDD, pParent)
{

}

LOGIN_SET::~LOGIN_SET()
{
}

void LOGIN_SET::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, r_tab1);
}


BEGIN_MESSAGE_MAP(LOGIN_SET, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &LOGIN_SET::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// LOGIN_SET ��Ϣ�������


BOOL LOGIN_SET::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��


	CRect tabRect;
	r_tab1.GetClientRect(&tabRect);
	tabRect.DeflateRect(2, 30, 5, 5);
	r_tab1.InsertItem(0, L"̽ͷ����");
	r_tab1.InsertItem(1, L"��¼����");
	r_tab1.InsertItem(2, L"�Զ�����");
	r_tab1.InsertItem(3, L"�����˻�");

	
	cTabDlg1 = new LOGIN_SET_TTSZ();
	cTabDlg2 = new LOGIN_SET_DLCL();
	cTabDlg3 = new LOGIN_SET_ZDBF();
	cTabDlg4 = new LOGIN_SET_CJZH();

	cTabDlg1->Create(IDD_LOGIN_SET_TTSZ, &r_tab1);
	cTabDlg2->Create(IDD_LOGIN_SET_DLCL, &r_tab1);
	cTabDlg3->Create(IDD_LOGIN_SET_ZDBF, &r_tab1);
	cTabDlg4->Create(IDD_LOGIN_SET_CJZH, &r_tab1);

	cTabDlg1->MoveWindow(tabRect);
	cTabDlg2->MoveWindow(tabRect);
	cTabDlg3->MoveWindow(tabRect);
	cTabDlg4->MoveWindow(tabRect);

	cTabDlg1->ShowWindow(SW_SHOW);//Ĭ��ֻ��ʾ��һ���Ӵ��ڣ����������ʾ���Ḳ�ǵ���һ��
	//cTabDlg2->ShowWindow(SW_SHOW);
	//cTabDlg3->ShowWindow(SW_SHOW);
	//cTabDlg4->ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void LOGIN_SET::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	switch (r_tab1.GetCurSel())
	{
	case 0:
		cTabDlg1->ShowWindow(SW_SHOW);
		cTabDlg2->ShowWindow(SW_HIDE);
		cTabDlg3->ShowWindow(SW_HIDE);
		cTabDlg4->ShowWindow(SW_HIDE);
		break;
	case 1:
		cTabDlg2->ShowWindow(SW_SHOW);
		cTabDlg1->ShowWindow(SW_HIDE);
		cTabDlg3->ShowWindow(SW_HIDE);
		cTabDlg4->ShowWindow(SW_HIDE);
		break;
	case 2:
		cTabDlg3->ShowWindow(SW_SHOW);
		cTabDlg1->ShowWindow(SW_HIDE);
		cTabDlg2->ShowWindow(SW_HIDE);
		cTabDlg4->ShowWindow(SW_HIDE);
		break;
	case 3:
		cTabDlg4->ShowWindow(SW_SHOW);
		cTabDlg1->ShowWindow(SW_HIDE);
		cTabDlg2->ShowWindow(SW_HIDE);
		cTabDlg3->ShowWindow(SW_HIDE);
		break;

	}


	*pResult = 0;
}
