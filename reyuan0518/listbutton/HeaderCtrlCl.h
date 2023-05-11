#if !defined(AFX_HEADERCTRLCL_H__D70906BC_ED2E_45AE_A20B_AFBD0AB1C283__INCLUDED_)
#define AFX_HEADERCTRLCL_H__D70906BC_ED2E_45AE_A20B_AFBD0AB1C283__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HeaderCtrlCl.h : header file
//
#include<iostream>
#include<vector>
using namespace std;

#define		WM_LBUTTONDOWN_MYMSG	(WM_USER+1092)
/////////////////////////////////////////////////////////////////////////////
// CHeaderCtrlCl window

class CHeaderCtrlCl : public CHeaderCtrl
{
// Construction
public:
	CHeaderCtrlCl();

public:
	BOOL	m_bChecked;
	BOOL	m_bShowCheckBox;
	void DrawCheckbox( CDC *pDC, CRect& rect);
	void SetShowCheckBoxSign(BOOL bShowCheckBoxSign);
	BOOL GetShowCheckBoxSign();
	void SetCheckState(BOOL bChecked);
	BOOL GetCheckState();
// Attributes
public:
	
	afx_msg void OnPaint();
	CStringArray m_HChar;
	CString m_Format; //表示对齐类型的整型数组,0表示左对齐，1表示中间对齐，2表示右对齐

// Operations
public:
	int m_R;
	int m_G;
	int m_B;
	int m_Gradient;	// 画立体背景，渐变系数
	float m_Height;  //表头高度，这是倍数,
	int m_fontHeight; //字体高度
	int m_fontWith;   //字体宽度
	COLORREF m_color;
	LRESULT OnLayout( WPARAM wParam, LPARAM lParam );

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHeaderCtrlCl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHeaderCtrlCl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CHeaderCtrlCl)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HEADERCTRLCL_H__D70906BC_ED2E_45AE_A20B_AFBD0AB1C283__INCLUDED_)
