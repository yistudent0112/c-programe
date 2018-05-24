#include "stdafx.h"
#include "Line.h"


IMPLEMENT_SERIAL(CLine, CElement, 0)

CLine::CLine()
{
	m_pt0 = CPoint2D(0.0, 0.0);
	m_pt1 = CPoint2D(0.0, 0.0);
}
CLine::CLine(CPoint2D& pt0, CPoint2D& pt1)
{
	m_pt0 = pt0;
	m_pt1 = pt1;
}
CLine::~CLine()
{
}
void CLine::Draw(CDC *pDC)
{
	m_pt0.Draw(pDC);
	pDC->MoveTo(m_pt0.m_dX, m_pt0.m_dY);
	pDC->LineTo(m_pt1.m_dX, m_pt1.m_dY);
	m_pt1.Draw(pDC);
}
void CLine::Serialize(CArchive &ar)
{
	CElement::Serialize(ar);
	m_pt0.Serialize(ar);
	m_pt1.Serialize(ar);
}
