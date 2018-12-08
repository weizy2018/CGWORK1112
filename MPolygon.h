// MPolygon.h: interface for the MPolygon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MPOLYGON_H__4C953015_3BF6_40C5_BED1_15BDF03CF3EF__INCLUDED_)
#define AFX_MPOLYGON_H__4C953015_3BF6_40C5_BED1_15BDF03CF3EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BasicType.h"
#include "stdafx.h"


class MPolygon : public BasicType  
{
public:
	MPolygon();
	virtual ~MPolygon();
public:
	void draw(CDC * pDC, COLORREF color);
	int getType();
	void addPoint(CPoint point);
private:
	CObArray points;

};

#endif // !defined(AFX_MPOLYGON_H__4C953015_3BF6_40C5_BED1_15BDF03CF3EF__INCLUDED_)
