
// Bit_PictureView.h : CBit_PictureView ��Ľӿ�
//

#pragma once


class CBit_PictureView : public CView
{
protected: // �������л�����
	CBit_PictureView();
	DECLARE_DYNCREATE(CBit_PictureView)

// ����
public:
	CBit_PictureDoc* GetDocument() const;

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
	virtual ~CBit_PictureView();
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
};

#ifndef _DEBUG  // Bit_PictureView.cpp �еĵ��԰汾
inline CBit_PictureDoc* CBit_PictureView::GetDocument() const
   { return reinterpret_cast<CBit_PictureDoc*>(m_pDocument); }
#endif

