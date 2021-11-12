// C_CROSSING_GAME.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include <thread>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

class CGAME // Xoa khi bat dau lam header
{
public:
	void update();
	bool isDead();
	bool isDone();
	void input(char cmd);
	void draw();
private:

};


static CGAME game;
bool IS_RUN = true;
char MOVE = '1';

void dogame()
{
	while (IS_RUN)
	{
		game.update();
		MOVE = ' ';
		IS_RUN = (MOVE != '0') && !(game.isDead()) && !(game.isDone());
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	if (IS_RUN == false)
	{
		std::cout << "Enter to done\n";
	}
}

int main()
{
	std::thread th1(dogame);
	while (IS_RUN)
	{
		std::cin >> MOVE;
		std::cin.clear();
		if (IS_RUN)
		{
			game.input(MOVE);
		}
		MOVE = '1';
		IS_RUN = (MOVE != '0') && !(game.isDead()) && !(game.isDone());
	}
	th1.join();
	if (game.isDead())
	{
		system("cls");
		game.draw();
		std::cout << "DED";
	}
	else if (game.isDone())
	{
		game.update();
		std::cout << "DONE";
	}
	else
	{
		game.update();
		std::cout << "Exit";
	}

	return 0;
}

