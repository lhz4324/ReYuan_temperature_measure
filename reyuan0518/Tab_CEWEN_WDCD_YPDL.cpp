// Tab_CEWEN_WDCD_YPDL.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "Tab_CEWEN_WDCD_YPDL.h"
#include "afxdialogex.h"
#include "Quanjv.h"


//#include "MyDatabase.h"
// Tab_CEWEN_WDCD_YPDL �Ի���

IMPLEMENT_DYNAMIC(Tab_CEWEN_WDCD_YPDL, CDialogEx)

Tab_CEWEN_WDCD_YPDL::Tab_CEWEN_WDCD_YPDL(CWnd* pParent /*=NULL*/)
: CDialogEx(Tab_CEWEN_WDCD_YPDL::IDD, pParent)
, YPDL_ph_CString(_T(""))
, YPDL_yptgdw_CString(_T(""))
, YPDL_ypbh_CString(_T(""))
, YPDL_GG_CString(_T(""))
, YPDL_JL_CString(_T(""))
, YPDL_GSPMC_CString(_T(""))
, YPDL_SYFF_CString(_T(""))
{

}

Tab_CEWEN_WDCD_YPDL::~Tab_CEWEN_WDCD_YPDL()
{
}

void Tab_CEWEN_WDCD_YPDL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, YPDL_list_control);
	//  DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Control(pDX, IDC_COMBO2, GSPMC_comboxcontrol);
	DDX_Control(pDX, IDC_EDIT5, YPDL_ph_control);
	DDX_Control(pDX, IDC_EDIT3, YPDL_yptgdw_control);
	DDX_Control(pDX, IDC_EDIT1, YPDL_ypbh_control);
	DDX_Text(pDX, IDC_EDIT5, YPDL_ph_CString);
	DDX_Text(pDX, IDC_EDIT3, YPDL_yptgdw_CString);
	DDX_Text(pDX, IDC_EDIT1, YPDL_ypbh_CString);
	DDX_Control(pDX, IDC_EDIT12, YPDL_GG_control);
	DDX_Control(pDX, IDC_EDIT13, YPDL_JL_control);
	DDX_Text(pDX, IDC_EDIT12, YPDL_GG_CString);
	DDX_Text(pDX, IDC_EDIT13, YPDL_JL_CString);
	DDX_CBString(pDX, IDC_COMBO2, YPDL_GSPMC_CString);
	DDX_CBString(pDX, IDC_COMBO1, YPDL_SYFF_CString);
	DDX_Control(pDX, IDC_COMBO1, SYFF_comboxcontrol);
}


BEGIN_MESSAGE_MAP(Tab_CEWEN_WDCD_YPDL, CDialogEx)
	
	ON_CBN_SELCHANGE(IDC_COMBO1, &Tab_CEWEN_WDCD_YPDL::OnCbnSelchangeCombo1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &Tab_CEWEN_WDCD_YPDL::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON5, &Tab_CEWEN_WDCD_YPDL::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &Tab_CEWEN_WDCD_YPDL::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Tab_CEWEN_WDCD_YPDL::OnBnClickedButton4)
	ON_CBN_SELCHANGE(IDC_COMBO2, &Tab_CEWEN_WDCD_YPDL::OnCbnSelchangeCombo2)
END_MESSAGE_MAP()


// Tab_CEWEN_WDCD_YPDL ��Ϣ�������


BOOL Tab_CEWEN_WDCD_YPDL::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	
	//������Ʒ��Ϣ���ݿ⣬��ȡ������vector����
		vec_YPXX.clear();//��������Ӳ˵���Ʒ�����Ӳ˵��ظ�����
		int ress = mysql_query(&myonlydatabase.m_sqlCon, "select * from ��Ʒ��Ϣ");//���������
		if (!ress)
		{
			myonlydatabase.res = mysql_store_result(&myonlydatabase.m_sqlCon);
			if (myonlydatabase.res)
			{
				for (int i = 0; i < myonlydatabase.res->row_count; i++) {//�����ݿ������ݲ�����
					myonlydatabase.row = mysql_fetch_row(myonlydatabase.res);
					CString str0(myonlydatabase.row[0]);
					CString str1(myonlydatabase.row[1]);
					CString str2(myonlydatabase.row[2]);
					CString str3(myonlydatabase.row[3]);

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
	
	







	
	//�ж�vector�����Ƿ�Ϊ�գ����յĻ������ݼ��룬�����ù���Ʒ�����������ѡ��
	if (!vec_YPXX.empty()) {


		for (int i = 0; i < vec_YPXX.size(); i++) {
			CString str;
			str.Format(vec_YPXX[i].YPXX_YPMC + TEXT("-") + vec_YPXX[i].YPXX_GG + TEXT("-") + vec_YPXX[i].YPXX_JL + TEXT("ml/kg"));
			GSPMC_comboxcontrol.AddString(str);//���ù���Ʒ�����������ѡ��
		}

	}

	


	//�������鷽���������ѡ��
	SYFF_comboxcontrol.AddString(TEXT("ChP������ѡ"));
	SYFF_comboxcontrol.AddString(TEXT("ChP����"));
	SYFF_comboxcontrol.AddString(TEXT("ChP����"));
	SYFF_comboxcontrol.AddString(TEXT("USP������ѡ"));
	SYFF_comboxcontrol.AddString(TEXT("USP����"));
	SYFF_comboxcontrol.AddString(TEXT("USP����"));
	SYFF_comboxcontrol.AddString(TEXT("EP������ѡ"));
	SYFF_comboxcontrol.AddString(TEXT("EP��һ��"));
	SYFF_comboxcontrol.AddString(TEXT("EP�ڶ���"));
	SYFF_comboxcontrol.AddString(TEXT("EP������"));
	SYFF_comboxcontrol.AddString(TEXT("EP���Ĵ�"));


	//��һ�δ����б����ݣ���ʽ������
	YPDL_list_control.SetExtendedStyle(YPDL_list_control.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	//��һ�γ�ʼ����ͷ����
	CString head1[] = { TEXT("����Ʒ����"), TEXT("��Ʒ���"), TEXT("����"), TEXT("��Ʒ�ṩ��λ"), TEXT("���"), TEXT("����"), TEXT("���鷽��"), TEXT("��ǰ�����ܺ�"), TEXT("��ǰ����ֻ��") };

	for (int i = 0; i < sizeof(head1) / sizeof(head1[0]); i++){//���β���
		YPDL_list_control.InsertColumn(i, head1[i], LVCFMT_LEFT, 100);
		}

	
	

	//���� ��̽ͷ����صı�ͷ����
	CString head2[] = { TEXT("̽ͷ��"), TEXT("����"), TEXT("ƿ��"), TEXT("ע�俪ʼʱ��"), TEXT("ע�����ʱ��") };

	
	int column_num = 9;
	for(int i = 0; i < PointNum; i++){
		for (int j = 0; j < 5; j++){
			CString str;
			str.Format(head2[j]+" % d", i+1);
			YPDL_list_control.InsertColumn(column_num++, str, LVCFMT_LEFT, 100);
		}
		
	}//����ѭ����������ͷ�������


	//����Ʒ������Ϣ��ʼ�������
	int ress2 = mysql_query(&myonlydatabase.m_sqlCon, "select * from ��Ʒ����");//���������
	if (!ress2)
	{
		myonlydatabase.res = mysql_store_result(&myonlydatabase.m_sqlCon);
		if (myonlydatabase.res)
		{
			for (int i = 0; i < myonlydatabase.res->row_count; i++) {//�����ݿ������ݲ�����
				myonlydatabase.row = mysql_fetch_row(myonlydatabase.res);
				CString str0(myonlydatabase.row[0]);//����Ʒ����
				CString str1(myonlydatabase.row[1]);//��Ʒ���
				CString str2(myonlydatabase.row[2]);//����
				CString str3(myonlydatabase.row[3]);//��Ʒ�ṩ��λsql`
				CString str4(myonlydatabase.row[4]);//���sql
				CString str5(myonlydatabase.row[5]);//����sql
				CString str6(myonlydatabase.row[6]);//ʵ�鷽��sql
				CString str7(myonlydatabase.row[7]);//��ǰ�����ܺ�sql`
				CString str8(myonlydatabase.row[8]);//��ǰ����ֻ��sql`

				YPDL_list_control.InsertItem(i, str0);//��һ���õ���insert����������set
				YPDL_list_control.SetItemText(i, 1, str1);
				YPDL_list_control.SetItemText(i, 2, str2);
				YPDL_list_control.SetItemText(i, 3, str3);
				YPDL_list_control.SetItemText(i, 4, str4);
				YPDL_list_control.SetItemText(i, 5, str5);
				YPDL_list_control.SetItemText(i, 6, str6);//�ѻ�ȡ���������ݲ��ȥ

			}
		}


	}

	mysql_free_result(myonlydatabase.res);





	CRect rect1;
	GetDlgItem(10222)->GetWindowRect(&rect1);
	//ת��Ϊ�Ի����ϵ����λ��
	ScreenToClient(rect1);

	CRect rect2;
	GetDlgItem(IDC_COMBO1)->GetWindowRect(&rect2);
	//ת��Ϊ�Ի����ϵ����λ��
	ScreenToClient(rect2);



	CRect text_rect;
	int left_static = rect1.left + 30;
	int right_static = rect1.left + 50 + 30;
	int top_static = rect1.top;
	int bottom_static = rect1.bottom;

	text_rect.left = rect1.left + 150;
	text_rect.right = rect1.left + 200 + 150;
	text_rect.bottom = rect1.bottom;
	text_rect.top = rect1.top;



		p_Myedit[0] = NewMyEdit(10100, CRect(text_rect.left, rect2.top, text_rect.right, rect2.bottom), 0);
	
		p_Myedit[1] = NewMyEdit(10101, CRect(text_rect.left, rect2.top, text_rect.right, rect2.bottom), 0);
	
		p_Myedit[2] = NewMyEdit(10102, CRect(text_rect.left, rect2.top, text_rect.right, rect2.bottom), 0);

		p_Myedit[3] = NewMyEdit(10103, CRect(text_rect.left, rect2.top, text_rect.right, rect2.bottom), 0);
	
		p_Myedit[4] = NewMyEdit(10104, CRect(text_rect.left, rect2.top, text_rect.right, rect2.bottom), 0);

		p_Myedit[5] = NewMyEdit(10105, CRect(text_rect.left, rect2.top + 65, text_rect.right, rect2.bottom + 65), 0);


		CRect rect3;
		GetDlgItem(10000)->GetWindowRect(&rect3);
		//ת��Ϊ�Ի����ϵ����λ��
		ScreenToClient(rect3);

	
		for (int i = 0; i < 6; i++) {

			GetDlgItem(10000 + i)->MoveWindow(rect3);
			GetDlgItem(10000+i)->ShowWindow(SW_HIDE);

			
			GetDlgItem(10100 + i)->ShowWindow(SW_HIDE);
		}
		
		GetDlgItem(10000 + 5)->MoveWindow(CRect(text_rect.left, rect2.top + 50, text_rect.right, rect2.bottom + 50));


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}





void Tab_CEWEN_WDCD_YPDL::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������


	int index = SYFF_comboxcontrol.GetCurSel();

	CString str;
	SYFF_comboxcontrol.GetLBText(index, str);//�������ؼ��еı�ѡ���һ���str




	for (int i = 0; i < 6; i++) {
		GetDlgItem(10000 + i)->ShowWindow(SW_HIDE);
		GetDlgItem(10100 + i)->ShowWindow(SW_HIDE);
	}
	

	if (str == _T("ChP����")) {

		
		GetDlgItem(10000 )->ShowWindow(SW_SHOW);
		GetDlgItem(10100 )->ShowWindow(SW_SHOW);



	}else if (str == _T("EP�ڶ���")) {

		GetDlgItem(10000 +1)->ShowWindow(SW_SHOW);
		GetDlgItem(10100 + 1)->ShowWindow(SW_SHOW);
	}
	else if (str == _T("EP������")) {

		GetDlgItem(10000 + 2)->ShowWindow(SW_SHOW);
		GetDlgItem(10100 + 2)->ShowWindow(SW_SHOW);
	}
	else if (str == _T("EP���Ĵ�")) {

		GetDlgItem(10000 + 3)->ShowWindow(SW_SHOW);
		GetDlgItem(10100 + 3)->ShowWindow(SW_SHOW);
	}
	else if (str == _T("USP����")) {

		GetDlgItem(10000 + 4)->ShowWindow(SW_SHOW);
		GetDlgItem(10100 + 4)->ShowWindow(SW_SHOW);

		GetDlgItem(10000 + 5)->ShowWindow(SW_SHOW);
		GetDlgItem(10100 + 5)->ShowWindow(SW_SHOW);

	}
	else {



	}




}


void Tab_CEWEN_WDCD_YPDL::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)//ѡ���б��ĳ�У���������ͬ�����ı��༭��
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������


	m_listSelPos = YPDL_list_control.GetSelectionMark();

	YPDL_GSPMC_CString = YPDL_list_control.GetItemText(m_listSelPos, 0); //��ȡ��ǰ��¼����ʾ���ı�
	GSPMC_comboxcontrol.SetWindowTextW(YPDL_GSPMC_CString);//������cedit���͵Ĳ��ܵ��������

	YPDL_ypbh_CString = YPDL_list_control.GetItemText(m_listSelPos, 1);
	YPDL_ypbh_control.SetWindowTextW(YPDL_ypbh_CString);


	YPDL_ph_CString = YPDL_list_control.GetItemText(m_listSelPos, 2);
	YPDL_ph_control.SetWindowTextW(YPDL_ph_CString);


	YPDL_yptgdw_CString = YPDL_list_control.GetItemText(m_listSelPos, 3);
	YPDL_yptgdw_control.SetWindowTextW(YPDL_yptgdw_CString);

	YPDL_GG_CString = YPDL_list_control.GetItemText(m_listSelPos, 4);
	YPDL_GG_control.SetWindowTextW(YPDL_GG_CString);

	YPDL_JL_CString = YPDL_list_control.GetItemText(m_listSelPos, 5);
	YPDL_JL_control.SetWindowTextW(YPDL_JL_CString);

	YPDL_SYFF_CString = YPDL_list_control.GetItemText(m_listSelPos, 6); 
	SYFF_comboxcontrol.SetWindowTextW(YPDL_SYFF_CString);

	*pResult = 0;
}


void Tab_CEWEN_WDCD_YPDL::OnBnClickedButton5()//ɾ��
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;

	str = TEXT("ȷ��ɾ������������");
	if (IDYES == AfxMessageBox(str, MB_YESNO | MB_ICONQUESTION))
	{
		YPDL_list_control.DeleteItem(m_listSelPos);//ɾ����������
	}


	USES_CONVERSION;

	myonlydatabase.delete_yangpinduilie_mydatabase(T2A(YPDL_GSPMC_CString)); //ɾ�����ݿ��ж�ӦԪ��


}


void Tab_CEWEN_WDCD_YPDL::OnBnClickedButton1()//����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);

	int pos; //��ӵ�λ��
	pos = YPDL_list_control.GetItemCount();

	CString str;
	if (!vec_YPXX.empty()){
		int index = GSPMC_comboxcontrol.GetCurSel();
		
		GSPMC_comboxcontrol.GetLBText(index, str);//�������ؼ��еı�ѡ���һ���str

		YPDL_list_control.InsertItem(pos, str);//��һ���õ���insert����������set

	}
	else
	{
		YPDL_list_control.InsertItem(pos, YPDL_GSPMC_CString);
	}

	//�ѻ�ȡ���������ݲ��ȥ
	YPDL_list_control.SetItemText(pos, 1, YPDL_ypbh_CString);
	YPDL_list_control.SetItemText(pos, 2, YPDL_ph_CString);
	YPDL_list_control.SetItemText(pos, 3, YPDL_yptgdw_CString);
	YPDL_list_control.SetItemText(pos, 4, YPDL_GG_CString);
	YPDL_list_control.SetItemText(pos, 5, YPDL_JL_CString);
	YPDL_list_control.SetItemText(pos, 6, YPDL_SYFF_CString);
	

	CString str_cqswzh;//��ǰ�����ܺ�
	CString str_cqcwzs;//��ǰ����ֻ��
	


	if (YPDL_SYFF_CString == _T("ChP����")) {
		GetDlgItem(10100)->GetWindowText(str_cqswzh);
		str_cqcwzs = _T("0");
	}

	else if (YPDL_SYFF_CString == _T("EP�ڶ���")) {

		GetDlgItem(10101)->GetWindowText(str_cqswzh);
		str_cqcwzs = _T("0");
	}
	else if (YPDL_SYFF_CString == _T("EP������")) {

		GetDlgItem(10102)->GetWindowText(str_cqswzh);
		str_cqcwzs = _T("0");
	}
	else if (YPDL_SYFF_CString == _T("EP���Ĵ�")) {

		GetDlgItem(10103)->GetWindowText(str_cqswzh);
		str_cqcwzs = _T("0");
	}
	else if (YPDL_SYFF_CString == _T("USP����")) {

		GetDlgItem(10104)->GetWindowText(str_cqswzh);
		GetDlgItem(10105)->GetWindowText(str_cqcwzs);

	}
	else {
		str_cqswzh = _T("0");
		str_cqcwzs = _T("0");
	}

	YPDL_list_control.SetItemText(pos, 7, str_cqswzh);
	YPDL_list_control.SetItemText(pos, 8, str_cqcwzs);


	USES_CONVERSION;

	//���Ŀǰ��û�мӴ�ǰ�����ܺ�
	myonlydatabase.add_yangpinduilie_mydatabase(T2A(str), T2A(YPDL_ypbh_CString), T2A(YPDL_ph_CString), T2A(YPDL_yptgdw_CString), T2A(YPDL_GG_CString), T2A(YPDL_JL_CString), T2A(YPDL_SYFF_CString));
	

}


void Tab_CEWEN_WDCD_YPDL::OnBnClickedButton4()//�޸�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//�������ݴ��͸�����Ի���ʵ����Ϣ���޸�
	UpdateData(true); //�ѶԻ����е���Ϣ���µ��ڴ���ȥ

	
	YPDL_list_control.SetItemText(m_listSelPos, 0,YPDL_GSPMC_CString);
	//vec_YPXX[m_listSelPos].YPXX_YPMC = SET_YPXX_YPMC;

	YPDL_list_control.SetItemText(m_listSelPos, 1, YPDL_ypbh_CString);
	//vec_YPXX[m_listSelPos].YPXX_GG = SET_YPXX_GG;

	//SET_YPXX_GG.Format(_T("%.2f"), SET_YPXX_JL);//��������ʽת����Cstring���� �Ѿ�û�õ���Ʒ��Ϣ���� ��֮�������Ʒ��Ϣ����
	YPDL_list_control.SetItemText(m_listSelPos, 2, YPDL_ph_CString);
	//vec_YPXX[m_listSelPos].YPXX_JL = SET_YPXX_JL;

	YPDL_list_control.SetItemText(m_listSelPos, 3, YPDL_yptgdw_CString);
	//vec_YPXX[m_listSelPos].YPXX_GSRY = SET_YPXX_GSRY;

	YPDL_list_control.SetItemText(m_listSelPos, 4, YPDL_GG_CString);

	YPDL_list_control.SetItemText(m_listSelPos, 5, YPDL_JL_CString);

	YPDL_list_control.SetItemText(m_listSelPos, 6, YPDL_SYFF_CString);

	USES_CONVERSION;

	myonlydatabase.change_yangpinduilie_mydatabase(T2A(YPDL_GSPMC_CString), T2A(YPDL_ypbh_CString), T2A(YPDL_ph_CString), T2A(YPDL_yptgdw_CString), T2A(YPDL_GG_CString), T2A(YPDL_JL_CString), T2A(YPDL_SYFF_CString));


}


void Tab_CEWEN_WDCD_YPDL::OnCbnSelchangeCombo2()//������Ʒ�����������л�ʱ����Ӧ�Ĺ�������Ҫ�л�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	int index = GSPMC_comboxcontrol.GetCurSel();

	CString str;
	GSPMC_comboxcontrol.GetLBText(index, str);//�������ؼ��еı�ѡ���һ���str


		

	YPDL_GG_control.SetWindowTextW(vec_YPXX[index].YPXX_GG);//�л����
	YPDL_JL_control.SetWindowTextW(vec_YPXX[index].YPXX_JL);//�л�����



}

CEdit* Tab_CEWEN_WDCD_YPDL::NewMyEdit(int nID, CRect rect, int nStyle)
{
	CString m_Caption;
	m_Caption.LoadString(nID); //ȡ��ť����
	CEdit *p_Edit = new CEdit();
	ASSERT_VALID(p_Edit);
	p_Edit->Create(WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | nStyle, rect, this, nID);
	return p_Edit;
}



CStatic* Tab_CEWEN_WDCD_YPDL::NewMyText(int nID, CRect rect, int nStyle)
{
	CString m_Caption;
	m_Caption.LoadString(nID); //ȡ��ť����
	m_Caption.Format(_T("%d"), nID - 10000);


	
	CStatic *p_Text = new CStatic();


	ASSERT_VALID(p_Text);
	p_Text->Create(m_Caption, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | nStyle, rect, this, nID);  //������ť

	

	return p_Text;
}