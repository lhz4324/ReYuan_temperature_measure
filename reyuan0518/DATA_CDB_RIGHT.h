#pragma once


// DATA_CDB_RIGHT 对话框

class DATA_CDB_RIGHT : public CDialogEx
{
	DECLARE_DYNAMIC(DATA_CDB_RIGHT)

public:
	DATA_CDB_RIGHT(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DATA_CDB_RIGHT();

// 对话框数据
	enum { IDD = IDD_FV_DATA_CDB_RIGHT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
