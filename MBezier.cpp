// MBezier.cpp: implementation of the MBezier class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK1112.h"
#include "MBezier.h"
#include "Line.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MBezier::MBezier()
{
	this->count = 0;

}

MBezier::~MBezier()
{

}

void MBezier::draw(CDC* pDC) {
	//先画四条线
	drawLine(pDC);
	
	double dist = sqrt((points[0].x - points[count - 1].x)*(points[0].x - points[ count - 1].x) 
		+ (points[0].y - points[count - 1].y)*(points[0].y - points[ count - 1].y));
	dist /= 2;
	double delt = 1.0/(double)dist;
	CPoint startPoint = points[0];
	double t = 0.0;
	for (int i = 0; i < dist; i++) {
		CPoint endPoint = decas(t);
		Line line(startPoint, endPoint);
		line.setColor(color2);
		line.draw(pDC);
		startPoint = endPoint;
		t += delt;
	}
	

}
int MBezier::getType() {
	return BEZIER;
}
void MBezier::addPoint(CPoint point) {
	points[count++] = point;
}

void MBezier::drawLine(CDC* pDC) {
	int x = points[0].x;
	int y = points[0].y;
	int i, j, k;
	for (i = y - 2; i < y+2; i++) {
		for (j = x - 2; j < x + 2; j++) {
			pDC->SetPixel(j, i, color);
		}
	}

	for (i = 0; i < count - 1; i++) {
		Line line(points[i], points[i+1]);
		line.setColor(color);
		line.draw(pDC);
		x = points[i+1].x;
		y = points[i+1].y;
		for (j = y - 2; j < y + 2; j++) {
			for (k = x - 2; k < x + 2; k++) {
				pDC->SetPixel(k, j, color);
			}
		}
	}
}
CPoint MBezier::decas(double t) {
	int m, i;
	CPoint Q[POINT_COUNT];
	CPoint R[POINT_COUNT];
	for (i = 0; i < count; i++) {
		R[i] = points[i];
	}

	for (m = count - 1; m > 0; m--) {
		for (i = 0; i < m; i++) {
			Q[i].x = R[i].x + (long)(t*(R[i+1].x - R[i].x));
			Q[i].y = R[i].y + (long)(t*(R[i+1].y - R[i].y));
		}
		for (i = 0; i < m; i++) {
			R[i] = Q[i];
		}
	}
	return R[0];
}
