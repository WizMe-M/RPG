#pragma once
#include <string>
#include <windows.h>
#include <iostream>

using std::string;

class Player
{
public:
	string PlayerName;
	string PlayerClass;
	double PlayerTotalHP;
	double PlayerHP;
	double PlayerLevel;
	double PlayerDamage;
	double PlayerMinDamage;
	double PlayerDefence;
	double PlayerKnowledge;
	double PlayerMagicPower;
	int PlayerMana;
	int PlayerGold;

	string Inventory[15];
	int CurrentInventoryCapacity;
	int InventoryMaxCapacity;
};

Player create();

