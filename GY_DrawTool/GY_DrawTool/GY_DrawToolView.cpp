
// GY_DrawToolView.cpp : CGY_DrawToolView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "GY_DrawTool.h"
#endif

#include "GY_DrawToolDoc.h"
#include "GY_DrawToolView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGY_DrawToolView

IMPLEMENT_DYNCREATE(CGY_DrawToolView, CView)

BEGIN_MESSAGE_MAP(CGY_DrawToolView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGY_DrawToolView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_Point2D, &CGY_DrawToolView::OnPoint2d)
	ON_COMMAND(ID_Undo, &CGY_DrawToolView::OnUndo)
	ON_COMMAND(ID_Redo, &CGY_DrawToolView::OnRedo)
	ON_COMMAND(ID_Openex, &CGY_DrawToolView::OnOpenex)
	ON_COMMAND(ID_Saveex, &CGY_DrawToolView::OnSaveex)
	ON_COMMAND(ID_Newex, &CGY_DrawToolView::OnNewex)
	ON_COMMAND(ID_Line, &CGY_DrawToolView::OnLine)
	//ON_UPDATE_COMMAND_UI(ID_Point2D, &CGY_DrawToolView::OnUpdatePoint2d)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_Arbitrary_painting, &CGY_DrawToolView::OnArbitraryPainting)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CGY_DrawToolView ����/����

CGY_DrawToolView::CGY_DrawToolView()
{
	// TODO: �ڴ˴���ӹ������
	m_nEleKind = -1;
	m_nMouseDown = 0;
	m_Move = false;
}

void CGY_DrawToolView::SerializeEx(CArchive & ar)
{
	m_listOfEle.Serialize(ar);
}

CGY_DrawToolView::~CGY_DrawToolView()
{
	while (!m_listOfEle.IsEmpty())
	{
		delete m_listOfEle.RemoveTail();
	}
	while (!m_listOfUndoEle.IsEmpty())
	{
		delete m_listOfUndoEle.RemoveTail();
	}
}

BOOL CGY_DrawToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CGY_DrawToolView ����

void CGY_DrawToolView::OnDraw(CDC* pDC)
{
	CGY_DrawToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	POSITION pos = m_listOfEle.GetHeadPosition();
	CElement *pEle;
	while (pos) {
		pEle = (CElement*)m_listOfEle.GetNext(pos);
		pEle->Draw(pDC);
		// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	}
}


// CGY_DrawToolView ��ӡ


void CGY_DrawToolView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGY_DrawToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CGY_DrawToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CGY_DrawToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CGY_DrawToolView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGY_DrawToolView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGY_DrawToolView ���

#ifdef _DEBUG
void CGY_DrawToolView::AssertValid() const
{
	CView::AssertValid();
}

void CGY_DrawToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGY_DrawToolDoc* CGY_DrawToolView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGY_DrawToolDoc)));
	return (CGY_DrawToolDoc*)m_pDocument;
}


#endif //_DEBUG


// CGY_DrawToolView ��Ϣ�������


//void CGY_DrawToolView::OnPoint2D()
//{
//	m_nEleKind = 0;
//}


//void CGY_DrawToolView::OnLine()
//{
//	m_nEleKind = 1;
//}


//void CGY_DrawToolView::OnPoint2d()
//{
//	// TODO: �ڴ���������������
//}


void CGY_DrawToolView::OnUndo()
{
	// TODO: �ڴ���������������
	if (m_listOfEle.IsEmpty())
		return;
	m_listOfUndoEle.AddTail(m_listOfEle.RemoveTail());
	this->Invalidate();
}


void CGY_DrawToolView::OnRedo()
{
	// TODO: �ڴ���������������
	if (m_listOfUndoEle.IsEmpty())
		return;
	m_listOfEle.AddTail(m_listOfUndoEle.RemoveTail());
	this->Invalidate();
}


void CGY_DrawToolView::OnOpenex()
{
	// TODO: �ڴ���������������
	/*
	CFile file;
	if (file.Open((LPCTSTR)"f:\\1.dat", CFile::modeRead) == TRUE)
	{
		CArchive ar(&file, CArchive::load);
		SerializeEx(ar);
		ar.Close();
		file.Close();
	}
	*/
	// TODO: �ڴ���������������  
	char szFilters[] =
		"Dat File(*.dat)\0*.dat\0"\
		"Text File(*.txt)\0*.txt\0"\
		"All Typle(*.*)\0*.*\0" \
		"\0";

	CFileDialog OpenDlg(TRUE);
	OpenDlg.m_ofn.lpstrTitle = _T ("Open File");
	OpenDlg.m_ofn.lpstrFilter = _T(szFilters);

	if (IDOK == OpenDlg.DoModal())
	{
		CFile File;
		CFileException e;
		//�����ļ���ͬʱ�����쳣����  
		if (!File.Open(OpenDlg.GetPathName(), CFile::modeRead, &e))
		{
			CString strErr;
			strErr.Format(_T("File could not be opened %d\n"), e.m_cause);
			MessageBox(strErr);
		}
		//����ָ����С��Buffer  
		DWORD  dwFileLenth = (DWORD)File.GetLength();
		//��ʼ��buffer�� ����һ��/0�ռ�  
		char *pBuf = new char[dwFileLenth + 1];
		memset(pBuf, 0, dwFileLenth + 1);

		if (pBuf != NULL)
		{
			//��ȡ�ļ�����  
			File.Read(pBuf, dwFileLenth);
			File.Close();
			//��ʾ�ļ�����  
			MessageBox(_T(pBuf));
			//ɾ��bufer�������ڴ�й©  
			delete[] pBuf;
			pBuf = NULL;
		}
	}
	this->Invalidate();
}


void CGY_DrawToolView::OnSaveex()
{
	// TODO: �ڴ���������������
	/*
	CFile file;
	if (file.Open((LPCTSTR)"f:\\1.dat", CFile::modeWrite | CFile::modeCreate) == TRUE)
	{
		CArchive ar(&file, CArchive::store);
		SerializeEx(ar);
		ar.Close();
		file.Close();
	}
	*/
	//��ʽ������������������ʾ���ã�+ \0 + �ļ���չ���ƣ��������ã�  
	//�����չ����֮���ã�;���ָ������������ַ���֮����\0�ָ�  
	//���Ĺ�������Ҫ������\0\0��β  
	char szFilters[] =
		"Dat File(*.dat)\0*.dat\0" \
		"Text File(*.txt)\0*.txt\0" \
		"All Typle(*.*)\0*.*\0" \
		"\0";
	//������������Ĭ�Ϲ��������ֵ��������£�  
	//ʹ�ù��캯���޸ĶԻ����ʼ״̬���ܸ��ã���������϶�  
	CFileDialog FileDlg(FALSE, _T("dat"), _T("Test"));
	FileDlg.m_ofn.lpstrTitle = _T("Save File");
	FileDlg.m_ofn.lpstrFilter = _T(szFilters);

	//ͨ���������������޸ĶԻ����ʼ״̬����������ʹ��Ĭ�Ϲ�����ʽ����  
	//������VS2008������+Wind7ϵͳ  
	//FileDlg.m_ofn.lpstrDefExt = "txt";  
	//FileDlg.m_ofn.lpstrFile = "test";  

	if (IDOK == FileDlg.DoModal())
	{
		CFile File(FileDlg.GetPathName(), CFile::modeCreate | CFile::modeReadWrite);

		char szBufData[100] = { "��ϲ��ɹ���" };
		//д���ļ�����,������/0  
		File.Write(szBufData, strlen(szBufData));
		//����д�룬������  
		File.Flush();
		//�ļ����������ر�  
		File.Close();
	}
}


void CGY_DrawToolView::OnNewex()
{
	// TODO: �ڴ���������������
	while (!m_listOfEle.IsEmpty())
		delete m_listOfEle.RemoveTail();
	while (!m_listOfUndoEle.IsEmpty())
		delete m_listOfUndoEle.RemoveTail();
	this->Invalidate();
}


void CGY_DrawToolView::OnLine()
{
	m_nEleKind = 1;
	// TODO: �ڴ���������������
}


void CGY_DrawToolView::OnPoint2d()
{
	m_nEleKind = 0;
	// TODO: �ڴ������������û����洦��������
}


void CGY_DrawToolView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_nEleKind == 0) {
		CPoint2D *pPt = new CPoint2D(point.x, point.y);
		CDC *pDC = this->GetDC();
		pPt->Draw(pDC);
		this->ReleaseDC(pDC);
		m_listOfEle.AddTail(pPt);
		//		m_nEleKind = -1;
	}
	else if (m_nEleKind == 1) {
		m_nMouseDown++;
		if (m_nMouseDown == 1) {
			m_pt0 = CPoint2D(point.x, point.y);
			CDC *pDC = this->GetDC();
			m_pt0.Draw(pDC);
			this->ReleaseDC(pDC);
		}
		else {
			m_pt1 = CPoint2D(point.x, point.y);
			CLine *pLine = new CLine(m_pt0, m_pt1);
			CDC *pDC = this->GetDC();
			m_pt1.Draw(pDC);
			pLine->Draw(pDC);
			this->ReleaseDC(pDC);
			m_listOfEle.AddTail(pLine);
			m_nMouseDown = 0;
		}
	}
	if (m_nEleKind = 2) {
		m_Move = true;
		m_pt0 = CPoint2D(point.x, point.y);
		/*
		m_nMouseDown++;
		if (m_nMouseDown == 1) {
			m_pt0 = CPoint2D(point.x, point.y);
			CDC *pDC = this->GetDC();
			m_pt0.Draw(pDC);
			this->ReleaseDC(pDC);
		}
		else {
			m_pt1 = CPoint2D(point.x, point.y);
			CArbitrary_Painting *Arbitrary = new CArbitrary_Painting(m_pt0, m_pt1);
			CDC *pDC = this->GetDC();
			m_pt1.Draw(pDC);
			Arbitrary->Draw(pDC);
			this->ReleaseDC(pDC);
			m_listOfEle.AddTail(Arbitrary);
			m_nMouseDown = 0;
		}*/
	}
	CView::OnLButtonDown(nFlags, point);
}


void CGY_DrawToolView::OnArbitraryPainting()
{
	m_nEleKind = 2;
	// TODO: �ڴ���������������
}


void CGY_DrawToolView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_Move = false;
	CView::OnLButtonUp(nFlags, point);
}


void CGY_DrawToolView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_Move) {
		if (m_nEleKind == 2) {
			m_nMouseDown++;
			if (m_nMouseDown %2== 1) {
				m_pt0 = CPoint2D(point.x, point.y);
				CDC *pDC = this->GetDC();
				m_pt0.Draw(pDC);
				this->ReleaseDC(pDC);
			}
			else {
				m_pt1 = CPoint2D(point.x, point.y);
				CArbitrary_Painting *Arbitrary = new CArbitrary_Painting(m_pt0, m_pt1);
				CDC *pDC = this->GetDC();
				m_pt1.Draw(pDC);
				Arbitrary->Draw(pDC);
				m_pt0 = CPoint2D(point.x, point.y);
				//Arbitrary->UpdatePoint(m_pt0);
				this->ReleaseDC(pDC);
				m_listOfEle.AddTail(Arbitrary);
				//m_nMouseDown = 0;
				m_nMouseDown++;
			}
		}
		else {
			return;
		}
	}
	CView::OnMouseMove(nFlags, point);
}
