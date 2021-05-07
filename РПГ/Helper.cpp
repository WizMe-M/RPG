#include "Helper.h"
#include "Player.h"
#include "Combat.h"
#include "Windows.h"
#include <conio.h>
#include <ctime>
#include <iostream>
#include <vector>
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
			<< player.CurrentInventoryCapacity << " / " << player.InventoryMaxCapacity << "\n";
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
int ChoiceCheck(int max)
{
	int Choice = 0;
	while (Choice > max || Choice <= 0)
	{
		cout << "\n �����: ";
		Choice = InputStringToInt();
	}
	return Choice;
}
int InputStringToInt() {
	string input;
	do {
		getline(cin, input);
	} while (!(input.find_first_not_of("0123456789") && input.length() == 1));
	return stoi(input);
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
		boss.Name += " (̨���)";
		boss.isDead = true;
	}
}
void CheckDeath(Player player) {
	Sleep(1000);
	if (player.HP <= 0) {
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
void GetKey() {
	int i = _getch();
}
bool CheckMoney(int Gold, int price)
{
	if (Gold >= price)
		return true;
	else
		return false;
}

/*����� ��������� �������, ����������� ��� ����������� ��������� ������ ���������*/

void MainMenu(Player& player, Companion& �ompanion, Shop& shop)
{
	while (true)
	{
		system("cls");
		cout << "\n\t<-- ������� ���� -->\n";
		cout << "\n " << player.Name << ", �������� ��������: \n";
		cout << " 1. �������� �������.\n";
		cout << " 2. ����������� ����������.\n";
		cout << " 3. �������������� �����\n";
		cout << " 4. ����� �����.\n";
		switch (ChoiceCheck(4))
		{
		case 1:
			Tavern(player, �ompanion, shop);
			break;
		case 2:
			Dungeon(player, �ompanion);
			break;
		case 3:
			HeroStats(player);
			break;
		case 4:
			HeroArmy(player, �ompanion);
			break;
		}
	}
}
void Tavern(Player& player, Companion& companion, Shop& shop)
{
	while (true)
	{
		system("cls");
		cout << "\n\t<-- ������� -->\n";
		cout << " ������ �������: ����� ���������� � ��� �������, �����! ����� ��� ���� �������� ����, ��� � ����������.\n\n";
		cout << " 1. ��������� ����������.\n";
		cout << " 2. ������ �����.\n";
		cout << " 3. ���������. ��������� ��������������� �������� � ����.\n";
		cout << " 4. ��������� � ������� ����\n";
		switch (ChoiceCheck(4))
		{
		case 1: BuyItems(player, shop);
			break;
		case 2:	BuyMercenaries(player, companion, shop);
			break;
		case 3: RestInTavern(player, companion);
			break;
		case 4: return; break;
		}
	}
}
void BuyItems(Player& player, Shop& shop)
{
	system("cls");
	cout << "\n\t<-- �������/������� ���������� -->\n";
	cout << " 1. ������ ����������.\n";
	cout << " 2. ������� ����������. \n";
	bool isBuying = true;
	switch (ChoiceCheck(2))
	{
	case 1:
		system("cls");
		cout << "\n ��������: ������������ � ����� ����������.\n";
		while (true)
		{
			cout << "\n\t<-- ����� ���������� ��������� -->\n";
			cout << " ��������: ���, ��� �����������:\n";
			for (int i = 0; i < 5; i++)
			{
				cout << " " << to_string(i) + ".  �����: " << shop.Items.at(i).Name
					<< " | ����������: " << shop.Items.at(i).Quantity
					<< " | ����: " << shop.Items.at(i).Price << "\n";
			}
			cout << "\n 6. �����";

			cout << "\n ��������: ������� ���-������ ���������?";
			int Choice = ChoiceCheck(6);
			if (Choice == 6) {
				cout << "\n ��������: �� ��������, �������� ���!";
				break;
			}

			if (shop.Items.at(Choice - 1).Quantity != 0)
			{
				if (CheckMoney(player.Gold, shop.Items.at(Choice - 1).Price))
				{
					if (player.Inventory.size() != player.InventoryMaxCapacity)
					{
						shop.Items.at(Choice - 1).Quantity--;
						bool alreadyHaveChosenItem = false;
						int itemSlot = 0;
						for (int i = 0; i < player.Inventory.size(); i++)
							if (player.Inventory.at(i).Name == shop.Items.at(Choice - 1).Name)
							{
								alreadyHaveChosenItem = true;
								itemSlot = i;
								break;
							}

						if (alreadyHaveChosenItem)
							player.Inventory.at(itemSlot).Quantity++;
						else
						{
							player.Inventory.push_back(shop.Items.at(Choice - 1));
							player.Inventory.back().Quantity = 1;
							player.Inventory.back().Price /= 2;
						}
						cout << "\n ��������: ������� �� �������!";
					}
					else cout << "\n ��������: ��-��, ������� ��� ��������� �����! �� �� ������� ������ ������";
				}
				else cout << "\n ��������: ��������, � �� ���� ���� ��� � ����. �������������, ����� ������� ������� ��������.";
			}
			else cout << "\n ��������: ��������, ���� ������� ���������, �������� ������.";
		}
		cout << " ������� ����� ������, ����� ��������� � �������" << endl;
		GetKey();
		break;


	case 2:
		system("cls");
		cout << "\n\t <-- ������� ������ -->\n";
		cout << " �������: ������������. � - ������� ����� ������, ��� �� ��� ��������. � ����� ������ ��� ������.";
		Sleep(1000);
		if (player.Inventory->empty())
			cout << "\n �������: ... �� ������ � ������� ������? ��������? ������������ ������.";
		else
		{
			while (true)
			{

				cout << "\n �������: ��-�, ���������, ��� � ��� ����...\n";
				for (int i = 0; i < player.Inventory->size(); i++)
					cout << " " << to_string(i + 1) << ". " << player.Inventory->at(i).Name << " | ����������: " << player.Inventory->at(i).Quantity << endl;
				cout << player.Inventory->size() + 1 << ". �����";

				cout << "\n <-- �������� ������� �� ������� -->";
				int Choice = ChoiceCheck(player.Inventory->size() + 1);
				if (Choice == player.Inventory->size() + 1)
				{
					cout << "\n �������: ��������.";
					break;
				}
				cout << "\n �������: � ����� " << player.Inventory->at(Choice - 1).Name << " �� " << player.Inventory->at(Choice - 1).Price << " �������. �� ��������?";
				cout << "\n 1. ��";
				cout << "\n 2. ���";

				if (ChoiceCheck(2) == 1)
				{
					cout << "\n �������: �������! ��� �������� ��� ���������.";
					player.Gold += player.Inventory->at(Choice - 1).Price;
					player.Inventory->at(Choice - 1).Quantity--;
					if (player.Inventory->at(Choice - 1).Quantity == 0)
						player.Inventory->erase(player.Inventory->begin() + Choice - 1);
				}
				else cout << "\n �������: ��� �������.";


				if (player.Inventory->empty()) {
					cout << "\n �������: �������, � ��� ���������� �����. ������ �������� ������ ������ � �� ������������, ���� � ��� �� �������� �����.";
					break;
				}
			}

			cout << " ������� ����� ������, ����� ��������� � �������" << endl;
			GetKey();
			break;
		}
	}
}
void BuyMercenaries(Player& player, Companion& companion, Shop& shop)
{
	while (true)
	{
		system("cls");
		cout << "\n\t<-- ���� ����������� -->\n";
		cout << " ������� ��������: ����������� � ���-���. ������� �����.";
		for (int i = 0; i < 5; i++)
			cout << " " << to_string(i + 1) << ". " << shop.Companions[i].Name << " | �����: " << shop.Companions[i].Class
			<< " | ��������: " << shop.Companions[i].TotalHP << " | ������: " << shop.Companions[i].Defence
			<< " | ����: " << shop.Companions[i].Damage << " | ���������� ����: " << shop.Companions[i].MaxAttackCount << "\n";
		cout << "\n 6. �����";
		cout << "\n �����\n";

		int Choice = ChoiceCheck(6);
		if (Choice == 6) return;

		if (!shop.Companions[Choice - 1].isSold)
			if (player.haveCompanion)
			{
				cout << "\n � ��� ��� ���� ��������� " << companion.Name << ":\n";
				cout << " �����: " << companion.Class << " | ��������: " << companion.HP << " / " << companion.TotalHP << " | ������: " << companion.Defence
					<< " | ����: " << companion.Damage << " | ���������� ����: " << companion.CurAttackCount << " / " << companion.MaxAttackCount;
				cout << "\n\n ������ ��� ��������?";
				cout << "\n 1. ��";
				cout << "\n 2. ���";
				if (ChoiceCheck(2) == 1)
				{
					companion = shop.Companions[Choice - 1];
					shop.Companions[Choice - 1].isSold = true;
					shop.Companions[Choice - 1].Name += " (������)";
					return;
				}
			}
			else
			{
				cout << "\n �� ������ ���������� " << companion.Name;
				companion = shop.Companions[Choice - 1];
				shop.Companions[Choice - 1].isSold = true;
				shop.Companions[Choice - 1].Name += " (������)";
				return;
			}
		else cout << "\n ���� ������ ��� ��� �����.";
	}
}
void RestInTavern(Player& player, Companion& companion)
{
	system("cls");
	cout << "\n\t<-- ����� � ������� -->\n";
	int restPrice = (player.TotalHP - player.HP) + (player.MaxMana - player.Mana) +
		(companion.TotalHP - companion.HP) + (companion.MaxAttackCount - companion.CurAttackCount) * 5;
	if (restPrice != 0) {
		if (CheckMoney(player.Gold, restPrice))
		{
			player.Gold = player.Gold - restPrice;
			player.HP = player.TotalHP;
			player.Mana = player.MaxMana;
			companion.HP = companion.TotalHP;
			companion.CurAttackCount = companion.MaxAttackCount;
			cout << " �� ���������. ���� �������� � ���� ��������� �������������.";
			cout << "\n ��� ��������� ��������. ��� �������� � ���� ��������� �������������.";
		}
		else cout << " ������ �������: �������������, ����� ����� ������, ���������!";
	}
	else cout << " �� �� ���������� � ������... ";
	cout << endl;
	cout << endl;
	cout << " ������� ����� ������, ����� ��������� � ������� ����" << endl;
	GetKey();
}
void Dungeon(Player& player, Companion& companion)
{
	system("cls");
	int floor = 1;
	cout << "\n\t<-- ����� � ���������� -->\n";
	cout << " ��������, ���� ����:\n";
	cout << " 1. ��� ������ �������� (�����, 5 ������) \n";
	cout << " 2. ����� ������ (������, 12 ������) \n";
	cout << " 3. �������� ������� (������, 25 ������) \n" << endl;
	NewDungeon myDungeon;
	switch (ChoiceCheck(3)) {
	case 1:
		myDungeon.DungDifficulty = 0.75;
		myDungeon.DungFloorsCount = 5;
		myDungeon.DungType = "��� ������ ��������";
		myDungeon.isDungBoss = 0.0;
		break;
	case 2:
		myDungeon.DungDifficulty = 1.5;
		myDungeon.DungFloorsCount = 12;
		myDungeon.DungType = "����� ������";
		myDungeon.isDungBoss = 0.5;
		break;
	case 3:
		myDungeon.DungDifficulty = 3.0;
		myDungeon.DungFloorsCount = 25;
		myDungeon.DungType = "�������� �������";
		myDungeon.isDungBoss = 1.0;
		break;
	}

	for (int i = 1; i <= myDungeon.DungFloorsCount; i++) {
		myDungeon.DungCurFloor = i;
		if (myDungeon.DungCurFloor == myDungeon.DungFloorsCount)
			if ((double)Random(0, 11) / 10.0 <= myDungeon.DungDifficulty)
				ChooseRandomBoss(player, companion, myDungeon);
		ChooseRandomFloor(player, companion, myDungeon);
	}

	system("cls");
	cout << "\n ������� �����������. �� ���������� ������� ��������� � ���� ����...";
	cout << " ������� ����� ������, ����� ��������� � ������� ����" << endl;
	GetKey();
}
void ChooseRandomFloor(Player& player, Companion& companion, NewDungeon& dungeon) 
{
	Reward BattleReward;
	//������������ ������ ������
	vector <Enemy> Enemies;
	int r;
	//UI
	{
		system("cls");
		cout << "\n ������� " << dungeon.DungType << " | ���� " << dungeon.DungCurFloor << " �� " << dungeon.DungFloorsCount << endl;

		cout << "\n " << player.Name << " ��������������: \n";
		cout << " �����: " << player.Class << "\n";
		cout << " �������: " << player.Level << "\n";
		cout << " ����: " << player.Experience << " / " << player.MaxExp << "\n";
		cout << " ��������: " << player.HP << " / " << player.TotalHP << "\n";
		cout << " ������� ����: " << (player.Damage + player.MinDamage) / 2.0 << "\n";
		cout << " ������: " << player.Defence << "\n";
		cout << " ���������� ����: " << player.MagicPower << "\n";
		cout << " ����: " << player.Mana << " / " << player.MaxMana << "\n";
		cout << " ������: " << player.Gold << "\n";
		cout << " \n\n";
	}

	switch (Random(0, 10))
	{
	default:
	case 0:
	{
		cout << " �� ���� �� �����, ��� ����� �� ���� ��������� ������, ���������� � ��� �� ��������. ���� ��������?\n";
		cout << " 1. ������� �� ����\n";
		cout << " 2. ���������� �� ������\n";
		cout << " 3. ���������� ������\n";
		cout << " 4. ������ �� ������\n";
		Enemies.push_back(Enemy("����� ������", 0, 60 * dungeon.DungDifficulty, 33 * dungeon.DungDifficulty, 3));
		switch (ChoiceCheck(4)) {
		case 1:
		{
			player.HP -= Random(Enemies.front().Damage - 5, Enemies.front().Damage + 5);
			Enemies.front().HP -= Random(player.MinDamage, player.Damage);

			cout << "\n ����� �������� � ��� ������� (���� ��������: " << player.HP << "), �� �������� �� ��� ����� ������.";
			if (Enemies.front().HP <= 0) {
				Reward rew = CalculateReward(dungeon.DungDifficulty, Enemies);
				cout << "\n ����� ����. �������� �����: " << rew.Experience;
				cout << "\n �� ����������� ������� � �������� ������� ������: " << rew.Gold;
				GiveReward(player, rew);
				vector<Enemy>().swap(Enemies);
			}
			else {
				cout << "\n �� ������ ������, �������� ��� " << Enemies.front().HP << " ��������.\n";
			}
		}
		break;
		case 2:
		{
			int difference = player.InventoryMaxCapacity - player.Inventory.size();
			double hardness = 10 * dungeon.DungDifficulty;
			if (difference > hardness)
				cout << "\n �� ������� ���������� �� ������!";
			else
			{
				player.HP -= Random(Enemies.front().Damage - 10, Enemies.front().Damage);
				cout << "\n ���-�� ���������� ���� ������������ - �� �� ������ ����������.";
				cout << "\n ����� ����� ��� ������� � ��������� " << player.HP << " ��������.\n";
			}
		}
		break;
		case 3:
		{
			double hardness = 100 * dungeon.DungDifficulty;
			if (player.Defence > hardness)
				cout << "\n �� ������� �������� ������!";
			else
			{
				player.HP -= DecreaseDmgByDef(Enemies.front().Damage, player.Defence);
				cout << "\n ���� ������ ��������� ������ ������� - �� �� ������ ����������.";
				cout << "\n ����� ����� ��� ������� � ��������� " << player.HP << " ��������.\n";
			}
		}
		break;
		case 4:
		{
			int dmg = Enemies.front().Damage * 1.5;
			player.HP -= dmg;
			CheckDeath(player);
			cout << "\n ������� �� ����� ������ - �������� ���� ��� ��������!!!";
			cout << "\n ����� �������� �� ������������ ����� ������ ���� � ����� ��� �� " << dmg;
			cout << ".\n ���� ��������: " << player.HP;
		}
		break;
		}
		break;
	}
	case 1:
	{
		cout << "\n �� ���������� ������� � �������� ��������� ����� ��������. ��� ��� �� �����.";
		cout << "\n ���� �� ����� �������� ��������� ����� � ����. ����� ���-�� ������.";
		cout << "\n 1.������� ������ ����� � �����";
		cout << "\n 2.���� ����";
		cout << "\n 3.����������� � ������ ����� � ���������� ��� �����";
		cout << "\n 4.��������";


		for (int i = 0; i < 5; i++)
			Enemies.push_back(Enemy(" ����� ���������� [" + to_string(i + 1) + "]", 0, 80 * dungeon.DungDifficulty, 17 * dungeon.DungDifficulty, 2));

		GetKey();
		switch (ChoiceCheck(4)) {
		case 1:
		{
			cout << "\n �� ���� ��������������� � ������ � ����� ��� � �����";
			Enemies.at(Random(0, 5)).HP /= 2;
		}
		break;
		case 2:
		{
			cout << "\n �� ��������� ���� ����, �� ���� �� ����� �������� ���.";
			cout << "\n �� ������� �...";
			Sleep(2000);
			if (Random(0, 100) > 30)
			{
				cout << " ��������.";
				player.HP -= Enemies.front().Damage;
				cout << "\n ��� ������� " << Enemies.front().Damage << " �����. ������� ��������: " << player.HP;
				CheckDeath(player);
			}
			else cout << " �������������.";
		}
		break;
		case 3:
		{
			if (Random(0, 100) > 85) {
				cout << "\n �� ��������������� � ������ � �������� ��� ����������� ����, ����������� ������ ���.";
				int i = Random(0, 5);
				Enemies.at(i).Name += " (̨���)";
				Enemies.at(i).isDead = true;
			}
			else cout << "\n ��� ��������.";
		}
		break;
		case 4:
		{
			cout << "\n �� ������� ����� ��������. ��� ��������.";
		}
		break;
		}
		break;
	}
	case 2:
	{
		Enemies.push_back(Enemy("�����-������", 2, Random(80, 100) * dungeon.DungDifficulty, Random(20, 41) * dungeon.DungDifficulty, 4));
		int dmg = Enemies.front().Damage * 2;
		player.HP -= dmg;
		cout << "\n ������� ������������ ��� �������� ��� ����������� ������� �����������-����������.";
		cout << "\n �����-������ ������ ��������, ����������� � ��������, ������ ��� ���� (" << dmg << "). ���� ��������: " << player.HP;
		CheckDeath(player);
		break;
	}
	case 3:
	{

		for (int i = 0; i < 7; i++)
			Enemies.push_back(Enemy(" ����� [" + to_string(i + 1) + "]", 7, 50 * dungeon.DungDifficulty, 14 * dungeon.DungDifficulty, 2));

		cout << "\n �� ��������� � �������, � ������ � ������ ����� ������. �� ��� ����� ���� ���������� ����.";
		cout << "\n ���� ��������?";
		cout << "\n 1. ����� ���� �����";
		cout << "\n 2. ������� �� ��������� ����";
		switch (ChoiceCheck(2))
		{
		case 1:
			cout << "\n ������ ������ �� �������� ���� �� ����, ��������������� �� ���.";
			r = Random(0, 7);
			Enemies.at(r).HP = 0;
			Enemies.at(r).isDead = true;
			break;
		case 2:
			r = Random(0, 4);
			cout << "\n �� ������ ��� ���� �� " << player.Damage;
			for (int i = r; i < r + 3; i++)
				Enemies.at(i).HP -= player.Damage;
			break;
		}
		break;
	}
	case 4:
	{
		cout << "\n �� ��������� ����� ����� � ������������ � �������� ����.";
		cout << "\n ������� �� ������ ���������� ���� �����, ������� � ���-�� ����. �������, ��� ��� �� �����.";
		Enemies.push_back(Enemy("����-������ [1]", 2, Random(40, 55) * dungeon.DungDifficulty, Random(20, 30) * dungeon.DungDifficulty, 2));
		Enemies.push_back(Enemy("����-���", 2, Random(30, 36) * dungeon.DungDifficulty, Random(50, 60) * dungeon.DungDifficulty, 3));
		Enemies.push_back(Enemy("����-������ [2]", 2, Random(40, 55) * dungeon.DungDifficulty, Random(20, 30) * dungeon.DungDifficulty, 2));

		if (player.Defence > 100 * dungeon.DungDifficulty)
			cout << "\n �� ��������� ����������������� � ��� ����-�������.\n �� ������ �����, ��� ���������� �������� ���������.";
		else {
			int dmg = DecreaseDmgByDef(Enemies.front().Damage - 5, player.Defence);
			cout << "\n � ��� �������������� ������ ���� � ���� �������� ����� ��������. �� ������ �� " << dmg << ".";
			player.HP -= dmg;
			cout << "\n ���� ��������: " << player.HP;
			cout << "\n �� ��� ���� ������ ��� � �������� �������� �� ���. ������, ��� ��������� ����������.";
		}
		break;
	}
	case 5:
	{
		cout << "\n �� ����������� � ���������, ������� ���������. ��� ������ ���� �� �������� �� ������ � ��������� ��������� � �������.";
		for (int i = 0; i < 12; i++)
			Enemies.push_back(Enemy("������ [" + to_string(i + 1) + "]", 3, 20 * dungeon.DungDifficulty, 8 * dungeon.DungDifficulty, 1));
		break;
	}
	case 6:
	{
		cout << "\n �� ��������� � ������������ �����. ����� ����� ���� ����������� �������.";
		cout << "\n ����� � ���� �������� ��������, ������� �������� �������� ��� � ����� �� �������. ������ �� ��� ������?";
		cout << "\n 1. �� \n 2. ���\n";
		if (ChoiceCheck(2) == 1)
			Enemies.push_back(Enemy("����������� �����", 6, 220 * dungeon.DungDifficulty, Random(20, 30) * dungeon.DungDifficulty, 5));
		else
			for (int i = 0; i < 2; i++)
				Enemies.push_back(Enemy("����������� ����� [" + to_string(i + 1) + "]", 6, Random(160, 190) * dungeon.DungDifficulty, 25 * dungeon.DungDifficulty, 6));
		break;
	}
	case 7:
	{
		player.HP -= player.TotalHP / 12;
		if (player.HP <= 0)
			player.HP = 1;
		cout << "\n � ���� �������� ��� ������� � ������ �����. ������� ��������� ��������� ����������� �� ����� �������� (��������: " << player.HP << ").";
		cout << "\n ��� ������� �� ������ �� ��� �������� �������� � ������� � ������� �������.";

		Enemies.push_back(Enemy("��������", 3, Random(80, 105) * dungeon.DungDifficulty, Random(15, 20) * dungeon.DungDifficulty, 3));
		Enemies.push_back(Enemy("������� � ������� �������", 0, Random(20, 45) * dungeon.DungDifficulty, 60 * dungeon.DungDifficulty, 4));
		break;
	}
	case 8:
	{
		cout << "\n �� ��������� ����� �����. ���� ����� ��������� ������� ������������� ����� ����� � �������� �������.";
		cout << "\n ��� ���� ����� � �������� ����� �����, ���� �� ����� ���������� �����-�� ������.";
		cout << "\n ������ � ��� ��� ������ ��� ������ ������, ����������� ����� � �����. � ������� �� ���� ����� ������ ����� �, �������, �������.";
		cout << "\n ��� �� ������ �������?";
		cout << "\n 1. ���������� �� ������ �����";
		cout << "\n 2. ��������������� ������ ����� � ������� ����� �� ������ �������";
		if (ChoiceCheck(2) == 1) {
			Enemies.push_back(Enemy("������ �����", 1, Random(60, 75) * dungeon.DungDifficulty, 50 * dungeon.DungDifficulty, 3));

			cout << "\n\n �� �������� ������ ��� ������� �����, �� ��� ������������� �� ����� � ������������.";
			int dmg = DecreaseDmgByDef(Enemies.front().Damage, player.Defence);
			player.HP -= dmg;
			cout << "\n �� ������ ������ ������, �� ����������� ���� ���� (" << dmg << " �����)...";
			Sleep(1000);
			CheckDeath(player);
			cout << "\n ������ ����� �� ��� �����, ��� �������. �� ����������� ����������� � ����������� ����� ��� �������� � ������ �������.";
			for (int i = 1; i < 4; i++) {
				Enemies.push_back(Enemy("������ ������ [" + to_string(i + 1) + "]", 6, Random(90, 105) * dungeon.DungDifficulty, Random(15, 20) * dungeon.DungDifficulty, 2));
				Sleep(100);
			}
			if (Random(0, 100) > 70) {
				cout << "\n �� ������ ������ � ������ ������ �����.";
				Enemies.front().HP -= player.Damage;
				Sleep(500);
				cout << "\n �� ��� ���� �� �������, ������ � ���, ������ ������ ����� ������.";
				dmg = DecreaseDmgByDef(Enemies.at(1).Damage, player.Defence);
				cout << "\n ��� �������: " << dmg << ". ���� ��������: " << player.HP;
				CheckDeath(player);
			}
		}
		else {
			cout << "\n\n �� ��������� ���� ������ �����. � ���������, ������ ��� �� ���������, ��� �� ��������� ��� �������.";
			cout << "\n �����, ��� �� ������������� � ������ ������� �� ������� � ���������� �������� �� ��� ��������.";
			cout << "\n ���� ������ ������ ��� ������� ��� � ������������� � �����.";
			for (int i = 0; i < 3; i++)
				Enemies.push_back(Enemy("������ ������ [" + to_string(i + 1) + "]", 6, Random(90, 105) * dungeon.DungDifficulty, Random(15, 20) * dungeon.DungDifficulty, 2));
		}

		break;
	}
	case 9:
	{
		cout << "\n � ����� ����������� �� ��������� ���������. � ����� � ������ �� ���������� ��������, ���������������� \"����������\".";
		cout << "\n ��������: �����������! ������, �� ������ � ����� ���! ��� �� ������� � ����������? �� ������ ��� ���-�� � ���� ����?";
		cout << "\n 1. ��";
		cout << "\n 2. ���";
		Enemies.push_back(Enemy("������ ��������", 1, Random(120, 130)* dungeon.DungDifficulty, 50 * dungeon.DungDifficulty, 6));
			int answer = (ChoiceCheck(2));
		if (answer == 1)
			cout << "\n ��������: ��, ��� ��� � ��������������. ����� � ����� ������������� ��� ������ - � ������ �� ���� ����� �����. ��� ������� �����, ��� ��� ������ ��� ����. ��-��-��.";
		else
			cout << "\n ��������: ���? �������, ��� �������. �, � ����, � ��� ����. ���� ����� �������, ���������? ��, ��� �� ��� �� ����... ��� ������� �����, ��� ��� ������ ��� ����. ��-��-��.";
		cout << "\n �������� �� ���, �������� ����� ����, �� �������� �� ����. �� ������� ����������� � ��� � ���������� ��� ���.";
		if (answer == 1)
			cout << "\n �� �������� ���������. �� ������ ���������� � ��������� ��� �����.\n �������� : ��� ������ - �� ���������, ������.";
		else
		{
			vector<Enemy>().swap(Enemies);
			cout << "\n ��������: ��, ��! ���, � ��� ���� ����? ������ ��, � ������ ��� �����... �������, ���� ��� �� ��������� ������ �������������?";
			cout << "\n 1. ��";
			cout << "\n 2. ���";
			if (ChoiceCheck(2) == 1) {
				cout << "\n ��������: �����?! ��, ������� �����. ��� ����� ����, ������! "
					<< "\n ��������: �� ������, ����������, ��� ��� �� � ���� ���� ������? ���� ���� ������ �������! ������ ��, ��� ������ ���������! "
					<< "\n ��������: ��� ������ ������. � � �� ����������! �, ������ ��������, ������������ � ������������! � ����! ��� ������ ���������. "
					<< "\n ��������: �� �� ����� �������! ��������� ��������! ��-�����, �����. ��-��-��.";
				cout << "\n � ����� ������� �������� ������� ��� 100 �������.";
				player.Gold += 100;
			}
			else {
				cout << "\n ��������: �������? �������! ������, ��� � �������? �, ������ ��������, ������������ � ������������!";
				cout << "\n ��������: �� � �, ������ ��������� ��������, ������, �������?";
			}
			Sleep(5000);
			goto label;
		}
	}
	}
	if (!Enemies.empty()) {
		cout << "\n ���������� ���...";
		Sleep(3000);
		Combat(player, companion, Enemies, dungeon);
		cout << "\n ����� ���������. ��� ���� �������:\n";
		BattleReward = CalculateReward(dungeon.DungDifficulty, Enemies);
		cout << " ����: " << BattleReward.Experience << "\t ������: " << BattleReward.Gold;
		GiveReward(player, BattleReward);
	}
label:
	cout << "\n\n ������� ����� �������, ����� ������� �� ��������� ����. ";
	GetKey();
}
void ChooseRandomBoss(Player& player, Companion& companion, NewDungeon& dungeon)
{
	DungeonBoss boss = DungeonBoss("���????", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	Reward BattleReward;
	switch (Random(0, 5)) {
	case 0:
	{
		cout << "\n �� ���������� ����� ������ ������. �� ����� �� ���� � ��� � ����� �������� ���������� �����-�����.";
		cout << "\n ����� ����� �� ������ ���� � ������ �� ���, �������� �����������.";
		cout << "\n ���� ��������?";
		cout << "\n 1. ��������� ������ ������";
		cout << "\n 2. ���������� ����������";
		boss = DungeonBoss("�����-�����", 4, 
			Random(300, 500) * dungeon.DungDifficulty, 
			Random(40, 90) * dungeon.DungDifficulty, 
			70, 5, Random(100, 300) * dungeon.DungDifficulty, 
			100 * dungeon.DungDifficulty, 0, 0, 3);
		Sleep(13);

		int dmg = DecreaseDmgByDef(boss.Damage * 1.5, player.Defence);
		switch (ChoiceCheck(2))
		{
		case 1:
			cout << "\n �� ��������� ������ ������-������ ����� ��� ��� �� ���������� ��� � ����� �� �����.\n";
			player.HP -= dmg;
			player.HP -= 10;
			cout << "\n �����-����� ���� ��� " << dmg + 10 << " �����. ���� ��������: " << player.HP;
			dmg = DecreaseDmgByDef(player.MinDamage, boss.Defence);
			boss.HP -= dmg;
			cout << "\n �� ������� ������-������ " << dmg << " �����. �������� ������-������: " << boss.HP;
			CheckDeath(boss);
			break;
		case 2:
			if (Random(0, 100) > 80)
			{
				cout << "\n �� ������� ���������� �� ������-������. �� ��������� � ����� � �������� 50 �����.";
				boss.HP -= 50;
			}
			else {
				player.HP -= dmg;
				cout << "\n �����-����� ������� ���. �� ��������� " << dmg << " �����. ���� ��������: " << player.HP;
			}

			break;
		}
		CheckDeath(player);
	}
	break;
	case 1:
	{
		cout << "\n ������ ����� �����, �� ��������� � ����������� �����, ��������� � �������� ��� ������.  ���� � ����� ����������� ����� �����.";
		cout << "\n ������� ���, �� ����� � ������ ������ � ����������� ��� ����, ����� ��� ���� ����� �������� ����� �� ����. ����� �� ��������.";
		boss = DungeonBoss("����� �����", 4,
			500 * dungeon.DungDifficulty,
			Random(10, 20) * dungeon.DungDifficulty,
			-35, 6, Random(150, 300) * dungeon.DungDifficulty,
			150 * dungeon.DungDifficulty, 15, 2, 3);
	}
	break;
	case 2:
	{
		cout << "\n �� ���� �� ����� � ������� ����� ������. �� ������ ������� ��������� ������ ����� � ��� ���������� � ���...";
		cout << "\n �� �������� � ���� ��� ������ ������� ������� ������� � �������� ���� ������ �����.";
		cout << "\n ������� ������� �� �������� ����� � ��� �� ����� ������ � ���. �� ������, ��� ��� ���������� ������� ������.";
		cout << "\n �� ������� ��������������� �������� � �������� �������.";
		boss = DungeonBoss("������� �������", 5,
			430 * dungeon.DungDifficulty,
			80 * dungeon.DungDifficulty,
			140, 7, 100 * dungeon.DungDifficulty,
			Random(250, 500) * dungeon.DungDifficulty, 25, 1, 4);
		boss.HP -= (player.Damage + player.MagicPower);
	}
	break;
	case 3:
	{
		cout << "\n �� ����� ��������� ������� �����������, �� ��� �������� ���.";
		boss = DungeonBoss("���", 3,
			350 * dungeon.DungDifficulty,
			40 * dungeon.DungDifficulty,
			56, 8, Random(300, 500) * dungeon.DungDifficulty,
			Random(250, 400)* dungeon.DungDifficulty, 5, 3, 2);
	}
	break;
	case 4:
	{
		cout << "\n � �������� ����, � ����� �� ����� ��� ����������� ������� � �������� �������� ������.";
		cout << "\n �� ������ ������ �������, ��� ��� ���� �� �������� �������� �����, �� ��� ��������� ������� � ���, ��� �� ������� � ������ � ��������� ����� �� ���.";
		cout << "\n �� �������� ������� � ���� �� ����� �����, ����� �� ������. �� �������, ��� ������� ������� ���������� �� ��� ������.";
		boss = DungeonBoss("����� ����� �� ������", 2,
			300 * dungeon.DungDifficulty,
			120 * dungeon.DungDifficulty,
			100, 6, Random(500, 1500) * dungeon.DungDifficulty,
			Random(200, 450) * dungeon.DungDifficulty, 35, 4, 3);
	}
	break;
	}
	cout << "\n ���������� ���...";
	Sleep(3000);
	Combat(player, companion, boss);

	cout << "\n ����� � ������ ���������. ��� ���� �������:\n";
	BattleReward = CalculateReward(dungeon.DungDifficulty, boss);
	cout << " ����: " << BattleReward.Experience << "\t ������: " << BattleReward.Gold;
	GiveReward(player, BattleReward);
	cout << "\n\n ������� ����� �������, ����� �������� ���� � ��������� � ������� ����. ";
	GetKey();
}
void HeroStats(Player& player)
{
	system("cls");
	cout << "\n " << player.Name << " ��������������: \n";
	cout << " �����: " << player.Class << "\n";
	cout << " �������: " << player.Level << "\n";
	cout << " ����: " << player.Experience << " / " << player.MaxExp << "\n";
	cout << " ��������: " << player.HP << " / " << player.TotalHP << "\n";
	cout << " ������� ����: " << (player.Damage + player.MinDamage) / 2.0 << "\n";
	cout << " ������: " << player.Defence << "\n";
	cout << " ���������� ����: " << player.MagicPower << "\n";
	cout << " ����: " << player.Mana << " / " << player.MaxMana << "\n";
	cout << " ������: " << player.Gold << "\n";
	cout << " \n";
	cout << " ���������: \n";

	for (int i = 0; i < player.Inventory->size(); i++)
		cout << " |" << player.Inventory->at(i).Name << " - " << player.Inventory->at(i).Quantity << "| ";

	cout << endl << endl;
	cout << " ������� ����� ������, ����� ��������� � ������� ����" << endl;
	GetKey();
}
void HeroArmy(Player& player, Companion& companion)
{
	system("cls");
	cout << "\n ����� " << player.Name << ":";
	cout << "\n\n " << player.Name << "\n�����: " << player.Class << "\t��������: " << player.HP << " / " << player.TotalHP << "\t������: " << player.Defence << "\t����: " << (player.MinDamage + player.Damage) / 2.0;
	cout << "\n\n " << companion.Name << "\n�����: " << companion.Class << "\t��������: " << companion.HP << " / " << companion.TotalHP << "\t������: " << companion.Defence << "\t����: " << companion.Damage;
	cout << "\n\n ������� ����� ������, ����� ��������� � ������� ���� \n";
	GetKey();
}