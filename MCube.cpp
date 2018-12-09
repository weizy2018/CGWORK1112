// MCube.cpp: implementation of the MCube class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK1112.h"
#include "MCube.h"

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
	

}

MCube::~MCube()
{

}

void MCube::draw(CDC* pDC, COLORREF color) {

}
int MCube::getType() {
	return CUBE;
}
/*
private:
	int face[6][4];
	int edge[12][2];
	int point[8][3];*/

void MCube::init() {
	points[0] = MPoint(200, 100, 100);
	points[1] = MPoint(200, 200, 100);
	points[2] = MPoint(100, 200, 100);
	points[3] = MPoint(100, 100, 100);
	points[4] = MPoint(200, 100, 200);
	points[5] = MPoint(200, 200, 200);
	points[6] = MPoint(100, 200, 300);
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
	face[2][1] = 5;
	face[2][2] = 6;
	face[2][3] = 3;

	face[3][0] = 0;
	face[3][1] = 3;
	face[3][2] = 6;
	face[3][3] = 7;

	face[4][0] = 4;
	face[4][1] = 5;
	face[4][2] = 6;
	face[4][3] = 7;

	face[5][0] = 0;
	face[5][1] = 1;
	face[5][2] = 2;
	face[5][3] = 3;
}

void MCube::calNormalVector() {
	for (int i = 0; i < 6; i++) {
		MPoint p0 = points[face[i][0]];
		MPoint p1 = points[face[i][1]];
		MPoint p2 = points[face[i][3]];

		MPoint line1 = MPoint(p1.x - p0.x, p1.y - p0.y, p1.z - p0.z);
		MPoint line2 = MPoint(p2.x - p0.x, p2.y - p0.y, p2.z - p0.z);

	}
}
