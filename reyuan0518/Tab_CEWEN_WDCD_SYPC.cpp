// Tab_CEWEN_WDCD_SYPC.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "Tab_CEWEN_WDCD_SYPC.h"
#include "afxdialogex.h"

#include "Quanjv.h"

#include "SYPC_XZGSP.h"

// Tab_CEWEN_WDCD_SYPC 对话框

IMPLEMENT_DYNAMIC(Tab_CEWEN_WDCD_SYPC, CDialogEx)

Tab_CEWEN_WDCD_SYPC::Tab_CEWEN_WDCD_SYPC(CWnd* pParent /*=NULL*/)
	: CDialogEx(Tab_CEWEN_WDCD_SYPC::IDD, pParent)
	, TTH_cstring(_T(""))
	, TH_cstring(_T(""))
	, TZ_cstring(_T(""))
	, SYFF_cstring(_T(""))
{

}

Tab_CEWEN_WDCD_SYPC::~Tab_CEWEN_WDCD_SYPC()
{
}

void Tab_CEWEN_WDCD_SYPC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, TTH_cstring);
	DDX_Control(pDX, IDC_EDIT1, TTH_control);
	DDX_Control(pDX, IDC_COMBO1, SYFF_combobox_control);
	DDX_Text(pDX, IDC_EDIT3, TH_cstring);
	DDX_Text(pDX, IDC_EDIT5, TZ_cstring);
	DDX_Control(pDX, IDC_EDIT3, TH_control);
	DDX_Control(pDX, IDC_EDIT5, TZ_control);
	DDX_CBString(pDX, IDC_COMBO1, SYFF_cstring);
	DDX_Control(pDX, IDC_LIST2, m_ListCtrl);
}


BEGIN_MESSAGE_MAP(Tab_CEWEN_WDCD_SYPC, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Tab_CEWEN_WDCD_SYPC::OnBnClickedButton1)
	
	ON_BN_CLICKED(IDC_BUTTON4, &Tab_CEWEN_WDCD_SYPC::OnBnClickedButton4)

	ON_MESSAGE(WM_USER_BUTTON_CLICKED, OnListCtrlButtonClicked)

	ON_WM_SIZE()
	ON_WM_MOUSEWHEEL()
	ON_WM_NCCALCSIZE()
	ON_WM_KILLFOCUS()

	ON_NOTIFY(NM_CLICK, IDC_LIST2, &Tab_CEWEN_WDCD_SYPC::OnNMClickList2)
	ON_WM_TIMER()
	ON_CBN_SELCHANGE(IDC_COMBO1, &Tab_CEWEN_WDCD_SYPC::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON5, &Tab_CEWEN_WDCD_SYPC::OnBnClickedButton5)


	ON_MESSAGE(WM_CHILDFRAMEDBCLK, OnChlidFrameDBClick)
END_MESSAGE_MAP()


// Tab_CEWEN_WDCD_SYPC 消息处理程序


UINT XferLoop1(LPVOID params) {

	OVERLAPPED outOvLap, inOvLap;

	Tab_CEWEN_WDCD_SYPC *dlg = (Tab_CEWEN_WDCD_SYPC *)params;


	char s[1024];						ZeroMemory(s, 1024);

	LONG xfer = 1024;
	PUCHAR data = new UCHAR[xfer];	ZeroMemory(data, xfer);
	PUCHAR inData = new UCHAR[xfer];	ZeroMemory(inData, xfer);

	outOvLap.hEvent = CreateEvent(NULL, false, false, TEXT("CYUSB_OUT"));
	inOvLap.hEvent = CreateEvent(NULL, false, false, TEXT("CYUSB_IN"));



	bool success;
	LONG nSuccess = 0;
	LONG nFailure = 0;


	dlg->OutEndpt->TimeOut = 2000;
	dlg->InEndpt->TimeOut = 2000;

	//dlg->SetDlgItemText(IDC_EDIT1, TEXT(""));

	for (; dlg->bLooping;) {
		LONG outlen, inlen, len;

		outlen = inlen = len = xfer;     // Use temp var because XferData can change the value of len
		data[0] = 0xeb;
		data[1] = 0x90;
		outlen = 2;
		//UCHAR  *outContext = dlg->OutEndpt->BeginDataXfer(data, outlen, &outOvLap);
		UCHAR  *outContext = dlg->OutEndpt->BeginDataXfer(data, outlen, &outOvLap);
		UCHAR  *inContext = dlg->InEndpt->BeginDataXfer(inData, inlen, &inOvLap);

		dlg->OutEndpt->WaitForXfer(&outOvLap, 2000);
		dlg->InEndpt->WaitForXfer(&inOvLap, 2000);

		success = dlg->OutEndpt->FinishDataXfer(data, outlen, &outOvLap, outContext);
		success = dlg->InEndpt->FinishDataXfer(inData, inlen, &inOvLap, inContext);


		if (inlen > 0) {


			for (int i = 0; i < PointNum; i++) {
				
				if (point_ifstart_now[i].ifstart == 1) {
					
					point_ifstart_now[i].t_real = point_temperature_now[i].a + point_temperature_now[i].b * inData[Protocol[i]];


				}
			}

			

		}
		Sleep(1);
	}

	CloseHandle(outOvLap.hEvent);
	CloseHandle(inOvLap.hEvent);

	delete[] data;
	delete[] inData;


	dlg->XferThread = NULL;


	return true;
}


BOOL Tab_CEWEN_WDCD_SYPC::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	
	my_wnd = this->GetSafeHwnd();

	//设置试验方法下拉框的选项
	SYFF_combobox_control.AddString(TEXT("正式试验"));
	SYFF_combobox_control.AddString(TEXT("ChP新兔挑选"));
	SYFF_combobox_control.AddString(TEXT("EP新兔挑选"));
	SYFF_combobox_control.AddString(TEXT("USP新兔挑选"));
	

	


	//list2
	m_ListCtrl.SetShowCheckBoxSign(TRUE);//设置内容行是否显示复选 框
	m_ListCtrl.SetSingleRowCheck(FALSE);//设置单击行是否可以选择复选框
	m_ListCtrl.SetRowHeight(35);               //设置行高度

	m_ListCtrl.SetHeaderBKColor(234, 243, 248, 1); //设置头部背景色



	m_ListCtrl.InsertColumn(0, _T(""), LVCFMT_CENTER, 0);
	m_ListCtrl.InsertColumn(1, _T("注射完成"), LVCFMT_CENTER, 80, FALSE, TRUE);
	m_ListCtrl.InsertColumn(2, _T("操作"), LVCFMT_CENTER, 80, FALSE, TRUE);//可编辑(加入编辑框)
	m_ListCtrl.InsertColumn(3, _T("探头号"), LVCFMT_CENTER,80);//可编辑(加入编辑框)
	m_ListCtrl.InsertColumn(4, _T("兔号"), LVCFMT_CENTER, 80);
	m_ListCtrl.InsertColumn(5, _T("体重"), LVCFMT_CENTER, 80);
	m_ListCtrl.InsertColumn(6, _T("剂量"), LVCFMT_CENTER, 80,1);
	m_ListCtrl.InsertColumn(7, _T("全部时间"), LVCFMT_CENTER, 80);
	m_ListCtrl.InsertColumn(8, _T("注射后时间"), LVCFMT_CENTER, 80);
	m_ListCtrl.InsertColumn(9, _T("实时温度"), LVCFMT_CENTER, 80); 
	m_ListCtrl.InsertColumn(10, _T("均温"), LVCFMT_CENTER,85);
	m_ListCtrl.InsertColumn(11, _T("温差"), LVCFMT_CENTER, 85);
	m_ListCtrl.InsertColumn(12, _T("试验方法"), LVCFMT_CENTER,85);
	m_ListCtrl.InsertColumn(13, _T("供试品名称"), LVCFMT_CENTER, 105, FALSE, TRUE);
	m_ListCtrl.InsertColumn(14, _T("样品编号"), LVCFMT_CENTER, 75);
	m_ListCtrl.InsertColumn(15, _T("批号"), LVCFMT_CENTER, 75);


	CString str1;
	for (int i = 0; i < PointNum ; i++)
	{
		m_ListCtrl.InsertItem(i, TEXT(""));
		m_ListCtrl.SetItemText(i, 1, _T("确认"));
		m_ListCtrl.SetItemText(i, 2, _T("开始"));
		//把获取进来的数据插进去

		str1.Format(_T("%d"), i + 1);//将整形转换为cstring并存在str中
		m_ListCtrl.SetItemText(i, 3, str1);

		m_ListCtrl.SetItemColor(13, i, RGB(0, 0, 255)); //设置供试品名称背景色

	}

	







	//m_ListCtrl.SetHeaderCheckedState(1);//头部是否显示复选框0:NO CHECKBOX；1：未选 中；2：选 中
	//m_ListCtrl.SetHeaderHeight(2);          //设置头部高度
	//m_ListCtrl.SetHeaderFontHW(16, 0);         //设置头部字体高度,和宽度,0表示缺省，自适应 
	//m_ListCtrl.SetHeaderTextColor(RGB(0, 0, 0)); //设置头部字体颜色
	//m_ListCtrl.SetHeaderBKColor(234, 243, 248, 1); //设置头部背景色
	//m_ListCtrl.SetShowCheckBoxSign(TRUE);//设置内容行是否显示复选 框
	//m_ListCtrl.SetSingleRowCheck(FALSE);//设置单击行是否可以选择复选框
	////m_ListCtrl.SetColColor(0,RGB(10,150,20)); //设置列背景色
	////m_ListCtrl.SetColColor(2,RGB(30,100,90)); //设置列背景色
	////m_ListCtrl.SetBkColor(RGB(233,243,248));        //设置背景色
	//m_ListCtrl.SetItemColor(1,1,RGB(255,0,0)); //设置指定单元背景色
	//m_ListCtrl.SetItemColor(2, 1, RGB(100, 100, 10)); //设置指定单元背景色
	//m_ListCtrl.SetItemColor(15, 1, RGB(100, 100, 10)); //设置指定单元背景色
	//m_ListCtrl.SetRowHeight(35);               //设置行高度
	//m_ListCtrl.SetTextColor(RGB(0, 0, 0));  //设置文本颜色
	//m_ListCtrl.SetFontHW(20, 0);               //设置字体高度，和宽度,0表示缺省宽度
	////m_ListCtrl.SetColTextColor(2,RGB(255,255,100)); //设置列文本颜色
	////m_ListCtrl.SetItemTextColor(3,1,RGB(255,0,0));  //设置单元格字体颜色(col,row,color)



		 //连接cyusb
			mCCyUsbDevice = new CCyUSBDevice(NULL);//实例化对象

			//TRACE("%d\n", mCCyUsbDevice->DeviceCount());
			if (!mCCyUsbDevice->Open(0)) //打开失败
			{
				//TRACE("USB未连接");
			}
			if (mCCyUsbDevice->DeviceCount())   //保证至少有一个USB设备连接  
			{
				for (int i = 0; i < mCCyUsbDevice->DeviceCount(); i++)    //枚举所有USB设备  
				{
					mCCyUsbDevice->Open(i);                   //打开第i号USB设备  
					//TRACE("%s\n", mCCyUsbDevice->DeviceName);//所选择的当前设备名  
				}
			}
			else {
				return 0;
			}
		
			OutEndpt = mCCyUsbDevice->EndPoints[1];
			InEndpt = mCCyUsbDevice->EndPoints[3];
		
			bLooping = true;
			XferThread = AfxBeginThread(XferLoop1, this);




	


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


/*按钮点击消息，内容改变之后，进行消息处理*/
LRESULT Tab_CEWEN_WDCD_SYPC::OnListCtrlButtonClicked(WPARAM wParam, LPARAM lParam)
{
	ListCtrlColButton *pInfo = (ListCtrlColButton *)lParam;

	CString str;

	CString str_syff(m_ListCtrl.GetItemText(pInfo->row, 12));//获取对应的实验方法

	

	//CString str_ifstart;//

	CString zssy(TEXT("正式试验"));
	CString chp(TEXT("Chp新兔挑选"));
	CString ep(TEXT("Ep新兔挑选"));

	if (str_syff != TEXT("")) {

		switch (pInfo->col)
		{
		
		case 1://确认按钮
			
					if (point_ifstart_now[pInfo->row].ifstart!=1) //判断是否已经开始
					{
						AfxMessageBox(TEXT("请先点击开始按钮！"));
					}
					else {
						
							CString str_gspmc(m_ListCtrl.GetItemText(pInfo->row, 13));//获取对应的供试品名称

							if (str_gspmc != _T("")) //当选择完供试品，即可确认
							{
								str.Format(_T("%d号探头已确认！"), pInfo->row + 1);
								AfxMessageBox(str);
								m_ListCtrl.SetItemText(pInfo->row, 1, _T("已确认"));

								//做对应确认要做的事		
								point_ifstart_now[pInfo->row].ifconfirm = 1;

								//将列表全部信息同步至数据库
								MyDatabase mydatabase;

								if (!mydatabase.ConnectDB_orcreate())//判断是否连接数据库成功
								{
									AfxMessageBox(_T("数据库连接失败!"));

								}
								else {
									CString str_tuhao(m_ListCtrl.GetItemText(pInfo->row, 4));//兔号
									CString str_tizhong(m_ListCtrl.GetItemText(pInfo->row, 5));//体重
									CString str_jiliang(m_ListCtrl.GetItemText(pInfo->row, 6));//剂量
									CString str_qbsj(m_ListCtrl.GetItemText(pInfo->row, 7));//全部时间
									CString str_zshsj(m_ListCtrl.GetItemText(pInfo->row, 8));//注射后时间
									CString str_sswd(m_ListCtrl.GetItemText(pInfo->row, 9));//实时温度
									CString str_jw(m_ListCtrl.GetItemText(pInfo->row, 10));//均温
									CString str_wc(m_ListCtrl.GetItemText(pInfo->row, 11));//温差
									CString str_ssff(m_ListCtrl.GetItemText(pInfo->row, 12));//试验方法
									CString str_ypbh(m_ListCtrl.GetItemText(pInfo->row, 14));//样品编号
									CString str_ph(m_ListCtrl.GetItemText(pInfo->row, 15));//批号
									
									
									mydatabase.add_SYPC_info(pInfo->row + 1, str_tuhao, str_tizhong, str_jiliang, str_qbsj, str_zshsj, str_sswd, str_jw, str_wc, str_ssff, str_gspmc, str_ypbh, str_ph);
								}


							}
						
					}

			break;
		case 2://开始按钮
			

					str.Format(_T("%d号探头已开始！"), pInfo->row + 1);
					m_ListCtrl.SetItemText(pInfo->row, 2, _T("已开始"));
					//str_ifstart = TEXT("已开始");
					//point_ifstart_now[pInfo->row].str_ifstart = TEXT("已开始");

					point_ifstart_now[pInfo->row].ifstart = 1;

					if (!str_syff.CompareNoCase(zssy)) {//判断是否是正式实验
						//AfxMessageBox(TEXT("正式试验！"));
						point_ifstart_now[pInfo->row].syff = 1;
					}
					else if (!str_syff.CompareNoCase(chp)) {//判断是否是Chp新兔挑选
						//AfxMessageBox(TEXT("Chp新兔挑选！"));
						point_ifstart_now[pInfo->row].syff = 2;
					}
					else if (!str_syff.CompareNoCase(ep)) {//判断是否是Ep新兔挑选
						//AfxMessageBox(TEXT("Ep新兔挑选！"));
						point_ifstart_now[pInfo->row].syff = 3;
					}
					else {
						//AfxMessageBox(TEXT("USP新兔挑选！"));
						point_ifstart_now[pInfo->row].syff = 4;
					}




					SetTimer(1, 20000, NULL);      //参数：定时器标号，定时时间（ms）。启动定时器1，每隔20s刷新一次


			break;
	
		case 13://供试品名称按钮

					/*current_selected_point_gspmc_button = pInfo->row;
					SYPC_XZGSP xzgsp;
					xzgsp.DoModal();*///测试用代码，提前调出选择供试品窗口

					if (point_ifstart_now[pInfo->row].ifstart != 1) //判断是否已经开始
						{
							AfxMessageBox(TEXT("请先点击开始按钮！"));
						}
					else 
					{
						if (point_ifstart_now[pInfo->row].syff == 1) //正式实验
						{
							if (point_ifstart_now[pInfo->row].j >= 270)//到90min了
							{
								if (point_ifstart_now[pInfo->row].t_avereage >= 38.0&&point_ifstart_now[pInfo->row].t_avereage <= 39.6&&point_ifstart_now[pInfo->row].t_maxdif <= 0.2)//满足要求
								{
									//点击出现窗口选择供试品

									current_selected_point_gspmc_button = pInfo->row;//标记向哪一行添加信息

									SYPC_XZGSP xzgsp;
									xzgsp.DoModal();

								}
								else //不满足要求
								{
									//提示不满足要求，重新测

									MessageBox(TEXT("当采集温度已开始，均温和温差满足相应试验方法的要求后，才可选择供试品用于该兔的注射！"), TEXT("提示"), MB_ICONASTERISK|MB_OK);
								}

							}
							else//没到90min
							{
								MessageBox(TEXT("当采集温度已开始，均温和温差满足相应试验方法的要求后，才可选择供试品用于该兔的注射！"), TEXT("提示"), MB_ICONASTERISK | MB_OK);
							
							}

						}
						else//其他实验
						{
							if (point_ifstart_now[pInfo->row].j >= 270)//到90min了
							{
								//直接点击出现窗口选择供试品，无要求
								current_selected_point_gspmc_button = pInfo->row;
								SYPC_XZGSP xzgsp;
								xzgsp.DoModal();

							}
							else
							{
								MessageBox(TEXT("当采集温度已开始，测温至少90分钟后，才可选择供试品！"), TEXT("提示"), MB_ICONASTERISK | MB_OK);
							}
						}

					}

			
			break;
		}

		

	}
	else
	{
		AfxMessageBox(TEXT("请先补全探头所对应信息数据！"));
	}
	
	




	return 0;
}

void Tab_CEWEN_WDCD_SYPC::OnBnClickedButton1()//增加
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(TRUE);


	/*UNICODE字符集用以下方式，数据被插入到数据库时不会出错,但是这种方式插入不了中文，可能也跟下面的insert语法有关*/
	char temp[100] = {};
	std::string str_1 = CStringA(TTH_cstring);
	strncpy_s(temp, _countof(temp), str_1.c_str(), TTH_cstring.GetLength());//这三行实现将cstring装换为char*

	if (atoi(temp) > 0 && atoi(temp) <= PointNum){
		int pos; //添加的位置
		
		CString str;//用来接收第i行所对应的探头号
		for (int i = 0; i < PointNum; i++)
		{
			
			str = m_ListCtrl.GetItemText(i, 3); //获取第i行所对应的探头号
			if (str == TTH_cstring){
				pos = i;
			}
		}


		//把获取进来的数据插进去
		if (TH_cstring == TEXT("") || TZ_cstring == TEXT(""))MessageBox(TEXT("兔号或体重不能为空"), TEXT("提示"));
		else{
			m_ListCtrl.SetItemText(pos, 4, TH_cstring);
			m_ListCtrl.SetItemText(pos, 5, TZ_cstring);

			if (SYFF_cstring == TEXT(""))MessageBox(TEXT("试验方法不能为空"), TEXT("提示"));
			else m_ListCtrl.SetItemText(pos, 12, SYFF_cstring);
		}

	}
	else{

		CString str2;
		str2.Format(_T("%d"),PointNum);//将整形转换为cstring并存在str2中
		str2.Format(TEXT("请输入在1到") + str2+ TEXT("之间的探头号"));//利用FORMAT拼接到一块
		MessageBox(str2, TEXT("提示"));
	}


}





void Tab_CEWEN_WDCD_SYPC::OnBnClickedButton4()//编正
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true); //把对话框中的信息更新到内存中去


	m_ListCtrl.SetItemText(m_listSelPos, 4, TH_cstring);

	m_ListCtrl.SetItemText(m_listSelPos, 5, TZ_cstring);
	
	m_ListCtrl.SetItemText(m_listSelPos, 12, SYFF_cstring);


}










void Tab_CEWEN_WDCD_SYPC::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码



}


BOOL Tab_CEWEN_WDCD_SYPC::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	
	

	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void Tab_CEWEN_WDCD_SYPC::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值



	CDialogEx::OnNcCalcSize(bCalcValidRects, lpncsp);
}


void Tab_CEWEN_WDCD_SYPC::OnKillFocus(CWnd* pNewWnd)
{
	CDialogEx::OnKillFocus(pNewWnd);

	// TODO: 在此处添加消息处理程序代码


}






void Tab_CEWEN_WDCD_SYPC::OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	m_listSelPos = m_ListCtrl.GetSelectionMark();


	TTH_cstring = m_ListCtrl.GetItemText(m_listSelPos, 3);//获取当前记录的显示的文本
	TTH_control.SetWindowTextW(TTH_cstring);//必须用cedit类型的才能调这个函数

	TH_cstring = m_ListCtrl.GetItemText(m_listSelPos, 4);//获取当前记录的显示的文本
	TH_control.SetWindowTextW(TH_cstring);//必须用cedit类型的才能调这个函数

	TZ_cstring = m_ListCtrl.GetItemText(m_listSelPos, 5);//获取当前记录的显示的文本
	TZ_control.SetWindowTextW(TZ_cstring);//必须用cedit类型的才能调这个函数

	SYFF_cstring = m_ListCtrl.GetItemText(m_listSelPos, 12);//获取当前记录的显示的文本
	SYFF_combobox_control.SetWindowTextW(SYFF_cstring);//必须用cedit类型的才能调这个函数
	*pResult = 0;




}


double average(double *x, int len)

{

	double sum = 0;

	for (int i = 0; i<len;i++)

		sum += x[i];

		return sum / len; // 返回平均值

}

double max_difference(double *arr, int arr_len)
{
	int i = 2;
	double min, max;
	if (arr[0] > arr[1])
	{
		max = arr[0];
		min = arr[1];
	}
	else
	{
		max = arr[1];
		min = arr[0];
	}

	for (; i < arr_len; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		else if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return (max - min);
}


void Tab_CEWEN_WDCD_SYPC::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值


	switch (nIDEvent)
	{
	case 1:   //定时器1
	{
		
		for (int i = 0; i < PointNum; i++) {

			if (point_ifstart_now[i].ifstart == 1) {
				 
				CString str_real_t;
				str_real_t.Format(_T("%.2f"), point_ifstart_now[i].t_real);

				CString str_total_t;
				str_total_t.Format(_T("%d"), (point_ifstart_now[i].j)/3);//每3个20s 1min

				(m_ListCtrl).SetItemText(i, 9, str_real_t);//往表格中传入实时温度

				(m_ListCtrl).SetItemText(i, 7, str_total_t);//往表格中传入全部时间

				point_ifstart_now[i].t_all[point_ifstart_now[i].j] = point_ifstart_now[i].t_real;//记录温度
				point_ifstart_now[i].j++;

				//当时间到90min时
				if (point_ifstart_now[i].j == 270) 
				{
					point_ifstart_now[i].t_avereage=average(point_ifstart_now[i].t_all, 90);//前三十分钟均温
					point_ifstart_now[i].t_maxdif = max_difference(point_ifstart_now[i].t_all, 90);//前三十分钟温差

					CString str_avereage_t;
					str_avereage_t.Format(_T("%.2f"), point_ifstart_now[i].t_avereage);

					CString str_maxdif_t;
					str_maxdif_t.Format(_T("%.2f"), point_ifstart_now[i].t_maxdif);

					(m_ListCtrl).SetItemText(i, 10, str_avereage_t);//往表格中传入均温
					(m_ListCtrl).SetItemText(i, 11, str_maxdif_t);//往表格中传入温差

					if (point_ifstart_now[i].t_avereage >= 38.0&&point_ifstart_now[i].t_avereage <= 39.6&&point_ifstart_now[i].t_maxdif <= 0.2)//当温差和均温符合要求时
					{
						for (int p = 1; p <= 15; p++)//将这一行背景颜色改变
						{
							m_ListCtrl.SetItemColor(p, i, RGB(255, 0, 0)); //设置指定单元背景色
						}
						
						//判断是什么实验方法，做出相应反应


					}
				}

				//当按下确认按钮后
				if (point_ifstart_now[i].ifconfirm == 1) 
				{	
					CString str_after_t;
					str_after_t.Format(_T("%d"), (point_ifstart_now[i].after_time) / 3);//每3个20s 1min
					(m_ListCtrl).SetItemText(i, 8, str_after_t);//往表格中传入注射后时间

					point_ifstart_now[i].after_time++;
				}



			}
		}


		break;
	}

	case 2:   //定时器2
	{
		
		break;
	}
	}


	CDialogEx::OnTimer(nIDEvent);
}


void Tab_CEWEN_WDCD_SYPC::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}






void Tab_CEWEN_WDCD_SYPC::OnBnClickedButton5()//结束测温
{
	// TODO: 在此添加控件通知处理程序代码


	

	if (MessageBox(TEXT("有一只家兔被选择，如果选择的家兔中有的被分配了供试品，那么在样品队列中的该家兔所对应的探头号也将同时被取消。家兔结束测温后，所获的温度数据将全部作废。确定要结束测温吗？"), TEXT("提示"), MB_ICONASTERISK | MB_OKCANCEL) == IDOK)
	{
		
		//清空此行数据
		for (int k = 4; k <= 15; k++) {
			m_ListCtrl.SetItemText(m_listSelPos, k, TEXT(""));
		}
		
		
		//清空该探头所对应数据
		point_ifstart_now[m_listSelPos].ifstart = 0;
		point_ifstart_now[m_listSelPos].j = 0;
		point_ifstart_now[m_listSelPos].t_real = 0;

	}

}

void Tab_CEWEN_WDCD_SYPC::PostNcDestroy()
{
	// TODO: 在此添加专用代码和/或调用基类

	//关闭设备
	for (int i = 0; i < mCCyUsbDevice->DeviceCount(); i++)    //枚举所有USB设备  
	{
		mCCyUsbDevice->Close();
		delete mCCyUsbDevice;
	}



	CDialogEx::PostNcDestroy();
}


LRESULT Tab_CEWEN_WDCD_SYPC::OnChlidFrameDBClick(WPARAM wParam, LPARAM lParam)
{


	select_GSP*my_gsp = (select_GSP*)(lParam);

	(m_ListCtrl).SetItemText(current_selected_point_gspmc_button , 13, my_gsp->str_gsp);//往表格中传入供试品名称
	(m_ListCtrl).SetItemText(current_selected_point_gspmc_button, 14, my_gsp->str_ypbh);//往表格中传入样品编号
	(m_ListCtrl).SetItemText(current_selected_point_gspmc_button, 15, my_gsp->str_ph);//往表格中传入批号


	return 0;
}