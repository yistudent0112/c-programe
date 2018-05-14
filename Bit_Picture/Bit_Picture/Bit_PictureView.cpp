
// Bit_PictureView.cpp : CBit_PictureView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBit_PictureView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CBit_PictureView ����/����

CBit_PictureView::CBit_PictureView()
{
	// TODO: �ڴ˴���ӹ������

}

CBit_PictureView::~CBit_PictureView()
{
}

BOOL CBit_PictureView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CBit_PictureView ����

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

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CBit_PictureView ��ӡ


void CBit_PictureView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBit_PictureView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CBit_PictureView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CBit_PictureView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CBit_PictureView ���

#ifdef _DEBUG
void CBit_PictureView::AssertValid() const
{
	CView::AssertValid();
}

void CBit_PictureView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBit_PictureDoc* CBit_PictureView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBit_PictureDoc)));
	return (CBit_PictureDoc*)m_pDocument;
}
#endif //_DEBUG


// CBit_PictureView ��Ϣ�������
