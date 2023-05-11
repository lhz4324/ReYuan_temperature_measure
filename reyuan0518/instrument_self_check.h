#pragma once

#include "./CyAPI.h"//导入头文件，
#pragma comment(lib,"./CyAPI.lib")//指定路径，导入静态链接库

// instrument_self_check 对话框

class instrument_self_check : public CDialogEx
{
	DECLARE_DYNAMIC(instrument_self_check)

public:
	instrument_self_check(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~instrument_self_check();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_instrument_self_check };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	// 进度条控制
	CProgressCtrl m_Progress;
	int progress_pos;


	CCyUSBDevice*mCCyUSBDevice;
	bool isDevice;
	bool isWaring;
	bool isRead;
	bool iscollect;
};
