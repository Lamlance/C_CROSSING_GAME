#pragma once
#ifndef CGAME_H
#define CGAME_H
#include "CDINOSAUR.h"
#include "CELEPHANT.h"
#include "CCAR.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"
#include <vector>
#include "CTRUCK.h"
#include <windows.h>
#define GAME_WIDTH 20
#define GAME_HEIGHT 15

class CGAME
{
public:
	CGAME();
	void draw();

	void update(int stop,bool redLight);
	void carUpdate(bool green = true);
	void truckUpdate(bool green = true);
	void dinoUpdate(bool green = true);
	void eleUpdate(bool green = true);
	void input(char cmd);
	bool isDead() { return pep.isDead; };
	bool isDone() { return pep.isWin; };
	void save();
	void saveGame(std::string fileName);
	void loadGame(std::string fileName);
	~CGAME()
	{
		for (int i = 0; i < GAME_HEIGHT; i++)
		{
			delete[] gameBoard[i];
		}
	}
	//void CHANGE_GAME_HANDLE(HANDLE poi) { gamethreadHandler = poi; };
private:
	bool carIsStop;
	CPEOPLE pep;
	std::vector<CCAR> carVct;
	std::vector<CTRUCK> truckVct;
	std::vector<CDINOSAUR> dinoVct;
	std::vector<CELEPHANT> eleVct;
	char** gameBoard;
	//HANDLE gamethreadHandler;
};


#endif // !CGAME_H
