// SET_YPXX.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "SET_YPXX.h"
#include "afxdialogex.h"



// SET_YPXX 对话框

IMPLEMENT_DYNAMIC(SET_YPXX, CDialogEx)

SET_YPXX::SET_YPXX(CWnd* pParent /*=NULL*/)
	: CDialogEx(SET_YPXX::IDD, pParent)
	, SET_YPXX_YPMC(_T(""))
	, SET_YPXX_GG(_T(""))
	, SET_YPXX_GSRY(_T(""))
	, SET_YPXX_JL(_T(""))
{
	list_row_index = 0;//构造函数初始化
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


// SET_YPXX 消息处理程序


BOOL SET_YPXX::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	//这一段处理列表内容，格式的设置
	SET_YPXX_LIST.SetExtendedStyle(SET_YPXX_LIST.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	
	//这一段初始化表头内容
	CString head[] = { TEXT("供试品名称"), TEXT("规格"), TEXT("剂量"), TEXT("供试溶液的配置") };
	SET_YPXX_LIST.InsertColumn(0, head[0], LVCFMT_LEFT, 100);
	SET_YPXX_LIST.InsertColumn(1, head[1], LVCFMT_LEFT, 100);
	SET_YPXX_LIST.InsertColumn(2, head[2], LVCFMT_LEFT, 100);
	SET_YPXX_LIST.InsertColumn(3, head[3], LVCFMT_LEFT, 100);
	

		vec_YPXX.clear();//避免测温子菜单样品队列子菜单重复加载
		int ress = mysql_query(&myonlydatabase.m_sqlCon, "select * from 样品信息");//表里面查找
		if (!ress)
		{
			myonlydatabase.res = mysql_store_result(&myonlydatabase.m_sqlCon);
			if (myonlydatabase.res)
			{
				for (int i = 0; i < myonlydatabase.res->row_count; i++){//将数据库里数据插进表格
					myonlydatabase.row = mysql_fetch_row(myonlydatabase.res);
					CString str0(myonlydatabase.row[0]);
					CString str1(myonlydatabase.row[1]);
					CString str2(myonlydatabase.row[2]);
					CString str3(myonlydatabase.row[3]);

					SET_YPXX_LIST.InsertItem(i, str0);//第一个用的是insert，其余列用set
					SET_YPXX_LIST.SetItemText(i, 1, str1);
					SET_YPXX_LIST.SetItemText(i, 2, str2);
					SET_YPXX_LIST.SetItemText(i, 3, str3);//把获取进来的数据插进去

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





	//下面处理四个编辑框
	SET_YPXX_YPMC = TEXT("");
	UpdateData(FALSE);


	SET_YPXX_JL = TEXT("");
	UpdateData(FALSE);

	SET_YPXX_GG = TEXT("");
	UpdateData(FALSE);

	SET_YPXX_GSRY = TEXT("");




	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void SET_YPXX::OnBnClicked1003()//增加按钮
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);//先update这样保证编辑框中更改后的数据也可以被加入列表，每一版都得有


	/*********************************************第三版*********************************************/

	
	YangPinXinXi ypxx;
	ypxx.YPXX_YPMC = SET_YPXX_YPMC;
	ypxx.YPXX_GG = SET_YPXX_GG;
	ypxx.YPXX_JL = SET_YPXX_JL;
	ypxx.YPXX_GSRY = SET_YPXX_GSRY;

	vec_YPXX.push_back(ypxx);


	int pos; //添加的位置
	pos = SET_YPXX_LIST.GetItemCount();
	SET_YPXX_LIST.InsertItem(pos, ypxx.YPXX_YPMC);//第一个用的是insert，其余列用set
	SET_YPXX_LIST.SetItemText(pos, 1, ypxx.YPXX_GG);
	SET_YPXX_LIST.SetItemText(pos, 2, ypxx.YPXX_JL);
	SET_YPXX_LIST.SetItemText(pos, 3, ypxx.YPXX_GSRY);//把获取进来的数据插进去

	UpdateData(FALSE);

	
	USES_CONVERSION;

	myonlydatabase.add_yangpinxinxi_mydatabase(T2A(SET_YPXX_YPMC), T2A(SET_YPXX_GG), T2A(SET_YPXX_JL), T2A(SET_YPXX_GSRY));



	


}


void SET_YPXX::OnBnClicked1006()//删除按钮
{
	// TODO:  在此添加控件通知处理程序代码
		CString str;
		
		str = TEXT("确认删除这行数据吗？");
		if (IDYES == AfxMessageBox(str, MB_YESNO | MB_ICONQUESTION))
		{
			SET_YPXX_LIST.DeleteItem(m_listSelPos);//删除这行数据
		}

			
		vec_YPXX.erase(vec_YPXX.begin() + m_listSelPos);     //删除vec_YPXX中对应元素


		USES_CONVERSION;

		myonlydatabase.delete_yangpinxinxi_mydatabase(T2A(SET_YPXX_YPMC)); //删除数据库中对应元素




}


void SET_YPXX::OnNMClick1037(NMHDR *pNMHDR, LRESULT *pResult)//选中列表的某行，并将内容同步到文本编辑框
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码

	m_listSelPos = SET_YPXX_LIST.GetSelectionMark();
	
	SET_YPXX_YPMC = SET_YPXX_LIST.GetItemText(m_listSelPos, 0); //获取当前记录的显示的文本
	YPMC_control.SetWindowTextW(SET_YPXX_YPMC);//必须用cedit类型的才能调这个函数
	
	SET_YPXX_GG = SET_YPXX_LIST.GetItemText(m_listSelPos, 1);
	GG_control.SetWindowTextW(SET_YPXX_GG);

	
	SET_YPXX_JL = SET_YPXX_LIST.GetItemText(m_listSelPos, 2);
	JL_control.SetWindowTextW(SET_YPXX_JL);


	SET_YPXX_GSRY = SET_YPXX_LIST.GetItemText(m_listSelPos, 3);
	GSRY_control.SetWindowTextW(SET_YPXX_GSRY);
	
	
	*pResult = 0;
}


void SET_YPXX::OnBnClicked1005()//修改按钮
{
	// TODO:  在此添加控件通知处理程序代码
		
		
	//把新数据传送给浏览对话框，实现信息的修改
	UpdateData(true); //把对话框中的信息更新到内存中去
	SET_YPXX_LIST.SetItemText(m_listSelPos, 0, SET_YPXX_YPMC);
	vec_YPXX[m_listSelPos].YPXX_YPMC = SET_YPXX_YPMC;

	SET_YPXX_LIST.SetItemText(m_listSelPos, 1, SET_YPXX_GG);
	vec_YPXX[m_listSelPos].YPXX_GG = SET_YPXX_GG;
	
	//SET_YPXX_GG.Format(_T("%.2f"), SET_YPXX_JL);//将剂量格式转换成Cstring并用 已经没用的样品信息接收 ，之后插入样品信息就行
	SET_YPXX_LIST.SetItemText(m_listSelPos, 2, SET_YPXX_JL);
	vec_YPXX[m_listSelPos].YPXX_JL = SET_YPXX_JL;

	SET_YPXX_LIST.SetItemText(m_listSelPos, 3, SET_YPXX_GSRY);
	vec_YPXX[m_listSelPos].YPXX_GSRY = SET_YPXX_GSRY;

	UpdateData(FALSE);



	USES_CONVERSION;

	

	myonlydatabase.change_yangpinxinxi_mydatabase(T2A(SET_YPXX_YPMC), T2A(SET_YPXX_GG), T2A(SET_YPXX_JL), T2A(SET_YPXX_GSRY));

	



	
	

}


void SET_YPXX::OnBnClicked1007()//取消按钮
{
	// TODO:  在此添加控件通知处理程序代码

	CDialogEx::OnCancel();
}
