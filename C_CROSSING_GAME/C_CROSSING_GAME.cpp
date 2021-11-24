// C_CROSSING_GAME.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include <thread>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "CGAME.h"
#include<conio.h>
static CGAME game;
bool IS_RUN = true;
char MOVE = '1';

double timePass_since(double startTime)
{
	return (clock() - startTime) / CLOCKS_PER_SEC;
	
}

void dogame()
{
	double startTime = clock();
	double stopTime = 0;
	int num = 1;
	while (IS_RUN)
	{
		++num;
		if (timePass_since(startTime) < 5)// car go
		{
			game.carUpdate(num % 3);
			game.truckUpdate(num % 2);
			stopTime = clock();
		}
		else
		{
			if (timePass_since(stopTime) >= 10)
			{
				stopTime = clock();
				startTime = clock();
			}
		}
		game.eleUpdate(num % 2);
		game.dinoUpdate(num % 2);

		game.draw();
		MOVE = ' ';
		IS_RUN = (MOVE != '0') && !(game.isDead()) && !(game.isDone());
		std::this_thread::sleep_for(std::chrono::milliseconds(400));
		num = num % 7;
	}
	if (IS_RUN == false)
	{
		//abort();
	}
}

int main()
{
	/*for (unsigned char i = 0; i < UCHAR_MAX; i++)
	{
		std::cout << int(i) << ": " << char(i) << std::endl;
	}

	return 0;*/

	std::thread th1(dogame);
	while (IS_RUN)
	{
		MOVE = _getch();
		std::cin.clear();
		if (MOVE == 'p')
		{
			SuspendThread(th1.native_handle());
		}
		else if(MOVE == 'c')
		{
			ResumeThread(th1.native_handle());
		}
		else
		{
			if (IS_RUN)
			{
				game.input(MOVE);
			}
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
		game.update(true,true);
		std::cout << "DONE";
	}
	else
	{
		game.update(true, true);
		std::cout << "Exit";
	}

	return 0;
}

