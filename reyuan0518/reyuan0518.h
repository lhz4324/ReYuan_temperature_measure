
// reyuan0518.h : reyuan0518 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Creyuan0518App:
// �йش����ʵ�֣������ reyuan0518.cpp
//

class Creyuan0518App : public CWinApp
{
public:
	Creyuan0518App();

public://�˵���ѡ������Ӧ�Ľ���
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
	

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
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
