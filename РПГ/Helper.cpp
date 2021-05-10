#pragma once
#include <conio.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <cstdio>
#include <iostream>
#include "Helper.h"

using namespace std;



/*Здесь находятся системные функции, упрощающие написание кода*/

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

	cout << "\n Нажмите любую клавишу, чтобы принять награду.";
	GetKey();
	while (player.Experience >= player.MaxExp)
		LevelUp(player);
}
void LevelUp(Player& player) {

	system("cls");
	cout << "\n Сегодня вы научились лучше обращаться с оружием... \n";
	cout << "\n\t\tУРОВЕНЬ ПОВЫШЕН! \n";
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

	cout << "\n Ваши характеристики увеличены: \n";
	cout << " Класс: " << player.Class << "\n";
	cout << " Уровень: " << player.Level << "\n";
	cout << " Опыт: " << player.Experience << " / " << player.MaxExp << "\n";
	cout << " Здоровье: " << player.HP << " / " << player.TotalHP << "\n";
	cout << " Урон: " << (player.Damage + player.MinDamage) / 2 << "\n";
	cout << " Защита: " << player.Defence << "\n";
	cout << " Магическая сила: " << player.MagicPower << "\n";
	cout << " Мана: " << player.Mana << " / " << player.MaxMana << "\n";
	if (player.InventoryMaxCapacity != 25) {
		player.InventoryMaxCapacity++;
		cout << " Объём вашего рюкзака увеличен на 1. Текущая его вместимость: "
			<< player.Inventory.size()<< " / " << player.InventoryMaxCapacity << "\n";
	}
	cout << " \n";

	cout << "\n Выберите какую характеристику вы хотите дополнительно увеличить: ";
	cout << "\n 1.Здоровье \n 2.Урон \n 3.Защита \n 4.Магическая сила \n 5.Мана \n";
	int up;
	switch (ChoiceCheck(5)) {
	case 1:
		up = player.HPperLVL + 10;
		cout << "\n Здоровье увеличено на " << up << "\n";
		player.TotalHP += up;
		player.HP = player.TotalHP;
		break;
	case 2:
		up = player.DMGperLVL * 1.5;
		cout << "\n Урон увеличен на " << up << "\n";
		player.Damage += up;
		player.MinDamage += up;
		break;
	case 3:
		up = player.DEFperLVL * 2 + 5;
		cout << "\n Защита увеличена на " << up << "\n";
		player.Defence += up;
		break;
	case 4:
		up = player.MPperLVL + 5;
		cout << "\n Магическая сила увеличена на " << up << "\n";
		player.MagicPower += up;
		break;
	case 5:
		up = player.MaxMana * 2;
		cout << "\n Мана увеличена на " << up << "\n";
		player.MaxMana += up;
		player.Mana = player.MaxMana;
		break;
	}

	//каждый четный уровень можно немного ускорить развитие какой-то статы
	if (player.Level % 2 == 0)
	{
		cout << "\n В этот раз вы узнали немного больше, чем обычно!";
		cout << "\n Теперь вы развиваетесь быстрее.";
		cout << "\n Выберите характеристику, ускорить развитие которой вы хотите: ";
		cout << "\n 1.Здоровье \n 2.Урон \n 3.Защита \n 4.Магическая сила \n 5.Мана \n";

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
		cout << "\n\n Боги милостивы. Да будет так!";
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
void CheckDeath(vector<Enemy>& Enemies, vector<Enemy>& DeadEnemies, int id)
{
	if (Enemies.at(id).HP <= 0)
	{
		DeadEnemies.push_back(Enemies.at(id));
		Enemies.erase(Enemies.begin() + id);
	}
}
void CheckDeath(DungeonBoss& boss)
{
	if (boss.HP <= 0)
	{
		boss.Name += " (МЁРТВ)";
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

		cout << "\tВаша статистика за этот забег:\n";
		cout << "\t" << player.Name << " характеристики: \n";
		cout << "\tКласс: " << player.Class << "\n";
		cout << "\tУровень: " << player.Level << "\n";
		cout << "\tОпыт: " << player.Experience << " / " << player.MaxExp << "\n";
		cout << "\tЗдоровье: " << player.HP << " / " << player.TotalHP << "\n";
		cout << "\tУрон: " << (player.Damage + player.MinDamage) / 2 << "\n";
		cout << "\tЗащита: " << player.Defence << "\n";
		cout << "\tМагическая сила: " << player.MagicPower << "\n";
		cout << "\tМана: " << player.Mana << " / " << player.MaxMana << "\n";
		cout << "\tЗолото: " << player.Gold << "\n";
		cout << "\n";
		cout << "\n\n\n" << endl;
		cout << "\tНажмите любую кнопку " << endl;
		GetKey();
		exit(0);
	}
}
void CheckDeath(Player& p, Companion& c) {
	Sleep(1000);
	if (c.HP <= 0) {
		p.haveCompanion = false;
		c.Name = "Мёртв";
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

