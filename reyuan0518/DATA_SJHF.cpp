// DATA_SJHF.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "DATA_SJHF.h"
#include "afxdialogex.h"


// DATA_SJHF �Ի���

IMPLEMENT_DYNAMIC(DATA_SJHF, CDialogEx)

DATA_SJHF::DATA_SJHF(CWnd* pParent /*=NULL*/)
	: CDialogEx(DATA_SJHF::IDD, pParent)
{

}

DATA_SJHF::~DATA_SJHF()
{
}

void DATA_SJHF::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, SJHF_ml_control);
}


BEGIN_MESSAGE_MAP(DATA_SJHF, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &DATA_SJHF::OnBnClickedButton2)
END_MESSAGE_MAP()


// DATA_SJHF ��Ϣ�������


void DATA_SJHF::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CString m_strFilePath = _T("");

	//��ȡ�ļ�·����
	LPCTSTR szFilter = _T("TXT(*.txt)|*.txt|LOG(*.log)|*.log|ALLSUPORTFILE(*.*)|*.*||");

	CFileDialog dlgFileOpenImg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);
	//��txt�ļ�
	if (dlgFileOpenImg.DoModal() == IDOK)
	{
		//��ȡ�ļ���
		m_strFilePath = dlgFileOpenImg.GetPathName();

		SJHF_ml_control.SetWindowTextW(m_strFilePath);//��·������ʾ��Ŀ¼����(�˴�Ŀ¼�����·����

	}
	else
	{
		return;
	}
}
