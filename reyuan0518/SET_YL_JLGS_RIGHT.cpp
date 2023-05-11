// SET_YL_JLGS_RIGHT.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "SET_YL_JLGS_RIGHT.h"


// SET_YL_JLGS_RIGHT

IMPLEMENT_DYNCREATE(SET_YL_JLGS_RIGHT, CFormView)

SET_YL_JLGS_RIGHT::SET_YL_JLGS_RIGHT()
	: CFormView(SET_YL_JLGS_RIGHT::IDD)
{

}

SET_YL_JLGS_RIGHT::~SET_YL_JLGS_RIGHT()
{
}

void SET_YL_JLGS_RIGHT::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(SET_YL_JLGS_RIGHT, CFormView)
	ON_WM_PAINT()
	ON_WM_SIZE()

	ON_MESSAGE(WM_LEFTPREVIEW, OnLEFTPREVIEWClick)
END_MESSAGE_MAP()


// SET_YL_JLGS_RIGHT 诊断

#ifdef _DEBUG
void SET_YL_JLGS_RIGHT::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void SET_YL_JLGS_RIGHT::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// SET_YL_JLGS_RIGHT 消息处理程序





void SET_YL_JLGS_RIGHT::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类

	my_second_wnd_l2r=this->GetSafeHwnd();


	HDC hdc = ::GetDC(m_hWnd);
	int w = GetDeviceCaps(hdc, HORZSIZE); // 指物理设备水平方向的宽度
	int h = GetDeviceCaps(hdc, VERTSIZE); // 指物理设备水平方向的高度

	// 指物理设备每英寸有多少个显示点
	w = GetDeviceCaps(hdc, LOGPIXELSX);
	h = GetDeviceCaps(hdc, LOGPIXELSY);

	/*
	根据A4纸尺寸是210毫米×297毫米，而1英寸=2.54厘米，
	我们可以得出当分辨率是多少像素时，得出A4纸大小尺寸为多少毫米。如下是我们较长用到的规格尺寸：
	*/

	// 由于电脑显示显示不了这么大图片，因此我们将其宽高缩小一半
	float attenuation = 1.7f;
	a4w_in_pixel = (int)(w * 210 / 25.4 / attenuation);
	a4h_in_pixel = (int)(h * 297 / 25.4 / attenuation);
	::ReleaseDC(m_hWnd, hdc);

	RECT rect;
	GetWindowRect(&rect);


	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);

 


}

void ShowItem(CDC* pDC, char *pTitle, char *pContent, int x, int y, LOGFONT CurrentIf)
{
	CFont font;


	CFont *pOldFont;

	CurrentIf.lfWeight = 600;

	font.CreateFontIndirect(&CurrentIf);
	pOldFont = pDC->SelectObject(&font);


	CString STR(pTitle);
	// 显示title
	pDC->TextOut(x, y, STR);

	CSize size = pDC->GetTextExtent(STR);
	
	// 显示content;
	font.DeleteObject();

	CurrentIf.lfWeight = 500;
	font.CreateFontIndirect(&CurrentIf);
	pOldFont = pDC->SelectObject(&font);

	CString STR2(pContent);
	if (pContent)
		pDC->TextOut(x + size.cx, y, STR2);

	font.DeleteObject();
	pDC->SelectObject(pOldFont);
}

struct MyRect
{
	int x;
	int y;
	int w;
	int h;
};

void MyPrinter(CDC* pDC,CRect mRECT,
	BOOL isPreView,
	BOOL isShowSelectPrinter,
	const char *  pCheckOrgan = "右脚后根键肌骨头"
)
{
	int Doc_W = 0;
	int Doc_H = 0;
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));       // zero out structure



	

	CFont font;
	CFont *pOldFont;
	CPen pen;
	CPen *pOldPen;
	int penW = 1;

	int strat_y = 20;
	int left_margin = 20;
	int right_margin = 20;


	const int basic_info_max_chars = 30;


	int symptomsDesp_h = 96;

	int cur_y = strat_y;

	TEXTMETRIC metrics;
	BOOL ret = FALSE;
	HANDLE  handle = NULL;
	CSize size;
	CPoint point;
	TEXTMETRIC tm;
	CString str;

	// for real printer
	CDC MemDc;
	HDC hdcPrint = NULL;
	CPrintDialog dlg(FALSE);
	int nPaperSize_X = 1;
	int nPaperSize_Y = 1;
	float coefficient = 1;

	if (!isPreView)
	{

		symptomsDesp_h = 160;

		if (isShowSelectPrinter)
		{
			dlg.DoModal();
			hdcPrint = dlg.GetPrinterDC();
			if (!hdcPrint)
			{
				::MessageBox(0, TEXT("获取打印机失败"), TEXT("注意"), MB_OK);
				return;
			}
		}
		else	// 否则使用默认打印机
		{
			PRINTDLG printInfo;
			ZeroMemory(&printInfo, sizeof(printInfo));  //清空该结构
			printInfo.lStructSize = sizeof(printInfo);
			printInfo.hwndOwner = 0;
			printInfo.hDevMode = 0;
			printInfo.hDevNames = 0;
			//这个是关键，PD_RETURNDC 如果不设这个标志，就拿不到hDC了
			//PD_RETURNDEFAULT 这个就是得到默认打印机，不需要弹出设置对话框
			printInfo.Flags = PD_RETURNDC | PD_RETURNDEFAULT | PD_ALLPAGES;

			PrintDlg(&printInfo);//调用API拿出默认打印机
			DWORD rst = CommDlgExtendedError();//看看出错没有
			if (rst != 0)
			{//出错了，清空标志再次调用API，此时就会弹出打印设置对话框供用户选择了
				printInfo.Flags = 0;
				PrintDlg(&printInfo);
			}

			hdcPrint = printInfo.hDC; //得到打印DC，输出到打印

			if (!hdcPrint)
			{
				::MessageBox(0, TEXT("获取打印机失败"), TEXT("注意"), MB_OK);
				return;
			}
		}
		// 将hDC句柄挂在到cdc对象上;
		MemDc.Attach(hdcPrint);
		nPaperSize_X = MemDc.GetDeviceCaps(HORZSIZE);    // 纸张宽度
		nPaperSize_Y = MemDc.GetDeviceCaps(VERTSIZE);    // 纸张高度
		int xP = GetDeviceCaps(MemDc.m_hDC, LOGPIXELSX);	//x方向每英寸像素点数
		int yP = GetDeviceCaps(MemDc.m_hDC, LOGPIXELSY);	//y方向每英寸像素点数
		int xPix = (DOUBLE)xP * 10 / 254;	//每 mm 宽度的像素
		int yPix = (DOUBLE)yP * 10 / 254;	//每 mm 高度的像素

		// 计算以像素点为单位的宽与高
		Doc_W = xPix*nPaperSize_X;
		Doc_H = yPix*nPaperSize_Y;

		// reset parameter
		coefficient = (float)xP / GetDeviceCaps(pDC->m_hDC, LOGPIXELSX);

		lf.lfHeight = 26 * coefficient;
		strat_y = 30 * coefficient;
		left_margin = 60 * coefficient;
		right_margin = 20 * coefficient;
		symptomsDesp_h *= coefficient;

		// end
		pDC = &MemDc;

		if (MemDc.m_hDC == NULL)
		{
			::MessageBox(0, TEXT("获取打印机失败"), TEXT("注意"), MB_OK);
			return;
		}

		static DOCINFO di = { sizeof(DOCINFO), TEXT("诊断报告") };
		if (MemDc.StartDoc(&di) < 0) // startdoc-----enddoc
		{
			MessageBox(0, TEXT("初始化打印机失败"), NULL, MB_OK);
			return;
		}

		if (MemDc.StartPage() < 0)
		{
			MessageBox(0, TEXT("打印失败"), NULL, MB_OK);
			MemDc.AbortDoc();
			return;
		}
	}
	else
	{
		RECT wrect;
		pDC->GetWindow()->GetWindowRect(&wrect);
		pDC->GetWindow()->ScreenToClient(&wrect);

		Doc_W = wrect.right - wrect.left;
		Doc_H = wrect.bottom - wrect.top;

		nPaperSize_X = pDC->GetDeviceCaps(HORZSIZE);    // 纸张宽度
		nPaperSize_Y = pDC->GetDeviceCaps(VERTSIZE);    // 纸张高度
		int xP = GetDeviceCaps(pDC->m_hDC, LOGPIXELSX);	//x方向每英寸像素点数
		int yP = GetDeviceCaps(pDC->m_hDC, LOGPIXELSY);	//y方向每英寸像素点数
		int xPix = (DOUBLE)xP * 10 / 254;	//每 mm 宽度的像素
		int yPix = (DOUBLE)yP * 10 / 254;	//每 mm 高度的像素
	}


	cur_y = strat_y;
	font.CreateFontIndirect(&lf);
	pOldFont = pDC->SelectObject(&font);



	double y_basic = (mRECT.bottom - mRECT.top) / 100;//定义y基本刻度
	double x_basic = (mRECT.right - mRECT.left) / 100;//定义x基本刻度

	double left_margin_new = mRECT.left + x_basic * 4;//定义左边缘
	double right_margin_new = mRECT.right - x_basic * 4;//定义右边缘

	if (!isPreView)
		pen.CreatePen(PS_SOLID, penW*coefficient, RGB(0, 0, 0));
	else
		pen.CreatePen(PS_SOLID, penW, RGB(0, 0, 0));

	pOldPen = pDC->SelectObject(&pen);

	cur_y = strat_y + 50;

	point.x = mRECT.left + x_basic * 4;
	point.y = mRECT.top + y_basic * 5;
	

	cur_y = point.y;

	// 画分割线1
	if (checkbox_state_now.fzx_xd1) {
		
		pDC->MoveTo(point);
		point.x = mRECT.right - x_basic * 4;
		point.y = cur_y;
		pDC->LineTo(point);		
	}
	pDC->SelectObject(pOldFont);
	font.DeleteObject();

	//标题居中显示
	CString STR(TEXT("热原检查记录"));
	CSize title_size = pDC->GetTextExtent(STR);//获取标题的size
	int weizhi_x_title = (mRECT.right - mRECT.left) / 2 + mRECT.left;
	font.CreateFont(23,  // 字体的高度   
		0,               // 字体的宽度  
		0,               // nEscapement 
		0,               // nOrientation   
		FW_NORMAL,       // nWeight 字体的粗细
		FALSE,           // bItalic 字体是否斜体  
		FALSE,           // bUnderline 是否有下划线 
		0,               // cStrikeOut 是否有删除线  
		ANSI_CHARSET,    // nCharSet   使用的字符集
		OUT_DEFAULT_PRECIS, //nOutPrecision  指定怎样选择合适的字体 
		CLIP_DEFAULT_PRECIS, //nClipPrecision  确定裁剪的精度 
		DEFAULT_QUALITY,     //nQuality  怎么样跟选择的字体相符合
		DEFAULT_PITCH | FF_SWISS,//nPitchAndFamily  间距标志和属性标志   
		_T("黑体"));

	pDC->SelectObject(&font);
	if (checkbox_state_now.jlbt) {
		pDC->TextOut(weizhi_x_title - title_size.cx, cur_y + y_basic, STR, STR.GetLength());
	}




	cur_y += 4 * y_basic ;//更新cur_y
	if (checkbox_state_now.basic_info_gspmc) {
		ShowItem(pDC, "供试品名称: ", (char*)pCheckOrgan, left_margin_new, cur_y, lf);
	}
	if (checkbox_state_now.basic_info_ypbh) {
		ShowItem(pDC, "样品编号: ", (char*)pCheckOrgan, weizhi_x_title + title_size.cx / 2, cur_y, lf);
	}
	

	cur_y +=  y_basic + title_size.cy;//更新cur_y
	if (checkbox_state_now.basic_info_ph) {
		ShowItem(pDC, "批号: ", (char*)pCheckOrgan, left_margin_new, cur_y, lf);
	}
	if (checkbox_state_now.basic_info_yptgdw) {
		ShowItem(pDC, "样品提供单位: ", (char*)pCheckOrgan, weizhi_x_title + title_size.cx / 2, cur_y, lf);
	}
	

	cur_y += y_basic + title_size.cy;//更新cur_y
	if (checkbox_state_now.basic_info_gg) {
		ShowItem(pDC, "规格: ", (char*)pCheckOrgan, left_margin_new, cur_y, lf);
	}
	if (checkbox_state_now.fzx_wb1_yqmc) {
		ShowItem(pDC, "仪器名称: ", "微机热原温仪", weizhi_x_title + title_size.cx / 2, cur_y, lf);
	}
	
	cur_y += y_basic + title_size.cy;//更新cur_y
	if (checkbox_state_now.basic_info_jl) {
		ShowItem(pDC, "剂量: ", (char*)pCheckOrgan, left_margin_new, cur_y, lf);
	}
	if (checkbox_state_now.fzx_wb2_yqxh) {
		ShowItem(pDC, "仪器型号: ", "WRY-2015", weizhi_x_title + title_size.cx / 2, cur_y, lf);
	}
	

	cur_y += y_basic + title_size.cy;//更新cur_y
	if (checkbox_state_now.basic_info_syrq) {
		ShowItem(pDC, "试验日期: ", (char*)pCheckOrgan, left_margin_new, cur_y, lf);
	}
	
	ShowItem(pDC, "设备编号: ", "A21001", weizhi_x_title + title_size.cx / 2, cur_y, lf);

	cur_y += y_basic + title_size.cy;//更新cur_y
	ShowItem(pDC, "检验依据: ", "GB2015-2003", left_margin_new, cur_y, lf);
	ShowItem(pDC, "室温: ", (char*)pCheckOrgan, weizhi_x_title + title_size.cx / 2, cur_y, lf);

	cur_y += y_basic + title_size.cy;//更新cur_y
	if (checkbox_state_now.basic_info_syff) {
		ShowItem(pDC, "试验方法: ", (char*)pCheckOrgan, left_margin_new, cur_y, lf);
	}
	
	ShowItem(pDC, "时间阈值: ", (char*)pCheckOrgan, weizhi_x_title + title_size.cx / 2, cur_y, lf);
	ShowItem(pDC, "温度阈值: ", (char*)pCheckOrgan, weizhi_x_title + 2*title_size.cx , cur_y, lf);

	cur_y += y_basic + title_size.cy;//更新cur_y
	ShowItem(pDC, "供试溶液的配置: ", "供试济液的配制:取本品，按100mg加1%碳酸氢钠溶液2.3ml的比例加入1%碳酸氢钠无热原溶液，在50℃", left_margin_new, cur_y, lf);
	cur_y += y_basic + title_size.cy;//更新cur_y
	ShowItem(pDC, "", "水浴振摇使溶解，再加氧化钠注射液制成每1ml含2.5mg的溶液，照《热原检查法标准操作规程》(文件编号 : GWZ - S0P80 - ", left_margin_new, cur_y, lf);
	cur_y += y_basic + title_size.cy;//更新cur_y
	ShowItem(pDC, "", "103) 检查，剂量按家兔体重每1kg注射1ml", left_margin_new, cur_y, lf);
	cur_y += y_basic + title_size.cy;//更新cur_y
	


	//if (!isPreView)
	//	lf.lfHeight = 17 * coefficient;
	//else
	//	lf.lfHeight = 14 * coefficient;                      // request a 12-pixel-height font


	// 画分割线
	point.x = left_margin_new;
	point.y = cur_y;
	pDC->MoveTo(point);

	point.x =right_margin_new;
	point.y = cur_y;
	pDC->LineTo(point);

	cur_y += y_basic;//更新cur_y
	
	
	//画表格1
	double biaoge1_top = cur_y;
	CPoint m_ptOrigin(left_margin_new, cur_y);
	CPoint point_bot_right(right_margin_new, cur_y + y_basic * 6);
	cur_y += y_basic * 6;//更新cur_y
	pDC->SelectObject(&pen);
	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush = pDC->SelectObject(pBrush);

	pDC->Rectangle(CRect(m_ptOrigin, point_bot_right));
	pDC->Rectangle(CRect(left_margin_new, cur_y, right_margin_new, cur_y + y_basic * 3));
	cur_y += y_basic * 3;//更新cur_y
	pDC->Rectangle(CRect(left_margin_new, cur_y, right_margin_new, cur_y + y_basic * 3));
	cur_y += y_basic * 3;//更新cur_y
	pDC->Rectangle(CRect(left_margin_new, cur_y, right_margin_new, cur_y + y_basic * 3));
	cur_y += y_basic * 3;//更新cur_y

	double biaoge1_bottom = cur_y;

	pDC->Rectangle(CRect(left_margin_new, biaoge1_top, left_margin_new+8*x_basic, biaoge1_bottom));
	pDC->Rectangle(CRect(left_margin_new + 8 * x_basic, biaoge1_top, left_margin_new + 25 * x_basic, biaoge1_bottom));
	for (int i = 0; i < 11; i++){
		pDC->Rectangle(CRect(left_margin_new + 25 * x_basic + i * 7 * x_basic, biaoge1_top, left_margin_new + 25 * x_basic + (i+1) * 7 * x_basic, biaoge1_bottom));
	}

	//画表格2
	cur_y += y_basic;//更新cur_y
	double biaoge2_top = cur_y;
	cur_y += y_basic * 3;//更新cur_y
	double biaoge2_bottom = cur_y;

	pDC->Rectangle(CRect(left_margin_new, biaoge2_top, right_margin_new, biaoge2_bottom));
	pDC->Rectangle(CRect(left_margin_new, biaoge2_top, left_margin_new + 22 * x_basic, biaoge2_bottom));
	pDC->Rectangle(CRect(left_margin_new + 35 * x_basic, biaoge2_top, left_margin_new +35 * x_basic+22 * x_basic, biaoge2_bottom));
	pDC->Rectangle(CRect(left_margin_new + 35 *2* x_basic, biaoge2_top, left_margin_new + 35*2 * x_basic + 22 * x_basic, biaoge2_bottom));
	pDC->SelectObject(pOldBrush);

	pDC->SelectObject(pBrush);

	//画表格3
	cur_y += y_basic;//更新cur_y
	double biaoge3_top = cur_y;
	cur_y += y_basic * 15;//更新cur_y
	double biaoge3_bottom = cur_y;

	pDC->Rectangle(CRect(left_margin_new, biaoge3_top, right_margin_new, biaoge3_bottom));
	pDC->Rectangle(CRect(left_margin_new, biaoge3_top, right_margin_new, biaoge3_top + 6 * y_basic));
	pDC->Rectangle(CRect(left_margin_new, biaoge3_top + 9 * y_basic, right_margin_new, biaoge3_top + 12 * y_basic));
	
	
	pDC->Rectangle(CRect(left_margin_new, biaoge3_top, left_margin_new + 8 * x_basic, biaoge3_bottom));
	pDC->Rectangle(CRect(left_margin_new + 25 * x_basic, biaoge3_top, left_margin_new + 37 * x_basic, biaoge3_bottom));


	pDC->Rectangle(CRect(right_margin_new - 12 * x_basic, biaoge3_top, right_margin_new, biaoge3_bottom));
	pDC->Rectangle(CRect(right_margin_new - 36 * x_basic, biaoge3_top, right_margin_new - 24 * x_basic, biaoge3_bottom));
	pDC->Rectangle(CRect(right_margin_new - 48 * x_basic, biaoge3_top, right_margin_new, biaoge3_bottom));




	// 画分割线
	point.x = left_margin_new;
	point.y = mRECT.bottom-y_basic*6;
	pDC->MoveTo(point);
	point.x = right_margin_new;
	point.y = mRECT.bottom - y_basic * 6;
	pDC->LineTo(point);


	//画操作人/日期
	if (checkbox_state_now.fzx_wb4_czr) {
		ShowItem(pDC, "操作人/日期: ", " ", left_margin_new, point.y - 3 * y_basic, lf);
	}

	//画复核人/日期
	if (checkbox_state_now.fzx_wb5_fhr) {
		ShowItem(pDC, "复核人/日期: ", " ", left_margin_new + 35 * x_basic, point.y - 3 * y_basic, lf);
	}
	
	//画审核人/日期
	if (checkbox_state_now.fzx_wb6_shr) {
		ShowItem(pDC, "审核人/日期: ", " ", left_margin_new + 70 * x_basic, point.y - 3 * y_basic, lf);
	}
	


	//画打印时间
	ShowItem(pDC, "Printed time: ", " ", right_margin_new - 35 * x_basic, point.y + y_basic, lf);


	if (!isPreView)
	{
		MemDc.EndDoc();
		MemDc.Detach();
		DeleteDC(hdcPrint);
	}
}


void SET_YL_JLGS_RIGHT::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//// TODO:  在此处添加消息处理程序代码


	CRect   rect;
	GetClientRect(rect);
	CRect mrect(CRect(rect.left+20, rect.top+35, rect.left+20 + a4w_in_pixel * 1.5, rect.top + 35+a4h_in_pixel * 1.5));

	dc.FillSolidRect(mrect, RGB(255, 255, 255));     //设置为白色背景  


	CFormView::OnPaint();

	goto repaint;
	repaint:  MessageBox(TEXT("kk"));

	//MyPrinter(&dc, mrect,TRUE, FALSE);

}


void SET_YL_JLGS_RIGHT::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	RECT rect;
	GetWindowRect(&rect);
	ScreenToClient(&rect);
	RECT rectitem;
	if (GetDlgItem(IDOK))
	{

		GetDlgItem(IDOK)->GetWindowRect(&rectitem);
		int w = rectitem.right - rectitem.left;
		int h = rectitem.bottom - rectitem.top;

		GetDlgItem(IDOK)->MoveWindow(rect.right - w, rect.bottom - h, w, h);
	}


}

LRESULT SET_YL_JLGS_RIGHT::OnLEFTPREVIEWClick(WPARAM wParam, LPARAM lParam)
{

	//MessageBox(TEXT("hh"));
	CPaintDC dc(this);

	CRect   rect;
	//GetClientRect(rect);
	CRect mrect(CRect(rect.left + 20, rect.top + 35, rect.left + 20 + a4w_in_pixel * 1.5, rect.top + 35 + a4h_in_pixel * 1.5));

	//dc.FillSolidRect(mrect, RGB(255, 255, 255));     //设置为白色背景  


	//CFormView::OnPaint();

	MyPrinter(&dc, mrect,TRUE, FALSE);

	

	return 0;
}