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
	, SLF_ltx(0)
	, SLF_lty(0)
	, SLF_rbx(0)
	, SLF_rby(0)
{

}

CSLF::~CSLF()
{
}

void CSLF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SLF_ltx, SLF_ltx);
	DDV_MinMaxInt(pDX, SLF_ltx, 0, 500);
	DDX_Text(pDX, IDC_SLF_lty, SLF_lty);
	DDV_MinMaxInt(pDX, SLF_lty, 0, 500);
	DDX_Text(pDX, IDC_SLF_rbx, SLF_rbx);
	DDV_MinMaxInt(pDX, SLF_rbx, 0, 500);
	DDX_Text(pDX, IDC_SLF_rby, SLF_rby);
	DDV_MinMaxInt(pDX, SLF_rby, 0, 500);
}


BEGIN_MESSAGE_MAP(CSLF, CDialog)
	ON_EN_CHANGE(IDC_SLF_rbx, &CSLF::OnEnChangeSlfrbx)
END_MESSAGE_MAP()


// CSLF message handlers


void CSLF::OnEnChangeSlfrbx()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
