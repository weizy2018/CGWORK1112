// MCube.h: interface for the MCube class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MCUBE_H__008AF51F_F80B_418D_862E_F0E858889425__INCLUDED_)
#define AFX_MCUBE_H__008AF51F_F80B_418D_862E_F0E858889425__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BasicType.h"
#include "MPoint.h"

class MCube : public BasicType  
{
public:
	MCube();
	virtual ~MCube();
	void draw(CDC* pDC);
	int getType();
	void addPoint(CPoint point) {}
public:
	void move_x(int step);

	void move_y(int step);

	void move_z(int step);

	void rotate_x(int angle);
	void rotate_y(int angle);
	void rotate_z(int angle);

private:
	int face[6][4];
	//int edge[12][2];
	MPoint points[8];

	//int normalVector[6][3];
	MPoint normalVector[6];
	MPoint view;

	COLORREF colors[6];
private:
	void calNormalVector();
private:
	void init();
	bool isView(int f);
	void drawFace(int i, CDC * pDC);

};

#endif // !defined(AFX_MCUBE_H__008AF51F_F80B_418D_862E_F0E858889425__INCLUDED_)
