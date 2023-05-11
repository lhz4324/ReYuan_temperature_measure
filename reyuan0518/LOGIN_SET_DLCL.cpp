// LOGIN_SET_DLCL.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "LOGIN_SET_DLCL.h"
#include "afxdialogex.h"

#include "Quanjv.h"
// LOGIN_SET_DLCL 对话框

IMPLEMENT_DYNAMIC(LOGIN_SET_DLCL, CDialogEx)

LOGIN_SET_DLCL::LOGIN_SET_DLCL(CWnd* pParent /*=NULL*/)
	: CDialogEx(LOGIN_SET_DLCL::IDD, pParent)
{

}

LOGIN_SET_DLCL::~LOGIN_SET_DLCL()
{
}

void LOGIN_SET_DLCL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LOGIN_SET_DLCL, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LOGIN_SET_DLCL::OnBnClickedButton1)
END_MESSAGE_MAP()


// LOGIN_SET_DLCL 消息处理程序


void LOGIN_SET_DLCL::OnBnClickedButton1()//应用
{
	// TODO: 在此添加控件通知处理程序代码

	/*char hostname[128];
	gethostname(hostname, 128);
	CString str(hostname);//获取本机设备名称
	MessageBox(str);*/

	if (((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		LPWSTR current_computer_username_temp;
		current_computer_username_temp = (LPWSTR)malloc(100);
		DWORD dw = 100;
		GetUserName(current_computer_username_temp, &dw);
		CString str(current_computer_username_temp);
		current_computer_username = str;//将全局变量当前电脑用户名赋值
		
		//MessageBox(str);
	}

	current_computer_username_selected = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck();
	MessageBox(TEXT("设置成功！"));

}
