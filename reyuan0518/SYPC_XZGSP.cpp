// SYPC_XZGSP.cpp: 实现文件
//

//#include "pch.h"
#include "stdafx.h"
#include "reyuan0518.h"
#include "SYPC_XZGSP.h"
#include "afxdialogex.h"

#include "Quanjv.h"

// SYPC_XZGSP 对话框

IMPLEMENT_DYNAMIC(SYPC_XZGSP, CDialogEx)

SYPC_XZGSP::SYPC_XZGSP(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SYPC_XZGSP, pParent)
{

}

SYPC_XZGSP::~SYPC_XZGSP()
{
}

void SYPC_XZGSP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, LISTCTRL_XZGSP);
}


BEGIN_MESSAGE_MAP(SYPC_XZGSP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &SYPC_XZGSP::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &SYPC_XZGSP::OnBnClickedButton4)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &SYPC_XZGSP::OnNMClickList1)
END_MESSAGE_MAP()


// SYPC_XZGSP 消息处理程序


void SYPC_XZGSP::OnBnClickedButton1()//确定  按此按钮将信息添加至试验排程表格
{
	// TODO: 在此添加控件通知处理程序代码

	//取得当前行内容，并将该行内容同步至 试验排程表格

	//CString str0= LISTCTRL_XZGSP.GetItemText(m_listSelPos, 0); //获取当前记录的显示的文本
	

	//MessageBox(str0);





	my_select_gsp.str_gsp = LISTCTRL_XZGSP.GetItemText(m_listSelPos, 0);//供试品名称
	my_select_gsp.str_ypbh = LISTCTRL_XZGSP.GetItemText(m_listSelPos, 1);//样品编号
	my_select_gsp.str_ph = LISTCTRL_XZGSP.GetItemText(m_listSelPos, 2);//批号
	my_select_gsp.str_yptgdw = LISTCTRL_XZGSP.GetItemText(m_listSelPos, 3);//样品提供单位
	my_select_gsp.str_gg = LISTCTRL_XZGSP.GetItemText(m_listSelPos, 4);//规格
	my_select_gsp.str_cqswzh = LISTCTRL_XZGSP.GetItemText(m_listSelPos,5);//从前升温总和
	my_select_gsp.str_cqcwzs = LISTCTRL_XZGSP.GetItemText(m_listSelPos, 6);//从前超温只数


	//CWnd* pWnd = FindWindow(NULL, _T("Tab_CEWEN_WDCD_SYPC"));//
	::SendMessage(my_wnd, WM_CHILDFRAMEDBCLK, 0, (LPARAM)(&my_select_gsp));





}


void SYPC_XZGSP::OnBnClickedButton4()//取消
{
	// TODO: 在此添加控件通知处理程序代码

	CDialogEx::OnCancel();
}


BOOL SYPC_XZGSP::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	//这一段处理列表内容，格式的设置
	LISTCTRL_XZGSP.SetExtendedStyle(LISTCTRL_XZGSP.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	//这一段初始化表头内容
	CString head1[] = { TEXT("供试品名称"), TEXT("样品编号"), TEXT("批号"), TEXT("样品提供单位"), TEXT("规格"), TEXT("从前升温总和"), TEXT("从前超温只数") };

	for (int i = 0; i < sizeof(head1) / sizeof(head1[0]); i++) {//依次插入
		LISTCTRL_XZGSP.InsertColumn(i, head1[i], LVCFMT_LEFT, 100);
	}

	LISTCTRL_XZGSP.SetColumnWidth(8, LVSCW_AUTOSIZE_USEHEADER);



	//将样品队列中的内容同步至此表格

		
		int ress = mysql_query(&myonlydatabase.m_sqlCon, "select * from 样品队列");//表里面查找
		if (!ress)
		{
			myonlydatabase.res = mysql_store_result(&myonlydatabase.m_sqlCon);
			if (myonlydatabase.res)
			{
				for (int i = 0; i < myonlydatabase.res->row_count; i++) {//将数据库里数据插进表格
					myonlydatabase.row = mysql_fetch_row(myonlydatabase.res);
					CString str0(myonlydatabase.row[0]);//供试品名称
					CString str1(myonlydatabase.row[1]);//样品编号
					CString str2(myonlydatabase.row[2]);//批号
					CString str3(myonlydatabase.row[3]);//样品提供单位sql`
					CString str4(myonlydatabase.row[4]);//规格sql
					CString str5(myonlydatabase.row[7]);//从前升温总和sql`
					CString str6(myonlydatabase.row[8]);//从前超温只数sql`
					
					LISTCTRL_XZGSP.InsertItem(i, str0);//第一个用的是insert，其余列用set
					LISTCTRL_XZGSP.SetItemText(i, 1, str1);
					LISTCTRL_XZGSP.SetItemText(i, 2, str2);
					LISTCTRL_XZGSP.SetItemText(i, 3, str3);
					LISTCTRL_XZGSP.SetItemText(i, 4, str4);
					LISTCTRL_XZGSP.SetItemText(i, 5, str5);
					LISTCTRL_XZGSP.SetItemText(i, 6, str6);//把获取进来的数据插进去

				}
			}

		
		}

		mysql_free_result(myonlydatabase.res);


	LISTCTRL_XZGSP.InsertItem(0, TEXT("hh0"));//第一个用的是insert，其余列用set
	LISTCTRL_XZGSP.SetItemText(0, 1, TEXT("hh1"));
	LISTCTRL_XZGSP.SetItemText(0, 2, TEXT("hh2"));
	LISTCTRL_XZGSP.SetItemText(0, 3, TEXT("hh3"));
	LISTCTRL_XZGSP.SetItemText(0, 4, TEXT("hh4"));
	LISTCTRL_XZGSP.SetItemText(0, 5, TEXT("hh5"));
	LISTCTRL_XZGSP.SetItemText(0, 6, TEXT("hh6"));//把获取进来的数据插进去

	LISTCTRL_XZGSP.InsertItem(1, TEXT("gg0"));//第一个用的是insert，其余列用set
	LISTCTRL_XZGSP.SetItemText(1, 1, TEXT("gg1"));
	LISTCTRL_XZGSP.SetItemText(1, 2, TEXT("gg2"));
	LISTCTRL_XZGSP.SetItemText(1, 3, TEXT("gg3"));
	LISTCTRL_XZGSP.SetItemText(1, 4, TEXT("gg4"));
	LISTCTRL_XZGSP.SetItemText(1, 5, TEXT("gg5"));
	LISTCTRL_XZGSP.SetItemText(1, 6, TEXT("gg6"));//把获取进来的数据插进去


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void SYPC_XZGSP::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	m_listSelPos = LISTCTRL_XZGSP.GetSelectionMark();




	*pResult = 0;
}
