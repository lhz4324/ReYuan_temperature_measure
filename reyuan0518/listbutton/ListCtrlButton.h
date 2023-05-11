#if !defined(AFX_LISTCTRLBUTTON_H__D859227C_A0FA_45A7_840C_1FA26F39D917__INCLUDED_)
#define AFX_LISTCTRLBUTTON_H__D859227C_A0FA_45A7_840C_1FA26F39D917__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListCtrlButton.h : header file
//

#include<iostream>
#include<vector>
using namespace std;

#define WM_USER_BTN_CLICK WM_USER + 1093
/////////////////////////////////////////////////////////////////////////////
// CListCtrlButton window

class CListCtrlButton : public CButton
{
// Construction
public:
	CListCtrlButton();

// Attributes
public:
	//设置Button Down的背景颜色
    void SetDownColor(COLORREF color);
    //设置Button Up的背景颜色
	void SetUpColor(COLORREF color);
	BOOL Attach(const UINT nID, CWnd* pParent);
// Operations
public:
	//三种颜色分别为文字，Button Down的背景颜色，Button Up的背景颜色
	COLORREF m_TextColor, m_DownColor, m_UpColor;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListCtrlButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CListCtrlButton)
	afx_msg void OnClicked();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTRLBUTTON_H__D859227C_A0FA_45A7_840C_1FA26F39D917__INCLUDED_)
