#pragma once
#ifndef CGAME_H
#define CGAME_H

#include "CCAR.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"
#include <vector>
#include "CTRUCK.h"
#include <windows.h>

#define GAME_WIDTH 16
#define GAME_HEIGHT 7

class CGAME
{
public:
	CGAME();
	void draw();

	void update(int stop,bool redLight);
	void carUpdate(bool green = true);
	void truckUpdate(bool green = true);

	void input(char cmd);
	bool isDead() { return pep.isDead; };
	bool isDone() { return pep.isWin; };
	void save();
	~CGAME()
	{
		for (int i = 0; i < GAME_HEIGHT; i++)
		{
			delete[] gameBoard[i];
		}
	}
	void CHANGE_GAME_HANDLE(HANDLE poi) { gamethreadHandler = poi; };
private:
	CPEOPLE pep;
	std::vector<CCAR> carVct;
	std::vector<CTRUCK> truckVct;
	char** gameBoard;
	HANDLE gamethreadHandler;

};


#endif // !CGAME_H
