// LOGIN_SET_DLCL.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "LOGIN_SET_DLCL.h"
#include "afxdialogex.h"

#include "Quanjv.h"
// LOGIN_SET_DLCL �Ի���

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


// LOGIN_SET_DLCL ��Ϣ�������


void LOGIN_SET_DLCL::OnBnClickedButton1()//Ӧ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	/*char hostname[128];
	gethostname(hostname, 128);
	CString str(hostname);//��ȡ�����豸����
	MessageBox(str);*/

	if (((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		LPWSTR current_computer_username_temp;
		current_computer_username_temp = (LPWSTR)malloc(100);
		DWORD dw = 100;
		GetUserName(current_computer_username_temp, &dw);
		CString str(current_computer_username_temp);
		current_computer_username = str;//��ȫ�ֱ�����ǰ�����û�����ֵ
		
		//MessageBox(str);
	}

	current_computer_username_selected = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck();
	MessageBox(TEXT("���óɹ���"));

}
