// instrument_self_check.cpp: 实现文件
//

#include "stdafx.h"
//#include "pch.h"
#include "reyuan0518.h"
#include "instrument_self_check.h"
#include "afxdialogex.h"

#include "Quanjv.h"

// instrument_self_check 对话框

IMPLEMENT_DYNAMIC(instrument_self_check, CDialogEx)

instrument_self_check::instrument_self_check(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_instrument_self_check, pParent)
{

}

instrument_self_check::~instrument_self_check()
{
}

void instrument_self_check::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
}


BEGIN_MESSAGE_MAP(instrument_self_check, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &instrument_self_check::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &instrument_self_check::OnBnClickedButton4)
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// instrument_self_check 消息处理程序


void instrument_self_check::OnBnClickedButton1()//继续
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();//用户名密码一致，进入程序
	
}


void instrument_self_check::OnBnClickedButton4()//退出
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


BOOL instrument_self_check::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化



	//CProgressCtrl *myProCtrl2 = (CProgressCtrl *)GetDlgItem(IDC_PROGRESS1);

	m_Progress.SetRange(0, 100);//设置进度条数值变化范围
	m_Progress.SetPos(0);      //设置进度条默认初始进度
	progress_pos = m_Progress.GetPos();
	m_Progress.SetStep(5);



	SetTimer(1, 200, NULL);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


BOOL instrument_self_check::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDC MemDC;
	MemDC.CreateCompatibleDC(pDC);

	CBitmap CBP;
	CBP.LoadBitmapW(IDB_BITMAP1);
	MemDC.SelectObject(&CBP);

	BITMAP bp;
	CBP.GetBitmap(&bp);

	CRect rect;
	GetClientRect(&rect);
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &MemDC, 0, 0, bp.bmWidth, bp.bmHeight, SRCCOPY);

	MemDC.DeleteDC();
	return TRUE;

	//return CDialogEx::OnEraseBkgnd(pDC);
}


void instrument_self_check::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值


	if (progress_pos >= 100) {
		
		
		KillTimer(1);
			mCCyUSBDevice = new CCyUSBDevice(NULL);
			if (mCCyUSBDevice->DeviceCount() > 0) {
				mCCyUSBDevice->Close();
			}

			USB_DEVICE_DESCRIPTOR descr;
			unsigned int dCnt = mCCyUSBDevice->DeviceCount();
			if (dCnt > 0) {
				if (true == mCCyUSBDevice->IsOpen()) {

				}
				else {
					if (mCCyUSBDevice->Open(0)) {
						mCCyUSBDevice->GetDeviceDescriptor(&descr);
					}
					isDevice = true;
					CString str;
					str.Format(TEXT("发现%d个可操作设备!"), dCnt);
					MessageBox(str);
					
					isWaring = true;

					Invalidate(); // 触发界面刷新显示
				}
			}
			else {
				isDevice = false;
				isRead = false;
				iscollect = false;
				
				mCCyUSBDevice->Close();
				MessageBox(TEXT("没有连接通讯采集设备或通讯采集设备故障！\n当连接好设备或排除故障后，重新执行热原测定通讯程序!"));
				if (true == isWaring) {
					isWaring = false;
					
					Invalidate(); // 触发界面刷新显示
				}
			}


				mCCyUSBDevice->Close();
				delete mCCyUSBDevice;

	}
	
	else {
		m_Progress.StepIt();
		progress_pos += 5;



		//int nPos = m_Progress.GetPos();// 获取进度条当前位置
		//CString str;
		//str.Format(_T("%d"), nPos);
		//GetDlgItem(IDC_PROGRESS1)->SetWindowText(str + _T("%"));//显示进度条初始进度

	}





	CDialogEx::OnTimer(nIDEvent);
}
