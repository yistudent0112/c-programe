
// GY_DrawToolView.h : CGY_DrawToolView ��Ľӿ�
//

#pragma once
#include"Arbitrary_Painting.h"
#include "Point2D.h"
#include"Line.h"
class CGY_DrawToolView : public CView
{
protected: // �������л�����
	CGY_DrawToolView();
	DECLARE_DYNCREATE(CGY_DrawToolView)

// ����
public:
	CGY_DrawToolDoc* GetDocument() const;

// ����
public:
	void SerializeEx(CArchive &ar);
	int m_nEleKind;
	int m_nMouseDown;
	CPoint2D m_pt0;
	CPoint2D m_pt1;
	CObList m_listOfEle;
	CObList m_listOfUndoEle;
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
	virtual ~CGY_DrawToolView();
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
//	afx_msg void OnPoint2D();
//	afx_msg void OnLine();
	afx_msg void OnPoint2d();
	afx_msg void OnUndo();
	afx_msg void OnRedo();
	afx_msg void OnOpenex();
	afx_msg void OnSaveex();
	afx_msg void OnNewex();
	afx_msg void OnLine();
//	afx_msg void OnUpdatePoint2d(CCmdUI *pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnArbitraryPainting();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	bool m_Move;
};

#ifndef _DEBUG  // GY_DrawToolView.cpp �еĵ��԰汾
inline CGY_DrawToolDoc* CGY_DrawToolView::GetDocument() const
   { return reinterpret_cast<CGY_DrawToolDoc*>(m_pDocument); }
#endif

