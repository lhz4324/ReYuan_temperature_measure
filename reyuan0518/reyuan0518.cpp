
// reyuan0518.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "reyuan0518.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "reyuan0518Doc.h"
#include "reyuan0518View.h"

#include "LOGIN.h"//��¼����ͷ�ļ�


#include "FV_POINT_BD.h"//̽ͷ�궨ͷ�ļ�
#include "FV_POINT_QR.h"//̽ͷȷ��ͷ�ļ�


#include "FV_DATA_TTBDJG.h"//����_̽ͷ�궨���
#include "FV_DATA_XTTXJG.h"//�����Ӳ˵�_������ѡ���
#include "FV_DATA_GZSJSJ.h"//�����Ӳ˵�_�����������
#include "FV_DATA_CKLXJT.h"//�����Ӳ˵�_�鿴��ѡ����
#include "FV_DATA_CDB.h"//�����Ӳ˵�_��ѯ����ӡ�������Դʵ����
#include "DATA_SJBF.h"//�����Ӳ˵�_���ݱ���
#include "DATA_SJHF.h"//�����Ӳ˵�_���ݻָ�



#include "FV_CEWEN_WDCD.h"//����_�¶Ȳⶨ



#include "SET_YPXX.h"//��������_��Ʒ��Ϣ
#include "SET_SJGS.h"//��������_���ݸ�ʽ
#include "SET_JLGS_RY.h"//��������_��¼��ʽ_��Դ�����¼��ʽ
#include "SET_JLGS_XT.h"////��������_��¼��ʽ_������ѡ��¼��ʽ
#include "SET_JLGS_JT.h"////��������_��¼��ʽ_���÷����¼��ʽ


#include "ACCOUNT_GGMM.h"//�˻�_��������
#include "ACCOUNT_ZHGL.h"//�˻�_�˻�����


#include "SHITU_STSZ.h"//��ͼ_��ͼ����


#include "MyDatabase.h"
#include "Quanjv.h"//ʵ�ּ�¼��ǰ�˻��û���

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Creyuan0518App

BEGIN_MESSAGE_MAP(Creyuan0518App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &Creyuan0518App::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// ��׼��ӡ��������
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


// Creyuan0518App ����

Creyuan0518App::Creyuan0518App()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���: 
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO:  ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("reyuan0518.AppID.NoVersion"));

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� Creyuan0518App ����

Creyuan0518App theApp;


// Creyuan0518App ��ʼ��

BOOL Creyuan0518App::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);


	LOGIN dlg;	//������½�Ի�����Ҫͷ�ļ�#include "LoginDlg.h"
	dlg.DoModal();	//��ģ̬��ʽ����



	CWinApp::InitInstance();


	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO:  Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)








	// ע��Ӧ�ó�����ĵ�ģ�塣  �ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������


                        // ̽ͷ�궨����
                        JIESHOU_FV_POINT_BD = new CMultiDocTemplate(
                        	IDR_MAINFRAME,
                        	RUNTIME_CLASS(Creyuan0518Doc),
                        	RUNTIME_CLASS(CChildFrame),
                        	RUNTIME_CLASS(FV_POINT_BD)
                        	);//FV_POINT_BDΪ̽ͷ�궨��Ӧ�Ի�������
						
						// ̽ͷȷ�Ͻ���
						JIESHOU_FV_POINT_QR = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_POINT_QR)
							);

						//����_̽ͷ�궨�������
						JIESHOU_FV_DATA_TTBDJG = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_DATA_TTBDJG)
							);

						//�����Ӳ˵�_������ѡ���
						JIESHOU_FV_DATA_XTTXJG = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_DATA_XTTXJG)
							);

						//�����Ӳ˵�_�����������
						JIESHOU_FV_DATA_GZSJSJ = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_DATA_GZSJSJ)
							);


						//�����Ӳ˵�_�鿴��ѡ����
						JIESHOU_FV_DATA_CKLXJT = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_DATA_CKLXJT)
							);

						//�����Ӳ˵�_��ѯ����ӡ�������Դʵ����
						JIESHOU_FV_DATA_CDB = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_DATA_CDB)
							);



						//����_�¶Ȳⶨ
						JIESHOU_FV_CEWEN_WDCD = new CMultiDocTemplate(
							IDR_MAINFRAME,
							RUNTIME_CLASS(Creyuan0518Doc),
							RUNTIME_CLASS(CChildFrame),
							RUNTIME_CLASS(FV_CEWEN_WDCD)
							);




	// ������ MDI ��ܴ���
	CMainFrame* pMainFrame = new CMainFrame;

	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// ������׼ shell ���DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// ��������������ָ�������  ���
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// �������ѳ�ʼ���������ʾ����������и���
	
	
	//pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->ShowWindow(SW_SHOWMAXIMIZED);//���һ���������
	pMainFrame->UpdateWindow();




	return TRUE;
}

int Creyuan0518App::ExitInstance()
{
	//TODO:  �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// Creyuan0518App ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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

// �������жԻ����Ӧ�ó�������
void Creyuan0518App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// Creyuan0518App ��Ϣ�������





void Creyuan0518App::On32788()//̽ͷ_̽ͷ�궨formview����ģ̬
{
	// TODO:  �ڴ���������������

	CDocument*poc32788 = JIESHOU_FV_POINT_BD->OpenDocumentFile(NULL);
	
	poc32788->SetTitle(TEXT("̽ͷ�궨"));//���ñ���

}


void Creyuan0518App::On32789()//̽ͷ_̽ͷȷ��
{
	// TODO:  �ڴ���������������

	CDocument*poc32789 = JIESHOU_FV_POINT_QR->OpenDocumentFile(NULL);

	poc32789->SetTitle(TEXT("̽ͷȷ��"));//���ñ���

}


void Creyuan0518App::On32786()//����_̽ͷ�궨���
{
	// TODO:  �ڴ���������������

	CDocument*poc32786 = JIESHOU_FV_DATA_TTBDJG->OpenDocumentFile(NULL);
	poc32786->SetTitle(TEXT("̽ͷ�궨���"));//���ñ���
}


void Creyuan0518App::On32783()//�����Ӳ˵�_������ѡ���
{
	// TODO:  �ڴ���������������
	CDocument*poc32783 = JIESHOU_FV_DATA_XTTXJG->OpenDocumentFile(NULL);
	poc32783->SetTitle(TEXT("������ѡ���"));//���ñ���
}



void Creyuan0518App::On32782()//�����Ӳ˵�_�����������
{
	// TODO:  �ڴ���������������

	CDocument*poc32782 = JIESHOU_FV_DATA_GZSJSJ->OpenDocumentFile(NULL);
	poc32782->SetTitle(TEXT("�����������"));//���ñ���
}


void Creyuan0518App::On32784()//�����Ӳ˵�_�鿴��ѡ����
{
	// TODO:  �ڴ���������������

	
	CDocument*poc32784 = JIESHOU_FV_DATA_CKLXJT->OpenDocumentFile(NULL);
	poc32784->SetTitle(TEXT("�鿴��ѡ����"));//���ñ���
}


void Creyuan0518App::On32771()//����_�¶Ȳⶨ
{
	// TODO:  �ڴ���������������JIESHOU_FV_CEWEN_WDCD
    CDocument*poc32771 = JIESHOU_FV_CEWEN_WDCD->OpenDocumentFile(NULL);
    poc32771->SetTitle(TEXT("�¶Ȳⶨ"));//���ñ���
}


void Creyuan0518App::On32785()//�����Ӳ˵�_��ѯ����ӡ�������Դʵ����
{
	// TODO:  �ڴ���������������



	CDocument*poc32785 = JIESHOU_FV_DATA_CDB->OpenDocumentFile(NULL);
	poc32785->SetTitle(TEXT("��ѯ����ӡ�������Դʵ����"));//���ñ���
}


void Creyuan0518App::On32791()//�˻�_��������
{
	// TODO:  �ڴ���������������
	ACCOUNT_GGMM ggmm;
	ggmm.DoModal();
}


void Creyuan0518App::On32780()//���ݱ���
{
	// TODO:  �ڴ���������������

	DATA_SJBF sjbf;
	sjbf.DoModal();
}


void Creyuan0518App::On32781()//�����Ӳ˵�_���ݻָ�
{
	// TODO:  �ڴ���������������
	DATA_SJHF sjhf;
	sjhf.DoModal();
}


void Creyuan0518App::On32774()//��������_��Ʒ��Ϣ
{
	// TODO:  �ڴ���������������
	SET_YPXX ypxx;
	ypxx.DoModal();
}


void Creyuan0518App::On32775()//��������_���ݸ�ʽ
{
	// TODO:  �ڴ���������������
	SET_SJGS sjgs;
	sjgs.DoModal();

}


void Creyuan0518App::On32777()//��������_��¼��ʽ_��Դ�����¼��ʽ
{
	// TODO:  �ڴ���������������

	SET_JLGS_RY jlgsry;
	jlgsry.DoModal();
}


void Creyuan0518App::On32778()
{
	// TODO:  �ڴ���������������

	SET_JLGS_XT jlgsxt;
	jlgsxt.DoModal();
}


void Creyuan0518App::On32779()//��������_��¼��ʽ_���÷����¼��ʽ
{
	// TODO:  �ڴ���������������

	SET_JLGS_JT jlgsjt;
	jlgsjt.DoModal();
}


void Creyuan0518App::On32790()//�˻�_�˻�����
{
	// TODO:  �ڴ���������������
	ACCOUNT_ZHGL zhgl;
	zhgl.DoModal();
}


void Creyuan0518App::On32798()//��ͼ_��ͼ����
{
	// TODO:  �ڴ���������������

	SHITU_STSZ stsz;
	stsz.DoModal();

}


void Creyuan0518App::OnUpdate32771(CCmdUI *pCmdUI)//���Ʋ��°�ť�Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������

	pCmdUI->Enable(user_info_now.wdcd_now);
}


void Creyuan0518App::OnUpdate32774(CCmdUI *pCmdUI)//��������_��Ʒ��Ϣ�Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.ypxxsz_now);
}


void Creyuan0518App::OnUpdate32775(CCmdUI *pCmdUI)//��������_���ݸ�ʽ�Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.sjgssz_now);
}


void Creyuan0518App::OnUpdate32780(CCmdUI *pCmdUI)//���ݱ����Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.sjbf_now);

}


void Creyuan0518App::OnUpdate32781(CCmdUI *pCmdUI)//�����Ӳ˵�_���ݻָ��Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.sjbf_now);
}



void Creyuan0518App::OnUpdate32782(CCmdUI *pCmdUI)//�����Ӳ˵�_������������Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.gzsjsj_now);
}


void Creyuan0518App::OnUpdate32783(CCmdUI *pCmdUI)//�����Ӳ˵�_������ѡ����Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.ckxttxjg_now);
}


void Creyuan0518App::OnUpdate32784(CCmdUI *pCmdUI)//�����Ӳ˵�_�鿴��ѡ�����Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.cklxjt_now);
}


void Creyuan0518App::OnUpdate32785(CCmdUI *pCmdUI)//�����Ӳ˵�_��ѯ����ӡ�������Դʵ�����Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.cxdyryjg_now);
}


void Creyuan0518App::OnUpdate32786(CCmdUI *pCmdUI)//����_̽ͷ�궨���
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.ckttbdjg_now);
}


void Creyuan0518App::OnUpdate32787(CCmdUI *pCmdUI)//����_̽ͷȷ�Ͻ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.ckttbdjg_now);
}


void Creyuan0518App::OnUpdate32788(CCmdUI *pCmdUI)//̽ͷ_̽ͷ�궨  �Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.bdtt_now);
}



void Creyuan0518App::OnUpdate32789(CCmdUI *pCmdUI)//̽ͷ_̽ͷȷ��  �Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.bdtt_now);
}


void Creyuan0518App::OnUpdate32790(CCmdUI *pCmdUI)//�˻�_�˻����� �Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.zhgl_now);
}


void Creyuan0518App::OnUpdate32777(CCmdUI *pCmdUI)//��������_��¼��ʽ_��Դ�����¼��ʽ �Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.jlgssz_now);
}


void Creyuan0518App::OnUpdate32778(CCmdUI *pCmdUI)//��������_��¼��ʽ_������ѡ��¼��ʽ �Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.jlgssz_now);
}


void Creyuan0518App::OnUpdate32779(CCmdUI *pCmdUI)//��������_��¼��ʽ_���÷����¼��ʽ �Ƿ��ѡ��
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable(user_info_now.jlgssz_now);
}

 