#pragma once
#include <conio.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <cstdio>
#include <iostream>
#include "Helper.h"

using namespace std;



/*����� ��������� ��������� �������, ���������� ��������� ����*/

Reward CalculateReward(double difficulty, vector<Enemy>& deadEnemies) {
	Reward r;
	r.Gold = 0;
	r.Experience = 0;

	int classtype = 1;
	for (int i = 0; i < deadEnemies.size(); i++)
	{
		r.Gold += deadEnemies.at(i).Level * 10;
		r.Experience += deadEnemies.at(i).Level * 4;

		switch (deadEnemies.at(i).RaceType) {
		case 0:
			r.Gold *= 1.2;
			break;
		case 1:
			r.Experience *= 1.2;
			r.Gold *= 2;
			break;
		case 2:
			r.Experience *= 1.1;
			r.Gold *= 1.2;
			break;
		case 3:
			r.Experience *= 1.3;
			break;
		case 4:
			r.Experience *= 1.4;
			r.Gold *= 1.1;
			break;
		case 5:
			r.Experience *= 2;
			r.Gold *= 2;
			break;
		case 6:
			r.Experience *= 1.1;
			r.Gold *= 0.9;
			break;
		}

	}
	r.Experience *= difficulty;
	r.Gold *= difficulty;

	vector<Enemy>().swap(deadEnemies);

	return r;
}
Reward CalculateReward(double difficulty, DungeonBoss boss) {
	Reward r;
	r.Gold = boss.Gold * difficulty;
	r.Experience = boss.Exp * difficulty;

	switch (boss.RaceType) {
	case 0:
		r.Gold *= 1.2;
		break;
	case 1:
		r.Experience *= 1.2;
		r.Gold *= 2;
		break;
	case 2:
		r.Experience *= 1.1;
		r.Gold *= 1.2;
		break;
	case 3:
		r.Experience *= 1.3;
		break;
	case 4:
		r.Experience *= 1.4;
		r.Gold *= 1.1;
		break;
	case 5:
		r.Experience *= 2;
		r.Gold *= 2;
		break;
	case 6:
		r.Experience *= 1.1;
		r.Gold *= 0.9;
		break;
	}
	return r;
}
void GiveReward(Player& player, Reward reward) {
	player.Experience += reward.Experience;
	player.Gold += reward.Gold;

	cout << "\n ������� ����� �������, ����� ������� �������.";
	GetKey();
	while (player.Experience >= player.MaxExp)
		LevelUp(player);
}
void LevelUp(Player& player) {

	system("cls");
	cout << "\n ������� �� ��������� ����� ���������� � �������... \n";
	cout << "\n\t\t������� �������! \n";
	player.Level++;
	player.Experience -= player.MaxExp;
	player.MaxExp += 2;
	player.TotalHP += player.HPperLVL;
	player.HP = player.TotalHP;
	player.Damage += player.DMGperLVL;
	player.MinDamage += player.DMGperLVL;
	player.Defence += player.DEFperLVL;
	player.MagicPower += player.MPperLVL;
	player.MaxMana += player.MANAperLVL;
	player.Mana = player.MaxMana;

	cout << "\n ���� �������������� ���������: \n";
	cout << " �����: " << player.Class << "\n";
	cout << " �������: " << player.Level << "\n";
	cout << " ����: " << player.Experience << " / " << player.MaxExp << "\n";
	cout << " ��������: " << player.HP << " / " << player.TotalHP << "\n";
	cout << " ����: " << (player.Damage + player.MinDamage) / 2 << "\n";
	cout << " ������: " << player.Defence << "\n";
	cout << " ���������� ����: " << player.MagicPower << "\n";
	cout << " ����: " << player.Mana << " / " << player.MaxMana << "\n";
	if (player.InventoryMaxCapacity != 25) {
		player.InventoryMaxCapacity++;
		cout << " ����� ������ ������� �������� �� 1. ������� ��� �����������: "
			<< player.Inventory.size()<< " / " << player.InventoryMaxCapacity << "\n";
	}
	cout << " \n";

	cout << "\n �������� ����� �������������� �� ������ ������������� ���������: ";
	cout << "\n 1.�������� \n 2.���� \n 3.������ \n 4.���������� ���� \n 5.���� \n";
	int up;
	switch (ChoiceCheck(5)) {
	case 1:
		up = player.HPperLVL + 10;
		cout << "\n �������� ��������� �� " << up << "\n";
		player.TotalHP += up;
		player.HP = player.TotalHP;
		break;
	case 2:
		up = player.DMGperLVL * 1.5;
		cout << "\n ���� �������� �� " << up << "\n";
		player.Damage += up;
		player.MinDamage += up;
		break;
	case 3:
		up = player.DEFperLVL * 2 + 5;
		cout << "\n ������ ��������� �� " << up << "\n";
		player.Defence += up;
		break;
	case 4:
		up = player.MPperLVL + 5;
		cout << "\n ���������� ���� ��������� �� " << up << "\n";
		player.MagicPower += up;
		break;
	case 5:
		up = player.MaxMana * 2;
		cout << "\n ���� ��������� �� " << up << "\n";
		player.MaxMana += up;
		player.Mana = player.MaxMana;
		break;
	}

	//������ ������ ������� ����� ������� �������� �������� �����-�� �����
	if (player.Level % 2 == 0)
	{
		cout << "\n � ���� ��� �� ������ ������� ������, ��� ������!";
		cout << "\n ������ �� ������������ �������.";
		cout << "\n �������� ��������������, �������� �������� ������� �� ������: ";
		cout << "\n 1.�������� \n 2.���� \n 3.������ \n 4.���������� ���� \n 5.���� \n";

		switch (ChoiceCheck(5)) {
		case 1:
			player.HPperLVL = (player.HPperLVL * 1.3) + 2;
			break;
		case 2:
			player.DMGperLVL *= 1.15;
			break;
		case 3:
			player.DEFperLVL = (player.DEFperLVL * 1.2) + 2;
			break;
		case 4:
			player.MPperLVL + 2;
			break;
		case 5:
			player.MaxMana += 3;
			break;
		}
		cout << "\n\n ���� ���������. �� ����� ���!";
		Sleep(3000);
	}

}
int DecreaseDmgByDef(int damage, int defence) {
	int decreasePercent = defence / 7 + 5;
	if (decreasePercent > 70)
		decreasePercent = 70;
	damage -= damage / decreasePercent;
	return damage;
}
int Random(int min, int max)
{
	srand(time(NULL));
	if (min > 0)
	{
		return min + rand() % (max - min);
	}
	else
	{
		return min + rand() % (abs(min) + max);
	}
}
bool CheckDeath(vector<Enemy>& Enemies, vector<Enemy>& DeadEnemies, int id)
{
	if (Enemies.at(id).HP <= 0)
	{
		DeadEnemies.push_back(Enemies.at(id));
		Enemies.erase(Enemies.begin() + id);
	}
}
bool CheckDeath(DungeonBoss& boss)
{
	if (boss.HP <= 0)
	{
		boss.Name += " (̨���)";
		boss.isDead = true;
	}
}
void CheckDeath(Player player) {
	Sleep(1000);
	if (player.HP <= 0) {

		string path = "D:\\saves\\" + player.Name + ".txt";
		remove(path.c_str());

		system("cls");
		cout << "\n\n\n \t\t YOU DIED \n\n";

		cout << "\t���� ���������� �� ���� �����:\n";
		cout << "\t" << player.Name << " ��������������: \n";
		cout << "\t�����: " << player.Class << "\n";
		cout << "\t�������: " << player.Level << "\n";
		cout << "\t����: " << player.Experience << " / " << player.MaxExp << "\n";
		cout << "\t��������: " << player.HP << " / " << player.TotalHP << "\n";
		cout << "\t����: " << (player.Damage + player.MinDamage) / 2 << "\n";
		cout << "\t������: " << player.Defence << "\n";
		cout << "\t���������� ����: " << player.MagicPower << "\n";
		cout << "\t����: " << player.Mana << " / " << player.MaxMana << "\n";
		cout << "\t������: " << player.Gold << "\n";
		cout << "\t���������� ������ �����������: " << player.EnemiesKilledCount << "\n";

		cout << "\n";
		cout << "\n\n\n" << endl;
		cout << "\t������� ����� ������ " << endl;
		GetKey();
		exit(0);
	}
}
void CheckDeath(Player& p, Companion& c) {
	Sleep(1000);
	if (c.HP <= 0) {
		p.haveCompanion = false;
		c.Name = "̸���";
		c.HP = 0;
	}
}
void CheckGreaterPoints(int& points, int max_points) {
	if (points > max_points)
		points = max_points;
}
bool CheckMoney(int Gold, int price)
{
	if (Gold >= price)
		return true;
	else
		return false;
}

