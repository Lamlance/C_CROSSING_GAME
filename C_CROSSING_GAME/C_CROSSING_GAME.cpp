// C_CROSSING_GAME.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include <thread>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "CGAME.h"
#include<conio.h>
#include <string>
#include "GUI.h"

bool IS_RUN = true;
char MOVE = '1';
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
static CGAME game(handle);
int level = 3;
bool continuee = false;

double timePass_since(double startTime)
{
	return (clock() - startTime) / CLOCKS_PER_SEC;
}

void drawConsole()
{
	while (IS_RUN)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		game.draw();
		if (!IS_RUN)
		{
			while (!IS_RUN && level > 0) {}
		}
	}
}

void dogame()
{
	double startTime = clock();
	double stopTime = 0;
	int num = 1;
	bool RUN = true;
	std::thread th2(drawConsole);

	while (IS_RUN)
	{
		continuee = false;
		//timeScore();
		++num;
		if (timePass_since(startTime) <= 10)// car go
		{
			game.carUpdate(num % 3);
			game.truckUpdate(num % 2);
			stopTime = clock();
		}
		else
		{
			game.turnRed(true);
			if (timePass_since(stopTime) >= 5) // car stop
			{
				game.turnRed(false);
				stopTime = clock();
				startTime = clock();
			}
		}
		game.eleUpdate(num % 2);
		game.dinoUpdate(num % 3);

		//game.draw();
		MOVE = ' ';
		IS_RUN = (MOVE != '0') && !(game.isDead()) && !(game.isDone()) && (level > 0);
		std::this_thread::sleep_for(std::chrono::milliseconds(200) * level);
		num = num % 7;
		if (!IS_RUN)
		{
			RUN = false;
			SuspendThread((HANDLE)th2.native_handle());
			system("cls");
			std::cout << " Press Enter to continue";
			while (!IS_RUN) {}
			ResumeThread((HANDLE)th2.native_handle());
		}
	}
}



int main()
{
	UINT default_encoding = GetConsoleOutputCP();
	std::string filepath;
	gameIntro(handle);
	int select = 0;

	do
	{
		box(33, 8, handle, select);
		if (select == 2)
		{
			rule(handle, select);
		}
		if (select == 6)
		{
			box(33, 8, handle, select);
		}
		if (select == 3)
		{
			about(handle, select);
			SetConsoleOutputCP(default_encoding);
		}

	} while (select != 0 && select != 4 && select != 1);

	if (select != 4)
	{
		SetConsoleTextAttribute(handle, 10); // White
		std::thread th1(dogame);

		while (IS_RUN)
		{
			if (select == 1)
			{
				MOVE = 'l';
				select = 0;
			}
			else
			{
				// use _getch() in order not to hit enter while moving
				MOVE = _getch();
				std::cin.clear();
			}
			// pause
			// press p to pause game
			if (MOVE == 'p')
			{
				SuspendThread(th1.native_handle());
			}
			// press c to continue game
			else if (MOVE == 'c')
			{
				ResumeThread((HANDLE)th1.native_handle());
			}
			// press k to save game
			else if (MOVE == 'k') 
			{
				system("cls");
				SuspendThread((HANDLE)th1.native_handle());
				//pause game befor inter file save name
				std::cout << "Save file name: ";
				std::getline(std::cin, filepath);
				game.saveGame(filepath);
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				ResumeThread((HANDLE)th1.native_handle());
				system("cls");
			}

			// load game
			// press l to load game
			else if (MOVE == 'l')
			{
				SuspendThread((HANDLE)th1.native_handle());
				system("cls");
				std::cout << "Load file path: ";
				std::getline(std::cin, filepath);
				game.loadGame(filepath);
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				ResumeThread((HANDLE)th1.native_handle());
				system("cls");
			}
			else if(MOVE == '[')
			{
				game.instaWin();
			}
			else
			{
				if (IS_RUN && (MOVE == 'a' || MOVE == 'w' || MOVE == 's' || MOVE == 'd'))
				{
					game.input(MOVE);
				}
			}
			MOVE = '1';
			IS_RUN = (MOVE != '0') && !(game.isDead()) && !(game.isDone()) && (level > 0);

			if (!IS_RUN && level > 0)
			{
				SuspendThread((HANDLE)th1.native_handle());
				system("cls");

				if (game.isDead())
				{
					system("cls");
					lose(handle);
					char ans;
					std::cout << "You are ded :)). Restart enter y: ";
					std::cin >> ans;
					if (ans == 'y')
					{
						continuee = true;
						IS_RUN = true;
						game.reset();
						level = 3;
						ResumeThread((HANDLE)th1.native_handle());
					}
				}
				else if (game.isDone())
				{
					system("cls");
					win(handle);
					std::cout << "Level complete loading next level ...";
					std::this_thread::sleep_for(std::chrono::milliseconds(3000));
					level--;
					continuee = true;
					IS_RUN = true;
					game.reset();
					ResumeThread((HANDLE)th1.native_handle());

				}
			}
		}

		if (game.isDead())
		{
			lose(handle);
		}
		else if (game.isDone())
		{
			win(handle);
		}

		cls(handle);
		goodbye(handle);

		exit(0);

		th1.join();
	}
	return 0;
}



//chua biet code ntn de dua vao su dung save voi load
		/*if (MOVE == 'l') {
			SuspendThread(th1.native_handle());
			std::cout << "Inter name fileSave: ";
			std::string path;
			std::cin >> path;
			game.saveGame(path);
		}*/
		/*std::cout << "Continue(c) or Exit(e)"<<std::endl;
		if (MOVE == 'c') {
				ResumeThread(th1.native_handle());
			}
		else if (MOVE == 'e') {
				game.isDone();
		}*/
