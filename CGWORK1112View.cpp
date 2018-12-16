// CGWORK1112View.cpp : implementation of the CCGWORK1112View class
//

#include "stdafx.h"
#include "CGWORK1112.h"

#include "CGWORK1112Doc.h"
#include "CGWORK1112View.h"
#include "Line.h"
#include "MRectangle.h"
#include "MCircular.h"
#include "MCube.h"
#include "InputColorDlg.h"
#include "InputColorDlg2.h"
#include "InputColorDlgB.h"

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
	ON_COMMAND(ID_SET_COLOR1, OnSetColor1)
	ON_COMMAND(ID_SET_COLOR2, OnSetColor2)
	ON_COMMAND(ID_SER_COLOR3, OnSerColor3)
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

	polygon = NULL;
	bezier = NULL;

	list = new TypeList;

	rectColor = RGB(0, 0, 0);
	cirColor = RGB(0, 0, 0);

	borderColor = RGB(0, 0, 0);
	fillColor = RGB(0, 0, 0);

	bezierBorder = RGB(0, 0, 0);
	bezierCurve = RGB(0, 0, 0);

	category = 1;
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

		pMap->draw(pDC);
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
	if (type != NONE && type != POLYGON && type != BEZIER) {
		if (isDraw) {
			this->DrawLButtonUp(nFlags, point);
		}
		isDraw = false;
	} else if (type == POLYGON) {
		
	} else if (type == BEZIER) {
		if (count == 4) {
			CDC* pDC = this->GetDC();
			SetCursor(cursor);
			ReleaseCapture();
	
			bezier->setColor(bezierBorder, bezierCurve);
			bezier->draw(pDC);
			list->Add(bezier);
			bezier = NULL;
			count = 0;
			this->ReleaseDC(pDC);
			isDraw = false;
		}

	}
	

	CView::OnLButtonUp(nFlags, point);
}
void CCGWORK1112View::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	if (type == POLYGON && count >= 3) {
		this->drawLButtonDblClk(nFlags, point);
		isDraw = false;
	}
	
	CView::OnLButtonDblClk(nFlags, point);
}

void CCGWORK1112View::DrawLButtonDown(UINT nFlags, CPoint point)
{
	if (type != NONE && type != POLYGON && type != BEZIER && type != CUBE) {
		SetCursor(cursor);
	
		this->SetCapture();

		startPoint = point;
		endPoint = point;
		LButtonDown = true;
	}else if (type == POLYGON) {
		SetCursor(cursor);
		this->SetCapture();

		if (polygon == NULL) {
			polygon = new MPolygon();
			count = 0;
		}
		polygon->addPoint(point);
		count++;

		startPoint = point;
		endPoint = point;
		LButtonDown = true;
	} else if (type == BEZIER) {
		SetCursor(cursor);
		this->SetCapture();

		if (bezier == NULL) {
			bezier = new MBezier();
			count = 0;
		}
		bezier->addPoint(point);
		count++;

		startPoint = point;
		endPoint = point;
		LButtonDown = true;
	}
	

}


void CCGWORK1112View::DrawMouseMove(UINT nFlags, CPoint point)
{
	if (type != NONE && type != CUBE) {
		SetCursor(cursor);
	}
	
	CDC* pDC = this->GetDC();

	if (LButtonDown && type == LINE) {

		pDC->SetROP2(R2_NOT);

		Line line1;
		line1.setStartPoint(startPoint);
		line1.setEndPoint(endPoint);
		line1.draw(pDC);

		/*
		dc.MoveTo(startPoint);
		dc.LineTo(endPoint);
		*/
		Line line2;
		line2.setStartPoint(startPoint);
		line2.setEndPoint(point);
		line2.draw(pDC);
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
		rect1.draw(pDC);

		MRectangle rect2;
		rect2.setStartPoint(startPoint);
		rect2.setEndPoint(point);
		rect2.draw(pDC);
		
		endPoint = point;

	} else if (LButtonDown && type == CIRCULAR) {
		pDC->SetROP2(R2_NOT);

		MCircular circular1;
		circular1.setStartPoint(startPoint);
		circular1.setEndPoint(endPoint);
		circular1.draw(pDC);

		MCircular circular2;
		circular2.setStartPoint(startPoint);
		circular2.setEndPoint(point);
		circular2.draw(pDC);
		
		endPoint = point;
	}else if (LButtonDown && type == POLYGON) {
		pDC->SetROP2(R2_NOT);

		Line line1;
		line1.setStartPoint(startPoint);
		line1.setEndPoint(endPoint);
		line1.draw(pDC);

		Line line2;
		line2.setStartPoint(startPoint);
		line2.setEndPoint(point);
		line2.draw(pDC);
		endPoint = point;
	} else if (LButtonDown && type == BEZIER) {
		pDC->SetROP2(R2_NOT);

		Line line1;
		line1.setStartPoint(startPoint);
		line1.setEndPoint(endPoint);
		line1.draw(pDC);

		Line line2;
		line2.setStartPoint(startPoint);
		line2.setEndPoint(point);
		line2.draw(pDC);
		endPoint = point;
	}

	this->ReleaseDC(pDC);

}

void CCGWORK1112View::DrawLButtonUp(UINT nFlags, CPoint point)
{
	/*
	if (type != NONE) {
		SetCursor(cursor);
		ReleaseCapture();
	}
	*/

	//CDC* pDC = this->GetDC();

	if (type == LINE) {
		CDC* pDC = this->GetDC();
		SetCursor(cursor);
		ReleaseCapture();

		Line * line = new Line(startPoint, endPoint);
		line->setColor(rectColor);
		line->draw(pDC);
		list->Add(line);
		this->ReleaseDC(pDC);
	} else if (type == RECT) {
		CDC* pDC = this->GetDC();
		SetCursor(cursor);
		ReleaseCapture();

		MRectangle * rect = new MRectangle(startPoint, endPoint);
		rect->setColor(rectColor);
		rect->draw(pDC);
		list->Add(rect);
		this->ReleaseDC(pDC);
	} else if (type == CIRCULAR) {
		CDC* pDC = this->GetDC();
		SetCursor(cursor);
		ReleaseCapture();

		MCircular * cir = new MCircular(startPoint, endPoint);
		cir->setColor(cirColor);
		cir->draw(pDC);
		list->Add(cir);
		this->ReleaseDC(pDC);
	}


//	this->ReleaseDC(pDC);

}
void CCGWORK1112View::drawLButtonDblClk(UINT nFlags, CPoint point)
{	if (type == POLYGON) {
		SetCursor(cursor);
		ReleaseCapture();

		CDC* pDC = this->GetDC();
		polygon->setColor(borderColor, fillColor);
		polygon->draw(pDC);
		list->Add(polygon);
		polygon = NULL;
		count = 0;
	
		this->ReleaseDC(pDC);
	}
	
}

void CCGWORK1112View::OnDrawBezier() 
{
	// TODO: Add your command handler code here
	type = BEZIER;
	if (category != 4) {
		this->clear();
		category = 4;
	}
	
}

void CCGWORK1112View::OnDrawCircular() 
{
	// TODO: Add your command handler code here
	type = CIRCULAR;
	if (category != 1) {
		this->clear();
		category = 1;
	}
	
}

void CCGWORK1112View::OnDrawCube() 
{
	// TODO: Add your command handler code here
	this->clear();

	CDC* pDC = this->GetDC();
	type = CUBE;
	MCube cube;
	cube.draw(pDC);
	this->ReleaseDC(pDC);
}

void CCGWORK1112View::OnDrawPolygon() 
{
	// TODO: Add your command handler code here
	type = POLYGON;
	if (category != 2) {
		this->clear();
		category = 2;
	}
	
}

void CCGWORK1112View::OnDrawRect() 
{
	// TODO: Add your command handler code here
	type = RECT;
	if (category != 1) {
		this->clear();
		category = 1;
	}
	
}

void CCGWORK1112View::OnDrawLine() 
{
	// TODO: Add your command handler code here
	type = LINE;
	if (category != 1) {
		this->clear();
		category = 1;
	}
	
}



void CCGWORK1112View::OnSetColor1() 
{
	// TODO: Add your command handler code here
	InputColorDlg input;
	if (input.DoModal() == IDOK) {
		rectColor = RGB(input.rect_r, input.rect_g, input.rect_b);

		cirColor = RGB(input.cir_r, input.cir_g, input.cir_b);
	}

	
}

void CCGWORK1112View::OnSetColor2() 
{
	// TODO: Add your command handler code here
	InputColorDlg2 input;
	if (input.DoModal() == IDOK) {
		borderColor = RGB(input.border_r, input.border_g, input.border_b);

		fillColor = RGB(input.fill_r, input.fill_g, input.fill_b);
	}

}

void CCGWORK1112View::OnSerColor3() 
{
	// TODO: Add your command handler code here
	InputColorDlgB input;
	if (input.DoModal() == IDOK) {
		bezierBorder = RGB(input.border_r, input.border_g, input.border_b);

		bezierCurve = RGB(input.curve_r, input.curve_g, input.curve_b);
	}
	
}

void CCGWORK1112View::clear() {
	this->list->clearList();
	this->Invalidate();
}

