#pragma once
#include "Element.h"
#include"Point2D.h"
class CArbitrary_Painting :
	public CElement
{
	DECLARE_SERIAL(CArbitrary_Painting)
public:
	CArbitrary_Painting();
	
	CArbitrary_Painting(CPoint2D & pt0, CPoint2D & pt1);
	virtual ~CArbitrary_Painting();

	virtual void Serialize(CArchive &ar);

	virtual void Draw(CDC *pDC);
	CPoint2D m_pt0;
	CPoint2D m_pt1;
};

