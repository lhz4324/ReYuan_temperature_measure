// HeaderCtrlCl.cpp : implementation file
//

#include "stdafx.h"
//#include "../Tab_CEWEN_WDCD_SYPC.h"
#include "HeaderCtrlCl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHeaderCtrlCl
CHeaderCtrlCl::CHeaderCtrlCl()
: m_R(171)
, m_G(199)
, m_B(235)
, m_Gradient(8)
{
	m_Format = "";
	m_Height = 1;
	m_fontHeight = 15;
	m_fontWith = 0;
	m_color = RGB(0,0,0);
	m_bShowCheckBox = FALSE;//是否显示复选框
	m_bChecked = FALSE;//复选 框是否选 中
}

CHeaderCtrlCl::~CHeaderCtrlCl()
{
}


BEGIN_MESSAGE_MAP(CHeaderCtrlCl, CHeaderCtrl)
	//{{AFX_MSG_MAP(CHeaderCtrlCl)
	ON_WM_PAINT()
	ON_MESSAGE(HDM_LAYOUT, OnLayout)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHeaderCtrlCl message handlers
void CHeaderCtrlCl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CHeaderCtrl::OnPaint()
	CRect tRect;
	int nItem; 
	nItem = GetItemCount();//得到有几个单元 
	for(int i = 0; i<nItem;i ++) 
	{ 
		GetItemRect(i,&tRect);//得到Item的尺寸
		int R = m_R,G = m_G,B = m_B;
		CRect nRect(tRect);//拷贝尺寸到新的容器中 
		nRect.left++;//留出分割线的地方 
		//绘制立体背景 
		for(int j = tRect.top;j<=tRect.bottom;j++) 
		{ 
			nRect.bottom = nRect.top+1; 
			CBrush _brush; 
			_brush.CreateSolidBrush(RGB(R, G, B));//创建画刷 
			dc.FillRect(&nRect,&_brush); //填充背景 
			_brush.DeleteObject(); //释放画刷 
			R-=m_Gradient;G-=m_Gradient;B-=m_Gradient;
			if (R<0)R = 0;
			if (G<0)G = 0;
			if (B<0)B= 0;
			nRect.top = nRect.bottom; 
		} 
		dc.SetBkMode(TRANSPARENT);
		CFont nFont ,* nOldFont; 
		//dc.SetTextColor(RGB(250,50,50)); 
		dc.SetTextColor(m_color);
		nFont.CreateFont(m_fontHeight,m_fontWith,0,0,0,FALSE,FALSE,0,0,0,0,0,0,_TEXT("宋体"));//创建字体 
		nOldFont = dc.SelectObject(&nFont);
		UINT nFormat = 1;
		if (m_Format[i]=='0')
		{
			nFormat = DT_LEFT;
			tRect.left+=3;
		}
		else if (m_Format[i]=='1')
		{
			nFormat = DT_CENTER;
		}
		else if (m_Format[i]=='2')
		{
			nFormat = DT_RIGHT;
			tRect.right-=3;
		}
		//将文字显示在一个适合的高度位置
		TEXTMETRIC metric;
		dc.GetTextMetrics(&metric);
		int ofst = 0;
		ofst = tRect.Height() - metric.tmHeight;
		tRect.OffsetRect(0,ofst/2);
 		dc.DrawText(m_HChar[i],&tRect,nFormat);
		dc.SelectObject(nOldFont); 
		nFont.DeleteObject(); //释放字体 
	} 
	//画头部剩余部分(没有标题的那部分)
	CRect rtRect;
	CRect clientRect;
	GetItemRect(nItem - 1,rtRect);
	GetClientRect(clientRect); //当前(CHeaderCtrl)控件的大小
	rtRect.left = rtRect.right+1;
	rtRect.right = clientRect.right;
	int R = m_R,G = m_G,B = m_B;
	CRect nRect(rtRect);
	//绘制立体背景 
	for(int j = rtRect.top;j<=rtRect.bottom;j++) 
	{ 
		nRect.bottom = nRect.top+1; 
		CBrush _brush; 
		_brush.CreateSolidBrush(RGB(R,G,B));//创建画刷 
		dc.FillRect(&nRect,&_brush); //填充背景 
		_brush.DeleteObject(); //释放画刷 
		R-=m_Gradient;G-=m_Gradient;B-=m_Gradient;
		if (R<0)R = 0;
		if (G<0)G = 0;
		if (B<0)B= 0;
		nRect.top = nRect.bottom; 
	} 

	//是否显示复选框
	if (m_bShowCheckBox)
	{
		//
		GetItemRect(0, &tRect);
		//CHECKBOX
		DrawCheckbox((CDC *)&dc, tRect);
	}
}

LRESULT CHeaderCtrlCl::OnLayout( WPARAM wParam, LPARAM lParam )
{

	LRESULT lResult = CHeaderCtrl::DefWindowProc(HDM_LAYOUT, 0, lParam); 
	HD_LAYOUT &hdl = *( HD_LAYOUT * ) lParam; 
	RECT *prc = hdl.prc; 
	WINDOWPOS *pwpos = hdl.pwpos; 
	//表头高度为原来1.5倍，如果要动态修改表头高度的话，将1.5设成一个全局变量 
	int nHeight = (int)(pwpos->cy * m_Height);
	pwpos->cy = nHeight; 
	prc->top = nHeight; 
	return lResult; 
}
//////////////////////////////////////////////////////////////////////////////
// DrawCheckbox
void CHeaderCtrlCl::DrawCheckbox( CDC *pDC, CRect& rect)
{
	CRect chkboxrect = rect;
	// center the checkbox
	int h = 15;	// height and width are the same
	chkboxrect.left = rect.left + rect.Width() / 2 - h / 2 - 1;
	chkboxrect.right = chkboxrect.left + h;
	chkboxrect.top = rect.top + (rect.Height() - h) / 2;
	chkboxrect.bottom = chkboxrect.top + h;

	// fill rect inside checkbox with white
	COLORREF rgbBackground = pDC->SetBkColor(::GetSysColor(COLOR_WINDOW));
	pDC->FillSolidRect(&chkboxrect, ::GetSysColor(COLOR_WINDOW));

	// draw border 51, 102, 153
	CBrush brush(RGB(96, 135, 142));//96,135,142//边框颜色
	pDC->FrameRect(&chkboxrect, &brush);

	if (m_bChecked)
	{
		CPen blackpen(PS_SOLID, 1, RGB(51, 153, 51));
		CPen * pOldPen = pDC->SelectObject(&blackpen);

		// draw the checkmark
		int x = chkboxrect.left + 10;
		ASSERT(x < chkboxrect.right);
		int y = chkboxrect.top + 4;
		int i = 0;
		for (i = 0; i < 4; i++)
		{
			pDC->MoveTo(x, y);
			pDC->LineTo(x, y + 3);
			x--;
			y++;
		}
		for (i = 0; i < 3; i++)
		{
			pDC->MoveTo(x, y);
			pDC->LineTo(x, y + 3);
			x--;
			y--;
		}

		if (pOldPen)
			pDC->SelectObject(pOldPen);
	}

	pDC->SetBkColor(rgbBackground);

	

}

/**
设置是否显示复选框
*/
void CHeaderCtrlCl::SetShowCheckBoxSign(BOOL bShowCheckBoxSign)
{
	m_bShowCheckBox = bShowCheckBoxSign;
}

/**
取得是否显示复选 框
*/
BOOL CHeaderCtrlCl::GetShowCheckBoxSign()
{
	return m_bShowCheckBox;
}

/**
取得复选框状态
*/
BOOL CHeaderCtrlCl::GetCheckState()
{
	return m_bChecked;
}

/**
设置是否选 中复选 框
*/
void CHeaderCtrlCl::SetCheckState(BOOL bChecked)
{
	m_bChecked = bChecked;
}

void CHeaderCtrlCl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (!m_bShowCheckBox)
		return;
	//
	RECT rectiSubItem = { 0 };
	int nTotalColumn = 0;
	int nItem = -1;
	int nColumn = -1;

	int nItems = GetItemCount();
	for (int i = 0; i < nItems; ++i)
	{
		nItem = i;
		if (nItem == 0)
		{
			GetItemRect(nItem, &rectiSubItem);
			if (PtInRect(&rectiSubItem, point))
			{
				m_bChecked = !m_bChecked;
				InvalidateRect(NULL, FALSE);
				break;
			}
		}
	}
	//nItem = HitTest(point,NULL);//判断鼠标选择项nTotalColumn - 1
	::SendMessage(GetParent()->m_hWnd, WM_LBUTTONDOWN_MYMSG, nFlags, MAKELPARAM(point.x, point.y));//向父窗口发送消息
	//CHeaderCtrl::OnLButtonDblClk(nFlags, point);

}

void CHeaderCtrlCl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	RECT rectiSubItem = { 0 };

	int nTotalColumn = 0;
	int nItem = -1;
	int nColumn = -1;

	int nItems = GetItemCount();
	for (int i = 0; i < nItems; ++i)
	{
		nItem = i;
		if (nItem == 0)
		{
			GetItemRect(nItem, &rectiSubItem);
			if (PtInRect(&rectiSubItem, point))
			{
				m_bChecked = !m_bChecked;
				InvalidateRect(NULL, FALSE);
				break;
			}
		}
	}
	//nItem = HitTest(point,NULL);//判断鼠标选择项nTotalColumn - 1
	::SendMessage(GetParent()->m_hWnd,WM_LBUTTONDOWN_MYMSG, nFlags, MAKELPARAM(point.x, point.y));//向父窗口发送消息
	CHeaderCtrl::OnLButtonDown(nFlags, point);
}
