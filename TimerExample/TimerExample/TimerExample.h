
// TimerExample.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTimerExampleApp: 
// �йش����ʵ�֣������ TimerExample.cpp
//

class CTimerExampleApp : public CWinApp
{
public:
	CTimerExampleApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTimerExampleApp theApp;