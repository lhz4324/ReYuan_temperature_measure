// DATA_SJHF.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "DATA_SJHF.h"
#include "afxdialogex.h"


// DATA_SJHF 对话框

IMPLEMENT_DYNAMIC(DATA_SJHF, CDialogEx)

DATA_SJHF::DATA_SJHF(CWnd* pParent /*=NULL*/)
	: CDialogEx(DATA_SJHF::IDD, pParent)
{

}

DATA_SJHF::~DATA_SJHF()
{
}

void DATA_SJHF::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, SJHF_ml_control);
}


BEGIN_MESSAGE_MAP(DATA_SJHF, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &DATA_SJHF::OnBnClickedButton2)
END_MESSAGE_MAP()


// DATA_SJHF 消息处理程序


void DATA_SJHF::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码

	CString m_strFilePath = _T("");

	//获取文件路径名
	LPCTSTR szFilter = _T("TXT(*.txt)|*.txt|LOG(*.log)|*.log|ALLSUPORTFILE(*.*)|*.*||");

	CFileDialog dlgFileOpenImg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);
	//打开txt文件
	if (dlgFileOpenImg.DoModal() == IDOK)
	{
		//读取文件名
		m_strFilePath = dlgFileOpenImg.GetPathName();

		SJHF_ml_control.SetWindowTextW(m_strFilePath);//将路径名显示在目录框中(此处目录框就是路径）

	}
	else
	{
		return;
	}
}
