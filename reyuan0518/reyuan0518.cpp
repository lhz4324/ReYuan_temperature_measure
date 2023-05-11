
// reyuan0518.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "reyuan0518.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "reyuan0518Doc.h"
#include "reyuan0518View.h"

#include "LOGIN.h"//登录窗口头文件


#include "FV_POINT_BD.h"//探头标定头文件
#include "FV_POINT_QR.h"//探头确认头文件


#include "FV_DATA_TTBDJG.h"//数据_探头标定结果
#include "FV_DATA_XTTXJG.h"//数据子菜单_新兔挑选结果
#include "FV_DATA_GZSJSJ.h"//数据子菜单_跟踪审计数据
#include "FV_DATA_CKLXJT.h"//数据子菜单_查看落选家兔
#include "FV_DATA_CDB.h"//数据子菜单_查询、打印与编正热源实验结果
#include "DATA_SJBF.h"//数据子菜单_数据备份
#include "DATA_SJHF.h"//数据子菜单_数据恢复



#include "FV_CEWEN_WDCD.h"//测温_温度测定



#include "SET_YPXX.h"//包含设置_样品信息
#include "SET_SJGS.h"//包含设置_数据格式
#include "SET_JLGS_RY.h"//包含设置_记录格式_热源试验记录格式
#include "SET_JLGS_XT.h"////包含设置_记录格式_新兔挑选记录格式
#include "SET_JLGS_JT.h"////包含设置_记录格式_家兔分组记录格式


#include "ACCOUNT_GGMM.h"//账户_更改密码
#include "ACCOUNT_ZHGL.h"//账户_账户管理


#include "SHITU_STSZ.h"//视图_视图设置


#include "MyDatabase.h"
#include "Quanjv.h"//实现记录当前账户用户名

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Creyuan0518App

BEGIN_MESSAGE_MAP(Creyuan0518App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &Creyuan0518App::OnAppAbout)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_32788, &Creyuan0518App::On32788)
	ON_COMMAND(ID_32789, &Creyuan0518App::On32789)
	ON_COMMAND(ID_32786, &Creyuan0518App::On32786)
	ON_COMMAND(ID_32783, &Creyuan0518App::On32783)
	ON_COMMAND(ID_32782, &Creyuan0518App::On32782)
	ON_COMMAND(ID_32784, &Creyuan0518App::On32784)
	ON_COMMAND(ID_32771, &Creyuan0518App::On32771)
	ON_COMMAND(ID_32785, &Creyuan0518App::On32785)
	ON_COMMAND(ID_32791, &Creyuan0518App::On32791)
	ON_COMMAND(ID_32780, &Creyuan0518App::On32780)
	ON_COMMAND(ID_32781, &Creyuan0518App::On32781)
	ON_COMMAND(ID_32774, &Creyuan0518App::On32774)
	ON_COMMAND(ID_32775, &Creyuan0518App::On32775)
	ON_COMMAND(ID_32777, &Creyuan0518App::On32777)
	ON_COMMAND(ID_32778, &Creyuan0518App::On32778)
	ON_COMMAND(ID_32779, &Creyuan0518App::On32779)
	ON_COMMAND(ID_32790, &Creyuan0518App::On32790)
	ON_COMMAND(ID_32798, &Creyuan0518App::On32798)
	ON_UPDATE_COMMAND_UI(ID_32771, &Creyuan0518App::OnUpdate32771)
	ON_UPDATE_COMMAND_UI(ID_32774, &Creyuan0518App::OnUpdate32774)
	ON_UPDATE_COMMAND_UI(ID_32775, &Creyuan0518App::OnUpdate32775)
	ON_UPDATE_COMMAND_UI(ID_32780, &Creyuan0518App::OnUpdate32780)
	ON_UPDATE_COMMAND_UI(ID_32781, &Creyuan0518App::OnUpdate32781)
	ON_UPDATE_COMMAND_UI(ID_32782, &Creyuan0518App::OnUpdate32782)
	ON_UPDATE_COMMAND_UI(ID_32783, &Creyuan0518App::OnUpdate32783)
	ON_UPDATE_COMMAND_UI(ID_32784, &Creyuan0518App::OnUpdate32784)
	ON_UPDATE_COMMAND_UI(ID_32785, &Creyuan0518App::OnUpdate32785)
	ON_UPDATE_COMMAND_UI(ID_32786, &Creyuan0518App::OnUpdate32786)
	ON_UPDATE_COMMAND_UI(ID_32787, &Creyuan0518App::OnUpdate32787)
	ON_UPDATE_COMMAND_UI(ID_32788, &Creyuan0518App::OnUpdate32788)
	ON_UPDATE_COMMAND_UI(ID_32789, &Creyuan0518App::OnUpdate32789)
	ON_UPDATE_COMMAND_UI(ID_32790, &Creyuan0518App::OnUpdate32790)
	ON_UPDATE_COMMAND_UI(ID_32777, &Creyuan0518App::OnUpdate32777)
	ON_UPDATE_COMMAND_UI(ID_32778, &Creyuan0518App::OnUpdate32778)
	ON_UPDATE_COMMAND_UI(ID_32779, &Creyuan0518App::OnUpdate32779)
END_MESSAGE_MAP()


// Creyuan0518App 构造

Creyuan0518App::Creyuan0518App()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// 如果应用程序是利用公共语言运行时支持(/clr)构建的，则: 
	//     1) 必须有此附加设置，“重新启动管理器”支持才能正常工作。
	//     2) 在您的项目中，您必须按照生成顺序向 System.Windows.Forms 添加引用。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO:  将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("reyuan0518.AppID.NoVersion"));

	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 Creyuan0518App 对象

Creyuan0518App theApp;


// Creyuan0518App 初始化

BOOL Creyuan0518App::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);


	LOGIN dlg;	//创建登陆对话框，需要头文件#include "LoginDlg.h"
	dlg.DoModal();	//以模态方式运行



	CWinApp::InitInstance();


	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// 使用 RichEdit 控件需要  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO:  应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)








	// 注册应用程序的文档模板。  文档模板
	// 将用作文档、框架窗口和视图之间的连接


                        // 探头标定接收
                        JIESHOU_FV_POINT_BD = new CMultiDocTemplate(
                        	IDR_MAINFRAME,
                        	RUNTIME_CLASS(Creyuan0518Doc),
                        	RUNTIME_CLASS(CChildFrame),
                        	RUNTIME_CLASS(FV_POINT_BD)
                        	);//FV_POINT_BD为探头标定对应对话框类名
						
						// 探头确认接收
						JIESHOU_FV_POINT_QR = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_POINT_QR)
							);

						//数据_探头标定结果接收
						JIESHOU_FV_DATA_TTBDJG = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_DATA_TTBDJG)
							);

						//数据子菜单_新兔挑选结果
						JIESHOU_FV_DATA_XTTXJG = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_DATA_XTTXJG)
							);

						//数据子菜单_跟踪审计数据
						JIESHOU_FV_DATA_GZSJSJ = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_DATA_GZSJSJ)
							);


						//数据子菜单_查看落选家兔
						JIESHOU_FV_DATA_CKLXJT = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_DATA_CKLXJT)
							);

						//数据子菜单_查询、打印与编正热源实验结果
						JIESHOU_FV_DATA_CDB = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_DATA_CDB)
							);



						//测温_温度测定
						JIESHOU_FV_CEWEN_WDCD = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_CEWEN_WDCD)
							);




	// 创建主 MDI 框架窗口
	CMainFrame* pMainFrame = new CMainFrame;

	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// 分析标准 shell 命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// 调度在命令行中指定的命令。  如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// 主窗口已初始化，因此显示它并对其进行更新
	
	
	//pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->ShowWindow(SW_SHOWMAXIMIZED);//框架一启动就最大化
	pMainFrame->UpdateWindow();




	return TRUE;
}

int Creyuan0518App::ExitInstance()
{
	//TODO:  处理可能已添加的附加资源
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// Creyuan0518App 消息处理程序


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void Creyuan0518App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Creyuan0518App 消息处理程序





void Creyuan0518App::On32788()//探头_探头标定formview，非模态
{
	// TODO:  在此添加命令处理程序代码

	CDocument*poc32788 = JIESHOU_FV_POINT_BD->OpenDocumentFile(NULL);
	
	poc32788->SetTitle(TEXT("探头标定"));//设置标题

}


void Creyuan0518App::On32789()//探头_探头确认
{
	// TODO:  在此添加命令处理程序代码

	CDocument*poc32789 = JIESHOU_FV_POINT_QR->OpenDocumentFile(NULL);

	poc32789->SetTitle(TEXT("探头确认"));//设置标题

}


void Creyuan0518App::On32786()//数据_探头标定结果
{
	// TODO:  在此添加命令处理程序代码

	CDocument*poc32786 = JIESHOU_FV_DATA_TTBDJG->OpenDocumentFile(NULL);
	poc32786->SetTitle(TEXT("探头标定结果"));//设置标题
}


void Creyuan0518App::On32783()//数据子菜单_新兔挑选结果
{
	// TODO:  在此添加命令处理程序代码
	CDocument*poc32783 = JIESHOU_FV_DATA_XTTXJG->OpenDocumentFile(NULL);
	poc32783->SetTitle(TEXT("新兔挑选结果"));//设置标题
}



void Creyuan0518App::On32782()//数据子菜单_跟踪审计数据
{
	// TODO:  在此添加命令处理程序代码

	CDocument*poc32782 = JIESHOU_FV_DATA_GZSJSJ->OpenDocumentFile(NULL);
	poc32782->SetTitle(TEXT("跟踪审计数据"));//设置标题
}


void Creyuan0518App::On32784()//数据子菜单_查看落选家兔
{
	// TODO:  在此添加命令处理程序代码

	
	CDocument*poc32784 = JIESHOU_FV_DATA_CKLXJT->OpenDocumentFile(NULL);
	poc32784->SetTitle(TEXT("查看落选家兔"));//设置标题
}


void Creyuan0518App::On32771()//测温_温度测定
{
	// TODO:  在此添加命令处理程序代码JIESHOU_FV_CEWEN_WDCD
    CDocument*poc32771 = JIESHOU_FV_CEWEN_WDCD->OpenDocumentFile(NULL);
    poc32771->SetTitle(TEXT("温度测定"));//设置标题
}


void Creyuan0518App::On32785()//数据子菜单_查询、打印与编正热源实验结果
{
	// TODO:  在此添加命令处理程序代码



	CDocument*poc32785 = JIESHOU_FV_DATA_CDB->OpenDocumentFile(NULL);
	poc32785->SetTitle(TEXT("查询、打印与编正热源实验结果"));//设置标题
}


void Creyuan0518App::On32791()//账户_更改密码
{
	// TODO:  在此添加命令处理程序代码
	ACCOUNT_GGMM ggmm;
	ggmm.DoModal();
}


void Creyuan0518App::On32780()//数据备份
{
	// TODO:  在此添加命令处理程序代码

	DATA_SJBF sjbf;
	sjbf.DoModal();
}


void Creyuan0518App::On32781()//数据子菜单_数据恢复
{
	// TODO:  在此添加命令处理程序代码
	DATA_SJHF sjhf;
	sjhf.DoModal();
}


void Creyuan0518App::On32774()//包含设置_样品信息
{
	// TODO:  在此添加命令处理程序代码
	SET_YPXX ypxx;
	ypxx.DoModal();
}


void Creyuan0518App::On32775()//包含设置_数据格式
{
	// TODO:  在此添加命令处理程序代码
	SET_SJGS sjgs;
	sjgs.DoModal();

}


void Creyuan0518App::On32777()//包含设置_记录格式_热源试验记录格式
{
	// TODO:  在此添加命令处理程序代码

	SET_JLGS_RY jlgsry;
	jlgsry.DoModal();
}


void Creyuan0518App::On32778()
{
	// TODO:  在此添加命令处理程序代码

	SET_JLGS_XT jlgsxt;
	jlgsxt.DoModal();
}


void Creyuan0518App::On32779()//包含设置_记录格式_家兔分组记录格式
{
	// TODO:  在此添加命令处理程序代码

	SET_JLGS_JT jlgsjt;
	jlgsjt.DoModal();
}


void Creyuan0518App::On32790()//账户_账户管理
{
	// TODO:  在此添加命令处理程序代码
	ACCOUNT_ZHGL zhgl;
	zhgl.DoModal();
}


void Creyuan0518App::On32798()//视图_视图设置
{
	// TODO:  在此添加命令处理程序代码

	SHITU_STSZ stsz;
	stsz.DoModal();

}


void Creyuan0518App::OnUpdate32771(CCmdUI *pCmdUI)//控制测温按钮是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码

	pCmdUI->Enable(user_info_now.wdcd_now);
}


void Creyuan0518App::OnUpdate32774(CCmdUI *pCmdUI)//包含设置_样品信息是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.ypxxsz_now);
}


void Creyuan0518App::OnUpdate32775(CCmdUI *pCmdUI)//包含设置_数据格式是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.sjgssz_now);
}


void Creyuan0518App::OnUpdate32780(CCmdUI *pCmdUI)//数据备份是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.sjbf_now);

}


void Creyuan0518App::OnUpdate32781(CCmdUI *pCmdUI)//数据子菜单_数据恢复是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.sjbf_now);
}



void Creyuan0518App::OnUpdate32782(CCmdUI *pCmdUI)//数据子菜单_跟踪审计数据是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.gzsjsj_now);
}


void Creyuan0518App::OnUpdate32783(CCmdUI *pCmdUI)//数据子菜单_新兔挑选结果是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.ckxttxjg_now);
}


void Creyuan0518App::OnUpdate32784(CCmdUI *pCmdUI)//数据子菜单_查看落选家兔是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.cklxjt_now);
}


void Creyuan0518App::OnUpdate32785(CCmdUI *pCmdUI)//数据子菜单_查询、打印与编正热源实验结果是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.cxdyryjg_now);
}


void Creyuan0518App::OnUpdate32786(CCmdUI *pCmdUI)//数据_探头标定结果
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.ckttbdjg_now);
}


void Creyuan0518App::OnUpdate32787(CCmdUI *pCmdUI)//数据_探头确认结果
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.ckttbdjg_now);
}


void Creyuan0518App::OnUpdate32788(CCmdUI *pCmdUI)//探头_探头标定  是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.bdtt_now);
}



void Creyuan0518App::OnUpdate32789(CCmdUI *pCmdUI)//探头_探头确认  是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.bdtt_now);
}


void Creyuan0518App::OnUpdate32790(CCmdUI *pCmdUI)//账户_账户管理 是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.zhgl_now);
}


void Creyuan0518App::OnUpdate32777(CCmdUI *pCmdUI)//包含设置_记录格式_热源试验记录格式 是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.jlgssz_now);
}


void Creyuan0518App::OnUpdate32778(CCmdUI *pCmdUI)//包含设置_记录格式_新兔挑选记录格式 是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.jlgssz_now);
}


void Creyuan0518App::OnUpdate32779(CCmdUI *pCmdUI)//包含设置_记录格式_家兔分组记录格式 是否可选中
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(user_info_now.jlgssz_now);
}

 