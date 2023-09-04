#include "stdafx.h"
#include "NetChess.h"
#include "MyColorDialog.h"
#include "NetChessDoc.h"
#include "NetChessView.h"


IMPLEMENT_DYNAMIC(CMyColorDialog, CColorDialog)

CMyColorDialog::CMyColorDialog(COLORREF clrInit, DWORD dwFlags, CWnd* pParentWnd) : CColorDialog(clrInit, dwFlags, pParentWnd)
{
}


BEGIN_MESSAGE_MAP(CMyColorDialog, CColorDialog)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


void CMyColorDialog::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CColorDialog::OnLButtonUp(nFlags, point);
}

void CMyColorDialog::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CColorDialog::OnLButtonDown(nFlags, point);
}
