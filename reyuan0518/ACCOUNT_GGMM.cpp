// ACCOUNT_GGMM.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "ACCOUNT_GGMM.h"
#include "afxdialogex.h"
//#include "./mysql/mysql.h"

//#include "MyDatabase.h"
#include "Quanjv.h"
// ACCOUNT_GGMM 对话框

IMPLEMENT_DYNAMIC(ACCOUNT_GGMM, CDialogEx)

ACCOUNT_GGMM::ACCOUNT_GGMM(CWnd* pParent /*=NULL*/)
	: CDialogEx(ACCOUNT_GGMM::IDD, pParent)
	, STATIC_username_now(_T(""))
	, current_password(_T(""))
	, new_password(_T(""))
	, new_password_again(_T(""))
{

}

ACCOUNT_GGMM::~ACCOUNT_GGMM()
{
}

void ACCOUNT_GGMM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_username_now, STATIC_username_now);
	DDX_Text(pDX, 1000, current_password);
	DDX_Text(pDX, 1001, new_password);
	DDX_Text(pDX, 1004, new_password_again);
}


BEGIN_MESSAGE_MAP(ACCOUNT_GGMM, CDialogEx)
	ON_BN_CLICKED(1002, &ACCOUNT_GGMM::OnBnClicked1002)
END_MESSAGE_MAP()


// ACCOUNT_GGMM 消息处理程序


void ACCOUNT_GGMM::OnBnClicked1002()//修改密码
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(1000)->GetWindowText(current_password);//获取文本框数据—输入的旧密码
	if (current_password != user_info_now.password_now){//判断是否一致

		if (current_password == _T(""))AfxMessageBox(_T("请输入旧密码！"));
		else AfxMessageBox(_T("当前密码不正确，请重新输入！"));
	}
	else{//若一致，再看输入的新密码
		GetDlgItem(1001)->GetWindowText(new_password);//获取文本框数据—输入的新密码
		GetDlgItem(1004)->GetWindowText(new_password_again);//获取文本框数据—输入的第二次新密码
		if (new_password == _T("") && new_password_again == _T("")){
			AfxMessageBox(_T("请输入新密码！"));
		}
		else{
			if (new_password != new_password_again){//看新输入的两次是否一致
				AfxMessageBox(_T("输入的新密码不一致，请重新输入！"));
			}
			else{//这个里面为更新密码的代码

				USES_CONVERSION;

				myonlydatabase.change_account_password_mydatabase(T2A(new_password), T2A(user_info_now.username_now));//更改密码
					
				
		}					
		}
	}





}


BOOL ACCOUNT_GGMM::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	CStatic* m_pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC_username_now);//static控件先添加一个变量，改一下ID就行，这两行设置当前账户名称
	m_pStatic2->SetWindowText(user_info_now.username_now);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}



