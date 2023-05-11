// DATA_SJBF.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "DATA_SJBF.h"
#include "afxdialogex.h"


// DATA_SJBF �Ի���

IMPLEMENT_DYNAMIC(DATA_SJBF, CDialogEx)

DATA_SJBF::DATA_SJBF(CWnd* pParent /*=NULL*/)
	: CDialogEx(DATA_SJBF::IDD, pParent)
	, SJBF_ml_cstring(_T(""))
{

}

DATA_SJBF::~DATA_SJBF()
{
}

void DATA_SJBF::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, SJBF_ml_control);
	DDX_Text(pDX, IDC_EDIT2, SJBF_ml_cstring);
}


BEGIN_MESSAGE_MAP(DATA_SJBF, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &DATA_SJBF::OnBnClickedButton2)
END_MESSAGE_MAP()


// DATA_SJBF ��Ϣ�������


void DATA_SJBF::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	/*��һ�δ����ǻ�ȡ�ļ�·��
	CString m_strFilePath = _T("");
	
	   //��ȡ�ļ�·����
	 LPCTSTR szFilter = _T("TXT(*.txt)|*.txt|LOG(*.log)|*.log|ALLSUPORTFILE(*.*)|*.*||");

	 CFileDialog dlgFileOpenImg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);
	//��txt�ļ�
	    if (dlgFileOpenImg.DoModal() == IDOK)
	    {
	        //��ȡ�ļ���
	      m_strFilePath = dlgFileOpenImg.GetPathName();

		  SJBF_ml_control.SetWindowTextW(m_strFilePath);//��·������ʾ��Ŀ¼����(�˴�Ŀ¼�����·����
		  
	    }
	else
	    {
	        return;
	    }
		*/


	//���ǻ�ȡ�ļ���·��
		CString m_saveFilePath;
		//���ļ�����ȡ�ļ�·����
		TCHAR szPath[_MAX_PATH];
		BROWSEINFO bi;
		bi.hwndOwner = GetSafeHwnd();
		bi.pidlRoot = NULL;
		bi.lpszTitle = _T("��ѡ�񱸷�·��");
		bi.pszDisplayName = szPath;
		bi.ulFlags = BIF_RETURNONLYFSDIRS;
		bi.lpfn = NULL;
		bi.lParam = NULL;

		LPITEMIDLIST pItemIDList = SHBrowseForFolder(&bi);

		if (pItemIDList)
		{
			if (SHGetPathFromIDList(pItemIDList, szPath))
			{
				m_saveFilePath = szPath;
				m_saveFilePath = m_saveFilePath + _T("\\");

				SJBF_ml_control.SetWindowTextW(m_saveFilePath);//��·������ʾ��Ŀ¼����(�˴�Ŀ¼�����·����
			}

			//use IMalloc interface for avoiding memory leak  
			IMalloc* pMalloc;
			if (SHGetMalloc(&pMalloc) != NOERROR)
			{
				TRACE(_T("Can't get the IMalloc interface\n"));
			}


			pMalloc->Free(pItemIDList);
			if (pMalloc)
				pMalloc->Release();

			
			//UpdateData(FALSE);
		}

}
