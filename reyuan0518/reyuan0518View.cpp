
// reyuan0518View.cpp : Creyuan0518View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Creyuan0518View 构造/析构

Creyuan0518View::Creyuan0518View()
{
	// TODO:  在此处添加构造代码

}

Creyuan0518View::~Creyuan0518View()
{
}

BOOL Creyuan0518View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Creyuan0518View 绘制

void Creyuan0518View::OnDraw(CDC* /*pDC*/)
{
	Creyuan0518Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// Creyuan0518View 打印

BOOL Creyuan0518View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Creyuan0518View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void Creyuan0518View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// Creyuan0518View 诊断

#ifdef _DEBUG
void Creyuan0518View::AssertValid() const
{
	CView::AssertValid();
}

void Creyuan0518View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Creyuan0518Doc* Creyuan0518View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Creyuan0518Doc)));
	return (Creyuan0518Doc*)m_pDocument;
}
#endif //_DEBUG


// Creyuan0518View 消息处理程序
