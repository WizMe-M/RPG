#pragma once
#include <string>
#include <windows.h>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Combat.h"

//���� �����������
const string Races[8]{ "�����", "�������", "��������", "������", "�����", "������", "�����", "�����" };
//������ ������
const string SpecialAbilities[5]{ "�����", "�������� �������", "����������� ������", "����������� �����", "�������������� ��������" };


//���������, ����������� ������ ������
class Enemy
{
public:
	string Name;
	//id ����
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

//���� ���������� ����� � ����������� ��������
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

//����� ������� �� ��������
class Reward
{
public:
	int Gold;
	int Experience;
};

//����� �����, ���� ������������ �����
class NewDungeon {
public:
	string DungType;
	double DungDifficulty;
	int DungFloorsCount;
	int DungCurFloor;
	double isDungBoss;
	Reward DungReward;
};



//ChooseRandomGloor. �������������� ������ ������� �� ����  
void GiveReward(Player& player, Reward reward);

//GiveReward. ���� ������ ���������� �����, ����������� �������� ��������� ������
void LevelUp(Player& player);

//Combat. ������� ��������� ���� �� �������
int DecreaseDmgByDef(int damage, int defence);

//Combat. ������������ ������� �� ������ �����������
Reward CalculateReward(double difficulty, vector<Enemy>& deadEnemies);

//Combat. ������������ ������� �� �����
Reward CalculateReward(double difficulty, DungeonBoss boss);

//Helper. ������ �� ����� (������������) �� ������� ����� (�� ������������)
int Random(int min, int max);

//Combat. ��������� "������" ����������, ������������� ��������� ��� ��������� ��� �������, ��������� ���������� "�����" �����������
void CheckDeath(vector<Enemy>& Enemies, vector<Enemy>& DeadEnemies, int id);

//Combat. ��������� ��� �� ����� � ���� ���, ������� ���������� � ��������� ����
void CheckDeath(Player player);

//Combat. ��������� ��� �� ����� � ���� ���, ������� ���������� � ��������� ����
void CheckDeath(DungeonBoss& boss);

//Combat. ��������� ��� �� ��������� ������
void CheckDeath(Player& p, Companion& c);

//Helper. �������� ����������� ���� ����� � ��������� �� 1 �� �������������, ���� �� ����� ������� ���������� ��������
int ChoiceCheck(int max);

//Helper. ��������� ����� �� ���������� ������ ��������
void CheckGreaterPoints(int& points, int max_points);

//Hepler. ���������������� ��������� ���� �� ����� ������ �������
void GetKey();

//Helper. ��������� ���������� �� ������ �� �������
bool CheckMoney(int gold, int price);


//������� ���� ����, ���� ����� ��������� ������������ ����� ������ � ����
void MainMenu(Player& player, Companion& companion, Shop& shop);

//MainMenu. ����� ���� ������ �������� � �������
void Tavern(Player& player, Companion& companion, Shop& shop);

//Tavern. �����-������� ���������
void BuyItems(Player& player, Shop& shop);

//Tavern. ���� ����������� � �����
void BuyMercenaries(Player& player, Companion& companion, Shop& shop);

//MainMenu. ����� � ���� (����� ��������� � ��������� ����� ������)
void Dungeon(Player& player, Companion& �ompanion);

//MainMenu. ����� ������������� ������
void HeroStats(Player& player);

//MainMenu. ����� ������ ������
void HeroArmy(Player& player, Companion& �ompanion);

//Tavern. �������������� �������� � ���� ������
void RestInTavern(Player& player, Companion& companion);

//Helper. �������, ����������� � ���� ������ �����
int InputStringToInt();

//Dungeon. ����� ���������� ����� ����� (������� �� ���� �������)
void ChooseRandomFloor(Player& player, Companion& companion, NewDungeon& dungeon);

//Dungeon. ����� ��������� �� ��������� ����� �����
void ChooseRandomBoss(Player& player, Companion& companion, NewDungeon& dngeon);