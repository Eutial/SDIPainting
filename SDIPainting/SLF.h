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
	int SLF_x1;
	int SLF_x2;
	int SLF_x3;
	int SLF_x4;
	int SLF_x5;
	int SLF_y1;
	int SLF_y2;
	int SLF_y3;
	int SLF_y4;
	int SLF_y5;
};
