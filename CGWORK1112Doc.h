// CGWORK1112Doc.h : interface of the CCGWORK1112Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CGWORK1112DOC_H__83F8ACEC_F285_45C0_B256_AF7CDA5940C5__INCLUDED_)
#define AFX_CGWORK1112DOC_H__83F8ACEC_F285_45C0_B256_AF7CDA5940C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TypeList.h"
#include "BasicType.h"


class CCGWORK1112Doc : public CDocument
{
protected: // create from serialization only
	CCGWORK1112Doc();
	DECLARE_DYNCREATE(CCGWORK1112Doc)

// Attributes
public:

// Operations
public:
private:

public:


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGWORK1112Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCGWORK1112Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCGWORK1112Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGWORK1112DOC_H__83F8ACEC_F285_45C0_B256_AF7CDA5940C5__INCLUDED_)
