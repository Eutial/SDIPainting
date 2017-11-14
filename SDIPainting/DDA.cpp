// DDA.cpp : implementation file
//

#include "stdafx.h"
#include "SDIPainting.h"
#include "DDA.h"
#include "afxdialogex.h"


// CDDA dialog

IMPLEMENT_DYNAMIC(CDDA, CDialog)

CDDA::CDDA(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DDA, pParent)
{

}

CDDA::~CDDA()
{
}

void CDDA::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDDA, CDialog)
END_MESSAGE_MAP()


// CDDA message handlers
