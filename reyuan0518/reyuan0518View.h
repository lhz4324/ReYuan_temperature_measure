
// reyuan0518View.h : Creyuan0518View 类的接口
//

#pragma once


class Creyuan0518View : public CView
{
protected: // 仅从序列化创建
	Creyuan0518View();
	DECLARE_DYNCREATE(Creyuan0518View)

// 特性
public:
	Creyuan0518Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Creyuan0518View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // reyuan0518View.cpp 中的调试版本
inline Creyuan0518Doc* Creyuan0518View::GetDocument() const
   { return reinterpret_cast<Creyuan0518Doc*>(m_pDocument); }
#endif

