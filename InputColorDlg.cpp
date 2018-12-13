// InputColorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CGWORK1112.h"
#include "InputColorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// InputColorDlg dialog


InputColorDlg::InputColorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(InputColorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(InputColorDlg)
		// NOTE: the ClassWizard will add member initialization here
	rect_r = 0;
	rect_g = 0;
	rect_b = 0;

	cir_r = 0;
	cir_g = 0;
	cir_b = 0;
	//}}AFX_DATA_INIT
}


void InputColorDlg::DoDataExchange(CDataExchange* pDX)
{
	//DDX_Text(pDX, IDC_EDIT1, m_x1);
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(InputColorDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Text(pDX, IDC_RECT_R, rect_r);
	DDX_Text(pDX, IDC_RECT_G, rect_g);
	DDX_Text(pDX, IDC_RECT_B, rect_b);

	DDX_Text(pDX, IDC_CIRCULAR_R, cir_r);
	DDX_Text(pDX, IDC_CIRCULAR_G, cir_g);
	DDX_Text(pDX, IDC_CIRCULAR_B, cir_b);
	//}}AFX_DATA_MAP
	
}


BEGIN_MESSAGE_MAP(InputColorDlg, CDialog)
	//{{AFX_MSG_MAP(InputColorDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// InputColorDlg message handlers
