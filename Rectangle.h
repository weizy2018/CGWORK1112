// Rectangle.h: interface for the Rectangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTANGLE_H__0E78303C_1950_45FF_B637_CC7C54366B48__INCLUDED_)
#define AFX_RECTANGLE_H__0E78303C_1950_45FF_B637_CC7C54366B48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BasicType.h"

class Rectangle : public BasicType  
{
public:
	Rectangle();
	virtual ~Rectangle();
public:
	void draw(CDC* pDC, COLORREF color);
	int getType();

};

#endif // !defined(AFX_RECTANGLE_H__0E78303C_1950_45FF_B637_CC7C54366B48__INCLUDED_)
