// MCube.cpp: implementation of the MCube class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK1112.h"
#include "MCube.h"
#include "cmath"
#include <stack>

using namespace std;

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

	view.x = 200;
	view.y = 0;
	view.z = -300;

	init();
	

}

MCube::~MCube()
{

}

void MCube::draw(CDC* pDC) {
	FILE * f;
	f = fopen("test.txt", "w");
	fclose(f);

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
	points[0] = MPoint(200 + 200, 100 + 100, 100);
	points[1] = MPoint(200 + 200, 200 + 100, 100);
	points[2] = MPoint(100 + 200, 200 + 100, 100);
	points[3] = MPoint(100 + 200, 100 + 100, 100);
	points[4] = MPoint(200 + 200, 100 + 100, 200);
	points[5] = MPoint(200 + 200, 200 + 100, 200);
	points[6] = MPoint(100 + 200, 200 + 100, 200);
	points[7] = MPoint(100 + 200, 100 + 100, 200);

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
	//三维转二维
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

	/*
	CPoint startPoint;
	startPoint.x = (point0.x + point2.x)/2;
	startPoint.y = (point0.y + point2.y)/2;
	this->drawColor(pDC, startPoint, colors[i]);
	*/
	Line lines[4];
	lines[0].setStartPoint(line1.getStartPoint());
	lines[0].setEndPoint(line1.getEndPoint());
	
	lines[1].setStartPoint(line2.getStartPoint());
	lines[1].setEndPoint(line2.getEndPoint());

	lines[2].setStartPoint(line3.getStartPoint());
	lines[2].setEndPoint(line3.getEndPoint());

	lines[3].setStartPoint(line4.getStartPoint());
	lines[3].setEndPoint(line4.getEndPoint());

	//processLine(lines, 4);

	//drawColor(pDC, lines, 4, colors[i]);
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
/*
void MCube::drawColor(CDC * pDC, CPoint startPoint, COLORREF col) {

	CPoint p;
	COLORREF bgColor = pDC->GetPixel(startPoint);

	stack<CPoint> s;
	s.push(startPoint);
	
	int x, y;
	int xr, xl;
	int x0, y0;

	while (!s.empty()) {
		p = s.top();
		s.pop();
		x = p.x;
		y = p.y;
		pDC->SetPixel(x, y, col);
		x0 = x + 1;
		while (pDC->GetPixel(x0, y) == bgColor) {
			pDC->SetPixel(x0, y, col);
			x0++;
		}
		xr = x0 - 1;
		x0 = x - 1;
		while (pDC->GetPixel(x0, y) == bgColor) {
			pDC->SetPixel(x0, y, col);
			x0--;
		}
		xl = x0 + 1;
		
		y0 = y;

		for (int i = 1; i >= -1; i -= 2) {
			x0 = xr;
			y = y0 + i;
			while (x0 >= xl) {
				if (pDC->GetPixel(x0, y) == bgColor) {		//下一个种子点
					s.push(CPoint(x0, y));
					break;
				} else {
					x0--;
				}
			}
		}
	}
}
*/
void MCube::processLine(Line lines[], int n) {
	CPoint startPoint1, endPoint1;
	CPoint startPoint2, endPoint2;
	CPoint start, end;
	CPoint p;
	for (int i = 0; i < n; i++) {
		Line L1, L2;
		L1.setStartPoint(lines[i].getStartPoint());
		L1.setEndPoint(lines[i].getEndPoint());
		
		L2.setStartPoint(lines[(i+1)%n].getStartPoint());
		L2.setStartPoint(lines[(i+1)%n].getEndPoint());

		startPoint1 = L1.getStartPoint();
		endPoint1 = L1.getEndPoint();

		startPoint2 = L2.getStartPoint();
		endPoint2 = L2.getEndPoint();
		
		if (startPoint1 == startPoint2) {
			p = startPoint1;
		} else if (startPoint1 == endPoint2) {
			p = startPoint1;
		} else if (endPoint1 == startPoint1) {
			p = endPoint1;
		} else if (endPoint1 == endPoint2) {
			p = endPoint1;
		}
		int y = p.y + 1;
		//对非极值点处理
		if (isInnerPoint(L1, p.y + 1) && !isInnerPoint(L2, p.y + 1)) {
			if (p == startPoint1) {
				start.x = (p.y + 1 - startPoint1.y)*(endPoint1.x - startPoint1.x)/(endPoint1.y - startPoint1.y) + startPoint1.x;
				start.y = p.y + 1;
				L1.setStartPoint(start);
			} else {
				end.x = (p.y + 1 - startPoint1.y)*(endPoint1.x - startPoint1.x)/(endPoint1.y - startPoint1.y) + startPoint1.x;
				end.y = p.y + 1;
				L1.setEndPoint(end);
			}
		} else if (!isInnerPoint(L1, p.y + 1) && isInnerPoint(L2, p.y + 1)) {
			if (p == startPoint2) {
				start.x = (p.y + 1 - startPoint2.y)*(endPoint2.x - startPoint2.x)/(endPoint2.y - startPoint2.y) + startPoint2.x;
				start.y = p.y + 1;
				L2.setStartPoint(start);
			} else {
				end.x = (p.y + 1 - startPoint2.y)*(endPoint2.x - startPoint2.x)/(endPoint2.y - startPoint2.y) + startPoint2.x;
				end.y = p.y + 1;
				L2.setEndPoint(end);
			}
		} else if (isInnerPoint(L1, p.y - 1) && !isInnerPoint(L2, p.y - 1)) {
			if (p == startPoint1) {
				start.x = (p.y - 1 - startPoint1.y)*(endPoint1.x - startPoint1.x)/(endPoint1.y - startPoint1.y) + startPoint1.x;
				start.y = p.y - 1;
				L1.setStartPoint(start);
			} else {
				end.x = (p.y - 1 - startPoint1.y)*(endPoint1.x - startPoint1.x)/(endPoint1.y - startPoint1.y) + startPoint1.x;
				end.y = p.y - 1;
				L1.setEndPoint(end);
			}
		} else if (!isInnerPoint(L1, p.y - 1) && isInnerPoint(L2, p.y - 1)) {
			if (p == startPoint2) {
				start.x = (p.y + 1 - startPoint2.y)*(endPoint2.x - startPoint2.x)/(endPoint2.y - startPoint2.y) + startPoint2.x;
				start.y = p.y - 1;
				L2.setStartPoint(start);
			} else {
				end.x = (p.y + 1 - startPoint2.y)*(endPoint2.x - startPoint2.x)/(endPoint2.y - startPoint2.y) + startPoint2.x;
				end.y = p.y - 1;
				L2.setEndPoint(end);
			}
		}
	}

}
void MCube::drawColor(CDC * pDC, Line lines[], int n, COLORREF col) {
	int y_min = lines[0].getStartPoint().y;
	int y_max = lines[0].getStartPoint().y;
	EdgeTable et[5];
	
	for (int i = 1; i < n; i++) {
		if (lines[i].getStartPoint().y < y_min)
			y_min = lines[i].getStartPoint().y;
		if (lines[i].getStartPoint().y > y_max)
			y_max = lines[i].getStartPoint().y;
		if (lines[i].getEndPoint().y < y_min)
			y_min = lines[i].getEndPoint().y;
		if (lines[i].getEndPoint().y > y_max)
			y_max = lines[i].getEndPoint().y;
	}
	int count = getEt(et, lines, y_min, n);
	FILE * f;
	f = fopen("test.txt", "a");
	fprintf(f, "count = %d\n", count);

	sortEt(et, count);
	for (int y0 = y_min; y0 < y_max; y0++) {
		//fprintf(f, "y0 = %d\n", y0);
		//et[0].x_min = et[1].x_min + et[1].k;
		fprintf(f, "count = %d y0 = %d\n",count ,y0);
		for (int k = 0; k < count; k += 2) {
			et[k].x_min = et[k].x_min + et[k].k;
			fprintf(f, "x_min1 = %ld  x_min2 = %ld\n", et[k].x_min, et[k+1].x_min);

			for ( i = et[k].x_min; i < et[k+1].x_min; i++) {
				pDC->SetPixel(i, y0, col);
				
			}
		}
		for (i = 0; i < count; i++) {
			et[i].x_min += et[i].k;
		}

		for (int j = 0; j < count; j++) {
			if (et[j].y_max == y0) {
				count = getEt(et, lines, y0 + 1, n);
				sortEt(et, count);
				fprintf(f, "count = %d\n", count);
				break;
			}
		}

	}
	fprintf(f, "\n\n");
	fclose(f);

}
bool MCube::isInnerPoint(Line & line, int y) {
	CPoint start = line.getStartPoint();
	CPoint end = line.getEndPoint();
	if ((y > start.y && y > end.y) || (y < start.y && y < end.y)) {
		return false;
	} else {
		return true;
	}
}

int MCube::getEt(EdgeTable et[], Line lines[], int y0, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		CPoint start = lines[i].getStartPoint();
		CPoint end = lines[i].getEndPoint();
		if (start.y == end.y) {						//水平的线不放入
			continue;
		} else {
			if (end.x == start.x){					//垂直于x轴
				et[count].k = 0;
				et[count].x_min = end.x;			//或者start.x
				et[count].y_max = max(start.y, end.y);
			}
			else {
				double k = (end.y*1.0 - start.y*1.0)/(end.x*1.0 - start.x*1.0);	//斜率
				et[count].k = 1/k;
				//et[count].x_min = (y0 - start.y)/k + start.x;
				et[count].x_min = (y0 - start.y)*(end.x - start.x)/(end.y - start.y) + start.x;
				et[count].y_max = max(start.y, end.y);
			}
			count++;
		}
	}
	return count;
}

void MCube::sortEt(EdgeTable ets[], int count) {
	for (int i = 0; i < count - 1; i++) {
		EdgeTable e = ets[i];
		for (int j = i+1; j < count; j++) {
			if (ets[j].x_min < e.x_min)
				e = ets[j];
		}
		EdgeTable temp = ets[i];
		ets[i] = e;
		e = temp;
	}

}

int MCube::m_max(int a, int b) {
	return a > b ? a : b;
}
int MCube::m_min(int a, int b) {
	return a < b ? a : b;
}
