// LOGIN.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "LOGIN.h"
#include "afxdialogex.h"
//#include "./mysql/mysql.h"


#include "LOGIN_SET.h"//设置按钮的头文件
// LOGIN 对话框

#include "instrument_self_check.h"

IMPLEMENT_DYNAMIC(LOGIN, CDialogEx)

LOGIN::LOGIN(CWnd* pParent /*=NULL*/)
	: CDialogEx(LOGIN::IDD, pParent)
	, username(_T(""))
	, password(_T(""))
{

}

LOGIN::~LOGIN()
{
}

void LOGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, username);
	DDX_Text(pDX, IDC_EDIT2, password);
}


BEGIN_MESSAGE_MAP(LOGIN, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LOGIN::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &LOGIN::OnBnClickedButton2)
	ON_WM_CTLCOLOR()
	
END_MESSAGE_MAP()


// LOGIN 消息处理程序


void LOGIN::OnBnClickedButton1()//登录
{
	// TODO:  在此添加控件通知处理程序代码


	//if (没有连接) {
	//	MessageBox(TEXT("设备未连接！请检查端口连接设备！"));
	//}




	GetDlgItem(IDC_EDIT1)->GetWindowText(username);
	GetDlgItem(IDC_EDIT2)->GetWindowText(password);

	
	//const char user[] = "root";
	//const char pswd[] = "root";
	//const char host[] = "localhost";
	//const char databasename[] = "reyuan_mydatabase";
	//unsigned int port = 3306;



	if (username.IsEmpty()){
		MessageBox(TEXT("用户名为空！清重新输入"));
		return;
	}
	if (password.IsEmpty()){
		MessageBox(TEXT("密码为空！清重新输入"));
		return;
	}
	
	
			
			int ress = mysql_query(&myonlydatabase.m_sqlCon, "select * from 用户账号密码");//表里面查找
			if (!ress)
			{
				myonlydatabase.res = mysql_store_result(&myonlydatabase.m_sqlCon);
				if (myonlydatabase.res)
				{
					for (int i = 0; i < myonlydatabase.res->row_count; i++) {
						myonlydatabase.row = mysql_fetch_row(myonlydatabase.res);
						if (myonlydatabase.row[0] == username && myonlydatabase.row[1] == password)//比对是否用户名密码是否一致
						{

							user_info_now.username_now = username; //将此时的账户名称赋值给全局变量 - username_now
							user_info_now.password_now = password;

							//将此账号对应的用户权限同步
							user_info_now.wdcd_now = atoi(myonlydatabase.row[6]);
							user_info_now.ypxxsz_now = atoi(myonlydatabase.row[7]);
							user_info_now.jlgssz_now = atoi(myonlydatabase.row[8]);
							user_info_now.ckttbdjg_now = atoi(myonlydatabase.row[9]);
							user_info_now.ckxttxjg_now = atoi(myonlydatabase.row[10]);
							user_info_now.cxdyryjg_now = atoi(myonlydatabase.row[11]);
							user_info_now.sjbf_now = atoi(myonlydatabase.row[12]);
							user_info_now.bdtt_now = atoi(myonlydatabase.row[13]);
							user_info_now.sdsscwqxsf_now = atoi(myonlydatabase.row[14]);
							user_info_now.gzsjsj_now = atoi(myonlydatabase.row[15]);
							user_info_now.sjgssz_now = atoi(myonlydatabase.row[16]);
							user_info_now.cklxjt_now = atoi(myonlydatabase.row[17]);
							user_info_now.sjwh_now = atoi(myonlydatabase.row[18]);
							user_info_now.zhgl_now = atoi(myonlydatabase.row[19]);


							mysql_free_result(myonlydatabase.res);
							

							if (current_computer_username_selected) {
								if (current_computer_username == username) {
									instrument_self_check window;
									window.DoModal();
									CDialogEx::OnOK();//用户名密码一致，进入程序
								}
								else
								{
									MessageBox(TEXT("当前输入用户名与本机账户名称不一致！请重新输入！"));
								}


							}
							else {
								instrument_self_check window;
								window.DoModal();

								CDialogEx::OnOK();//用户名密码一致，进入程序
							}

							break;
						}
						else
						{
							if (i == myonlydatabase.res->row_count - 1) {
								MessageBox(TEXT("用户名或密码不正确，请重新输入"));
								return;
							}
						}
					}
				}

			}

		
	


	
}


BOOL LOGIN::OnInitDialog()//开始时设置用户名密码
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	// TODO:  在此添加额外的初始化
	username = TEXT("lhz");	//用户名
	password = TEXT("123456");//密码


	UpdateData(FALSE); //内容更新到对应的控件



	if (!myonlydatabase.ConnectDB_orcreate())//判断是否连接数据库成功
	{
		AfxMessageBox(_T("数据库连接失败!"));

	}



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void LOGIN::OnOK()//重写登录界面的回车
{
	// TODO:  在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void LOGIN::OnCancel()//重写登录界面的关闭按钮
{
	// TODO:  在此添加专用代码和/或调用基类


	//CDialogEx::OnCancel();
	exit(0);
}


void LOGIN::OnBnClickedButton2()//配置界面
{
	// TODO:  在此添加控件通知处理程序代码
	LOGIN_SET set;
	set.DoModal();


}


HBRUSH LOGIN::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔

	if (pWnd->GetDlgCtrlID() == IDC_STATICMessage){
		pDC->SetTextColor(RGB(250, 0, 0));

	}
	return hbr;
}



