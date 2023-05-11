// DATA_SJBF.cpp : 实现文件
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "DATA_SJBF.h"
#include "afxdialogex.h"


// DATA_SJBF 对话框

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


// DATA_SJBF 消息处理程序


void DATA_SJBF::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码

	/*这一段代码是获取文件路径
	CString m_strFilePath = _T("");
	
	   //获取文件路径名
	 LPCTSTR szFilter = _T("TXT(*.txt)|*.txt|LOG(*.log)|*.log|ALLSUPORTFILE(*.*)|*.*||");

	 CFileDialog dlgFileOpenImg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);
	//打开txt文件
	    if (dlgFileOpenImg.DoModal() == IDOK)
	    {
	        //读取文件名
	      m_strFilePath = dlgFileOpenImg.GetPathName();

		  SJBF_ml_control.SetWindowTextW(m_strFilePath);//将路径名显示在目录框中(此处目录框就是路径）
		  
	    }
	else
	    {
	        return;
	    }
		*/


	//这是获取文件夹路径
		CString m_saveFilePath;
		//打开文件，获取文件路径名
		TCHAR szPath[_MAX_PATH];
		BROWSEINFO bi;
		bi.hwndOwner = GetSafeHwnd();
		bi.pidlRoot = NULL;
		bi.lpszTitle = _T("请选择备份路径");
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

				SJBF_ml_control.SetWindowTextW(m_saveFilePath);//将路径名显示在目录框中(此处目录框就是路径）
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
