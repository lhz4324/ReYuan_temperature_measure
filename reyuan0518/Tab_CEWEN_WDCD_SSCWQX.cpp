// Tab_CEWEN_WDCD_SSCWQX.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "Tab_CEWEN_WDCD_SSCWQX.h"
#include "afxdialogex.h"

#include "Quanjv.h"

// Tab_CEWEN_WDCD_SSCWQX 对话框

IMPLEMENT_DYNAMIC(Tab_CEWEN_WDCD_SSCWQX, CDialogEx)

Tab_CEWEN_WDCD_SSCWQX::Tab_CEWEN_WDCD_SSCWQX(CWnd* pParent /*=NULL*/)
	: CDialogEx(Tab_CEWEN_WDCD_SSCWQX::IDD, pParent)
{

}

Tab_CEWEN_WDCD_SSCWQX::~Tab_CEWEN_WDCD_SSCWQX()
{
}

void Tab_CEWEN_WDCD_SSCWQX::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_ChartCtrl1, m_ChartCtrl1);
}


BEGIN_MESSAGE_MAP(Tab_CEWEN_WDCD_SSCWQX, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Tab_CEWEN_WDCD_SSCWQX 消息处理程序


BOOL Tab_CEWEN_WDCD_SSCWQX::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化





	
	int k = PointNum;//探头数传值
	for (int j = 0; j < (PointNum / 8) + 1; j++)
	{

		k -= 8;
		if (k > 0){
			for (int i = 0; i < 8; i++){

				p_ChartCtrl[i + j * 8] = NewMyTuXiang(11000 + n++, CRect(10 + jiange_hengxiang * i, 10 + jiange_zongxiang * (j), 210 + jiange_hengxiang * i, 210 + jiange_zongxiang * (j)), 0);



			}

		}
		else{
			k += 8;
			for (int i = 0; i < k; i++){

				p_ChartCtrl[i + j * 8] = NewMyTuXiang(11000 + n++, CRect(10 + jiange_hengxiang * i, 10 + jiange_zongxiang * (j), 210 + jiange_hengxiang * i, 210 + jiange_zongxiang * (j)), 0);
				


			}
		}
	}

	SetTimer(1, 1000, NULL);



	


	


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

CChartCtrl* Tab_CEWEN_WDCD_SSCWQX::NewMyTuXiang(int nID, CRect rect, int nStyle)
{
	CChartCtrl *m_ChartCtrl = new CChartCtrl();
	ASSERT_VALID(m_ChartCtrl);

	m_ChartCtrl->Create(this, rect, nID, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | nStyle);

	////控件1坐标轴设置
	CChartAxis *pAxis = NULL;
	pAxis = m_ChartCtrl->CreateStandardAxis(CChartCtrl::BottomAxis);
	pAxis->SetAutomatic(true);
	pAxis = m_ChartCtrl->CreateStandardAxis(CChartCtrl::LeftAxis);
	pAxis->SetAutomatic(true);


	//控件标题
	TChartString str1;

	CString str;
	str.Format(_T("Chart - %d"), nID+1-11000);

	str1 = str;
	


	m_ChartCtrl->GetTitle()->AddString(str1);



	CChartAxisLabel* pLabel = NULL;
	CChartAxis *pAxis1 = NULL;
	TChartString str3 = _T("左坐标轴");

	pAxis1 = m_ChartCtrl->GetLeftAxis();
	if (pAxis1)
	{
		pLabel = pAxis1->GetLabel();
	}

	if (pLabel)
	{
		pLabel->SetText(str3);
	}


	str3 = _T("数值坐标轴");
	pAxis1 = m_ChartCtrl->GetBottomAxis();
	if (pAxis1)
		pLabel = pAxis1->GetLabel();
	if (pLabel)
		pLabel->SetText(str3);


	return m_ChartCtrl;
}



void Tab_CEWEN_WDCD_SSCWQX::huatu(CChartCtrl *m_ChartCtrl1,int i){

	m_ChartCtrl1->EnableRefresh(false);
	////////////////////////////////////////////////////////////////////////////画图测试//////////////////////////////////////////////////////////////////////////
	
	for (int m = 0; m< point_ifstart_now[i].j; m++)
	{
		x[m] = m;
		y[m] = point_ifstart_now[i].t_all[m];
	}

	for (int n = point_ifstart_now[i].j; n <540 ; n++)
	{
		x[n] = n;
		y[n] = 0;
	}

	CChartLineSerie *pLineSerie1;
	m_ChartCtrl1->RemoveAllSeries();
	//先清空

	pLineSerie1 = m_ChartCtrl1->CreateLineSerie();
	pLineSerie1->SetSeriesOrdering(poNoOrdering);
	//设置为无序


	pLineSerie1->AddPoints(x, y, 540);//将横纵坐标加进图中
	//pLineSerie1->SetName(_T("这是IDC_ChartCtrl1的第一条线"));


	m_ChartCtrl1->EnableRefresh(true);
}

void Tab_CEWEN_WDCD_SSCWQX::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	

	for (int i= 0; i < PointNum ; i++)
	{

				//if (point_ifstart_now[i ].ifstart == 1) {
					huatu(p_ChartCtrl[i],i);
				//}

	}


	CDialogEx::OnTimer(nIDEvent);
}
