
// GY_PersonMoveView.cpp : CGY_PersonMoveView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "GY_PersonMove.h"
#endif

#include "GY_PersonMoveDoc.h"
#include "GY_PersonMoveView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGY_PersonMoveView

IMPLEMENT_DYNCREATE(CGY_PersonMoveView, CView)

BEGIN_MESSAGE_MAP(CGY_PersonMoveView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGY_PersonMoveView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CGY_PersonMoveView 构造/析构

CGY_PersonMoveView::CGY_PersonMoveView()
{
	// TODO: 在此处添加构造代码

	m_Cpoint.x = 0;
	m_Cpoint.y = 0;
}

CGY_PersonMoveView::~CGY_PersonMoveView()
{
}

BOOL CGY_PersonMoveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGY_PersonMoveView 绘制

void CGY_PersonMoveView::OnDraw(CDC* pDC)
{
	CGY_PersonMoveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CDC *cDC = this->GetDC();   //获得当前窗口的DC     
	GetClientRect(&m_client);   //获得窗口的尺寸 
	CBitmap btBackground;
	CBitmap btPeople;
	CBitmap btPeople1;
	btBackground.LoadBitmapW(IDB_BITMAPBG);
	btPeople.LoadBitmapW(IDB_BITMAPMAN);
	btPeople1.LoadBitmapW(IDB_BITMAPMAN1);
	BITMAP bm1;
	btBackground.GetBitmap(&bm1);
	BITMAP bm2;
	btPeople.GetBitmap(&bm2);
	BITMAP bm3;
	btPeople1.GetBitmap(&bm3);
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	dc.SelectObject(&btBackground);
 
	if (m_Cpoint.x > m_client.Width())
	{
		m_Cpoint.x = 0;
    }
	if (m_Cpoint.y > m_client.Height())
	{
		m_Cpoint.y = 0;
	}



	
	pDC->BitBlt(0, 0, m_client.Width(),m_client.Height(), &dc, 0, 0, SRCCOPY);
	dc.SelectObject(&btPeople);
	pDC->BitBlt(m_Cpoint.x, m_Cpoint.y, bm2.bmWidth, bm2.bmHeight, &dc, 0, 0, SRCAND);
	dc.SelectObject(&btPeople1);
	pDC->BitBlt(m_Cpoint.x, m_Cpoint.y, bm2.bmWidth, bm2.bmHeight, &dc, 0, 0, SRCPAINT);
	ReleaseDC(cDC);           //释放DC 
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CGY_PersonMoveView 打印


void CGY_PersonMoveView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGY_PersonMoveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGY_PersonMoveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CGY_PersonMoveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CGY_PersonMoveView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGY_PersonMoveView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGY_PersonMoveView 诊断

#ifdef _DEBUG
void CGY_PersonMoveView::AssertValid() const
{
	CView::AssertValid();
}

void CGY_PersonMoveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGY_PersonMoveDoc* CGY_PersonMoveView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGY_PersonMoveDoc)));
	return (CGY_PersonMoveDoc*)m_pDocument;
}
#endif //_DEBUG


// CGY_PersonMoveView 消息处理程序


void CGY_PersonMoveView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nChar)
	{
	case VK_RIGHT:
		m_Cpoint.x = m_Cpoint.x + 10;
		break;
	case VK_LEFT:
		m_Cpoint.x = m_Cpoint.x - 10;
		break;
	case VK_UP:
		m_Cpoint.y = m_Cpoint.y - 10;
		break;
	case VK_DOWN:
		m_Cpoint.y = m_Cpoint.y + 10;
		break;
	default:
		break;
	}
	if (m_Cpoint.x > m_client.Width())
	{
		m_Cpoint.x = 0;
	}
	if (m_Cpoint.y > m_client.Height())
	{
		m_Cpoint.y = 0;
	}
	Invalidate(NULL);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CGY_PersonMoveView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_Cpoint.x = point.x;
	m_Cpoint.y = point.y;
	if (m_Cpoint.x > m_client.Width())
	{
		m_Cpoint.x = 0;
	}
	if (m_Cpoint.y > m_client.Height())
	{
		m_Cpoint.y = 0;
	}
	Invalidate(NULL);
	CView::OnLButtonDblClk(nFlags, point);
}
