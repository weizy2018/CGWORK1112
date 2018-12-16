// InputColorDlg2.cpp : implementation file
//

#include "stdafx.h"
#include "CGWORK1112.h"
#include "InputColorDlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// InputColorDlg2 dialog


InputColorDlg2::InputColorDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(InputColorDlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(InputColorDlg2)
	border_b = 0;
	border_g = 0;
	border_r = 0;
	fill_b = 0;
	fill_g = 0;
	fill_r = 0;
	//}}AFX_DATA_INIT
}


void InputColorDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(InputColorDlg2)
	DDX_Text(pDX, IDC_BORDER_B, border_b);
	DDX_Text(pDX, IDC_BORDER_G, border_g);
	DDX_Text(pDX, IDC_BORDER_R, border_r);
	DDX_Text(pDX, IDC_FILL_B, fill_b);
	DDX_Text(pDX, IDC_FILL_G, fill_g);
	DDX_Text(pDX, IDC_FILL_R, fill_r);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(InputColorDlg2, CDialog)
	//{{AFX_MSG_MAP(InputColorDlg2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// InputColorDlg2 message handlers
