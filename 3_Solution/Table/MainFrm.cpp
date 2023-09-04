#include "stdafx.h"
#include "NetChess.h"
#include "MainFrm.h"
#include "NetChessDoc.h"
#include "NetChessView.h"

// implementa funcționalitatea de creare dinamică a ferestrei principale
IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_HIDE, OnViewHide)
	ON_COMMAND(ID_VIEW_STATUS_BAR, OnViewStatusBar)
	ON_COMMAND(ID_VIEW_TOOLBAR, OnViewToolbar)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_QUERYENDSESSION()
	ON_WM_ENDSESSION()
	ON_COMMAND(ID_SHELL_CLOSE, OnShellClose)
	ON_COMMAND(ID_SHELL_VIEW, OnShellView)
	ON_MESSAGE(MY_MESSAGE_SHELLNOTIFY, OnShellNotify)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR,
	ID_SEPARATOR
	
};

CMainFrame::CMainFrame()
{
	
}

CMainFrame::~CMainFrame()
{
}

//Creează și încarcă bara de instrumente (toolbar)
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;
	}

	m_wndStatusBar.SetPaneInfo(0,ID_SEPARATOR,0,320);
	m_wndStatusBar.SetPaneInfo(1,ID_SEPARATOR,0,70);

	m_wndStatusBar.SetPaneInfo(2,ID_SEPARATOR,0,40);
	m_wndStatusBar.SetPaneText(2,"ALB");

	m_wndStatusBar.SetPaneInfo(3,ID_SEPARATOR,0,70);
	m_wndStatusBar.SetPaneText(3,"Rand jucator");
	m_wndStatusBar.SetPaneInfo(4,ID_SEPARATOR,0,40);
	m_wndStatusBar.SetPaneText(4,"ALB");
	return 0;
}

// folosită pentru a configura proprietățile ferestrei,
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style = WS_OVERLAPPED | WS_SYSMENU | WS_BORDER|WS_MINIMIZE;
	cs.cx = 580;
	cs.cy = 550;
	cs.x = 40;
	cs.y = 10;
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

void CMainFrame::OnViewHide() 
{
	 
}
//Aceasta răspunde la evenimentele de clic (stânga, dreapta) asupra iconiței din caseta de sistem și efectuează acțiuni 
//precum afișarea sau ascunderea ferestrei principale, sau afișarea unui meniu contextual.
LRESULT CMainFrame::OnShellNotify(WPARAM wParam,LPARAM lParam)
{
 
	
	return 0;
} 

void CMainFrame::OnViewStatusBar() 
{

}

void CMainFrame::OnViewToolbar() 
{

}

void CMainFrame::OnClose() 
{
	ShowTrayIcon(NIM_DELETE,IDR_MAINFRAME,0);	
	CFrameWnd::OnClose();
}

void CMainFrame::OnDestroy() 
{
	CFrameWnd::OnDestroy();
	ShowTrayIcon(NIM_DELETE,IDR_MAINFRAME,0);	
}

BOOL CMainFrame::OnQueryEndSession() 
{
	if (!CFrameWnd::OnQueryEndSession())
		return FALSE;
	ShowTrayIcon(NIM_DELETE,IDR_MAINFRAME,0);	
	return TRUE;
}

void CMainFrame::OnEndSession(BOOL bEnding)
{
	CFrameWnd::OnEndSession(bEnding);
	ShowTrayIcon(NIM_DELETE,IDR_MAINFRAME,0);	
}

void CMainFrame::OnShellClose() 
{
	ShowTrayIcon(NIM_DELETE,IDR_MAINFRAME,0);
	SendMessage(WM_CLOSE);
}

void CMainFrame::OnShellView() 
{
}
void CMainFrame::ShowTrayIcon(DWORD message,int icon,int input)
{


}


 
