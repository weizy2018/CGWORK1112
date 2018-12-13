// MRectangle.cpp: implementation of the MRectangle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK1112.h"
#include "MRectangle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MRectangle::MRectangle()
{

}
MRectangle::MRectangle(CPoint startPoint, CPoint endPoint) {
	this->startPoint = startPoint;
	this->endPoint = endPoint;
}

MRectangle::~MRectangle()
{

}

void MRectangle::draw(CDC* pDC) {
	int temp;
	if (startPoint.x > endPoint.x) {
		temp = startPoint.x;
		startPoint.x = endPoint.x;
		endPoint.x = temp;
	}
	if (startPoint.y > endPoint.y) {
		temp = startPoint.y;
		startPoint.y = endPoint.y;
		endPoint.y = temp;
	}
	int i;

	for (i = startPoint.x; i < endPoint.x; i++) {
		pDC->SetPixel(i, startPoint.y, color);
	}
	for (i = startPoint.x; i < endPoint.x; i++) {
		pDC->SetPixel(i, endPoint.y, color);
	}

	for (i = startPoint.y; i < endPoint.y; i++) {
		pDC->SetPixel(startPoint.x, i, color);
	}
	for (i = startPoint.y; i < endPoint.y; i++) {
		pDC->SetPixel(endPoint.x, i, color);
	}
	


}
int MRectangle::getType() {
	return RECT;
}
