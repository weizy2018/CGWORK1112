// CGWORK1112Doc.cpp : implementation of the CCGWORK1112Doc class
//

#include "stdafx.h"
#include "CGWORK1112.h"

#include "CGWORK1112Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCGWORK1112Doc

IMPLEMENT_DYNCREATE(CCGWORK1112Doc, CDocument)

BEGIN_MESSAGE_MAP(CCGWORK1112Doc, CDocument)
	//{{AFX_MSG_MAP(CCGWORK1112Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCGWORK1112Doc construction/destruction

CCGWORK1112Doc::CCGWORK1112Doc()
{
	// TODO: add one-time construction code here
	

}

CCGWORK1112Doc::~CCGWORK1112Doc() {


}

BOOL CCGWORK1112Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCGWORK1112Doc serialization

void CCGWORK1112Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCGWORK1112Doc diagnostics

#ifdef _DEBUG
void CCGWORK1112Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCGWORK1112Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCGWORK1112Doc commands
