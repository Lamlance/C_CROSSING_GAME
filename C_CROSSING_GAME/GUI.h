#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#define consoleWidth 100
#define consoleHeight 25
struct carrunning
{
	char t[30];
	int x, y;
};
void cls(HANDLE hConsole);
void gameIntro();
void gotoxy(short x, short y);