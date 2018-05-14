
// DrawPainterView.cpp : CDrawPainterView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DrawPainter.h"
#endif

#include "DrawPainterDoc.h"
#include "DrawPainterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawPainterView

IMPLEMENT_DYNCREATE(CDrawPainterView, CView)

BEGIN_MESSAGE_MAP(CDrawPainterView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawPainterView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()

// CDrawPainterView 构造/析构

CDrawPainterView::CDrawPainterView()
	: m_Cpoint(0)
	, m_Bmove(false)
{
	// TODO: 在此处添加构造代码

}

CDrawPainterView::~CDrawPainterView()
{
}

BOOL CDrawPainterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawPainterView 绘制

void CDrawPainterView::OnDraw(CDC* /*pDC*/)
{
	CDrawPainterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDrawPainterView 打印


void CDrawPainterView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawPainterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawPainterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawPainterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

//void CDrawPainterView::OnRButtonUp(UINT /* nFlags */, CPoint point)
//{
//	ClientToScreen(&point);
//	OnContextMenu(this, point);
//}

void CDrawPainterView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawPainterView 诊断

#ifdef _DEBUG
void CDrawPainterView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawPainterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawPainterDoc* CDrawPainterView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawPainterDoc)));
	return (CDrawPainterDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawPainterView 消息处理程序


void CDrawPainterView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*CDC *pDC = GetDC();
	pDC->MoveTo(m_Cpoint);
	pDC->LineTo(point);*/
	m_Bmove = false;
	CView::OnLButtonUp(nFlags, point);
}


void CDrawPainterView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_Cpoint = point;
	m_Bmove = true;
	CView::OnLButtonDown(nFlags, point);
}


void CDrawPainterView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC *pDC = GetDC();
	CPen pen(PS_SOLID, 4, RGB(255, 0, 0));
	pDC->SelectObject(pen);
	if(m_Bmove)
	{
	pDC->MoveTo(m_Cpoint);
	pDC->LineTo(point);

	}
	m_Cpoint = point;
	CView::OnMouseMove(nFlags, point);
}


void CDrawPainterView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC *pDC = GetDC();
	CPen pen(PS_SOLID, 4, RGB(255, 0, 0));
	pDC->SelectObject(pen);
	switch (nChar)
	{
	case VK_RIGHT:
		pDC->MoveTo(m_Cpoint);
		pDC->LineTo(m_Cpoint.x+10,m_Cpoint.y);
		m_Cpoint.x = m_Cpoint.x +10;
		break;
	case VK_LEFT:
		pDC->MoveTo(m_Cpoint);
		pDC->LineTo(m_Cpoint.x - 10, m_Cpoint.y);
		m_Cpoint.x = m_Cpoint.x - 10;
		break;
	case VK_UP:
		pDC->MoveTo(m_Cpoint);
		pDC->LineTo(m_Cpoint.x , m_Cpoint.y-10);
		m_Cpoint.y = m_Cpoint.y - 10;
		break;
	case VK_DOWN:
		pDC->MoveTo(m_Cpoint);
		pDC->LineTo(m_Cpoint.x, m_Cpoint.y + 10);
		m_Cpoint.y = m_Cpoint.y + 10;
		break;
	default:
		break;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


//void CDrawPainterView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	CView::OnKeyUp(nChar, nRepCnt, nFlags);
//}
