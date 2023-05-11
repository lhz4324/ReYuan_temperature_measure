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
	// �򸸴��ڷ���Ϣ
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
	dc.Attach(lpDrawItemStruct->hDC);//�õ����Ƶ��豸����CDC
	VERIFY(lpDrawItemStruct->CtlType==ODT_BUTTON);
	// �õ�Button������,����Ĳ�����:1,�ȵõ�����Դ��༭�İ�ť������,

	//Ȼ�󽫴��������»��Ƶ���ť��,
	//ͬʱ�������ֵı���ɫ��Ϊ͸��,����,��ť�Ͻ�����ʾ����

	USES_CONVERSION;
	 const int bufSize = 512;
	 char buffer[bufSize];
	 GetWindowText(A2T(buffer), bufSize);

	 int size=(int)strlen(buffer);   //�õ�����
	 DrawText(lpDrawItemStruct->hDC, A2T(buffer),size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);   //��������
	 SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);   //͸��

	if (lpDrawItemStruct->itemState &ODS_SELECTED)  //�����°�ťʱ�Ĵ���
	{//
		  //�ػ���������
		  CBrush brush(m_DownColor);  
		  dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//

		  //��Ϊ����������ػ�,��������ҲҪ�ػ�
		  DrawText(lpDrawItemStruct->hDC, A2T(buffer),size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);   
		  SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);      
	}
	else //����ť���������ߵ���ʱ
	{
		  CBrush brush(m_UpColor);     
		  dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//

		  //ͬ��,�����ػ�����
		  DrawText(lpDrawItemStruct->hDC, A2T(buffer),size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);
		  SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);
	}

	if ((lpDrawItemStruct->itemState &ODS_SELECTED)&&(lpDrawItemStruct->itemAction &(ODA_SELECT| ODA_DRAWENTIRE)))
	{   
		  //ѡ���˱��ؼ�,�����߿�
		  COLORREF fc=RGB(255-GetRValue(m_UpColor),255-GetGValue(m_UpColor), 255-GetBValue(m_UpColor));//
		  CBrush brush(fc);//
		  dc.FrameRect(&(lpDrawItemStruct->rcItem),&brush);//

	}
	if (!(lpDrawItemStruct->itemState & ODS_SELECTED) &&(lpDrawItemStruct->itemAction & ODA_SELECT))
	{
		  //���Ƶ�ѡ��״̬����,ȥ���߿�
		  CBrush brush(m_UpColor);
		  dc.FrameRect(&lpDrawItemStruct->rcItem,&brush);//

	}
	dc.Detach();//
}
