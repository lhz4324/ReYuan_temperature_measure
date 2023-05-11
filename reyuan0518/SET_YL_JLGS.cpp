// SET_YL_JLGS.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "SET_YL_JLGS.h"
#include "afxdialogex.h"


#include "SET_YL_JLGS_LEFT.h"
#include "SET_YL_JLGS_RIGHT.h"

#include "Quanjv.h"
// SET_YL_JLGS �Ի���

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


// SET_YL_JLGS ��Ϣ�������


int SET_YL_JLGS::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
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

	//CCreateContext cc;
	m_cSplitter.CreateView(0, 0, RUNTIME_CLASS(SET_YL_JLGS_LEFT), CSize(500, 100), NULL);//��һ��һ��

	m_cSplitter.CreateView(0, 1, RUNTIME_CLASS(SET_YL_JLGS_RIGHT), CSize(100, 100), NULL);//��һ�ж���

	return 0;
}


void SET_YL_JLGS::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO:  �ڴ˴������Ϣ����������
	if (m_pMyFrame) delete m_pMyFrame;
}


void SET_YL_JLGS::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
	CRect cRect;
	GetWindowRect(&cRect);
	ScreenToClient(&cRect);
	m_pMyFrame->MoveWindow(&cRect);
	m_pMyFrame->ShowWindow(SW_SHOW);

}


BOOL SET_YL_JLGS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��



	ShowWindow(SW_MAXIMIZE);//�Ի���Ĭ����󻯵���

	this->SetWindowText(title);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
