#pragma once
#include "Element.h"
#include "Point2D.h"
class CLine : public CElement
{
	DECLARE_SERIAL(CLine)
public:
	CLine();
	CLine(CPoint2D & pt0, CPoint2D & pt1);
	virtual ~CLine();

	virtual void Serialize(CArchive &ar);

	virtual void Draw(CDC *pDC);
	CPoint2D m_pt0;
	CPoint2D m_pt1;
};

