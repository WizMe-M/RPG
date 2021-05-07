#pragma once
#include <string>
#include <windows.h>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Combat.h"

//Расы противников
const string Races[8]{ "Полый", "Человек", "Гуманоид", "Нежить", "Демон", "Дракон", "Голем", "Зверь" };
//Абилки боссов
const string SpecialAbilities[5]{ "Таран", "Огненное дыхание", "Зачарование оружия", "Высасывание жизни", "Восстановление здоровья" };

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

//Противник, сражающийся против игрока
class Enemy
{
public:
	string Name;
	//id расы
	int RaceType;
	string Race;
	int HP;
	int BaseHP;
	int Damage;
	int Level;
	bool isDead;
	Enemy(string name, int raceType, int fullhp, int damage, int level) {
		Name = name;
		RaceType = raceType;
		Race = Races[RaceType];
		BaseHP = fullhp;
		HP = fullhp;
		Damage = damage;
		Level = level;
		isDead = false;
	}
};

//Босс последнего этажа с уникальными умениями
class DungeonBoss {
public:
	string Name;
	int RaceType;
	string Race;
	int HP;
	int BaseHP;
	int Damage;
	int Defence;
	int Level;
	int Gold;
	int Exp;
	int EvasionChance;
	bool isDead;
	int IdSpecialAbility;
	int SpecialAbilityCooldown;
	int Max_SpecialAbilityCooldown;
	DungeonBoss(string name, int raceType, int fullhp, int damage, int defence, int level, int gold, int exp, int evasion, int abilityId, int max_cd) {
		Name = name;
		RaceType = raceType;
		Race = Races[RaceType];
		BaseHP = fullhp;
		HP = fullhp;
		Damage = damage;
		Defence = defence;
		Level = level;
		Gold = gold;
		Exp = exp;
		EvasionChance = evasion;
		IdSpecialAbility = abilityId;
		Max_SpecialAbilityCooldown = max_cd;
		SpecialAbilityCooldown = 0;
		isDead = false;
	}
};

//Класс цели для атаки противника
class Target {
public:
	string Name;
	string Type;
	int HP;
	int Defence;
	Target(string name, string type, int hp, int defence) {
		Name = name;
		Type = type;
		HP = hp;
		Defence = defence;
	}
};

//Класс предмета
class Item {
public:
	string Name;
	int Price;
	int Quantity;
	Item(){}
	Item(string name, int price, int quantity) {
		Name = name;
		Price = price;
		Quantity = quantity;
	}
};

//Класс магазина в таверне
class Shop
{
public:
	vector <Item> Items;
	vector <Companion> Companions;
};

//Класс награды за убийство
class Reward
{
public:
	int Gold;
	int Experience;
};

//Класс данжа, куда отправляется игрок
class NewDungeon {
public:
	string DungType;
	double DungDifficulty;
	int DungFloorsCount;
	int DungCurFloor;
	double isDungBoss;
	Reward DungReward;
};






//ChooseRandomGloor. Приплюсовывает игроку награду за этаж  
void GiveReward(Player& player, Reward reward);

//GiveReward. Если игроку достаточно опыта, запускается алгоритм повышения уровня
void LevelUp(Player& player);

//Combat. Срезает наносимый урон по формуле
int DecreaseDmgByDef(int damage, int defence);

//Combat. Подсчитывает награду за убитых противников
Reward CalculateReward(double difficulty, vector<Enemy>& deadEnemies);

//Combat. Подсчитывает награду за босса
Reward CalculateReward(double difficulty, DungeonBoss boss);

//Helper. Рандом от числа (включительно) до другого числа (не включительно)
int Random(int min, int max);

//Combat. Проверяет "смерть" противника, устанавливает некоторые его параметры как мёртвого, уменьшает количество "живых" противников
void CheckDeath(vector<Enemy>& Enemies, vector<Enemy>& DeadEnemies, int id);

//Combat. Проверяет жив ли игрок и если нет, выводит статистику и завершает игру
void CheckDeath(Player player);

//Combat. Проверяет жив ли игрок и если нет, выводит статистику и завершает игру
void CheckDeath(DungeonBoss& boss);

//Combat. Проверяет жив ли компаньон игрока
void CheckDeath(Player& p, Companion& c);

//Helper. Циклично запрашивает ввод числа в диапазоне от 1 до максимального, пока не будет введено корректное значение
int ChoiceCheck(int max);

//Helper. Проверяет число на превышение некого значения
void CheckGreaterPoints(int& points, int max_points);

//Hepler. Приостанавливает программу пока не будет нажата клавиша
void GetKey();

//Helper. Проверяет достаточно ли золота на покупку
bool CheckMoney(int gold, int price);


//Главное меню игры, куда игрок постоянно возвращается после похода в Данж
void MainMenu(Player& player, Companion& companion, Shop& shop);

//MainMenu. Вывод меню выбора действий в таверне
void Tavern(Player& player, Companion& companion, Shop& shop);

//Tavern. Купля-продажа предметов
void BuyItems(Player& player, Shop& shop);

//Tavern. Найм компаньонов в битву
void BuyMercenaries(Player& player, Companion& companion, Shop& shop);

//MainMenu. Поход в данж (выбор сложности и цикличный вызов этажей)
void Dungeon(Player& player, Companion& сompanion);

//MainMenu. Вывод характеристик игрока
void HeroStats(Player& player);

//MainMenu. Вывод отряда игрока
void HeroArmy(Player& player, Companion& сompanion);

//Tavern. Восстановление здоровья и маны игрока
void RestInTavern(Player& player, Companion& companion);

//Helper. Функция, принимающая в ввод только цифры
int InputStringToInt();

//Dungeon. Выбор случайного этажа данжа (события из пула событий)
void ChooseRandomFloor(Player& player, Companion& companion, NewDungeon& dungeon);

//Dungeon. Выбор минибосса на последнем этаже данжа
void ChooseRandomBoss(Player& player, Companion& companion, NewDungeon& dngeon);