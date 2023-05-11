// SET_YL_JLGS.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "SET_YL_JLGS.h"
#include "afxdialogex.h"


#include "SET_YL_JLGS_LEFT.h"
#include "SET_YL_JLGS_RIGHT.h"

#include "Quanjv.h"
// SET_YL_JLGS 对话框

IMPLEMENT_DYNAMIC(SET_YL_JLGS, CDialogEx)

SET_YL_JLGS::SET_YL_JLGS(CWnd* pParent /*=NULL*/)
	: CDialogEx(SET_YL_JLGS::IDD, pParent)
{

}

SET_YL_JLGS::~SET_YL_JLGS()
{
}

void SET_YL_JLGS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SET_YL_JLGS, CDialogEx)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// SET_YL_JLGS 消息处理程序


int SET_YL_JLGS::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
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

	//CCreateContext cc;
	m_cSplitter.CreateView(0, 0, RUNTIME_CLASS(SET_YL_JLGS_LEFT), CSize(500, 100), NULL);//第一行一列

	m_cSplitter.CreateView(0, 1, RUNTIME_CLASS(SET_YL_JLGS_RIGHT), CSize(100, 100), NULL);//第一行二列

	return 0;
}


void SET_YL_JLGS::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO:  在此处添加消息处理程序代码
	if (m_pMyFrame) delete m_pMyFrame;
}


void SET_YL_JLGS::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	CRect cRect;
	GetWindowRect(&cRect);
	ScreenToClient(&cRect);
	m_pMyFrame->MoveWindow(&cRect);
	m_pMyFrame->ShowWindow(SW_SHOW);

}


BOOL SET_YL_JLGS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化



	ShowWindow(SW_MAXIMIZE);//对话框默认最大化弹出

	this->SetWindowText(title);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
