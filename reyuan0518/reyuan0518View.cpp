
// reyuan0518View.cpp : Creyuan0518View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "reyuan0518.h"
#endif

#include "reyuan0518Doc.h"
#include "reyuan0518View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Creyuan0518View

IMPLEMENT_DYNCREATE(Creyuan0518View, CView)

BEGIN_MESSAGE_MAP(Creyuan0518View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Creyuan0518View ����/����

Creyuan0518View::Creyuan0518View()
{
	// TODO:  �ڴ˴���ӹ������

}

Creyuan0518View::~Creyuan0518View()
{
}

BOOL Creyuan0518View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Creyuan0518View ����

void Creyuan0518View::OnDraw(CDC* /*pDC*/)
{
	Creyuan0518Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Creyuan0518View ��ӡ

BOOL Creyuan0518View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Creyuan0518View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Creyuan0518View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// Creyuan0518View ���

#ifdef _DEBUG
void Creyuan0518View::AssertValid() const
{
	CView::AssertValid();
}

void Creyuan0518View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Creyuan0518Doc* Creyuan0518View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Creyuan0518Doc)));
	return (Creyuan0518Doc*)m_pDocument;
}
#endif //_DEBUG


// Creyuan0518View ��Ϣ�������
