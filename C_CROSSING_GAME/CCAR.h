#pragma once
#ifndef CCAR_H
#define CCAR_H

#include "CVEHICLE.h"

class CCAR : public CVEHICLE
{
public:
	CCAR() :CVEHICLE() {};
	CCAR(int posX, int posY) :CVEHICLE(posX, posY) {};
	friend class CGAME;
	char getChar() { return symb; };


private:
	static int spds;
	static int size;
	static int dist;
	static char symb;
	
};

#endif // !CCAR_H
