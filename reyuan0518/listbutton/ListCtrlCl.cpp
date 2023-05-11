// ListCtrlCl.cpp : implementation file
//

#include "stdafx.h"
//#include "../Tab_CEWEN_WDCD_SYPC.h"
#include "ListCtrlCl.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CListCtrlCl

CListCtrlCl::CListCtrlCl()
: m_nRowHeight(0)
, m_fontHeight(12)
, m_fontWith(0)
{
	m_color = RGB(0,0,0);
	m_crGrayText = ::GetSysColor(COLOR_GRAYTEXT);
	m_crWindow = ::GetSysColor(COLOR_WINDOW);
	m_crWindowText = ::GetSysColor(COLOR_WINDOWTEXT);
	m_bShowCheckBoxSign = FALSE;
    //
    m_bSingleRowCheck = TRUE;//�����У�ѡ��CHECKBOX��ѡ��

	LIST_ITEM_HEIGHT = 32;
	//��ʼ��m_bItemCheckStateȫΪFALSE
	memset(m_bItemCheckState, 0, sizeof(m_bItemCheckState));
}

CListCtrlCl::~CListCtrlCl()
{
	stColor *ptemp = NULL;
	while (m_ptrListCol.GetCount() > 0)
	{	
		ptemp = (stColor *)(m_ptrListCol.RemoveHead());
		if ( NULL != ptemp )
		{
			delete ptemp;
			ptemp = NULL;
		}
	}
	while ( m_ptrListItem.GetCount() > 0)
	{
		ptemp = (stColor *)(m_ptrListItem.RemoveHead());
		if ( NULL != ptemp )
		{
			delete ptemp;
			ptemp = NULL;
		}
	}
	while ( m_colTextColor.GetCount() > 0)
	{
		ptemp = (stColor *)(m_colTextColor.RemoveHead());
		if ( NULL != ptemp )
		{
			delete ptemp;
			ptemp = NULL;
		}
	}
	while ( m_ItemTextColor.GetCount() > 0)
	{
		ptemp = (stColor *)(m_ItemTextColor.RemoveHead());
		if ( NULL != ptemp )
		{
			delete ptemp;
			ptemp = NULL;
		}
	}
}


BEGIN_MESSAGE_MAP(CListCtrlCl, CListCtrl)
	//{{AFX_MSG_MAP(CListCtrlCl)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_MEASUREITEM_REFLECT()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_USER_EDIT_END,CListCtrlCl::OnEditEnd)
	ON_MESSAGE(WM_USER_BTN_CLICK,CListCtrlCl::OnMyBtnClicked)
	ON_MESSAGE(WM_LBUTTONDOWN_MYMSG, OnHeadCtrlLButtonDown)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnNMCustomdraw)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////

void CListCtrlCl::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{

	/*LPNMLVCUSTOMDRAW lpnmcd = (LPNMLVCUSTOMDRAW)pNMHDR;
	if (lpnmcd->nmcd.dwDrawStage == CDDS_PREPAINT)
	{
		*pResult = CDRF_NOTIFYITEMDRAW | CDRF_NOTIFYPOSTPAINT;
		return;
	}
	else if (lpnmcd->nmcd.dwDrawStage == CDDS_ITEMPREPAINT)
	{
		CRect rSubItem, rectClient;
		int nColumnCount = GetHeaderCtrl()->GetItemCount();
		if (nColumnCount>0)
		{
			GetSubItemRect(lpnmcd->nmcd.dwItemSpec, nColumnCount - 1, LVIR_LABEL, rSubItem);
			GetClientRect(&rectClient);
			rSubItem.left = rSubItem.right;
			rSubItem.right = rectClient.right;
			rSubItem.NormalizeRect();
			bool bSelected = false;
			if (GetItemState(lpnmcd->nmcd.dwItemSpec, LVIS_SELECTED))
			{
				bSelected = true;
			}

			bool bFocus = false;
			HWND hWndFocus = ::GetFocus();
			if (::IsChild(m_hWnd, hWndFocus) || m_hWnd == hWndFocus)
			{
				bFocus = true;
			}
			CDC dc;
			dc.Attach(lpnmcd->nmcd.hdc);
			draw_row_bg(&dc, rSubItem, bSelected, bFocus, (int)lpnmcd->nmcd.dwItemSpec);
			dc.Detach();
		}

		*pResult = CDRF_NOTIFYSUBITEMDRAW;
		return;
	}
	else if (lpnmcd->nmcd.dwDrawStage == (CDDS_SUBITEM | CDDS_ITEMPREPAINT))
	{
		AfxMessageBox(_T("d"));
		int iItem = lpnmcd->nmcd.dwItemSpec;
		int iSubItem = lpnmcd->iSubItem;
		if (iItem >= 0 && iSubItem >= 0)
		{
			CString str;
			str.Format(_T("%d%d"),iItem,iSubItem);
			AfxMessageBox(str);
			CRect rSubItem;
			HDC hDC = lpnmcd->nmcd.hdc;
			GetSubItemRect(iItem, iSubItem, LVIR_LABEL, rSubItem);
			if (iSubItem == 0)
			{
				rSubItem.left = 0;
			}

			bool bSelected = false;
			if (GetItemState(iItem, LVIS_SELECTED))
			{
				bSelected = true;
			}

			bool bFocus = false;
			CWnd *pWndFocus = GetFocus();
			if (IsChild(pWndFocus) || pWndFocus == this)
			{
				bFocus = true;
			}

			rSubItem.NormalizeRect();
			CDC dc;
			dc.Attach(lpnmcd->nmcd.hdc);
			DrawSubItem(&dc, iItem, iSubItem, rSubItem, bSelected, bFocus);
			dc.Detach();
			*pResult = CDRF_SKIPDEFAULT;
			return;
		}
	}
	else if (lpnmcd->nmcd.dwDrawStage == CDDS_POSTPAINT)
	{
		DrawRemainSpace(lpnmcd);
		*pResult = CDRF_SKIPDEFAULT;
		return;
	}*/

	*pResult = 0;

}

// CListCtrlCl message handlers
void CListCtrlCl::PreSubclassWindow()
{
	// TODO: �ڴ����ר�ô����/����û���
	ModifyStyle(0,LVS_OWNERDRAWFIXED);
	CListCtrl::PreSubclassWindow();
	CHeaderCtrl *pHeader = GetHeaderCtrl();
	m_Header.SubclassWindow(pHeader->GetSafeHwnd());
}

void CListCtrlCl::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO:  ������Ĵ����Ի���ָ����
	TCHAR lpBuffer[256];
	LV_ITEM lvi;
	lvi.mask = LVIF_TEXT | LVIF_PARAM ;
	lvi.iItem = lpDrawItemStruct->itemID ; 
	lvi.iSubItem = 0;
	lvi.pszText = lpBuffer ;
	lvi.cchTextMax = sizeof(lpBuffer);
	VERIFY(GetItem(&lvi));
	LV_COLUMN lvc, lvcprev ;
	::ZeroMemory(&lvc, sizeof(lvc));
	::ZeroMemory(&lvcprev, sizeof(lvcprev));
	lvc.mask = LVCF_WIDTH | LVCF_FMT;
	lvcprev.mask = LVCF_WIDTH | LVCF_FMT;
	CDC* pDC;
	pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	CRect rtClient;
	GetClientRect(&rtClient);

	for ( int nCol=0; GetColumn(nCol, &lvc); nCol++)
	{
		if ( nCol > 0 ) 
		{
			// Get Previous Column Width in order to move the next display item
			GetColumn(nCol-1, &lvcprev) ;
			lpDrawItemStruct->rcItem.left += lvcprev.cx ;
			lpDrawItemStruct->rcItem.right += lpDrawItemStruct->rcItem.left; 
		}
		CRect rcItem;   
		if (!GetSubItemRect(lpDrawItemStruct->itemID,nCol,LVIR_LABEL,rcItem))   
			continue;   
		::ZeroMemory(&lvi, sizeof(lvi));
		lvi.iItem = lpDrawItemStruct->itemID;
		lvi.mask = LVIF_TEXT | LVIF_PARAM;
		lvi.iSubItem = nCol;
		lvi.pszText = lpBuffer;
		lvi.cchTextMax = sizeof(lpBuffer);
		VERIFY(GetItem(&lvi));
		CRect rcTemp;
		rcTemp = rcItem;
		if (nCol==0)
		{
			rcTemp.left -=2;
		}
		if ( lpDrawItemStruct->itemState & ODS_SELECTED )
		{
			pDC->FillSolidRect(&rcTemp, RGB(233, 250, 213)/*GetSysColor(COLOR_HIGHLIGHT)*/) ;//ѡ���б�����ɫ
			pDC->SetTextColor(GetSysColor(COLOR_HIGHLIGHTTEXT)) ;
		}
		else
		{
			COLORREF color;
			color = GetBkColor();
			pDC->FillSolidRect(rcTemp,color);
			if (FindColColor(nCol,color))
			{
				pDC->FillSolidRect(rcTemp,color);
			}
			if (FindItemColor(nCol,lpDrawItemStruct->itemID,color))
			{
				pDC->FillSolidRect(rcTemp,color);
			}
			//pDC->SetTextColor(m_color);
		}
		pDC->SelectObject(GetStockObject(DEFAULT_GUI_FONT));
		UINT   uFormat    = DT_CENTER ;
		if (m_Header.m_Format[nCol]=='0')
		{
			uFormat = DT_LEFT;
		}
		else if (m_Header.m_Format[nCol]=='1')
		{
			uFormat = DT_CENTER;
		}
		else if (m_Header.m_Format[nCol]=='2')
		{
			uFormat = DT_RIGHT;
		}
		TEXTMETRIC metric;
		pDC->GetTextMetrics(&metric);
		int ofst;
		ofst = rcItem.Height() - metric.tmHeight;
		rcItem.OffsetRect(0,ofst/2);
		pDC->SetTextColor(m_color);
		COLORREF color;
		if (FindColTextColor(nCol,color))
		{
			pDC->SetTextColor(color);
		}
		if (FindItemTextColor(nCol,lpDrawItemStruct->itemID,color))
		{
			pDC->SetTextColor(color);
		}
		CFont nFont ,* nOldFont; 
		nFont.CreateFont(m_fontHeight,m_fontWith,0,0,0,FALSE,FALSE,0,0,0,0,0,0,_TEXT("����"));//�������� 
		nOldFont = pDC->SelectObject(&nFont);
		DrawText(lpDrawItemStruct->hDC, lpBuffer, (int)wcslen(lpBuffer), &rcItem, uFormat) ;
		pDC->SelectStockObject(SYSTEM_FONT) ;

		//�Ƿ���ʾ��ѡ ��
		if (m_bShowCheckBoxSign)
		{
			//��0��,��ʾcheckbox
			if (nCol == 0)
			{
				//���Ƹ�ѡ��
				DrawCheckbox(lpDrawItemStruct->itemID, nCol, pDC, rcItem);
				
			}
		}
		/*//��ʾ��ť
		if(GetItemShowButton(nCol))
		{
			//��ʾ�༭��
			ShowButton(TRUE, lpDrawItemStruct->itemID, nCol, pDC,rcItem);
		}
		//��ʾedit
		m_strItemOldValue=GetItemText(lpDrawItemStruct->itemID,nCol);
		if(GetItemEnableEdit(nCol))
		{
			//��ʾ�༭��
			ShowEdit(TRUE, lpDrawItemStruct->itemID, nCol, rcItem);
		}*/
	}

	
}

void CListCtrlCl::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	if (m_nRowHeight>0)
	{
		lpMeasureItemStruct->itemHeight = m_nRowHeight;
	}
}

int CListCtrlCl::InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat /* = LVCFMT_LEFT */, int nWidth /* = -1 */, BOOL bEnableEdit/*=FALSE*/, BOOL bShowButton/*=FALSE*/,int nSubItem /* = -1 */)
{
	m_Header.m_HChar.Add(lpszColumnHeading);
	if (nFormat==LVCFMT_LEFT)
	{
		m_Header.m_Format = m_Header.m_Format + TEXT("0");
	}
	else if (nFormat==LVCFMT_CENTER)
	{
		m_Header.m_Format = m_Header.m_Format + TEXT("1");
	}
	else if (nFormat==LVCFMT_RIGHT)
	{
		m_Header.m_Format = m_Header.m_Format + TEXT("2");
	}
	else
	{
		m_Header.m_Format = m_Header.m_Format + TEXT("1");
	}
	//edit
	ListCtrlColEdit lcce;
	lcce.col=nCol;
	lcce.bEnableEdit=bEnableEdit;
	m_vecEdit.push_back(lcce);
	//button
	ListCtrlColButton lccb;
	lccb.col=nCol;
	lccb.bShowButton=bShowButton;
	m_vecButton.push_back(lccb);

	return CListCtrl::InsertColumn(nCol,lpszColumnHeading,nFormat,nWidth,nSubItem);

}

// Gradient - ����ϵ�������屳����,���ý�����Ϊ0
void CListCtrlCl::SetHeaderBKColor(int R, int G, int B, int Gradient) //���ñ�ͷ����ɫ
{
	m_Header.m_R = R;
	m_Header.m_G = G;
	m_Header.m_B = B;
	m_Header.m_Gradient = Gradient;
}

// ���ñ�ͷ�߶�
void CListCtrlCl::SetHeaderHeight(float Height) //���ñ�ͷ�߶�
{
	m_Header.m_Height = Height;
}

bool CListCtrlCl::FindColColor(int col,COLORREF &color) //��������ɫ
{
	int flag = 0;
	for (POSITION pos = m_ptrListCol.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_ptrListCol.GetNext(pos);
		if (pColor->nCol==col)
		{
		flag = 1;
		color = pColor->rgb;
		break;
		}
	}
	if (1==flag)
	{
		return true;
	}
	return false;
}

bool CListCtrlCl::FindItemColor(int col,int row,COLORREF &color) //������ɫ
{
	int flag = 0;
	for (POSITION pos = m_ptrListItem.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_ptrListItem.GetNext(pos);
		if (pColor->nCol==col&&pColor->nRow==row)
		{
			flag = 1;
			color = pColor->rgb;
			break;
		}
	}
	if (1==flag)
	{
		return true;
	}
	return false;
}

void CListCtrlCl::SetColColor(int col,COLORREF color) //��������ɫ
{
	stColor *pColor  = new stColor;
	pColor->nCol = col;
	pColor->rgb = color;
	m_ptrListCol.AddTail(pColor);
}

void CListCtrlCl::SetItemColor(int col,int row,COLORREF color) //���ø�����ɫ
{
	stColor *pColor  = new stColor;
	pColor->nCol = col;
	pColor->nRow = row;
	pColor->rgb = color;
	m_ptrListItem.AddTail(pColor);
}

void CListCtrlCl::SetRowHeight(int nHeight) // �����и�
{
	m_nRowHeight = nHeight;
	CRect rcWin;
	GetWindowRect(&rcWin);
	WINDOWPOS wp;
	wp.hwnd = m_hWnd;
	wp.cx = rcWin.Width();
	wp.cy = rcWin.Height();
	wp.flags = SWP_NOACTIVATE | SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER;
	SendMessage(WM_WINDOWPOSCHANGED, 0, (LPARAM)&wp);
}

void CListCtrlCl::SetHeaderFontHW(int nHeight,int nWith) //����ͷ�������͸�
{
	m_Header.m_fontHeight = nHeight;
	m_Header.m_fontWith = nWith;
}

void CListCtrlCl::SetHeaderTextColor(COLORREF color) //����ͷ��������ɫ
{
	m_Header.m_color = color;
}

void CListCtrlCl::SetTextColor(COLORREF cr)  //����������ɫ
{
	m_color = cr;
}

void CListCtrlCl::SetFontHW(int nHeight,int nWith) //��������ߺͿ�
{
	m_fontHeight = nHeight;
	m_fontWith = nWith;
}

void CListCtrlCl::SetColTextColor(int col,COLORREF color)
{
	stColor *pColor = new stColor;
	pColor->nCol = col;
	pColor->rgb = color;
	m_colTextColor.AddTail(pColor);
}

bool CListCtrlCl::FindColTextColor(int col,COLORREF &color)
{
	int flag = 0;
	for (POSITION pos = m_colTextColor.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_colTextColor.GetNext(pos);
		if (pColor->nCol==col)
		{
			flag = 1;
			color = pColor->rgb;
			break;
		}
	}
	if (1==flag)
	{
		return true;
	}
	return false;
}

bool CListCtrlCl::FindItemTextColor(int col,int row,COLORREF &color)
{
	int flag = 0;
	for (POSITION pos = m_ItemTextColor.GetHeadPosition();pos!=NULL;)
	{
		stColor *pColor = (stColor*)m_ItemTextColor.GetNext(pos);
		if (pColor->nCol==col&&pColor->nRow==row)
		{
			flag = 1;
			color = pColor->rgb;
			break;
		}
	}
	if (1==flag)
	{
		return true;
	}
	return false;
}

void CListCtrlCl::SetItemTextColor(int col,int row,COLORREF color)
{
	stColor *pColor = new stColor;
	pColor->nCol = col;
	pColor->nRow = row;
	pColor->rgb = color;
	m_ItemTextColor.AddTail(pColor);
}
//=====================================================================
void CListCtrlCl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	LVHITTESTINFO lvhti;    // ����ListCtrl������Ϣ�Ľṹ
	lvhti.pt = point;
	m_nItem = CListCtrl::SubItemHitTest(&lvhti);//ȡ����
	if (m_nItem == -1) return;
	m_nSubItem = lvhti.iSubItem;//ȡ����

	CRect rect;
	CListCtrl::GetSubItemRect(m_nItem, m_nSubItem, LVIR_LABEL, rect);

	//ȡ�õ�Ԫ����ֵ
	m_strItemOldValue=GetItemText(m_nItem,m_nSubItem);
	if(GetItemEnableEdit(m_nSubItem))
	{
		//��ʾ�༭��
		ShowEdit(TRUE, m_nItem, m_nSubItem, rect);
	}

	CListCtrl::OnLButtonDblClk(nFlags, point);
}

void CListCtrlCl::ShowEdit(bool bShow, int nItem, int nSubItem, CRect rcCtrl)
{
	if (m_Edit.m_hWnd == NULL)
	{
		m_Edit.Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN | WS_BORDER, CRect(0, 0, 0, 0), this, IDC_EDIT);
		m_Edit.ShowWindow(SW_HIDE);

		CFont tpFont;
		tpFont.CreateStockObject(DEFAULT_GUI_FONT);
		m_Edit.SetFont(&tpFont);
		tpFont.DeleteObject();
	}
	if (bShow == TRUE)
	{
		CString strItem = CListCtrl::GetItemText(nItem, nSubItem);
		rcCtrl.top -= 2;    // ��ֹ�ϱ߿��ڵ�
		m_Edit.MoveWindow(&rcCtrl);
		m_Edit.ShowWindow(SW_SHOW);
		m_Edit.SetWindowText(strItem);
		m_Edit.SetFocus();
		m_Edit.SetSel(-1);
	}
	else
		m_Edit.ShowWindow(SW_HIDE);
}

void CListCtrlCl::ShowButton(bool bShow, int nItem, int nSubItem, CRect& rect)
{
	if (m_Button.m_hWnd == NULL)
	{
		//m_Button.Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN | WS_BORDER, CRect(0, 0, 0, 0), this, IDC_EDIT);
		m_Button.Create(TEXT(""),/////��ť����ʾ���ı� 
                          BS_DEFPUSHBUTTON|WS_VISIBLE|WS_CHILD,///���û���ƶ�WS_VISIBLE��Ҫ����ShowWindow������ʾ���� 
                          CRect(0, 0, 0, 0),/////���Ͻǵ�����(0��0),����Ϊ100��100 
                          this, 
                          IDC_BUTTON);

		//����ť�޸�ΪBS_OWNERDRAW���,���������Ч
		//m_Button.ModifyStyle(0,BS_OWNERDRAW,0);
		//�󶨿ؼ�IDC_BUTTON1����CMyButton����Ӧ���غ���DrawItem()
		m_Button.Attach(IDC_BUTTON,this);
		//ȡ�õ�Ԫ�񱳾���ɫ
		//����Button Up�ı���ɫ
		m_Button.SetUpColor(RGB(161,205,95));
		//����Button Down�ı���ɫ
		m_Button.SetDownColor(RGB(233, 250, 213));
		//
		m_Button.ShowWindow(SW_HIDE);

		CFont tpFont;
		tpFont.CreateStockObject(DEFAULT_GUI_FONT);
		m_Button.SetFont(&tpFont);
		tpFont.DeleteObject();
	}
	if (bShow == TRUE)
	{
		CString strItem = CListCtrl::GetItemText(nItem, nSubItem);
		rect.top += 5;    // ��ֹ�ϱ߿��ڵ�
		rect.bottom -= 5;
		rect.left += 5;
		rect.right -= 5;
		m_Button.MoveWindow(&rect);
		m_Button.ShowWindow(SW_SHOW);
		m_Button.SetWindowText(strItem);
		//m_Button.SetFocus();
		//m_Button.SetSel(-1);
	}
	else
		m_Button.ShowWindow(SW_HIDE);
}

LRESULT CListCtrlCl::OnEditEnd(WPARAM wParam, LPARAM lParam)
{
	CString strText;
	m_Edit.GetWindowText(strText);
	CListCtrl::SetItemText(m_nItem, m_nSubItem, strText);
	m_Edit.ShowWindow(SW_HIDE);
	if(m_strItemOldValue!=strText)//��ֵ�޸�
	{
		//�򸸴��ڷ�����Ϣ����ʾ��ֵ�޸�
		ListCtrlColEdit lcce;
		lcce.row=m_nItem;
		lcce.col=m_nSubItem;
		lcce.strText=strText;//.GetBuffer(strText.GetLength());
		//AfxMessageBox(strText);
		//SendMessage(WM_NOTIFY, GetDlgCtrlID(), (LPARAM)&dispinfo );
		CWnd* pParent = this->GetParent();
		SetItemTextColor(m_nSubItem,m_nItem,RGB(255,0,0));
		//::PostMessage(pParent->GetSafeHwnd(),WM_USER_EDITTEXT_CHANGE,0,(LPARAM)&lcce);//�˷������ַ��������޷�����
		::SendMessage(pParent->GetSafeHwnd(),WM_USER_EDITTEXT_CHANGE,0,(LPARAM)&lcce);
	}

	return 0;
}
//��Ԫ���Ƿ���Ա༭
BOOL CListCtrlCl::GetItemEnableEdit(int nSubItem)
{
	BOOL bEnableEdit=FALSE;
	vector<ListCtrlColEdit> vec = m_vecEdit;
	if (m_vecEdit.size() > 0)
	{
		//ʹ�õ���������Ԫ��.
		vector<ListCtrlColEdit>::iterator it;
		for (it = vec.begin(); it != vec.end(); it++)
		{
			int iCol=it->col;
			bEnableEdit=it->bEnableEdit;
			if(nSubItem==iCol)
			{
				break;
			}
		}
		//
	}
	//
	return bEnableEdit;
}

//��Ԫ���Ƿ���Ա༭
BOOL CListCtrlCl::GetItemShowButton(int nSubItem)
{
	BOOL bShowButton=FALSE;
	vector<ListCtrlColButton> vec = m_vecButton;
	if (m_vecEdit.size() > 0)
	{
		//ʹ�õ���������Ԫ��.
		vector<ListCtrlColButton>::iterator it;
		for (it = vec.begin(); it != vec.end(); it++)
		{
			int iCol=it->col;
			bShowButton=it->bShowButton;
			if(nSubItem==iCol)
			{
				break;
			}
		}
		//
	}
	//
	return bShowButton;
}
///////////////////////////////////////////////////////////////////////////////
// GetHeaderCheckedState
//
// The GetHeaderCheckedState and SetHeaderCheckedState may be used to toggle
// the checkbox in a column header.
//     0 = no checkbox
//     1 = unchecked
//     2 = checked
//
int CListCtrlCl::GetHeaderCheckedState()
{
	int iValue = 0;
	BOOL bShowCheckBoxSign = m_Header.GetShowCheckBoxSign();//ȡ���Ƿ���ʾ��ѡ��
	if (bShowCheckBoxSign)//���ڸ�ѡ ��
	{
		iValue = 1;//δѡ��
		BOOL bChecked = m_Header.GetCheckState();
		if (bChecked)
		{
			iValue = 2;//ѡ��
		}
	}
	return iValue;
}

///////////////////////////////////////////////////////////////////////////////
// SetHeaderCheckedState
/**
����ͷ���Ƿ���ʾ ��ѡ��Ĭ��Ϊ0����ʾ��
// The GetHeaderCheckedState and SetHeaderCheckedState may be used to toggle
// the checkbox in a column header.
//     0 = no checkbox
//     1 = unchecked
//     2 = checked
//
*/
BOOL CListCtrlCl::SetHeaderCheckedState(int nCheckedState)
{
	if (nCheckedState == 0)//�� ��ѡ ��
	{
		m_Header.SetShowCheckBoxSign(FALSE);
	}
	else
	{
		m_Header.SetShowCheckBoxSign(TRUE);
		//�����Ƿ�ѡ��
		if (nCheckedState == 1)//δѡ ��
		{
			m_Header.SetCheckState(FALSE);
		}
		else if (nCheckedState == 2)//ѡ ��
		{
			m_Header.SetCheckState(TRUE);
		}
	}
	

	return TRUE;
}
//
int CListCtrlCl::GetColumns()
{
	return GetHeaderCtrl()->GetItemCount();
}
//
LRESULT CListCtrlCl::OnHeadCtrlLButtonDown(WPARAM wParam, LPARAM lParam)
{
	if (!m_bShowCheckBoxSign)
		return 0;
	//AfxMessageBox(_T("dddd"));
	RECT rectiSubItem = { 0 };

	int nTotalColumn = 0;
	int nItem = -1;
	int nColumn = -1;

	CHeaderCtrl* pListHeader = NULL;
	pListHeader = (CHeaderCtrl*)GetDlgItem(0);
	nTotalColumn = pListHeader->GetItemCount();

	BOOL bChecked = m_Header.GetCheckState();
	if (bChecked)//ѡ��
	{
		for (int i = 0; i < GetItemCount(); ++i)
		{
			nItem = i;
			m_bItemCheckState[nItem] = TRUE;
			InvalidateRect(NULL, FALSE);
		}
	}
	else
	{
		for (int i = 0; i < GetItemCount(); ++i)
		{
			nItem = i;
			m_bItemCheckState[nItem] = FALSE;
			InvalidateRect(NULL, FALSE);
		}
	}

	return 0;
}

/**
ȡ���Ƿ���ʾ��ѡ �� 
Ĭ��Ϊ0��
*/
BOOL CListCtrlCl::GetShowCheckBoxSign()
{
	return m_bShowCheckBoxSign;
}

/**
�����Ƿ���ʾ��ѡ ��
Ĭ��Ϊ0��
*/
void CListCtrlCl::SetShowCheckBoxSign(BOOL bShowCheckBoxSign)
{
	m_bShowCheckBoxSign = bShowCheckBoxSign;
}

/**
�����Ƿ�ѡ���� ѡ��ѡ��
*/
void CListCtrlCl::SetSingleRowCheck(BOOL bSingleRowCheckSign)
{
	m_bSingleRowCheck = bSingleRowCheckSign;
}
///////////////////////////////////////////////////////////////////////////////
// SetCheckbox
BOOL CListCtrlCl::SetCheckbox(int nItem, int nSubItem, int nCheckedState)
{
	ASSERT(nItem >= 0);
	ASSERT(nItem < GetItemCount());
	if ((nItem < 0) || nItem >= GetItemCount())
		return FALSE;
	ASSERT(nSubItem >= 0);
	ASSERT(nSubItem < GetColumns());
	if ((nSubItem < 0) || nSubItem >= GetColumns())
		return FALSE;
	ASSERT(nCheckedState == 0 || nCheckedState == 1 || nCheckedState == -1);


	// update checkbox in subitem

	m_bItemCheckState[nItem] = nCheckedState;

	UpdateSubItem(nItem, nSubItem);

	// now update checkbox in column header
	// -1 = no checkbox in column header
	if (GetHeaderCheckedState() != 0)
	{
		int nCheckedCount = GetCountCheckedItems();

		if (nCheckedCount == GetItemCount())
			SetHeaderCheckedState(TRUE);
		else
			SetHeaderCheckedState(FALSE);
	}

	return TRUE;
}
///////////////////////////////////////////////////////////////////////////////
// UpdateSubItem
void CListCtrlCl::UpdateSubItem(int nItem, int nSubItem)
{
	ASSERT(nItem >= 0);
	ASSERT(nItem < GetItemCount());
	if ((nItem < 0) || nItem >= GetItemCount())
		return;
	ASSERT(nSubItem >= 0);
	ASSERT(nSubItem < GetColumns());
	if ((nSubItem < 0) || nSubItem >= GetColumns())
		return;

	CRect rect;
	if (nSubItem == -1)
	{
		GetItemRect(nItem, &rect, LVIR_BOUNDS);
	}
	else
	{
		GetSubItemRect(nItem, nSubItem, LVIR_BOUNDS, rect);
	}

	rect.InflateRect(2, 2);

	InvalidateRect(&rect);
	UpdateWindow();
}
///////////////////////////////////////////////////////////////////////////////
// CountCheckedItems
int CListCtrlCl::GetCountCheckedItems()
{
	int nCount = 0;

	for (int nItem = 0; nItem < GetItemCount(); nItem++)
	{
		if (m_bItemCheckState[nItem])
			nCount++;
	}

	return nCount;
}

// overwrite:
void CListCtrlCl::DrawSubItem(CDC *pDC, int nItem, int nSubItem, CRect &rSubItem, bool bSelected, bool bFocus)
{


	/*pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(0, 0, 0));

	CFont font;
	font.CreateFont(16,   // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("����"));
	pDC->SelectObject(&font);

	CString strText;
	strText = GetItemText(nItem, nSubItem);

	draw_row_bg(pDC, rSubItem, bSelected, bFocus, nItem);

	pDC->SetTextColor(RGB(58, 89, 109));//�����ı���ɫ
	pDC->DrawText(strText, strText.GetLength(), &rSubItem, DT_SINGLELINE | DT_CENTER | DT_VCENTER | DT_END_ELLIPSIS);

	//�Ƿ���ʾ��ѡ ��
	if (m_bShowCheckBoxSign)
	{
		//��0��,��ʾcheckbox
		if (nSubItem == 0)
		{
			//���Ƹ�ѡ��
			DrawCheckbox(nItem, nSubItem, pDC, rSubItem);
		}
	}*/


}
///////////////////////////////////////////////////////////////////////////////
// DrawCheckbox
void CListCtrlCl::DrawCheckbox(int nItem, int nSubItem, CDC *pDC, CRect& rect)
{
	ASSERT(pDC);

	if (rect.IsRectEmpty())
	{
		return;
	}

	//GetDrawColors(nItem, nSubItem, crText, crBkgnd);
	//pDC->FillSolidRect(&rect, crBkgnd);

	CRect chkboxrect;
	/*chkboxrect = rect;
	chkboxrect.top -= 10;//�ϱ߾�
	chkboxrect.bottom -= 30;
	chkboxrect.left += 5;		// line up checkbox with header checkbox
	chkboxrect.right = chkboxrect.left + chkboxrect.Height();	// width = height*/
	int h = 15;	// height and width are the same
	chkboxrect.left = rect.left + rect.Width() / 2 - h / 2 - 1;
	chkboxrect.right = chkboxrect.left + h;
	chkboxrect.top = rect.top ;//+ (rect.Height() - h) / 2;
	chkboxrect.bottom = chkboxrect.top + h;

	CString str;
	str = GetItemText(nItem, nSubItem);

	if (str.IsEmpty())
	{
		// center the checkbox
		chkboxrect.left = rect.left + rect.Width() / 2 - chkboxrect.Height() / 2 - 1;
		chkboxrect.right = chkboxrect.left + chkboxrect.Height();
	}

	// fill rect around checkbox with white
	pDC->FillSolidRect(&chkboxrect, m_crWindow);
	// draw border 51, 102, 153
	CBrush brush(RGB(96, 135, 142));//96,135,142//�߿���ɫ
	pDC->FrameRect(&chkboxrect, &brush);

	if (m_bItemCheckState[nItem])
	{
		CPen *pOldPen = NULL;

		//CPen graypen(PS_SOLID, 1, m_crGrayText);
		CPen blackpen(PS_SOLID, 1, RGB(51, 153, 51));//������ɫ����ѡ��ɫ��

	    /*if (pXLCD[0].bEnabled)
		pOldPen = pDC->SelectObject(&blackpen);
		else
		pOldPen = pDC->SelectObject(&graypen);*/
		pOldPen = pDC->SelectObject(&blackpen);

		// draw the checkmark
		int x = chkboxrect.left + 10;
		ASSERT(x < chkboxrect.right);
		int y = chkboxrect.top + 4;
		int i;
		//
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
}

void CListCtrlCl::draw_row_bg(CDC *pDC, RECT rc, bool bSelected, bool bFocus, int nRow)
{

	bool bOdd = (nRow % 2 == 0 ? true : false);

	CRect rect = rc;
	if (rect.Width() == 0)
	{
		return;
	}

	draw_row_bg(pDC, rc, bSelected, bFocus, bOdd);
}

void CListCtrlCl::draw_row_bg(CDC *pDC, RECT rc, bool bSelected, bool bFocus, bool bOdd)
{
	CRect rect = rc;
	if (rect.Width() == 0)
	{
		return;
	}

	int nSave = pDC->SaveDC();

	if (bOdd)//�������ɫ��һ��
	{
		CBrush oddBrush;
		oddBrush.CreateSolidBrush(RGB(255, 255, 255));
		pDC->FillRect(&rc, &oddBrush);

	}
	else//�������ɫ������
	{
		CBrush normalBrush;
		normalBrush.CreateSolidBrush(RGB(245, 250, 252));
		pDC->FillRect(&rc, &normalBrush);
	}

	if (bSelected)
	{
		if (bFocus)//��ý���ʱ
		{
			CBrush selectBrush;
			selectBrush.CreateSolidBrush(RGB(233, 250, 213));//RGB(203, 223, 239)
			pDC->FillRect(&rc, &selectBrush);

		}
		else//ʧȥ����ʱ
		{
			CBrush selectNoFocusBrush;
			selectNoFocusBrush.CreateSolidBrush(RGB(233, 250, 213));//209, 250, 252
			pDC->FillRect(&rc, &selectNoFocusBrush);
		}

	}

	// ������RGB(209, 229, 240)
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(209, 229, 240));//RGB(218, 218, 218)

	pDC->SelectObject(&pen);
	pDC->MoveTo(rc.right - 1, rc.top);
	pDC->LineTo(rc.right - 1, rc.bottom);

	// ��ѡ�еĵײ��ָ���
	if (bSelected)
	{
		CPen bottomPen;
		bottomPen.CreatePen(PS_SOLID, 1, RGB(209, 229, 240));//RGB(255, 255, 255)

		pDC->SelectObject(&bottomPen);
		pDC->MoveTo(rc.left, rc.bottom - 1);
		pDC->LineTo(rc.right, rc.bottom - 1);
	}

	pDC->RestoreDC(nSave);
}

void CListCtrlCl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (!m_bShowCheckBoxSign)
	{
		CListCtrl::OnLButtonDown(nFlags, point);
		return;
	}
	RECT rectiSubItem = { 0 };

	int nTotalColumn = 0;
	int nItem = -1;
	int nColumn = -1;
	int iSubItem = -1;

	CHeaderCtrl* pListHeader = NULL;

	pListHeader = (CHeaderCtrl*)GetDlgItem(0);
	nTotalColumn = pListHeader->GetItemCount();
	//+++
	LVHITTESTINFO lvhit;
	lvhit.pt = point;
	SubItemHitTest(&lvhit);
	if (lvhit.flags & LVHT_ONITEMLABEL)
	{
		nItem = lvhit.iItem;
		iSubItem = lvhit.iSubItem;
		if (iSubItem == 0 || m_bSingleRowCheck)//ѡ���0�У��������õ�����ѡ��  
		{
			GetSubItemRect(nItem, iSubItem, LVIR_BOUNDS, (CRect&)rectiSubItem);

			if (PtInRect(&rectiSubItem, point))
			{
				m_bItemCheckState[nItem] = !m_bItemCheckState[nItem];
				InvalidateRect(NULL, FALSE);
			}
		}
	}
	//
	if (GetHeaderCheckedState() != 0)//HEADER��ʾ��ѡ ��
	{
		int nCheckedCount = GetCountCheckedItems();

		if (nCheckedCount == GetItemCount())
			m_Header.SetCheckState(TRUE);
		else
			m_Header.SetCheckState(FALSE);
	}

		

	CListCtrl::OnLButtonDown(nFlags, point);
}

int CListCtrlCl::GetFirsetSelectedItem()
{
	int nItem = -1;

	for (int iItem = 0;iItem < MAX_LISTITEM;++iItem)
	{
		if (m_bItemCheckState[iItem])
		{
			nItem = iItem;//���ص�һ����ѡ����
			break;
		}
	}
	return nItem;
}

int CListCtrlCl::GetNextSelectedItem(int nItem)
{
	int nNextItem = -1;
	for (int iItem = nItem + 1;iItem < MAX_LISTITEM;++iItem)
	{
		if (m_bItemCheckState[iItem])
		{
			nNextItem = iItem;
			break;
		}
	}
	return nNextItem;
}
// ��ʣ�ಿ��
void CListCtrlCl::DrawRemainSpace(LPNMLVCUSTOMDRAW lpnmcd)
{
	int nTop = lpnmcd->nmcd.rc.top;
	int nCount = GetItemCount();
	if (nCount > 0)
	{
		CRect rcItem;
		GetItemRect(nCount - 1, &rcItem, LVIR_LABEL);
		nTop = rcItem.bottom;
	}

	//bool bSelected = lpnmcd->nmcd.uItemState;//LVIS_SELECTED

	CRect rectClient;
	GetClientRect(&rectClient);
	if (nTop < lpnmcd->nmcd.rc.bottom) // ��ʣ��
	{
		CRect rcRemain = lpnmcd->nmcd.rc;
		rcRemain.top = nTop;
		rcRemain.right = rectClient.right;
		int nRemainItem = rcRemain.Height() / LIST_ITEM_HEIGHT;
		if (rcRemain.Height() % LIST_ITEM_HEIGHT)
		{
			nRemainItem++;
		}

		int pos = GetScrollPos(SB_HORZ);
		CDC dc;
		dc.Attach(lpnmcd->nmcd.hdc);
		int nColumnCount = GetHeaderCtrl()->GetItemCount();
		CRect  rcSubItem;
		CRect rcItem;
		for (int i = 0; i < nRemainItem; ++i)
		{

			rcItem.top = rcRemain.top + i * LIST_ITEM_HEIGHT;
			rcItem.left = rcRemain.left;
			rcItem.right = rcRemain.right;
			rcItem.bottom = rcItem.top + LIST_ITEM_HEIGHT;
			for (int j = 0; j < nColumnCount; ++j)
			{
				GetHeaderCtrl()->GetItemRect(j, &rcSubItem);
				rcSubItem.top = rcItem.top;
				rcSubItem.bottom = rcItem.bottom;
				rcSubItem.OffsetRect(-pos, 0);
				if (rcSubItem.right < rcRemain.left || rcSubItem.left > rcRemain.right)
					continue;
				draw_row_bg(&dc, rcSubItem, false, false, i + nCount);
			}
			if (rcSubItem.right<rectClient.right)
			{
				rcSubItem.left = rcSubItem.right;
				rcSubItem.right = rectClient.right;
				draw_row_bg(&dc, rcSubItem, false, false, i + nCount);
			}

		}

		dc.Detach();
	}
}
LRESULT CListCtrlCl::OnMyBtnClicked(WPARAM wParam, LPARAM lParam)
{
	
		//�򸸴��ڷ�����Ϣ����ʾ��ֵ�޸�
		ListCtrlColButton lccb;
		lccb.row=m_nItem;
		lccb.col=m_nSubItem;
		//lccb.strText=strText;//.GetBuffer(strText.GetLength());
		//AfxMessageBox(strText);
		//SendMessage(WM_NOTIFY, GetDlgCtrlID(), (LPARAM)&dispinfo );
		CWnd* pParent = this->GetParent();
		//SetItemTextColor(m_nSubItem,m_nItem,RGB(255,0,0));
		::SendMessage(pParent->GetSafeHwnd(),WM_USER_BUTTON_CLICKED,0,(LPARAM)&lccb);
	

	return 0;
}

void CListCtrlCl::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (!m_bShowCheckBoxSign)
	{
		CListCtrl::OnLButtonDown(nFlags, point);
		return;
	}
	RECT rectiSubItem = { 0 };

	int nTotalColumn = 0;
	int nItem = -1;
	int nColumn = -1;
	int iSubItem = -1;

	CHeaderCtrl* pListHeader = NULL;

	pListHeader = (CHeaderCtrl*)GetDlgItem(0);
	nTotalColumn = pListHeader->GetItemCount();
	//+++
	LVHITTESTINFO lvhit;
	lvhit.pt = point;
	SubItemHitTest(&lvhit);
	if (lvhit.flags & LVHT_ONITEMLABEL)
	{
		nItem = lvhit.iItem;
		iSubItem = lvhit.iSubItem;
		if (iSubItem == 0 || m_bSingleRowCheck)//ѡ���0�У��������õ�����ѡ��  
		{
			
		}else
			if(GetItemShowButton(iSubItem))
			{
				m_nItem = nItem;//ȡ����
				m_nSubItem = iSubItem;//ȡ����
				
				CRect rc;
				GetSubItemRect(nItem, iSubItem, LVIR_BOUNDS, (CRect&)rc);
				//��ʾ�༭��
				ShowButton(TRUE, nItem, iSubItem,rc);
			}else
			{
				//����������ʾ�İ�ť
				vector<ListCtrlColButton> vec = m_vecButton;
				if (m_vecEdit.size() > 0)
				{
					//ʹ�õ���������Ԫ��.
					vector<ListCtrlColButton>::iterator it;
					for (it = vec.begin(); it != vec.end(); it++)
					{
						int iRow=it->row;
						int iCol=it->col;
						BOOL bShowButton=it->bShowButton;
						if(bShowButton)
						{
							CRect rc;
							GetSubItemRect(iRow, iCol, LVIR_BOUNDS, (CRect&)rc);
							ShowButton(FALSE, iRow, iCol,rc);
						}
					}
					//
				}
			}
	}

	
	CListCtrl::OnMouseMove(nFlags, point);
}
