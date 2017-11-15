#pragma once


// CMPL dialog

class CMPL : public CDialog
{
	DECLARE_DYNAMIC(CMPL)

public:
	CMPL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMPL();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MidPointLine };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int MPL_x1;
	int MPL_y1;
	int MPL_x2;
	int MPL_y2;
};
