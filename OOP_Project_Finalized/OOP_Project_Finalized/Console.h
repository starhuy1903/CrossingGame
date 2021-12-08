#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#define COLOR_RED 4
#define COLOR_GREEN 2
#define COLOR_WHITE 7

void gotoXY(int, int);

void fixConsoleWindow();

void resizeWindow(int, int);

void setWindowPosition(int,int);

void showConsoleCursor(bool);

void setColor(int);

void clearScreen();

int inputKey();

#endif // !_CONSOLE_H_

