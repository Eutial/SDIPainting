
// SDIPainting.h : main header file for the SDIPainting application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSDIPaintingApp:
// See SDIPainting.cpp for the implementation of this class
//

class CSDIPaintingApp : public CWinAppEx
{
public:
	CSDIPaintingApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDIPaintingApp theApp;
