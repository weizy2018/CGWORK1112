// BasicType.h: interface for the BasicType class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASICTYPE_H__90C36BDD_6AEB_4E3F_BAAD_8B6D3EDC0558__INCLUDED_)
#define AFX_BASICTYPE_H__90C36BDD_6AEB_4E3F_BAAD_8B6D3EDC0558__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define NONE		0
#define RECT		1
#define CIRCULAR	2
#define POLYGON		3
#define CUBE		4
#define BEZIER		5

#define LINE		6

class BasicType : public CObject  
{
public:
	BasicType();
	virtual ~BasicType();
protected:
	CPoint startPoint;
	CPoint endPoint;
	COLORREF color;

public:
	void setStartPoint(CPoint point);
	void setEndPoint(CPoint point);
	CPoint getStartPoint();
	CPoint getEndPoint();

	void setColor(COLORREF color);

	virtual void draw(CDC* pDC);
	virtual int getType();
	virtual void addPoint(CPoint point);

};

#endif // !defined(AFX_BASICTYPE_H__90C36BDD_6AEB_4E3F_BAAD_8B6D3EDC0558__INCLUDED_)
