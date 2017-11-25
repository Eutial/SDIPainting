// MPC.cpp : implementation file
//

#include "stdafx.h"
#include "SDIPainting.h"
#include "MPC.h"
#include "afxdialogex.h"


// CMPC dialog

IMPLEMENT_DYNAMIC(CMPC, CDialog)

CMPC::CMPC(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MidPointCircle, pParent)
	, MPC_x(0)
	, MPC_y(0)
	, MPC_r(0)
{

}

CMPC::~CMPC()
{
}

void CMPC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MPC_x, MPC_x);
	DDV_MinMaxInt(pDX, MPC_x, 0, 999);
	DDX_Text(pDX, IDC_MPC_y, MPC_y);
	DDV_MinMaxInt(pDX, MPC_y, 0, 999);
	DDX_Text(pDX, IDC_MPC_r, MPC_r);
	DDV_MinMaxInt(pDX, MPC_r, 1, 500);
}


BEGIN_MESSAGE_MAP(CMPC, CDialog)
END_MESSAGE_MAP()


// CMPC message handlers
