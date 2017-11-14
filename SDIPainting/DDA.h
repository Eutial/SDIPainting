#pragma once


// CDDA dialog

class CDDA : public CDialog
{
	DECLARE_DYNAMIC(CDDA)

public:
	CDDA(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDDA();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DDA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
