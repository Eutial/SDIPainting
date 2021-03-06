
// SDIPaintingView.cpp : implementation of the CSDIPaintingView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SDIPainting.h"
#endif

#include "SDIPaintingDoc.h"
#include "SDIPaintingView.h"
#include "DDA.h"
#include "MPL.h"
#include "MPC.h"
#include "SLF.h"
#include "SF.h"
#include <stack>
#include <vector>
#include <functional>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIPaintingView

IMPLEMENT_DYNCREATE(CSDIPaintingView, CView)

BEGIN_MESSAGE_MAP(CSDIPaintingView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DRAWING_DDA, &CSDIPaintingView::OnDrawingDda)
	ON_COMMAND(ID_DRAWING_MPL, &CSDIPaintingView::OnDrawingMpl)
	ON_COMMAND(ID_DRAWING_MPC, &CSDIPaintingView::OnDrawingMpc)
	ON_COMMAND(ID_DRAWING_SLF, &CSDIPaintingView::OnDrawingSlf)
	ON_COMMAND(ID_DRAWING_SF, &CSDIPaintingView::OnDrawingSf)
END_MESSAGE_MAP()

// CSDIPaintingView construction/destruction

CSDIPaintingView::CSDIPaintingView()
{
	// TODO: add construction code here
}

CSDIPaintingView::~CSDIPaintingView()
{
}

BOOL CSDIPaintingView::PreCreateWindow(CREATESTRUCT& cs)
{

	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	return CView::PreCreateWindow(cs);
}

// CSDIPaintingView drawing

void CSDIPaintingView::OnDraw(CDC* /*pDC*/)
{
	CSDIPaintingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

}

void CSDIPaintingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}


void CSDIPaintingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSDIPaintingView diagnostics

#ifdef _DEBUG
void CSDIPaintingView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIPaintingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIPaintingDoc* CSDIPaintingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIPaintingDoc)));
	return (CSDIPaintingDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIPaintingView message handlers


void CSDIPaintingView::OnDrawingDda()
{
	// TODO: Add your command handler code here

	CDDA drawDDA;
	if (drawDDA.DoModal() == IDOK) {
		CDC* pDC = GetDC();
		COLORREF color = RGB(0, 0, 0);
		DDA(pDC, drawDDA.DDA_x1, drawDDA.DDA_x2, drawDDA.DDA_y1, drawDDA.DDA_y2, color);
		ReleaseDC(pDC);
	}
}
void CSDIPaintingView::DDA(CDC* pDC, int x1, int x2, int y1, int y2, COLORREF color)
{
	int x, y, dx, dy, k, xend, yend;

	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dx) >= abs(dy)) {
		k = dy / dx;
		if (dx>0)
		{
			x = x1;
			y = y1;
			xend = x2;
		}
		else
		{
			x = x2;
			y = y2;
			xend = x1;
		}
		while (x<=xend)
		{
			pDC->SetPixel(x, y, color);
			y = y + k;
			x = x + 1;
		}
	}
	else
	{
		k = dx / dy;
		if (dy>0)
		{
			x = x1;
			y = y1;
			yend = y2;
		}
		else
		{
			x = x2;
			y = y2;
			yend = y1;
		}
		while (y<=yend)
		{
			pDC->SetPixel(x, y, color);
			x = x + k;
			y = y + 1;
		}
	}
}

void CSDIPaintingView::OnDrawingMpl()
{
	// TODO: Add your command handler code here

	CMPL drawMPL;
	if (drawMPL.DoModal() == IDOK) {
		CDC* pDC = GetDC();
		COLORREF color = RGB(0, 0, 0);
		BresenhamLine(pDC, drawMPL.MPL_x1, drawMPL.MPL_x2, drawMPL.MPL_y1, drawMPL.MPL_y2, color);
		ReleaseDC(pDC);
	}
}
void CSDIPaintingView::BresenhamLine(CDC* pDC, int x1, int x2, int y1, int y2, COLORREF color)
{
	int dx, dy, error, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	bool steep = abs(dy) > abs(dx);

	if (steep)
	{
		std::swap(x1, y1);
		std::swap(x2, y2);
	}
	if (x1>x2)
	{
		std::swap(x1, x2);
		std::swap(y1, y2);
	}
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	error = 0;
	int derr = dy / dx;
	int ystep;
	y = y1;
	if (y1<y2)
	{
		ystep = 1;
	}
	else 
	{
		ystep = -1;
	}
	for ( x = 0; x < x2; x++)
	{
		if (steep) {
			pDC->SetPixel(y, x, color);
		}
		else
		{
			pDC->SetPixel(x, y, color);
		}
		error = error + derr;
		if (error>=0.5)
		{
			y = y + ystep;
			error = error - 1;
		}
	}
}

void CSDIPaintingView::OnDrawingMpc()
{
	// TODO: Add your command handler code here

	CMPC drawMPC;
	if (drawMPC.DoModal() == IDOK) {
		CDC* pDC = GetDC();
		COLORREF color = RGB(0, 0, 0);
		BresenhamCircle(pDC, drawMPC.MPC_x, drawMPC.MPC_y, drawMPC.MPC_r, color);
		ReleaseDC(pDC);
	}

}
void CSDIPaintingView::BresenhamCircle(CDC* pDC, int x0, int y0, int r, COLORREF color)
{
	int x = 0;
	int y = r;
	int d = 1 - r;

	while (y > x)
	{
		pDC->SetPixel(x0 + x, y0 + y, color);
		pDC->SetPixel(x0 + y, y0 + x, color);
		pDC->SetPixel(x0 - y, y0 + x, color);
		pDC->SetPixel(x0 - x, y0 + y, color);
		pDC->SetPixel(x0 - x, y0 - y, color);
		pDC->SetPixel(x0 - y, y0 - x, color);
		pDC->SetPixel(x0 + y, y0 - x, color);
		pDC->SetPixel(x0 + x, y0 - y, color);

		if (d <= 0)
		{
			d = d + 2 * x + 3;
		}

		else
		{
			d = d + 2 * (x - y) + 5;
			y--;
		}
		x++;
	}
}

void CSDIPaintingView::OnDrawingSlf()
{
	// TODO: Add your command handler code here

	CSLF drawSLF;
	if (drawSLF.DoModal() == IDOK) {
		CDC* pDC = GetDC();
		COLORREF colorOld = RGB(255, 255, 255);
		COLORREF colorNew = RGB(255, 0, 0);
		pDC->Ellipse(drawSLF.SLF_ltx, drawSLF.SLF_lty, drawSLF.SLF_rbx, drawSLF.SLF_rby);
		ScanLineFill(pDC, ((drawSLF.SLF_rbx - drawSLF.SLF_ltx) / 2), ((drawSLF.SLF_rby - drawSLF.SLF_lty) / 2), colorOld, colorNew);
		ReleaseDC(pDC);

	}
}
void CSDIPaintingView::ScanLineFill(CDC* pDC, int x, int y, COLORREF colorOld, COLORREF colorNew)
{
	CPoint pt;
	int xLeft, xRight;
	bool isNeedFill;
	std::stack<CPoint> stk;
	pt.x = x;
	pt.y = y;
	stk.push(pt);
	while (!stk.empty())
	{
		pt = stk.top();
		stk.pop();
		y = pt.y;
		x = pt.x;
		while (pDC->GetPixel(x, y) == colorOld)
		{
			pDC->SetPixel(x, y, colorNew);
			x++;
		}
		xRight = x - 1;
		x = pt.x - 1;
		while (pDC->GetPixel(x, y) == colorOld)
		{
			pDC->SetPixel(x, y, colorNew);
			x--;
		}
		xLeft = x + 1;

		x = xLeft;
		y = y + 1;
		while (x < xRight)
		{
			isNeedFill = FALSE;
			while (pDC->GetPixel(x, y) == colorOld)
			{
				isNeedFill = TRUE;
				x++;
			}
			if (isNeedFill)
			{
				pt.x = x - 1;
				pt.y = y;
				stk.push(pt);
				isNeedFill = FALSE;
			}
			while (pDC->GetPixel(x, y) != colorOld && x < xRight)
			{
				x++;
			}
		}

		x = xLeft;
		y = y - 2;
		while (x < xRight)
		{
			isNeedFill = FALSE;
			while (pDC->GetPixel(x, y) == colorOld)
			{
				isNeedFill = TRUE;
				x++;
			}
			if (isNeedFill)
			{
				pt.x = x - 1;
				pt.y = y;
				stk.push(pt);
				isNeedFill = FALSE;
			}
			while (pDC->GetPixel(x, y) != colorOld && x < xRight)
			{
				x++;
			}
		}
	}
}

void CSDIPaintingView::OnDrawingSf()
{
	// TODO: Add your command handler code here

	CSF drawSF;
	if (drawSF.DoModal() == IDOK)
	{
		CDC* pDC = GetDC();
		COLORREF colorNew = RGB(255, 0, 0);
		COLORREF colorOld = RGB(255, 255, 255);
		pDC->Ellipse(drawSF.SF_ltx, drawSF.SF_lty, drawSF.SF_rbx, drawSF.SF_rby);

		FloodFill(pDC, ((drawSF.SF_rbx - drawSF.SF_ltx) / 2), ((drawSF.SF_rby - drawSF.SF_lty) / 2), colorOld, colorNew);
		ReleaseDC(pDC);
	}
}
void CSDIPaintingView::FloodFill(CDC* pDC, int x, int y, COLORREF colorOld, COLORREF colorNew)
{
	if (pDC->GetPixel(CPoint(x, y)) == colorOld)
	{
		pDC->SetPixel(CPoint(x, y), colorNew);

		FloodFill(pDC, x, y - 1, colorOld, colorNew);
		FloodFill(pDC, x + 1, y, colorOld, colorNew); 
		FloodFill(pDC, x, y + 1, colorOld, colorNew); 
		FloodFill(pDC, x - 1, y, colorOld, colorNew); 
	}
}