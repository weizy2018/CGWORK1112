// BasicType.cpp: implementation of the BasicType class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK1112.h"
#include "BasicType.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BasicType::BasicType()
{

}

BasicType::~BasicType()
{

}
void BasicType::setStartPoint(CPoint point){
	startPoint = point;
}
void BasicType::setEndPoint(CPoint point) {
	endPoint = point;
}
CPoint BasicType::getStartPoint() {
	return startPoint;
}
CPoint BasicType::getEndPoint() {
	return endPoint;
}

void BasicType::draw(CDC *pDC, COLORREF color) {

}
int BasicType::getType() {
	return 0;
}

void BasicType::addPoint(CPoint point) {

}

