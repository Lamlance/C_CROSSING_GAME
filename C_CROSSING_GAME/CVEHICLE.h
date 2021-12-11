#pragma once
#ifndef CVEHICLE_H
#define CVEHICLE_H
#include <string>
#include <vector>

class CVEHICLE
{
public:
	CVEHICLE() :mX(0), mY(0){};
	CVEHICLE(int posX, int posY) :mX(posX), mY(posY) {};
	virtual void Move(int width, int speed)
	{
		mX = (mX + speed) % width;
	};
	int getX() { return mX; };
	int getY() { return mY; };
	virtual char getChar() { return '?'; };
	friend class CGAME;

private:
	int mX;
	int mY;
};

#endif // !CCAR_H
