// MPL.cpp : implementation file
//

#include "stdafx.h"
#include "SDIPainting.h"
#include "MPL.h"
#include "afxdialogex.h"


// CMPL dialog

IMPLEMENT_DYNAMIC(CMPL, CDialog)

CMPL::CMPL(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MidPointLine, pParent)
	, MPL_x1(0)
	, MPL_y1(0)
	, MPL_x2(0)
	, MPL_y2(0)
{

}

CMPL::~CMPL()
{
}

void CMPL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MPL_x1, MPL_x1);
	DDV_MinMaxInt(pDX, MPL_x1, 0, 999);
	DDX_Text(pDX, IDC_MPL_y1, MPL_y1);
	DDV_MinMaxInt(pDX, MPL_y1, 0, 999);
	DDX_Text(pDX, IDC_MPL_x2, MPL_x2);
	DDV_MinMaxInt(pDX, MPL_x2, 0, 999);
	DDX_Text(pDX, IDC_MPL_y2, MPL_y2);
	DDV_MinMaxInt(pDX, MPL_y2, 0, 999);
}


BEGIN_MESSAGE_MAP(CMPL, CDialog)
END_MESSAGE_MAP()


// CMPL message handlers
