#pragma once


// m_tree_h6tp 对话框

class m_tree_h6tp : public CDialogEx
{
	DECLARE_DYNAMIC(m_tree_h6tp)

public:
	m_tree_h6tp(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~m_tree_h6tp();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TREEH6_TP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
