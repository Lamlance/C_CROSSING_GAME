#pragma once
#ifndef CDINOSAUR_H
#define CDINOSAUR_H

#include "CVEHICLE.h"

class CDINOSAUR : public CVEHICLE
{
public:
	CDINOSAUR() :CVEHICLE() {};
	CDINOSAUR(int posX, int posY) :CVEHICLE(posX, posY) {};
	friend class CGAME;


private:
	static int spds;
	static int size;
	static int dist;
	static char symb;

};

#endif // !CDINOSAUR_H
