#pragma once


// m_tree_h5 对话框

class m_tree_h5 : public CDialogEx
{
	DECLARE_DYNAMIC(m_tree_h5)

public:
	m_tree_h5(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~m_tree_h5();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SET_YL_JLGS_h5WDQX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
