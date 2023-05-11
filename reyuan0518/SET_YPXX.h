#pragma once
#include "afxcmn.h"
#include "Quanjv.h"
#include "afxwin.h"

//#include "MyDatabase.h"
// SET_YPXX 对话框

class SET_YPXX : public CDialogEx
{
	DECLARE_DYNAMIC(SET_YPXX)

public:
	SET_YPXX(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SET_YPXX();

// 对话框数据
	enum { IDD = IDD_SET_YPXX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	//MyDatabase mydatabase;

private:
	CListCtrl SET_YPXX_LIST;
	CString SET_YPXX_YPMC;
	CString SET_YPXX_GG;
	CString SET_YPXX_GSRY;
	int list_row_index;

	int m_listSelPos;//获取选中的当前行
public:
	afx_msg void OnBnClicked1003();
	afx_msg void OnBnClicked1006();
	afx_msg void OnNMClick1037(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClicked1005();
	CEdit YPMC_control;
	CEdit GG_control;
	CEdit GSRY_control;
	CString SET_YPXX_JL;
	CEdit JL_control;
	afx_msg void OnBnClicked1007();
};
