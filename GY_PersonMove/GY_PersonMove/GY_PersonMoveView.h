
// GY_PersonMoveView.h : CGY_PersonMoveView ��Ľӿ�
//

#pragma once
#include "atltypes.h"


class CGY_PersonMoveView : public CView
{
protected: // �������л�����
	CGY_PersonMoveView();
	DECLARE_DYNCREATE(CGY_PersonMoveView)

// ����
public:
	CGY_PersonMoveDoc* GetDocument() const;

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
	virtual ~CGY_PersonMoveView();
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
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CPoint m_Cpoint;
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	CRect m_client;
};

#ifndef _DEBUG  // GY_PersonMoveView.cpp �еĵ��԰汾
inline CGY_PersonMoveDoc* CGY_PersonMoveView::GetDocument() const
   { return reinterpret_cast<CGY_PersonMoveDoc*>(m_pDocument); }
#endif

