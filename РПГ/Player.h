#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;

//Helper. Циклично запрашивает ввод числа в диапазоне от 1 до максимального, пока не будет введено корректное значение
int ChoiceCheck(int max);
//ChoiceCheck. Ввод, пока не число 
int InputStringToInt();
//Hepler. Приостанавливает программу пока не будет нажата клавиша
void GetKey();

//Персонаж игрока
class Player
{
public:
	string Name;
	string Class;
	int Level;
	int MaxExp;
	int Experience;
	int TotalHP;
	int HP;
	int Damage;
	int MinDamage;
	int Defence;
	int MagicPower;
	int Mana;
	int MaxMana;
	int Gold;
	vector <Item> Inventory;
	int InventoryMaxCapacity;

	int HPperLVL;
	int DMGperLVL;
	int DEFperLVL;
	int MPperLVL;
	int MANAperLVL;
	bool haveCompanion;
	int SpecialAbilityCooldown;
	int EnemiesKilledCount;
};
Player create();