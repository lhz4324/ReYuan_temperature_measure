// SET_YPXX.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "SET_YPXX.h"
#include "afxdialogex.h"



// SET_YPXX �Ի���

IMPLEMENT_DYNAMIC(SET_YPXX, CDialogEx)

SET_YPXX::SET_YPXX(CWnd* pParent /*=NULL*/)
	: CDialogEx(SET_YPXX::IDD, pParent)
	, SET_YPXX_YPMC(_T(""))
	, SET_YPXX_GG(_T(""))
	, SET_YPXX_GSRY(_T(""))
	, SET_YPXX_JL(_T(""))
{
	list_row_index = 0;//���캯����ʼ��
}

SET_YPXX::~SET_YPXX()
{
}

void SET_YPXX::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, 1037, SET_YPXX_LIST);
	DDX_Text(pDX, 1000, SET_YPXX_YPMC);
	DDX_Text(pDX, 1001, SET_YPXX_GG);
	DDX_Text(pDX, 1004, SET_YPXX_GSRY);
	DDX_Control(pDX, 1000, YPMC_control);
	DDX_Control(pDX, 1001, GG_control);
	DDX_Control(pDX, 1004, GSRY_control);
	DDX_Text(pDX, 1002, SET_YPXX_JL);
	DDX_Control(pDX, 1002, JL_control);
}


BEGIN_MESSAGE_MAP(SET_YPXX, CDialogEx)
	ON_BN_CLICKED(1003, &SET_YPXX::OnBnClicked1003)
	ON_BN_CLICKED(1006, &SET_YPXX::OnBnClicked1006)
	ON_NOTIFY(NM_CLICK, 1037, &SET_YPXX::OnNMClick1037)
	ON_BN_CLICKED(1005, &SET_YPXX::OnBnClicked1005)
	ON_BN_CLICKED(1007, &SET_YPXX::OnBnClicked1007)
END_MESSAGE_MAP()


// SET_YPXX ��Ϣ�������


BOOL SET_YPXX::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	//��һ�δ����б����ݣ���ʽ������
	SET_YPXX_LIST.SetExtendedStyle(SET_YPXX_LIST.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	
	//��һ�γ�ʼ����ͷ����
	CString head[] = { TEXT("����Ʒ����"), TEXT("���"), TEXT("����"), TEXT("������Һ������") };
	SET_YPXX_LIST.InsertColumn(0, head[0], LVCFMT_LEFT, 100);
	SET_YPXX_LIST.InsertColumn(1, head[1], LVCFMT_LEFT, 100);
	SET_YPXX_LIST.InsertColumn(2, head[2], LVCFMT_LEFT, 100);
	SET_YPXX_LIST.InsertColumn(3, head[3], LVCFMT_LEFT, 100);
	

		vec_YPXX.clear();//��������Ӳ˵���Ʒ�����Ӳ˵��ظ�����
		int ress = mysql_query(&myonlydatabase.m_sqlCon, "select * from ��Ʒ��Ϣ");//���������
		if (!ress)
		{
			myonlydatabase.res = mysql_store_result(&myonlydatabase.m_sqlCon);
			if (myonlydatabase.res)
			{
				for (int i = 0; i < myonlydatabase.res->row_count; i++){//�����ݿ������ݲ�����
					myonlydatabase.row = mysql_fetch_row(myonlydatabase.res);
					CString str0(myonlydatabase.row[0]);
					CString str1(myonlydatabase.row[1]);
					CString str2(myonlydatabase.row[2]);
					CString str3(myonlydatabase.row[3]);

					SET_YPXX_LIST.InsertItem(i, str0);//��һ���õ���insert����������set
					SET_YPXX_LIST.SetItemText(i, 1, str1);
					SET_YPXX_LIST.SetItemText(i, 2, str2);
					SET_YPXX_LIST.SetItemText(i, 3, str3);//�ѻ�ȡ���������ݲ��ȥ

					YangPinXinXi ypxx;
					ypxx.YPXX_YPMC = str0;
					ypxx.YPXX_GG = str1;
					ypxx.YPXX_JL = str2;
					ypxx.YPXX_GSRY = str3;

					vec_YPXX.push_back(ypxx);

				}
			}

		}

		mysql_free_result(myonlydatabase.res);





	//���洦���ĸ��༭��
	SET_YPXX_YPMC = TEXT("");
	UpdateData(FALSE);


	SET_YPXX_JL = TEXT("");
	UpdateData(FALSE);

	SET_YPXX_GG = TEXT("");
	UpdateData(FALSE);

	SET_YPXX_GSRY = TEXT("");




	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void SET_YPXX::OnBnClicked1003()//���Ӱ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);//��update������֤�༭���и��ĺ������Ҳ���Ա������б�ÿһ�涼����


	/*********************************************������*********************************************/

	
	YangPinXinXi ypxx;
	ypxx.YPXX_YPMC = SET_YPXX_YPMC;
	ypxx.YPXX_GG = SET_YPXX_GG;
	ypxx.YPXX_JL = SET_YPXX_JL;
	ypxx.YPXX_GSRY = SET_YPXX_GSRY;

	vec_YPXX.push_back(ypxx);


	int pos; //��ӵ�λ��
	pos = SET_YPXX_LIST.GetItemCount();
	SET_YPXX_LIST.InsertItem(pos, ypxx.YPXX_YPMC);//��һ���õ���insert����������set
	SET_YPXX_LIST.SetItemText(pos, 1, ypxx.YPXX_GG);
	SET_YPXX_LIST.SetItemText(pos, 2, ypxx.YPXX_JL);
	SET_YPXX_LIST.SetItemText(pos, 3, ypxx.YPXX_GSRY);//�ѻ�ȡ���������ݲ��ȥ

	UpdateData(FALSE);

	
	USES_CONVERSION;

	myonlydatabase.add_yangpinxinxi_mydatabase(T2A(SET_YPXX_YPMC), T2A(SET_YPXX_GG), T2A(SET_YPXX_JL), T2A(SET_YPXX_GSRY));



	


}


void SET_YPXX::OnBnClicked1006()//ɾ����ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
		CString str;
		
		str = TEXT("ȷ��ɾ������������");
		if (IDYES == AfxMessageBox(str, MB_YESNO | MB_ICONQUESTION))
		{
			SET_YPXX_LIST.DeleteItem(m_listSelPos);//ɾ����������
		}

			
		vec_YPXX.erase(vec_YPXX.begin() + m_listSelPos);     //ɾ��vec_YPXX�ж�ӦԪ��


		USES_CONVERSION;

		myonlydatabase.delete_yangpinxinxi_mydatabase(T2A(SET_YPXX_YPMC)); //ɾ�����ݿ��ж�ӦԪ��




}


void SET_YPXX::OnNMClick1037(NMHDR *pNMHDR, LRESULT *pResult)//ѡ���б��ĳ�У���������ͬ�����ı��༭��
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_listSelPos = SET_YPXX_LIST.GetSelectionMark();
	
	SET_YPXX_YPMC = SET_YPXX_LIST.GetItemText(m_listSelPos, 0); //��ȡ��ǰ��¼����ʾ���ı�
	YPMC_control.SetWindowTextW(SET_YPXX_YPMC);//������cedit���͵Ĳ��ܵ��������
	
	SET_YPXX_GG = SET_YPXX_LIST.GetItemText(m_listSelPos, 1);
	GG_control.SetWindowTextW(SET_YPXX_GG);

	
	SET_YPXX_JL = SET_YPXX_LIST.GetItemText(m_listSelPos, 2);
	JL_control.SetWindowTextW(SET_YPXX_JL);


	SET_YPXX_GSRY = SET_YPXX_LIST.GetItemText(m_listSelPos, 3);
	GSRY_control.SetWindowTextW(SET_YPXX_GSRY);
	
	
	*pResult = 0;
}


void SET_YPXX::OnBnClicked1005()//�޸İ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
		
		
	//�������ݴ��͸�����Ի���ʵ����Ϣ���޸�
	UpdateData(true); //�ѶԻ����е���Ϣ���µ��ڴ���ȥ
	SET_YPXX_LIST.SetItemText(m_listSelPos, 0, SET_YPXX_YPMC);
	vec_YPXX[m_listSelPos].YPXX_YPMC = SET_YPXX_YPMC;

	SET_YPXX_LIST.SetItemText(m_listSelPos, 1, SET_YPXX_GG);
	vec_YPXX[m_listSelPos].YPXX_GG = SET_YPXX_GG;
	
	//SET_YPXX_GG.Format(_T("%.2f"), SET_YPXX_JL);//��������ʽת����Cstring���� �Ѿ�û�õ���Ʒ��Ϣ���� ��֮�������Ʒ��Ϣ����
	SET_YPXX_LIST.SetItemText(m_listSelPos, 2, SET_YPXX_JL);
	vec_YPXX[m_listSelPos].YPXX_JL = SET_YPXX_JL;

	SET_YPXX_LIST.SetItemText(m_listSelPos, 3, SET_YPXX_GSRY);
	vec_YPXX[m_listSelPos].YPXX_GSRY = SET_YPXX_GSRY;

	UpdateData(FALSE);



	USES_CONVERSION;

	

	myonlydatabase.change_yangpinxinxi_mydatabase(T2A(SET_YPXX_YPMC), T2A(SET_YPXX_GG), T2A(SET_YPXX_JL), T2A(SET_YPXX_GSRY));

	



	
	

}


void SET_YPXX::OnBnClicked1007()//ȡ����ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CDialogEx::OnCancel();
}
