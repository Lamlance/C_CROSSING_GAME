#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
using namespace std;
void Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void introgame() {
	Color(10);
	cout << "Hello";
}
