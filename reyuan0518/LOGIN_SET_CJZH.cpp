// LOGIN_SET_CJZH.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "LOGIN_SET_CJZH.h"
#include "afxdialogex.h"

#include "ACCOUNT_ZHGL_TJZH.h"
#include "ACCOUNT_ZHGL_XGZH.h"
#include "Quanjv.h"
//#include "MyDatabase.h"
// LOGIN_SET_CJZH 对话框

IMPLEMENT_DYNAMIC(LOGIN_SET_CJZH, CDialogEx)

LOGIN_SET_CJZH::LOGIN_SET_CJZH(CWnd* pParent /*=NULL*/)
: CDialogEx(LOGIN_SET_CJZH::IDD, pParent)
{

}

LOGIN_SET_CJZH::~LOGIN_SET_CJZH()
{
}

void LOGIN_SET_CJZH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mlist_control);
}


BEGIN_MESSAGE_MAP(LOGIN_SET_CJZH, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LOGIN_SET_CJZH::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &LOGIN_SET_CJZH::OnBnClickedButton2)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &LOGIN_SET_CJZH::OnNMClickList1)
END_MESSAGE_MAP()


// LOGIN_SET_CJZH 消息处理程序


void LOGIN_SET_CJZH::OnBnClickedButton1()//添加账户
{
	// TODO:  在此添加控件通知处理程序代码

	ACCOUNT_ZHGL_TJZH tjzh;
	
	tjzh.DoModal();

}


void LOGIN_SET_CJZH::OnBnClickedButton2()//修改账户
{
	// TODO:  在此添加控件通知处理程序代码

	ACCOUNT_ZHGL_XGZH xgzh;
	
	xgzh.DoModal();

}


BOOL LOGIN_SET_CJZH::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//这一段处理列表内容，格式的设置
	mlist_control.SetExtendedStyle(mlist_control.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	//这一段初始化表头内容
	CString head[] = { TEXT("账户"), TEXT("权限等级"), TEXT("角色"), TEXT("初次登录更改密码"), TEXT("账户锁定"), TEXT("温度测定"), TEXT("样品信息设置"), TEXT("记录格式设置"), TEXT("查看探头结果"), TEXT("查看新兔挑选结果"), TEXT("查询、打印热原结果"), TEXT("数据备份"), TEXT("标定探头"), TEXT("设定实时测温曲线缩放"), TEXT("跟踪审计数据"), TEXT("数据格式设置"), TEXT("查看落选家兔"), TEXT("数据维护"), TEXT("账户管理") };
	for(int i = 0; i < sizeof(head) / sizeof(head[0]); i++){
		mlist_control.InsertColumn(i, head[i], LVCFMT_LEFT, 100);

	}


	//将数据库里账户信息初始化进表格中
		int ress = mysql_query(&myonlydatabase.m_sqlCon, "select * from 用户账号密码");//表里面查找
		if (!ress)
		{
			myonlydatabase.res = mysql_store_result(&myonlydatabase.m_sqlCon);
			if (myonlydatabase.res)
			{
				for (int i = 0; i < myonlydatabase.res->row_count; i++){//将数据库里数据插进表格
					myonlydatabase.row = mysql_fetch_row(myonlydatabase.res);
					CString str0(myonlydatabase.row[0]);
					CString str1(myonlydatabase.row[3]);
					CString str2(myonlydatabase.row[2]);
	

					mlist_control.InsertItem(i, str0);//第一个用的是insert，其余列用set
					mlist_control.SetItemText(i, 1, str1);
					mlist_control.SetItemText(i, 2, str2);

					for (int j = 3; j < sizeof(head) / sizeof(head[0]); j++){

						CString str(myonlydatabase.row[j+1]);
						mlist_control.SetItemText(i, j, str);
					}


				}
			}

		}
	




	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void LOGIN_SET_CJZH::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码

	m_listSelPos = mlist_control.GetSelectionMark();
	
	selected_current_name=mlist_control.GetItemText(m_listSelPos, 0);//必须用cedit类型的才能调这个函数




	*pResult = 0;
}
