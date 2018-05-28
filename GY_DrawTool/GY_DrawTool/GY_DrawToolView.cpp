
// GY_DrawToolView.cpp : CGY_DrawToolView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CGY_DrawToolView 构造/析构

CGY_DrawToolView::CGY_DrawToolView()
{
	// TODO: 在此处添加构造代码
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGY_DrawToolView 绘制

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
		// TODO: 在此处为本机数据添加绘制代码
	}
}


// CGY_DrawToolView 打印


void CGY_DrawToolView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGY_DrawToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGY_DrawToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CGY_DrawToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CGY_DrawToolView 诊断

#ifdef _DEBUG
void CGY_DrawToolView::AssertValid() const
{
	CView::AssertValid();
}

void CGY_DrawToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGY_DrawToolDoc* CGY_DrawToolView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGY_DrawToolDoc)));
	return (CGY_DrawToolDoc*)m_pDocument;
}


#endif //_DEBUG


// CGY_DrawToolView 消息处理程序


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
//	// TODO: 在此添加命令处理程序代码
//}


void CGY_DrawToolView::OnUndo()
{
	// TODO: 在此添加命令处理程序代码
	if (m_listOfEle.IsEmpty())
		return;
	m_listOfUndoEle.AddTail(m_listOfEle.RemoveTail());
	this->Invalidate();
}


void CGY_DrawToolView::OnRedo()
{
	// TODO: 在此添加命令处理程序代码
	if (m_listOfUndoEle.IsEmpty())
		return;
	m_listOfEle.AddTail(m_listOfUndoEle.RemoveTail());
	this->Invalidate();
}


void CGY_DrawToolView::OnOpenex()
{
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加命令处理程序代码  
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
		//构造文件，同时增加异常处理  
		if (!File.Open(OpenDlg.GetPathName(), CFile::modeRead, &e))
		{
			CString strErr;
			strErr.Format(_T("File could not be opened %d\n"), e.m_cause);
			MessageBox(strErr);
		}
		//创建指定大小的Buffer  
		DWORD  dwFileLenth = (DWORD)File.GetLength();
		//初始化buffer， 增加一个/0空间  
		char *pBuf = new char[dwFileLenth + 1];
		memset(pBuf, 0, dwFileLenth + 1);

		if (pBuf != NULL)
		{
			//读取文件内容  
			File.Read(pBuf, dwFileLenth);
			File.Close();
			//显示文件内容  
			MessageBox(_T(pBuf));
			//删除bufer，避免内存泄漏  
			delete[] pBuf;
			pBuf = NULL;
		}
	}
	this->Invalidate();
}


void CGY_DrawToolView::OnSaveex()
{
	// TODO: 在此添加命令处理程序代码
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
	//格式：过滤器描述符（显示作用）+ \0 + 文件扩展名称（过滤作用）  
	//多个扩展名称之间用（;）分隔，两个过滤字符串之间以\0分隔  
	//最后的过滤器需要以两个\0\0结尾  
	char szFilters[] =
		"Dat File(*.dat)\0*.dat\0" \
		"Text File(*.txt)\0*.txt\0" \
		"All Typle(*.*)\0*.*\0" \
		"\0";
	//当过滤器或者默认构造参数赋值较少情况下，  
	//使用构造函数修改对话框初始状态可能更好，这过滤器较多  
	CFileDialog FileDlg(FALSE, _T("dat"), _T("Test"));
	FileDlg.m_ofn.lpstrTitle = _T("Save File");
	FileDlg.m_ofn.lpstrFilter = _T(szFilters);

	//通过以下两个参数修改对话框初始状态，程序奔溃，使用默认构造形式正常  
	//环境：VS2008编译器+Wind7系统  
	//FileDlg.m_ofn.lpstrDefExt = "txt";  
	//FileDlg.m_ofn.lpstrFile = "test";  

	if (IDOK == FileDlg.DoModal())
	{
		CFile File(FileDlg.GetPathName(), CFile::modeCreate | CFile::modeReadWrite);

		char szBufData[100] = { "恭喜你成功打开" };
		//写入文件内容,不包含/0  
		File.Write(szBufData, strlen(szBufData));
		//立即写入，不缓冲  
		File.Flush();
		//文件操作结束关闭  
		File.Close();
	}
}


void CGY_DrawToolView::OnNewex()
{
	// TODO: 在此添加命令处理程序代码
	while (!m_listOfEle.IsEmpty())
		delete m_listOfEle.RemoveTail();
	while (!m_listOfUndoEle.IsEmpty())
		delete m_listOfUndoEle.RemoveTail();
	this->Invalidate();
}


void CGY_DrawToolView::OnLine()
{
	m_nEleKind = 1;
	// TODO: 在此添加命令处理程序代码
}


void CGY_DrawToolView::OnPoint2d()
{
	m_nEleKind = 0;
	// TODO: 在此添加命令更新用户界面处理程序代码
}


void CGY_DrawToolView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加命令处理程序代码
}


void CGY_DrawToolView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_Move = false;
	CView::OnLButtonUp(nFlags, point);
}


void CGY_DrawToolView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
