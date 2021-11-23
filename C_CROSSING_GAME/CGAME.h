#pragma once
#ifndef CGAME_H
#define CGAME_H

#include "CCAR.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"
#include <vector>

#define GAME_WIDTH 16
#define GAME_HEIGHT 3

class CGAME
{
public:
	CGAME();
	void draw();
	void update();
	void carUpdate(bool green = true);
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
private:
	CPEOPLE pep;
	std::vector<CCAR> carVct;
	char** gameBoard;

};


#endif // !CGAME_H
