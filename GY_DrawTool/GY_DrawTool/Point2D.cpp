#include "stdafx.h"
#include "Point2D.h"

IMPLEMENT_SERIAL(CPoint2D, CElement, 0)

CPoint2D::CPoint2D()
{
	m_dX = m_dY = 0.0;
}
CPoint2D::CPoint2D(double dX, double dY)
{
	m_dX = dX;
	m_dY = dY;
}
void CPoint2D::Draw(CDC *pDC)
{
	if (pDC != NULL)
	{
		pDC->Ellipse(m_dX - 3, m_dY - 3, m_dX + 3, m_dY + 3);
		cout << "point success" << endl;
	}
}
void CPoint2D::Serialize(CArchive &ar)
{
	CElement::Serialize(ar);
	if (ar.IsStoring()) {
		ar << m_dX;
		ar << m_dY;
	}
	else {
		ar >> m_dX;
		ar >> m_dY;
	}
}
CPoint2D& CPoint2D::operator = (CPoint2D& pt)
{
	CElement::operator = (pt);
	m_dX = pt.m_dX;
	m_dY = pt.m_dY;
	return *this;
}

CPoint2D::~CPoint2D()
{
}
