// MCube.cpp: implementation of the MCube class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK1112.h"
#include "MCube.h"
#include "Line.h"
#include "cmath"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define pi 3.1415926

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
	view.z = -300;

	init();
	

}

MCube::~MCube()
{

}

void MCube::draw(CDC* pDC) {

	calNormalVector();

	for (int i = 0; i < 6; i++) {
		if (isView(i)) {
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
	face[0][2] = 5;
	face[0][3] = 4;

	face[1][0] = 1;
	face[1][1] = 2;
	face[1][2] = 6;
	face[1][3] = 5;

	face[2][0] = 2;
	face[2][1] = 3;
	face[2][2] = 7;
	face[2][3] = 6;

	face[3][0] = 0;
	face[3][1] = 4;
	face[3][2] = 7;
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

		normalVector[i].x = line1.y * line2.z - line1.z * line2.y;
		normalVector[i].y = line1.z * line2.x - line1.x * line2.z;
		normalVector[i].z = line1.x * line2.y - line1.y * line2.x;
	}
}

bool MCube::isView(int f) {
	MPoint p1 = points[face[f][0]];
	MPoint p2 = points[face[f][2]];
	MPoint p;
	p.x = (p1.x + p2.x)/2;
	p.y = (p1.y + p2.y)/2;
	p.z = (p1.z + p2.z)/2;
	MPoint viewVector;
	/*
	viewVector.x = p.x - view.x;
	viewVector.y = p.y - view.y;
	viewVector.z = p.z - view.z;
	*/
	viewVector.x = view.x - p.x;
	viewVector.y = view.y - p.y;
	viewVector.z = view.z - p.z;


	int a = viewVector.x * normalVector[f].x + viewVector.y * normalVector[f].y + viewVector.z * normalVector[f].z;
	return a > 0;

}

void MCube::drawFace(int i, CDC * pDC) {
	//ÈýÎ¬×ª¶þÎ¬
	MPoint p0 = points[face[i][0]];
	MPoint p1 = points[face[i][1]];
	MPoint p2 = points[face[i][2]];
	MPoint p3 = points[face[i][3]];

	int d = abs(view.z);
	
	CPoint point0, point1, point2, point3;
	point0.x = view.x + d*(p0.x - view.x)/(p0.z - view.z);
	point0.y = view.y + d*(p0.y - view.y)/(p0.z - view.z);

	point1.x = view.x + d*(p1.x - view.x)/(p1.z - view.z);
	point1.y = view.y + d*(p1.y - view.y)/(p1.z - view.z);

	point2.x = view.x + d*(p2.x - view.x)/(p2.z - view.z);
	point2.y = view.y + d*(p2.y - view.y)/(p2.z - view.z);

	point3.x = view.x + d*(p3.x - view.x)/(p3.z - view.z);
	point3.y = view.y + d*(p3.y - view.y)/(p3.z - view.z);

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

void MCube::move_x(int step) {
	for (int i = 0; i < 8; i++) {
		points[i].x += step;
	}
}

void MCube::move_y(int step) {
	for (int i = 0; i < 8; i++) {
		points[i].y += step;
	}
}

void MCube::move_z(int step) {
	for (int i = 0; i < 8; i++) {
		points[i].z += step;
	}
}


void MCube::rotate_x(int angle) {
	for (int i = 0; i < 8; i++) {
		MPoint p = points[i];
		points[i].y = (int)(p.y * cos(angle*pi/180.0) - p.z * sin(angle*pi/180.0));
		points[i].z = (int)(p.y * sin(angle*pi/180.0) + p.z * cos(angle*pi/180.0));
	}

}
void MCube::rotate_y(int angle) {
	for (int i = 0; i < 8; i++) {
		MPoint p = points[i];
		points[i].x = (int)(p.x * cos(angle*pi/180.0) + p.z * sin(angle*pi/180.0));
		points[i].z = (int)(-p.x * sin(angle*pi/180.0) + p.z * cos(angle*pi/180.0)); 
	}

}
void MCube::rotate_z(int angle) {
	for (int i = 0; i < 8; i++) {
		MPoint p = points[i];
		points[i].x = (int)(p.x * cos(angle*pi/180.0) - p.y * sin(angle*pi/180.0));
		points[i].y = (int)(p.x * sin(angle*pi/180.0) + p.y * cos(angle*pi/180.0));
	}
}