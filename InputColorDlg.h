#if !defined(AFX_INPUTCOLORDLG_H__B30B4980_4742_4906_973F_654D99A97DB7__INCLUDED_)
#define AFX_INPUTCOLORDLG_H__B30B4980_4742_4906_973F_654D99A97DB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputColorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// InputColorDlg dialog



class InputColorDlg : public CDialog
{
// Construction
public:
	InputColorDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(InputColorDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	int rect_r;
	int rect_g;
	int rect_b;

	int cir_r;
	int cir_g;
	int cir_b;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(InputColorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(InputColorDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTCOLORDLG_H__B30B4980_4742_4906_973F_654D99A97DB7__INCLUDED_)
