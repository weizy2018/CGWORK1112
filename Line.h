// Line.h: interface for the Line class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__D5D33B1B_EBF8_401D_8134_C8C9795C2E68__INCLUDED_)
#define AFX_LINE_H__D5D33B1B_EBF8_401D_8134_C8C9795C2E68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BasicType.h"

class Line : public BasicType {
public:
	Line();
	Line(CPoint startPoint, CPoint endPoint);
	virtual ~Line();
public:
	void draw(CDC* pDC);
	int getType();
	void addPoint(CPoint point) {}

};

#endif // !defined(AFX_LINE_H__D5D33B1B_EBF8_401D_8134_C8C9795C2E68__INCLUDED_)
