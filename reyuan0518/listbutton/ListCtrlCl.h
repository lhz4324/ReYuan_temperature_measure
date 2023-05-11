#if !defined(AFX_LISTCTRLCL_H__98BE3BE3_8B77_4EC4_B8A8_90099DBB3326__INCLUDED_)
#define AFX_LISTCTRLCL_H__98BE3BE3_8B77_4EC4_B8A8_90099DBB3326__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListCtrlCl.h : header file
//
#include "HeaderCtrlCl.h"
#include "ListCtrlEdit.h"
#include "ListCtrlButton.h"


#include<iostream>
#include<vector>
using namespace std;

#define IDC_EDIT	1091
#define IDC_BUTTON	1092

#define WM_USER_EDITTEXT_CHANGE WM_USER + 1080
#define WM_USER_BUTTON_CLICKED	WM_USER + 1081

#define MAX_LISTITEM 200
/////////////////////////////////////////////////////////////////////////////
// CListCtrlCl window

struct ListCtrlColEdit
{
	int		col;			//列
	int		row;			//行
	BOOL	bEnableEdit;	//是否可编辑(加入编辑框)
	CString strText;		//内容
};

struct ListCtrlColButton
{
	int		col;			//列
	int		row;			//行
	BOOL	bShowButton;	//是否显示按钮
	CString strText;		//内容
};

struct stColor
{
	int nRow;
	int nCol;
	COLORREF rgb;
};


class CListCtrlCl : public CListCtrl
{
// Construction
public:
	CListCtrlCl();

// Attributes
public:
	unsigned int LIST_ITEM_HEIGHT;
	COLORREF		m_crGrayText;
	COLORREF		m_crWindow;
	COLORREF		m_crWindowText;
	void DrawCheckbox(int nItem,int nSubItem,CDC *pDC,CRect& rect);
	BOOL m_bSingleRowCheck;
	BOOL m_bShowCheckBoxSign;
	BOOL m_bItemCheckState[MAX_LISTITEM];

	void DrawRemainSpace(LPNMLVCUSTOMDRAW lpnmcd);
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
	//取得被选中的第一项
	int GetFirsetSelectedItem();
	//返回下一个选中项
	int GetNextSelectedItem(int nItem);
	void SetShowCheckBoxSign(BOOL bShowCheckBoxSign);//设置 是否显示复选 框
	void SetSingleRowCheck(BOOL bSingleRowCheckSign);//单击行 选择复选框
	BOOL GetShowCheckBoxSign();//是否显示复选框
	int GetColumns();
	BOOL SetCheckbox(int nItem, int nSubItem, int nCheckedState);
	void UpdateSubItem(int nItem, int nSubItem);
	int GetCountCheckedItems();
	int	SetHeaderCheckedState(int nCheckedState);
	int GetHeaderCheckedState();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlCl)
	virtual void PreSubclassWindow();
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void DrawSubItem(CDC *pDC, int nItem, int nSubItem, CRect &rSubItem, bool bSelected, bool bFocus);
	virtual void draw_row_bg(CDC *pDC, RECT rc, bool bSelected, bool bFocus,int nRow);
	virtual void draw_row_bg(CDC *pDC, RECT rc, bool bSelected, bool bFocus, bool bOdd);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListCtrlCl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CListCtrlCl)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg LRESULT OnMyBtnClicked(WPARAM wParam,LPARAM lParam = FALSE);
	afx_msg LRESULT OnEditEnd(WPARAM wParam,LPARAM lParam = FALSE);
	afx_msg LRESULT OnHeadCtrlLButtonDown(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

protected:
	CHeaderCtrlCl m_Header; //表头
	int m_nRowHeight;// 行高
	CPtrList m_ptrListCol;  //保存列颜色
	CPtrList m_ptrListItem; //保存Item颜色表
	CPtrList m_colTextColor; //保存列字体颜色
	CPtrList m_ItemTextColor; //保存单元格字体颜色
	COLORREF m_color;
	int m_fontHeight;	// 字体高度
	int m_fontWith;         // 字体宽度
public:
	// 设置表头高度
	void SetHeaderHeight(float Height);
	// Gradient - 渐变系数，立体背景用,不用渐变设为0
	void SetHeaderBKColor(int R, int G, int B, int Gradient);
	int InsertColumn(int nCol, LPCTSTR lpszColumnHeading,int nFormat = LVCFMT_LEFT, int nWidth = -1, BOOL bEnableEdit=FALSE, BOOL bShowButton=FALSE, int nSubItem = -1);
	void SetHeaderFontHW(int nHeight,int nWith); //设置表头字体大小
	void SetHeaderTextColor(COLORREF color);
	void SetRowHeight(int nHeight); //设置行高
	bool FindColColor(int col ,COLORREF &color); //查找列颜色
	bool FindItemColor(int col,int row,COLORREF &color);
	bool FindColTextColor(int col,COLORREF &color); //查找列字体颜色
	bool FindItemTextColor(int col,int row,COLORREF &color);
	void SetColColor(int col,COLORREF color);  //设置列颜色
	void SetItemColor(int col,int row,COLORREF color); //设置Item颜色
	void SetColTextColor(int col,COLORREF color);   //设置列文本颜色
	void SetItemTextColor(int col,int row,COLORREF color);
	void SetTextColor(COLORREF cr);
	void SetFontHW(int nHeight,int nWith);  //设置字体的高和宽

public:
	int m_nItem;               // 行
    int m_nSubItem;            // 列
	CListCtrlButton m_Button;
    CListCtrlEdit m_Edit;
	CString m_strItemOldValue;
	vector<ListCtrlColEdit> m_vecEdit;
	vector<ListCtrlColButton> m_vecButton;
	BOOL GetItemEnableEdit(int nSubItem);
    void ShowEdit(bool bShow, int nItem, int nSubItem, CRect rcCtrl);
	//
	BOOL GetItemShowButton(int nSubItem);
	void ShowButton(bool bShow, int nItem, int nSubItem, CRect& rect);

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTRLCL_H__98BE3BE3_8B77_4EC4_B8A8_90099DBB3326__INCLUDED_)
