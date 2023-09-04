#include "stdafx.h"
#include "NetChess.h"
#include "NetChessDoc.h"

IMPLEMENT_DYNCREATE(CNetChessDoc, CDocument)
BEGIN_MESSAGE_MAP(CNetChessDoc, CDocument)
END_MESSAGE_MAP()

CNetChessDoc::CNetChessDoc()
{

}

CNetChessDoc::~CNetChessDoc()
{
}

BOOL CNetChessDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

// CNetChessDoc serialization

void CNetChessDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{

	}
	else
	{
	}
}
