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
	count = 0;

}

MPolygon::~MPolygon()
{

}
void MPolygon::draw(CDC * pDC) {
	int i, j;
	for (i = 0; i < count - 1; i++) {
		Line line(points[i], points[i+1]);
		line.setColor(color);
		line.draw(pDC);
	}
	Line li(points[count - 1], points[0]);
	li.setColor(color);
	li.draw(pDC);
	
	int width = (16+4)*5;
	int height = 30+8;
	int min_x = points[0].x;
	int max_x = points[0].x;
	int min_y = points[0].y;
	int max_y = points[0].y;
	for (i = 1; i < count; i++) {
		if (points[i].x < min_x)
			min_x = points[i].x;
		if (points[i].x > max_x)
			max_x = points[i].x;
		if (points[i].y < min_y)
			min_y = points[i].y;
		if (points[i].y > max_y)
			max_y = points[i].y;
	}
	int w = min_x/20;
	min_x = w*20;
	int a = w%5;

	int h = min_y/height;
	min_y = h*height;

	for (i = min_y; i < max_y; i++) {
		int type = a;
		for (j = min_x; j < max_x; j++) {
			//MPolygon::printPixel(CDC * pDC, int x, int y, int type, COLORREL color)
			
			printPixel(pDC, j, i, type%5);
			j += 20;
			j--;
			type++;
		}
		i += height;
		i--;
	}





}

int MPolygon::getType() {
	return POLYGON;
}

void MPolygon::addPoint(CPoint point) {
	points[count] = point;
	count++;
}

bool MPolygon::isInner(int x, int y) {
	points[count] = points[0];
	int yy;
	int m = -1;
	int i = 0; 
	while (i < count) {
		if ((x < points[i].x && x < points[i+1].x) || (x >= points[i].x && x >= points[i+1].x) || (y < points[i].y && y < points[i+1].y)) {

		} else {
			yy = points[i].y + (x - points[i].x)*(points[i+1].y - points[i].y)/(points[i+1].x - points[i].x);
			if (yy == y)
				return true;
			if (yy < y)
				m = m*(-1);
		}
		i++;
	}
	if(m == -1)
		return false;
	else 
		return true;
}

void MPolygon::printPixel(CDC * pDC, int x, int y, int type) {
	bool two[30][16] = 
					{{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
					{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
					{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
					{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
					{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
					{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
					{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
					{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
					{0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
					{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
					{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
					{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
					{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
					{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
					{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
					{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
					{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	/*
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 4; j++) {
			pDC->SetPixel(100+j, 100+i, RGB(255, 0, 0));
		}
	}
	for (i = 0; i < 30; i++) {
		for (int j = 0; j < 16; j++) {
			if (two[i][j]) {
				pDC->SetPixel(108+j, 100+i, RGB(255, 0, 0));
			}
		}
	}*/
	int i, j;
	//print 1
	if (type == 0 || type == 1 || type == 2) {
		x += 12;
		//bool MPolygon::isInner(int x, int y) {
		for (i = 0; i < 30; i++) {
			for (j = 0; j < 4; j++) {
				if (isInner(x+j, y+i))
					pDC->SetPixel(x+j, y+i, color2);
			}
		}

	} else if (type == 3) {
		for (i = 0; i < 30; i++) {
			for (j = 0; j < 16; j++){
				if (two[i][j] && isInner(x+j, y+i))
					pDC->SetPixel(x+j, y+i, color2);
			}
		}
	}
}

