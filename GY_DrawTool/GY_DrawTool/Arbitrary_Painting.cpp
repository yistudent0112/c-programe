#include "stdafx.h"
#include "Arbitrary_Painting.h"
IMPLEMENT_SERIAL(CArbitrary_Painting, CElement, 0)
CArbitrary_Painting::CArbitrary_Painting()
{
	m_pt0 = CPoint2D(0.0, 0.0);
	m_pt1 = CPoint2D(0.0, 0.0);
}


CArbitrary_Painting::CArbitrary_Painting(CPoint2D & pt0, CPoint2D & pt1)
{
	m_pt0 = pt0;
	m_pt1 = pt1;
}

CArbitrary_Painting::~CArbitrary_Painting()
{
}

void CArbitrary_Painting::Serialize(CArchive & ar)
{
	CElement::Serialize(ar);
	m_pt0.Serialize(ar);
	m_pt1.Serialize(ar);
}

void CArbitrary_Painting::Draw(CDC * pDC)
{
	m_pt0.Draw(pDC);
	pDC->MoveTo(m_pt0.m_dX, m_pt0.m_dY);
	pDC->LineTo(m_pt1.m_dX, m_pt1.m_dY);
	m_pt1.Draw(pDC);
}

void CArbitrary_Painting::UpdatePoint(CPoint2D point)
{
	m_pt0 = point;
}
