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
#define GAME_WIDTH 40
#define GAME_HEIGHT 20

class CGAME
{
public:
	CGAME(HANDLE &Consolehandler);
	void draw();
	void drawBorder();
	//void update(int stop,bool redLight);
	void carUpdate(bool green = true);
	void truckUpdate(bool green = true);
	void dinoUpdate(bool green = true);
	void eleUpdate(bool green = true);
	void input(char cmd);
	bool isDead() { return pep.isDead; };
	bool isDone() { return pep.isWin; };
	void save();
	void turnRed(bool redLight) { carIsStop = redLight; }
	void saveGame(std::string fileName);
	void loadGame(std::string fileName);

	bool havePep(int xPos, int yPos)
	{
		return (xPos == pep.mX) && (yPos == pep.mY);
	}

	bool pepRunInto();

	~CGAME()
	{
		for (int i = 0; i < GAME_HEIGHT; i++)
		{
			//delete[] gameBoard[i];
		}
	}
	//void CHANGE_GAME_HANDLE(HANDLE poi) { gamethreadHandler = poi; };
private:
	//int ConsoleColumns, ConsoleRows;

	bool carIsStop;
	CPEOPLE pep;
	std::vector<CCAR> carVct;
	std::vector<CTRUCK> truckVct;
	std::vector<CDINOSAUR> dinoVct;
	std::vector<CELEPHANT> eleVct;


	char** gameBoard;
	std::vector<int> CarTruck_yLine;
	std::vector<int> animal_yLine;
	HANDLE Consolehandle;
};


#endif // !CGAME_H
