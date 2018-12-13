#if !defined(AFX_OLORINPUT_H__46A75DEE_7B23_4100_A0EC_F68D851F2262__INCLUDED_)
#define AFX_OLORINPUT_H__46A75DEE_7B23_4100_A0EC_F68D851F2262__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// olorInput.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ColorInput dialog

class ColorInput : public CDialog
{
// Construction
public:
	ColorInput(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ColorInput)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ColorInput)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ColorInput)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLORINPUT_H__46A75DEE_7B23_4100_A0EC_F68D851F2262__INCLUDED_)
