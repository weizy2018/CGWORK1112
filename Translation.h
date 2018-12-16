#if !defined(AFX_TRANSLATION_H__45165D51_47F7_4330_A116_115A389F9D78__INCLUDED_)
#define AFX_TRANSLATION_H__45165D51_47F7_4330_A116_115A389F9D78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Translation.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Translation dialog

class Translation : public CDialog
{
// Construction
public:
	Translation(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Translation)
	enum { IDD = IDD_DIALOG4 };
	int		angle;
	int		step;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Translation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Translation)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSLATION_H__45165D51_47F7_4330_A116_115A389F9D78__INCLUDED_)
