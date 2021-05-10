#pragma once
#include <string>
using namespace std;

//Персонаж-компаньон для игрока, который не имеет прокачки и сражается в бою с отдельной от игрока логикой
class Companion {
public:
	string Name;
	string Class;
	int TotalHP;
	int HP;
	int Defence;
	int CurAttackCount;
	int MaxAttackCount;
	int Damage;
	bool isSold;
	int Price;

	Companion(string name, string cclass, int fullhp, int hp, int def, int attcount, int maxattcount, int dmg, bool sold, int price) {
		Name = name;
		Class = cclass;
		TotalHP = fullhp;
		HP = hp;
		Defence = def;
		CurAttackCount = attcount;
		MaxAttackCount = maxattcount;
		Damage = dmg;
		isSold = sold;
		Price = price;
	}
};

