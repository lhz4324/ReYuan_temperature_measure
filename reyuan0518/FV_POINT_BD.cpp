// FV_POINT_BD.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "reyuan0518.h"
#include "FV_POINT_BD.h"

#include "Quanjv.h"
//#include "MyDatabase.h"
// FV_POINT_BD

IMPLEMENT_DYNCREATE(FV_POINT_BD, CFormView)

FV_POINT_BD::FV_POINT_BD()
	: CFormView(FV_POINT_BD::IDD)
	, First_t(_T(""))
	, Second_t(_T(""))
	, Third_t(_T(""))
	, Fourth_t(_T(""))
	, Fifth_t(_T(""))
{

}

FV_POINT_BD::~FV_POINT_BD()
{
}

void FV_POINT_BD::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, 1000, First_t);
	DDX_Text(pDX, 1001, Second_t);
	DDX_Text(pDX, 1002, Third_t);
	DDX_Text(pDX, 1003, Fourth_t);
	DDX_Text(pDX, 1004, Fifth_t);
}

BEGIN_MESSAGE_MAP(FV_POINT_BD, CFormView)
	ON_BN_CLICKED(IDC_BUTTON10, &FV_POINT_BD::OnBnClickedButton10)

	ON_COMMAND_RANGE(10300, 10363, OnButtonPort)
	ON_BN_CLICKED(1005, &FV_POINT_BD::OnBnClicked1005)
	ON_BN_CLICKED(1006, &FV_POINT_BD::OnBnClicked1006)
	ON_BN_CLICKED(1007, &FV_POINT_BD::OnBnClicked1007)
	ON_BN_CLICKED(1008, &FV_POINT_BD::OnBnClicked1008)
	ON_BN_CLICKED(IDC_BUTTON11, &FV_POINT_BD::OnBnClickedButton11)
	ON_BN_CLICKED(1031, &FV_POINT_BD::OnBnClicked1031)
	ON_BN_CLICKED(IDC_BUTTON12, &FV_POINT_BD::OnBnClickedButton12)
	ON_BN_CLICKED(1030, &FV_POINT_BD::OnBnClicked1030)
	
END_MESSAGE_MAP()


// FV_POINT_BD ���

#ifdef _DEBUG
void FV_POINT_BD::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FV_POINT_BD::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FV_POINT_BD ��Ϣ�������


UINT XferLoop(LPVOID params) {

	OVERLAPPED outOvLap, inOvLap;

	FV_POINT_BD *dlg = (FV_POINT_BD *)params;


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



		/*	CString recvpoint1;
			recvpoint1.Format(_T("%02x"), inData[1]);*/

			CString recvpoint2;
			//recvpoint2.Format(_T("%d"), inData[1]);

			for (int i = 0; i < PointNum; i++) {

					if (dlg->point_array[i] == 1) {

						//((CEdit*)dlg->GetDlgItem(10201+i))->SetWindowTextW(recvpoint2);

						recvpoint2.Format(_T("%d"), inData[Protocol[i]]);//����Ӧ�����ֵ�ѹ������Ӧ�Ĵ���

						dlg->SetDlgItemTextW(10201 + i, recvpoint2);
				
					}
			 }
			

		
				CString recvStr;
				for (int i = 0; i < inlen; ++i) {
					recvStr.AppendFormat(_T("%02x"), inData[i]);
				}

				CString recvpoint1;
				recvpoint1.Format(_T("%02x"), inData[1]);

				((CEdit*)dlg->GetDlgItem(IDC_EDIT1))->SetSel(-1);
				((CEdit*)dlg->GetDlgItem(IDC_EDIT1))->ReplaceSel(recvStr + "\r\n");
				((CEdit*)dlg->GetDlgItem(IDC_EDIT1))->ReplaceSel(recvpoint1 + "\r\n");
				((CEdit*)dlg->GetDlgItem(IDC_EDIT1))->ReplaceSel(recvpoint2 + "\r\n");


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

void FV_POINT_BD::OnBnClickedButton10()//��ʼ�궨
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//��������༭���д
	(GetDlgItem(1000))->EnableWindow(TRUE);//ֻ��
	(GetDlgItem(1001))->EnableWindow(TRUE);//ֻ��
	(GetDlgItem(1002))->EnableWindow(TRUE);//ֻ��
	(GetDlgItem(1003))->EnableWindow(TRUE);//ֻ��
	(GetDlgItem(1004))->EnableWindow(TRUE);//ֻ��

	//���������ť��д
	(GetDlgItem(1005))->EnableWindow(TRUE);//ֻ��
	(GetDlgItem(1006))->EnableWindow(TRUE);//ֻ��
	(GetDlgItem(1007))->EnableWindow(TRUE);//ֻ��
	(GetDlgItem(1008))->EnableWindow(TRUE);//ֻ��
	(GetDlgItem(IDC_BUTTON11))->EnableWindow(TRUE);//ֻ��


	for (int i = 0; i < PointNum; i++) {
		if (point_array[i] == 1) {
			point_array[i] = 66;
		}		
	}

	

	//��checkbox��״̬ͬ��
	for (int i = 0; i < PointNum; i++) {
		point_array[i] = ((CButton *)GetDlgItem(10301 + i))->GetCheck();
	}

	//��������checkbox״̬���ɱ༭
	for (int i = 0; i < PointNum; i++) {
		((CButton *)GetDlgItem(10301 + i))->EnableWindow(FALSE);//ֻ��
	}




	//����cyusb
	CString btnStr;
	GetDlgItemText(IDC_BUTTON10, btnStr);
	if (_T("��ʼ�궨") == btnStr) {

		TRACE("%d\n", mCCyUsbDevice->DeviceCount());
		if (!mCCyUsbDevice->Open(0)) //��ʧ��
		{
			TRACE("USBδ����");
		}
		if (mCCyUsbDevice->DeviceCount())   //��֤������һ��USB�豸����  
		{
			for (int i = 0; i < mCCyUsbDevice->DeviceCount(); i++)    //ö������USB�豸  
			{
				mCCyUsbDevice->Open(i);                   //�򿪵�i��USB�豸  
				TRACE("%s\n", mCCyUsbDevice->DeviceName);//��ѡ��ĵ�ǰ�豸��  
			}
		}
		else {
			return;
		}

		OutEndpt = mCCyUsbDevice->EndPoints[1];
		InEndpt = mCCyUsbDevice->EndPoints[3];

		bLooping = true;
		XferThread = AfxBeginThread(XferLoop, this);

		SetDlgItemText(IDC_BUTTON10, _T("�Ͽ�"));
	}
	else {
		bLooping = false;
		SetDlgItemText(IDC_BUTTON10, _T("��ʼ�궨"));
	}



}


void FV_POINT_BD::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���

	mCCyUsbDevice = new CCyUSBDevice(NULL);

	//��ʼ��������༭��ֻ��
	(GetDlgItem(1000))->EnableWindow(FALSE);//ֻ��
	(GetDlgItem(1001))->EnableWindow(FALSE);//ֻ��
	(GetDlgItem(1002))->EnableWindow(FALSE);//ֻ��
	(GetDlgItem(1003))->EnableWindow(FALSE);//ֻ��
	(GetDlgItem(1004))->EnableWindow(FALSE);//ֻ��
	

	//��ʼ���������ťֻ��
	(GetDlgItem(1005))->EnableWindow(FALSE);//ֻ��
	(GetDlgItem(1006))->EnableWindow(FALSE);//ֻ��
	(GetDlgItem(1007))->EnableWindow(FALSE);//ֻ��
	(GetDlgItem(1008))->EnableWindow(FALSE);//ֻ��
	(GetDlgItem(IDC_BUTTON11))->EnableWindow(FALSE);//ֻ��



	
	//��ȡ�ؼ��������Ļ��λ��
	CRect rectL;
	GetDlgItem(IDC_STATIC_POINT7)->GetWindowRect(&rectL);
	//ת��Ϊ�Ի����ϵ����λ��
	ScreenToClient(rectL);


	int left_static = rectL.left + 30;
	int right_static = rectL.left + 50 + 30;
	int top_static = rectL.top + 50;
	int bottom_static = rectL.top + 50+35;

	int jiange_hengxiang = 120;//������
	int jiange_zongxiang = 60;//������

	PointNum = 63;
	int k = PointNum;//̽ͷ����ֵ
	CStatic *p_Mytext[64];
	CEdit *p_Myedit[64];
	CButton *p_MyBut[64];
	int n = 1;//static�ı�������

	for (int j = 0; j < (PointNum / 8)+1; j++)
	{

		k -= 8;
		if (k > 0){
			for (int i = 0; i < 8; i++){

				p_Mytext[i+j*8] = NewMyText(10000 + n++, CRect(left_static + jiange_hengxiang * i, top_static + jiange_zongxiang * (j), right_static + jiange_hengxiang * i, bottom_static + jiange_zongxiang * (j)), 0);

				p_Myedit[i + j * 8] = NewMyEdit(10200 + n-1, CRect(left_static + 30 + jiange_hengxiang * i, top_static + jiange_zongxiang * (j), right_static + 30 + jiange_hengxiang * i, jiange_zongxiang * (j)+bottom_static), SS_BLACKFRAME);
				p_Myedit[i + j * 8]->SetWindowTextW(TEXT("0"));
				p_Myedit[i + j * 8]->EnableWindow(FALSE);//ֻ��

				p_MyBut[i + j * 8] = NewMyButton(10300 + n-1, CRect(left_static + 20+15 + 50 + jiange_hengxiang * i, top_static + jiange_zongxiang * (j), right_static + 20 +15+ 20 + jiange_hengxiang * i, +jiange_zongxiang * (j)+bottom_static - 15), BS_CHECKBOX);
			}

		}
		else{
			k += 8;
			for (int i = 0; i < k; i++){
				p_Mytext[i + j * 8] = NewMyText(10000 + n++, CRect(left_static + jiange_hengxiang * i, top_static + jiange_zongxiang * (j), right_static + jiange_hengxiang * i, bottom_static + jiange_zongxiang * (j)), 0);

				p_Myedit[i + j * 8] = NewMyEdit(10200 + n-1, CRect(left_static + 30 + jiange_hengxiang * i, top_static + jiange_zongxiang * (j), right_static + 30 + jiange_hengxiang * i, jiange_zongxiang * (j)+bottom_static), 0);
				p_Myedit[i + j * 8]->SetWindowTextW(TEXT("0"));
				p_Myedit[i + j * 8]->EnableWindow(FALSE);//ֻ��

				p_MyBut[i + j * 8] = NewMyButton(10300 + n-1, CRect(left_static + 20 + 15+50 + jiange_hengxiang * i, top_static + jiange_zongxiang * (j), right_static + 20 +15+ 20 + jiange_hengxiang * i, jiange_zongxiang * (j)+bottom_static - 15), BS_CHECKBOX);
			}
		}
	}
	



}


CEdit* FV_POINT_BD::NewMyEdit(int nID, CRect rect, int nStyle)
{
	CString m_Caption;
	m_Caption.LoadString(nID); //ȡ��ť����
	CEdit *p_Edit = new CEdit();
	ASSERT_VALID(p_Edit);
	p_Edit->Create(WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | nStyle, rect, this, nID);
	return p_Edit;
}



CStatic* FV_POINT_BD::NewMyText(int nID, CRect rect, int nStyle)
{
	CString m_Caption;
	m_Caption.LoadString(nID); //ȡ��ť����
	m_Caption.Format(_T("%d"), nID-10000);

	CStatic *p_Text = new CStatic();
	ASSERT_VALID(p_Text);
	p_Text->Create(m_Caption, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | nStyle, rect, this, nID);  //������ť
	return p_Text;
}


CButton* FV_POINT_BD::NewMyButton(int nID, CRect rect, int nStyle)
{
	CString m_Caption;
	m_Caption.LoadString(nID); //ȡ��ť����
	CButton *p_Button = new CButton();
	ASSERT_VALID(p_Button);
	p_Button->Create(m_Caption, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | nStyle, rect, this, nID);  //������ť
	return p_Button;
}


void FV_POINT_BD::OnButtonPort(UINT nID){

	CWnd *pWnd = GetFocus();
	int nPortID = pWnd->GetDlgCtrlID();


	CButton* pBtn = (CButton*)GetDlgItem(nPortID);		
	pBtn->SetCheck(!pBtn->GetCheck());

	



}

void FV_POINT_BD::OnBnClicked1005()//��һ���¶Ƚ��ܰ�ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	


	CString str_first_voltage;
	
	char temp[100] = {};
	std::string str_1 = CStringA(First_t);
	strncpy_s(temp, _countof(temp), str_1.c_str(), First_t.GetLength());//������ʵ�ֽ�cstringװ��Ϊchar*

	if (atof(temp) >= 36.8 && atof(temp) <= 37.2) {

		for (int i = 0; i < PointNum; i++) {

			if (point_array[i] == 1) {
				point_temperature_now[i].first_t = First_t;

				(GetDlgItem(10201 + i))->GetWindowTextW(str_first_voltage);//��ȡ��̽ͷ��Ӧ�����ֵ�ѹ
				point_temperature_now[i].first_voltage = str_first_voltage;
				

			}

		}
		(GetDlgItem(1005))->SetWindowTextW(TEXT("�ѽ���"));
		(GetDlgItem(1005))->EnableWindow(FALSE);//ֻ��

	}
	else {
		MessageBox(TEXT("������36.8��-37.2�淶Χ�ڵ����ݣ�"), TEXT("����"), MB_ICONEXCLAMATION | MB_OK);
	}

	

}


void FV_POINT_BD::OnBnClicked1006()//�ڶ����¶Ƚ��ܰ�ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	char temp[100] = {};
	std::string str_1 = CStringA(Second_t);
	strncpy_s(temp, _countof(temp), str_1.c_str(), Second_t.GetLength());//������ʵ�ֽ�cstringװ��Ϊchar*

	CString str_second_voltage;
	
	if (atof(temp) >= 37.8 && atof(temp) <= 38.2) {

		for (int i = 0; i < PointNum; i++) {
			if (point_array[i] == 1) {
				point_temperature_now[i].second_t = Second_t;

				(GetDlgItem(10201 + i))->GetWindowTextW(str_second_voltage);//��ȡ��̽ͷ��Ӧ�����ֵ�ѹ
				point_temperature_now[i].second_voltage = str_second_voltage;
			}
		}

		(GetDlgItem(1006))->SetWindowTextW(TEXT("�ѽ���"));
		(GetDlgItem(1006))->EnableWindow(FALSE);//ֻ��
	}
	else {
		MessageBox(TEXT("������37.8��-38.2�淶Χ�ڵ����ݣ�"), TEXT("����"), MB_ICONEXCLAMATION | MB_OK);
	}
	

}


void FV_POINT_BD::OnBnClicked1007()//�������¶Ƚ��ܰ�ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);

	char temp[100] = {};
	std::string str_1 = CStringA(Third_t);
	strncpy_s(temp, _countof(temp), str_1.c_str(), Third_t.GetLength());//������ʵ�ֽ�cstringװ��Ϊchar*


	CString str_third_voltage;

	if (atof(temp) >= 38.8 && atof(temp) <= 39.2) {

		for (int i = 0; i < PointNum; i++) {
			if (point_array[i] == 1) {
				point_temperature_now[i].third_t = Third_t;

				(GetDlgItem(10201 + i))->GetWindowTextW(str_third_voltage);//��ȡ��̽ͷ��Ӧ�����ֵ�ѹ
				point_temperature_now[i].third_voltage = str_third_voltage;

			}
		}

		(GetDlgItem(1007))->SetWindowTextW(TEXT("�ѽ���"));
		(GetDlgItem(1007))->EnableWindow(FALSE);//ֻ��
	}
	else {
		MessageBox(TEXT("������38.8��-39.2�淶Χ�ڵ����ݣ�"), TEXT("����"), MB_ICONEXCLAMATION | MB_OK);
	}
	

}


void FV_POINT_BD::OnBnClicked1008()//���ĵ��¶Ƚ��ܰ�ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);

	char temp[100] = {};
	std::string str_1 = CStringA(Fourth_t);
	strncpy_s(temp, _countof(temp), str_1.c_str(), Fourth_t.GetLength());//������ʵ�ֽ�cstringװ��Ϊchar*

	CString str_fourth_voltage;

	if (atof(temp) >= 39.8 && atof(temp) <= 40.2) {

		for (int i = 0; i < PointNum; i++) {
			if (point_array[i] == 1) {
				point_temperature_now[i].fourth_t = Fourth_t;

				(GetDlgItem(10201 + i))->GetWindowTextW(str_fourth_voltage);//��ȡ��̽ͷ��Ӧ�����ֵ�ѹ
				point_temperature_now[i].fourth_voltage = str_fourth_voltage;

			}
		}

		(GetDlgItem(1008))->SetWindowTextW(TEXT("�ѽ���"));
		(GetDlgItem(1008))->EnableWindow(FALSE);//ֻ��
	}
	else {
		MessageBox(TEXT("������39.8��-40.2�淶Χ�ڵ����ݣ�"), TEXT("����"), MB_ICONEXCLAMATION | MB_OK);
	}
	
}


void FV_POINT_BD::OnBnClickedButton11()//������¶Ƚ��ܰ�ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	char temp[100] = {};
	std::string str_1 = CStringA(Fifth_t);
	strncpy_s(temp, _countof(temp), str_1.c_str(), Fifth_t.GetLength());//������ʵ�ֽ�cstringװ��Ϊchar*

	CString str_fifth_voltage;;

	if (atof(temp) >= 40.8 && atof(temp) <= 41.2) {

		for (int i = 0; i < PointNum; i++) {
			if (point_array[i] == 1) {
				point_temperature_now[i].fifth_t = Fifth_t;

				(GetDlgItem(10201 + i))->GetWindowTextW(str_fifth_voltage);//��ȡ��̽ͷ��Ӧ�����ֵ�ѹ
				point_temperature_now[i].fifth_voltage = str_fifth_voltage;

			}
		}

		(GetDlgItem(IDC_BUTTON11))->SetWindowTextW(TEXT("�ѽ���"));
		(GetDlgItem(IDC_BUTTON11))->EnableWindow(FALSE);//ֻ��
	}
	else {
		MessageBox(TEXT("������40.8��-41.2�淶Χ�ڵ����ݣ�"), TEXT("����"), MB_ICONEXCLAMATION | MB_OK);
	}
	
}


void FV_POINT_BD::OnBnClicked1031()//����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (MessageBox(TEXT("���غ�˽������ݽ���գ�ȷ�Ϸ�����"), TEXT("����"), MB_ICONEXCLAMATION| MB_OKCANCEL) == IDOK) {
		GetParentFrame()->DestroyWindow();
		return;
	}

}


void FV_POINT_BD::OnBnClickedButton12()//ȫ�����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (MessageBox(TEXT("���ִ��ȫ����������α궨����õ���ʱ���ݽ�ȫ����գ���֮�����±궨�����Ҫ�����"), TEXT("��ʾ"), MB_ICONASTERISK|MB_OKCANCEL) == IDOK) {


		First_t = TEXT("");
		Second_t= TEXT("");
		Third_t	= TEXT("");
		Fourth_t= TEXT("");
		Fifth_t	= TEXT("");

		(GetDlgItem(1005))->SetWindowTextW(TEXT("����"));
		
		(GetDlgItem(1006))->SetWindowTextW(TEXT("����"));
		
		(GetDlgItem(1007))->SetWindowTextW(TEXT("����"));
		
		(GetDlgItem(1008))->SetWindowTextW(TEXT("����"));
		
		(GetDlgItem(IDC_BUTTON11))->SetWindowTextW(TEXT("����"));
		

		//��ʼ��������༭��ֻ��
		(GetDlgItem(1000))->EnableWindow(FALSE);//ֻ��
		(GetDlgItem(1001))->EnableWindow(FALSE);//ֻ��
		(GetDlgItem(1002))->EnableWindow(FALSE);//ֻ��
		(GetDlgItem(1003))->EnableWindow(FALSE);//ֻ��
		(GetDlgItem(1004))->EnableWindow(FALSE);//ֻ��


		//��ʼ���������ťֻ��
		(GetDlgItem(1005))->EnableWindow(FALSE);//ֻ��
		(GetDlgItem(1006))->EnableWindow(FALSE);//ֻ��
		(GetDlgItem(1007))->EnableWindow(FALSE);//ֻ��
		(GetDlgItem(1008))->EnableWindow(FALSE);//ֻ��
		(GetDlgItem(IDC_BUTTON11))->EnableWindow(FALSE);//ֻ��


		for (int i = 0; i < PointNum; i++) {
			((CButton *)GetDlgItem(10301 + i))->SetCheck(0);//����ÿ��checkbox���
			((CButton *)GetDlgItem(10301 + i))->EnableWindow(TRUE);
		}


	}

	UpdateData(FALSE);
}



double cstring_to_double(CString str) {

	char temp[100] = {};
	std::string str_temp = CStringA(str);
	strncpy_s(temp, _countof(temp), str_temp.c_str(), str.GetLength());//������ʵ�ֽ�cstringװ��Ϊchar*

	return atof(temp);
}
void calculate_regress(int i) {

	double x[5];
	double y[5];

	x[0] = cstring_to_double(point_temperature_now[i].first_voltage);
	x[1] = cstring_to_double(point_temperature_now[i].second_voltage);
	x[2] = cstring_to_double(point_temperature_now[i].third_voltage);
	x[3] = cstring_to_double(point_temperature_now[i].fourth_voltage);
	x[4] = cstring_to_double(point_temperature_now[i].fifth_voltage);

	if (x[0] == 0) {//���û������������ѹ����0������mysql���ݿ�����ʧ�ܣ�������Ĭ��ֵ����
		x[0] = 63;
		x[1] = 90;
		x[2] = 117;
		x[3] = 146;
		x[4] = 177;
	}
							
	/*x[0] = 63;
	x[1] = 90;
	x[2] = 117;
	x[3] = 146;
	x[4] = 177;*/

	y[0] = cstring_to_double(point_temperature_now[i].first_t);
	y[1] = cstring_to_double(point_temperature_now[i].second_t);
	y[2] = cstring_to_double(point_temperature_now[i].third_t);
	y[3] = cstring_to_double(point_temperature_now[i].fourth_t);
	y[4] = cstring_to_double(point_temperature_now[i].fifth_t);

	double totx=0, toty=0;
	double xy = 0, x2 = 0;
	double xbar = 0, ybar = 0;
	double a= 0, b = 0;
	for (int i = 0; i < 5; i++)
	{
		totx += x[i];
		toty += y[i];
		xy += x[i] * y[i];
		x2 += x[i] * x[i];
	}
	xbar = totx / 5;
	ybar = toty / 5;

	b = (xy - 5 * xbar*ybar) / (x2 - 5 * xbar*xbar);
	a = ybar - b * xbar;

	point_temperature_now[i].a = a;
	point_temperature_now[i].b = b;


	point_temperature_now[i].first_regress = a + b * x[0];
	point_temperature_now[i].second_regress = a + b * x[1];
	point_temperature_now[i].third_regress = a + b * x[2];
	point_temperature_now[i].fourth_regress = a + b * x[3];
	point_temperature_now[i].fifth_regress = a + b * x[4];

	point_temperature_now[i].qualified = TEXT("yes");

	for (int i = 0; i < 5; i++) {
		if ((a + b * x[i] - y[i]) > 0.5|| (a + b * x[i] - y[i]) <- 0.5)point_temperature_now[i].qualified=TEXT("not");
	}
	

	//printf("һԪ���Իع鷽��Ϊ��");
	//cout << "y=" << a << "+" << b << "x";
}

void FV_POINT_BD::OnBnClicked1030()//����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (MessageBox(TEXT("��ȷ�������������ȷ��Ҫ�������"), TEXT("����"), MB_ICONEXCLAMATION | MB_OKCANCEL) == IDOK) {



		CString str_sample(TEXT("�ѽ���"));

		CString Firststr;
		(GetDlgItem(1005))->GetWindowTextW(Firststr);//ֻ��

		CString Secondstr;
		(GetDlgItem(1006))->GetWindowTextW(Secondstr);//ֻ��

		CString Thirdstr;
		(GetDlgItem(1007))->GetWindowTextW(Thirdstr);//ֻ��

		CString Fourthstr;
		(GetDlgItem(1008))->GetWindowTextW(Fourthstr);//ֻ��

		CString Fifthstr;
		(GetDlgItem(IDC_BUTTON11))->GetWindowTextW(Fifthstr);//ֻ��



		if (Firststr == str_sample && Secondstr == str_sample && Thirdstr == str_sample && Fourthstr == str_sample && Fifthstr == str_sample)
		{
			//�������ݿ⣬�洢����
			
			SYSTEMTIME st;
			CString strDate, strTime;
			GetLocalTime(&st);
			strDate.Format(TEXT("%4d-%2d-%2d"), st.wYear, st.wMonth, st.wDay);
			strTime.Format(TEXT("%2d:%2d:%2d"), st.wHour, st.wMinute, st.wSecond);


			for (int i = 0; i < PointNum; i++) {
				point_array[i] = ((CButton *)GetDlgItem(10301 + i))->GetCheck();
				if (point_array[i] == 1) {


					CString strPointnum;//̽ͷ��
					strPointnum.Format(TEXT("%d"), i + 1);



					calculate_regress(i);//����ع��¶�

					USES_CONVERSION;
					myonlydatabase.add_point_BD_info(T2A(strDate), T2A(strTime), point_temperature_now[i], i + 1);

				

					

				}

			}

			MessageBox(TEXT("̽ͷ�궨�����ѱ��棬�ɲ鿴�궨����Ƿ�ϸ�Ҳ�ɰ���ȫ���������������̽ͷ�ı궨��"), TEXT("��ʾ"), MB_ICONASTERISK | MB_OK);

		}
		else {
			MessageBox(TEXT("��������δ���ܣ���ȫ�����ܺ����ԣ�"), TEXT("��ʾ"), MB_ICONASTERISK | MB_OK);

		}
		
		
	}
}


void FV_POINT_BD::PostNcDestroy()
{
	// TODO: �ڴ����ר�ô����/����û���

		//�ر��豸
		for (int i = 0; i < mCCyUsbDevice->DeviceCount(); i++)    //ö������USB�豸  
		{
			mCCyUsbDevice->Close();   
			delete mCCyUsbDevice;
		}



	CFormView::PostNcDestroy();
}


