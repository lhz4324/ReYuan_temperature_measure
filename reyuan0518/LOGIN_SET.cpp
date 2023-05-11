// LOGIN_SET.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "LOGIN_SET.h"
#include "afxdialogex.h"


// LOGIN_SET 对话框

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


// LOGIN_SET 消息处理程序


BOOL LOGIN_SET::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	CRect tabRect;
	r_tab1.GetClientRect(&tabRect);
	tabRect.DeflateRect(2, 30, 5, 5);
	r_tab1.InsertItem(0, L"探头设置");
	r_tab1.InsertItem(1, L"登录策略");
	r_tab1.InsertItem(2, L"自动备份");
	r_tab1.InsertItem(3, L"创建账户");

	
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

	cTabDlg1->ShowWindow(SW_SHOW);//默认只显示第一个子窗口，其余的若显示，会覆盖掉第一个
	//cTabDlg2->ShowWindow(SW_SHOW);
	//cTabDlg3->ShowWindow(SW_SHOW);
	//cTabDlg4->ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void LOGIN_SET::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码

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
