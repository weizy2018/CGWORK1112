#if !defined(AFX_INPUTCOLORDLG2_H__0D063291_3600_4711_96F5_AA0023D687FE__INCLUDED_)
#define AFX_INPUTCOLORDLG2_H__0D063291_3600_4711_96F5_AA0023D687FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputColorDlg2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// InputColorDlg2 dialog

class InputColorDlg2 : public CDialog
{
// Construction
public:
	InputColorDlg2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(InputColorDlg2)
	enum { IDD = IDD_DIALOG2 };
	int		border_b;
	int		border_g;
	int		border_r;
	int		fill_b;
	int		fill_g;
	int		fill_r;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(InputColorDlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(InputColorDlg2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTCOLORDLG2_H__0D063291_3600_4711_96F5_AA0023D687FE__INCLUDED_)
