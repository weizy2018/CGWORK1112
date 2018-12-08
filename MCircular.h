// MCircular.h: interface for the MCircular class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MCIRCULAR_H__2A6C8B37_075B_4582_868E_E8DA2D022FE9__INCLUDED_)
#define AFX_MCIRCULAR_H__2A6C8B37_075B_4582_868E_E8DA2D022FE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BasicType.h"

class MCircular : public BasicType  
{
public:
	MCircular();
	MCircular(CPoint startPoint, CPoint endPoint);
	virtual ~MCircular();

public:
	void draw(CDC* pDC, COLORREF color);
	int getType();
	void addPoint(CPoint point) {}

};

#endif // !defined(AFX_MCIRCULAR_H__2A6C8B37_075B_4582_868E_E8DA2D022FE9__INCLUDED_)
