// TypeList.cpp: implementation of the TypeList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGWORK1112.h"
#include "TypeList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TypeList::TypeList()
{

}

TypeList::~TypeList() {
	for (int i=0;i<GetSize();i++) {
		delete GetAt(i);
	}
}
void TypeList::clearList() {
	for (int i = 0; i < this->GetSize(); i++) {
		delete GetAt(i);
	}
	this->RemoveAll();
}
