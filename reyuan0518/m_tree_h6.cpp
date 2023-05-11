// m_tree_h6.cpp: 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "m_tree_h6.h"
#include "afxdialogex.h"


// m_tree_h6 对话框

IMPLEMENT_DYNAMIC(m_tree_h6, CDialogEx)

m_tree_h6::m_tree_h6(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SET_YL_JLGS_h6FZX, pParent)
{

}

m_tree_h6::~m_tree_h6()
{
}

void m_tree_h6::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, r_tab1);
}


BEGIN_MESSAGE_MAP(m_tree_h6, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &m_tree_h6::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// m_tree_h6 消息处理程序


void m_tree_h6::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
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


BOOL m_tree_h6::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	CRect tabRect;
	r_tab1.GetClientRect(&tabRect);
	tabRect.DeflateRect(2, 30, 5, 5);
	r_tab1.InsertItem(0, L"文本");
	r_tab1.InsertItem(1, L"打印报告日期");
	r_tab1.InsertItem(2, L"线段");
	r_tab1.InsertItem(3, L"图片");


	cTabDlg1 = new m_tree_h6wb();
	cTabDlg2 = new m_tree_h6dybgrq();
	cTabDlg3 = new m_tree_h6xd();
	cTabDlg4 = new m_tree_h6tp();

	
	
	cTabDlg1->Create(IDD_TREEH6_WB, &r_tab1);
	cTabDlg2->Create(IDD_TREEH6_DYBGRQ, &r_tab1);
	cTabDlg3->Create(IDD_TREEH6_XD, &r_tab1);
	cTabDlg4->Create(IDD_TREEH6_TP, &r_tab1);

	cTabDlg1->MoveWindow(tabRect);
	cTabDlg2->MoveWindow(tabRect);
	cTabDlg3->MoveWindow(tabRect);
	cTabDlg4->MoveWindow(tabRect);

	cTabDlg1->ShowWindow(SW_SHOW);//默认只显示第一个子窗口，其余的若显示，会覆盖掉第一个

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
