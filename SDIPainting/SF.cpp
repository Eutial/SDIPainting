// SF.cpp : implementation file
//

#include "stdafx.h"
#include "SDIPainting.h"
#include "SF.h"
#include "afxdialogex.h"


// CSF dialog

IMPLEMENT_DYNAMIC(CSF, CDialog)

CSF::CSF(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SeedFilling, pParent)
	, SF_ltx(0)
	, SF_lty(0)
	, SF_rbx(0)
	, SF_rby(0)
{

}

CSF::~CSF()
{
}

void CSF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SF_ltx, SF_ltx);
	DDV_MinMaxInt(pDX, SF_ltx, 0, 500);
	DDX_Text(pDX, IDC_SF_lty, SF_lty);
	DDV_MinMaxInt(pDX, SF_lty, 0, 500);
	DDX_Text(pDX, IDC_SF_rbx, SF_rbx);
	DDV_MinMaxInt(pDX, SF_rbx, 0, 500);
	DDX_Text(pDX, IDC_SF_rby, SF_rby);
	DDV_MinMaxInt(pDX, SF_rby, 0, 500);
}


BEGIN_MESSAGE_MAP(CSF, CDialog)
	ON_EN_CHANGE(IDC_SF_rby, &CSF::OnEnChangeSfrby)
END_MESSAGE_MAP()


// CSF message handlers


void CSF::OnEnChangeSfrby()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
