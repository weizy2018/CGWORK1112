// olorInput.cpp : implementation file
//

#include "stdafx.h"
#include "CGWORK1112.h"
#include "olorInput.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// ColorInput dialog


ColorInput::ColorInput(CWnd* pParent /*=NULL*/)
	: CDialog(ColorInput::IDD, pParent)
{
	//{{AFX_DATA_INIT(ColorInput)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ColorInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ColorInput)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ColorInput, CDialog)
	//{{AFX_MSG_MAP(ColorInput)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ColorInput message handlers
