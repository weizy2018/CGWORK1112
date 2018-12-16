// Translation.cpp : implementation file
//

#include "stdafx.h"
#include "CGWORK1112.h"
#include "Translation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Translation dialog


Translation::Translation(CWnd* pParent /*=NULL*/)
	: CDialog(Translation::IDD, pParent)
{
	//{{AFX_DATA_INIT(Translation)
	angle = 10;
	step = 10;
	//}}AFX_DATA_INIT
}


void Translation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Translation)
	DDX_Text(pDX, IDC_ANGLE, angle);
	DDX_Text(pDX, IDC_STEP, step);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Translation, CDialog)
	//{{AFX_MSG_MAP(Translation)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Translation message handlers
