
// reyuan0518.h : reyuan0518 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// Creyuan0518App:
// 有关此类的实现，请参阅 reyuan0518.cpp
//

class Creyuan0518App : public CWinApp
{
public:
	Creyuan0518App();

public://菜单中选项所对应的接收
	CMultiDocTemplate *JIESHOU_FV_POINT_BD;
	CMultiDocTemplate *JIESHOU_FV_POINT_QR;
	CMultiDocTemplate *JIESHOU_FV_DATA_TTBDJG;
	CMultiDocTemplate *JIESHOU_FV_DATA_XTTXJG;
	CMultiDocTemplate *JIESHOU_FV_DATA_GZSJSJ;
	CMultiDocTemplate *JIESHOU_FV_DATA_CKLXJT;
	CMultiDocTemplate *	JIESHOU_FV_DATA_CDB;


public:

	int cewen_int;


	CMultiDocTemplate *JIESHOU_FV_CEWEN_WDCD;
	

// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void On32788();
	afx_msg void On32789();
	afx_msg void On32786();
	afx_msg void On32783();
	afx_msg void On32782();
	afx_msg void On32784();
	afx_msg void On32771();
	afx_msg void On32785();
	afx_msg void On32791();
	afx_msg void On32780();
	afx_msg void On32781();
	afx_msg void On32774();
	afx_msg void On32775();
	afx_msg void On32777();
	afx_msg void On32778();
	afx_msg void On32779();
	afx_msg void On32790();
	afx_msg void On32798();
	afx_msg void OnUpdate32771(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32774(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32775(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32780(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32781(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32782(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32783(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32784(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32785(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32786(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32787(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32788(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32789(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32790(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32777(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32778(CCmdUI *pCmdUI);
	afx_msg void OnUpdate32779(CCmdUI *pCmdUI);
};

extern Creyuan0518App theApp;
