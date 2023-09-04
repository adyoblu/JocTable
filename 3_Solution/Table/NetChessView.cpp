#include "stdafx.h"
#include "NetChess.h"
#include "Options.h"
#include "ChessBoard.h"
#include "MainFrm.h"
#include "NetChessDoc.h"
#include "NetChessView.h"
#include "HowToPlay.h"

void writeMessage(char* str, ...)
{
#ifdef _DEBUG

#endif
}

IMPLEMENT_DYNCREATE(CNetChessView, CView)
// Implementarea macro-ului DYNCREATE pentru clasa CNetChessView.
// Acest macro ajută la gestionarea dinamică a obiectelor.

BEGIN_MESSAGE_MAP(CNetChessView, CView)
	// Începe definirea hărții mesajelor pentru clasa CNetChessView.
	// Această hartă asociază mesaje și funcții pentru a le trata.

	ON_COMMAND(ID_EDIT_OPTIONS, OnEditOptions)
	// Atunci când este apăsată comanda ID_EDIT_OPTIONS, se apelează funcția OnEditOptions.

	ON_WM_LBUTTONDOWN()
	// Atunci când este apăsat butonul stâng al mouse-ului, se apelează funcția asociată OnLButtonDown().

	ON_WM_LBUTTONUP()
	// Atunci când butonul stâng al mouse-ului este eliberat, se apelează funcția asociată OnLButtonUp().

	ON_WM_MOUSEMOVE()
	// Atunci când mouse-ul este mișcat, se apelează funcția asociată OnMouseMove().

	ON_COMMAND(ID_TOOLS_CLIENT, OnToolsClient)
	// Atunci când este apăsată comanda ID_TOOLS_CLIENT, se apelează funcția OnToolsClient().

	ON_COMMAND(ID_TOOLS_SERVER, OnToolsServer)
	// Atunci când este apăsată comanda ID_TOOLS_SERVER, se apelează funcția OnToolsServer().

	ON_COMMAND(ID_TOOLS_SENDMESSAGE, OnToolsSendmessage)
	// Atunci când este apăsată comanda ID_TOOLS_SENDMESSAGE, se apelează funcția OnToolsSendmessage().

	ON_COMMAND(ID_VIEW_LETTER, OnViewLetter)
	// Atunci când este apăsată comanda ID_VIEW_LETTER, se apelează funcția OnViewLetter().

	ON_UPDATE_COMMAND_UI(ID_VIEW_LETTER, OnUpdateViewLetter)
	// Atunci când trebuie actualizată interfața utilizatorului pentru comanda ID_VIEW_LETTER,
	// se apelează funcția OnUpdateViewLetter().

	ON_COMMAND(ID_VIEW_NUMBER, OnViewNumber)
	// Atunci când este apăsată comanda ID_VIEW_NUMBER, se apelează funcția OnViewNumber().

	ON_UPDATE_COMMAND_UI(ID_VIEW_NUMBER, OnUpdateViewNumber)
	// Atunci când trebuie actualizată interfața utilizatorului pentru comanda ID_VIEW_NUMBER,
	// se apelează funcția OnUpdateViewNumber().

	ON_COMMAND(ID_FILE_SAVEHISTORY, OnFileSavehistory)
	// Atunci când este apăsată comanda ID_FILE_SAVEHISTORY, se apelează funcția OnFileSavehistory().

	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	// Atunci când este apăsată comanda ID_EDIT_UNDO, se apelează funcția OnEditUndo().

	ON_COMMAND(ID_EDIT_REDO, OnEditRedo)
	// Atunci când este apăsată comanda ID_EDIT_REDO, se apelează funcția OnEditRedo().

	ON_WM_RBUTTONDOWN()
	// Atunci când este apăsat butonul drept al mouse-ului, se apelează funcția asociată OnRButtonDown().

	ON_UPDATE_COMMAND_UI(ID_TOOLS_SERVER, OnUpdateToolsServer)
	// Atunci când trebuie actualizată interfața utilizatorului pentru comanda ID_TOOLS_SERVER,
	// se apelează funcția OnUpdateToolsServer().

	ON_UPDATE_COMMAND_UI(ID_TOOLS_CLIENT, OnUpdateToolsClient)
	// Atunci când trebuie actualizată interfața utilizatorului pentru comanda ID_TOOLS_CLIENT,
	// se apelează funcția OnUpdateToolsClient().

	ON_WM_TIMER()
	// Atunci când expiră un timer, se apelează funcția asociată OnTimer().

	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	// Atunci când este apăsată comanda ID_FILE_NEW, se apelează funcția OnFileNew().

	ON_COMMAND(ID_VIEW_HISTORY, OnViewHistory)
	// Atunci când este apăsată comanda ID_VIEW_HISTORY, se apelează funcția OnViewHistory().

	ON_COMMAND(ID_TOOLS_WHITEONTOP, OnToolsWhiteontop)
	// Atunci când este apăsată comanda ID_TOOLS_WHITEONTOP, se apelează funcția OnToolsWhiteontop().

	ON_COMMAND(ID_EDIT_MOVEFIRST, OnEditMovefirst)
	// Atunci când este apăsată comanda ID_EDIT_MOVEFIRST, se apelează funcția OnEditMovefirst().

	ON_COMMAND(ID_EDIT_MOVELAST, OnEditMovelast)
	// Atunci când este apăsată comanda ID_EDIT_MOVELAST, se apelează funcția OnEditMovelast().

	ON_COMMAND(ID_HELP_HOWTOPLAY, OnHelpHowtoplay)
	// Atunci când este apăsată comanda ID_HELP_HOWTOPLAY, se apelează funcția OnHelpHowtoplay().

	ON_COMMAND(ID_TOOLS_DISCONNECT, OnToolsDisconnect)
	// Atunci când este apăsată comanda ID_TOOLS_DISCONNECT, se apelează funcția OnToolsDisconnect().

	ON_COMMAND(D_EDIT_PROPERTIES, OnEditProperties)
	// Atunci când este apăsată comanda D_EDIT_PROPERTIES, se apelează funcția OnEditProperties().

	ON_COMMAND(ID_TOOLS_GAMETYPE, OnToolsGametype)
	// Atunci când este apăsată comanda ID_TOOLS_GAMETYPE, se apelează funcția OnToolsGametype().

	ON_COMMAND(ID_EDIT_PROPERTIES, OnEditProperties)
	// Atunci când este apăsată comanda ID_EDIT_PROPERTIES, se apelează funcția OnEditProperties().

	ON_WM_LBUTTONDBLCLK()
	// Atunci când este dublu-clic pe butonul stâng al mouse-ului, se apelează funcția asociată OnLButtonDblClk().

	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	// Atunci când este apăsată comanda ID_FILE_PRINT, se apelează funcția OnFilePrint() din clasa CView.

	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	// Atunci când este apăsată comanda ID_FILE_PRINT_DIRECT, se apelează funcția OnFilePrint() din clasa CView.

	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	// Atunci când este apăsată comanda ID_FILE_PRINT_PREVIEW, se apelează funcția OnFilePrintPreview() din clasa CView.

	ON_MESSAGE(ID_MY_MESSAGE_COLORDATA, OnMessageColorData)
	// Atunci când se primește mesajul ID_MY_MESSAGE_COLORDATA, se apelează funcția OnMessageColorData().
	// Acesta este un mesaj personalizat definit în aplicație.
END_MESSAGE_MAP()

int checkExisting(int n, int* arr, int rand)
{
	// Această funcție verifică dacă "rand" există deja în vectorul "arr" cu "n" elemente.
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == rand)
			return 1; // Returnează 1 dacă elementul există în vector.
	}
	return 0; // Returnează 0 dacă elementul nu există în vector.
}

int getExisting(int n, int* arr, int* data)
{
	// Această funcție caută și returnează primul element din vectorul "data" care nu există în vectorul "arr".
	int foundFlag = 0;
	for (int i = 0; i < n; i++)
	{
		if (data[i] == 0) continue; // Dacă elementul din "data" este 0, trece la următorul element.
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == 0)
			{
				return data[i]; // Returnează elementul din "data" dacă găsește un loc liber în "arr".
			}
			if (arr[j] == data[i])
			{
				foundFlag = 1; // Dacă elementul din "data" există deja în "arr", setează foundFlag la 1.
				break;
			}
		}
		if (foundFlag == 0)
		{
			return data[i]; // Returnează elementul din "data" dacă nu există în "arr".
		}
	}
	return -1; // Returnează -1 dacă nu găsește niciun element potrivit.
}

int getRandom(int num)
{
	SYSTEMTIME st;
	::GetSystemTime(&st);
	int value = (st.wMilliseconds % num) + 1;
	return value;
}
// Funcția getRandom() generează un număr aleatoriu între 1 și "num" folosind milisecundele sistemului.

CNetChessView::CNetChessView()
{
	m_pClientSocket = NULL;
	m_pServerSocket = NULL;
	m_ChatDlg = NULL;
	Initialize();
	m_whoAmI = "WHITE";
}
// Constructorul clasei CNetChessView. Inițializează variabilele membru și stabilește "whoAmI" la "WHITE".

CNetChessView::~CNetChessView()
{
}
// Destructorul clasei CNetChessView. Nu efectuează operații specifice de distrugere.

BOOL CNetChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}
// Funcția PreCreateWindow() pentru configurarea ferestrei de vizualizare.

void CNetChessView::OnDraw(CDC* pDC)
{
	CNetChessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	DrawBoard();
}
// Funcția OnDraw() pentru desenarea tablei de șah în fereastra de vizualizare.

BOOL CNetChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}
// Funcția OnPreparePrinting() pentru pregătirea tipăririi.

void CNetChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}
// Funcția OnBeginPrinting() pentru începerea tipăririi.

void CNetChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}
// Funcția OnEndPrinting() pentru încheierea tipăririi.

void CNetChessView::OnEditOptions()
{
	m_optDlg.DoModal();
	DrawBoard();
}
// Funcția OnEditOptions() pentru gestionarea opțiunilor. Afișează dialogul pentru opțiuni și redesenează tabla.

void CNetChessView::DrawBoard()
{
	CClientDC dc(this);
	// Obține contextul dispozitiv pentru desenare (DC) pentru fereastra curentă.

	CBitmap localbmp;
	localbmp.LoadBitmap(IDB_BITMAP_BASE);
	// Încarcă o imagine bitmap din resurse cu ID-ul IDB_BITMAP_BASE.

	CDC ldc;
	ldc.CreateCompatibleDC(&dc);
	ldc.SelectObject(&localbmp);
	// Creează un DC compatibil cu DC-ul clientului și selectează imaginea bitmap în el.

	COLORREF cr(RGB(71, 70, 62));	 // Culoarea de fundal pentru tabla de șah.
	// Definește culoarea de fundal pentru tabla de șah.

	CBrush brush(cr);
	COLORREF blackcr(RGB(0, 0, 0));
	CBrush blackbrush(blackcr);
	ldc.SelectObject(brush);
	// Creează pensule cu culorile definite mai sus și le selectează în DC-ul local.

	CRect crect;
	GetClientRect(&crect);
	// Obține dreptunghiul clientului pentru fereastra de vizualizare.

	ldc.FillRect(&crect, &brush);
	// Umple întregul client cu culoarea de fundal.

	COLORREF bkcrRef;

	COLORREF redcr(RGB(255, 0, 0));
	CBrush redbrush;
	redbrush.CreateSolidBrush(redcr);
	// Definește o pensulă roșie.

	COLORREF redbluecr(RGB(204, 102, 0));// Culoarea pentru marginea tablei.
	CBrush redbluebrush;
	redbluebrush.CreateSolidBrush(redbluecr);
	// Definește o pensulă cu culoare roșu-albastru pentru marginea tablei.

	CBrush* pbrush = ldc.SelectObject(&redbluebrush);

	ldc.Rectangle(crect.left + 6, crect.top + 4,
		crect.right - 122, crect.bottom - 4);
	// Desenează un dreptunghi roșu-albastru pentru marginea tablei.

	COLORREF bluecr(RGB(204, 102, 0));// Culoarea pentru tabla de șah.
	CBrush bluebrush;
	bluebrush.CreateSolidBrush(bluecr);
	// Definește o pensulă cu culoare albastru pentru tabla de șah.

	COLORREF greencr(RGB(0, 255, 0));
	CBrush greenbrush;
	greenbrush.CreateSolidBrush(greencr);
	// Definește o pensulă cu culoare verde.

	ldc.SelectObject(bluebrush);
	ldc.Rectangle(crect.left + 21, crect.top + 21,
		crect.right - 135, crect.bottom - 21);
	// Desenează tabla de șah folosind pensula cu culoarea albastru.

	pbrush = ldc.SelectObject(&redbluebrush);

	CPen pen(PS_NULL, 0, RGB(0, 0, 0));
	CPen* orgpen = ldc.SelectObject(&pen);
	// Creează un creion pentru desenare cu culoarea neagră și selectează-l.

	COLORREF c1 = m_optDlg.m_crefWhiteColor;
	COLORREF c2 = m_optDlg.m_crefBlackColor;
	// Obține culorile pentru piesele albe și negre din opțiuni.

	for (int i = 0; i < m_level; i++)
	{
		if (i == 6)
		{
			// Dacă este linia 6, se tratează ca o excepție și se completează dreptunghiul pentru întreaga linie
			CRect rect1 = cb[0][i].GetRect();
			CRect rect2 = cb[13 - 1][i].GetRect();
			CRect rect3(rect1.left, rect1.top, rect2.right, rect2.bottom);
			ldc.FillRect(&rect3, &brush);
			continue; // Trecem la următoarea iterație a buclei
		}
		CRect rect = cb[0][i].GetRect();
		CRect rect1 = cb[4][i].GetRect();
		POINT pt[4] = {
			{rect.left, rect.top},
			{rect.right, rect.top},
			{rect1.left + 15, rect1.bottom},
			{rect.left, rect.top}
		};
		// Construiește un poligon folosind punctele definite mai sus

		if (i < 13)
		{
			CBrush brush(c1); // Definim o perie cu culoarea c1
			CRgn rgn;
			rgn.CreatePolygonRgn(pt, 4, ALTERNATE); // Creăm o regiune poligonală cu punctele specificate
			ldc.Polygon(pt, 4); // Desenăm poligonul
			ldc.FillRgn(&rgn, &brush); // Umplem regiunea cu culoarea periei
			ldc.FrameRgn(&rgn, &blackbrush, 1, 0); // Desenăm un contur pentru regiunea poligonală

			CRect rect2 = cb[13 - 1][i].GetRect();
			CRect rect3 = cb[13 - 5][i].GetRect();
			POINT pt1[4] = {
				{rect2.left, rect2.bottom},
				{rect2.right, rect2.bottom},
				{rect3.left + 15, rect3.top},
				{rect2.left, rect2.bottom}
			};
			CBrush brush1(c2); // Definim o perie cu culoarea c2
			CRgn rgn1;
			rgn1.CreatePolygonRgn(pt1, 4, ALTERNATE);
			ldc.Polygon(pt1, 4);
			ldc.FillRgn(&rgn1, &brush1);
			ldc.FrameRgn(&rgn1, &blackbrush, 1, 0);
			COLORREF temp = c1;
			c1 = c2;
			c2 = temp;
		}
	}


	ldc.SelectObject(orgpen);

	for (i = 0; i < m_level; i++)
	{
		for (int j = 0; j < m_level; j++)
		{
			// Obține dreptunghiul pentru celula curentă
			CRect rect = cb[i][j].GetRect();

			// Verifică dacă celula nu este goală și piesa nu este în mișcare
			if (cb[i][j].GetPieceType() != BLANK && cb[i][j].GetPieceState() != PIECE_MOVING)
			{
				int piece_id;
				COLOR_TYPE piece_color;
				PIECE_TYPE piece_type;
				STATE piece_state;

				// Obține informațiile despre piesa curentă
				cb[i][j].GetPieceData(piece_id, piece_color, piece_type, piece_state);

				// Verifică dacă piesa are un ID valid
				if (piece_id <= 0)
				{
					break; // Ieși din bucla for dacă piesa nu are un ID valid
				}

				// Creează o regiune eliptică pentru piesă
				CRect rect1(rect.left, rect.top, rect.right, rect.bottom);
				CRgn rgn;
				rgn.CreateEllipticRgn(rect1.left, rect1.top, rect1.right, rect1.bottom);

				// Desenează și colorează piesa în funcție de tipul și culoarea ei
				switch (piece_id)
				{
				case CHECKERS_WHITE:
				{
					CBrush brush(m_optDlg.m_crefWhitePieceColor);
					ldc.FillRgn(&rgn, &brush);
					ldc.FrameRgn(&rgn, &brush, 1, 1);
				}
				break;

				case CHECKERS_BLACK:
				{
					CBrush brush(m_optDlg.m_crefBlackPieceColor);
					ldc.FillRgn(&rgn, &brush);
					ldc.FrameRgn(&rgn, &brush, 1, 1);
				}
				break;
				}
			}
		}
	}


	for (i = 0; i < 13; i++)
	{
		ldc.SetBkColor(redbluecr); // Setăm culoarea de fundal pentru text
		int j = i;
		if (i == 6) continue; // Excludem linia 6 din buclă

		if (i > 6)
		{
			j = i - 1; // Ajustăm indicele pentru a evita linia 6
		}

		CString str1;
		CString str2;
		str1.Format("%d", 13 + j); // Generăm textul pentru prima parte a numerelor
		str2.Format("%d", 12 - j); // Generăm textul pentru a doua parte a numerelor

		if (m_whoAmI == "NEGRU")
		{
			// Dacă jucăm cu piese negre, textul este afișat în partea de sus și jos a tablei
			ldc.TextOut(m_squareWidth * (i + 1) + 5, 5, str1); // Desenăm textul în partea de sus
			ldc.TextOut(m_squareWidth * (i + 1) + 5, crect.bottom - 21, str2); // Desenăm textul în partea de jos
		}
		else
		{
			// Dacă jucăm cu piese albe, textul este afișat în partea stângă și dreaptă a tablei
			ldc.TextOut(m_squareWidth * (i + 1) + 5, crect.bottom - 21, str1); // Desenăm textul în partea de jos
			ldc.TextOut(m_squareWidth * (i + 1) + 5, 5, str2); // Desenăm textul în partea de sus
		}
	}

	COLORREF textcolor(RGB(255, 255, 255));// Culoarea textului
	COLORREF backcr(RGB(17, 0, 255));// Culoarea fundalului textului
	ldc.SetBkColor(backcr);
	ldc.SetTextColor(textcolor);
	ldc.TextOut(450, 25, "Apasa pe zaruri");
	// Adaugă text pe tabla de șah pentru a indica acțiunea cu zarurile.

	CDC ldc1;
	CBitmap localbmp1;
	localbmp1.LoadBitmap(IDB_DICE + m_diceBitmapId); // Încarcă imaginea pentru zarul 1
	ldc1.CreateCompatibleDC(&ldc);
	ldc1.SelectObject(&localbmp1);
	ldc.BitBlt(470, 50, 50, 50, &ldc1, 0, 0, SRCCOPY); // Copiază imaginea zarului 1 pe ecran

	CDC ldc2;
	CBitmap localbmp2;
	localbmp2.LoadBitmap(IDB_DICE + m_diceBitmapId1); // Încarcă imaginea pentru zarul 2
	ldc2.CreateCompatibleDC(&ldc);
	ldc2.SelectObject(&localbmp2);
	ldc.BitBlt(510, 50, 50, 50, &ldc2, 0, 0, SRCCOPY); // Copiază imaginea zarului 2 pe ecran

	CString str;
	str.Format("%d       %d", m_diceBitmapId, m_diceBitmapId1); // Formatează un șir de caractere cu valorile zarurilor
	ldc.TextOut(490, 90, str); // Afișează valorile zarurilor

	str.Format("%d       %d", m_lastDiceMove1, m_lastDiceMove2); // Formatează un șir de caractere cu ultimele mutări
	ldc.TextOut(490, 120, str); // Afișează ultimele mutări

	if (m_sendButtonClickedFlag == 1)
	{
		ldc.SelectObject(bluebrush); // Selectează o perie albastră
		ldc.SetBkColor(bluecr); // Setează culoarea de fundal la albastru
	}
	else
	{
		ldc.SelectObject(redbluebrush); // Selectează o perie roșu-albastru
		ldc.SetBkColor(redbluecr); // Setează culoarea de fundal la roșu-albastru
	}

	ldc.RoundRect(450, 430, 550, 455, 10, 10); // Desenează un chenar rotund pe ecran

	ldc.TextOut(480, 435, "Gata");
	// Adaugă butonul "Gata" pe ecran și îl colorează în funcție de starea lui.

	COLORREF cr1(RGB(255, 255, 255));
	ldc.SetBkColor(cr1); // Setează culoarea de fundal a contextului de desen la alb

	if (m_mouseMoveFlag == true) // Dacă se realizează o mutare cu mouse-ul
	{
		CRect rect = m_moveRect; // Obține dreptunghiul zonei de mutare
		int piece_id;
		ldc.SetBkColor(bkcrRef); // Setează culoarea de fundal
		COLOR_TYPE  piece_color;
		PIECE_TYPE  piece_type;
		STATE piece_state;
		cb[m_point.x][m_point.y].GetPieceData(piece_id, piece_color, piece_type, piece_state); // Obține datele piesei
		if (piece_id < 0)
		{
			dc.BitBlt(0, 0, 600, 700, &ldc, 0, 0, SRCCOPY); // Copiază imaginea pe ecran
			return;
		}
		CRect rect1(rect.left + 10, rect.top + 10, rect.right - 10, rect.bottom - 10); // Calculează un dreptunghi mai mic în interiorul zonei de mutare
		CRgn rgn;
		rgn.CreateEllipticRgn(rect1.left, rect1.top, rect1.right, rect1.bottom); // Creează o regiune eliptică

		switch (piece_id)
		{
		case CHECKERS_WHITE:
		{
			CBrush brush(m_optDlg.m_crefWhitePieceColor); // Selectează peria pentru piese albe
			ldc.FillRgn(&rgn, &brush); // Umple regiunea cu culoarea periei
			ldc.FrameRgn(&rgn, &brush, 1, 1); // Desenează conturul regiunii
		}
		break;

		case CHECKERS_BLACK:
		{
			CBrush brush(m_optDlg.m_crefBlackPieceColor); // Selectează peria pentru piese negre
			ldc.FillRgn(&rgn, &brush); // Umple regiunea cu culoarea periei
			ldc.FrameRgn(&rgn, &brush, 1, 1); // Desenează conturul regiunii
		}
		break;
		}
	}

	dc.BitBlt(0, 0, 600, 700, &ldc, 0, 0, SRCCOPY); // Copiază imaginea pe ecran

}

void CNetChessView::Initialize()
{
	m_mouseMoveFlag = false; // Setează flag-ul de mutare cu mouse-ul ca fals
	m_moveRect = 0; // Inițializează dreptunghiul de mutare cu zero
	m_sendButtonClickedFlag = 0;	// Inițializează flag-ul pentru butonul de trimitere ca zero
	m_player_turn = WHITE;	// Inițializează tura jucătorului cu alb
	m_timerFlag = false; // Inițializează flag-ul de cronometru ca fals
	m_squareWidth = 30; // Setează lățimea pătratelor pe tablă
	m_level = 18; // Setează nivelul de joc
	m_GameType = AMERICAN; // Setează tipul de joc la "AMERICAN"
	m_diceBitmapId = 0; // Inițializează identificatorul pentru imaginea zarului 1 cu zero
	m_diceBitmapId1 = 0; // Inițializează identificatorul pentru imaginea zarului 2 cu zero
	m_point.x = m_point.y = -1; // Inițializează poziția curentă pe tablă cu (-1, -1)
	m_bearindex.x = 3; // Setează indicele pentru locul de extragere a pieselor pentru x
	m_bearindex.y = 14; // Setează indicele pentru locul de extragere a pieselor pentru y

	for (int i = 0; i < 10; i++)
	{
		m_moveLength[i] = 0; // Inițializează lungimea mișcării cu zero pentru fiecare index
		memset(m_moveInfo, '\0', 100); // Inițializează bufferul pentru informații de mișcare cu caractere nule
	}

	m_moveIndex = -1; // Inițializează indexul de mișcare cu -1
	m_diceClickFlag = 0; // Inițializează flag-ul pentru clicul pe zar cu zero
	m_lastDiceMove1 = 0; // Inițializează ultima mișcare cu zarul 1 cu zero
	m_lastDiceMove2 = 0; // Inițializează ultima mișcare cu zarul 2 cu zero
}


int CNetChessView::GetBitmapId(int piece_id)
{
	return -1;
}
void CNetChessView::OnInitialUpdate()
{
	int xstart, ystart;
	xstart = 30;
	ystart = 30;

	int x, y = ystart;
	for (int i = 0; i < m_level; i++)
	{
		x = xstart;
		for (int j = 0; j < m_level; j++)
		{
			CRect rect(x, y, x + m_squareWidth, y + m_squareWidth);

			cb[i][j].SetRect(rect); // Setează dreptunghiul pentru fiecare celulă de șah
			cb[i][j].SetPieceType(BLANK); // Inițializează tipul de piesă ca "BLANK" (nici o piesă)
			cb[i][j].SetPieceData(-1, NONE, BLANK, PIECE_NOT_MOVING); // Inițializează datele piesei

			x += m_squareWidth;
		}
		y += m_squareWidth;
	}

	COLOR_TYPE typex = BLACK;

	for (int i = 0; i < m_level; i++)
	{
		if (typex == WHITE)
			typex = BLACK;
		else
			typex = WHITE;
		COLOR_TYPE type = typex;
		for (int j = 0; j < m_level; j++)
		{
			cb[i][j].SetColorType(type); // Setează culoarea celulelor de șah
			if (type == WHITE)
				type = BLACK;
			else
				type = WHITE;
		}
	}

	for (int j = 0; j < 5; j++)
	{
		cb[j][0].SetPieceData(CHECKERS_BLACK, BLACK, NORMAL, PIECE_NOT_MOVING); // Setează date pentru piesele negre din partea de sus
		cb[13 - j - 1][0].SetPieceData(CHECKERS_WHITE, WHITE, NORMAL, PIECE_NOT_MOVING); // Setează date pentru piesele albe din partea de jos
		cb[j][7].SetPieceData(CHECKERS_WHITE, WHITE, NORMAL, PIECE_NOT_MOVING); // Setează date pentru piesele albe din partea de sus
		cb[13 - j - 1][7].SetPieceData(CHECKERS_BLACK, BLACK, NORMAL, PIECE_NOT_MOVING); // Setează date pentru piesele negre din partea de jos
	}

	for (int j = 0; j < 3; j++)
	{
		cb[j][4].SetPieceData(CHECKERS_WHITE, WHITE, NORMAL, PIECE_NOT_MOVING); // Setează date pentru piesele albe din mijloc
		cb[13 - j - 1][4].SetPieceData(CHECKERS_BLACK, BLACK, NORMAL, PIECE_NOT_MOVING); // Setează date pentru piesele negre din mijloc
		if (j != 2)
		{
			cb[j][12].SetPieceData(CHECKERS_BLACK, BLACK, NORMAL, PIECE_NOT_MOVING); // Setează date pentru piesele negre din partea de sus
			cb[13 - j - 1][12].SetPieceData(CHECKERS_WHITE, WHITE, NORMAL, PIECE_NOT_MOVING); // Setează date pentru piesele albe din partea de jos
		}
	}

	int count = -4;
	for (int j = 17; j >= 0; j--)
	{
		if (j == 6)
		{
			continue; // Sari peste celula din mijloc
		}
		for (int i = 12; i > 6; i--)
		{
			cb[i][j].SetIndex(count); // Setează indexul pentru fiecare celulă de șah
			cb[12 - i][j].SetIndex(25 - count);
		}
		count++;
	}

	for (i = 0; i < 18; i++)
	{
		cb[i][6].SetIndex(cb[i][13].GetIndex()); // Setează indexul pentru celulele din mijloc
	}
}

void CNetChessView::OnLButtonDown(UINT nFlags, CPoint point)
{
	writeMessage("OnLButtonDown"); // Afișează un mesaj la apăsarea butonului mouse-ului
	OnLButtonDownAction(nFlags, point); // Execută acțiuni specifice la apăsarea butonului stâng al mouse-ului
	CView::OnLButtonDown(nFlags, point); // Apel către funcția de bază pentru tratarea evenimentului
}

void CNetChessView::OnLButtonUp(UINT nFlags, CPoint point)
{
	writeMessage("OnLbuttonUp"); // Afișează un mesaj la eliberarea butonului mouse-ului
	OnLButtonUpAction(nFlags, point); // Execută acțiuni specifice la eliberarea butonului stâng al mouse-ului
	CView::OnLButtonUp(nFlags, point); // Apel către funcția de bază pentru tratarea evenimentului
}

void CNetChessView::OnMouseMove(UINT nFlags, CPoint point)
{
	OnMouseMoveAction(nFlags, point); // Execută acțiuni specifice la mișcarea mouse-ului
	CView::OnMouseMove(nFlags, point); // Apel către funcția de bază pentru tratarea evenimentului
}


void CNetChessView::OnToolsClient() 
{
}

void CNetChessView::OnToolsServer() 
{
}
void CNetChessView::SetClientSocket(CAsyncSocket* sock)
{
}

CAsyncSocket* CNetChessView::GetClientSocket()
{	 
	return m_pClientSocket;
}
void CNetChessView::SetData(char* data,int length)
{
}
void CNetChessView::SendSockData(unsigned char *data,int length)
{
	char clength[5];	 
	memcpy(clength,&length,4);
	if(m_pClientSocket != NULL)
	{	 
		m_pClientSocket->Send(clength,4);	 
		m_pClientSocket->Send(data,length);	 	
	}
}

void CNetChessView::OnToolsSendmessage() 
{
}


void CNetChessView::OnViewLetter() 
{
	if(m_LetterFlag == false)
	{	 
		m_LetterFlag = true;
	}
	else
	{	 
		m_LetterFlag = false;
	}
	DrawBoard(); 
}

void CNetChessView::OnUpdateViewLetter(CCmdUI* pCmdUI) 
{

}

void CNetChessView::OnViewNumber() 
{

}

void CNetChessView::OnUpdateViewNumber(CCmdUI* pCmdUI) 
{

}
LRESULT CNetChessView::OnMessageColorData(WPARAM wParam,LPARAM lParam)
{	 
	DrawBoard();
	return 0;
}


void CNetChessView::OnFileSavehistory() 
{

}
bool CNetChessView::CheckValidMove(int i, int j, int& rmx, int& rmy)
{
	writeMessage("CheckValidMove i %d j %d x %d y %d", i, j, m_point.x, m_point.y);

	// Verifică dacă ambele mutări au fost deja făcute
	if (m_lastDiceMove1 != 0 && m_lastDiceMove2 != 0)
	{
		writeMessage("Ambele mutări au fost efectuate");
		return false;
	}

	PIECE_TYPE from_piece_type;
	COLOR_TYPE from_piece_color;
	int from_pieceid;
	STATE from_piece_state;
	cb[m_point.x][m_point.y].GetPieceData(from_pieceid, from_piece_color, from_piece_type, from_piece_state);
	int m_fromindex, m_toindex;

	PIECE_TYPE to_piece_type;
	COLOR_TYPE to_piece_color;
	int to_pieceid;
	STATE to_piece_state;
	cb[j][j].GetPieceData(to_pieceid, to_piece_color, to_piece_type, to_piece_state);
	m_toindex = cb[i][j].GetIndex();
	m_fromindex = cb[m_point.x][m_point.y].GetIndex();

	// Verifică dacă bara pentru piesele scoase este goală
	for (int k = 0; k < 13 && m_point.y != 6; k++)
	{
		if (cb[k][6].GetPieceId() != -1 && cb[k][6].GetPieceId() == from_pieceid)
		{
			writeMessage("Bara pentru piesele scoase nu este goală");
			return false;
		}
	}

	writeMessage("De la indexul %d la indexul %d", m_fromindex, m_toindex);

	int icountBalls = countBalls(i, j);
	writeMessage("De la indexul %d la indexul %d, numărul de bile %d, id-ul piesei de bază a țintei %d id-ul piesei de la sursă %d",
		m_fromindex, m_toindex, icountBalls, cb[i < 6 ? 0 : 12][j].GetPieceId(), from_pieceid);

	if ((icountBalls == 0 || icountBalls == 1) ||
		(icountBalls > 1 && from_pieceid == cb[i < 6 ? 0 : 12][j].GetPieceId()))
	{
		if (icountBalls == 1 && from_pieceid != cb[i < 6 ? 0 : 12][j].GetPieceId())
		{
			writeMessage("De la id-ul piesei de la sursă %d la id-ul piesei noi %d, i %d",
				from_pieceid, cb[i < 6 ? 0 : 12][j].GetPieceId(), i < 6 ? 0 : 12);
			rmx = i < 6 ? 0 : 12;
			rmy = j;
			writeMessage("rmx %d rmd %d", rmx, rmy);
		}

		if (from_pieceid == CHECKERS_BLACK)
		{
			int diff = abs(m_fromindex - m_toindex);
			writeMessage("m_diceBitmapId %d m_diceBitmapId1 %d diff %d",
				m_diceBitmapId, m_diceBitmapId1, diff);

			if (m_fromindex > m_toindex &&
				(diff == m_diceBitmapId || diff == m_diceBitmapId1))
			{
				(m_lastDiceMove1 != 0 ? m_lastDiceMove2 : m_lastDiceMove1) = diff;
				writeMessage("Condiția este adevărată, este o mutare validă, lastDiceMove1 %d lastDiceMove2 %d", m_lastDiceMove1, m_lastDiceMove2);
				return true;
			}
			else
			{
				writeMessage("Mutarea nu este validă");
				return false;
			}
		}
		else
		{
			int diff = abs(m_toindex - m_fromindex);
			writeMessage("m_diceBitmapId %d m_diceBitmapId1 %d diff %d",
				m_diceBitmapId, m_diceBitmapId1, diff);

			if (m_fromindex < m_toindex &&
				(diff == m_diceBitmapId || diff == m_diceBitmapId1))
			{
				(m_lastDiceMove1 != 0 ? m_lastDiceMove2 : m_lastDiceMove1) = diff;
				writeMessage("Condiția este adevărată, este o mutare validă, lastDiceMove1 %d lastDiceMove2 %d", m_lastDiceMove1, m_lastDiceMove2);
				return true;
			}
			else
			{
				writeMessage("Mutarea nu este validă");
				return false;
			}
		}
	}

	writeMessage("Condiția de bază nu a fost îndeplinită");
	return false;
}

int CNetChessView::countBalls(int i, int j)
{
	int count = 0;
	if (i > 6)
	{
		// Verifică bilele în partea de sus a tablei
		for (int k = 7; k < 13; k++)
		{
			if (cb[k][j].GetPieceId() > 0) count++;
		}
	}
	else
	{
		// Verifică bilele în partea de jos a tablei
		for (int k = 0; k < 6; k++)
		{
			if (cb[k][j].GetPieceId() > 0) count++;
		}
	}
	return count;
}

void CNetChessView::OnLButtonDownAction(UINT nFlags, CPoint point)
{
	writeMessage("OnLButtonDownAction");
	// Verifică dacă este rândul jucătorului și dacă conexiunea este validă
	if (((m_player_turn == WHITE && m_pServerSocket == NULL) || (m_player_turn == BLACK && m_pServerSocket != NULL)) && !(m_pServerSocket == NULL && m_pClientSocket == NULL))
	{
		writeMessage("OnLButtoncondition true %d %d %d", m_player_turn, m_pServerSocket, m_pClientSocket);
		return;
	}
	CRect diceRect1(470, 50, 510, 90);
	CRect diceRect2(510, 50, 560, 90);

	ShowTrayIcon(NIM_DELETE, IDR_MAINFRAME, 0);
	KillTimer(SHELL_ICON_TIMER_EVENT_ID);
	m_timerFlag = false;

	// Verifică dacă butoanele pentru zar sunt apăsate și generează numere aleatorii pentru zaruri
	if (m_diceClickFlag == 0 && (diceRect1.PtInRect(point) || diceRect2.PtInRect(point)))
	{
		m_diceBitmapId = getRandom(6);
		Sleep(7);
		m_diceBitmapId1 = getRandom(6);
		m_point.x = m_point.y = -1;
		writeMessage("%d %d", m_diceBitmapId, m_diceBitmapId1);
		char data[100];
		int k = 0;
		data[k++] = DICEROLL;
		memcpy(&data[k], &m_diceBitmapId, 4);
		k += 4;
		memcpy(&data[k], &m_diceBitmapId1, 4);
		k += 4;
		SendSockData((unsigned char*)data, k);
		DrawBoard();
		CView::OnLButtonDown(nFlags, point);
		m_diceClickFlag = 1;
		return;
	}

	CRect RoundRect(450, 430, 550, 450);
	if (RoundRect.PtInRect(point) && m_diceClickFlag == 1)
	{
		// Trimite mutarea
		m_sendButtonClickedFlag = 1;
		DrawBoard();
		return;
	}
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			CRgn rgn;
			CRect rect = cb[i][j].GetRect();

			rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);
			if (rgn.PtInRegion(point) && m_player_turn == cb[i][j].GetPieceColor())
			{
				// Verifică dacă se poate selecta o piesă pentru mutare
				if (i <= 6)
				{
					if (cb[i + 1][j].GetPieceId() != -1)
						return;
				}
				else if (i > 6)
				{
					if (cb[i - 1][j].GetPieceId() != -1)
						return;
				}
				m_point.x = i;
				m_point.y = j;
				cb[i][j].SetPieceState(PIECE_MOVING);
				m_mouseMoveFlag = true;
				return;
			}

		}
	}

	DrawBoard();
	CView::OnLButtonDown(nFlags, point);
}


void CNetChessView::OnLButtonUpAction(UINT nFlags, CPoint point)
{
	// Verificăm dacă s-a făcut clic pe butonul rotund și dacă este activat modul de trimitere
	writeMessage("Acțiune OnLButtonDown");
	CRect RoundRect(450, 430, 550, 450);
	if (RoundRect.PtInRect(point) && m_sendButtonClickedFlag == 1)
	{
		// Trimitem datele despre mutări către adversar
		writeMessage("În butonul de trimitere");
		for (int i = 0; i <= m_moveIndex; i++)
		{
			SendSockData((unsigned char*)m_moveInfo[i], m_moveLength[i]);
			memset(m_moveInfo[i], '\0', m_moveLength[i]);
		}
		char data = YOURTURN;
		SendSockData((unsigned char*)&data, 1);
		// Schimbăm tura de joc și actualizăm bara de stare
		m_player_turn = m_player_turn == WHITE ? BLACK : WHITE;
		SetPaneText(4, m_player_turn == WHITE ? "ALB" : "NEGRU");
		m_moveIndex = -1;
		m_sendButtonClickedFlag = 0;
		m_diceClickFlag = 0;
		m_lastDiceMove1 = 0;
		m_lastDiceMove2 = 0;
		m_diceBitmapId = 0;
		m_diceBitmapId1 = 0;
		DrawBoard();
	}
	m_sendButtonClickedFlag = 0;

	if (m_mouseMoveFlag == false)
	{
		writeMessage("Flagul m_mouseMoveFlag este fals");
		return;
	}
	m_mouseMoveFlag = false;
	m_moveRect = 0;


	cb[m_point.x][m_point.y].SetPieceState(PIECE_NOT_MOVING);
	// Verifică dacă toate bilele au fost scoase din casă
	CRect lefttop = cb[0][14].GetRect(), rightbottom = cb[17][17].GetRect();
	CRect bearect(lefttop.left, lefttop.top, rightbottom.right, rightbottom.bottom);
	if (bearect.PtInRect(point))
	{
		if (allBallsAreInHome() == false)
		{
			DrawBoard();
			return;
		}
		int piece_id;
		COLOR_TYPE  piece_color;
		PIECE_TYPE  piece_type;
		STATE piece_state;
		cb[m_point.x][m_point.y].GetPieceData(piece_id, piece_color, piece_type, piece_state);
		// Nu permite mutarea dacă piesa nu este în casă
		if ((piece_id == CHECKERS_WHITE && cb[m_point.x][m_point.y].GetIndex() < 19) ||
			(piece_id == CHECKERS_BLACK && cb[m_point.x][m_point.y].GetIndex() > 6))
		{
			writeMessage("piesa nu este în casă %d", cb[m_point.x][m_point.y].GetIndex());
			DrawBoard();
			return;
		}
		int index = cb[m_point.x][m_point.y].GetIndex();
		writeMessage("mută bila cu indexul %d, id-ul piesei", index, piece_id);
		if (piece_id == CHECKERS_WHITE)
		{
			writeMessage("piese albe");
			index = 25 - index;
			if (m_lastDiceMove1 == 0)
			{
				writeMessage("ultima bilă 1 este zero");
				if (index == m_diceBitmapId)
				{
					writeMessage("Indexul se potrivește cu primul m_diceBitmapid");
					m_lastDiceMove1 = m_diceBitmapId;
				}
				else if (index == m_diceBitmapId1)
				{
					writeMessage("Indexul se potrivește cu al doilea m_diceBitmapid");
					m_lastDiceMove1 = m_diceBitmapId1;
				}
				else
				{
					writeMessage("indexul nu se potrivește cu nici o valoare de zar");
					DrawBoard();
					return;
				}
			}
			else if (m_lastDiceMove2 == 0)
			{
				writeMessage("ultima bilă 1 nu este zero, ultima bilă 2 este zero");
				if (index == m_diceBitmapId)
				{
					writeMessage("Indexul se potrivește cu m_diceBitmapid");
					m_lastDiceMove2 = m_diceBitmapId;
				}
				else if (index == m_diceBitmapId1)
				{
					writeMessage("Indexul se potrivește cu m_diceBitmapid1");
					m_lastDiceMove2 = m_diceBitmapId1;
				}
				else
				{
					writeMessage("Indexul nu se potrivește cu nicio valoare");
					DrawBoard();
					return;
				}
			}
			else
			{
				writeMessage("ambele mutări au fost efectuate");
				return;
			}
		}
		else
		{
			writeMessage("BLACK_CHEKERS, index %d", index);
			if (m_lastDiceMove1 == 0)
			{
				writeMessage("ultima mutare 1 este zero");
				if (index == m_diceBitmapId)
				{
					writeMessage("indexul se potrivește cu prima valoare");
					m_lastDiceMove1 = m_diceBitmapId;
				}
				else if (index == m_diceBitmapId1)
				{
					writeMessage("indexul se potrivește cu a doua valoare");
					m_lastDiceMove1 = m_diceBitmapId1;
				}
				else
				{
					writeMessage("indexul nu se potrivește cu niciun bitmap");
					DrawBoard();
					return;
				}
			}
			else if (m_lastDiceMove2 == 0)
			{
				writeMessage("ultima mutare 1 nu este zero, ultima mutare 2 este zero");
				if (index == m_diceBitmapId)
				{
					writeMessage("indexul se potrivește cu primul m_diceBitmap");
					m_lastDiceMove2 = m_diceBitmapId;
				}
				else if (index == m_diceBitmapId1)
				{
					writeMessage("indexul se potrivește cu al doilea m_diceBitmap");
					m_lastDiceMove2 = m_diceBitmapId1;
				}
				else
				{
					writeMessage("indexul nu se potrivește cu nicio valoare");
					DrawBoard();
					return;
				}
			}
			else
			{
				writeMessage("id-ul piesei nu este valid");
				DrawBoard();
				return;
			}
		}
		writeMessage("trimite mesaj către celălalt jucător");
		m_bearindex.x++;
		if (m_bearindex.x == 13)
		{
			m_bearindex.x = 4;
			m_bearindex.y++;
		}
		cb[m_bearindex.x][m_bearindex.y].SetPieceData(piece_id, piece_color, piece_type, piece_state);
		char data[100];
		int k = 0;
		data[k++] = BEAROFF;
		data[k++] = m_white_on_top;
		data[k++] = (char)m_point.x;
		data[k++] = (char)m_point.y;
		memcpy(&data[k], &piece_id, 4);
		k += 4;
		data[k++] = piece_color;
		data[k++] = piece_type;
		data[k++] = m_bearindex.x;
		data[k++] = m_bearindex.y;
		int topieceid = -1;
		memcpy(&data[k], &topieceid, 4);
		k += 4;
		data[k++] = NONE;
		data[k++] = BLANK;
		data[k++] = 0;
		data[k++] = 0;
		int rm_piece_id = -1;
		memcpy(&data[k], &rm_piece_id, 4);
		k += 4;
		data[k++] = NONE;
		data[k++] = BLANK;
		memcpy(&data[k], &m_topHistory, 4);
		k += 4;
		m_moveIndex++;
		m_moveLength[m_moveIndex] = k;
		memcpy(m_moveInfo[m_moveIndex], data, k);
		cb[m_point.x][m_point.y].SetPieceData(-1, NONE, BLANK, PIECE_NOT_MOVING);
		m_point.x = m_point.y = -1;
		DrawBoard();
		return;
	}
	writeMessage("după scoaterea bilelor din casă");
	for (int i = 0; i < m_level; i++)
	{
		if (i == 6) continue;
		for (int j = 0; j < m_level; j++)
		{
			if (j == 6) continue;
			if (cb[i][j].GetPieceId() == -1)
			{
				CRgn rgn;
				CRect rect1 = cb[i > 6 ? 7 : 0][j].GetRect();
				CRect rect2 = cb[i > 6 ? 12 : 5][j].GetRect();
				CRect rect(rect1.left, rect1.top, rect2.right, rect2.bottom);
				rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);
				if (rgn.PtInRegion(point) && rect != cb[m_point.x][m_point.y].GetRect())
				{
					int piece_id;
					COLOR_TYPE  piece_color;
					PIECE_TYPE  piece_type;
					STATE piece_state;
					int to_piece_id;
					COLOR_TYPE  to_piece_color;
					PIECE_TYPE  to_piece_type;
					STATE to_piece_state;
					int rm_piece_id = -1;
					COLOR_TYPE  rm_piece_color = NONE;
					PIECE_TYPE  rm_piece_type = BLANK;
					STATE rm_piece_state = PIECE_NOT_MOVING;
					cb[m_point.x][m_point.y].GetPieceData(piece_id, piece_color, piece_type, piece_state);
					cb[i][j].GetPieceData(to_piece_id, to_piece_color, to_piece_type, to_piece_state);
					cb[m_point.x][m_point.y].SetPieceState(PIECE_NOT_MOVING);
					if (piece_color == to_piece_color)
					{
						m_point.x = m_point.y = -1;
						DrawBoard();
						return;
					}
					int rmx = -1, rmy = -1;
					writeMessage("înainte de valid %d %d %d %d", i, j, rmx, rmy);
					if (CheckValidMove(i, j, rmx, rmy) == true)
					{
						writeMessage("după valid %d %d %d %d", i, j, rmx, rmy);
						if (i <= 6)
						{
							for (int k = 0; k <= i; k++)
							{
								if (cb[k][j].GetPieceId() == -1)
								{
									i = k;
									break;
								}
							}
						}
						else
						{
							for (int k = 13 - 1; k >= i; k--)
							{
								if (cb[k][j].GetPieceId() == -1)
								{
									i = k;
									break;
								}
							}
						}
						writeMessage("după validare1 %d %d %d %d", i, j, rmx, rmy);
						int ii = 0;
						if (rmx != -1)
						{
							writeMessage("rmx nu este -1, după validare %d %d %d %d", i, j, rmx, rmy);
							cb[rmx][rmy].GetPieceData(rm_piece_id, rm_piece_color, rm_piece_type, rm_piece_state);
							i = rmx;
							j = rmy;
							int k = 0;
							//cb[rmx][rmy].SetPieceData(piece_id, piece_color, piece_type, PIECE_NOT_MOVING);
							if (rm_piece_id == CHECKERS_WHITE)
							{
								for (k = 12; k > 6; k--)
								{
									if (cb[k][6].GetPieceId() == -1)
									{
										cb[k][6].SetPieceData(rm_piece_id, rm_piece_color, rm_piece_type, rm_piece_state);
										writeMessage("bila scoasă este pusă în poziția blot");
										break;
									}
								}
							}
							else
							{
								for (k = 0; k < 6; k++)
								{
									if (cb[k][6].GetPieceId() == -1)
									{
										cb[k][6].SetPieceData(rm_piece_id, rm_piece_color, rm_piece_type, rm_piece_state);
										writeMessage("bila scoasă este pusă în poziția blot");
										break;
									}
								}
							}
							ii = k;
						}
						writeMessage("rmx -1 s-a terminat, după validare %d %d %d %d", i, j, rmx, rmy);
						cb[i][j].SetPieceData(piece_id, piece_color, piece_type, PIECE_NOT_MOVING);
						cb[m_point.x][m_point.y].SetPieceType(BLANK);
						cb[m_point.x][m_point.y].SetPieceData(-1, NONE, BLANK, PIECE_NOT_MOVING);
						// Stochează informațiile despre mutare

						char data[100];
						int k = 0;
						data[k++] = MOVE;
						data[k++] = m_white_on_top;
						data[k++] = m_point.x;
						data[k++] = m_point.y;
						memcpy(&data[k], &piece_id, 4);
						k += 4;
						data[k++] = piece_color;
						data[k++] = piece_type;
						data[k++] = i;
						data[k++] = j;
						memcpy(&data[k], &to_piece_id, 4);
						k += 4;
						data[k++] = to_piece_color;
						data[k++] = to_piece_type;
						data[k++] = ii;
						data[k++] = 6;
						memcpy(&data[k], &rm_piece_id, 4);
						k += 4;
						data[k++] = rm_piece_color;
						data[k++] = rm_piece_type;
						memcpy(&data[k], &m_topHistory, 4);
						k += 4;
						m_moveIndex++;
						m_moveLength[m_moveIndex] = k;
						memcpy(m_moveInfo[m_moveIndex], data, k);
						m_point.x = m_point.y = -1;
					}
					DrawBoard();
					return;
				}
			}
		}
	}
	m_point.x = m_point.y = -1;
	DrawBoard();
}

void CNetChessView::OnMouseMoveAction(UINT nFlags, CPoint point)
{
	// Verifică dacă se efectuează o mutare cu mouse-ul
	if (m_mouseMoveFlag == false)
		return;

	// Creează un dreptunghi în jurul punctului curent de la mouse
	CRect rect(point.x - 25, point.y - 25, point.x + 25, point.y + 25);
	m_moveRect = rect;
	DrawBoard();
}


void CNetChessView::OnEditUndo()
{
}

void CNetChessView::OnEditUndoAction()
{
}


void CNetChessView::OnEditRedo() 
{

}

void CNetChessView::OnEditRedoAction()
{

}
void CNetChessView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	
	CView::OnRButtonDown(nFlags, point);
}

void CNetChessView::OnUpdateToolsServer(CCmdUI* pCmdUI) 
{
	
}

void CNetChessView::OnUpdateToolsClient(CCmdUI* pCmdUI) 
{

}

void CNetChessView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// Desenăm tabla de șah înainte de a efectua imprimarea
	DrawBoard();

	// Apelăm funcția CView::OnPrint() pentru a efectua procesul de imprimare
	CView::OnPrint(pDC, pInfo);

	// Această funcție este utilizată pentru a desena tabla de șah înainte de imprimarea acesteia și pentru a continua procesul de imprimare.
}


void CNetChessView::OnTimer(UINT nIDEvent) 
{
	static int state=1;	 
	switch(nIDEvent)
	{
		case SHELL_ICON_TIMER_EVENT_ID:

			{			
				
				if(state == 1)
				{					
					ShowTrayIcon(NIM_MODIFY,IDR_MAINFRAME,0);					
					state = 0;
				}
				else
				{
					ShowTrayIcon(NIM_MODIFY,IDI_ICON_MAINFRAME_OPPOSITE,0);					
					state = 1;					
				}
			}
			break;
		default:
			break;
		 
	}
	CView::OnTimer(nIDEvent);
}
void CNetChessView::KillTimerEvent()
{
}

void CNetChessView::OnFileNew()
{
	// Apelăm funcția OnFileNewAction() pentru a începe o partidă nouă în aplicație
	OnFileNewAction();

	// Trimitem un mesaj către adversarul online pentru a semnala începutul unei partide noi
	unsigned char data = NEWGAME;
	SendSockData(&data, 1);

	// Această funcție inițiază o partidă nouă în aplicație și trimite un mesaj către adversarul online pentru a începe jocul.
}

void CNetChessView::OnFileNewAction()
{
	// Inițializăm o nouă partidă
	Initialize(); // Apelez metoda Initialize() pentru inițializarea jocului

	// Actualizăm starea inițială a vizualizării
	OnInitialUpdate(); // Apelez OnInitialUpdate() pentru a actualiza vizualizarea inițială

	// Desenăm tabla de șah
	DrawBoard(); // Apelez DrawBoard() pentru a desena tabla de șah

	// Acțiunea acestei funcții este de a începe o partidă nouă în aplicație.
}

void CNetChessView::OnViewHistory() 
{

}

void CNetChessView::OnToolsWhiteontop() 
{

}


void CNetChessView::OnEditMovefirst() 
{

}

void CNetChessView::OnEditMovelast() 
{

}

void CNetChessView::OnHelpHowtoplay() 
{
	CHowToPlay dlg;	
	dlg.DoModal();	
}

void CNetChessView::OnToolsDisconnect() 
{
}

void CNetChessView::OnEditProperties() 
{
}

void CNetChessView::OnToolsGametype() 
{

}
void CNetChessView::SetPaneText(int paneno,CString str)
{
	((CMainFrame*)((CNetChessApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(paneno,str);
	//reactualizarea textului in aplicatie
}
void CNetChessView::ShowTrayIcon(DWORD message,int icon,int input)
{
		((CMainFrame*)((CNetChessApp*)AfxGetApp())->m_pMainWnd)->ShowTrayIcon(message,icon,input);
		//reactualizearea iconitelor
}

void CNetChessView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// Această funcție este apelată atunci când are loc un dublu clic pe butonul din stânga al mouse-ului.
	writeMessage("OnLButtonDblClk");
	OnLButtonDownAction(nFlags,point);//apasare
	CPoint pt = getOffsetPoint();
	OnLButtonUpAction(nFlags,pt);//terminarea apasarii
	CView::OnLButtonDblClk(nFlags, point);
}

//Această funcție se ocupă de calcularea unui decalaj pentru coordonatele pieselor de șah,
//luând în considerare diverse condiții specifice jocului și valorile zarurilor.
CPoint CNetChessView::getOffsetPoint()
{
	// Verificăm dacă se permite mișcarea cu mouse-ul
	if (m_mouseMoveFlag == false)
	{
		return 0; // Dacă nu, returnăm punctul de origine (0,0)
	}
	writeMessage("Se obține decalajul la dublu clic pe butonul din stânga al mouse-ului");

	// Obținem indexul și identificatorul piesei din caseta curentă
	int index = cb[m_point.x][m_point.y].GetIndex();
	int pieceid = cb[m_point.x][m_point.y].GetPieceId();
	writeMessage("Index și identificatorul piesei = %d %d", index, pieceid);
	writeMessage("lastdiceMoveid1 %d lastdicemoveid2 %d", m_lastDiceMove1, m_lastDiceMove2);

	// Verificăm tipul piesei (albă sau neagră)
	if (pieceid == CHECKERS_WHITE)
	{
		writeMessage("CHECKERS_WHITE");

		// Verificăm dacă primul zar este zero
		if (m_lastDiceMove1 == 0)
		{
			writeMessage("lastDiceMove1 este zero, m_lastDiceMove1 %d, m_lastDiceMove2 %d, m_diceBitmap1 %d, m_diceBitmap2 %d",
				m_lastDiceMove1, m_lastDiceMove2, m_diceBitmapId, m_diceBitmapId1);
			index = index + m_diceBitmapId;
		}
		else
		{
			writeMessage("lastDiceMove1 nu este zero, m_lastDiceMove1 %d, m_lastDiceMove2 %d, m_diceBitmap1 %d, m_diceBitmap2 %d",
				m_lastDiceMove1, m_lastDiceMove2, m_diceBitmapId, m_diceBitmapId1);

			// Verificăm dacă primul zar este egal cu m_diceBitmapId
			if (m_lastDiceMove1 == m_diceBitmapId)
			{
				writeMessage("Se adaugă valoarea din zar 1");
				index = index + m_diceBitmapId1;
			}
			else
			{
				writeMessage("Se adaugă valoarea din zar");
				index = index + m_diceBitmapId;
			}
		}
	}
	else
	{
		writeMessage("CHECKERS_BLACK");

		// Verificăm dacă primul zar este zero
		if (m_lastDiceMove1 == 0)
		{
			writeMessage("lastDiceMove1 este zero, m_lastDiceMove1 %d, m_lastDiceMove2 %d, m_diceBitmap1 %d, m_diceBitmap2 %d",
				m_lastDiceMove1, m_lastDiceMove2, m_diceBitmapId, m_diceBitmapId1);
			index = index - m_diceBitmapId;
		}
		else
		{
			// Verificăm dacă primul zar este egal cu m_diceBitmapId
			if (m_lastDiceMove1 == m_diceBitmapId)
			{
				writeMessage("Se scade valoarea din zar 1");
				index = index - m_diceBitmapId1;
			}
			else
			{
				writeMessage("Se scade valoarea din zar");
				index = index - m_diceBitmapId;
			}
		}
	}
	writeMessage("Noul index și identificatorul piesei = %d %d", index, pieceid);

	// Căutăm un index potrivit pe tabla de joc
	for (int j = 0; j < 13; j++)
	{
		if (j == 6) continue;

		// Verificăm dacă indexul din caseta de start este potrivit
		if (cb[0][j].GetIndex() == index)
		{
			CRect rect = cb[0][j].GetRect();
			CPoint pt(rect.left + 10, rect.top + 10); // Adăugăm un decalaj la punctul găsit
			writeMessage("S-a găsit indexul %d %d", 0, j);
			return pt; // Returnăm punctul modificat
		}

		// Verificăm dacă indexul din caseta de sfârșit este potrivit
		if (cb[12][j].GetIndex() == index)
		{
			CRect rect = cb[12][j].GetRect();
			CPoint pt(rect.left + 10, rect.top + 10); // Adăugăm un decalaj la punctul găsit
			writeMessage("S-a găsit indexul %d %d", 0, j);
			return pt; // Returnăm punctul modificat
		}
	}

	writeMessage("Nu s-a găsit nicio potrivire");
	return 0; // În caz contrar, returnăm punctul de origine (0,0)
}

//Această funcție se ocupă de verificarea dacă toate piesele unui anumit jucător se află în "casă" 
//(zona de pornire) pe tabla de șah. Dacă găsește măcar o piesă în afara "casei", returnează false, 
//altfel returnează true.
bool CNetChessView::allBallsAreInHome()
{
	int pieceid = cb[m_point.x][m_point.y].GetPieceId();

	// Verificăm dacă piesa este de tip alb
	if (pieceid == CHECKERS_WHITE)
	{
		// Parcurgem tabla de joc
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				// Excludem anumite cazuri speciale
				if (i < 6 && j > 6) continue;

				// Verificăm dacă există o piesă albă în afara "casei" sale
				if (cb[i][j].GetPieceId() == pieceid)
				{
					writeMessage("Piesa la poziția %d %d nu se află în casă", i, j);
					return false; // Dacă găsim o piesă în afara "casei", returnăm false
				}
			}
		}
	}
	// Verificăm dacă piesa este de tip negru
	else if (pieceid == CHECKERS_BLACK)
	{
		// Parcurgem tabla de joc
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				// Excludem anumite cazuri speciale
				if (i > 6 && j > 6) continue;

				// Verificăm dacă există o piesă neagră în afara "casei" sale
				if (cb[i][j].GetPieceId() == pieceid)
				{
					writeMessage("Piesa la poziția %d %d nu se află în casă", i, j);
					return false; // Dacă găsim o piesă în afara "casei", returnăm false
				}
			}
		}
	}

	writeMessage("Toate piesele se află în casă"); // Dacă nu am găsit piese în afara "casei", returnăm true
	return true;
}