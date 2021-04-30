#include <iostream>
#include <string>
#include <ctime>
#include "Windows.h"
#include "Player.h"
#include "Helper.h"

using namespace std;

int main()
{
	COORD coord;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);

    srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    Player player = create();
    int Сhoice = 0;

    system("cls");

	Unit newUnit;
	newUnit.UnitTotalHP[0] = 120;
	newUnit.UntiHP[1] = player.PlayerLevel;
	newUnit.UnitTotalHP[1] = player.PlayerTotalHP;

	newUnit.UnitName[0] = " Лаврентий";
	newUnit.UnitName[1] = player.PlayerName;
	newUnit.UntiDamage[0] = 20.0;
	newUnit.UntiDamage[1] = player.PlayerDamage;

	newUnit.UntiHP[0] = 120;
	newUnit.UntiHP[1] = player.PlayerLevel;
	newUnit.UnitClass[0] = " Воин";
	newUnit.UnitClass[1] = player.PlayerClass;

	Squad newSquad;
	newSquad.SquadTotalNumber = 2;
	newSquad.SquadQuantity = 2;
	newSquad.SquadNames[0] = " Лаврентий";
	newSquad.SquadNames[1] = player.PlayerName;

	Enemy newEnemy;
	newEnemy.LastQuantity = 3;
	newEnemy.EnemyQuantity = 3;
	int k = 1;

	for (int i = 0; i < newEnemy.EnemyQuantity; i++) 
	{
		string names = " Стражник(" + std::to_string(k) + ")";
		newEnemy.EnemyName[i] = names;
		newEnemy.EnemyClass[i] = " Человек";
		newEnemy.EnemyHP[i] = 10.0;
		newEnemy.EnemyDamage[i] = 5.0;
		k++;
	}

	Enemy TheThing;
	TheThing.LastQuantity = 1;
	TheThing.EnemyQuantity = 1;
	TheThing.EnemyName[0] = " Демон-странник";
	TheThing.EnemyClass[0] = " Демон";
	TheThing.EnemyHP[0] = 120;
	TheThing.EnemyDamage[0] = 10;

	Shop newShop;
	newShop.BuyItemName[0] = " Эстус";
	newShop.BuyItemName[1] = " Секира";
	newShop.BuyItemName[2] = " Кольцо знания";
	newShop.BuyItemName[3] = " Зелье скрытности";
	newShop.BuyItemName[4] = " Броня полого солдата";

	newShop.ItemQuantity[0] = 15;
	newShop.ItemQuantity[1] = 1;
	newShop.ItemQuantity[2] = 2;
	newShop.ItemQuantity[3] = 1;
	newShop.ItemQuantity[4] = 1;

	newShop.ItemPrice[0] = 300;
	newShop.ItemPrice[1] = 1500;
	newShop.ItemPrice[2] = 1000;
	newShop.ItemPrice[3] = 1500;
	newShop.ItemPrice[4] = 5000;

	MainMenu(player, newUnit, newSquad, newShop);
}
