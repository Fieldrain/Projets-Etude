#include "stdafx.h"
#include "Window.h"


COORD Window::CoordonneToCOORD(Coordonne cor)
{
	COORD coordonne;
	coordonne.X = cor.X;
	coordonne.Y = cor.Y;

	return coordonne;
}

Coordonne Window::COORDToCoordonne(COORD cor)
{
	Coordonne coordonne;
	coordonne.X = cor.X;
	coordonne.Y = cor.Y;

	return coordonne;
}

void Window::resizeWindow()
{
	CONSOLE_SCREEN_BUFFER_INFOEX csbi;
	GetConsoleScreenBufferInfoEx(console, &csbi);

	csbi.srWindow = rectWindow;
	csbi.dwMaximumWindowSize = size;
	csbi.dwSize = size;
	csbi.bFullscreenSupported = false;

	SetConsoleScreenBufferInfoEx(console, &csbi);
}

void Window::EffacerEcran()
{
	resizeWindow();
	system("cls");
}

void Window::DeplacerCurseur(Coordonne position)
{
	resizeWindow();
	SetConsoleCursorPosition(console, CoordonneToCOORD(position));
}

void Window::DeplacerCurseurXY(uint8_t x, uint8_t y)
{
	resizeWindow();
	Coordonne position;
	position.X = x;
	position.Y = y;

	SetConsoleCursorPosition(console, CoordonneToCOORD(position));
}

Coordonne Window::PositionCurseur()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(console, &csbi);

	return COORDToCoordonne(csbi.dwCursorPosition);
}

void Window::ChangerLigneCurseur(uint8_t line)
{
	resizeWindow();
	Coordonne position = PositionCurseur();
	position.Y = line;

	SetConsoleCursorPosition(console, CoordonneToCOORD(position));
}

void Window::ChangerColonneCurseur(uint8_t row)
{
	resizeWindow();
	Coordonne position = PositionCurseur();
	position.X = row;

	SetConsoleCursorPosition(console, CoordonneToCOORD(position));
}

void Window::EcrireEnPosition(Coordonne position, string texte)
{
	resizeWindow();
	SetConsoleCursorPosition(console, CoordonneToCOORD(position));

	cout << texte;
}

void Window::EcrireNbEnPosition(Coordonne position, uint8_t nb)
{
	resizeWindow();
	SetConsoleCursorPosition(console, CoordonneToCOORD(position));

	cout << nb;
}

void Window::DessinerCadreXY(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool bordureDouble, ECouleur coulTrait, ECouleur coulFond)
{
	resizeWindow();

	Couleurs(coulTrait, coulFond);

	map<string, int> bordSimple;
	bordSimple["CHG"] = 9484;
	bordSimple["CHD"] = 9488;
	bordSimple["CBG"] = 9492;
	bordSimple["CBD"] = 9496;
	bordSimple["H"] = 9556;
	bordSimple["V"] = 9474;

	map<string, int> bordDouble;
	bordDouble["CHG"] = 9556;
	bordDouble["CHD"] = 9559;
	bordDouble["CBG"] = 9562;
	bordDouble["CBD"] = 9565;
	bordDouble["H"] = 9552;
	bordDouble["V"] = 9553;

	map<string, int> bord = ((bordureDouble) ? (bordDouble) : (bordSimple));

	for(uint8_t i = x1; i < x2; i++) {
		for (uint8_t j = y1; j < y2; j++) {

			if (i == x1 && j == y1)
				cout << char(bord["CHG"]);

			else if(i == x2 && j == y1)
				cout << char(bord["CHD"]);

			else if(i == x1 && j == y2)
				cout << char(bord["CBG"]);

			else if(i == x2 && j == y2)
				cout << char(bord["CBD"]);

			else if(j == y1 || j == y2)
				cout << char(bord["H"]);

			else if(i == x1 || i == x2)
				cout << char(bord["V"]);

			else
				cout << ' ';
		}
	}
}

void Window::DessinerCadre(Coordonne x, Coordonne y, bool bordureDouble, ECouleur coulTrait, ECouleur coulFond)
{
	DessinerCadreXY(x.X, x.Y, y.X, y.X, bordureDouble, coulTrait, coulFond);
}

void Window::Attendre(uint16_t temps)
{
	Sleep(temps);
}

void Window::CouleurFond(ECouleur couleur)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(console, &csbi);
	ECouleur couleurTexte = ECouleur(csbi.wAttributes % 16);

	Couleurs(couleurTexte, couleur);
}

void Window::CouleurTexte(ECouleur couleur)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(console, &csbi);
	ECouleur couleurFond = ECouleur((csbi.wAttributes/16)%16);

	Couleurs(couleur, couleurFond);
}

void Window::Couleurs(ECouleur couleurTexte, ECouleur couleurFond)
{
	resizeWindow();
	int textcol = int(couleurTexte);
	int backcol = int(couleurFond);

	textcol %= 16;
	backcol %= 16;

	unsigned short wAttributes = ((unsigned)backcol << 4) | (unsigned)textcol;
	SetConsoleTextAttribute(console, wAttributes);
}

string Window::RetourSaisi()
{
	string saisi;

	cin >> saisi;

	return saisi;
}

Window::Window()
{
	console = GetStdHandle(STD_OUTPUT_HANDLE);

	rectWindow.Top = 0;
	rectWindow.Bottom = 24;
	rectWindow.Left = 0;
	rectWindow.Right = 79;

	size.X = 79;
	size.Y = 24;

	CONSOLE_SCREEN_BUFFER_INFOEX csbi;
	GetConsoleScreenBufferInfoEx(console, &csbi);

	csbi.srWindow = rectWindow;
	csbi.dwMaximumWindowSize = size;
	csbi.dwSize = size;
	csbi.bFullscreenSupported = false;

	SetConsoleScreenBufferInfoEx(console, &csbi);
}


Window::~Window()
{
}
