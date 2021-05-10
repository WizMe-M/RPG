#include "MenuMethods.h"
#include "Helper.h"
#include "Combat.h"

using namespace std;

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
			for (int i = 0; i < shop.Items.size(); i++)
			{
				cout << " " << to_string(i + 1) << ".  �����: " << shop.Items.at(i).Name
					<< " | ����������: " << shop.Items.at(i).Quantity
					<< " | ����: " << shop.Items.at(i).Price << "\n";
			}
			cout << "\n " << shop.Items.size() + 1 << ". �����";

			cout << "\n ��������: ������� ���-������ ���������?";
			int Choice = ChoiceCheck(shop.Items.size() + 1) - 1;
			if (Choice == shop.Items.size()) {
				cout << "\n ��������: �� ��������, �������� ���!";
				break;
			}

			if (shop.Items.at(Choice).Quantity != 0)
			{
				if (CheckMoney(player.Gold, shop.Items.at(Choice).Price))
				{
					if (player.Inventory.size() != player.InventoryMaxCapacity)
					{
						shop.Items.at(Choice).Quantity--;
						bool alreadyHaveChosenItem = false;
						int itemSlot = 0;
						for (int i = 0; i < player.Inventory.size(); i++)
							if (player.Inventory.at(i).Name == shop.Items.at(Choice).Name)
							{
								alreadyHaveChosenItem = true;
								itemSlot = i;
								break;
							}

						if (alreadyHaveChosenItem)
							player.Inventory.at(itemSlot).Quantity++;
						else
						{
							player.Inventory.push_back(shop.Items.at(Choice));
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
		cout << "\n ������� ����� ������, ����� ��������� � �������" << endl;
		GetKey();
		break;


	case 2:
		system("cls");
		cout << "\n\t <-- ������� ������ -->\n";
		cout << " �������: ������������. � - ������� ����� ������, ��� �� ��� ��������. � ����� ������ ��� ������.";
		Sleep(1000);
		if (player.Inventory.empty())
			cout << "\n �������: ... �� ������ � ������� ������? ��������? ����������-�� ������.";
		else
		{
			while (true)
			{

				cout << "\n �������: ��-�, ���������, ��� � ��� ����...\n";
				for (int i = 0; i < player.Inventory.size(); i++)
					cout << " " << to_string(i + 1) << ". " << player.Inventory.at(i).Name << " | ����������: " << player.Inventory.at(i).Quantity << endl;
				cout << " " << player.Inventory.size() + 1 << ". �����";

				cout << "\n <-- �������� ������� �� ������� -->";
				int Choice = ChoiceCheck(player.Inventory.size() + 1);
				if (Choice == player.Inventory.size() + 1)
				{
					cout << "\n �������: ��������.";
					break;
				}
				cout << "\n �������: � ����� " << player.Inventory.at(Choice - 1).Name << " �� " << player.Inventory.at(Choice - 1).Price << " �������. �� ��������?";
				cout << "\n 1. ��";
				cout << "\n 2. ���";

				if (ChoiceCheck(2) == 1)
				{
					cout << "\n �������: �������! ��� �������� ��� ���������.";
					player.Gold += player.Inventory.at(Choice - 1).Price;
					player.Inventory.at(Choice - 1).Quantity--;
					if (player.Inventory.at(Choice - 1).Quantity == 0)
						player.Inventory.erase(player.Inventory.begin() + Choice - 1);
				}
				else cout << "\n �������: ��� �������.";


				if (player.Inventory.empty()) {
					cout << "\n �������: �������, � ���� ���������� ����� �� �������, �� ������ ��? ������ ������ ������ � �� ������������, ���� �� ����������� �����.";
					break;
				}
			}
		}
		cout << "\n ������� ����� ������, ����� ��������� � �������" << endl;
		GetKey();
		break;
	}
}
void BuyMercenaries(Player& player, Companion& companion, Shop& shop)
{
	while (true)
	{
		system("cls");
		cout << "\n\t<-- ���� ����������� -->\n";
		cout << " ������� ��������: ����������� � ���-���. ������� �����.\n";
		for (int i = 0; i < shop.Companions.size(); i++)
			cout << " " << to_string(i + 1) << ". " << shop.Companions.at(i).Name << " | �����: " << shop.Companions.at(i).Class
			<< " | ��������: " << shop.Companions.at(i).TotalHP << " | ������: " << shop.Companions.at(i).Defence
			<< " | ����: " << shop.Companions.at(i).Damage << " | ���������� ����: " << shop.Companions.at(i).MaxAttackCount << "\n";
		cout << "\n " << shop.Companions.size() + 1 << ". �����\n";

		int Choice = ChoiceCheck(shop.Companions.size() + 1) - 1;
		if (Choice == shop.Companions.size()) return;

		if (!shop.Companions.at(Choice).isSold)
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
					companion = shop.Companions.at(Choice);
					shop.Companions.at(Choice).isSold = true;
					shop.Companions.at(Choice).Name += " (������)";
					return;
				}
			}
			else
			{
				cout << "\n �� ������ ���������� " << companion.Name;
				companion = shop.Companions.at(Choice);
				shop.Companions.at(Choice).isSold = true;
				shop.Companions.at(Choice).Name += " (������)";
				return;
			}
		else cout << "\n ���� ������ ��� ��� �����.";
	}
	cout << "\n ������� ����� ������, ����� ��������� � �������" << endl;
	GetKey();
}
void RestInTavern(Player& player, Companion& companion)
{
	system("cls");
	cout << "\n\t<-- ����� � ������� -->\n";
	int restPrice = (player.TotalHP - player.HP) + (player.MaxMana - player.Mana) +
		(companion.TotalHP - companion.HP) + (companion.MaxAttackCount - companion.CurAttackCount) * 5;
	cout << "\n ������ �������: ���� ������� ��� ��� �������� " << restPrice << " �������";
	if (restPrice != 0) {
		if (CheckMoney(player.Gold, restPrice))
		{
			player.Gold = player.Gold - restPrice;
			player.HP = player.TotalHP;
			player.Mana = player.MaxMana;
			companion.HP = companion.TotalHP;
			companion.CurAttackCount = companion.MaxAttackCount;
			cout << "\n �� ���������. ���� �������� � ���� ��������� �������������.";
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
	SomeDungeon dungeon;
	switch (ChoiceCheck(3)) {
	case 1:
		dungeon.DungDifficulty = 0.75;
		dungeon.DungFloorsCount = 5;
		dungeon.DungType = "��� ������ ��������";
		dungeon.isDungBoss = 0.0;
		break;
	case 2:
		dungeon.DungDifficulty = 1.5;
		dungeon.DungFloorsCount = 12;
		dungeon.DungType = "����� ������";
		dungeon.isDungBoss = 0.5;
		break;
	case 3:
		dungeon.DungDifficulty = 3.0;
		dungeon.DungFloorsCount = 25;
		dungeon.DungType = "�������� �������";
		dungeon.isDungBoss = 1.0;
		break;
	}

	for (int i = 1; i <= dungeon.DungFloorsCount; i++) {
		dungeon.DungCurFloor = i;
		if (dungeon.DungCurFloor == dungeon.DungFloorsCount)
			if ((double)Random(0, 100) / 100.0 < dungeon.isDungBoss)
				ChooseRandomBoss(player, companion, dungeon);
		ChooseRandomFloor(player, companion, dungeon);
	}

	system("cls");
	cout << "\n ������� �����������. �� ���������� ������� ��������� � ���� ����...";
	cout << " ������� ����� ������, ����� ��������� � ������� ����" << endl;
	GetKey();
}
void ChooseRandomFloor(Player& player, Companion& companion, SomeDungeon& dungeon)
{
	if (player.SpecialAbilityCooldown != 0)
		player.SpecialAbilityCooldown--;
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
				Enemies.at(i).HP = 0;
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
		Sleep(1000);
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
		cout << "\n � ���� �������� ��� ������� � ������ �����. ������� ��������� ������� ����������� �� ����� �������� (��������: " << player.HP << ").";
		Sleep(1000);
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
		Enemies.push_back(Enemy("������ ��������", 1, Random(120, 130) * dungeon.DungDifficulty, 50 * dungeon.DungDifficulty, 6));
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
		cout << "\n ������� ����� �������, ����� ������ ���";
		GetKey();
		Combat(player, companion, Enemies);
		cout << "\n ����� ���������. ��� ���� �������:\n";
		BattleReward = CalculateReward(dungeon.DungDifficulty, Enemies);
		cout << " ����: " << BattleReward.Experience << "\t ������: " << BattleReward.Gold;
		GiveReward(player, BattleReward);
	}
label:
	cout << "\n\n ������� ����� �������, ����� ������� �� ��������� ����. ";
	GetKey();
}
void ChooseRandomBoss(Player& player, Companion& companion, SomeDungeon& dungeon)
{
	DungeonBoss boss = DungeonBoss("���????", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	Reward BattleReward;
	system("cls");
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
			Random(40, 60) * dungeon.DungDifficulty,
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
			Random(250, 400) * dungeon.DungDifficulty, 5, 3, 2);
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

	for (int i = 0; i < player.Inventory.size(); i++)
		cout << " |" << player.Inventory.at(i).Name << " - " << player.Inventory.at(i).Quantity << "| ";

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