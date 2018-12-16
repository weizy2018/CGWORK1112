// InputColorDlgB.cpp : implementation file
//

#include "stdafx.h"
#include "CGWORK1112.h"
#include "InputColorDlgB.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// InputColorDlgB dialog


InputColorDlgB::InputColorDlgB(CWnd* pParent /*=NULL*/)
	: CDialog(InputColorDlgB::IDD, pParent)
{
	//{{AFX_DATA_INIT(InputColorDlgB)
	border_b = 0;
	border_g = 0;
	border_r = 0;
	curve_b = 0;
	curve_g = 0;
	curve_r = 0;
	//}}AFX_DATA_INIT
}


void InputColorDlgB::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(InputColorDlgB)
	DDX_Text(pDX, IDC_BORDER_B, border_b);
	DDX_Text(pDX, IDC_BORDER_G, border_g);
	DDX_Text(pDX, IDC_BORDER_R, border_r);
	DDX_Text(pDX, IDC_CURVE_B, curve_b);
	DDX_Text(pDX, IDC_CURVE_G, curve_g);
	DDX_Text(pDX, IDC_CURVE_R, curve_r);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(InputColorDlgB, CDialog)
	//{{AFX_MSG_MAP(InputColorDlgB)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// InputColorDlgB message handlers
