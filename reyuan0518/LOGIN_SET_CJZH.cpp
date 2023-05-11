// LOGIN_SET_CJZH.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "LOGIN_SET_CJZH.h"
#include "afxdialogex.h"

#include "ACCOUNT_ZHGL_TJZH.h"
#include "ACCOUNT_ZHGL_XGZH.h"
#include "Quanjv.h"
//#include "MyDatabase.h"
// LOGIN_SET_CJZH �Ի���

IMPLEMENT_DYNAMIC(LOGIN_SET_CJZH, CDialogEx)

LOGIN_SET_CJZH::LOGIN_SET_CJZH(CWnd* pParent /*=NULL*/)
: CDialogEx(LOGIN_SET_CJZH::IDD, pParent)
{

}

LOGIN_SET_CJZH::~LOGIN_SET_CJZH()
{
}

void LOGIN_SET_CJZH::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mlist_control);
}


BEGIN_MESSAGE_MAP(LOGIN_SET_CJZH, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LOGIN_SET_CJZH::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &LOGIN_SET_CJZH::OnBnClickedButton2)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &LOGIN_SET_CJZH::OnNMClickList1)
END_MESSAGE_MAP()


// LOGIN_SET_CJZH ��Ϣ�������


void LOGIN_SET_CJZH::OnBnClickedButton1()//����˻�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	ACCOUNT_ZHGL_TJZH tjzh;
	
	tjzh.DoModal();

}


void LOGIN_SET_CJZH::OnBnClickedButton2()//�޸��˻�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	ACCOUNT_ZHGL_XGZH xgzh;
	
	xgzh.DoModal();

}


BOOL LOGIN_SET_CJZH::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//��һ�δ����б����ݣ���ʽ������
	mlist_control.SetExtendedStyle(mlist_control.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	//��һ�γ�ʼ����ͷ����
	CString head[] = { TEXT("�˻�"), TEXT("Ȩ�޵ȼ�"), TEXT("��ɫ"), TEXT("���ε�¼��������"), TEXT("�˻�����"), TEXT("�¶Ȳⶨ"), TEXT("��Ʒ��Ϣ����"), TEXT("��¼��ʽ����"), TEXT("�鿴̽ͷ���"), TEXT("�鿴������ѡ���"), TEXT("��ѯ����ӡ��ԭ���"), TEXT("���ݱ���"), TEXT("�궨̽ͷ"), TEXT("�趨ʵʱ������������"), TEXT("�����������"), TEXT("���ݸ�ʽ����"), TEXT("�鿴��ѡ����"), TEXT("����ά��"), TEXT("�˻�����") };
	for(int i = 0; i < sizeof(head) / sizeof(head[0]); i++){
		mlist_control.InsertColumn(i, head[i], LVCFMT_LEFT, 100);

	}


	//�����ݿ����˻���Ϣ��ʼ���������
		int ress = mysql_query(&myonlydatabase.m_sqlCon, "select * from �û��˺�����");//���������
		if (!ress)
		{
			myonlydatabase.res = mysql_store_result(&myonlydatabase.m_sqlCon);
			if (myonlydatabase.res)
			{
				for (int i = 0; i < myonlydatabase.res->row_count; i++){//�����ݿ������ݲ�����
					myonlydatabase.row = mysql_fetch_row(myonlydatabase.res);
					CString str0(myonlydatabase.row[0]);
					CString str1(myonlydatabase.row[3]);
					CString str2(myonlydatabase.row[2]);
	

					mlist_control.InsertItem(i, str0);//��һ���õ���insert����������set
					mlist_control.SetItemText(i, 1, str1);
					mlist_control.SetItemText(i, 2, str2);

					for (int j = 3; j < sizeof(head) / sizeof(head[0]); j++){

						CString str(myonlydatabase.row[j+1]);
						mlist_control.SetItemText(i, j, str);
					}


				}
			}

		}
	




	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void LOGIN_SET_CJZH::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_listSelPos = mlist_control.GetSelectionMark();
	
	selected_current_name=mlist_control.GetItemText(m_listSelPos, 0);//������cedit���͵Ĳ��ܵ��������




	*pResult = 0;
}
