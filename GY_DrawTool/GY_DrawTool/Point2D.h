#pragma once
#include "Element.h"

class CPoint2D :
	public CElement
{
	DECLARE_SERIAL(CPoint2D)
public:
	CPoint2D();
	CPoint2D(double dX, double dY);
	virtual ~CPoint2D();
	CPoint2D& operator = (CPoint2D& pt);
	virtual void Serialize(CArchive &ar);
	virtual void Draw(CDC* pDC);
	double m_dX;
	double m_dY;
};

