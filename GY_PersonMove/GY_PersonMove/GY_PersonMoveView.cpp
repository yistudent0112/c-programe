
// GY_PersonMoveView.cpp : CGY_PersonMoveView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGY_PersonMoveView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CGY_PersonMoveView ����/����

CGY_PersonMoveView::CGY_PersonMoveView()
{
	// TODO: �ڴ˴���ӹ������

	m_Cpoint.x = 0;
	m_Cpoint.y = 0;
}

CGY_PersonMoveView::~CGY_PersonMoveView()
{
}

BOOL CGY_PersonMoveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CGY_PersonMoveView ����

void CGY_PersonMoveView::OnDraw(CDC* pDC)
{
	CGY_PersonMoveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CDC *cDC = this->GetDC();   //��õ�ǰ���ڵ�DC     
	GetClientRect(&m_client);   //��ô��ڵĳߴ� 
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
	ReleaseDC(cDC);           //�ͷ�DC 
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CGY_PersonMoveView ��ӡ


void CGY_PersonMoveView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGY_PersonMoveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CGY_PersonMoveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CGY_PersonMoveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CGY_PersonMoveView ���

#ifdef _DEBUG
void CGY_PersonMoveView::AssertValid() const
{
	CView::AssertValid();
}

void CGY_PersonMoveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGY_PersonMoveDoc* CGY_PersonMoveView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGY_PersonMoveDoc)));
	return (CGY_PersonMoveDoc*)m_pDocument;
}
#endif //_DEBUG


// CGY_PersonMoveView ��Ϣ�������


void CGY_PersonMoveView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
