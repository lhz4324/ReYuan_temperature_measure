#pragma once

#include "chart_control/ChartLineSerie.h"
#include"chart_control/ChartAxisLabel.h"
#include "chart_control/ChartCtrl.h"

// Tab_CEWEN_WDCD_SSCWQX 对话框

class Tab_CEWEN_WDCD_SSCWQX : public CDialogEx
{
	DECLARE_DYNAMIC(Tab_CEWEN_WDCD_SSCWQX)

public:
	Tab_CEWEN_WDCD_SSCWQX(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Tab_CEWEN_WDCD_SSCWQX();

// 对话框数据
	enum { IDD = IDD_CEWEN_WDCD_SSCWQX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	CChartCtrl *p_ChartCtrl[64];




	
	int jiange_hengxiang = 250;//横向间隔
	int jiange_zongxiang = 230;//纵向间隔
	int n = 0;//id


	void huatu(CChartCtrl* m_ChartCtrl1,int i);
	CChartCtrl* NewMyTuXiang(int nID, CRect rect, int nStyle);
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	double x[540], y[540];//记录图像xy轴数据
};
