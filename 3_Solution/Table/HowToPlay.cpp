#include "stdafx.h"
#include "NetChess.h"
#include "HowToPlay.h"

CHowToPlay::CHowToPlay(CWnd* pParent) : CDialog(CHowToPlay::IDD, pParent)
{
	m_edit_string = _T("");
}


void CHowToPlay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_STRING, m_edit_string);
}


BEGIN_MESSAGE_MAP(CHowToPlay, CDialog)
END_MESSAGE_MAP()


BOOL CHowToPlay::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	m_edit_string = "\t\t\tCUM SE JOACA Net Backgammon\r\n\tNetBackgammon este un joc de Backgammon care poate fi jucat intre doi jucatori pe aceeasi "
		"tabla sau prin LAN, intranet folosind comunicarea TCP/IP. Jocul de Backgammon se joaca pe o tabla "
		"intre doi jucatori. Tabla consta in 24 de puncte sau triunghiuri inguste in culori alternative"
		"(Alege culoarea triunghiurilor din Edit->Optiuni)."
		" Aceste puncte sunt impartite in patru cadranuri. Aceste cadranuri sunt numite tabla de acasa si "
		"tabla exterioara a jucatorului si tabla de acasa si tabla exterioara a adversarului. Tabla de acasa si tabla exterioara sunt "
		"separate de bara. Punctele sunt numerotate de la 1 la 24 incepand de la tabla de acasa. Fiecare jucator "
		"are 15 piese de culoarea sa (Selecteaza culoarea din Edit->Proprietati).\r\nAranjamentul initial "
		"al NetBackgammon este stabilit automat astfel: doua piese pe punctul 24 al fiecarui jucator, "
		"cinci piese pe punctul 13 al fiecarui jucator, trei piese pe punctul 8 al fiecarui jucator si cinci piese pe "
		"punctul 6 al fiecarui jucator.\r\n"
		"Scopul jocului este sa mute toate piesele in propriul acasa si sa le scoata din joc.\r\n\r\n"
		"Nota: dublarea nu este suportata in acest joc.\r\n\r\n"
		"Regulile jocului:\r\n"
		"Apasa pe zaruri (cuburi rosii de pe partea dreapta a tablei). Muta piesele in functie de "
		"numerele de pe zaruri si apasa pe Trimite. Dublu click pe o piesa muta piesa in functie de "
		"numarul de pe zar.\r\n"
		"1. O piesa poate fi mutata pe un punct liber, care nu este ocupat de doua sau mai multe piese adverse.\r\n"
		"2. Un jucator trebuie sa mute ambele numere daca este posibil.\r\n\r\n"
		"Capturarea:\r\n"
		"Un punct ocupat de o singura piesa, indiferent de culoare, se numeste blot. Daca o piesa adversa "
		"ajunge pe un blot, blot-ul este capturat si plasat pe bara.\r\nOricand un jucator are una sau mai multe "
		"piese pe bara, prima obligatie este sa introduca acele piese in tabla adversa. O piesa este introdusa prin mutarea sa pe un punct liber corespunzator unuia dintre numerele "
		"de pe zar/dublu click pe ea. Daca nu este posibila nicio mutare, atunci jucatorul isi pierde randul si "
		"apasa pe Trimite pentru ca celalalt jucator sa joace\r\n\r\n"
		"Scoaterea pieselor din joc:\r\nOdata ce un jucator si-a mutat toate cele 15 piese in tabla sa de acasa, poate "
		"incepe sa scoata piesele din joc. Un jucator scoate o piesa prin rularea unui numar care corespunde "
		"punctului in care se afla piesa si apoi indeparteaza piesa respectiva de pe tabla. "
		"Astfel, daca se ruleaza un 4, jucatorul poate indeparta o piesa din al patrulea punct.\r\n\r\n"
		"Cum sa incepi:\r\n"
		"Pentru a incepe jocul, fiecare jucator porneste jocul pe propriul sau dispozitiv. Cei care doresc sa joace cu "
		"piesele albe trebuie sa ruleze ca server (Instrumente->Server), iar ceilalti trebuie sa seconecteze (Instrumente->Client) la server. Doar o singura conexiune este acceptata pe server. Odata ce conexiunea este stabilita "
		"(verifica conexiunea facand clic pe Editare->Proprietati), "
		"jucatorul cu piesele albe incepe jocul facand clic pe zaruri (imediat datele zarurilor vor fi reflectate pe "
		"ambele table) si muta piesele in functie de numere. "
		"Dupa ce mutarile (mutarea corespunzatoare numarului de pe primul zar si mutarea corespunzatoare numarului de pe al doilea zar) sunt facute, apasa pe Trimite. "
		"Mutarile pieselor vor fi reflectate pe ambele table. "
		"Randul jucatorului va fi afisat in bara de stare.\r\n\r\n"
		"\r\nAlte caracteristici sunt: -----\r\n"
		"Fisier->Nou Un nou joc va fi inceput prin stergerea jocului in desfasurare.\r\n"
		"Editare->Optiuni poate fi folosit pentru a schimba culoarea patratelor si a pieselor de pe tabla.\r\n"
		"Editare->Proprietati va afisa starea curenta a conexiunii in joc.\r\n"
		"Editare->Anulare Anuleaza ultima mutare sau ultimele doua mutari. Anularea poate fi facuta inainte de a trimite mutarea. Odata ce mutarea este trimisa, nu o poti anula.\r\n"
		"Instrumente->Trimite mesaj poate fi folosit pentru a trimite mesaj instant catre celalalt jucator.\r\n"
		"Instrumente->Deconectare deconecteaza din jocul pe retea.\r\n"
		"Vizualizare->Ascunde va ascunde tabla curenta si va plasa un icon in bara de sistem. "
		"Pentru a activa din nou jocul, da clic pe iconul NetBackgammon din bara de sistem, tabla ascunsa "
		"va fi activata.\r\n\r\n"
		"De fiecare data cand exista o mutare, un mesaj sau orice alta actiune, un icon va fi comutat in bara de sistem. "
		"Facand clic pe iconul din bara de sistem, jocul ascuns va fi afisat.\r\n\r\n"
		"Acest software este destinat sa se joace jocul NetBackgammon intre doi jucatori prin retea sau pe aceeasi tabla.\r\n\r\n"
		"Bucura-te de jocul gratuit!!!";

UpdateData(FALSE);
	return TRUE;
}
