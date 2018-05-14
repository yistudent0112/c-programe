
// yi_coinsView.cpp : Cyi_coinsView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "yi_coins.h"
#endif

#include "yi_coinsDoc.h"
#include "yi_coinsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cyi_coinsView

IMPLEMENT_DYNCREATE(Cyi_coinsView, CView)

BEGIN_MESSAGE_MAP(Cyi_coinsView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cyi_coinsView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// Cyi_coinsView 构造/析构

Cyi_coinsView::Cyi_coinsView()
{
	// TODO: 在此处添加构造代码

}

Cyi_coinsView::~Cyi_coinsView()
{
}

BOOL Cyi_coinsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cyi_coinsView 绘制

void Cyi_coinsView::OnDraw(CDC* pDC)
{
	Cyi_coinsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CString str;
	str.Format(_T("Coin Number : %d"), pDoc->m_ICoin);
	//MessageBox(_T("Coin Number : %d"), pDoc->m_ICoin);
	pDC->TextOut(100,300,str);
	if (pDoc->m_ICoin >0)
	{
		pDC->Ellipse(100, 200, 200, 250);
		for (int i = 1; i <= pDoc->m_ICoin; i++)
		{
			pDC->Ellipse(100, 200 - 10 * i, 200, 250 - 10 * i);
		}
	}
	//pDoc->UpdateAllViews(NULL);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
}


// Cyi_coinsView 打印


void Cyi_coinsView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cyi_coinsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cyi_coinsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cyi_coinsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void Cyi_coinsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cyi_coinsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cyi_coinsView 诊断

#ifdef _DEBUG
void Cyi_coinsView::AssertValid() const
{
	CView::AssertValid();
}

void Cyi_coinsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cyi_coinsDoc* Cyi_coinsView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cyi_coinsDoc)));
	return (Cyi_coinsDoc*)m_pDocument;
}
#endif //_DEBUG


// Cyi_coinsView 消息处理程序


void Cyi_coinsView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cyi_coinsDoc* pDoc = GetDocument();
	pDoc->m_ICoin++;
	pDoc->UpdateAllViews(NULL);
	CView::OnRButtonDown(nFlags, point);
}


void Cyi_coinsView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cyi_coinsDoc* pDoc = GetDocument();
	pDoc->m_ICoin--;
	//pDoc->UpdateAllViews(NULL);
	Invalidate(TRUE);
	CView::OnLButtonDown(nFlags, point);
}


void Cyi_coinsView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cyi_coinsDoc* pDoc = GetDocument();
	switch (nChar)
	{
	case VK_UP:
		pDoc->m_ICoin++;
		break;
	case VK_DOWN:
		pDoc->m_ICoin--;
		if (pDoc->m_ICoin < 0) {
			pDoc->m_ICoin = 0;
		}
	default:
		break;
	}
	Invalidate(TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
