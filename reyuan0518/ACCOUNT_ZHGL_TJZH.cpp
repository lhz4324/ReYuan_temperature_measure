// ACCOUNT_ZHGL_TJZH.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "ACCOUNT_ZHGL_TJZH.h"
#include "afxdialogex.h"
//#include "./mysql/mysql.h"
//#include "MyDatabase.h"

#include "Quanjv.h"
// ACCOUNT_ZHGL_TJZH 对话框

IMPLEMENT_DYNAMIC(ACCOUNT_ZHGL_TJZH, CDialogEx)

ACCOUNT_ZHGL_TJZH::ACCOUNT_ZHGL_TJZH(CWnd* pParent /*=NULL*/)
	: CDialogEx(ACCOUNT_ZHGL_TJZH::IDD, pParent)
	, ACCOUNT_ZHGL_TJZH_username(_T(""))
	, ACCOUNT_ZHGL_TJZH_password(_T(""))
	, m_ccdlggmm(FALSE)
{

}

ACCOUNT_ZHGL_TJZH::~ACCOUNT_ZHGL_TJZH()
{
}

void ACCOUNT_ZHGL_TJZH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ACCOUNT_ZHGL_TJZH_username);
	DDX_Text(pDX, IDC_EDIT3, ACCOUNT_ZHGL_TJZH_password);
	DDX_Check(pDX, IDC_CHECK1, m_ccdlggmm);
}


BEGIN_MESSAGE_MAP(ACCOUNT_ZHGL_TJZH, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ACCOUNT_ZHGL_TJZH::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &ACCOUNT_ZHGL_TJZH::OnBnClickedCheck1)
END_MESSAGE_MAP()


// ACCOUNT_ZHGL_TJZH 消息处理程序


void ACCOUNT_ZHGL_TJZH::OnBnClickedButton1()//按钮增加账户信息到数据库
{
	// TODO:  在此添加控件通知处理程序代码

	/*********************************************************************************************///以下代码是利用mydatabase类封装实现

	GetDlgItem(IDC_EDIT1)->GetWindowText(ACCOUNT_ZHGL_TJZH_username);//获取文本框数据—输入的账号
	GetDlgItem(IDC_EDIT3)->GetWindowText(ACCOUNT_ZHGL_TJZH_password);//获取文本框数据—输入的密码

	GetDlgItem(IDC_EDIT5)->GetWindowText(ACCOUNT_ZHGL_TJZH_juese);//获取文本框数据—输入的角色
	GetDlgItem(IDC_EDIT12)->GetWindowText(ACCOUNT_ZHGL_TJZH_quanxian);//获取文本框数据—输入的权限

	
	
		UpdateData(true);

		//将所有checkbox控件同步到全局变量
		user_info_now.ccdlggmm_now = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck();
		user_info_now.zhsd_now = ((CButton *)GetDlgItem(IDC_CHECK2))->GetCheck();
		user_info_now.wdcd_now = ((CButton *)GetDlgItem(IDC_CHECK5))->GetCheck();
		user_info_now.ypxxsz_now = ((CButton *)GetDlgItem(IDC_CHECK6))->GetCheck();
		user_info_now.jlgssz_now = ((CButton *)GetDlgItem(IDC_CHECK7))->GetCheck();
		user_info_now.ckttbdjg_now = ((CButton *)GetDlgItem(IDC_CHECK8))->GetCheck();
		user_info_now.ckxttxjg_now = ((CButton *)GetDlgItem(IDC_CHECK9))->GetCheck();
		user_info_now.sjbf_now = ((CButton *)GetDlgItem(IDC_CHECK10))->GetCheck();
		user_info_now.bdtt_now = ((CButton *)GetDlgItem(IDC_CHECK11))->GetCheck();
		user_info_now.sdsscwqxsf_now = ((CButton *)GetDlgItem(IDC_CHECK12))->GetCheck();
		user_info_now.gzsjsj_now = ((CButton *)GetDlgItem(IDC_CHECK13))->GetCheck();
		user_info_now.sjgssz_now = ((CButton *)GetDlgItem(IDC_CHECK14))->GetCheck();
		user_info_now.cklxjt_now = ((CButton *)GetDlgItem(IDC_CHECK15))->GetCheck();
		user_info_now.sjwh_now = ((CButton *)GetDlgItem(IDC_CHECK16))->GetCheck();

		user_info_now.cxdyryjg_now = ((CButton *)GetDlgItem(IDC_CHECK17))->GetCheck();
		user_info_now.zhgl_now = ((CButton *)GetDlgItem(IDC_CHECK18))->GetCheck();

		//将文本框中内容同步至全局变量
		user_info_now.username_now = ACCOUNT_ZHGL_TJZH_username;
		user_info_now.password_now = ACCOUNT_ZHGL_TJZH_password;
		user_info_now.juese_now = ACCOUNT_ZHGL_TJZH_juese;


		user_info_now.quanxian_now = ACCOUNT_ZHGL_TJZH_quanxian;

		myonlydatabase.add_account(user_info_now);
		return;

	





	UpdateData(false);
	//******************************************************************************************************************************
}


BOOL ACCOUNT_ZHGL_TJZH::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	//设置权限等级为默认值 二级
	CStatic* m_pStatic1 = (CStatic*)GetDlgItem(IDC_EDIT12);
	m_pStatic1->SetWindowText(_T("二级"));




	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void ACCOUNT_ZHGL_TJZH::OnBnClickedCheck1()
{
	// TODO:  在此添加控件通知处理程序代码

}
