
// DrawPainterView.h : CDrawPainterView ��Ľӿ�
//

#pragma once
#include "atltypes.h"


class CDrawPainterView : public CView
{
protected: // �������л�����
	CDrawPainterView();
	DECLARE_DYNCREATE(CDrawPainterView)

// ����
public:
	CDrawPainterDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDrawPainterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // DrawPainterView.cpp �еĵ��԰汾
inline CDrawPainterDoc* CDrawPainterView::GetDocument() const
   { return reinterpret_cast<CDrawPainterDoc*>(m_pDocument); }
#endif

