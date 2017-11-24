#pragma once


// CSLF dialog

class CSLF : public CDialog
{
	DECLARE_DYNAMIC(CSLF)

public:
	CSLF(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSLF();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ScanLineFilling };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	int SLF_ltx;
	int SLF_lty;
	int SLF_rbx;
	int SLF_rby;
};

