﻿#pragma once


// m_tree_h6dybgrq 对话框

class m_tree_h6dybgrq : public CDialogEx
{
	DECLARE_DYNAMIC(m_tree_h6dybgrq)

public:
	m_tree_h6dybgrq(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~m_tree_h6dybgrq();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TREEH6_DYBGRQ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
