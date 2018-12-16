#if !defined(AFX_INPUTCOLORDLGB_H__B86DF25B_19BA_4EDB_A515_3388A6A85561__INCLUDED_)
#define AFX_INPUTCOLORDLGB_H__B86DF25B_19BA_4EDB_A515_3388A6A85561__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputColorDlgB.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// InputColorDlgB dialog

class InputColorDlgB : public CDialog
{
// Construction
public:
	InputColorDlgB(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(InputColorDlgB)
	enum { IDD = IDD_DIALOG3 };
	int		border_b;
	int		border_g;
	int		border_r;
	int		curve_b;
	int		curve_g;
	int		curve_r;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(InputColorDlgB)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(InputColorDlgB)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTCOLORDLGB_H__B86DF25B_19BA_4EDB_A515_3388A6A85561__INCLUDED_)
