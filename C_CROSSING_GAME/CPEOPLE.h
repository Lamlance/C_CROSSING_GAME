#pragma once
#ifndef CPEOPLE_H
#define CPEOPLE_H

class CPEOPLE
{
public:
    CPEOPLE() = default;
    CPEOPLE(int width, int height) :mX(width / 2), mY(height), isDead(false), isWin(false) {};

    void Down(int height) { mY = (mY + 1) * (mY != height - 1) + mY * (mY == height - 1); };
    void Left(int width) { mX = (mX != 0) * (mX - 1); };
    void Right(int width) { mX = (mX + 1) * (mX != width - 1) + mX * (mY == width - 1); };
    void Up(int height) { mY = (mY - 1); };

    friend class CGAME;
    //bool isImpact(const CVEHICLE*&);
    //bool isImpact(const CANIMAL*&);
private:
    int mX, mY;
    bool isDead;
    bool isWin;
};

#endif // !CPEOPLE_H
