// Tab_CEWEN_WDCD_YPDL.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "Tab_CEWEN_WDCD_YPDL.h"
#include "afxdialogex.h"
#include "Quanjv.h"


//#include "MyDatabase.h"
// Tab_CEWEN_WDCD_YPDL 对话框

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


// Tab_CEWEN_WDCD_YPDL 消息处理程序


BOOL Tab_CEWEN_WDCD_YPDL::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	
	//连接样品信息数据库，获取内容至vector数组
		vec_YPXX.clear();//避免测温子菜单样品队列子菜单重复加载
		int ress = mysql_query(&myonlydatabase.m_sqlCon, "select * from 样品信息");//表里面查找
		if (!ress)
		{
			myonlydatabase.res = mysql_store_result(&myonlydatabase.m_sqlCon);
			if (myonlydatabase.res)
			{
				for (int i = 0; i < myonlydatabase.res->row_count; i++) {//将数据库里数据插进表格
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
	
	







	
	//判断vector数组是否为空，不空的话将数据加入，即设置供试品名称下拉框的选项
	if (!vec_YPXX.empty()) {


		for (int i = 0; i < vec_YPXX.size(); i++) {
			CString str;
			str.Format(vec_YPXX[i].YPXX_YPMC + TEXT("-") + vec_YPXX[i].YPXX_GG + TEXT("-") + vec_YPXX[i].YPXX_JL + TEXT("ml/kg"));
			GSPMC_comboxcontrol.AddString(str);//设置供试品名称下拉框的选项
		}

	}

	


	//设置试验方法下拉框的选项
	SYFF_comboxcontrol.AddString(TEXT("ChP新兔挑选"));
	SYFF_comboxcontrol.AddString(TEXT("ChP初试"));
	SYFF_comboxcontrol.AddString(TEXT("ChP复试"));
	SYFF_comboxcontrol.AddString(TEXT("USP新兔挑选"));
	SYFF_comboxcontrol.AddString(TEXT("USP初试"));
	SYFF_comboxcontrol.AddString(TEXT("USP复试"));
	SYFF_comboxcontrol.AddString(TEXT("EP新兔挑选"));
	SYFF_comboxcontrol.AddString(TEXT("EP第一次"));
	SYFF_comboxcontrol.AddString(TEXT("EP第二次"));
	SYFF_comboxcontrol.AddString(TEXT("EP第三次"));
	SYFF_comboxcontrol.AddString(TEXT("EP第四次"));


	//这一段处理列表内容，格式的设置
	YPDL_list_control.SetExtendedStyle(YPDL_list_control.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	//这一段初始化表头内容
	CString head1[] = { TEXT("供试品名称"), TEXT("样品编号"), TEXT("批号"), TEXT("样品提供单位"), TEXT("规格"), TEXT("剂量"), TEXT("试验方法"), TEXT("从前升温总和"), TEXT("从前超温只数") };

	for (int i = 0; i < sizeof(head1) / sizeof(head1[0]); i++){//依次插入
		YPDL_list_control.InsertColumn(i, head1[i], LVCFMT_LEFT, 100);
		}

	
	

	//处理 跟探头数相关的表头内容
	CString head2[] = { TEXT("探头号"), TEXT("均温"), TEXT("瓶号"), TEXT("注射开始时间"), TEXT("注射结束时间") };

	
	int column_num = 9;
	for(int i = 0; i < PointNum; i++){
		for (int j = 0; j < 5; j++){
			CString str;
			str.Format(head2[j]+" % d", i+1);
			YPDL_list_control.InsertColumn(column_num++, str, LVCFMT_LEFT, 100);
		}
		
	}//两个循环继续往表头添加内容


	//将样品队列信息初始化进表格
	int ress2 = mysql_query(&myonlydatabase.m_sqlCon, "select * from 样品队列");//表里面查找
	if (!ress2)
	{
		myonlydatabase.res = mysql_store_result(&myonlydatabase.m_sqlCon);
		if (myonlydatabase.res)
		{
			for (int i = 0; i < myonlydatabase.res->row_count; i++) {//将数据库里数据插进表格
				myonlydatabase.row = mysql_fetch_row(myonlydatabase.res);
				CString str0(myonlydatabase.row[0]);//供试品名称
				CString str1(myonlydatabase.row[1]);//样品编号
				CString str2(myonlydatabase.row[2]);//批号
				CString str3(myonlydatabase.row[3]);//样品提供单位sql`
				CString str4(myonlydatabase.row[4]);//规格sql
				CString str5(myonlydatabase.row[5]);//剂量sql
				CString str6(myonlydatabase.row[6]);//实验方法sql
				CString str7(myonlydatabase.row[7]);//从前升温总和sql`
				CString str8(myonlydatabase.row[8]);//从前超温只数sql`

				YPDL_list_control.InsertItem(i, str0);//第一个用的是insert，其余列用set
				YPDL_list_control.SetItemText(i, 1, str1);
				YPDL_list_control.SetItemText(i, 2, str2);
				YPDL_list_control.SetItemText(i, 3, str3);
				YPDL_list_control.SetItemText(i, 4, str4);
				YPDL_list_control.SetItemText(i, 5, str5);
				YPDL_list_control.SetItemText(i, 6, str6);//把获取进来的数据插进去

			}
		}


	}

	mysql_free_result(myonlydatabase.res);





	CRect rect1;
	GetDlgItem(10222)->GetWindowRect(&rect1);
	//转化为对话框上的相对位置
	ScreenToClient(rect1);

	CRect rect2;
	GetDlgItem(IDC_COMBO1)->GetWindowRect(&rect2);
	//转化为对话框上的相对位置
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
		//转化为对话框上的相对位置
		ScreenToClient(rect3);

	
		for (int i = 0; i < 6; i++) {

			GetDlgItem(10000 + i)->MoveWindow(rect3);
			GetDlgItem(10000+i)->ShowWindow(SW_HIDE);

			
			GetDlgItem(10100 + i)->ShowWindow(SW_HIDE);
		}
		
		GetDlgItem(10000 + 5)->MoveWindow(CRect(text_rect.left, rect2.top + 50, text_rect.right, rect2.bottom + 50));


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}





void Tab_CEWEN_WDCD_YPDL::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码


	int index = SYFF_comboxcontrol.GetCurSel();

	CString str;
	SYFF_comboxcontrol.GetLBText(index, str);//将下拉控件中的被选择的一项传给str




	for (int i = 0; i < 6; i++) {
		GetDlgItem(10000 + i)->ShowWindow(SW_HIDE);
		GetDlgItem(10100 + i)->ShowWindow(SW_HIDE);
	}
	

	if (str == _T("ChP复试")) {

		
		GetDlgItem(10000 )->ShowWindow(SW_SHOW);
		GetDlgItem(10100 )->ShowWindow(SW_SHOW);



	}else if (str == _T("EP第二次")) {

		GetDlgItem(10000 +1)->ShowWindow(SW_SHOW);
		GetDlgItem(10100 + 1)->ShowWindow(SW_SHOW);
	}
	else if (str == _T("EP第三次")) {

		GetDlgItem(10000 + 2)->ShowWindow(SW_SHOW);
		GetDlgItem(10100 + 2)->ShowWindow(SW_SHOW);
	}
	else if (str == _T("EP第四次")) {

		GetDlgItem(10000 + 3)->ShowWindow(SW_SHOW);
		GetDlgItem(10100 + 3)->ShowWindow(SW_SHOW);
	}
	else if (str == _T("USP复试")) {

		GetDlgItem(10000 + 4)->ShowWindow(SW_SHOW);
		GetDlgItem(10100 + 4)->ShowWindow(SW_SHOW);

		GetDlgItem(10000 + 5)->ShowWindow(SW_SHOW);
		GetDlgItem(10100 + 5)->ShowWindow(SW_SHOW);

	}
	else {



	}




}


void Tab_CEWEN_WDCD_YPDL::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)//选中列表的某行，并将内容同步到文本编辑框
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码


	m_listSelPos = YPDL_list_control.GetSelectionMark();

	YPDL_GSPMC_CString = YPDL_list_control.GetItemText(m_listSelPos, 0); //获取当前记录的显示的文本
	GSPMC_comboxcontrol.SetWindowTextW(YPDL_GSPMC_CString);//必须用cedit类型的才能调这个函数

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


void Tab_CEWEN_WDCD_YPDL::OnBnClickedButton5()//删除
{
	// TODO:  在此添加控件通知处理程序代码
	CString str;

	str = TEXT("确认删除这行数据吗？");
	if (IDYES == AfxMessageBox(str, MB_YESNO | MB_ICONQUESTION))
	{
		YPDL_list_control.DeleteItem(m_listSelPos);//删除这行数据
	}


	USES_CONVERSION;

	myonlydatabase.delete_yangpinduilie_mydatabase(T2A(YPDL_GSPMC_CString)); //删除数据库中对应元素


}


void Tab_CEWEN_WDCD_YPDL::OnBnClickedButton1()//增加
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(TRUE);

	int pos; //添加的位置
	pos = YPDL_list_control.GetItemCount();

	CString str;
	if (!vec_YPXX.empty()){
		int index = GSPMC_comboxcontrol.GetCurSel();
		
		GSPMC_comboxcontrol.GetLBText(index, str);//将下拉控件中的被选择的一项传给str

		YPDL_list_control.InsertItem(pos, str);//第一个用的是insert，其余列用set

	}
	else
	{
		YPDL_list_control.InsertItem(pos, YPDL_GSPMC_CString);
	}

	//把获取进来的数据插进去
	YPDL_list_control.SetItemText(pos, 1, YPDL_ypbh_CString);
	YPDL_list_control.SetItemText(pos, 2, YPDL_ph_CString);
	YPDL_list_control.SetItemText(pos, 3, YPDL_yptgdw_CString);
	YPDL_list_control.SetItemText(pos, 4, YPDL_GG_CString);
	YPDL_list_control.SetItemText(pos, 5, YPDL_JL_CString);
	YPDL_list_control.SetItemText(pos, 6, YPDL_SYFF_CString);
	

	CString str_cqswzh;//从前升温总和
	CString str_cqcwzs;//从前超温只数
	


	if (YPDL_SYFF_CString == _T("ChP复试")) {
		GetDlgItem(10100)->GetWindowText(str_cqswzh);
		str_cqcwzs = _T("0");
	}

	else if (YPDL_SYFF_CString == _T("EP第二次")) {

		GetDlgItem(10101)->GetWindowText(str_cqswzh);
		str_cqcwzs = _T("0");
	}
	else if (YPDL_SYFF_CString == _T("EP第三次")) {

		GetDlgItem(10102)->GetWindowText(str_cqswzh);
		str_cqcwzs = _T("0");
	}
	else if (YPDL_SYFF_CString == _T("EP第四次")) {

		GetDlgItem(10103)->GetWindowText(str_cqswzh);
		str_cqcwzs = _T("0");
	}
	else if (YPDL_SYFF_CString == _T("USP复试")) {

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

	//这个目前还没有加从前升温总和
	myonlydatabase.add_yangpinduilie_mydatabase(T2A(str), T2A(YPDL_ypbh_CString), T2A(YPDL_ph_CString), T2A(YPDL_yptgdw_CString), T2A(YPDL_GG_CString), T2A(YPDL_JL_CString), T2A(YPDL_SYFF_CString));
	

}


void Tab_CEWEN_WDCD_YPDL::OnBnClickedButton4()//修改
{
	// TODO:  在此添加控件通知处理程序代码
	//把新数据传送给浏览对话框，实现信息的修改
	UpdateData(true); //把对话框中的信息更新到内存中去

	
	YPDL_list_control.SetItemText(m_listSelPos, 0,YPDL_GSPMC_CString);
	//vec_YPXX[m_listSelPos].YPXX_YPMC = SET_YPXX_YPMC;

	YPDL_list_control.SetItemText(m_listSelPos, 1, YPDL_ypbh_CString);
	//vec_YPXX[m_listSelPos].YPXX_GG = SET_YPXX_GG;

	//SET_YPXX_GG.Format(_T("%.2f"), SET_YPXX_JL);//将剂量格式转换成Cstring并用 已经没用的样品信息接收 ，之后插入样品信息就行
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


void Tab_CEWEN_WDCD_YPDL::OnCbnSelchangeCombo2()//当供试品名称下拉框切换时，对应的规格跟剂量要切换
{
	// TODO:  在此添加控件通知处理程序代码

	int index = GSPMC_comboxcontrol.GetCurSel();

	CString str;
	GSPMC_comboxcontrol.GetLBText(index, str);//将下拉控件中的被选择的一项传给str


		

	YPDL_GG_control.SetWindowTextW(vec_YPXX[index].YPXX_GG);//切换规格
	YPDL_JL_control.SetWindowTextW(vec_YPXX[index].YPXX_JL);//切换剂量



}

CEdit* Tab_CEWEN_WDCD_YPDL::NewMyEdit(int nID, CRect rect, int nStyle)
{
	CString m_Caption;
	m_Caption.LoadString(nID); //取按钮标题
	CEdit *p_Edit = new CEdit();
	ASSERT_VALID(p_Edit);
	p_Edit->Create(WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | nStyle, rect, this, nID);
	return p_Edit;
}



CStatic* Tab_CEWEN_WDCD_YPDL::NewMyText(int nID, CRect rect, int nStyle)
{
	CString m_Caption;
	m_Caption.LoadString(nID); //取按钮标题
	m_Caption.Format(_T("%d"), nID - 10000);


	
	CStatic *p_Text = new CStatic();


	ASSERT_VALID(p_Text);
	p_Text->Create(m_Caption, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | nStyle, rect, this, nID);  //创建按钮

	

	return p_Text;
}