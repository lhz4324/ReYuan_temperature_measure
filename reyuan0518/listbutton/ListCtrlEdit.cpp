// ListCtrlEdit.cpp : implementation file
//

#include "stdafx.h"
//#include "../Tab_CEWEN_WDCD_SYPC.h"
#include "ListCtrlEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListCtrlEdit

CListCtrlEdit::CListCtrlEdit()
{
}

CListCtrlEdit::~CListCtrlEdit()
{
}


BEGIN_MESSAGE_MAP(CListCtrlEdit, CEdit)
	//{{AFX_MSG_MAP(CListCtrlEdit)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, OnKillfocus)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListCtrlEdit message handlers

void CListCtrlEdit::OnKillfocus() 
{
	// TODO: Add your control notification handler code here
	// 向父窗口发消息
    CWnd* pParent = this->GetParent();
    ::PostMessage(pParent->GetSafeHwnd(),WM_USER_EDIT_END,0,0);
}
