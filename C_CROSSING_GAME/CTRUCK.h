#pragma once
#include "CVEHICLE.h"
#include <string>

class CTRUCK : public CVEHICLE {
public:
	CTRUCK() : CVEHICLE() {};
	CTRUCK(int posX, int posY) : CVEHICLE(posX, posY) {};
	friend class CGAME;

private:
	static int spds;
	static int size;
	static int dist;
	static char symb;
};
