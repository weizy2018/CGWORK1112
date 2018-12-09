// MPoint.h: interface for the MPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MPOINT_H__13C7C447_9C3D_48BD_A837_A66791E4ED9D__INCLUDED_)
#define AFX_MPOINT_H__13C7C447_9C3D_48BD_A837_A66791E4ED9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MPoint  
{
public:
	MPoint();
	MPoint(int x, int y, int z);
	virtual ~MPoint();
public:
	int x;
	int y;
	int z;

};

#endif // !defined(AFX_MPOINT_H__13C7C447_9C3D_48BD_A837_A66791E4ED9D__INCLUDED_)
