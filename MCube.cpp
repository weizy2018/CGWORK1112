// MCube.cpp: implementation of the MCube class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK1112.h"
#include "MCube.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MCube::MCube()
{
	colors[0] = RGB(255, 0, 0);
	colors[1] = RGB(0, 255, 0);
	colors[2] = RGB(0, 0, 255);
	colors[3] = RGB(255, 255, 0);
	colors[4] = RGB(255, 0, 255);
	colors[5] = RGB(0, 255, 255);

	view.x = 0;
	view.y = 0;
	view.z = 300;

	init();
	

}

MCube::~MCube()
{

}

void MCube::draw(CDC* pDC) {
	calNormalVector();

	for (int i = 0; i < 6; i++) {
		if (isView(normalVector[i])) {
			drawFace(i, pDC);
		}
	}


}
int MCube::getType() {
	return CUBE;
}


void MCube::init() {
	points[0] = MPoint(200, 100, 100);
	points[1] = MPoint(200, 200, 100);
	points[2] = MPoint(100, 200, 100);
	points[3] = MPoint(100, 100, 100);
	points[4] = MPoint(200, 100, 200);
	points[5] = MPoint(200, 200, 200);
	points[6] = MPoint(100, 200, 200);
	points[7] = MPoint(100, 100, 200);

	face[0][0] = 0;
	face[0][1] = 1;
	face[0][2] = 4;
	face[0][3] = 7;

	face[1][0] = 1;
	face[1][1] = 2;
	face[1][2] = 5;
	face[1][3] = 4;

	face[2][0] = 2;
	face[2][1] = 3;
	face[2][2] = 6;
	face[2][3] = 5;

	face[3][0] = 0;
	face[3][1] = 7;
	face[3][2] = 6;
	face[3][3] = 3;

	face[4][0] = 4;
	face[4][1] = 5;
	face[4][2] = 6;
	face[4][3] = 7;

	face[5][0] = 0;
	face[5][1] = 3;
	face[5][2] = 2;
	face[5][3] = 1;
}

void MCube::calNormalVector() {
	for (int i = 0; i < 6; i++) {
		MPoint p0 = points[face[i][0]];
		MPoint p1 = points[face[i][1]];
		MPoint p2 = points[face[i][3]];

		MPoint line1 = MPoint(p1.x - p0.x, p1.y - p0.y, p1.z - p0.z);
		MPoint line2 = MPoint(p2.x - p0.x, p2.y - p0.y, p2.z - p0.z);

		MPoint normal;
		normal.x = line1.y * line2.z - line1.z * line2.y;
		normal.y = line1.z * line2.x - line1.x * line2.z;
		normal.z = line1.x * line2.y - line1.y * line2.x;

		normalVector[i] = normal;
	}
}

bool MCube::isView(MPoint vector) {
	int a = view.x * vector.x + view.y * vector.y + view.z * vector.z;
	return a > 0;
}

void MCube::drawFace(int i, CDC * pDC) {
	//ÈýÎ¬×ª¶þÎ¬
	MPoint p0 = points[face[i][0]];
	MPoint p1 = points[face[i][1]];
	MPoint p2 = points[face[i][2]];
	MPoint p3 = points[face[i][3]];

	MPoint midle(300, 300, -200);

	int d = abs(midle.z);
	
	CPoint point0, point1, point2, point3;
	point0.x = p0.x;
	point0.y = p0.y;

	point1.x = p1.x;
	point1.y = p1.y;

	point2.x = p2.x;
	point2.y = p2.y;

	point3.x = p3.x;
	point3.y = p3.y;

	Line line1(point0, point1);
	Line line2(point1, point2);
	Line line3(point2, point3);
	Line line4(point3, point0);

	line1.setColor(colors[i]);
	line2.setColor(colors[i]);
	line3.setColor(colors[i]);
	line4.setColor(colors[i]);

	line1.draw(pDC);
	line2.draw(pDC);
	line3.draw(pDC);
	line4.draw(pDC);
}