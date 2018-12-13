// MBezier.h: interface for the MBezier class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MBEZIER_H__C8A9B948_BA51_41D2_993E_2A5D7232E39B__INCLUDED_)
#define AFX_MBEZIER_H__C8A9B948_BA51_41D2_993E_2A5D7232E39B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BasicType.h"

#define POINT_COUNT  4

class MBezier : public BasicType  
{
public:
	MBezier();
	virtual ~MBezier();

public:
	virtual void draw(CDC* pDC);
	virtual int getType();
	virtual void addPoint(CPoint point);
private:
	void drawLine(CDC* pDC);
	CPoint decas(double t);
private:
	int count;
	CPoint points[4];

};

#endif // !defined(AFX_MBEZIER_H__C8A9B948_BA51_41D2_993E_2A5D7232E39B__INCLUDED_)
