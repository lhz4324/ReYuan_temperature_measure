#pragma once
#include "afxcmn.h"



// FV_DATA_CKLXJT ������ͼ

class FV_DATA_CKLXJT : public CFormView
{
	DECLARE_DYNCREATE(FV_DATA_CKLXJT)

protected:
	FV_DATA_CKLXJT();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~FV_DATA_CKLXJT();

public:
	enum { IDD = IDD_DATA_CKLXJT };
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
	CListCtrl DATA_CKLXJT_list1;
	CListCtrl DATA_CKLXJT_list2;
public:
	virtual void OnInitialUpdate();
};


