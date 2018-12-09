// MPoint.cpp: implementation of the MPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK1112.h"
#include "MPoint.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MPoint::MPoint()
{

}
MPoint::MPoint(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

MPoint::~MPoint()
{

}
