#include "stdafx.h"
#include "Element.h"

IMPLEMENT_SERIAL(CElement, CObject, 0)
void CElement::Draw(CDC * pDC)
{
}
CElement::CElement()
{
}


CElement::~CElement()
{
}

void CElement::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);
}

CElement& CElement::operator = (CElement & ele)
{
	return *this;
}