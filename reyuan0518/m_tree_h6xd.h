#pragma once


// m_tree_h6xd 对话框

class m_tree_h6xd : public CDialogEx
{
	DECLARE_DYNAMIC(m_tree_h6xd)

public:
	m_tree_h6xd(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~m_tree_h6xd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TREEH6_XD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
