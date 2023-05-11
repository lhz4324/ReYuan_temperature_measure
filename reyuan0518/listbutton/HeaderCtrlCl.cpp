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
	m_bShowCheckBox = FALSE;//�Ƿ���ʾ��ѡ��
	m_bChecked = FALSE;//��ѡ ���Ƿ�ѡ ��
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
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CHeaderCtrl::OnPaint()
	CRect tRect;
	int nItem; 
	nItem = GetItemCount();//�õ��м�����Ԫ 
	for(int i = 0; i<nItem;i ++) 
	{ 
		GetItemRect(i,&tRect);//�õ�Item�ĳߴ�
		int R = m_R,G = m_G,B = m_B;
		CRect nRect(tRect);//�����ߴ絽�µ������� 
		nRect.left++;//�����ָ��ߵĵط� 
		//�������屳�� 
		for(int j = tRect.top;j<=tRect.bottom;j++) 
		{ 
			nRect.bottom = nRect.top+1; 
			CBrush _brush; 
			_brush.CreateSolidBrush(RGB(R, G, B));//������ˢ 
			dc.FillRect(&nRect,&_brush); //��䱳�� 
			_brush.DeleteObject(); //�ͷŻ�ˢ 
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
		nFont.CreateFont(m_fontHeight,m_fontWith,0,0,0,FALSE,FALSE,0,0,0,0,0,0,_TEXT("����"));//�������� 
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
		//��������ʾ��һ���ʺϵĸ߶�λ��
		TEXTMETRIC metric;
		dc.GetTextMetrics(&metric);
		int ofst = 0;
		ofst = tRect.Height() - metric.tmHeight;
		tRect.OffsetRect(0,ofst/2);
 		dc.DrawText(m_HChar[i],&tRect,nFormat);
		dc.SelectObject(nOldFont); 
		nFont.DeleteObject(); //�ͷ����� 
	} 
	//��ͷ��ʣ�ಿ��(û�б�����ǲ���)
	CRect rtRect;
	CRect clientRect;
	GetItemRect(nItem - 1,rtRect);
	GetClientRect(clientRect); //��ǰ(CHeaderCtrl)�ؼ��Ĵ�С
	rtRect.left = rtRect.right+1;
	rtRect.right = clientRect.right;
	int R = m_R,G = m_G,B = m_B;
	CRect nRect(rtRect);
	//�������屳�� 
	for(int j = rtRect.top;j<=rtRect.bottom;j++) 
	{ 
		nRect.bottom = nRect.top+1; 
		CBrush _brush; 
		_brush.CreateSolidBrush(RGB(R,G,B));//������ˢ 
		dc.FillRect(&nRect,&_brush); //��䱳�� 
		_brush.DeleteObject(); //�ͷŻ�ˢ 
		R-=m_Gradient;G-=m_Gradient;B-=m_Gradient;
		if (R<0)R = 0;
		if (G<0)G = 0;
		if (B<0)B= 0;
		nRect.top = nRect.bottom; 
	} 

	//�Ƿ���ʾ��ѡ��
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
	//��ͷ�߶�Ϊԭ��1.5�������Ҫ��̬�޸ı�ͷ�߶ȵĻ�����1.5���һ��ȫ�ֱ��� 
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
	CBrush brush(RGB(96, 135, 142));//96,135,142//�߿���ɫ
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
�����Ƿ���ʾ��ѡ��
*/
void CHeaderCtrlCl::SetShowCheckBoxSign(BOOL bShowCheckBoxSign)
{
	m_bShowCheckBox = bShowCheckBoxSign;
}

/**
ȡ���Ƿ���ʾ��ѡ ��
*/
BOOL CHeaderCtrlCl::GetShowCheckBoxSign()
{
	return m_bShowCheckBox;
}

/**
ȡ�ø�ѡ��״̬
*/
BOOL CHeaderCtrlCl::GetCheckState()
{
	return m_bChecked;
}

/**
�����Ƿ�ѡ �и�ѡ ��
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
	//nItem = HitTest(point,NULL);//�ж����ѡ����nTotalColumn - 1
	::SendMessage(GetParent()->m_hWnd, WM_LBUTTONDOWN_MYMSG, nFlags, MAKELPARAM(point.x, point.y));//�򸸴��ڷ�����Ϣ
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
	//nItem = HitTest(point,NULL);//�ж����ѡ����nTotalColumn - 1
	::SendMessage(GetParent()->m_hWnd,WM_LBUTTONDOWN_MYMSG, nFlags, MAKELPARAM(point.x, point.y));//�򸸴��ڷ�����Ϣ
	CHeaderCtrl::OnLButtonDown(nFlags, point);
}
