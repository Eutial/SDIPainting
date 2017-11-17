// SLF.cpp : implementation file
//

#include "stdafx.h"
#include "SDIPainting.h"
#include "SLF.h"
#include "afxdialogex.h"


// CSLF dialog

IMPLEMENT_DYNAMIC(CSLF, CDialog)

CSLF::CSLF(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ScanLineFilling, pParent)
	, SLF_x1(0)
	, SLF_x2(0)
	, SLF_x3(0)
	, SLF_x4(0)
	, SLF_x5(0)
	, SLF_y1(0)
	, SLF_y2(0)
	, SLF_y3(0)
	, SLF_y4(0)
	, SLF_y5(0)
{

}

CSLF::~CSLF()
{
}

void CSLF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SLF_x1, SLF_x1);
	DDV_MinMaxInt(pDX, SLF_x1, 0, 999);
	DDX_Text(pDX, IDC_SLF_x2, SLF_x2);
	DDV_MinMaxInt(pDX, SLF_x2, 0, 999);
	DDX_Text(pDX, IDC_SLF_x3, SLF_x3);
	DDV_MinMaxInt(pDX, SLF_x3, 0, 999);
	DDX_Text(pDX, IDC_SLF_x4, SLF_x4);
	DDV_MinMaxInt(pDX, SLF_x4, 0, 999);
	DDX_Text(pDX, IDC_SLF_x5, SLF_x5);
	DDV_MinMaxInt(pDX, SLF_x5, 0, 999);
	DDX_Text(pDX, IDC_SLF_y1, SLF_y1);
	DDV_MinMaxInt(pDX, SLF_y1, 0, 999);
	DDX_Text(pDX, IDC_SLF_y2, SLF_y2);
	DDV_MinMaxInt(pDX, SLF_y2, 0, 999);
	DDX_Text(pDX, IDC_SLF_y3, SLF_y3);
	DDV_MinMaxInt(pDX, SLF_y3, 0, 999);
	DDX_Text(pDX, IDC_SLF_y4, SLF_y4);
	DDV_MinMaxInt(pDX, SLF_y4, 0, 999);
	DDX_Text(pDX, IDC_SLF_y5, SLF_y5);
	DDV_MinMaxInt(pDX, SLF_y5, 0, 999);
}


BEGIN_MESSAGE_MAP(CSLF, CDialog)
END_MESSAGE_MAP()


// CSLF message handlers
