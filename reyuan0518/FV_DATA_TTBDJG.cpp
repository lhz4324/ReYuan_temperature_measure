// FV_DATA_TTBDJG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "FV_DATA_TTBDJG.h"

#include "Quanjv.h"

// FV_DATA_TTBDJG

IMPLEMENT_DYNCREATE(FV_DATA_TTBDJG, CFormView)

FV_DATA_TTBDJG::FV_DATA_TTBDJG()
	: CFormView(FV_DATA_TTBDJG::IDD)
{

}

FV_DATA_TTBDJG::~FV_DATA_TTBDJG()
{
}

void FV_DATA_TTBDJG::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, DATA_TTBDJG_list);
}

BEGIN_MESSAGE_MAP(FV_DATA_TTBDJG, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &FV_DATA_TTBDJG::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &FV_DATA_TTBDJG::OnBnClickedButton4)
END_MESSAGE_MAP()


// FV_DATA_TTBDJG ���

#ifdef _DEBUG
void FV_DATA_TTBDJG::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FV_DATA_TTBDJG::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FV_DATA_TTBDJG ��Ϣ�������


void FV_DATA_TTBDJG::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���



	//��һ�δ����б�����
	DATA_TTBDJG_list.SetExtendedStyle(DATA_TTBDJG_list.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	CString head[] = { TEXT("����"), TEXT("ʱ��"), TEXT("̽ͷ��"), TEXT("��һ��ʵ���¶�"), TEXT("��һ��ع��¶�"), TEXT("�ڶ���ʵ���¶�"), TEXT("�ڶ���ع��¶�"), TEXT("������ʵ���¶�"), TEXT("������ع��¶�"), TEXT("���ĵ�ʵ���¶�"), TEXT("���ĵ�ع��¶�"), TEXT("�����ʵ���¶�"), TEXT("�����ع��¶�"), TEXT("����") };

	for (int i = 0; i < sizeof(head) / sizeof(head[0]); i++) {
		DATA_TTBDJG_list.InsertColumn(i, head[i], LVCFMT_LEFT, 100);

	}


	//�����ݿ����˻���Ϣ��ʼ���������
		int ress = mysql_query(&myonlydatabase.m_sqlCon, "select * from ̽ͷ�궨��Ϣ");//���������
		if (!ress)
		{
			myonlydatabase.res = mysql_store_result(&myonlydatabase.m_sqlCon);
			if (myonlydatabase.res)
			{
				for (int i = 0; i < myonlydatabase.res->row_count; i++) {//�����ݿ������ݲ�����
					myonlydatabase.row = mysql_fetch_row(myonlydatabase.res);

					CString str0(myonlydatabase.row[0]);
			
					DATA_TTBDJG_list.InsertItem(i, str0);//��һ���õ���insert����������set
		

					for (int j = 1; j < sizeof(head) / sizeof(head[0])-1; j++) {

						CString str(myonlydatabase.row[j]);

						
						DATA_TTBDJG_list.SetItemText(i, j, str);
					}

					CString str(myonlydatabase.row[sizeof(head) / sizeof(head[0])-1]);

					if (str == TEXT("y"))
						DATA_TTBDJG_list.SetItemText(i, sizeof(head) / sizeof(head[0]) - 1, TEXT("�ϸ�"));
					else if (str == TEXT("n"))
						DATA_TTBDJG_list.SetItemText(i, sizeof(head) / sizeof(head[0]) - 1, TEXT("���ϸ�"));
					else
					{
						DATA_TTBDJG_list.SetItemText(i, sizeof(head) / sizeof(head[0]) - 1, TEXT(" "));
					}
				}
			}

		}
		mysql_free_result(myonlydatabase.res);


}


void FV_DATA_TTBDJG::OnBnClickedButton1()//��ӡԤ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void FV_DATA_TTBDJG::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
