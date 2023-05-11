// SET_SJGS.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "SET_SJGS.h"
#include "afxdialogex.h"

#include "Quanjv.h"
// SET_SJGS 对话框

IMPLEMENT_DYNAMIC(SET_SJGS, CDialogEx)

SET_SJGS::SET_SJGS(CWnd* pParent /*=NULL*/)
	: CDialogEx(SET_SJGS::IDD, pParent)
	, tz_geshi_cstring(_T(""))
	, jl_geshi_cstring(_T(""))
	, wd_geshi_cstring(_T(""))
{

}

SET_SJGS::~SET_SJGS()
{
}

void SET_SJGS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, TZ_duiyingcombo_control);
	DDX_Control(pDX, IDC_COMBO3, JL_duiyingcombo_control);
	DDX_Control(pDX, IDC_COMBO4, WD_duiyingcombo_control);
	DDX_CBString(pDX, IDC_COMBO1, tz_geshi_cstring);
	DDX_CBString(pDX, IDC_COMBO3, jl_geshi_cstring);
	DDX_CBString(pDX, IDC_COMBO4, wd_geshi_cstring);
}


BEGIN_MESSAGE_MAP(SET_SJGS, CDialogEx)
	ON_BN_CLICKED(1003, &SET_SJGS::OnBnClicked1003)
	ON_BN_CLICKED(1002, &SET_SJGS::OnBnClicked1002)
END_MESSAGE_MAP()


// SET_SJGS 消息处理程序


BOOL SET_SJGS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化



	//设置体重下拉框的选项
	TZ_duiyingcombo_control.AddString(TEXT("0"));
	TZ_duiyingcombo_control.AddString(TEXT("0.0"));
	TZ_duiyingcombo_control.AddString(TEXT("0.00"));
	TZ_duiyingcombo_control.AddString(TEXT("0.000"));

	//设置剂量下拉框的选项
	JL_duiyingcombo_control.AddString(TEXT("0"));
	JL_duiyingcombo_control.AddString(TEXT("0.0"));
	JL_duiyingcombo_control.AddString(TEXT("0.00"));

	//设置温度下拉框的选项
	WD_duiyingcombo_control.AddString(TEXT("0.0"));
	WD_duiyingcombo_control.AddString(TEXT("0.00"));


	//设置radiobutton按钮初试状态
	((CButton *)GetDlgItem(1026))->SetCheck(TRUE); //选上
	((CButton *)GetDlgItem(1027))->SetCheck(FALSE);//不选上





	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void SET_SJGS::OnBnClicked1003()//取消按钮
{
	// TODO:  在此添加控件通知处理程序代码

	CDialogEx::OnCancel();
}


void SET_SJGS::OnBnClicked1002()//保存按钮
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);


	//将选中格式保存至全局变量 data_style_now
	data_style_now.jl_style = jl_geshi_cstring;
	data_style_now.tz_style = tz_geshi_cstring;
	data_style_now.wd_style = wd_geshi_cstring;

	if (((CButton *)GetDlgItem(1026))->GetCheck()){
		MessageBox(jl_geshi_cstring);
		data_style_now.wcs = 1;
		data_style_now.sswr = 0;
	}

	if (((CButton *)GetDlgItem(1027))->GetCheck()){
		MessageBox(wd_geshi_cstring);
		data_style_now.sswr = 1;
		data_style_now.wcs = 0;
	}
}
