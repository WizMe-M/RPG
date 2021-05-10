#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;

//Helper. �������� ����������� ���� ����� � ��������� �� 1 �� �������������, ���� �� ����� ������� ���������� ��������
int ChoiceCheck(int max);
//ChoiceCheck. ����, ���� �� ����� 
int InputStringToInt();
//Hepler. ���������������� ��������� ���� �� ����� ������ �������
void GetKey();

//�������� ������
class Player
{
public:
	string Name;
	string Class;
	int Level = 1;
	int MaxExp = 50;
	int Experience = 0;
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