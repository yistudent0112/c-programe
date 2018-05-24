#pragma once
#include "afx.h"
#include<iostream>
using namespace std;
class CElement :
	public CObject
{
	DECLARE_SERIAL(CElement);
public:
	virtual void Draw(CDC *pDC);
	CElement();
	virtual ~CElement();
	CElement& operator=(CElement &ele);
	virtual void Serialize(CArchive &ar);
};

