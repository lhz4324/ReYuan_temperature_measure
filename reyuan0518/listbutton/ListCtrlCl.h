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
	int		col;			//��
	int		row;			//��
	BOOL	bEnableEdit;	//�Ƿ�ɱ༭(����༭��)
	CString strText;		//����
};

struct ListCtrlColButton
{
	int		col;			//��
	int		row;			//��
	BOOL	bShowButton;	//�Ƿ���ʾ��ť
	CString strText;		//����
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
	//ȡ�ñ�ѡ�еĵ�һ��
	int GetFirsetSelectedItem();
	//������һ��ѡ����
	int GetNextSelectedItem(int nItem);
	void SetShowCheckBoxSign(BOOL bShowCheckBoxSign);//���� �Ƿ���ʾ��ѡ ��
	void SetSingleRowCheck(BOOL bSingleRowCheckSign);//������ ѡ��ѡ��
	BOOL GetShowCheckBoxSign();//�Ƿ���ʾ��ѡ��
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
	CHeaderCtrlCl m_Header; //��ͷ
	int m_nRowHeight;// �и�
	CPtrList m_ptrListCol;  //��������ɫ
	CPtrList m_ptrListItem; //����Item��ɫ��
	CPtrList m_colTextColor; //������������ɫ
	CPtrList m_ItemTextColor; //���浥Ԫ��������ɫ
	COLORREF m_color;
	int m_fontHeight;	// ����߶�
	int m_fontWith;         // ������
public:
	// ���ñ�ͷ�߶�
	void SetHeaderHeight(float Height);
	// Gradient - ����ϵ�������屳����,���ý�����Ϊ0
	void SetHeaderBKColor(int R, int G, int B, int Gradient);
	int InsertColumn(int nCol, LPCTSTR lpszColumnHeading,int nFormat = LVCFMT_LEFT, int nWidth = -1, BOOL bEnableEdit=FALSE, BOOL bShowButton=FALSE, int nSubItem = -1);
	void SetHeaderFontHW(int nHeight,int nWith); //���ñ�ͷ�����С
	void SetHeaderTextColor(COLORREF color);
	void SetRowHeight(int nHeight); //�����и�
	bool FindColColor(int col ,COLORREF &color); //��������ɫ
	bool FindItemColor(int col,int row,COLORREF &color);
	bool FindColTextColor(int col,COLORREF &color); //������������ɫ
	bool FindItemTextColor(int col,int row,COLORREF &color);
	void SetColColor(int col,COLORREF color);  //��������ɫ
	void SetItemColor(int col,int row,COLORREF color); //����Item��ɫ
	void SetColTextColor(int col,COLORREF color);   //�������ı���ɫ
	void SetItemTextColor(int col,int row,COLORREF color);
	void SetTextColor(COLORREF cr);
	void SetFontHW(int nHeight,int nWith);  //��������ĸߺͿ�

public:
	int m_nItem;               // ��
    int m_nSubItem;            // ��
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
