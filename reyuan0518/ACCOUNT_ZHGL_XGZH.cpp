// ACCOUNT_ZHGL_XGZH.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "ACCOUNT_ZHGL_XGZH.h"
#include "afxdialogex.h"
#include "Quanjv.h"
//#include "MyDatabase.h"
// ACCOUNT_ZHGL_XGZH �Ի���

IMPLEMENT_DYNAMIC(ACCOUNT_ZHGL_XGZH, CDialogEx)

ACCOUNT_ZHGL_XGZH::ACCOUNT_ZHGL_XGZH(CWnd* pParent /*=NULL*/)
	: CDialogEx(ACCOUNT_ZHGL_XGZH::IDD, pParent)
	, ACCOUNT_ZHGL_XGZH_juese(_T(""))
	, ACCOUNT_ZHGL_XGZH_password(_T(""))
{

}

ACCOUNT_ZHGL_XGZH::~ACCOUNT_ZHGL_XGZH()
{
}

void ACCOUNT_ZHGL_XGZH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, ACCOUNT_ZHGL_XGZH_juese);
	DDX_Text(pDX, IDC_EDIT3, ACCOUNT_ZHGL_XGZH_password);
}


BEGIN_MESSAGE_MAP(ACCOUNT_ZHGL_XGZH, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ACCOUNT_ZHGL_XGZH::OnBnClickedButton1)
END_MESSAGE_MAP()


// ACCOUNT_ZHGL_XGZH ��Ϣ�������


void ACCOUNT_ZHGL_XGZH::OnBnClickedButton1()//�޸İ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������


	
	GetDlgItem(IDC_EDIT3)->GetWindowText(ACCOUNT_ZHGL_XGZH_password);//��ȡ�ı������ݡ����������
	GetDlgItem(IDC_EDIT5)->GetWindowText(ACCOUNT_ZHGL_XGZH_juese);//��ȡ�ı������ݡ�����Ľ�ɫ


	
	


		UpdateData(true);

		//������checkbox�ؼ�ͬ����ȫ�ֱ���
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

		//���ı���������ͬ����ȫ�ֱ���
		user_info_now.username_now = selected_current_name;
		user_info_now.password_now = ACCOUNT_ZHGL_XGZH_password;
		user_info_now.juese_now = ACCOUNT_ZHGL_XGZH_juese;


		myonlydatabase.change_account(user_info_now);
		return;



	UpdateData(false);

}


BOOL ACCOUNT_ZHGL_XGZH::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	CStatic* m_pStatic1 = (CStatic*)GetDlgItem(IDC_EDIT1);

	m_pStatic1->SetWindowText(selected_current_name);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
