// ListCtrlButton.cpp : implementation file
//

#include "stdafx.h"
//#include "../Tab_CEWEN_WDCD_SYPC.h"
#include "ListCtrlButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListCtrlButton

CListCtrlButton::CListCtrlButton()
{
	m_DownColor = m_UpColor = RGB(0,0,0);
}

CListCtrlButton::~CListCtrlButton()
{
}


BEGIN_MESSAGE_MAP(CListCtrlButton, CButton)
	//{{AFX_MSG_MAP(CListCtrlButton)
	ON_CONTROL_REFLECT(BN_CLICKED, OnClicked)
	ON_WM_ERASEBKGND()
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListCtrlButton message handlers

void CListCtrlButton::OnClicked() 
{
	// TODO: Add your control notification handler code here
	// 向父窗口发消息
    CWnd* pParent = this->GetParent();
    ::PostMessage(pParent->GetSafeHwnd(),WM_USER_BTN_CLICK,0,0);
}

BOOL CListCtrlButton::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return true;
	//return CButton::OnEraseBkgnd(pDC);
}

void CListCtrlButton::OnKillFocus(CWnd* pNewWnd) 
{
	CButton::OnKillFocus(pNewWnd);
	
	// TODO: Add your message handler code here
	ShowWindow(SW_HIDE);
}
BOOL CListCtrlButton::Attach(const UINT nID, CWnd* pParent)
{
 //GetDlgItem(nID)->ModifyStyle(0,BS_OWNERDRAW,0);

	 //if (!SubclassDlgItem(nID, pParent))
		// return FALSE;

	 return TRUE;
}

void CListCtrlButton::SetDownColor(COLORREF color)
{
	m_DownColor = color;
}

void CListCtrlButton::SetUpColor(COLORREF color)
{
	m_UpColor = color;
}

void CListCtrlButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);//得到绘制的设备环境CDC
	VERIFY(lpDrawItemStruct->CtlType==ODT_BUTTON);
	// 得当Button上文字,这里的步骤是:1,先得到在资源里编辑的按钮的文字,

	//然后将此文字重新绘制到按钮上,
	//同时将此文字的背景色设为透明,这样,按钮上仅会显示文字

	USES_CONVERSION;
	 const int bufSize = 512;
	 char buffer[bufSize];
	 GetWindowText(A2T(buffer), bufSize);

	 int size=(int)strlen(buffer);   //得到长度
	 DrawText(lpDrawItemStruct->hDC, A2T(buffer),size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);   //绘制文字
	 SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);   //透明

	if (lpDrawItemStruct->itemState &ODS_SELECTED)  //当按下按钮时的处理
	{//
		  //重绘整个控制
		  CBrush brush(m_DownColor);  
		  dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//

		  //因为这里进行了重绘,所以文字也要重绘
		  DrawText(lpDrawItemStruct->hDC, A2T(buffer),size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);   
		  SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);      
	}
	else //当按钮不操作或者弹起时
	{
		  CBrush brush(m_UpColor);     
		  dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//

		  //同上,进行重绘文字
		  DrawText(lpDrawItemStruct->hDC, A2T(buffer),size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);
		  SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);
	}

	if ((lpDrawItemStruct->itemState &ODS_SELECTED)&&(lpDrawItemStruct->itemAction &(ODA_SELECT| ODA_DRAWENTIRE)))
	{   
		  //选中了本控件,高亮边框
		  COLORREF fc=RGB(255-GetRValue(m_UpColor),255-GetGValue(m_UpColor), 255-GetBValue(m_UpColor));//
		  CBrush brush(fc);//
		  dc.FrameRect(&(lpDrawItemStruct->rcItem),&brush);//

	}
	if (!(lpDrawItemStruct->itemState & ODS_SELECTED) &&(lpDrawItemStruct->itemAction & ODA_SELECT))
	{
		  //控制的选中状态结束,去掉边框
		  CBrush brush(m_UpColor);
		  dc.FrameRect(&lpDrawItemStruct->rcItem,&brush);//

	}
	dc.Detach();//
}
