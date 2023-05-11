// Tab_CEWEN_WDCD_SYPC.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "Tab_CEWEN_WDCD_SYPC.h"
#include "afxdialogex.h"

#include "Quanjv.h"

#include "SYPC_XZGSP.h"

// Tab_CEWEN_WDCD_SYPC �Ի���

IMPLEMENT_DYNAMIC(Tab_CEWEN_WDCD_SYPC, CDialogEx)

Tab_CEWEN_WDCD_SYPC::Tab_CEWEN_WDCD_SYPC(CWnd* pParent /*=NULL*/)
	: CDialogEx(Tab_CEWEN_WDCD_SYPC::IDD, pParent)
	, TTH_cstring(_T(""))
	, TH_cstring(_T(""))
	, TZ_cstring(_T(""))
	, SYFF_cstring(_T(""))
{

}

Tab_CEWEN_WDCD_SYPC::~Tab_CEWEN_WDCD_SYPC()
{
}

void Tab_CEWEN_WDCD_SYPC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, TTH_cstring);
	DDX_Control(pDX, IDC_EDIT1, TTH_control);
	DDX_Control(pDX, IDC_COMBO1, SYFF_combobox_control);
	DDX_Text(pDX, IDC_EDIT3, TH_cstring);
	DDX_Text(pDX, IDC_EDIT5, TZ_cstring);
	DDX_Control(pDX, IDC_EDIT3, TH_control);
	DDX_Control(pDX, IDC_EDIT5, TZ_control);
	DDX_CBString(pDX, IDC_COMBO1, SYFF_cstring);
	DDX_Control(pDX, IDC_LIST2, m_ListCtrl);
}


BEGIN_MESSAGE_MAP(Tab_CEWEN_WDCD_SYPC, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Tab_CEWEN_WDCD_SYPC::OnBnClickedButton1)
	
	ON_BN_CLICKED(IDC_BUTTON4, &Tab_CEWEN_WDCD_SYPC::OnBnClickedButton4)

	ON_MESSAGE(WM_USER_BUTTON_CLICKED, OnListCtrlButtonClicked)

	ON_WM_SIZE()
	ON_WM_MOUSEWHEEL()
	ON_WM_NCCALCSIZE()
	ON_WM_KILLFOCUS()

	ON_NOTIFY(NM_CLICK, IDC_LIST2, &Tab_CEWEN_WDCD_SYPC::OnNMClickList2)
	ON_WM_TIMER()
	ON_CBN_SELCHANGE(IDC_COMBO1, &Tab_CEWEN_WDCD_SYPC::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON5, &Tab_CEWEN_WDCD_SYPC::OnBnClickedButton5)


	ON_MESSAGE(WM_CHILDFRAMEDBCLK, OnChlidFrameDBClick)
END_MESSAGE_MAP()


// Tab_CEWEN_WDCD_SYPC ��Ϣ�������


UINT XferLoop1(LPVOID params) {

	OVERLAPPED outOvLap, inOvLap;

	Tab_CEWEN_WDCD_SYPC *dlg = (Tab_CEWEN_WDCD_SYPC *)params;


	char s[1024];						ZeroMemory(s, 1024);

	LONG xfer = 1024;
	PUCHAR data = new UCHAR[xfer];	ZeroMemory(data, xfer);
	PUCHAR inData = new UCHAR[xfer];	ZeroMemory(inData, xfer);

	outOvLap.hEvent = CreateEvent(NULL, false, false, TEXT("CYUSB_OUT"));
	inOvLap.hEvent = CreateEvent(NULL, false, false, TEXT("CYUSB_IN"));



	bool success;
	LONG nSuccess = 0;
	LONG nFailure = 0;


	dlg->OutEndpt->TimeOut = 2000;
	dlg->InEndpt->TimeOut = 2000;

	//dlg->SetDlgItemText(IDC_EDIT1, TEXT(""));

	for (; dlg->bLooping;) {
		LONG outlen, inlen, len;

		outlen = inlen = len = xfer;     // Use temp var because XferData can change the value of len
		data[0] = 0xeb;
		data[1] = 0x90;
		outlen = 2;
		//UCHAR  *outContext = dlg->OutEndpt->BeginDataXfer(data, outlen, &outOvLap);
		UCHAR  *outContext = dlg->OutEndpt->BeginDataXfer(data, outlen, &outOvLap);
		UCHAR  *inContext = dlg->InEndpt->BeginDataXfer(inData, inlen, &inOvLap);

		dlg->OutEndpt->WaitForXfer(&outOvLap, 2000);
		dlg->InEndpt->WaitForXfer(&inOvLap, 2000);

		success = dlg->OutEndpt->FinishDataXfer(data, outlen, &outOvLap, outContext);
		success = dlg->InEndpt->FinishDataXfer(inData, inlen, &inOvLap, inContext);


		if (inlen > 0) {


			for (int i = 0; i < PointNum; i++) {
				
				if (point_ifstart_now[i].ifstart == 1) {
					
					point_ifstart_now[i].t_real = point_temperature_now[i].a + point_temperature_now[i].b * inData[Protocol[i]];


				}
			}

			

		}
		Sleep(1);
	}

	CloseHandle(outOvLap.hEvent);
	CloseHandle(inOvLap.hEvent);

	delete[] data;
	delete[] inData;


	dlg->XferThread = NULL;


	return true;
}


BOOL Tab_CEWEN_WDCD_SYPC::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��


	
	my_wnd = this->GetSafeHwnd();

	//�������鷽���������ѡ��
	SYFF_combobox_control.AddString(TEXT("��ʽ����"));
	SYFF_combobox_control.AddString(TEXT("ChP������ѡ"));
	SYFF_combobox_control.AddString(TEXT("EP������ѡ"));
	SYFF_combobox_control.AddString(TEXT("USP������ѡ"));
	

	


	//list2
	m_ListCtrl.SetShowCheckBoxSign(TRUE);//�����������Ƿ���ʾ��ѡ ��
	m_ListCtrl.SetSingleRowCheck(FALSE);//���õ������Ƿ����ѡ��ѡ��
	m_ListCtrl.SetRowHeight(35);               //�����и߶�

	m_ListCtrl.SetHeaderBKColor(234, 243, 248, 1); //����ͷ������ɫ



	m_ListCtrl.InsertColumn(0, _T(""), LVCFMT_CENTER, 0);
	m_ListCtrl.InsertColumn(1, _T("ע�����"), LVCFMT_CENTER, 80, FALSE, TRUE);
	m_ListCtrl.InsertColumn(2, _T("����"), LVCFMT_CENTER, 80, FALSE, TRUE);//�ɱ༭(����༭��)
	m_ListCtrl.InsertColumn(3, _T("̽ͷ��"), LVCFMT_CENTER,80);//�ɱ༭(����༭��)
	m_ListCtrl.InsertColumn(4, _T("�ú�"), LVCFMT_CENTER, 80);
	m_ListCtrl.InsertColumn(5, _T("����"), LVCFMT_CENTER, 80);
	m_ListCtrl.InsertColumn(6, _T("����"), LVCFMT_CENTER, 80,1);
	m_ListCtrl.InsertColumn(7, _T("ȫ��ʱ��"), LVCFMT_CENTER, 80);
	m_ListCtrl.InsertColumn(8, _T("ע���ʱ��"), LVCFMT_CENTER, 80);
	m_ListCtrl.InsertColumn(9, _T("ʵʱ�¶�"), LVCFMT_CENTER, 80); 
	m_ListCtrl.InsertColumn(10, _T("����"), LVCFMT_CENTER,85);
	m_ListCtrl.InsertColumn(11, _T("�²�"), LVCFMT_CENTER, 85);
	m_ListCtrl.InsertColumn(12, _T("���鷽��"), LVCFMT_CENTER,85);
	m_ListCtrl.InsertColumn(13, _T("����Ʒ����"), LVCFMT_CENTER, 105, FALSE, TRUE);
	m_ListCtrl.InsertColumn(14, _T("��Ʒ���"), LVCFMT_CENTER, 75);
	m_ListCtrl.InsertColumn(15, _T("����"), LVCFMT_CENTER, 75);


	CString str1;
	for (int i = 0; i < PointNum ; i++)
	{
		m_ListCtrl.InsertItem(i, TEXT(""));
		m_ListCtrl.SetItemText(i, 1, _T("ȷ��"));
		m_ListCtrl.SetItemText(i, 2, _T("��ʼ"));
		//�ѻ�ȡ���������ݲ��ȥ

		str1.Format(_T("%d"), i + 1);//������ת��Ϊcstring������str��
		m_ListCtrl.SetItemText(i, 3, str1);

		m_ListCtrl.SetItemColor(13, i, RGB(0, 0, 255)); //���ù���Ʒ���Ʊ���ɫ

	}

	







	//m_ListCtrl.SetHeaderCheckedState(1);//ͷ���Ƿ���ʾ��ѡ��0:NO CHECKBOX��1��δѡ �У�2��ѡ ��
	//m_ListCtrl.SetHeaderHeight(2);          //����ͷ���߶�
	//m_ListCtrl.SetHeaderFontHW(16, 0);         //����ͷ������߶�,�Ϳ��,0��ʾȱʡ������Ӧ 
	//m_ListCtrl.SetHeaderTextColor(RGB(0, 0, 0)); //����ͷ��������ɫ
	//m_ListCtrl.SetHeaderBKColor(234, 243, 248, 1); //����ͷ������ɫ
	//m_ListCtrl.SetShowCheckBoxSign(TRUE);//�����������Ƿ���ʾ��ѡ ��
	//m_ListCtrl.SetSingleRowCheck(FALSE);//���õ������Ƿ����ѡ��ѡ��
	////m_ListCtrl.SetColColor(0,RGB(10,150,20)); //�����б���ɫ
	////m_ListCtrl.SetColColor(2,RGB(30,100,90)); //�����б���ɫ
	////m_ListCtrl.SetBkColor(RGB(233,243,248));        //���ñ���ɫ
	//m_ListCtrl.SetItemColor(1,1,RGB(255,0,0)); //����ָ����Ԫ����ɫ
	//m_ListCtrl.SetItemColor(2, 1, RGB(100, 100, 10)); //����ָ����Ԫ����ɫ
	//m_ListCtrl.SetItemColor(15, 1, RGB(100, 100, 10)); //����ָ����Ԫ����ɫ
	//m_ListCtrl.SetRowHeight(35);               //�����и߶�
	//m_ListCtrl.SetTextColor(RGB(0, 0, 0));  //�����ı���ɫ
	//m_ListCtrl.SetFontHW(20, 0);               //��������߶ȣ��Ϳ��,0��ʾȱʡ���
	////m_ListCtrl.SetColTextColor(2,RGB(255,255,100)); //�������ı���ɫ
	////m_ListCtrl.SetItemTextColor(3,1,RGB(255,0,0));  //���õ�Ԫ��������ɫ(col,row,color)



		 //����cyusb
			mCCyUsbDevice = new CCyUSBDevice(NULL);//ʵ��������

			//TRACE("%d\n", mCCyUsbDevice->DeviceCount());
			if (!mCCyUsbDevice->Open(0)) //��ʧ��
			{
				//TRACE("USBδ����");
			}
			if (mCCyUsbDevice->DeviceCount())   //��֤������һ��USB�豸����  
			{
				for (int i = 0; i < mCCyUsbDevice->DeviceCount(); i++)    //ö������USB�豸  
				{
					mCCyUsbDevice->Open(i);                   //�򿪵�i��USB�豸  
					//TRACE("%s\n", mCCyUsbDevice->DeviceName);//��ѡ��ĵ�ǰ�豸��  
				}
			}
			else {
				return 0;
			}
		
			OutEndpt = mCCyUsbDevice->EndPoints[1];
			InEndpt = mCCyUsbDevice->EndPoints[3];
		
			bLooping = true;
			XferThread = AfxBeginThread(XferLoop1, this);




	


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


/*��ť�����Ϣ�����ݸı�֮�󣬽�����Ϣ����*/
LRESULT Tab_CEWEN_WDCD_SYPC::OnListCtrlButtonClicked(WPARAM wParam, LPARAM lParam)
{
	ListCtrlColButton *pInfo = (ListCtrlColButton *)lParam;

	CString str;

	CString str_syff(m_ListCtrl.GetItemText(pInfo->row, 12));//��ȡ��Ӧ��ʵ�鷽��

	

	//CString str_ifstart;//

	CString zssy(TEXT("��ʽ����"));
	CString chp(TEXT("Chp������ѡ"));
	CString ep(TEXT("Ep������ѡ"));

	if (str_syff != TEXT("")) {

		switch (pInfo->col)
		{
		
		case 1://ȷ�ϰ�ť
			
					if (point_ifstart_now[pInfo->row].ifstart!=1) //�ж��Ƿ��Ѿ���ʼ
					{
						AfxMessageBox(TEXT("���ȵ����ʼ��ť��"));
					}
					else {
						
							CString str_gspmc(m_ListCtrl.GetItemText(pInfo->row, 13));//��ȡ��Ӧ�Ĺ���Ʒ����

							if (str_gspmc != _T("")) //��ѡ���깩��Ʒ������ȷ��
							{
								str.Format(_T("%d��̽ͷ��ȷ�ϣ�"), pInfo->row + 1);
								AfxMessageBox(str);
								m_ListCtrl.SetItemText(pInfo->row, 1, _T("��ȷ��"));

								//����Ӧȷ��Ҫ������		
								point_ifstart_now[pInfo->row].ifconfirm = 1;

								//���б�ȫ����Ϣͬ�������ݿ�
								MyDatabase mydatabase;

								if (!mydatabase.ConnectDB_orcreate())//�ж��Ƿ��������ݿ�ɹ�
								{
									AfxMessageBox(_T("���ݿ�����ʧ��!"));

								}
								else {
									CString str_tuhao(m_ListCtrl.GetItemText(pInfo->row, 4));//�ú�
									CString str_tizhong(m_ListCtrl.GetItemText(pInfo->row, 5));//����
									CString str_jiliang(m_ListCtrl.GetItemText(pInfo->row, 6));//����
									CString str_qbsj(m_ListCtrl.GetItemText(pInfo->row, 7));//ȫ��ʱ��
									CString str_zshsj(m_ListCtrl.GetItemText(pInfo->row, 8));//ע���ʱ��
									CString str_sswd(m_ListCtrl.GetItemText(pInfo->row, 9));//ʵʱ�¶�
									CString str_jw(m_ListCtrl.GetItemText(pInfo->row, 10));//����
									CString str_wc(m_ListCtrl.GetItemText(pInfo->row, 11));//�²�
									CString str_ssff(m_ListCtrl.GetItemText(pInfo->row, 12));//���鷽��
									CString str_ypbh(m_ListCtrl.GetItemText(pInfo->row, 14));//��Ʒ���
									CString str_ph(m_ListCtrl.GetItemText(pInfo->row, 15));//����
									
									
									mydatabase.add_SYPC_info(pInfo->row + 1, str_tuhao, str_tizhong, str_jiliang, str_qbsj, str_zshsj, str_sswd, str_jw, str_wc, str_ssff, str_gspmc, str_ypbh, str_ph);
								}


							}
						
					}

			break;
		case 2://��ʼ��ť
			

					str.Format(_T("%d��̽ͷ�ѿ�ʼ��"), pInfo->row + 1);
					m_ListCtrl.SetItemText(pInfo->row, 2, _T("�ѿ�ʼ"));
					//str_ifstart = TEXT("�ѿ�ʼ");
					//point_ifstart_now[pInfo->row].str_ifstart = TEXT("�ѿ�ʼ");

					point_ifstart_now[pInfo->row].ifstart = 1;

					if (!str_syff.CompareNoCase(zssy)) {//�ж��Ƿ�����ʽʵ��
						//AfxMessageBox(TEXT("��ʽ���飡"));
						point_ifstart_now[pInfo->row].syff = 1;
					}
					else if (!str_syff.CompareNoCase(chp)) {//�ж��Ƿ���Chp������ѡ
						//AfxMessageBox(TEXT("Chp������ѡ��"));
						point_ifstart_now[pInfo->row].syff = 2;
					}
					else if (!str_syff.CompareNoCase(ep)) {//�ж��Ƿ���Ep������ѡ
						//AfxMessageBox(TEXT("Ep������ѡ��"));
						point_ifstart_now[pInfo->row].syff = 3;
					}
					else {
						//AfxMessageBox(TEXT("USP������ѡ��"));
						point_ifstart_now[pInfo->row].syff = 4;
					}




					SetTimer(1, 20000, NULL);      //��������ʱ����ţ���ʱʱ�䣨ms����������ʱ��1��ÿ��20sˢ��һ��


			break;
	
		case 13://����Ʒ���ư�ť

					/*current_selected_point_gspmc_button = pInfo->row;
					SYPC_XZGSP xzgsp;
					xzgsp.DoModal();*///�����ô��룬��ǰ����ѡ����Ʒ����

					if (point_ifstart_now[pInfo->row].ifstart != 1) //�ж��Ƿ��Ѿ���ʼ
						{
							AfxMessageBox(TEXT("���ȵ����ʼ��ť��"));
						}
					else 
					{
						if (point_ifstart_now[pInfo->row].syff == 1) //��ʽʵ��
						{
							if (point_ifstart_now[pInfo->row].j >= 270)//��90min��
							{
								if (point_ifstart_now[pInfo->row].t_avereage >= 38.0&&point_ifstart_now[pInfo->row].t_avereage <= 39.6&&point_ifstart_now[pInfo->row].t_maxdif <= 0.2)//����Ҫ��
								{
									//������ִ���ѡ����Ʒ

									current_selected_point_gspmc_button = pInfo->row;//�������һ�������Ϣ

									SYPC_XZGSP xzgsp;
									xzgsp.DoModal();

								}
								else //������Ҫ��
								{
									//��ʾ������Ҫ�����²�

									MessageBox(TEXT("���ɼ��¶��ѿ�ʼ�����º��²�������Ӧ���鷽����Ҫ��󣬲ſ�ѡ����Ʒ���ڸ��õ�ע�䣡"), TEXT("��ʾ"), MB_ICONASTERISK|MB_OK);
								}

							}
							else//û��90min
							{
								MessageBox(TEXT("���ɼ��¶��ѿ�ʼ�����º��²�������Ӧ���鷽����Ҫ��󣬲ſ�ѡ����Ʒ���ڸ��õ�ע�䣡"), TEXT("��ʾ"), MB_ICONASTERISK | MB_OK);
							
							}

						}
						else//����ʵ��
						{
							if (point_ifstart_now[pInfo->row].j >= 270)//��90min��
							{
								//ֱ�ӵ�����ִ���ѡ����Ʒ����Ҫ��
								current_selected_point_gspmc_button = pInfo->row;
								SYPC_XZGSP xzgsp;
								xzgsp.DoModal();

							}
							else
							{
								MessageBox(TEXT("���ɼ��¶��ѿ�ʼ����������90���Ӻ󣬲ſ�ѡ����Ʒ��"), TEXT("��ʾ"), MB_ICONASTERISK | MB_OK);
							}
						}

					}

			
			break;
		}

		

	}
	else
	{
		AfxMessageBox(TEXT("���Ȳ�ȫ̽ͷ����Ӧ��Ϣ���ݣ�"));
	}
	
	




	return 0;
}

void Tab_CEWEN_WDCD_SYPC::OnBnClickedButton1()//����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);


	/*UNICODE�ַ��������·�ʽ�����ݱ����뵽���ݿ�ʱ�������,�������ַ�ʽ���벻�����ģ�����Ҳ�������insert�﷨�й�*/
	char temp[100] = {};
	std::string str_1 = CStringA(TTH_cstring);
	strncpy_s(temp, _countof(temp), str_1.c_str(), TTH_cstring.GetLength());//������ʵ�ֽ�cstringװ��Ϊchar*

	if (atoi(temp) > 0 && atoi(temp) <= PointNum){
		int pos; //��ӵ�λ��
		
		CString str;//�������յ�i������Ӧ��̽ͷ��
		for (int i = 0; i < PointNum; i++)
		{
			
			str = m_ListCtrl.GetItemText(i, 3); //��ȡ��i������Ӧ��̽ͷ��
			if (str == TTH_cstring){
				pos = i;
			}
		}


		//�ѻ�ȡ���������ݲ��ȥ
		if (TH_cstring == TEXT("") || TZ_cstring == TEXT(""))MessageBox(TEXT("�úŻ����ز���Ϊ��"), TEXT("��ʾ"));
		else{
			m_ListCtrl.SetItemText(pos, 4, TH_cstring);
			m_ListCtrl.SetItemText(pos, 5, TZ_cstring);

			if (SYFF_cstring == TEXT(""))MessageBox(TEXT("���鷽������Ϊ��"), TEXT("��ʾ"));
			else m_ListCtrl.SetItemText(pos, 12, SYFF_cstring);
		}

	}
	else{

		CString str2;
		str2.Format(_T("%d"),PointNum);//������ת��Ϊcstring������str2��
		str2.Format(TEXT("��������1��") + str2+ TEXT("֮���̽ͷ��"));//����FORMATƴ�ӵ�һ��
		MessageBox(str2, TEXT("��ʾ"));
	}


}





void Tab_CEWEN_WDCD_SYPC::OnBnClickedButton4()//����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true); //�ѶԻ����е���Ϣ���µ��ڴ���ȥ


	m_ListCtrl.SetItemText(m_listSelPos, 4, TH_cstring);

	m_ListCtrl.SetItemText(m_listSelPos, 5, TZ_cstring);
	
	m_ListCtrl.SetItemText(m_listSelPos, 12, SYFF_cstring);


}










void Tab_CEWEN_WDCD_SYPC::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������



}


BOOL Tab_CEWEN_WDCD_SYPC::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	
	

	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void Tab_CEWEN_WDCD_SYPC::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ



	CDialogEx::OnNcCalcSize(bCalcValidRects, lpncsp);
}


void Tab_CEWEN_WDCD_SYPC::OnKillFocus(CWnd* pNewWnd)
{
	CDialogEx::OnKillFocus(pNewWnd);

	// TODO: �ڴ˴������Ϣ����������


}






void Tab_CEWEN_WDCD_SYPC::OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_listSelPos = m_ListCtrl.GetSelectionMark();


	TTH_cstring = m_ListCtrl.GetItemText(m_listSelPos, 3);//��ȡ��ǰ��¼����ʾ���ı�
	TTH_control.SetWindowTextW(TTH_cstring);//������cedit���͵Ĳ��ܵ��������

	TH_cstring = m_ListCtrl.GetItemText(m_listSelPos, 4);//��ȡ��ǰ��¼����ʾ���ı�
	TH_control.SetWindowTextW(TH_cstring);//������cedit���͵Ĳ��ܵ��������

	TZ_cstring = m_ListCtrl.GetItemText(m_listSelPos, 5);//��ȡ��ǰ��¼����ʾ���ı�
	TZ_control.SetWindowTextW(TZ_cstring);//������cedit���͵Ĳ��ܵ��������

	SYFF_cstring = m_ListCtrl.GetItemText(m_listSelPos, 12);//��ȡ��ǰ��¼����ʾ���ı�
	SYFF_combobox_control.SetWindowTextW(SYFF_cstring);//������cedit���͵Ĳ��ܵ��������
	*pResult = 0;




}


double average(double *x, int len)

{

	double sum = 0;

	for (int i = 0; i<len;i++)

		sum += x[i];

		return sum / len; // ����ƽ��ֵ

}

double max_difference(double *arr, int arr_len)
{
	int i = 2;
	double min, max;
	if (arr[0] > arr[1])
	{
		max = arr[0];
		min = arr[1];
	}
	else
	{
		max = arr[1];
		min = arr[0];
	}

	for (; i < arr_len; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		else if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return (max - min);
}


void Tab_CEWEN_WDCD_SYPC::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ


	switch (nIDEvent)
	{
	case 1:   //��ʱ��1
	{
		
		for (int i = 0; i < PointNum; i++) {

			if (point_ifstart_now[i].ifstart == 1) {
				 
				CString str_real_t;
				str_real_t.Format(_T("%.2f"), point_ifstart_now[i].t_real);

				CString str_total_t;
				str_total_t.Format(_T("%d"), (point_ifstart_now[i].j)/3);//ÿ3��20s 1min

				(m_ListCtrl).SetItemText(i, 9, str_real_t);//������д���ʵʱ�¶�

				(m_ListCtrl).SetItemText(i, 7, str_total_t);//������д���ȫ��ʱ��

				point_ifstart_now[i].t_all[point_ifstart_now[i].j] = point_ifstart_now[i].t_real;//��¼�¶�
				point_ifstart_now[i].j++;

				//��ʱ�䵽90minʱ
				if (point_ifstart_now[i].j == 270) 
				{
					point_ifstart_now[i].t_avereage=average(point_ifstart_now[i].t_all, 90);//ǰ��ʮ���Ӿ���
					point_ifstart_now[i].t_maxdif = max_difference(point_ifstart_now[i].t_all, 90);//ǰ��ʮ�����²�

					CString str_avereage_t;
					str_avereage_t.Format(_T("%.2f"), point_ifstart_now[i].t_avereage);

					CString str_maxdif_t;
					str_maxdif_t.Format(_T("%.2f"), point_ifstart_now[i].t_maxdif);

					(m_ListCtrl).SetItemText(i, 10, str_avereage_t);//������д������
					(m_ListCtrl).SetItemText(i, 11, str_maxdif_t);//������д����²�

					if (point_ifstart_now[i].t_avereage >= 38.0&&point_ifstart_now[i].t_avereage <= 39.6&&point_ifstart_now[i].t_maxdif <= 0.2)//���²�;��·���Ҫ��ʱ
					{
						for (int p = 1; p <= 15; p++)//����һ�б�����ɫ�ı�
						{
							m_ListCtrl.SetItemColor(p, i, RGB(255, 0, 0)); //����ָ����Ԫ����ɫ
						}
						
						//�ж���ʲôʵ�鷽����������Ӧ��Ӧ


					}
				}

				//������ȷ�ϰ�ť��
				if (point_ifstart_now[i].ifconfirm == 1) 
				{	
					CString str_after_t;
					str_after_t.Format(_T("%d"), (point_ifstart_now[i].after_time) / 3);//ÿ3��20s 1min
					(m_ListCtrl).SetItemText(i, 8, str_after_t);//������д���ע���ʱ��

					point_ifstart_now[i].after_time++;
				}



			}
		}


		break;
	}

	case 2:   //��ʱ��2
	{
		
		break;
	}
	}


	CDialogEx::OnTimer(nIDEvent);
}


void Tab_CEWEN_WDCD_SYPC::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}






void Tab_CEWEN_WDCD_SYPC::OnBnClickedButton5()//��������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������


	

	if (MessageBox(TEXT("��һֻ���ñ�ѡ�����ѡ��ļ������еı������˹���Ʒ����ô����Ʒ�����еĸü�������Ӧ��̽ͷ��Ҳ��ͬʱ��ȡ�������ý������º�������¶����ݽ�ȫ�����ϡ�ȷ��Ҫ����������"), TEXT("��ʾ"), MB_ICONASTERISK | MB_OKCANCEL) == IDOK)
	{
		
		//��մ�������
		for (int k = 4; k <= 15; k++) {
			m_ListCtrl.SetItemText(m_listSelPos, k, TEXT(""));
		}
		
		
		//��ո�̽ͷ����Ӧ����
		point_ifstart_now[m_listSelPos].ifstart = 0;
		point_ifstart_now[m_listSelPos].j = 0;
		point_ifstart_now[m_listSelPos].t_real = 0;

	}

}

void Tab_CEWEN_WDCD_SYPC::PostNcDestroy()
{
	// TODO: �ڴ����ר�ô����/����û���

	//�ر��豸
	for (int i = 0; i < mCCyUsbDevice->DeviceCount(); i++)    //ö������USB�豸  
	{
		mCCyUsbDevice->Close();
		delete mCCyUsbDevice;
	}



	CDialogEx::PostNcDestroy();
}


LRESULT Tab_CEWEN_WDCD_SYPC::OnChlidFrameDBClick(WPARAM wParam, LPARAM lParam)
{


	select_GSP*my_gsp = (select_GSP*)(lParam);

	(m_ListCtrl).SetItemText(current_selected_point_gspmc_button , 13, my_gsp->str_gsp);//������д��빩��Ʒ����
	(m_ListCtrl).SetItemText(current_selected_point_gspmc_button, 14, my_gsp->str_ypbh);//������д�����Ʒ���
	(m_ListCtrl).SetItemText(current_selected_point_gspmc_button, 15, my_gsp->str_ph);//������д�������


	return 0;
}