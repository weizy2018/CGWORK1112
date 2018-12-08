// CGWORK1112.h : main header file for the CGWORK1112 application
//

#if !defined(AFX_CGWORK1112_H__750E82EC_AFD0_4961_B70F_EB5F6EC38CE1__INCLUDED_)
#define AFX_CGWORK1112_H__750E82EC_AFD0_4961_B70F_EB5F6EC38CE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCGWORK1112App:
// See CGWORK1112.cpp for the implementation of this class
//

class CCGWORK1112App : public CWinApp
{
public:
	CCGWORK1112App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGWORK1112App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCGWORK1112App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGWORK1112_H__750E82EC_AFD0_4961_B70F_EB5F6EC38CE1__INCLUDED_)
