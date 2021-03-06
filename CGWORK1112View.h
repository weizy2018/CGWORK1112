// CGWORK1112View.h : interface of the CCGWORK1112View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CGWORK1112VIEW_H__3BB6E831_44A6_46ED_8AE5_8647F1A6B63B__INCLUDED_)
#define AFX_CGWORK1112VIEW_H__3BB6E831_44A6_46ED_8AE5_8647F1A6B63B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MPolygon.h"
#include "MBezier.h"
#include "MCube.h"

#define NONE		0
#define RECT		1
#define CIRCULAR	2
#define POLYGON		3
#define CUBE		4
#define BEZIER		5

#define LINE		6

#define MOVE_X		1
#define MOVE_Y		2
#define MOVE_Z		3
#define SPIN_X		4
#define SPIN_Y		5
#define SPIN_Z		6




class CCGWORK1112View : public CView
{
protected: // create from serialization only
	CCGWORK1112View();
	DECLARE_DYNCREATE(CCGWORK1112View)

// Attributes
public:
	CCGWORK1112Doc* GetDocument();
private:
	CPoint	startPoint;
	CPoint	endPoint;

	HCURSOR cursor;

	bool	LButtonDown;
	int		type;
	bool	isDraw;
	
	TypeList * list;

	MPolygon * polygon;
	MBezier * bezier;
	int count;

	int cube_Performance;
	MCube * cube;
	int step;
	int angle;
private:
	int category;

private:
	COLORREF rectColor;
	COLORREF cirColor;

	COLORREF borderColor;
	COLORREF fillColor;

	COLORREF bezierBorder;
	COLORREF bezierCurve;
public:
	void clear();


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGWORK1112View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void drawLButtonDblClk(UINT nFlags, CPoint point);
	void DrawLButtonUp(UINT nFlags, CPoint point);
	void DrawMouseMove(UINT nFlags, CPoint point);
	void DrawLButtonDown(UINT nFlags, CPoint point);
	virtual ~CCGWORK1112View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCGWORK1112View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDrawBezier();
	afx_msg void OnDrawCircular();
	afx_msg void OnDrawCube();
	afx_msg void OnDrawPolygon();
	afx_msg void OnDrawRect();
	afx_msg void OnDrawLine();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSetColor1();
	afx_msg void OnSetColor2();
	afx_msg void OnSerColor3();
	afx_msg void OnCleanScreen();
	afx_msg void OnMoveX();
	afx_msg void OnMoveY();
	afx_msg void OnMoveZ();
	afx_msg void OnSpinX();
	afx_msg void OnSpinY();
	afx_msg void OnSpinZ();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetData();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CGWORK1112View.cpp
inline CCGWORK1112Doc* CCGWORK1112View::GetDocument()
   { return (CCGWORK1112Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGWORK1112VIEW_H__3BB6E831_44A6_46ED_8AE5_8647F1A6B63B__INCLUDED_)
