
// GY_PersonMoveView.h : CGY_PersonMoveView 类的接口
//

#pragma once
#include "atltypes.h"


class CGY_PersonMoveView : public CView
{
protected: // 仅从序列化创建
	CGY_PersonMoveView();
	DECLARE_DYNCREATE(CGY_PersonMoveView)

// 特性
public:
	CGY_PersonMoveDoc* GetDocument() const;

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
	virtual ~CGY_PersonMoveView();
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
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CPoint m_Cpoint;
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	CRect m_client;
};

#ifndef _DEBUG  // GY_PersonMoveView.cpp 中的调试版本
inline CGY_PersonMoveDoc* CGY_PersonMoveView::GetDocument() const
   { return reinterpret_cast<CGY_PersonMoveDoc*>(m_pDocument); }
#endif

