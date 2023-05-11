// LOGIN.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "LOGIN.h"
#include "afxdialogex.h"
//#include "./mysql/mysql.h"


#include "LOGIN_SET.h"//���ð�ť��ͷ�ļ�
// LOGIN �Ի���

#include "instrument_self_check.h"

IMPLEMENT_DYNAMIC(LOGIN, CDialogEx)

LOGIN::LOGIN(CWnd* pParent /*=NULL*/)
	: CDialogEx(LOGIN::IDD, pParent)
	, username(_T(""))
	, password(_T(""))
{

}

LOGIN::~LOGIN()
{
}

void LOGIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, username);
	DDX_Text(pDX, IDC_EDIT2, password);
}


BEGIN_MESSAGE_MAP(LOGIN, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LOGIN::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &LOGIN::OnBnClickedButton2)
	ON_WM_CTLCOLOR()
	
END_MESSAGE_MAP()


// LOGIN ��Ϣ�������


void LOGIN::OnBnClickedButton1()//��¼
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������


	//if (û������) {
	//	MessageBox(TEXT("�豸δ���ӣ�����˿������豸��"));
	//}




	GetDlgItem(IDC_EDIT1)->GetWindowText(username);
	GetDlgItem(IDC_EDIT2)->GetWindowText(password);

	
	//const char user[] = "root";
	//const char pswd[] = "root";
	//const char host[] = "localhost";
	//const char databasename[] = "reyuan_mydatabase";
	//unsigned int port = 3306;



	if (username.IsEmpty()){
		MessageBox(TEXT("�û���Ϊ�գ�����������"));
		return;
	}
	if (password.IsEmpty()){
		MessageBox(TEXT("����Ϊ�գ�����������"));
		return;
	}
	
	
			
			int ress = mysql_query(&myonlydatabase.m_sqlCon, "select * from �û��˺�����");//���������
			if (!ress)
			{
				myonlydatabase.res = mysql_store_result(&myonlydatabase.m_sqlCon);
				if (myonlydatabase.res)
				{
					for (int i = 0; i < myonlydatabase.res->row_count; i++) {
						myonlydatabase.row = mysql_fetch_row(myonlydatabase.res);
						if (myonlydatabase.row[0] == username && myonlydatabase.row[1] == password)//�ȶ��Ƿ��û��������Ƿ�һ��
						{

							user_info_now.username_now = username; //����ʱ���˻����Ƹ�ֵ��ȫ�ֱ��� - username_now
							user_info_now.password_now = password;

							//�����˺Ŷ�Ӧ���û�Ȩ��ͬ��
							user_info_now.wdcd_now = atoi(myonlydatabase.row[6]);
							user_info_now.ypxxsz_now = atoi(myonlydatabase.row[7]);
							user_info_now.jlgssz_now = atoi(myonlydatabase.row[8]);
							user_info_now.ckttbdjg_now = atoi(myonlydatabase.row[9]);
							user_info_now.ckxttxjg_now = atoi(myonlydatabase.row[10]);
							user_info_now.cxdyryjg_now = atoi(myonlydatabase.row[11]);
							user_info_now.sjbf_now = atoi(myonlydatabase.row[12]);
							user_info_now.bdtt_now = atoi(myonlydatabase.row[13]);
							user_info_now.sdsscwqxsf_now = atoi(myonlydatabase.row[14]);
							user_info_now.gzsjsj_now = atoi(myonlydatabase.row[15]);
							user_info_now.sjgssz_now = atoi(myonlydatabase.row[16]);
							user_info_now.cklxjt_now = atoi(myonlydatabase.row[17]);
							user_info_now.sjwh_now = atoi(myonlydatabase.row[18]);
							user_info_now.zhgl_now = atoi(myonlydatabase.row[19]);


							mysql_free_result(myonlydatabase.res);
							

							if (current_computer_username_selected) {
								if (current_computer_username == username) {
									instrument_self_check window;
									window.DoModal();
									CDialogEx::OnOK();//�û�������һ�£��������
								}
								else
								{
									MessageBox(TEXT("��ǰ�����û����뱾���˻����Ʋ�һ�£����������룡"));
								}


							}
							else {
								instrument_self_check window;
								window.DoModal();

								CDialogEx::OnOK();//�û�������һ�£��������
							}

							break;
						}
						else
						{
							if (i == myonlydatabase.res->row_count - 1) {
								MessageBox(TEXT("�û��������벻��ȷ������������"));
								return;
							}
						}
					}
				}

			}

		
	


	
}


BOOL LOGIN::OnInitDialog()//��ʼʱ�����û�������
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	username = TEXT("lhz");	//�û���
	password = TEXT("123456");//����


	UpdateData(FALSE); //���ݸ��µ���Ӧ�Ŀؼ�



	if (!myonlydatabase.ConnectDB_orcreate())//�ж��Ƿ��������ݿ�ɹ�
	{
		AfxMessageBox(_T("���ݿ�����ʧ��!"));

	}



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void LOGIN::OnOK()//��д��¼����Ļس�
{
	// TODO:  �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void LOGIN::OnCancel()//��д��¼����Ĺرհ�ť
{
	// TODO:  �ڴ����ר�ô����/����û���


	//CDialogEx::OnCancel();
	exit(0);
}


void LOGIN::OnBnClickedButton2()//���ý���
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	LOGIN_SET set;
	set.DoModal();


}


HBRUSH LOGIN::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������

	if (pWnd->GetDlgCtrlID() == IDC_STATICMessage){
		pDC->SetTextColor(RGB(250, 0, 0));

	}
	return hbr;
}



