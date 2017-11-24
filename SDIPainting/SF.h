#pragma once


// CSF dialog

class CSF : public CDialog
{
	DECLARE_DYNAMIC(CSF)

public:
	CSF(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSF();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SeedFilling };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int SF_ltx;
	int SF_lty;
	int SF_rbx;
	int SF_rby;
	afx_msg void OnEnChangeSfrby();
};
