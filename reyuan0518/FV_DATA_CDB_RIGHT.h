#pragma once



// FV_DATA_CDB_RIGHT ������ͼ

class FV_DATA_CDB_RIGHT : public CFormView
{
	DECLARE_DYNCREATE(FV_DATA_CDB_RIGHT)

protected:
	FV_DATA_CDB_RIGHT();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~FV_DATA_CDB_RIGHT();

public:
	enum { IDD = IDD_FV_DATA_CDB_RIGHT };
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
	virtual void OnInitialUpdate();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnDraw(CDC* pDC);
};


