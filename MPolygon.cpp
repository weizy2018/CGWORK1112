// MPolygon.cpp: implementation of the MPolygon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK1112.h"
#include "MPolygon.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MPolygon::MPolygon()
{

}

MPolygon::~MPolygon()
{

}
void MPolygon::draw(CDC * pDC, COLORREF color) {

	for (int i = 0; i < points.GetSize() - 1; i++) {
		Line line(points.GetAt(i), points.GetAt(i+1));
		line.draw(pDC, color);
	}
	Line li(points.GetAt(points.GetSize() - 1), points.GetAt(0));
	li.draw(pDC, color);
}
int MPolygon::getType() {
	return POLYGON;
}

void MPolygon::addPoint(CPoint point) {
	points.push_back(point);
}


