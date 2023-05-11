// SET_YL_JLGS_RIGHT.cpp : ʵ���ļ�
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


// SET_YL_JLGS_RIGHT ���

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


// SET_YL_JLGS_RIGHT ��Ϣ�������





void SET_YL_JLGS_RIGHT::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���

	my_second_wnd_l2r=this->GetSafeHwnd();


	HDC hdc = ::GetDC(m_hWnd);
	int w = GetDeviceCaps(hdc, HORZSIZE); // ָ�����豸ˮƽ����Ŀ��
	int h = GetDeviceCaps(hdc, VERTSIZE); // ָ�����豸ˮƽ����ĸ߶�

	// ָ�����豸ÿӢ���ж��ٸ���ʾ��
	w = GetDeviceCaps(hdc, LOGPIXELSX);
	h = GetDeviceCaps(hdc, LOGPIXELSY);

	/*
	����A4ֽ�ߴ���210���ס�297���ף���1Ӣ��=2.54���ף�
	���ǿ��Եó����ֱ����Ƕ�������ʱ���ó�A4ֽ��С�ߴ�Ϊ���ٺ��ס����������ǽϳ��õ��Ĺ��ߴ磺
	*/

	// ���ڵ�����ʾ��ʾ������ô��ͼƬ��������ǽ�������Сһ��
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
	// ��ʾtitle
	pDC->TextOut(x, y, STR);

	CSize size = pDC->GetTextExtent(STR);
	
	// ��ʾcontent;
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
	const char *  pCheckOrgan = "�ҽź��������ͷ"
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
				::MessageBox(0, TEXT("��ȡ��ӡ��ʧ��"), TEXT("ע��"), MB_OK);
				return;
			}
		}
		else	// ����ʹ��Ĭ�ϴ�ӡ��
		{
			PRINTDLG printInfo;
			ZeroMemory(&printInfo, sizeof(printInfo));  //��ոýṹ
			printInfo.lStructSize = sizeof(printInfo);
			printInfo.hwndOwner = 0;
			printInfo.hDevMode = 0;
			printInfo.hDevNames = 0;
			//����ǹؼ���PD_RETURNDC ������������־�����ò���hDC��
			//PD_RETURNDEFAULT ������ǵõ�Ĭ�ϴ�ӡ��������Ҫ�������öԻ���
			printInfo.Flags = PD_RETURNDC | PD_RETURNDEFAULT | PD_ALLPAGES;

			PrintDlg(&printInfo);//����API�ó�Ĭ�ϴ�ӡ��
			DWORD rst = CommDlgExtendedError();//��������û��
			if (rst != 0)
			{//�����ˣ���ձ�־�ٴε���API����ʱ�ͻᵯ����ӡ���öԻ����û�ѡ����
				printInfo.Flags = 0;
				PrintDlg(&printInfo);
			}

			hdcPrint = printInfo.hDC; //�õ���ӡDC���������ӡ

			if (!hdcPrint)
			{
				::MessageBox(0, TEXT("��ȡ��ӡ��ʧ��"), TEXT("ע��"), MB_OK);
				return;
			}
		}
		// ��hDC������ڵ�cdc������;
		MemDc.Attach(hdcPrint);
		nPaperSize_X = MemDc.GetDeviceCaps(HORZSIZE);    // ֽ�ſ��
		nPaperSize_Y = MemDc.GetDeviceCaps(VERTSIZE);    // ֽ�Ÿ߶�
		int xP = GetDeviceCaps(MemDc.m_hDC, LOGPIXELSX);	//x����ÿӢ�����ص���
		int yP = GetDeviceCaps(MemDc.m_hDC, LOGPIXELSY);	//y����ÿӢ�����ص���
		int xPix = (DOUBLE)xP * 10 / 254;	//ÿ mm ��ȵ�����
		int yPix = (DOUBLE)yP * 10 / 254;	//ÿ mm �߶ȵ�����

		// ���������ص�Ϊ��λ�Ŀ����
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
			::MessageBox(0, TEXT("��ȡ��ӡ��ʧ��"), TEXT("ע��"), MB_OK);
			return;
		}

		static DOCINFO di = { sizeof(DOCINFO), TEXT("��ϱ���") };
		if (MemDc.StartDoc(&di) < 0) // startdoc-----enddoc
		{
			MessageBox(0, TEXT("��ʼ����ӡ��ʧ��"), NULL, MB_OK);
			return;
		}

		if (MemDc.StartPage() < 0)
		{
			MessageBox(0, TEXT("��ӡʧ��"), NULL, MB_OK);
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

		nPaperSize_X = pDC->GetDeviceCaps(HORZSIZE);    // ֽ�ſ��
		nPaperSize_Y = pDC->GetDeviceCaps(VERTSIZE);    // ֽ�Ÿ߶�
		int xP = GetDeviceCaps(pDC->m_hDC, LOGPIXELSX);	//x����ÿӢ�����ص���
		int yP = GetDeviceCaps(pDC->m_hDC, LOGPIXELSY);	//y����ÿӢ�����ص���
		int xPix = (DOUBLE)xP * 10 / 254;	//ÿ mm ��ȵ�����
		int yPix = (DOUBLE)yP * 10 / 254;	//ÿ mm �߶ȵ�����
	}


	cur_y = strat_y;
	font.CreateFontIndirect(&lf);
	pOldFont = pDC->SelectObject(&font);



	double y_basic = (mRECT.bottom - mRECT.top) / 100;//����y�����̶�
	double x_basic = (mRECT.right - mRECT.left) / 100;//����x�����̶�

	double left_margin_new = mRECT.left + x_basic * 4;//�������Ե
	double right_margin_new = mRECT.right - x_basic * 4;//�����ұ�Ե

	if (!isPreView)
		pen.CreatePen(PS_SOLID, penW*coefficient, RGB(0, 0, 0));
	else
		pen.CreatePen(PS_SOLID, penW, RGB(0, 0, 0));

	pOldPen = pDC->SelectObject(&pen);

	cur_y = strat_y + 50;

	point.x = mRECT.left + x_basic * 4;
	point.y = mRECT.top + y_basic * 5;
	

	cur_y = point.y;

	// ���ָ���1
	if (checkbox_state_now.fzx_xd1) {
		
		pDC->MoveTo(point);
		point.x = mRECT.right - x_basic * 4;
		point.y = cur_y;
		pDC->LineTo(point);		
	}
	pDC->SelectObject(pOldFont);
	font.DeleteObject();

	//���������ʾ
	CString STR(TEXT("��ԭ����¼"));
	CSize title_size = pDC->GetTextExtent(STR);//��ȡ�����size
	int weizhi_x_title = (mRECT.right - mRECT.left) / 2 + mRECT.left;
	font.CreateFont(23,  // ����ĸ߶�   
		0,               // ����Ŀ��  
		0,               // nEscapement 
		0,               // nOrientation   
		FW_NORMAL,       // nWeight ����Ĵ�ϸ
		FALSE,           // bItalic �����Ƿ�б��  
		FALSE,           // bUnderline �Ƿ����»��� 
		0,               // cStrikeOut �Ƿ���ɾ����  
		ANSI_CHARSET,    // nCharSet   ʹ�õ��ַ���
		OUT_DEFAULT_PRECIS, //nOutPrecision  ָ������ѡ����ʵ����� 
		CLIP_DEFAULT_PRECIS, //nClipPrecision  ȷ���ü��ľ��� 
		DEFAULT_QUALITY,     //nQuality  ��ô����ѡ������������
		DEFAULT_PITCH | FF_SWISS,//nPitchAndFamily  ����־�����Ա�־   
		_T("����"));

	pDC->SelectObject(&font);
	if (checkbox_state_now.jlbt) {
		pDC->TextOut(weizhi_x_title - title_size.cx, cur_y + y_basic, STR, STR.GetLength());
	}




	cur_y += 4 * y_basic ;//����cur_y
	if (checkbox_state_now.basic_info_gspmc) {
		ShowItem(pDC, "����Ʒ����: ", (char*)pCheckOrgan, left_margin_new, cur_y, lf);
	}
	if (checkbox_state_now.basic_info_ypbh) {
		ShowItem(pDC, "��Ʒ���: ", (char*)pCheckOrgan, weizhi_x_title + title_size.cx / 2, cur_y, lf);
	}
	

	cur_y +=  y_basic + title_size.cy;//����cur_y
	if (checkbox_state_now.basic_info_ph) {
		ShowItem(pDC, "����: ", (char*)pCheckOrgan, left_margin_new, cur_y, lf);
	}
	if (checkbox_state_now.basic_info_yptgdw) {
		ShowItem(pDC, "��Ʒ�ṩ��λ: ", (char*)pCheckOrgan, weizhi_x_title + title_size.cx / 2, cur_y, lf);
	}
	

	cur_y += y_basic + title_size.cy;//����cur_y
	if (checkbox_state_now.basic_info_gg) {
		ShowItem(pDC, "���: ", (char*)pCheckOrgan, left_margin_new, cur_y, lf);
	}
	if (checkbox_state_now.fzx_wb1_yqmc) {
		ShowItem(pDC, "��������: ", "΢����ԭ����", weizhi_x_title + title_size.cx / 2, cur_y, lf);
	}
	
	cur_y += y_basic + title_size.cy;//����cur_y
	if (checkbox_state_now.basic_info_jl) {
		ShowItem(pDC, "����: ", (char*)pCheckOrgan, left_margin_new, cur_y, lf);
	}
	if (checkbox_state_now.fzx_wb2_yqxh) {
		ShowItem(pDC, "�����ͺ�: ", "WRY-2015", weizhi_x_title + title_size.cx / 2, cur_y, lf);
	}
	

	cur_y += y_basic + title_size.cy;//����cur_y
	if (checkbox_state_now.basic_info_syrq) {
		ShowItem(pDC, "��������: ", (char*)pCheckOrgan, left_margin_new, cur_y, lf);
	}
	
	ShowItem(pDC, "�豸���: ", "A21001", weizhi_x_title + title_size.cx / 2, cur_y, lf);

	cur_y += y_basic + title_size.cy;//����cur_y
	ShowItem(pDC, "��������: ", "GB2015-2003", left_margin_new, cur_y, lf);
	ShowItem(pDC, "����: ", (char*)pCheckOrgan, weizhi_x_title + title_size.cx / 2, cur_y, lf);

	cur_y += y_basic + title_size.cy;//����cur_y
	if (checkbox_state_now.basic_info_syff) {
		ShowItem(pDC, "���鷽��: ", (char*)pCheckOrgan, left_margin_new, cur_y, lf);
	}
	
	ShowItem(pDC, "ʱ����ֵ: ", (char*)pCheckOrgan, weizhi_x_title + title_size.cx / 2, cur_y, lf);
	ShowItem(pDC, "�¶���ֵ: ", (char*)pCheckOrgan, weizhi_x_title + 2*title_size.cx , cur_y, lf);

	cur_y += y_basic + title_size.cy;//����cur_y
	ShowItem(pDC, "������Һ������: ", "���Լ�Һ������:ȡ��Ʒ����100mg��1%̼��������Һ2.3ml�ı�������1%̼����������ԭ��Һ����50��", left_margin_new, cur_y, lf);
	cur_y += y_basic + title_size.cy;//����cur_y
	ShowItem(pDC, "", "ˮԡ��ҡʹ�ܽ⣬�ټ�������ע��Һ�Ƴ�ÿ1ml��2.5mg����Һ���ա���ԭ��鷨��׼������̡�(�ļ���� : GWZ - S0P80 - ", left_margin_new, cur_y, lf);
	cur_y += y_basic + title_size.cy;//����cur_y
	ShowItem(pDC, "", "103) ��飬��������������ÿ1kgע��1ml", left_margin_new, cur_y, lf);
	cur_y += y_basic + title_size.cy;//����cur_y
	


	//if (!isPreView)
	//	lf.lfHeight = 17 * coefficient;
	//else
	//	lf.lfHeight = 14 * coefficient;                      // request a 12-pixel-height font


	// ���ָ���
	point.x = left_margin_new;
	point.y = cur_y;
	pDC->MoveTo(point);

	point.x =right_margin_new;
	point.y = cur_y;
	pDC->LineTo(point);

	cur_y += y_basic;//����cur_y
	
	
	//�����1
	double biaoge1_top = cur_y;
	CPoint m_ptOrigin(left_margin_new, cur_y);
	CPoint point_bot_right(right_margin_new, cur_y + y_basic * 6);
	cur_y += y_basic * 6;//����cur_y
	pDC->SelectObject(&pen);
	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush = pDC->SelectObject(pBrush);

	pDC->Rectangle(CRect(m_ptOrigin, point_bot_right));
	pDC->Rectangle(CRect(left_margin_new, cur_y, right_margin_new, cur_y + y_basic * 3));
	cur_y += y_basic * 3;//����cur_y
	pDC->Rectangle(CRect(left_margin_new, cur_y, right_margin_new, cur_y + y_basic * 3));
	cur_y += y_basic * 3;//����cur_y
	pDC->Rectangle(CRect(left_margin_new, cur_y, right_margin_new, cur_y + y_basic * 3));
	cur_y += y_basic * 3;//����cur_y

	double biaoge1_bottom = cur_y;

	pDC->Rectangle(CRect(left_margin_new, biaoge1_top, left_margin_new+8*x_basic, biaoge1_bottom));
	pDC->Rectangle(CRect(left_margin_new + 8 * x_basic, biaoge1_top, left_margin_new + 25 * x_basic, biaoge1_bottom));
	for (int i = 0; i < 11; i++){
		pDC->Rectangle(CRect(left_margin_new + 25 * x_basic + i * 7 * x_basic, biaoge1_top, left_margin_new + 25 * x_basic + (i+1) * 7 * x_basic, biaoge1_bottom));
	}

	//�����2
	cur_y += y_basic;//����cur_y
	double biaoge2_top = cur_y;
	cur_y += y_basic * 3;//����cur_y
	double biaoge2_bottom = cur_y;

	pDC->Rectangle(CRect(left_margin_new, biaoge2_top, right_margin_new, biaoge2_bottom));
	pDC->Rectangle(CRect(left_margin_new, biaoge2_top, left_margin_new + 22 * x_basic, biaoge2_bottom));
	pDC->Rectangle(CRect(left_margin_new + 35 * x_basic, biaoge2_top, left_margin_new +35 * x_basic+22 * x_basic, biaoge2_bottom));
	pDC->Rectangle(CRect(left_margin_new + 35 *2* x_basic, biaoge2_top, left_margin_new + 35*2 * x_basic + 22 * x_basic, biaoge2_bottom));
	pDC->SelectObject(pOldBrush);

	pDC->SelectObject(pBrush);

	//�����3
	cur_y += y_basic;//����cur_y
	double biaoge3_top = cur_y;
	cur_y += y_basic * 15;//����cur_y
	double biaoge3_bottom = cur_y;

	pDC->Rectangle(CRect(left_margin_new, biaoge3_top, right_margin_new, biaoge3_bottom));
	pDC->Rectangle(CRect(left_margin_new, biaoge3_top, right_margin_new, biaoge3_top + 6 * y_basic));
	pDC->Rectangle(CRect(left_margin_new, biaoge3_top + 9 * y_basic, right_margin_new, biaoge3_top + 12 * y_basic));
	
	
	pDC->Rectangle(CRect(left_margin_new, biaoge3_top, left_margin_new + 8 * x_basic, biaoge3_bottom));
	pDC->Rectangle(CRect(left_margin_new + 25 * x_basic, biaoge3_top, left_margin_new + 37 * x_basic, biaoge3_bottom));


	pDC->Rectangle(CRect(right_margin_new - 12 * x_basic, biaoge3_top, right_margin_new, biaoge3_bottom));
	pDC->Rectangle(CRect(right_margin_new - 36 * x_basic, biaoge3_top, right_margin_new - 24 * x_basic, biaoge3_bottom));
	pDC->Rectangle(CRect(right_margin_new - 48 * x_basic, biaoge3_top, right_margin_new, biaoge3_bottom));




	// ���ָ���
	point.x = left_margin_new;
	point.y = mRECT.bottom-y_basic*6;
	pDC->MoveTo(point);
	point.x = right_margin_new;
	point.y = mRECT.bottom - y_basic * 6;
	pDC->LineTo(point);


	//��������/����
	if (checkbox_state_now.fzx_wb4_czr) {
		ShowItem(pDC, "������/����: ", " ", left_margin_new, point.y - 3 * y_basic, lf);
	}

	//��������/����
	if (checkbox_state_now.fzx_wb5_fhr) {
		ShowItem(pDC, "������/����: ", " ", left_margin_new + 35 * x_basic, point.y - 3 * y_basic, lf);
	}
	
	//�������/����
	if (checkbox_state_now.fzx_wb6_shr) {
		ShowItem(pDC, "�����/����: ", " ", left_margin_new + 70 * x_basic, point.y - 3 * y_basic, lf);
	}
	


	//����ӡʱ��
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
	//// TODO:  �ڴ˴������Ϣ����������


	CRect   rect;
	GetClientRect(rect);
	CRect mrect(CRect(rect.left+20, rect.top+35, rect.left+20 + a4w_in_pixel * 1.5, rect.top + 35+a4h_in_pixel * 1.5));

	dc.FillSolidRect(mrect, RGB(255, 255, 255));     //����Ϊ��ɫ����  


	CFormView::OnPaint();

	goto repaint;
	repaint:  MessageBox(TEXT("kk"));

	//MyPrinter(&dc, mrect,TRUE, FALSE);

}


void SET_YL_JLGS_RIGHT::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
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

	//dc.FillSolidRect(mrect, RGB(255, 255, 255));     //����Ϊ��ɫ����  


	//CFormView::OnPaint();

	MyPrinter(&dc, mrect,TRUE, FALSE);

	

	return 0;
}