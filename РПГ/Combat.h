#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "Player.h"

using namespace std;
using std::string;

class Squad
{
public:
	int SquadQuantity;
	int SquadTotalNumber;
	string SquadNames[5];
};

class Enemy
{
public:
	int EnemyQuantity;
	int LastQuantity;
	string EnemyName[10];
	string EnemyClass[10];
	double EnemyHP[10];
	double EnemyDamage[10];
};

class Unit
{
public:
	string UnitName[5];
	string UnitClass[5];
	double UntiHP[5];
	double UnitTotalHP[5];
	double UntiDamage[5];
};

class Reward
{
public:
	int Gold;
};

int Combat(Squad& newSquad, Unit& newUnit, Enemy& newEnemy, Player& player);

