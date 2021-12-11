#pragma once
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <iomanip>
#include <locale>
#include <codecvt>
#include "CGAME.h"

#define consoleWidth 100
#define consoleHeight 25

struct object
{
	char t[30];
	int x, y;
};

struct chartext {
	char t[41];
	char t2[41];
	char t3[41];
};

void cls(HANDLE hConsole);
void gameIntro(HANDLE handle);
void gotoxy(short x, short y);
void box(int x, int y, HANDLE h, int& select);
void rule(HANDLE handle, int& option);
void about(HANDLE handle, int& option);
void goodbye(HANDLE h);
void win(HANDLE h);
void lose(HANDLE h);
