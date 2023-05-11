// FV_DATA_CDB.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "FV_DATA_CDB.h"

#include "FV_DATA_CDBRYSYJG.h"
#include "FV_DATA_CDB_RIGHT.h"
// FV_DATA_CDB

IMPLEMENT_DYNCREATE(FV_DATA_CDB, CFormView)

FV_DATA_CDB::FV_DATA_CDB()
	: CFormView(FV_DATA_CDB::IDD)
{

}

FV_DATA_CDB::~FV_DATA_CDB()
{
}

void FV_DATA_CDB::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(FV_DATA_CDB, CFormView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// FV_DATA_CDB ���

#ifdef _DEBUG
void FV_DATA_CDB::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FV_DATA_CDB::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FV_DATA_CDB ��Ϣ�������


int FV_DATA_CDB::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	CString strMyClass = AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW,
		::LoadCursor(NULL, IDC_ARROW), (HBRUSH) ::GetStockObject(WHITE_BRUSH),
		::LoadIcon(NULL, IDI_APPLICATION));

	// Create the frame window with "this" as the parent
	m_pMyFrame = new CFrameWnd;
	m_pMyFrame->Create(strMyClass, _T(""), WS_CHILD, CRect(0, 0, 300, 300), this);
	m_pMyFrame->ShowWindow(SW_SHOW);

	// and finally, create the splitter with the frame as the parent
	m_cSplitter.CreateStatic(m_pMyFrame, 1, 2); //��Frame���з���ͼ����Ϊ1��2������һ������
	CCreateContext cc;
	m_cSplitter.CreateView(0, 0, RUNTIME_CLASS(FV_DATA_CDBRYSYJG), CSize(1000, 100), &cc);//��һ��һ��

	m_cSplitter.CreateView(0, 1, RUNTIME_CLASS(FV_DATA_CDB_RIGHT), CSize(100, 100), &cc);//��һ�ж���

	return 0;
}


void FV_DATA_CDB::OnDestroy()
{
	CFormView::OnDestroy();

	// TODO:  �ڴ˴������Ϣ����������
	if (m_pMyFrame) delete m_pMyFrame;
}


void FV_DATA_CDB::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
	CRect cRect;
	GetWindowRect(&cRect);
	ScreenToClient(&cRect);
	m_pMyFrame->MoveWindow(&cRect);
	m_pMyFrame->ShowWindow(SW_SHOW);
}
