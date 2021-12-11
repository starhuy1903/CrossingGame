#include "Console.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

void gotoXY(int Xcoor, int Ycoor)
{
	COORD coord;
	coord.X = Xcoor;
	coord.Y = Ycoor;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void fixConsoleWindow() 
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void resizeWindow(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void setWindowPosition(int x, int y)
{
	HWND consoleWindow = GetConsoleWindow();

	SetWindowPos(consoleWindow, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

}

void showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = showFlag; 
	SetConsoleCursorInfo(out, &cursorInfo);
}

void setColor(int color_value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_value);
}

void clearScreen() // https://www.cplusplus.com/articles/4z18T05o/
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

int inputKey()
{
	if (_kbhit())
	{
		char temp = _getch();
		temp = toupper(temp);

		switch (temp)
		{
		case 'W':case 'A':case 'S':case 'D':case 'P':case 'T':case 'L':case 13:case 27:
			return temp;
			break;
		default:
			return -1;
		}
	}

	return -1;
}

// FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

