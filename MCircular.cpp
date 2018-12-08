// MCircular.cpp: implementation of the MCircular class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK1112.h"
#include "MCircular.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MCircular::MCircular()
{

}
MCircular::MCircular(CPoint startPoint, CPoint endPoint) {
	this->startPoint = startPoint;
	this->endPoint = endPoint;
}

MCircular::~MCircular()
{

}

void MCircular::draw(CDC* pDC, COLORREF color) {
	int x, y, d;

	int r = (int)sqrt((startPoint.x - endPoint.x)*(startPoint.x - endPoint.x) + (startPoint.y - endPoint.y)*(startPoint.y - endPoint.y));
	d = 1 - r;
	x = 0;
	y = r;
	pDC->SetPixel(x + startPoint.x, y + startPoint.y, color);
	pDC->SetPixel(y + startPoint.x, x + startPoint.y, color);
	pDC->SetPixel(x + startPoint.x, -y + startPoint.y, color);
	pDC->SetPixel(y + startPoint.x, -x + startPoint.y, color);
	pDC->SetPixel(-x + startPoint.x, -y + startPoint.y, color);
	pDC->SetPixel(-y + startPoint.x, -x + startPoint.y, color);
	pDC->SetPixel(-y + startPoint.x, x + startPoint.y, color);
	pDC->SetPixel(-x + startPoint.x, y + startPoint.y, color);
	while (x < y) {
		if (d < 0) {
			d += 2*x + 3;
			x++;
		} else {
			d += 2*(x - y) + 5;
			x++;
			y--;
		}
		pDC->SetPixel(x + startPoint.x, y + startPoint.y, color);
		pDC->SetPixel(y + startPoint.x, x + startPoint.y, color);
		pDC->SetPixel(x + startPoint.x, -y + startPoint.y, color);
		pDC->SetPixel(y + startPoint.x, -x + startPoint.y, color);
		pDC->SetPixel(-x + startPoint.x, -y + startPoint.y, color);
		pDC->SetPixel(-y + startPoint.x, -x + startPoint.y, color);
		pDC->SetPixel(-y + startPoint.x, x + startPoint.y, color);
		pDC->SetPixel(-x + startPoint.x, y + startPoint.y, color);
	}
}
int MCircular::getType() {
	return CIRCULAR;
}