#pragma once
#ifndef CTRUCK_H
#define CTRUCK_H

#include "CVEHICLE.h"
#include <string>

class CTRUCK : public CVEHICLE {
public:
	CTRUCK() : CVEHICLE() {};
	CTRUCK(int posX, int posY) : CVEHICLE(posX, posY) {};
	friend class CGAME;
	char getChar() { return symb; };

private:
	static int spds;
	static int size;
	static int dist;
	static char symb;
};

#endif // !CTRUCK_H


