
// AnimationView.cpp : CAnimationView 类的实现
//

#include "stdafx.h"
#include"resource.h"
#include<iostream>
using namespace std;
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Animation.h"
#endif

#include "AnimationDoc.h"
#include "AnimationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAnimationView

IMPLEMENT_DYNCREATE(CAnimationView, CView)

BEGIN_MESSAGE_MAP(CAnimationView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CAnimationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CAnimationView 构造/析构

CAnimationView::CAnimationView()
	: m_IC_x(0)
	, m_IC_y(0)
	, i(0)
{
	// TODO: 在此处添加构造代码
	m_IC_x = 0;
	m_IC_y = 0;
	//不能在构造函数定义定时器是因为此时还没有生成界面，没有定时器
	//SetTimer(1, 1000, NULL);
}

CAnimationView::~CAnimationView()
{
}

BOOL CAnimationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CAnimationView 绘制

void CAnimationView::OnDraw(CDC* pDC)
{
	CAnimationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//pDC->Ellipse(m_IC_x, m_IC_y, 100+m_IC_x, 100+m_IC_y);
	bt.LoadBitmap(bitmap->GetBitmap);
	//bt.LoadBitmap(IDB_BITMAP3);
	ASSERT_VALID(pDoc);
	BITMAP bm;
	bt.GetBitmap(&bm);
	int width = bm.bmWidth;
	int height = bm.bmHeight;
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	dc.SelectObject(&bt);
	pDC->StretchBlt(0, 0, width, height, &dc, 0, 0, width, height, SRCCOPY);
	// TODO: 在此处为本机数据添加绘制代码
}


// CAnimationView 打印


void CAnimationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CAnimationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CAnimationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CAnimationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CAnimationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAnimationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CAnimationView 诊断

#ifdef _DEBUG
void CAnimationView::AssertValid() const
{
	CView::AssertValid();
}

void CAnimationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAnimationDoc* CAnimationView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAnimationDoc)));
	return (CAnimationDoc*)m_pDocument;
}
#endif //_DEBUG


// CAnimationView 消息处理程序


void CAnimationView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CAnimationDoc* pDoc = GetDocument();
	switch (nIDEvent)
	{
	case 1:
		m_IC_x++;
		m_IC_y++;
	
		pDoc->UpdateAllViews(NULL);
		if (m_IC_x > 1000)
		{
			KillTimer(1);
			break;
		}
		break;
	case 2:
	
		//bt.LoadBitmap(bitmap[i++]);
		i++;
		if (i > 35) 
		{
			KillTimer(2);
			break;
		}
		pDoc->UpdateAllViews(NULL);
		break;

     default:
		//pDoc = GetDocument();
		break;
		
	}
	CView::OnTimer(nIDEvent);
}


void CAnimationView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	KillTimer(1);
	CView::OnRButtonDown(nFlags, point);
}


void CAnimationView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//SetTimer(1, 500, NULL);
	CView::OnLButtonDown(nFlags, point);
}


void CAnimationView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	SetTimer(1, 1000, NULL);
	SetTimer(2, 80, NULL);
	bitmap = new CBitmap[35];
	bitmap[0].LoadBitmap(IDB_BITMAP1);
	bitmap[1].LoadBitmap(IDB_BITMAP2);
	bitmap[2].LoadBitmap(IDB_BITMAP3);
	bitmap[3].LoadBitmap(IDB_BITMAP4);
	bitmap[4].LoadBitmap(IDB_BITMAP5);
	bitmap[5].LoadBitmap(IDB_BITMAP6);
	bitmap[6].LoadBitmap(IDB_BITMAP7);
	bitmap[7].LoadBitmap(IDB_BITMAP8);
	bitmap[8].LoadBitmap(IDB_BITMAP9);
	bitmap[9].LoadBitmap(IDB_BITMAP10);
	bitmap[10].LoadBitmap(IDB_BITMAP11);
	bitmap[11].LoadBitmap(IDB_BITMAP12);
	bitmap[12].LoadBitmap(IDB_BITMAP13);
	bitmap[13].LoadBitmap(IDB_BITMAP14);
	bitmap[14].LoadBitmap(IDB_BITMAP15);
	bitmap[15].LoadBitmap(IDB_BITMAP16);
	bitmap[16].LoadBitmap(IDB_BITMAP17);
	bitmap[17].LoadBitmap(IDB_BITMAP18);
	bitmap[18].LoadBitmap(IDB_BITMAP19);
	bitmap[19].LoadBitmap(IDB_BITMAP20);
	bitmap[20].LoadBitmap(IDB_BITMAP21);
	bitmap[21].LoadBitmap(IDB_BITMAP22);
    bitmap[22].LoadBitmap(IDB_BITMAP23);
	bitmap[23].LoadBitmap(IDB_BITMAP24);
	bitmap[24].LoadBitmap(IDB_BITMAP25);
	bitmap[25].LoadBitmap(IDB_BITMAP26);
	bitmap[26].LoadBitmap(IDB_BITMAP27);
	bitmap[27].LoadBitmap(IDB_BITMAP28);
	bitmap[28].LoadBitmap(IDB_BITMAP29);
	bitmap[29].LoadBitmap(IDB_BITMAP30);
	bitmap[30].LoadBitmap(IDB_BITMAP31);
	bitmap[31].LoadBitmap(IDB_BITMAP32);
	bitmap[32].LoadBitmap(IDB_BITMAP33);
	bitmap[33].LoadBitmap(IDB_BITMAP34);
	bitmap[34].LoadBitmap(IDB_BITMAP35);
	// TODO: 在此添加专用代码和/或调用基类
}
