#pragma once

class CPEOPLE {
public:
	CPEOPLE() = default;
	CPEOPLE(int width, int height);
	void Down(int height) { mY = (mY + 1) * (mY != height - 1) + mY * (mY == height - 1); };
	void Left(int width) { mX = (mX != 0) * (mX - 1); };
	void Right(int width) { mX = (mX != width - 1) * (mX + 1) + mX * (mX == width - 1); };
	void Up(int height) { mY = (mY != 0) * (mY - 1); };
	void reset();
	friend class CGAME;
	//bool isImpact(const CVEHICLE*&);
	//bool isImpact(const CANIMAL*&);

private:
	int initX, initY;
	int mX, mY;
	bool isDead;
	bool isWin;
};