#include <iostream>
#include <string>
#include <ctime>
#include "Helper.h"

using namespace std;

int main()
{
	COORD coord;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);
    srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    Player player;

	Companion companion("Лаврентий", "Воин", 160, 120, 35, 10, 20, 40, true, 0);

	Shop shop;
	shop.Companions.push_back(Companion("Лоскутик", "Воин", 200, 200, 49, 30, 30, 60, false, 500));
	shop.Items.push_back(Item("Эстус", 100, 50));


	MainMenu(player, companion, shop);
}