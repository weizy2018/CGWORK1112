// Line.cpp: implementation of the Line class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK1112.h"
#include "Line.h"
#include <math.h>
#include <conio.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Line::Line() {

}
Line::Line(CPoint startPoint, CPoint endPoint) {
	this->startPoint = startPoint;
	this->endPoint = endPoint;
}

Line::~Line() {

}
int Line::getType() {
	return LINE;
}


void Line::draw(CDC* pDC) {
	/*
	pDC->MoveTo(startPoint);
	pDC->LineTo(endPoint);
	*/
	int x1 = startPoint.x;
	int y1 = startPoint.y;
	int x2 = endPoint.x;
	int y2 = endPoint.y;

	
	double dx,dy,e,x,y;
	dx = x2 -x1;
	dy = y2- y1;
	e = (fabs(dx) > fabs(dy)) ? fabs(dx):fabs(dy);
	dx/=e;
	dy/=e;
	x = x1;
	y = y1;
	for (int i=1;i<=e;i++){
		pDC->SetPixel((int)(x+0.5),(int)(y+0.5),color);
		x+=dx;
		y+=dy;
	}

}
