// FV_DATA_GZSJSJ.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "FV_DATA_GZSJSJ.h"


// FV_DATA_GZSJSJ

IMPLEMENT_DYNCREATE(FV_DATA_GZSJSJ, CFormView)

FV_DATA_GZSJSJ::FV_DATA_GZSJSJ()
	: CFormView(FV_DATA_GZSJSJ::IDD)
{

}

FV_DATA_GZSJSJ::~FV_DATA_GZSJSJ()
{
}

void FV_DATA_GZSJSJ::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, DATA_GZSJSJ_list);
}

BEGIN_MESSAGE_MAP(FV_DATA_GZSJSJ, CFormView)
END_MESSAGE_MAP()


// FV_DATA_GZSJSJ ���

#ifdef _DEBUG
void FV_DATA_GZSJSJ::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FV_DATA_GZSJSJ::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FV_DATA_GZSJSJ ��Ϣ�������


void FV_DATA_GZSJSJ::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
	DATA_GZSJSJ_list.SetExtendedStyle(DATA_GZSJSJ_list.GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);//�������ݡ�����������ݵ��б�

	CString head[] = { TEXT("����"), TEXT("�˻�"), TEXT("Ȩ�޵ȼ�"), TEXT("��ɫ"), TEXT("����"), TEXT("ԭ��") };//�������ݡ�����������ݵ��б�
	DATA_GZSJSJ_list.InsertColumn(0, head[0], LVCFMT_LEFT, 100);
	DATA_GZSJSJ_list.InsertColumn(1, head[1], LVCFMT_LEFT, 100);
	DATA_GZSJSJ_list.InsertColumn(2, head[2], LVCFMT_LEFT, 100);
	DATA_GZSJSJ_list.InsertColumn(3, head[3], LVCFMT_LEFT, 100);
	DATA_GZSJSJ_list.InsertColumn(4, head[4], LVCFMT_LEFT, 100);
	DATA_GZSJSJ_list.InsertColumn(5, head[5], LVCFMT_LEFT, 100);
}
