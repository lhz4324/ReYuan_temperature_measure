#pragma once
#include "afxcmn.h"



// FV_DATA_GZSJSJ ������ͼ

class FV_DATA_GZSJSJ : public CFormView
{
	DECLARE_DYNCREATE(FV_DATA_GZSJSJ)

protected:
	FV_DATA_GZSJSJ();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~FV_DATA_GZSJSJ();

public:
	enum { IDD = IDD_DATA_GZSJSJ };
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
	CListCtrl DATA_GZSJSJ_list; //�������ݡ�����������ݵ��б�
public:
	virtual void OnInitialUpdate();//�����麯��
};


