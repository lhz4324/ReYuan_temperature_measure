#if !defined(AFX_LISTCTRLEDIT_H__97E4FD98_B41E_4EFE_8018_19BFEA6E751A__INCLUDED_)
#define AFX_LISTCTRLEDIT_H__97E4FD98_B41E_4EFE_8018_19BFEA6E751A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListCtrlEdit.h : header file

//

#include<iostream>
#include<vector>
using namespace std;

#define WM_USER_EDIT_END WM_USER + 1091
/////////////////////////////////////////////////////////////////////////////
// CListCtrlEdit window

class CListCtrlEdit : public CEdit
{
// Construction
public:
	CListCtrlEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListCtrlEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CListCtrlEdit)
	afx_msg void OnKillfocus();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTRLEDIT_H__97E4FD98_B41E_4EFE_8018_19BFEA6E751A__INCLUDED_)
