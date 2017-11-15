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
	, DDA_x1(0)
	, DDA_y1(0)
	, DDA_x2(0)
	, DDA_y2(0)
{

}

CDDA::~CDDA()
{
}

void CDDA::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DDA_x1, DDA_x1);
	DDV_MinMaxInt(pDX, DDA_x1, 0, 999);
	DDX_Text(pDX, IDC_DDA_y1, DDA_y1);
	DDV_MinMaxInt(pDX, DDA_y1, 0, 999);
	DDX_Text(pDX, IDC_DDA_x2, DDA_x2);
	DDV_MinMaxInt(pDX, DDA_x2, 0, 999);
	DDX_Text(pDX, IDC_DDA_y2, DDA_y2);
	DDV_MinMaxInt(pDX, DDA_y2, 0, 999);
}


BEGIN_MESSAGE_MAP(CDDA, CDialog)
END_MESSAGE_MAP()


// CDDA message handlers
