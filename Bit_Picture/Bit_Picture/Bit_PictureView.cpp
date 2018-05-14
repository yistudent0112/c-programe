
// Bit_PictureView.cpp : CBit_PictureView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Bit_Picture.h"
#endif

#include "Bit_PictureDoc.h"
#include "Bit_PictureView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBit_PictureView

IMPLEMENT_DYNCREATE(CBit_PictureView, CView)

BEGIN_MESSAGE_MAP(CBit_PictureView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBit_PictureView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CBit_PictureView 构造/析构

CBit_PictureView::CBit_PictureView()
{
	// TODO: 在此处添加构造代码

}

CBit_PictureView::~CBit_PictureView()
{
}

BOOL CBit_PictureView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CBit_PictureView 绘制

void CBit_PictureView::OnDraw(CDC* pDC)
{
	CBit_PictureDoc* pDoc = GetDocument();
	CBitmap bt;
	bt.LoadBitmap(IDB_BITMAP3);
	ASSERT_VALID(pDoc);
	BITMAP bm;
	bt.GetBitmap(&bm);
	int width = bm.bmWidth;
	int height = bm.bmHeight;
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	dc.SelectObject(&bt);
	pDC->StretchBlt(0,0,width,height,&dc, 0, 0, width, height,SRCCOPY );
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CBit_PictureView 打印


void CBit_PictureView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBit_PictureView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CBit_PictureView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CBit_PictureView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CBit_PictureView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBit_PictureView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBit_PictureView 诊断

#ifdef _DEBUG
void CBit_PictureView::AssertValid() const
{
	CView::AssertValid();
}

void CBit_PictureView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBit_PictureDoc* CBit_PictureView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBit_PictureDoc)));
	return (CBit_PictureDoc*)m_pDocument;
}
#endif //_DEBUG


// CBit_PictureView 消息处理程序
