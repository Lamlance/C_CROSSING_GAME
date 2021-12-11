#include "CPEOPLE.h"

CPEOPLE::CPEOPLE(int width, int height):
	mX(width / 2), mY(height), isDead(false), isWin(false),initX(width / 2),initY(height) {};

void CPEOPLE::reset()
{
	mX = initX;
	mY = initY;
	isDead = false;
	isWin = false;
}