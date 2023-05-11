// SET_YL_JLGS_LEFT.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "SET_YL_JLGS_LEFT.h"

#include "Quanjv.h"
// SET_YL_JLGS_LEFT

#include "m_tree_h1.h"
#include "m_tree_h2.h"
#include "m_tree_h3.h"
#include "m_tree_h4.h"
#include "m_tree_h5.h"
#include "m_tree_h6.h"

IMPLEMENT_DYNCREATE(SET_YL_JLGS_LEFT, CFormView)

SET_YL_JLGS_LEFT::SET_YL_JLGS_LEFT()
	: CFormView(SET_YL_JLGS_LEFT::IDD)
{

}

SET_YL_JLGS_LEFT::~SET_YL_JLGS_LEFT()
{
}

void SET_YL_JLGS_LEFT::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_treeCtrl);
}

BEGIN_MESSAGE_MAP(SET_YL_JLGS_LEFT, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &SET_YL_JLGS_LEFT::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &SET_YL_JLGS_LEFT::OnBnClickedButton5)
	ON_NOTIFY(NM_RCLICK, IDC_TREE1, &SET_YL_JLGS_LEFT::OnNMRClickTree1)
END_MESSAGE_MAP()


// SET_YL_JLGS_LEFT 诊断

#ifdef _DEBUG
void SET_YL_JLGS_LEFT::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void SET_YL_JLGS_LEFT::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// SET_YL_JLGS_LEFT 消息处理程序


void SET_YL_JLGS_LEFT::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类

	


	m_treeCtrl.ModifyStyle(0, TVS_CHECKBOXES); //设置树控件为带复选框风格

	
	 root = m_treeCtrl.InsertItem(TEXT("打印记录格式"), 1, 0,TVI_ROOT);//
	 H1 = m_treeCtrl.InsertItem(TEXT("页面设置"), 1, 0, root);
	 H2 = m_treeCtrl.InsertItem(TEXT("记录标题"), 1, 0, root);
	 H3 = m_treeCtrl.InsertItem(TEXT("基本信息"), 1, 0, root);
	 H4 = m_treeCtrl.InsertItem(TEXT("温度数据表"), 1, 0, root);
	 H5 = m_treeCtrl.InsertItem(TEXT("温度曲线"), 1, 0, root);
	 H6 = m_treeCtrl.InsertItem(TEXT("辅助项"), 1, 0, root);
	

	  H11 = m_treeCtrl.InsertItem(TEXT("纸张大小"), 1, 0, H1);
		  H111 = m_treeCtrl.InsertItem(TEXT("A4"), 1, 0, H11);
			  H1111 = m_treeCtrl.InsertItem(TEXT("宽（mm）"), 1, 0, H111);
				  H11111 = m_treeCtrl.InsertItem(TEXT("210"), 1, 0, H1111);
		  H1112 = m_treeCtrl.InsertItem(TEXT("高（mm）"), 1, 0, H111);
			  H11121 = m_treeCtrl.InsertItem(TEXT("297"), 1, 0, H1112);
	  H12 = m_treeCtrl.InsertItem(TEXT("方向"), 1, 0, H1);
		  H121 = m_treeCtrl.InsertItem(TEXT("纵向"), 1, 0, H12);

	  H21 = m_treeCtrl.InsertItem(TEXT("文本"), 1, 0, H2);
		  H211 = m_treeCtrl.InsertItem(TEXT("热源检查记录"), 1, 0, H21);
	  H22 = m_treeCtrl.InsertItem(TEXT("字体"), 1, 0, H2);
		  H221 = m_treeCtrl.InsertItem(TEXT("黑体，1,12"), 1, 0, H22);
	  H23 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H2);
		  H231 = m_treeCtrl.InsertItem(TEXT("5,20,180,12"), 1, 0, H23);

	  H31 = m_treeCtrl.InsertItem(TEXT("字体"), 1, 0, H3);
		  H311 = m_treeCtrl.InsertItem(TEXT("宋体，1,10.5"), 1, 0, H31);
	  H32 = m_treeCtrl.InsertItem(TEXT("供试品名称"), 1, 0, H3);
		  H321 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H32);
			  H3211 = m_treeCtrl.InsertItem(TEXT("15,30,100,10"), 1, 0, H321);
	  H33 = m_treeCtrl.InsertItem(TEXT("样品编号"), 1, 0, H3);
		  H331 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H33);
			  H3311 = m_treeCtrl.InsertItem(TEXT("110,30,100,10"), 1, 0, H331);
	  H34 = m_treeCtrl.InsertItem(TEXT("批号"), 1, 0, H3);
		  H341 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H34);
			  H3411 = m_treeCtrl.InsertItem(TEXT("15,35,100,10"), 1, 0, H341);
	  H35 = m_treeCtrl.InsertItem(TEXT("样品提供单位"), 1, 0, H3);
		  H351 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H35);
			  H3511 = m_treeCtrl.InsertItem(TEXT("110，35,100,10"), 1, 0, H351);
	  H36 = m_treeCtrl.InsertItem(TEXT("规格"), 1, 0, H3);
		  H361 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H36);
			  H3611 = m_treeCtrl.InsertItem(TEXT("15,40,100,10"), 1, 0, H361);
	  H37 = m_treeCtrl.InsertItem(TEXT("剂量"), 1, 0, H3);
		  H371 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H37);
			  H3711 = m_treeCtrl.InsertItem(TEXT("15,45,100,10"), 1, 0, H371);
	  H38 = m_treeCtrl.InsertItem(TEXT("试验方法"), 1, 0, H3);

	if (title == TEXT("新建")){  H381 = m_treeCtrl.InsertItem(TEXT("ChP初试"), 1, 0, H38);
	m_treeCtrl.SetItemState(H381, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	}
	else{  H381 = m_treeCtrl.InsertItem(title, 1, 0, H38);
	m_treeCtrl.SetItemState(H381, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	}	
		  H382 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H38);
			  H3821 = m_treeCtrl.InsertItem(TEXT("15,60,100,10"), 1, 0, H382);
	  H39 = m_treeCtrl.InsertItem(TEXT("试验日期"), 1, 0, H3);
		  H391 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H39);
			  H3911 = m_treeCtrl.InsertItem(TEXT("15,50,100,10"), 1, 0, H391);
	  H3_10 = m_treeCtrl.InsertItem(TEXT("供试溶液的配置"), 1, 0, H3);
		  H3_101 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H3_10);
			  H3_1011 = m_treeCtrl.InsertItem(TEXT("15,70,178,20"), 1, 0, H3_101);
	  H3_11 = m_treeCtrl.InsertItem(TEXT("关键温度时间点扩展"), 1, 0, H3);
		  H3_111 = m_treeCtrl.InsertItem(TEXT("时间阈值（±min）"), 1, 0, H3_11);
			  H3_1111 = m_treeCtrl.InsertItem(TEXT("2"), 1, 0, H3_111);
		  H3_112 = m_treeCtrl.InsertItem(TEXT("温度阈值（℃）"), 1, 0, H3_11);
			  H3_1121 = m_treeCtrl.InsertItem(TEXT("0"), 1, 0, H3_112);
		  H3_113 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H3_11);
			  H3_1131 = m_treeCtrl.InsertItem(TEXT("110,60,100,10"), 1, 0, H3_113);


	  H41 = m_treeCtrl.InsertItem(TEXT("字体"), 1, 0, H4);
		  H411 = m_treeCtrl.InsertItem(TEXT("宋体，0,10.5"), 1, 0, H41);
	  H42 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H4);
		  H421 = m_treeCtrl.InsertItem(TEXT("10,85,180,85"), 1, 0, H42);
	  H43 = m_treeCtrl.InsertItem(TEXT("时间信息"), 1, 0, H4);


	  H51 = m_treeCtrl.InsertItem(TEXT("字体"), 1, 0, H5);
		  H511 = m_treeCtrl.InsertItem(TEXT("宋体，0,6.75"), 1, 0, H51);
	  H52 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H5);
		  H521 = m_treeCtrl.InsertItem(TEXT("10,180,180,80"), 1, 0, H52);
	  H53 = m_treeCtrl.InsertItem(TEXT("图表个数/行"), 1, 0, H5);
		  H531 = m_treeCtrl.InsertItem(TEXT("3"), 1, 0, H53);



	  H61 = m_treeCtrl.InsertItem(TEXT("文本1"), 1, 0, H6);
		  H611 = m_treeCtrl.InsertItem(TEXT("内容"), 1, 0, H61);
			  H6111 = m_treeCtrl.InsertItem(TEXT("仪器名称：微机热源温仪"), 1, 0, H611);
		  H612 = m_treeCtrl.InsertItem(TEXT("字体"), 1, 0, H61);
			  H6121 = m_treeCtrl.InsertItem(TEXT("宋体，1,10.5"), 1, 0, H612);
		  H613= m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H61);
			  H6131 = m_treeCtrl.InsertItem(TEXT("110,40,100,10"), 1, 0, H613);
	
	  H62 = m_treeCtrl.InsertItem(TEXT("文本2"), 1, 0, H6);
		  H621 = m_treeCtrl.InsertItem(TEXT("内容"), 1, 0, H62);
			  H6211 = m_treeCtrl.InsertItem(TEXT("仪器型号：WRY-2015"), 1, 0, H621);
		  H622 = m_treeCtrl.InsertItem(TEXT("字体"), 1, 0, H62);
			  H6221 = m_treeCtrl.InsertItem(TEXT("宋体，1,10.5"), 1, 0, H622);
		  H623 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H62);
			  H6231 = m_treeCtrl.InsertItem(TEXT("110,45,100,10"), 1, 0, H623);

	  H63 = m_treeCtrl.InsertItem(TEXT("文本3"), 1, 0, H6);
		  H631 = m_treeCtrl.InsertItem(TEXT("内容"), 1, 0, H63);
			  H6311 = m_treeCtrl.InsertItem(TEXT("设备编号：A21001"), 1, 0, H631);
		  H632 = m_treeCtrl.InsertItem(TEXT("字体"), 1, 0, H63);
			  H6321 = m_treeCtrl.InsertItem(TEXT("宋体，1,10.5"), 1, 0, H632);
		  H633 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H63);
			  H6331 = m_treeCtrl.InsertItem(TEXT("110,50,100,10"), 1, 0, H633);

	  H64 = m_treeCtrl.InsertItem(TEXT("文本4"), 1, 0, H6);
		  H641 = m_treeCtrl.InsertItem(TEXT("内容"), 1, 0, H64);
			  H6411 = m_treeCtrl.InsertItem(TEXT("操作人/日期"), 1, 0, H641);
		  H642 = m_treeCtrl.InsertItem(TEXT("字体"), 1, 0, H64);
			  H6421 = m_treeCtrl.InsertItem(TEXT("黑体，0,10.5"), 1, 0, H642);
		  H643 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H64);
			  H6431 = m_treeCtrl.InsertItem(TEXT("110,265,100,10"), 1, 0, H643);



	  H65 = m_treeCtrl.InsertItem(TEXT("文本5"), 1, 0, H6);
		  H651 = m_treeCtrl.InsertItem(TEXT("内容"), 1, 0, H65);
			  H6511 = m_treeCtrl.InsertItem(TEXT("复核人/日期"), 1, 0, H651);
		  H652 = m_treeCtrl.InsertItem(TEXT("字体"), 1, 0, H65);
			  H6521 = m_treeCtrl.InsertItem(TEXT("黑体，0,10.5"), 1, 0, H652);
		  H653 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H65);
			  H6531 = m_treeCtrl.InsertItem(TEXT("75,265,80,10"), 1, 0, H653);


	  H66 = m_treeCtrl.InsertItem(TEXT("文本6"), 1, 0, H6);
		  H661 = m_treeCtrl.InsertItem(TEXT("内容"), 1, 0, H66);
			  H6611 = m_treeCtrl.InsertItem(TEXT("审核人/日期"), 1, 0, H661);
		  H662 = m_treeCtrl.InsertItem(TEXT("字体"), 1, 0, H66);
			  H6621 = m_treeCtrl.InsertItem(TEXT("黑体，0,10.5"), 1, 0, H662);
		  H663 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H66);
			  H6631 = m_treeCtrl.InsertItem(TEXT("135,265,50,10"), 1, 0, H663);

	  H67 = m_treeCtrl.InsertItem(TEXT("文本7"), 1, 0, H6);
		  H671 = m_treeCtrl.InsertItem(TEXT("内容"), 1, 0, H67);
			  H6711 = m_treeCtrl.InsertItem(TEXT("检验依据：GB2015-2003"), 1, 0, H671);
		  H672 = m_treeCtrl.InsertItem(TEXT("字体"), 1, 0, H67);
			  H6721 = m_treeCtrl.InsertItem(TEXT("黑体，0,10.5"), 1, 0, H672);
		  H673 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H67);
			  H6731 = m_treeCtrl.InsertItem(TEXT("15,55,180,10"), 1, 0, H673);


	  H68 = m_treeCtrl.InsertItem(TEXT("文本8"), 1, 0, H6);
		  H681 = m_treeCtrl.InsertItem(TEXT("内容"), 1, 0, H68);
			  H6811 = m_treeCtrl.InsertItem(TEXT("室温：17~25℃"), 1, 0, H681);
		  H682 = m_treeCtrl.InsertItem(TEXT("字体"), 1, 0, H68);
			  H6821 = m_treeCtrl.InsertItem(TEXT("黑体，0,10.5"), 1, 0, H682);
		  H683 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H68);
			  H6831 = m_treeCtrl.InsertItem(TEXT("110,55,180,10"), 1, 0, H683);

	  H69 = m_treeCtrl.InsertItem(TEXT("线段1"), 1, 0, H6);
		  H691 = m_treeCtrl.InsertItem(TEXT("坐标（x1，y1，x2，y2）"), 1, 0, H69);
			  H6911 = m_treeCtrl.InsertItem(TEXT("10,15,190,15"), 1, 0, H691);
		  H692 = m_treeCtrl.InsertItem(TEXT("线宽"), 1, 0, H69);
			  H6921 = m_treeCtrl.InsertItem(TEXT("0.2"), 1, 0, H692);

	  H6_10 = m_treeCtrl.InsertItem(TEXT("线段2"), 1, 0, H6);
		  H6_101 = m_treeCtrl.InsertItem(TEXT("坐标（x1，y1，x2，y2）"), 1, 0, H6_10);
			  H6_1011 = m_treeCtrl.InsertItem(TEXT("10,84,190,84"), 1, 0, H6_101);
		  H6_102 = m_treeCtrl.InsertItem(TEXT("线宽"), 1, 0, H6_10);
			  H6_1021 = m_treeCtrl.InsertItem(TEXT("0.2"), 1, 0, H6_102);

	  H6_11 = m_treeCtrl.InsertItem(TEXT("线段3"), 1, 0, H6);
		  H6_111 = m_treeCtrl.InsertItem(TEXT("坐标（x1，y1，x2，y2）"), 1, 0, H6_11);
			  H6_1111 = m_treeCtrl.InsertItem(TEXT("10,274,190,274"), 1, 0, H6_111);
		  H6_112 = m_treeCtrl.InsertItem(TEXT("线宽"), 1, 0, H6_11);
			  H6_1121 = m_treeCtrl.InsertItem(TEXT("0.2"), 1, 0, H6_112);

	  H6_12= m_treeCtrl.InsertItem(TEXT("图片1"), 1, 0, H6);
		  H6_121 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H6_12);
			  H6_1211 = m_treeCtrl.InsertItem(TEXT("10,5,50,8"), 1, 0, H6_121);
		  H6_122 = m_treeCtrl.InsertItem(TEXT("文件名"), 1, 0, H6_12);
			  H6_1221 = m_treeCtrl.InsertItem(TEXT(""), 1, 0, H6_122);


	  H6_13= m_treeCtrl.InsertItem(TEXT("图片2"), 1, 0, H6);
		  H6_131 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H6_13);
			  H6_1311 = m_treeCtrl.InsertItem(TEXT("100,5,50,8"), 1, 0, H6_131);
		  H6_132 = m_treeCtrl.InsertItem(TEXT("文件名"), 1, 0, H6_13);
			  H6_1321 = m_treeCtrl.InsertItem(TEXT(""), 1, 0, H6_132);

	  H6_14= m_treeCtrl.InsertItem(TEXT("打印报告日期"), 1, 0, H6);
		  H6_141 = m_treeCtrl.InsertItem(TEXT("字体"), 1, 0, H6_14);
			  H6_1411 = m_treeCtrl.InsertItem(TEXT("黑体，1,9"), 1, 0, H6_141);
		  H6_142 = m_treeCtrl.InsertItem(TEXT("位置（左边界、上边界、宽、高）"), 1, 0, H6_14);
			  H6_1421 = m_treeCtrl.InsertItem(TEXT("130,275,100,15"), 1, 0, H6_142);
	//m_treeCtrl.SetBkColor(RGB(0, 0, 0));
	//m_treeCtrl.SetTextColor(RGB(255, 255, 255));

	//设置复选框隐藏显示
	m_treeCtrl.SetItemState(root, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H1, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.SetItemState(H11, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H12, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H111, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H121, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H1111, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H1112, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.SetItemState(H21, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H22, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H23, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H211, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H221, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H231, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.SetItemState(H31, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H311, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H321, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3211, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H331, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3311, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H341, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3411, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H351, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3511, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H361, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3611, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H371, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3711, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	//m_treeCtrl.SetItemState(H381, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);在上面ifelse设置
	m_treeCtrl.SetItemState(H382, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3821, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H391, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3911, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3_101, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3_1011, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3_111, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3_1111, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3_112, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3_1121, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3_113, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H3_1131, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.SetItemState(H41, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H411, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H42, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H421, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.SetItemState(H51, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H511, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H52, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H521, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H53, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H531, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);


	m_treeCtrl.SetItemState(H611, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6111, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H612, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6121, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H613, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6131, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);


	m_treeCtrl.SetItemState(H621, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6211, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H622, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6221, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H623, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6231, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);


	m_treeCtrl.SetItemState(H631, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6311, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H632, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6321, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H633, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6331, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);


	m_treeCtrl.SetItemState(H641, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6411, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H642, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6421, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H643, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6431, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);


	m_treeCtrl.SetItemState(H651, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6511, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H652, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6521, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H653, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6531, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.SetItemState(H661, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6611, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H662, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6621, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H663, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6631, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.SetItemState(H671, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6711, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H672, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6721, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H673, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6731, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.SetItemState(H681, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6811, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H682, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6821, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H683, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6831, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);


	m_treeCtrl.SetItemState(H691, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6911, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H692, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6921, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.SetItemState(H6_101, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_1011, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_102, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_1021, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.SetItemState(H6_111, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_1111, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_112, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_1121, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.SetItemState(H6_121, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_1211, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_122, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_1221, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.SetItemState(H6_131, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_1311, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_132, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_1321, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.SetItemState(H6_141, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_1411, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_142, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);
	m_treeCtrl.SetItemState(H6_121, INDEXTOSTATEIMAGEMASK(0), TVIS_STATEIMAGEMASK);

	m_treeCtrl.Select(H1, TVGN_CARET);
}


void SET_YL_JLGS_LEFT::OnBnClickedButton1()//保存
{
	// TODO:  在此添加控件通知处理程序代码

}


void SET_YL_JLGS_LEFT::OnBnClickedButton5()//预览
{
	// TODO:  在此添加控件通知处理程序代码
	//m_treeCtrl.GetItemState(H2, TVIS_STATEIMAGEMASK);


	
		checkbox_state_now.jlbt = m_treeCtrl.GetCheck(H2);//记录标题
		
		checkbox_state_now.basic_info_gspmc = m_treeCtrl.GetCheck(H32);
		checkbox_state_now.basic_info_ypbh = m_treeCtrl.GetCheck(H33);
		checkbox_state_now.basic_info_ph = m_treeCtrl.GetCheck(H34);
		checkbox_state_now.basic_info_yptgdw = m_treeCtrl.GetCheck(H35);
		checkbox_state_now.basic_info_gg = m_treeCtrl.GetCheck(H36);
		checkbox_state_now.basic_info_jl = m_treeCtrl.GetCheck(H37);
		checkbox_state_now.basic_info_syff = m_treeCtrl.GetCheck(H38);
		checkbox_state_now.basic_info_syrq = m_treeCtrl.GetCheck(H39);
		checkbox_state_now.basic_info_gsrydpz = m_treeCtrl.GetCheck(H3_10);
		checkbox_state_now.basic_info_gjwdsjdkz = m_treeCtrl.GetCheck(H3_11);
		
		checkbox_state_now.wdsjb = m_treeCtrl.GetCheck(H4);
		checkbox_state_now.wdsjb_sjxx = m_treeCtrl.GetCheck(H43);

		checkbox_state_now.wdqx = m_treeCtrl.GetCheck(H5);
		
		checkbox_state_now.fzx_wb1_yqmc= m_treeCtrl.GetCheck(H61);
		checkbox_state_now.fzx_wb2_yqxh= m_treeCtrl.GetCheck(H62);
		checkbox_state_now.fzx_wb3_sbbh= m_treeCtrl.GetCheck(H63);
		checkbox_state_now.fzx_wb4_czr= m_treeCtrl.GetCheck(H64);
		checkbox_state_now.fzx_wb5_fhr= m_treeCtrl.GetCheck(H65);
		checkbox_state_now.fzx_wb6_shr= m_treeCtrl.GetCheck(H66);
		checkbox_state_now.fzx_wb7_jyyj = m_treeCtrl.GetCheck(H67);
		checkbox_state_now.fzx_wb8_sw = m_treeCtrl.GetCheck(H68);
		checkbox_state_now.fzx_xd1= m_treeCtrl.GetCheck(H69);
		checkbox_state_now.fzx_xd2= m_treeCtrl.GetCheck(H6_10);
		checkbox_state_now.fzx_xd3= m_treeCtrl.GetCheck(H6_11);
		checkbox_state_now.fzx_dybgrq = m_treeCtrl.GetCheck(H6_14);

		//if (checkbox_state_now.basic_info_gspmc){
		//	MessageBox(TEXT("hh"));
		//}
		//else {
		//	MessageBox(TEXT("gg"));
		//}


		::SendMessage(my_second_wnd_l2r, WM_LEFTPREVIEW, 0, 0);
}


void SET_YL_JLGS_LEFT::OnNMRClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码

	

	HTREEITEM   hSelect = m_treeCtrl.GetSelectedItem();
	HTREEITEM   hLight = m_treeCtrl.GetDropHilightItem();
	if (hLight != NULL && hSelect != hLight)
		hSelect = hLight;
	if (hSelect == NULL)
		return;
	m_treeCtrl.SelectItem(hSelect);

	if (m_treeCtrl.GetSelectedItem() == H1) {
	
		m_tree_h1 h1;
		h1.DoModal();
	}
	if (m_treeCtrl.GetSelectedItem() == H2) {
		
		m_tree_h2 h2;
		h2.DoModal();
	}
	if (m_treeCtrl.GetSelectedItem() == H3) {
		m_tree_h3 h3;
		h3.DoModal();
	}
	if (m_treeCtrl.GetSelectedItem() == H4) {
		m_tree_h4 h4;
		h4.DoModal();
	}
	if (m_treeCtrl.GetSelectedItem() == H5) {
		m_tree_h5 h5;
		h5.DoModal();
	}
	if (m_treeCtrl.GetSelectedItem() == H6) {
		m_tree_h6 h6;
		h6.DoModal();
	}


	*pResult = 0;
}
