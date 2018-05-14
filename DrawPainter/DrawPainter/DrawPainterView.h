
// DrawPainterView.h : CDrawPainterView 类的接口
//

#pragma once
#include "atltypes.h"


class CDrawPainterView : public CView
{
protected: // 仅从序列化创建
	CDrawPainterView();
	DECLARE_DYNCREATE(CDrawPainterView)

// 特性
public:
	CDrawPainterDoc* GetDocument() const;

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
	virtual ~CDrawPainterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CPoint m_Cpoint;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	bool m_Bmove=false;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // DrawPainterView.cpp 中的调试版本
inline CDrawPainterDoc* CDrawPainterView::GetDocument() const
   { return reinterpret_cast<CDrawPainterDoc*>(m_pDocument); }
#endif

