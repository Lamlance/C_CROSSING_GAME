#include "CGAME.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <windows.h>

void CGAME::input(char cmd)
{

	switch (cmd)
	{
	case 'w':
	{
		gameBoard[pep.mY][pep.mX] = '.';
		pep.Up(GAME_HEIGHT);
		pep.isDead = pep.isDead || (gameBoard[pep.mY][pep.mX] != '.');
		pep.isWin = pep.isWin || (pep.mY == 0);
		return;
	}
	case 's':
	{
		gameBoard[pep.mY][pep.mX] = '.';
		pep.Down(GAME_HEIGHT);
		return;
	}
	case 'a':
	{
		gameBoard[pep.mY][pep.mX] = '.';
		pep.Left(GAME_HEIGHT);
		pep.isDead = pep.isDead || (gameBoard[pep.mY][pep.mX] != '.');
		pep.isWin = pep.isWin || (pep.mY == 0);
		return;
	}
	case 'd':
	{
		gameBoard[pep.mY][pep.mX] = '.';
		pep.Right(GAME_WIDTH);
		return;
	}
	default:
		break;
	}
}

void CGAME::draw()
{
	
	system("cls");
	//init car characte
	int vctSize = carVct.size();
	for (int i = 0; i < vctSize; i++)
	{
		gameBoard[carVct[i].mY][carVct[i].mX] = CCAR::symb;
	}

	//inti truck character
	vctSize = truckVct.size();
	for (int i = 0; i < vctSize; i++)
	{
		gameBoard[truckVct[i].mY][truckVct[i].mX] = CTRUCK::symb;
	}

	//init dino character
	vctSize = dinoVct.size();
	for (int i = 0; i < vctSize; i++)
	{
		gameBoard[dinoVct[i].mY][dinoVct[i].mX] = CDINOSAUR::symb;
	}

	//inti ele character
	vctSize = eleVct.size();
	for (int i = 0; i < vctSize; i++)
	{
		gameBoard[eleVct[i].mY][eleVct[i].mX] = CELEPHANT::symb;
	}

	//init people character
	gameBoard[pep.mY][pep.mX] = '^';

	std::cout << char(219);
	for (int x = 0; x < GAME_WIDTH; x++) { std::cout << char(219); }
	std::cout << char(219) << std::endl;

	for (int y = 0; y < GAME_HEIGHT; y++)
	{
		if (y == carVct[0].getY() || y == truckVct[0].getY())
		{
			//Chuyen do xanh
			std::cout << char(219);
			//Trang tro lai
			for (int x = 0; x < GAME_WIDTH; x++)
			{
				std::cout << char(gameBoard[y][x]);
			}
			//Chuyen do xanh
			std::cout << char(219) << std::endl;
			//Trang tro lai
		}
		else
		{
			std::cout << char(219);
			for (int x = 0; x < GAME_WIDTH; x++)
			{
				std::cout << char(gameBoard[y][x]);
			}
			std::cout << char(219) << std::endl;
		}
		
	}

	std::cout << char(219);
	for (int x = 0; x < GAME_WIDTH; x++) { std::cout << char(219); }
	std::cout << char(219) << std::endl;
}

void CGAME::eleUpdate(bool green)
{
	if (!green) { return; }
	int vctSize = eleVct.size();
	for (int i = 0; i < vctSize; i++)
	{
		if (gameBoard[eleVct[i].mY][eleVct[i].mX] != '^')
		{
			gameBoard[eleVct[i].mY][eleVct[i].mX] = '.';
		}
		eleVct[i].Move(GAME_WIDTH, CELEPHANT::spds);
		pep.isDead = pep.isDead || (gameBoard[eleVct[i].mY][eleVct[i].mX] == '^');
		pep.isWin = pep.isWin || (pep.mY == 0);
	}
}

void CGAME::dinoUpdate(bool green)
{
	if (!green) { return; }
	int vctSize = dinoVct.size();
	for (int i = 0; i < vctSize; i++)
	{
		if (gameBoard[dinoVct[i].mY][dinoVct[i].mX] != '^')
		{
			gameBoard[dinoVct[i].mY][dinoVct[i].mX] = '.';
		}
		dinoVct[i].Move(GAME_WIDTH, CDINOSAUR::spds);
		pep.isDead = pep.isDead || (gameBoard[dinoVct[i].mY][dinoVct[i].mX] == '^');
		pep.isWin = pep.isWin || (pep.mY == 0);
	}
}


void CGAME::truckUpdate(bool green)
{
	if (!green) 
	{ 
		carIsStop = true;
		return; 
	}
	int vctSize = truckVct.size();
	for (int i = 0; i < vctSize; i++)
	{
		if (gameBoard[truckVct[i].mY][truckVct[i].mX] != '^')
		{
			gameBoard[truckVct[i].mY][truckVct[i].mX] = '.';
		}
		truckVct[i].Move(GAME_WIDTH, CTRUCK::spds);
		pep.isDead = pep.isDead || (gameBoard[truckVct[i].mY][truckVct[i].mX] == '^');
		pep.isWin = pep.isWin || (pep.mY == 0);

	}
}
void CGAME::carUpdate(bool green)
{
	if (!green) 
	{
		carIsStop = true;
		return; 
	}
	
	int vctSize = carVct.size();
	for (int i = 0; i < vctSize; i++)
	{
		if (gameBoard[carVct[i].mY][carVct[i].mX] != '^')
		{
			gameBoard[carVct[i].mY][carVct[i].mX] = '.';
		}
		carVct[i].Move(GAME_WIDTH, CCAR::spds);
		pep.isDead = pep.isDead || (gameBoard[carVct[i].mY][carVct[i].mX] == '^');
		pep.isWin = pep.isWin || (pep.mY == 0);

	}
}

void CGAME::update(int stop,bool redLight)
{	
	system("cls");
	if (redLight)
	{
		this->draw();
		
		std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	}
	else
	{
		
		this->carUpdate(stop % 3);
		this->truckUpdate(stop % 2);
		this->draw();
		
	}
	
}

CGAME::CGAME() : 
	gameBoard(nullptr), carVct(0), truckVct(0), pep(GAME_WIDTH, GAME_HEIGHT - 1),dinoVct(0),eleVct(0), carIsStop(false)
{
	//Crate game board
	gameBoard = new char* [GAME_HEIGHT];
	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		gameBoard[i] = new char[GAME_WIDTH];
		for (int a = 0; a < GAME_WIDTH; a++)
		{
			gameBoard[i][a] = '.';
		}
	}

	for (int theHeight = 0; GAME_HEIGHT - theHeight > 1; )
	{
		//Line of car
		theHeight += 2;
		if (GAME_HEIGHT - theHeight <= 0) { break; }
		for (int a = 0; a < GAME_WIDTH; a += CCAR::dist)
		{
			if (a + CCAR::size < GAME_WIDTH)
			{
				for (int b = 0; b < CCAR::size && (b + CCAR::size) < GAME_WIDTH; b++)
				{
					carVct.push_back(CCAR(a + b, GAME_HEIGHT - theHeight));
				}
			}
		}

		//Line of truck
		theHeight += 1;
		if (GAME_HEIGHT - theHeight <= 0) { break; }
		for (int a = 0; a < GAME_WIDTH; a += CTRUCK::dist)
		{
			if (a + CTRUCK::size < GAME_WIDTH)
			{
				for (int b = 0; b < CTRUCK::size && (b + CTRUCK::size) < GAME_WIDTH; b++)
				{
					truckVct.push_back(CTRUCK(a + b, GAME_HEIGHT - theHeight));
				}
			}
		}

		//Line of ele
		theHeight += 2;
		if (GAME_HEIGHT - theHeight <= 0) { break; }
		for (int a = 0; a < GAME_WIDTH; a += CELEPHANT::dist)
		{
			if (a + CELEPHANT::size < GAME_WIDTH)
			{
				for (int b = 0; b < CELEPHANT::size && (b + CELEPHANT::size) < GAME_WIDTH; b++)
				{
					eleVct.push_back(CELEPHANT(a + b, GAME_HEIGHT - theHeight));
				}
			}
		}

		//Line of dino
		theHeight += 1;
		if (GAME_HEIGHT - theHeight <= 0) { break; }
		for (int a = 0; a < GAME_WIDTH; a += CDINOSAUR::dist)
		{
			if (a + CDINOSAUR::size < GAME_WIDTH)
			{
				for (int b = 0; b < CDINOSAUR::size && (b + CDINOSAUR::size) < GAME_WIDTH; b++)
				{
					dinoVct.push_back(CDINOSAUR(a + b, GAME_HEIGHT - theHeight));
				}
			}
		}
	}
	////Line of car
	//for (int a = 0; a < GAME_WIDTH; a += CCAR::dist)
	//{
	//	if (a + CCAR::size < GAME_WIDTH)
	//	{
	//		for (int b = 0; b < CCAR::size && (b + CCAR::size) < GAME_WIDTH; b++)
	//		{
	//			carVct.push_back(CCAR(a + b, GAME_HEIGHT - 2));
	//		}
	//	}
	//}

	////Line of truck
	//for (int a = 0; a < GAME_WIDTH; a += CTRUCK::dist)
	//{
	//	if (a + CTRUCK::size < GAME_WIDTH)
	//	{
	//		for (int b = 0; b < CTRUCK::size && (b + CTRUCK::size) < GAME_WIDTH; b++)
	//		{
	//			truckVct.push_back(CTRUCK(a + b, GAME_HEIGHT - 3));
	//		}
	//	}
	//}

	////Line of dino
	//for (int a = 0; a < GAME_WIDTH; a += CDINOSAUR::dist)
	//{
	//	if (a + CDINOSAUR::size < GAME_WIDTH)
	//	{
	//		for (int b = 0; b < CDINOSAUR::size && (b + CDINOSAUR::size) < GAME_WIDTH; b++)
	//		{
	//			dinoVct.push_back(CDINOSAUR(a + b, GAME_HEIGHT - 6));
	//		}
	//	}
	//}
	//
	////Line of ele
	//for (int a = 0; a < GAME_WIDTH; a += CELEPHANT::dist)
	//{
	//	if (a + CELEPHANT::size < GAME_WIDTH)
	//	{
	//		for (int b = 0; b < CELEPHANT::size && (b + CELEPHANT::size) < GAME_WIDTH; b++)
	//		{
	//			eleVct.push_back(CELEPHANT(a + b, GAME_HEIGHT - 5));
	//		}
	//	}
	//}

}

void CGAME::save()
{
	std::ofstream saveFile("saveFile.txt");
	saveFile << GAME_HEIGHT << " " << GAME_WIDTH << std::endl;
	saveFile << pep.mX << " " << pep.mY << std::endl;

	saveFile << "CCAR" << std::endl;
	for (int i = 0; i < carVct.size(); i++)
	{
		saveFile << carVct[i].getX() << " " << carVct[i].getY() << std::endl;
	}

}

void CGAME::saveGame(std::string fileName)
{
	std::ofstream file(fileName);
	
	/*if (file.fail())
	{
		std::cout << "Cannot open file at " << fileName << std::endl;
		return;
	}*/
	std::cout << "Saving..." << std::endl; Sleep(1);

	file << GAME_HEIGHT << " " << GAME_WIDTH << std::endl;
	file << pep.mX << " " << pep.mY << std::endl;

	file << "CCAR" << std::endl; // #
	for (int i = 0; i < carVct.size(); i++)
	{
		file <<  carVct[i].getX() << " " << carVct[i].getY() << std::endl;
	}

	file<< "CTRUCK " << std::endl; // **
	for (int i = 0; i < truckVct.size(); i++){
		file << truckVct[i].getX() << " " << truckVct[i].getY() << std::endl;
	}

	file<< "CDINOSAUR "<< std::endl; // >>>>
	for (int i = 0; i < dinoVct.size(); i++) {
		file << dinoVct[i].getX() << " " << dinoVct[i].getY() << std::endl;	
	}
	
	file << "CELEPHANT " << std::endl; // 000
	for (int i = 0; i < eleVct.size(); i++) {
		file << eleVct[i].getX() << " " << eleVct[i].getY() << std::endl;	
	}

	std::cout << "Save Succeessfully!" << std::endl;
	file.close();
}

void CGAME::loadGame(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);
	if (file.fail()) {
		std::cout << "Failed to open this file!" << std::endl;
		return;
	}

	for (int y = 0; y < GAME_HEIGHT; y++)
	{
		for (int x = 0; x < GAME_WIDTH; x++)
		{
			gameBoard[y][x] = '.';
		}
	}
	int hight, width;
	file >> hight >> width;
	//std::cout << hight << " " << width << std::endl;
	file >> pep.mX >> pep.mY;
	std::cout << pep.mX << " " << pep.mY << std::endl;
	//td::cout << pep.mX << " " << pep.mY << std::endl;
	std::string car;
	file >> car; // junk car
	for (int i = 0; i < carVct.size(); i++)
	{
		file >> carVct[i].mX >> carVct[i].mY;
	}

	std::string truck;
	file >> truck; // junk truck
	for (int i = 0; i < truckVct.size(); i++) {
	file >> truckVct[i].mX >> truckVct[i].mY;
	}

	std::string dinosaur;
	file >> dinosaur; // junk dinosaur
	for (int i = 0; i < dinoVct.size(); i++) {
		file >> dinoVct[i].mX >> dinoVct[i].mY;
	}

	std::string elepants;
	file >> elepants; // junk elepants
	for (int i = 0; i < eleVct.size(); i++) {
	file >> eleVct[i].mX >> eleVct[i].mY;
	}
	file.close();
	std::cout << "Load successfull" << std::endl;
}