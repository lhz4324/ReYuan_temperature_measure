// SET_JLGS_RY.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "SET_JLGS_RY.h"
#include "afxdialogex.h"

#include "SET_YL_JLGS.h"

#include "Quanjv.h"
// SET_JLGS_RY �Ի���

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


// SET_JLGS_RY ��Ϣ�������


void SET_JLGS_RY::OnBnClicked1002()//�޸İ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SET_YL_JLGS YL_JLGS;
	YL_JLGS.DoModal();
	
}


void SET_JLGS_RY::OnBnClicked1003()//�½���ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SET_YL_JLGS YL_JLGS;
	title = TEXT("�½�");
	YL_JLGS.DoModal();
	
}


BOOL SET_JLGS_RY::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	
	CString head[] = { TEXT("ChP����"), TEXT("ChP����"), TEXT("ChP������ѡ"), TEXT("EP��һ��"), TEXT("EP�ڶ���"), TEXT("EP������"), TEXT("EP���Ĵ�"), TEXT("EP������ѡ"), TEXT("USP����"), TEXT("USP����"),TEXT("USP������ѡ") };

	for (int i = 0; i < sizeof(head) / sizeof(head[0]); i++){
			RY_list_control.InsertItem(i, head[i], 100);
		}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void SET_JLGS_RY::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_listSelPos = RY_list_control.GetSelectionMark();


	title = RY_list_control.GetItemText(m_listSelPos, 0); //��ȡ��ǰ��¼����ʾ���ı�

	

	*pResult = 0;
}
