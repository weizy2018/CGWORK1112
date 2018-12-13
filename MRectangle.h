// MRectangle.h: interface for the MRectangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MRECTANGLE_H__38894CC1_04D0_491E_9AD1_713D5A70F962__INCLUDED_)
#define AFX_MRECTANGLE_H__38894CC1_04D0_491E_9AD1_713D5A70F962__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BasicType.h"

class MRectangle : public BasicType  
{
public:
	MRectangle();
	MRectangle(CPoint startPoint, CPoint endPoint);
	virtual ~MRectangle();
public:
	void draw(CDC* pDC);
	int getType();
	void addPoint(CPoint point) {}

};

#endif // !defined(AFX_MRECTANGLE_H__38894CC1_04D0_491E_9AD1_713D5A70F962__INCLUDED_)
