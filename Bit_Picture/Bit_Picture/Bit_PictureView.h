
// Bit_PictureView.h : CBit_PictureView 类的接口
//

#pragma once


class CBit_PictureView : public CView
{
protected: // 仅从序列化创建
	CBit_PictureView();
	DECLARE_DYNCREATE(CBit_PictureView)

// 特性
public:
	CBit_PictureDoc* GetDocument() const;

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
	virtual ~CBit_PictureView();
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
};

#ifndef _DEBUG  // Bit_PictureView.cpp 中的调试版本
inline CBit_PictureDoc* CBit_PictureView::GetDocument() const
   { return reinterpret_cast<CBit_PictureDoc*>(m_pDocument); }
#endif

