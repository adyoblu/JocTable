#include "stdafx.h"
#include "NetChess.h"
#include "MyColorDialog.h"
#include "Options.h"
#include "NetChessDoc.h"
#include "NetChessView.h"

COptions::COptions(CWnd* pParent)
	: CDialog(COptions::IDD, pParent)
{
	m_check_white_on_top = FALSE;
	COLORREF w(RGB(25,100,120)),b(RGB(128,128,128));
	m_crefWhiteColor =  w;
	m_crefBlackColor =  b;
	COLORREF wp(RGB(255,255,255)),bp(RGB(0,0,0));
	m_crefWhitePieceColor =  wp;
	m_crefBlackPieceColor =  bp;
	m_pieceType = 1;
	m_whiteClrDlg = false;
	m_blackClrDlg = false;
}


void COptions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_WHITE_ON_TOP, m_check_white_on_top);
}


BEGIN_MESSAGE_MAP(COptions, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_BLACK_COLOR, OnButtonBlackColor)
	ON_BN_CLICKED(IDC_BUTTON_WHITE_COLOR, OnButtonWhiteColor)
	ON_BN_CLICKED(IDC_CHECK_WHITE_ON_TOP, OnCheckWhiteOnTop)
	ON_BN_CLICKED(IDC_STATIC_PIECE_TYPE1, OnStaticPieceType1)
	ON_BN_CLICKED(IDC_STATIC_PIECE_TYPE2, OnStaticPieceType2)
	ON_BN_CLICKED(IDC_STATIC_PIECE_TYPE3, OnStaticPieceType3)
	ON_BN_CLICKED(IDC_BUTTON_WHITE_PIECE_COLOR, OnButtonWhitePieceColor)
	ON_BN_CLICKED(IDC_STATIC_BLACK_PIECE_COLOR, OnStaticBlackPieceColor)
	ON_BN_CLICKED(IDC_BUTTON_BLACK_PIECE_COLOR, OnButtonBlackPieceColor)
END_MESSAGE_MAP()

void COptions::OnButtonBlackColor() 
{
	CMyColorDialog cdlg;
	if(cdlg.DoModal() == IDOK)
	{
		m_crefBlackColor=cdlg.GetColor();		 
		CStatic *pblack = (CStatic*)GetDlgItem(IDC_STATIC_BLACK);
		CRect rect;
		CClientDC dc((CWnd*)pblack);
		pblack->GetClientRect(rect);		 
		CBrush brush(m_crefBlackColor);
		CBrush *pOldBrush = (CBrush*)dc.SelectObject(brush); 
		dc.FillRect(&rect,&brush);
		UpdateData(FALSE);
		m_whiteClrDlg = false;
		m_blackClrDlg = true;
	}	
	((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);
}

void COptions::OnButtonWhiteColor() 
{
	CMyColorDialog cdlg;
	if(cdlg.DoModal() == IDOK)
	{
		m_crefWhiteColor = cdlg.GetColor();
		CStatic *pwhite = (CStatic*)GetDlgItem(IDC_STATIC_WHITE);
		CRect rect;
		CClientDC dc((CWnd*)pwhite);
		pwhite->GetClientRect(rect);		 
		CBrush brush(m_crefWhiteColor);
		CBrush *pOldBrush = (CBrush*)dc.SelectObject(brush); 
		dc.FillRect(&rect,&brush);
		UpdateData(FALSE);
		m_whiteClrDlg = true;
		m_blackClrDlg = false;
	}	
	((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);
}

BOOL COptions::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CStatic *pwhite = (CStatic*)GetDlgItem(IDC_STATIC_WHITE);

	CRect rect;
	CClientDC dc((CWnd*)pwhite);
	pwhite->GetClientRect(rect);		 
	CBrush brush(m_crefWhiteColor);
	CBrush *pOldBrush = (CBrush*)dc.SelectObject(brush); 
	dc.FillRect(&rect,&brush);	

	CStatic *pblack = (CStatic*)GetDlgItem(IDC_STATIC_BLACK);	 
	CClientDC bdc((CWnd*)pblack);
	pblack->GetClientRect(rect);		 
	CBrush bbrush(m_crefBlackColor);
	CBrush *pOldBBrush = (CBrush*)bdc.SelectObject(bbrush); 
	bdc.FillRect(&rect,&bbrush);
	UpdateData(FALSE);
	return TRUE;
}

void COptions::OnCheckWhiteOnTop() 
{
	UpdateData(TRUE);	 
	((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);
}

void COptions::OnOK() 
{
	m_whiteClrDlg = false;
	m_blackClrDlg = false;	
	CDialog::OnOK();
}
void COptions ::SetColor(COLORREF cr)
{	
	UpdateData(TRUE);
	if(m_whiteClrDlg == true)
	{
		m_crefWhiteColor = cr;
	}
	else 
	{
		m_crefBlackColor = cr;
	}
	((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);
}

void COptions::OnStaticPieceType1() 
{
	m_pieceType = 1;
		((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);
}

void COptions::OnStaticPieceType2() 
{
	m_pieceType = 2;
		((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);
}

void COptions::OnStaticPieceType3() 
{
	m_pieceType = 3;
		((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);
	
}

void COptions::OnButtonWhitePieceColor() 
{
	CMyColorDialog cdlg;
	if(cdlg.DoModal() == IDOK)
	{
		m_crefWhitePieceColor = cdlg.GetColor();
		CStatic *pwhite = (CStatic*)GetDlgItem(IDC_STATIC_WHITE_PIECE_COLOR);
		CRect rect;
		CClientDC dc((CWnd*)pwhite);
		pwhite->GetClientRect(rect);		 
		CBrush brush(m_crefWhitePieceColor);
		CBrush *pOldBrush = (CBrush*)dc.SelectObject(brush); 
		dc.FillRect(&rect,&brush);
		UpdateData(FALSE);
	}	
	((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);
}	


void COptions::OnStaticBlackPieceColor() 
{

}


void COptions::OnButtonBlackPieceColor() 
{
	CMyColorDialog cdlg;
	if(cdlg.DoModal() == IDOK)
	{
		m_crefBlackPieceColor = cdlg.GetColor();
		CStatic *pwhite = (CStatic*)GetDlgItem(IDC_STATIC_BLACK_PIECE_COLOR);
		CRect rect;
		CClientDC dc((CWnd*)pwhite);
		pwhite->GetClientRect(rect);		 
		CBrush brush(m_crefBlackPieceColor);
		CBrush *pOldBrush = (CBrush*)dc.SelectObject(brush); 
		dc.FillRect(&rect,&brush);
		UpdateData(FALSE);
	}	
	((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->PostMessage(ID_MY_MESSAGE_COLORDATA,0,0);	
}
