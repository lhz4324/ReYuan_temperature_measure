// LOGIN_SET_TTSZ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "LOGIN_SET_TTSZ.h"
#include "afxdialogex.h"

#include "Quanjv.h"
// LOGIN_SET_TTSZ �Ի���

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


// LOGIN_SET_TTSZ ��Ϣ�������


void LOGIN_SET_TTSZ::OnBnClickedButton3()//Ӧ�ð�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	int a;
	a = wcstol(m_Edit1, NULL, 10);
	PointNum = a;//��ȫ�ֱ���̽ͷ��ͳһ

	MessageBox(TEXT("Ӧ�óɹ���"));
	UpdateData(false);
}


void LOGIN_SET_TTSZ::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(true);

	
	CString ss;
	if (pNMUpDown->iDelta == -1) // �����ֵΪ-1 , ˵�������Spin�����µļ�ͷ
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
	else if (pNMUpDown->iDelta == 1) // �����ֵΪ1, ˵�������Spin�����ϵļ�ͷ
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_Spin.SetBuddy(GetDlgItem(IDC_EDIT1));
	m_Spin.SetRange(0, 100);

	CStatic* m_pStatic2 = (CStatic*)GetDlgItem(IDC_EDIT1);//static�ؼ������һ����������һ��ID����
	m_pStatic2->SetWindowText(TEXT("1"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
