// ACCOUNT_ZHGL.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "ACCOUNT_ZHGL.h"
#include "afxdialogex.h"
#include "ACCOUNT_ZHGL_TJZH.h"

// ACCOUNT_ZHGL 对话框

IMPLEMENT_DYNAMIC(ACCOUNT_ZHGL, CDialogEx)

ACCOUNT_ZHGL::ACCOUNT_ZHGL(CWnd* pParent /*=NULL*/)
	: CDialogEx(ACCOUNT_ZHGL::IDD, pParent)
{

}

ACCOUNT_ZHGL::~ACCOUNT_ZHGL()
{
}

void ACCOUNT_ZHGL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ACCOUNT_ZHGL, CDialogEx)
	ON_BN_CLICKED(1002, &ACCOUNT_ZHGL::OnBnClicked1002)
	ON_BN_CLICKED(1003, &ACCOUNT_ZHGL::OnBnClicked1003)
END_MESSAGE_MAP()


// ACCOUNT_ZHGL 消息处理程序


void ACCOUNT_ZHGL::OnBnClicked1002()
{
	// TODO:  在此添加控件通知处理程序代码
	ACCOUNT_ZHGL_TJZH dlg;
	dlg.DoModal();

}


void ACCOUNT_ZHGL::OnBnClicked1003()
{
	// TODO:  在此添加控件通知处理程序代码
}
