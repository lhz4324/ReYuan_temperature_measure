// SET_JLGS_RY.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "SET_JLGS_RY.h"
#include "afxdialogex.h"

#include "SET_YL_JLGS.h"

#include "Quanjv.h"
// SET_JLGS_RY 对话框

IMPLEMENT_DYNAMIC(SET_JLGS_RY, CDialogEx)

SET_JLGS_RY::SET_JLGS_RY(CWnd* pParent /*=NULL*/)
	: CDialogEx(SET_JLGS_RY::IDD, pParent)
{

}

SET_JLGS_RY::~SET_JLGS_RY()
{
}

void SET_JLGS_RY::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, RY_list_control);
}


BEGIN_MESSAGE_MAP(SET_JLGS_RY, CDialogEx)
	ON_BN_CLICKED(1002, &SET_JLGS_RY::OnBnClicked1002)
	ON_BN_CLICKED(1003, &SET_JLGS_RY::OnBnClicked1003)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &SET_JLGS_RY::OnNMClickList1)
END_MESSAGE_MAP()


// SET_JLGS_RY 消息处理程序


void SET_JLGS_RY::OnBnClicked1002()//修改按钮
{
	// TODO:  在此添加控件通知处理程序代码
	SET_YL_JLGS YL_JLGS;
	YL_JLGS.DoModal();
	
}


void SET_JLGS_RY::OnBnClicked1003()//新建按钮
{
	// TODO:  在此添加控件通知处理程序代码
	SET_YL_JLGS YL_JLGS;
	title = TEXT("新建");
	YL_JLGS.DoModal();
	
}


BOOL SET_JLGS_RY::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	
	CString head[] = { TEXT("ChP初试"), TEXT("ChP复试"), TEXT("ChP新兔挑选"), TEXT("EP第一次"), TEXT("EP第二次"), TEXT("EP第三次"), TEXT("EP第四次"), TEXT("EP新兔挑选"), TEXT("USP初试"), TEXT("USP复试"),TEXT("USP新兔挑选") };

	for (int i = 0; i < sizeof(head) / sizeof(head[0]); i++){
			RY_list_control.InsertItem(i, head[i], 100);
		}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void SET_JLGS_RY::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码

	m_listSelPos = RY_list_control.GetSelectionMark();


	title = RY_list_control.GetItemText(m_listSelPos, 0); //获取当前记录的显示的文本

	

	*pResult = 0;
}
