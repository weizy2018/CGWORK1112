// Rectangle.cpp: implementation of the Rectangle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK1112.h"
#include "Rectangle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Rectangle::Rectangle()
{

}

Rectangle::~Rectangle()
{

}

void Rectangle::draw(CDC* pDC, COLORREF color) {

}
int Rectangle::getType() {
	return RECT;
}
