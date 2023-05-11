// LOGIN_SET_TTSZ.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "LOGIN_SET_TTSZ.h"
#include "afxdialogex.h"

#include "Quanjv.h"
// LOGIN_SET_TTSZ 对话框

IMPLEMENT_DYNAMIC(LOGIN_SET_TTSZ, CDialogEx)

LOGIN_SET_TTSZ::LOGIN_SET_TTSZ(CWnd* pParent /*=NULL*/)
	: CDialogEx(LOGIN_SET_TTSZ::IDD, pParent)
	, m_Edit1(_T(""))
{

}

LOGIN_SET_TTSZ::~LOGIN_SET_TTSZ()
{
}

void LOGIN_SET_TTSZ::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, m_Spin);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1);
}


BEGIN_MESSAGE_MAP(LOGIN_SET_TTSZ, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &LOGIN_SET_TTSZ::OnBnClickedButton3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &LOGIN_SET_TTSZ::OnDeltaposSpin1)
END_MESSAGE_MAP()


// LOGIN_SET_TTSZ 消息处理程序


void LOGIN_SET_TTSZ::OnBnClickedButton3()//应用按钮
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	int a;
	a = wcstol(m_Edit1, NULL, 10);
	PointNum = a;//将全局变量探头数统一

	MessageBox(TEXT("应用成功！"));
	UpdateData(false);
}


void LOGIN_SET_TTSZ::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(true);

	
	CString ss;
	if (pNMUpDown->iDelta == -1) // 如果此值为-1 , 说明点击了Spin的往下的箭头
	{
		/*double a;
		a = wcstod(m_Edit1, NULL) - 1;
		ss.Format(_T("%.1f"), a);*/
		int a;
		a = wcstol(m_Edit1, NULL,10) - 1;

		if (a >= 0){
			ss.Format(_T("%d"), a);
			m_Edit1 = ss;
		}
		

	}
	else if (pNMUpDown->iDelta == 1) // 如果此值为1, 说明点击了Spin的往上的箭头
	{
		//double a;
		//a = wcstod(m_Edit1, NULL) + 1;
		//ss.Format(_T("%.1f"), a);

		int a;
		a = wcstol(m_Edit1, NULL,10) + 1;
		ss.Format(_T("%d"), a);
		m_Edit1 = ss;
	}
	
	UpdateData(false);

	*pResult = 0;
}


BOOL LOGIN_SET_TTSZ::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_Spin.SetBuddy(GetDlgItem(IDC_EDIT1));
	m_Spin.SetRange(0, 100);

	CStatic* m_pStatic2 = (CStatic*)GetDlgItem(IDC_EDIT1);//static控件先添加一个变量，改一下ID就行
	m_pStatic2->SetWindowText(TEXT("1"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
