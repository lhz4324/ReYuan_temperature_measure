// ACCOUNT_GGMM.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "ACCOUNT_GGMM.h"
#include "afxdialogex.h"
//#include "./mysql/mysql.h"

//#include "MyDatabase.h"
#include "Quanjv.h"
// ACCOUNT_GGMM �Ի���

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


// ACCOUNT_GGMM ��Ϣ�������


void ACCOUNT_GGMM::OnBnClicked1002()//�޸�����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(1000)->GetWindowText(current_password);//��ȡ�ı������ݡ�����ľ�����
	if (current_password != user_info_now.password_now){//�ж��Ƿ�һ��

		if (current_password == _T(""))AfxMessageBox(_T("����������룡"));
		else AfxMessageBox(_T("��ǰ���벻��ȷ�����������룡"));
	}
	else{//��һ�£��ٿ������������
		GetDlgItem(1001)->GetWindowText(new_password);//��ȡ�ı������ݡ������������
		GetDlgItem(1004)->GetWindowText(new_password_again);//��ȡ�ı������ݡ�����ĵڶ���������
		if (new_password == _T("") && new_password_again == _T("")){
			AfxMessageBox(_T("�����������룡"));
		}
		else{
			if (new_password != new_password_again){//��������������Ƿ�һ��
				AfxMessageBox(_T("����������벻һ�£����������룡"));
			}
			else{//�������Ϊ��������Ĵ���

				USES_CONVERSION;

				myonlydatabase.change_account_password_mydatabase(T2A(new_password), T2A(user_info_now.username_now));//��������
					
				
		}					
		}
	}





}


BOOL ACCOUNT_GGMM::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��


	CStatic* m_pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC_username_now);//static�ؼ������һ����������һ��ID���У����������õ�ǰ�˻�����
	m_pStatic2->SetWindowText(user_info_now.username_now);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}



