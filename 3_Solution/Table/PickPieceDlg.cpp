#include "stdafx.h"
#include "NetChess.h"
#include "PickPieceDlg.h"
#include "NetChessDoc.h"
#include "NetChessView.h"

CPickPieceDlg::CPickPieceDlg(CWnd* pParent)
	: CDialog(CPickPieceDlg::IDD, pParent)
{
	m_static_status = _T("Nu s-a selectat nimic");
	m_piecked_piece = -1;
	m_piece_type = BLANK;
	m_piece_color = NONE;
}


void CPickPieceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_STATUS, m_static_status);
}


BEGIN_MESSAGE_MAP(CPickPieceDlg, CDialog)
	ON_BN_CLICKED(IDC_STATIC_BITMAP_BLACK, OnStaticBitmapBlack)
	ON_BN_CLICKED(IDC_STATIC_BITMAP_BLACK_KING, OnStaticBitmapBlackKing)
	ON_BN_CLICKED(IDC_STATIC_BITMAP_WHITE, OnStaticBitmapWhite)
	ON_BN_CLICKED(IDC_STATIC_BITMAP_WHITE_KING, OnStaticBitmapWhiteKing)
	ON_BN_CLICKED(IDC_STATIC_EMPTY, OnStaticEmpty)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CPickPieceDlg::OnStaticBitmapBlack() 
{
	m_piecked_piece = CHECKERS_BLACK;
	m_piece_type = NORMAL;
	m_piece_color = BLACK;
	m_static_status ="Selected Black Checker";
	UpdateData(FALSE);
	
}

void CPickPieceDlg::OnStaticBitmapBlackKing() 
{
	m_piecked_piece = CHECKERS_BLACK_KING;
	m_piece_type = KING;
	m_piece_color = BLACK;
	m_static_status ="Selected Black King";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticBitmapWhite() 
{
	m_piecked_piece = CHECKERS_WHITE;
	m_piece_type = NORMAL;
	m_piece_color = WHITE;
	m_static_status ="Selected White checker";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticBitmapWhiteKing() 
{
	m_piecked_piece = CHECKERS_WHITE_KING;
	m_piece_type = KING;
	m_piece_color = WHITE;
	m_static_status ="Selected White King";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticEmpty() 
{
	m_piecked_piece = -1;
	m_piece_type = BLANK;
	m_piece_color = NONE;
	m_static_status ="Selected Blank";
	UpdateData(FALSE);	
}

BOOL CPickPieceDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	return TRUE;
}

void CPickPieceDlg::OnPaint() 
{
	CPaintDC dc(this);
	{
 		CWnd *pwnd = GetDlgItem(IDC_STATIC_BITMAP_BLACK);
		CRect rect;
		pwnd->GetClientRect(rect);
		CDC *pdc = pwnd->GetDC();
		CRect rect1(rect.left+5,rect.top+5,rect.right-5,rect.bottom-5);
		pdc->Ellipse(rect1);
		CRgn rgn;						 
		rgn.CreateEllipticRgn(rect1.left, rect1.top, rect1.right, rect1.bottom);	
		CBrush brush(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_optDlg.m_crefBlackPieceColor);								 
		pdc->FillRgn(&rgn,&brush );
		pwnd->ReleaseDC(pdc);
		UpdateData(FALSE);
	}
	{
 		CWnd *pwnd = GetDlgItem(IDC_STATIC_BITMAP_BLACK_KING);
		CRect rect;
		pwnd->GetClientRect(rect);
		CDC *pdc = pwnd->GetDC();
		CRect rect1(rect.left+5,rect.top+5,rect.right-5,rect.bottom-5);
		pdc->Ellipse(rect1);
		CRgn rgn;						 
		rgn.CreateEllipticRgn(rect1.left, rect1.top, rect1.right, rect1.bottom);	
		CBrush brush(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_optDlg.m_crefBlackPieceColor);								 
		pdc->FillRgn(&rgn,&brush );		 
		POINT pt[6] = {
							{rect.left+15,rect.top+20},
							{rect.right -15, rect.top+20},
							{rect.left+15, rect.bottom - 15},
							{rect.left + 25,rect.top +15},
							{rect.right-15,rect.bottom-15},
							{rect.left+15,rect.top+20}};
 		pdc->Polyline(pt,6); 
		pwnd->ReleaseDC(pdc);

		UpdateData(FALSE);
	}
	{
 		CWnd *pwnd = GetDlgItem(IDC_STATIC_BITMAP_WHITE);
		CRect rect;
		pwnd->GetClientRect(rect);
		CDC *pdc = pwnd->GetDC();
		
		CBrush brush(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_optDlg.m_crefWhitePieceColor);								 
		pdc->SetBkColor(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_optDlg.m_crefWhitePieceColor);
		CRect rect1(rect.left+5,rect.top+5,rect.right-5,rect.bottom-5);

		pdc->Ellipse(rect1);
		CRgn rgn;						 
		rgn.CreateEllipticRgn(rect1.left, rect1.top, rect1.right, rect1.bottom);	
		 
		pdc->FillRgn(&rgn,&brush );
		pwnd->ReleaseDC(pdc);
		UpdateData(FALSE);
	}
	{
 		CWnd *pwnd = GetDlgItem(IDC_STATIC_BITMAP_WHITE_KING);
		CRect rect;
		pwnd->GetClientRect(rect);
		CDC *pdc = pwnd->GetDC();
		CRect rect1(rect.left+5,rect.top+5,rect.right-5,rect.bottom-5);
		pdc->Ellipse(rect1);
		CRgn rgn;						 
		rgn.CreateEllipticRgn(rect1.left, rect1.top, rect1.right, rect1.bottom);	
		CBrush brush(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_optDlg.m_crefWhitePieceColor);								 
		pdc->FillRgn(&rgn,&brush );		 
		POINT pt[6] = {
							{rect.left+15,rect.top+20},
							{rect.right -15, rect.top+20},
							{rect.left+15, rect.bottom - 15},
							{rect.left + 25,rect.top +15},
							{rect.right-15,rect.bottom-15},
							{rect.left+15,rect.top+20}};
 		pdc->Polyline(pt,6); 
		pwnd->ReleaseDC(pdc);

		UpdateData(FALSE);
	}
}
