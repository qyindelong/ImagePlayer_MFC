
// ImagePlayer_MFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CImagePlayer_MFCApp:
// �йش����ʵ�֣������ ImagePlayer_MFC.cpp
//

class CImagePlayer_MFCApp : public CWinApp
{
public:
	CImagePlayer_MFCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CImagePlayer_MFCApp theApp;