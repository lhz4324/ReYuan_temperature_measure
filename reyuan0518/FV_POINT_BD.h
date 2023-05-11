#pragma once

#include "./CyAPI.h"//����ͷ�ļ���
#pragma comment(lib,"./CyAPI.lib")//ָ��·�������뾲̬���ӿ�

// FV_POINT_BD ������ͼ

class FV_POINT_BD : public CFormView
{
	DECLARE_DYNCREATE(FV_POINT_BD)

protected:
	FV_POINT_BD();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~FV_POINT_BD();

public:
	enum { IDD = IDD_POINT_BD };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton10();
	virtual void OnInitialUpdate();

	CButton* NewMyButton(int nID, CRect rect, int nStyle);
	CStatic* NewMyText(int nID, CRect rect, int nStyle);
	CEdit* NewMyEdit(int nID, CRect rect, int nStyle);

	afx_msg void OnButtonPort(UINT nID);//���ֶ˿ںţ���Ӧ��ͬid��������ͬ��Ӧ

	afx_msg void OnBnClicked1005();
	afx_msg void OnBnClicked1006();
	afx_msg void OnBnClicked1007();
	afx_msg void OnBnClicked1008();
	afx_msg void OnBnClickedButton11();


	int point_array[128];//��¼��̽ͷ�Ƿ�ѡ��
	afx_msg void OnBnClicked1031();
	CString First_t;
	CString Second_t;
	CString Third_t;
	CString Fourth_t;
	CString Fifth_t;
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClicked1030();



	CCyUSBDevice *mCCyUsbDevice;
	CCyUSBEndPoint *OutEndpt;
	CCyUSBEndPoint *InEndpt;

	bool bLooping;
	CWinThread *XferThread;//�߳�
	virtual void PostNcDestroy();

};


