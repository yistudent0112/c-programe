
// yi_coinsView.cpp : Cyi_coinsView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cyi_coinsView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// Cyi_coinsView ����/����

Cyi_coinsView::Cyi_coinsView()
{
	// TODO: �ڴ˴���ӹ������

}

Cyi_coinsView::~Cyi_coinsView()
{
}

BOOL Cyi_coinsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cyi_coinsView ����

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
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cyi_coinsView ��ӡ


void Cyi_coinsView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cyi_coinsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cyi_coinsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cyi_coinsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// Cyi_coinsView ���

#ifdef _DEBUG
void Cyi_coinsView::AssertValid() const
{
	CView::AssertValid();
}

void Cyi_coinsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cyi_coinsDoc* Cyi_coinsView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cyi_coinsDoc)));
	return (Cyi_coinsDoc*)m_pDocument;
}
#endif //_DEBUG


// Cyi_coinsView ��Ϣ�������


void Cyi_coinsView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cyi_coinsDoc* pDoc = GetDocument();
	pDoc->m_ICoin++;
	pDoc->UpdateAllViews(NULL);
	CView::OnRButtonDown(nFlags, point);
}


void Cyi_coinsView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cyi_coinsDoc* pDoc = GetDocument();
	pDoc->m_ICoin--;
	//pDoc->UpdateAllViews(NULL);
	Invalidate(TRUE);
	CView::OnLButtonDown(nFlags, point);
}


void Cyi_coinsView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
