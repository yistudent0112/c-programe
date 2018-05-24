
// AnimationView.h : CAnimationView 类的接口
//

#pragma once
#include "afxwin.h"


class CAnimationView : public CView
{
protected: // 仅从序列化创建
	CAnimationView();
	DECLARE_DYNCREATE(CAnimationView)

// 特性
public:
	CAnimationDoc* GetDocument() const;

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
	virtual ~CAnimationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_IC_x;
	int m_IC_y;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
	CBitmap *bitmap;
	CBitmap bt;
	int i;
};

#ifndef _DEBUG  // AnimationView.cpp 中的调试版本
inline CAnimationDoc* CAnimationView::GetDocument() const
   { return reinterpret_cast<CAnimationDoc*>(m_pDocument); }
#endif

