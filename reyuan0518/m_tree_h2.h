﻿#pragma once


// m_tree_h2 对话框

class m_tree_h2 : public CDialogEx
{
	DECLARE_DYNAMIC(m_tree_h2)

public:
	m_tree_h2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~m_tree_h2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SET_YL_JLGS_h2JLBT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
