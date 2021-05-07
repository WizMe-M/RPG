#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include "Helper.h"
using namespace std;

//Класс предмета
class Item {
public:
	string Name;
	int Price;
	int Quantity;
	Item() {}
	Item(string name, int price, int quantity) {
		Name = name;
		Price = price;
		Quantity = quantity;
	}
};

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

//Класс магазина в таверне
class Shop
{
public:
	vector <Item> Items;
	vector <Companion> Companions;
};

//Персонаж игрока
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
	bool haveCompanion = true;
	int SpecialAbilityCooldown = 0;
	//Базовый конструктор класса
	Player() {
		cout << " Введите имя персонажа: ";
		cin >> Name;
		cout << "\n Выберите класс персонажа: \n\n";

		string ClassesDescription =
			" 1. Воин – имеет большое количество здоровья и повышенную защиту, хорошие показатели атаки, но полностью отсутствуют магические силы.\n\n"
			" 2. Лучник – высокий урон, средние показатели здоровья, защиты и магической силы, крайне скудные запасы маны.\n\n"
			" 3. Маг – низкие показатели здоровья, ужасные показатели урона в рукопашном бою и защиты, однако класс"
			" имеет высокие показатели магической силы и обладает больши запасом маны.\n\n";
		cout << ClassesDescription << " \n";


		int Choice = 0;

		cout << " 1 - выбрать класс 'Воин'.\n";
		cout << " 2 - выбрать класс 'Лучник'.\n";
		cout << " 3 - выбрать класс 'Маг'.\n";
		cout << "\n\t<-- Выбор класса --> ";
		
		switch (ChoiceCheck(3))
		{
		case 1:
		{
			//базовые статы
			Class = "Воин";
			TotalHP = 120;
			MinDamage = 15;
			Damage = 20;
			Defence = 35;
			MagicPower = 0;
			Mana = 0;

			//статы за лвл
			HPperLVL = 25;
			DMGperLVL = 9;
			DEFperLVL = 10;
			MPperLVL = 0;
			MANAperLVL = 0;
			break;
		}
		case 2:
		{
			//базовые статы
			Class = "Лучник";
			TotalHP = 90;
			MinDamage = 25;
			Damage = 35;
			Defence = 5;
			MagicPower = 0;
			Mana = 25;

			//статы за лвл
			HPperLVL = 14;
			DMGperLVL = 13;
			DEFperLVL = 4;
			MPperLVL = 5;
			MANAperLVL = 10;
			break;
		}
		case 3:
		{
			//базовые статы
			Class = "Маг";
			TotalHP = 80;
			MinDamage = 5;
			Damage = 10;
			Defence = 5;
			MagicPower = 20;
			Mana = 100;

			//статы за лвл
			HPperLVL = 5;
			DMGperLVL = 5;
			DEFperLVL = 0;
			MPperLVL = 15;
			MANAperLVL = 30;
			break;
		}
		}
		HP = TotalHP;
		MaxMana = Mana;
		Gold = 100;
		InventoryMaxCapacity = 10;
		Inventory.push_back(Item("Эстус", 0, 3));

		system("cls");
		cout << "\n\n\tСоздаём персонажа";
		for (int i = 0; i < 3; i++)
		{
			Sleep(600);
			cout << ".";
		}
		Sleep(100);

		system("cls");
		cout << " " << Name << " характеристики: \n";
		cout << " Класс: " << Class << "\n";
		cout << " Уровень: " << Level << "\n";
		cout << " Опыт: " << Experience << " / " << MaxExp << "\n";
		cout << " Здоровье: " << HP << " / " << TotalHP << "\n";
		cout << " Урон: " << (Damage + MinDamage) / 2 << "\n";
		cout << " Защита: " << Defence << "\n";
		cout << " Магическая сила: " << MagicPower << "\n";
		cout << " Мана: " << Mana << " / " << MaxMana << "\n";
		cout << " Золото: " << Gold << "\n";
		cout << " \n";
		cout << " Нажмите любую кнопку, чтобы продолжить" << endl;
		GetKey();
		system("cls");
	}
};
Player create();