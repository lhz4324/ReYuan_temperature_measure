#pragma once

#include "./CyAPI.h"//导入头文件，
#pragma comment(lib,"./CyAPI.lib")//指定路径，导入静态链接库

// FV_POINT_BD 窗体视图

class FV_POINT_BD : public CFormView
{
	DECLARE_DYNCREATE(FV_POINT_BD)

protected:
	FV_POINT_BD();           // 动态创建所使用的受保护的构造函数
	virtual ~FV_POINT_BD();

public:
	enum { IDD = IDD_POINT_BD };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton10();
	virtual void OnInitialUpdate();

	CButton* NewMyButton(int nID, CRect rect, int nStyle);
	CStatic* NewMyText(int nID, CRect rect, int nStyle);
	CEdit* NewMyEdit(int nID, CRect rect, int nStyle);

	afx_msg void OnButtonPort(UINT nID);//区分端口号，对应不同id，做出不同反应

	afx_msg void OnBnClicked1005();
	afx_msg void OnBnClicked1006();
	afx_msg void OnBnClicked1007();
	afx_msg void OnBnClicked1008();
	afx_msg void OnBnClickedButton11();


	int point_array[128];//记录该探头是否选中
	afx_msg void OnBnClicked1031();
	CString First_t;
	CString Second_t;
	CString Third_t;
	CString Fourth_t;
	CString Fifth_t;
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClicked1030();



	CCyUSBDevice *mCCyUsbDevice;
	CCyUSBEndPoint *OutEndpt;
	CCyUSBEndPoint *InEndpt;

	bool bLooping;
	CWinThread *XferThread;//线程
	virtual void PostNcDestroy();

};


