// FV_DATA_TTBDJG.cpp : 实现文件
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


// FV_DATA_TTBDJG 诊断

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


// FV_DATA_TTBDJG 消息处理程序


void FV_DATA_TTBDJG::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类



	//这一段处理列表内容
	DATA_TTBDJG_list.SetExtendedStyle(DATA_TTBDJG_list.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	CString head[] = { TEXT("日期"), TEXT("时间"), TEXT("探头号"), TEXT("第一点实际温度"), TEXT("第一点回归温度"), TEXT("第二点实际温度"), TEXT("第二点回归温度"), TEXT("第三点实际温度"), TEXT("第三点回归温度"), TEXT("第四点实际温度"), TEXT("第四点回归温度"), TEXT("第五点实际温度"), TEXT("第五点回归温度"), TEXT("结论") };

	for (int i = 0; i < sizeof(head) / sizeof(head[0]); i++) {
		DATA_TTBDJG_list.InsertColumn(i, head[i], LVCFMT_LEFT, 100);

	}


	//将数据库里账户信息初始化进表格中
		int ress = mysql_query(&myonlydatabase.m_sqlCon, "select * from 探头标定信息");//表里面查找
		if (!ress)
		{
			myonlydatabase.res = mysql_store_result(&myonlydatabase.m_sqlCon);
			if (myonlydatabase.res)
			{
				for (int i = 0; i < myonlydatabase.res->row_count; i++) {//将数据库里数据插进表格
					myonlydatabase.row = mysql_fetch_row(myonlydatabase.res);

					CString str0(myonlydatabase.row[0]);
			
					DATA_TTBDJG_list.InsertItem(i, str0);//第一个用的是insert，其余列用set
		

					for (int j = 1; j < sizeof(head) / sizeof(head[0])-1; j++) {

						CString str(myonlydatabase.row[j]);

						
						DATA_TTBDJG_list.SetItemText(i, j, str);
					}

					CString str(myonlydatabase.row[sizeof(head) / sizeof(head[0])-1]);

					if (str == TEXT("y"))
						DATA_TTBDJG_list.SetItemText(i, sizeof(head) / sizeof(head[0]) - 1, TEXT("合格"));
					else if (str == TEXT("n"))
						DATA_TTBDJG_list.SetItemText(i, sizeof(head) / sizeof(head[0]) - 1, TEXT("不合格"));
					else
					{
						DATA_TTBDJG_list.SetItemText(i, sizeof(head) / sizeof(head[0]) - 1, TEXT(" "));
					}
				}
			}

		}
		mysql_free_result(myonlydatabase.res);


}


void FV_DATA_TTBDJG::OnBnClickedButton1()//打印预览
{
	// TODO: 在此添加控件通知处理程序代码
}


void FV_DATA_TTBDJG::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
}
