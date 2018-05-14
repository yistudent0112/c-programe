
// DrawPainterView.cpp : CDrawPainterView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CDrawPainterView ����/����

CDrawPainterView::CDrawPainterView()
	: m_Cpoint(0)
	, m_Bmove(false)
{
	// TODO: �ڴ˴���ӹ������

}

CDrawPainterView::~CDrawPainterView()
{
}

BOOL CDrawPainterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDrawPainterView ����

void CDrawPainterView::OnDraw(CDC* /*pDC*/)
{
	CDrawPainterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDrawPainterView ��ӡ


void CDrawPainterView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawPainterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDrawPainterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDrawPainterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CDrawPainterView ���

#ifdef _DEBUG
void CDrawPainterView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawPainterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawPainterDoc* CDrawPainterView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawPainterDoc)));
	return (CDrawPainterDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawPainterView ��Ϣ�������


void CDrawPainterView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*CDC *pDC = GetDC();
	pDC->MoveTo(m_Cpoint);
	pDC->LineTo(point);*/
	m_Bmove = false;
	CView::OnLButtonUp(nFlags, point);
}


void CDrawPainterView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_Cpoint = point;
	m_Bmove = true;
	CView::OnLButtonDown(nFlags, point);
}


void CDrawPainterView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	CView::OnKeyUp(nChar, nRepCnt, nFlags);
//}
