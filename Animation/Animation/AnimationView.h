
// AnimationView.h : CAnimationView ��Ľӿ�
//

#pragma once
#include "afxwin.h"


class CAnimationView : public CView
{
protected: // �������л�����
	CAnimationView();
	DECLARE_DYNCREATE(CAnimationView)

// ����
public:
	CAnimationDoc* GetDocument() const;

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
	virtual ~CAnimationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // AnimationView.cpp �еĵ��԰汾
inline CAnimationDoc* CAnimationView::GetDocument() const
   { return reinterpret_cast<CAnimationDoc*>(m_pDocument); }
#endif

