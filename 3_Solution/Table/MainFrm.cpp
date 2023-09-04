#include "stdafx.h"
#include "NetChess.h"
#include "MainFrm.h"
#include "NetChessDoc.h"
#include "NetChessView.h"

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
	CNetChessView* pView = (CNetChessView*)GetActiveView();
	if(pView->m_timerFlag == false)
	{
		ShowTrayIcon(NIM_ADD,IDR_MAINFRAME,0);		
	}
	this->ShowWindow(SW_HIDE);
	 
}
LRESULT CMainFrame::OnShellNotify(WPARAM wParam,LPARAM lParam)
{
 
	switch(lParam)
	{
		case WM_LBUTTONDOWN:
				this->ShowWindow(SW_SHOW);
			break;
		case WM_LBUTTONUP:
			{	
				CNetChessView* pView = (CNetChessView*)GetActiveView();
		 
				if(pView->m_timerFlag == true)
				{
					pView->KillTimerEvent();					 
				}
				ShowTrayIcon(NIM_DELETE,IDR_MAINFRAME,0);				 
			}
			break;
		case WM_RBUTTONDOWN:
			{
				CRect rect;
				GetWindowRect(rect);
				CMenu menu;
				menu.LoadMenu(IDR_SHELL_MENU);
				CMenu *pMenu = menu.GetSubMenu(0);
				pMenu->TrackPopupMenu(TPM_LEFTALIGN |
				TPM_LEFTBUTTON | TPM_RIGHTBUTTON,rect.bottom,rect.right ,this);
			}
			break;
	}
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
	ShowTrayIcon(NIM_ADD,IDR_MAINFRAME,0);
	this->ShowWindow(SW_SHOW);	
}
void CMainFrame::ShowTrayIcon(DWORD message,int icon,int input)
{
	NOTIFYICONDATA nicondata;
	char data[64] = "NetChess";
	nicondata.hWnd = this->GetSafeHwnd();;
	nicondata.uID = 10;
	nicondata.uFlags = NIF_ICON |NIF_MESSAGE | NIF_TIP; 
	nicondata.cbSize = sizeof(nicondata);
	nicondata.uCallbackMessage = MY_MESSAGE_SHELLNOTIFY;
	nicondata.hIcon = AfxGetApp()->LoadIcon(icon);
	strcpy(nicondata.szTip,data);
	Shell_NotifyIcon(message,&nicondata);

}


 
