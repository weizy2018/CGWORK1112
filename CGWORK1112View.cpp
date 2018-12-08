// CGWORK1112View.cpp : implementation of the CCGWORK1112View class
//

#include "stdafx.h"
#include "CGWORK1112.h"

#include "CGWORK1112Doc.h"
#include "CGWORK1112View.h"
#include "Line.h"
#include "MRectangle.h"
#include "MCircular.h"

#include <conio.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CCGWORK1112View

IMPLEMENT_DYNCREATE(CCGWORK1112View, CView)

BEGIN_MESSAGE_MAP(CCGWORK1112View, CView)
	//{{AFX_MSG_MAP(CCGWORK1112View)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_DRAW_BEZIER, OnDrawBezier)
	ON_COMMAND(ID_DRAW_CIRCULAR, OnDrawCircular)
	ON_COMMAND(ID_DRAW_CUBE, OnDrawCube)
	ON_COMMAND(ID_DRAW_POLYGON, OnDrawPolygon)
	ON_COMMAND(ID_DRAW_RECT, OnDrawRect)
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCGWORK1112View construction/destruction

CCGWORK1112View::CCGWORK1112View()
{
	// TODO: add construction code here
	cursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
	LButtonDown = false;
	type = NONE;
	isDraw = false;

	//polygon = NULL;

	list = new TypeList;
}

CCGWORK1112View::~CCGWORK1112View()
{
}

BOOL CCGWORK1112View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCGWORK1112View drawing

void CCGWORK1112View::OnDraw(CDC* pDC)
{

	// TODO: add draw code for native data here
	for (int i=0;i < list->GetSize();i++)
	{
		
		BasicType* pMap = (BasicType*)list->GetAt(i);

		pMap->draw(pDC, RGB(255, 0, 0));
	}

}

/////////////////////////////////////////////////////////////////////////////
// CCGWORK1112View printing

BOOL CCGWORK1112View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCGWORK1112View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCGWORK1112View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCGWORK1112View diagnostics

#ifdef _DEBUG
void CCGWORK1112View::AssertValid() const
{
	CView::AssertValid();
}

void CCGWORK1112View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGWORK1112Doc* CCGWORK1112View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGWORK1112Doc)));
	return (CCGWORK1112Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCGWORK1112View message handlers

void CCGWORK1112View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	isDraw = true;
	if (isDraw) {
		this->DrawLButtonDown(nFlags, point);
	}

	CView::OnLButtonDown(nFlags, point);
}

void CCGWORK1112View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (isDraw) {
		this->DrawMouseMove(nFlags, point);
	}

	CView::OnMouseMove(nFlags, point);
}

void CCGWORK1112View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (isDraw) {
		this->DrawLButtonUp(nFlags, point);
	}
	isDraw = false;

	CView::OnLButtonUp(nFlags, point);
}
void CCGWORK1112View::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDblClk(nFlags, point);
}

void CCGWORK1112View::DrawLButtonDown(UINT nFlags, CPoint point)
{
	if (type != NONE && type != POLYGON) {
		SetCursor(cursor);
	
		this->SetCapture();

		startPoint = point;
		endPoint = point;
		LButtonDown = true;
	}
	/*else if (type == POLYGON) {
		SetCursor(cursor);
		this->SetCapture();
		if (polygon == NULL) {
			polygon = new MPolygon();
		}
		polygon->addPoint(point);

		startPoint = point;
		endPoint = point;
		LButtonDown = true;
	}*/
	

}

void CCGWORK1112View::DrawMouseMove(UINT nFlags, CPoint point)
{
	if (type != NONE) {
		SetCursor(cursor);
	}
	
	CDC* pDC = this->GetDC();

	if (LButtonDown && type == LINE) {

		pDC->SetROP2(R2_NOT);

		Line line1;
		line1.setStartPoint(startPoint);
		line1.setEndPoint(endPoint);
		line1.draw(pDC, RGB(255, 0, 0));

		/*
		dc.MoveTo(startPoint);
		dc.LineTo(endPoint);
		*/
		Line line2;
		line2.setStartPoint(startPoint);
		line2.setEndPoint(point);
		line2.draw(pDC, RGB(255, 0, 0));
		/*
		dc.MoveTo(startPoint);
		dc.LineTo(point);
		*/
		
		endPoint = point;
	} else if (LButtonDown && type == RECT) {
		pDC->SetROP2(R2_NOT);
		

		MRectangle rect1;
		rect1.setStartPoint(startPoint);
		rect1.setEndPoint(endPoint);
		rect1.draw(pDC, RGB(255, 0, 0));

		MRectangle rect2;
		rect2.setStartPoint(startPoint);
		rect2.setEndPoint(point);
		rect2.draw(pDC, RGB(255, 0, 0));
		
		endPoint = point;

	} else if (LButtonDown && type == CIRCULAR) {
		pDC->SetROP2(R2_NOT);

		MCircular circular1;
		circular1.setStartPoint(startPoint);
		circular1.setEndPoint(endPoint);
		circular1.draw(pDC, RGB(255, 0, 0));

		MCircular circular2;
		circular2.setStartPoint(startPoint);
		circular2.setEndPoint(point);
		circular2.draw(pDC, RGB(255, 0, 0));
		
		endPoint = point;
	}
	/*else if (LButtonDown && type == POLYGON) {
		pDC->SetROP2(R2_NOT);

		Line line1;
		line1.setStartPoint(startPoint);
		line1.setEndPoint(endPoint);
		line1.draw(pDC, RGB(255, 0, 0));

		Line line2;
		line2.setStartPoint(startPoint);
		line2.setEndPoint(point);
		line2.draw(pDC, RGB(255, 0, 0));
		endPoint = point;
	}*/

}

void CCGWORK1112View::DrawLButtonUp(UINT nFlags, CPoint point)
{
	if (type != NONE) {
		SetCursor(cursor);
		ReleaseCapture();
	}

	CDC* pDC = this->GetDC();

	if (type == LINE) {
		Line * line = new Line(startPoint, endPoint);
		line->draw(pDC, RGB(255, 0, 0));
		list->Add(line);
	} else if (type == RECT) {
		MRectangle * rect = new MRectangle(startPoint, endPoint);
		rect->draw(pDC, RGB(255, 0, 0));
		list->Add(rect);
	} else if (type == CIRCULAR) {
		MCircular * cir = new MCircular(startPoint, endPoint);
		cir->draw(pDC, RGB(255, 0, 0));
		list->Add(cir);
	}
	this->ReleaseDC(pDC);

}

void CCGWORK1112View::OnDrawBezier() 
{
	// TODO: Add your command handler code here
	type = BEZIER;
	
}

void CCGWORK1112View::OnDrawCircular() 
{
	// TODO: Add your command handler code here
	type = CIRCULAR;
	
}

void CCGWORK1112View::OnDrawCube() 
{
	// TODO: Add your command handler code here
	type = CUBE;
	
}

void CCGWORK1112View::OnDrawPolygon() 
{
	// TODO: Add your command handler code here
	type = POLYGON;
	
}

void CCGWORK1112View::OnDrawRect() 
{
	// TODO: Add your command handler code here
	type = RECT;
	
}

void CCGWORK1112View::OnDrawLine() 
{
	// TODO: Add your command handler code here
	type = LINE;
	/*
	AllocConsole();
	_cprintf("type = %d\n", type);
	FreeConsole();
	*/
}



void CCGWORK1112View::drawLButtonDblClk(UINT nFlags, CPoint point)
{

}
