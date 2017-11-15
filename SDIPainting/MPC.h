#pragma once


// CMPC dialog

class CMPC : public CDialog
{
	DECLARE_DYNAMIC(CMPC)

public:
	CMPC(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMPC();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MidPointCircle };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int MPC_x;
	int MPC_y;
	int MPC_r;
};
