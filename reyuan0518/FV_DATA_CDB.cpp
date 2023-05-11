// FV_DATA_CDB.cpp : 实现文件
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


// FV_DATA_CDB 诊断

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


// FV_DATA_CDB 消息处理程序


int FV_DATA_CDB::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	CString strMyClass = AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW,
		::LoadCursor(NULL, IDC_ARROW), (HBRUSH) ::GetStockObject(WHITE_BRUSH),
		::LoadIcon(NULL, IDI_APPLICATION));

	// Create the frame window with "this" as the parent
	m_pMyFrame = new CFrameWnd;
	m_pMyFrame->Create(strMyClass, _T(""), WS_CHILD, CRect(0, 0, 300, 300), this);
	m_pMyFrame->ShowWindow(SW_SHOW);

	// and finally, create the splitter with the frame as the parent
	m_cSplitter.CreateStatic(m_pMyFrame, 1, 2); //在Frame里切分视图窗口为1×2，就是一行两列
	CCreateContext cc;
	m_cSplitter.CreateView(0, 0, RUNTIME_CLASS(FV_DATA_CDBRYSYJG), CSize(1000, 100), &cc);//第一行一列

	m_cSplitter.CreateView(0, 1, RUNTIME_CLASS(FV_DATA_CDB_RIGHT), CSize(100, 100), &cc);//第一行二列

	return 0;
}


void FV_DATA_CDB::OnDestroy()
{
	CFormView::OnDestroy();

	// TODO:  在此处添加消息处理程序代码
	if (m_pMyFrame) delete m_pMyFrame;
}


void FV_DATA_CDB::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	CRect cRect;
	GetWindowRect(&cRect);
	ScreenToClient(&cRect);
	m_pMyFrame->MoveWindow(&cRect);
	m_pMyFrame->ShowWindow(SW_SHOW);
}
