#pragma once
#include "afxcmn.h"



// FV_DATA_TTBDJG ������ͼ

class FV_DATA_TTBDJG : public CFormView
{
	DECLARE_DYNCREATE(FV_DATA_TTBDJG)

protected:
	FV_DATA_TTBDJG();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~FV_DATA_TTBDJG();

public:
	enum { IDD = IDD_DATA_TTBDJG };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl DATA_TTBDJG_list;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
};


