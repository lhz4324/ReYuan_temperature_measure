#pragma once



// FV_POINT_QR 窗体视图

class FV_POINT_QR : public CFormView
{
	DECLARE_DYNCREATE(FV_POINT_QR)

protected:
	FV_POINT_QR();           // 动态创建所使用的受保护的构造函数
	virtual ~FV_POINT_QR();

public:
	enum { IDD = IDD_POINT_QR };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};


