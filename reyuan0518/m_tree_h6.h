#pragma once
#include "m_tree_h6dybgrq.h"
#include "m_tree_h6tp.h"
#include "m_tree_h6wb.h"
#include "m_tree_h6xd.h"
// m_tree_h6 对话框

class m_tree_h6 : public CDialogEx
{
	DECLARE_DYNAMIC(m_tree_h6)

public:
	m_tree_h6(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~m_tree_h6();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SET_YL_JLGS_h6FZX};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl r_tab1;

	//tab的四个子菜单
	m_tree_h6wb* cTabDlg1;
	m_tree_h6dybgrq* cTabDlg2;
	m_tree_h6xd* cTabDlg3;
	m_tree_h6tp* cTabDlg4;

	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
};
