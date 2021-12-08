#pragma once
#ifndef CELEPHANT_H
#define CELEPHANT_H

#include "CVEHICLE.h"

class CELEPHANT : public CVEHICLE
{
public:
	CELEPHANT() :CVEHICLE() {};
	CELEPHANT(int posX, int posY) :CVEHICLE(posX, posY) {};
	friend class CGAME;
	char getChar() { return symb; };

private:
	static int spds;
	static int size;
	static int dist;
	static char symb;

};

#endif // !CELEPHANT_H
