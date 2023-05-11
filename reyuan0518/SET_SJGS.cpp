// SET_SJGS.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "SET_SJGS.h"
#include "afxdialogex.h"

#include "Quanjv.h"
// SET_SJGS �Ի���

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


// SET_SJGS ��Ϣ�������


BOOL SET_SJGS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��



	//���������������ѡ��
	TZ_duiyingcombo_control.AddString(TEXT("0"));
	TZ_duiyingcombo_control.AddString(TEXT("0.0"));
	TZ_duiyingcombo_control.AddString(TEXT("0.00"));
	TZ_duiyingcombo_control.AddString(TEXT("0.000"));

	//���ü����������ѡ��
	JL_duiyingcombo_control.AddString(TEXT("0"));
	JL_duiyingcombo_control.AddString(TEXT("0.0"));
	JL_duiyingcombo_control.AddString(TEXT("0.00"));

	//�����¶��������ѡ��
	WD_duiyingcombo_control.AddString(TEXT("0.0"));
	WD_duiyingcombo_control.AddString(TEXT("0.00"));


	//����radiobutton��ť����״̬
	((CButton *)GetDlgItem(1026))->SetCheck(TRUE); //ѡ��
	((CButton *)GetDlgItem(1027))->SetCheck(FALSE);//��ѡ��





	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void SET_SJGS::OnBnClicked1003()//ȡ����ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CDialogEx::OnCancel();
}


void SET_SJGS::OnBnClicked1002()//���水ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);


	//��ѡ�и�ʽ������ȫ�ֱ��� data_style_now
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
