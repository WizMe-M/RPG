#include "Combat.h"

using namespace std;

void ShowEnemies(vector<Enemy> Enemies, vector<Enemy> DeadEnemies)
{
	system("cls");
	if (!DeadEnemies.empty())
	{
		cout << "\n\t<-- ̸����� ����� -->\n";
		for (Enemy en : DeadEnemies)
			cout << " |" << en.Name << "(�������: " << en.Level << ")|\t";
	}

	cout << "\n\t<-- ����� ���������� -->";
	cout << "\n ���������� �����������: " << Enemies.size() << "\n ";
	for (int i = 0; i < Enemies.size(); i++) {
		cout << to_string(i + 1) << ". " << Enemies.at(i).Name
			<< " | �������: " << Enemies.at(i).Level
			<< " | ����: " << Enemies.at(i).Race
			<< " | ��������: " << Enemies.at(i).HP << "/" << Enemies.at(i).BaseHP
			<< " | ����: " << Enemies.at(i).Damage << "\n";
	}
	cout << "\n\n";
}

void ShowBoss(DungeonBoss boss) {
	system("cls");
	cout << "\n\t<-- ����� ���������� -->";
	cout << "\n ���� \"" << boss.Name << "\" �������: " << boss.Level << "\n";
	cout << " ����: " << boss.Race
		<< " | ��������: " << boss.HP << "/" << boss.BaseHP
		<< " | ����: " << boss.Damage;
	cout << "\n\n";
}

void ShowHero(Player player, Companion companion) {
	cout << "\n\t <-- ����� " << player.Name << " -->";
	cout << "\n\n |" << player.Name << "|\n�����: " << player.Class << "\t��������: " << player.HP << " / " << player.TotalHP << "\t������: " << player.Defence << "\t����: " << (player.MinDamage + player.Damage) / 2.0;
	cout << "\n\n |" << companion.Name << "|\n�����: " << companion.Class << "\t��������: " << companion.HP << " / " << companion.TotalHP << "\t������: " << companion.Defence << "\t����: " << companion.Damage;
	cout << "\n\n";
}

void Combat(Player& player, Companion& companion, vector<Enemy>& Enemies)
{
	vector<Enemy> DeadEnemies;
	while (Enemies.size() != 0)
	{
		PlayerTurn(player, companion, Enemies, DeadEnemies);
		if (Enemies.size() == 0) break;
		EnemyTurn(player, companion, Enemies);
	}
	system("cls");
	Enemies.swap(DeadEnemies);
}

void PlayerTurn(Player& player, Companion& companion, vector<Enemy>& Enemies, vector<Enemy>& DeadEnemies)
{
	bool isActed = false;
	int Choice = 0;
	while (!isActed)
	{
		ShowEnemies(Enemies, DeadEnemies);
		ShowHero(player, companion);

		cout << "\n";
		cout << "\n 1 --|====>\t��������� ����������.";
		cout << "\n 2 --|====>\t������������ ������ ����.";
		cout << "\n 3 --|====>\t��������� ������� �� ���������.";
		cout << " \n";

		cout << "\n <-- �������� �������� -->\n";
		switch (ChoiceCheck(3)) {
		case 1:
		{
			cout << "\n <-- �������� ���������� ��� ����� -->\n";
			Choice = ChoiceCheck(Enemies.size() + 1) - 1;

			if (Random(0, 100) > 25)
			{
				Enemies.at(Choice).HP -= (Random(player.MinDamage, player.Damage) + player.MagicPower);
				cout << player.Name << " ������� " << Enemies.at(Choice).Name << " � ��������� ��� " << Enemies.at(Choice).HP << " ��������. ";
				CheckDeath(Enemies, DeadEnemies, Choice);
			}
			else cout << player.Name << " ������� " << Enemies.at(Choice - 1).Name << " � �������������.\n";

			Sleep(1000);
			if (companion.CurAttackCount != 0 && Enemies.size() != 0)
			{
				int RandAttack;
				if (Enemies.size() == 1) RandAttack = 0;
				else RandAttack = Random(0, Enemies.size());

				Enemies.at(RandAttack).HP -= companion.Damage;
				cout << companion.Name << " ������� " << Enemies.at(RandAttack).Name << " � ��������� ��� "
					<< Enemies.at(RandAttack).HP << " ��������. ";
				companion.CurAttackCount--;
				CheckDeath(Enemies, DeadEnemies, RandAttack);
			}
			isActed = true;
			break;
		}
		case 2:
		{
			if (player.Class == "����")
			{
				cout << "\n <-- �������� ���������� ��� ����� -->\n";
				Choice = ChoiceCheck(Enemies.size() + 1) - 1;

				Enemies.at(Choice).HP -= 2 * player.Damage;
				cout << "\n\n" << player.Name << " ������� " << Enemies.at(Choice).Name << " ����������� ������ � ��������� " << Enemies.at(Choice).HP << " ��������. ";
				CheckDeath(Enemies, DeadEnemies, Choice);
				isActed = true;
			}
			if (player.Class == "���")
			{
				if (player.Mana >= player.MaxMana / 2) {
					cout << "\n\n " << player.Name << " ������� �������� ��� � ������� �� ���� �����������. ";
					player.Mana -= player.MaxMana / 2;
					for (int i = 0; i < Enemies.size(); i++)
					{
						Enemies.at(i).HP -= 3 * (player.MagicPower + player.Damage);
						cout << "\n " << player.Name << " ������� " << 3 * (player.MagicPower + player.Damage) << " ����� ���������� "
							<< Enemies.at(i).Name << " � ��������� ���" << Enemies.at(i).HP << " ��������. ";
						CheckDeath(Enemies, DeadEnemies, i);
					}
					isActed = true;
				}
				else cout << "\n ������������ ���� ��� ���������� �����������. "
					<< "\n ����� ����� ������ �������� �� ������������� ������ ���� (" << player.MaxMana / 2 << ").";
			}
			if (player.Class == "������")
			{
				if (player.Mana >= 20)
				{
					cout << "\n <-- �������� ���������� ��� ����� -->\n";
					Choice = ChoiceCheck(Enemies.size() + 1) - 1;
					player.Mana -= 20;
					int dealDamage = 3 * player.Damage;
					Enemies.at(Choice).HP -= dealDamage;
					cout << player.Name << " ����� " << Enemies.at(Choice).Name << " ������ ���������, �������� ��� "
						<< Enemies.at(Choice).HP << " ��������. ";
					CheckDeath(Enemies, DeadEnemies, Choice);
					isActed = true;
				}
				else cout << "\n ������������ ���� ��� ���������� ������� ������ (����� ��-������� ���� 20 ����).";
			}
		}
		break;
		case 3:
		{
			cout << "\n\t<-- �������� ������� � ��������� -->";
			for (int i = 0; i < player.Inventory.size(); i++)
				cout << to_string(i + 1) << ". " << player.Inventory.at(i).Name << "\n";
			cout << to_string(player.Inventory.size() + 1) << ". �����";

			Choice = ChoiceCheck(player.Inventory.size() + 1);
			if (player.Inventory.at(Choice).Name == "�����")
			{
				player.HP += 50;
				companion.HP += 50;
				CheckGreaterPoints(player.HP, player.TotalHP);
				CheckGreaterPoints(companion.HP, companion.TotalHP);
				cout << "\n �� ������ �������� �����! ��� ����� ����������� 50 ��������.";
				isActed = true;
			}
			else cout << "\n �� �� ������ ���� ��������� ���� �������";
		}
		break;
		}
	}
	cout << "\n\n ������� ����� �������, ����� �������� ��� ����������.";
	GetKey();
}

void EnemyTurn(Player& player, Companion& companion, vector<Enemy>& Enemies)
{
	system("cls");
	cout << " \n";
	cout << " ��� ����������...\n";
	Sleep(1000);
	ShowHero(player, companion);

	for (int i = 0; i < Enemies.size(); i++) {

		//������ ������ ���� ��� ����� (�����, ����� ������ ���� �������� � �������� ����� ������� � �����������). �� ��������� ��� �����
		Target newTarget = Target(player.Name, "�����", player.HP, player.Defence);

		//��� ����������� ���������� ����� ����� ��� �����
		if (player.haveCompanion) 
		{
			if (companion.Class == "����") {
				if (Random(0, 100) > 50) newTarget = Target(companion.Name, "���������", companion.HP, companion.Defence);
			}
			else if (Random(0, 100) > 85) newTarget = Target(companion.Name, "���������", companion.HP, companion.Defence);
		}

		int dmg = DecreaseDmgByDef(Enemies.at(i).Damage, newTarget.Defence);

		cout << "\n" << Enemies.at(i).Name << " ������� " << newTarget.Name;
		if (Random(0, 100) > 35) {
			cout << " � ������� ��� " << dmg << ".";
			newTarget.HP -= dmg;
			cout << " �������� " << newTarget.Name << ": " << newTarget.HP;
		}
		else cout << " � �������������.";

		if (newTarget.Type == "�����") {
			player.HP = newTarget.HP;
			CheckDeath(player);
		}
		else {
			companion.HP = newTarget.HP;
			CheckDeath(player, companion);
		}
	}
	cout << "\n\n ������� ����� �������, ����� �������� ���� ���.";
	GetKey();
}

void Combat(Player& player, Companion& companion, DungeonBoss& boss)
{
	while (!boss.isDead)
	{
		PlayerTurn(player, companion, boss);
		if (boss.isDead) break;
		EnemyTurn(player, companion, boss);
	}
	system("cls");
}

void PlayerTurn(Player& player, Companion& companion, DungeonBoss& boss)
{
	bool isActed = false;
	int Choice = 0;
	while (!isActed) {
		ShowBoss(boss);
		ShowHero(player, companion);

		cout << "\n";
		cout << "\n 1 --|====>\t��������� �����.";
		cout << "\n 2 --|====>\t������������ ������ ����.";
		cout << "\n 3 --|====>\t��������� ������� �� ���������.";
		cout << " \n";

		cout << "\n <-- �������� �������� -->\n";
		switch (ChoiceCheck(3)) {
		case 1:
		{
			if (Random(0, 100) > boss.EvasionChance)
			{
				boss.HP -= Random(player.MinDamage, player.Damage);
				cout << player.Name << " ������� " << boss.Name << " � ��������� ��� " << boss.HP << " ��������. ";
				CheckDeath(boss);
			}
			else cout << player.Name << " ������� " << boss.Name << " � �������������.\n";

			Sleep(1000);
			if (companion.CurAttackCount != 0 && Random(0, 100) > boss.EvasionChance)
			{
				boss.HP -= companion.Damage;
				cout << companion.Name << " ������� " << boss.Name << " � ��������� ��� " << boss.HP << " ��������. ";
				companion.CurAttackCount--;
				CheckDeath(boss);
			}
		}
		break;
		case 2:
		{
			if (player.Class == "����")
			{
				boss.HP -= 2 * player.Damage;
				cout << "\n\n" << player.Name << " ������� " << boss.Name << " ����������� ������ � ��������� ��� " << boss.HP << " ��������. ";
				CheckDeath(boss);
				isActed = true;
			}
			if (player.Class == "���")
			{
				if (player.Mana >= player.MaxMana / 2) {

					cout << "\n";
					cout << "\n " << player.Name << " ������� �������� ��� � ������� �� " << boss.Name << ".\n";
					player.Mana -= player.MaxMana / 2;
					boss.HP -= 3 * (player.MagicPower + player.Damage);
					cout << player.Name << " ������� " << (player.MagicPower + player.Damage) << " ����� " << boss.Name << " � ��������� ���" << boss.HP << " ��������. ";
					CheckDeath(boss);
					isActed = true;
				}
				else cout << "\n ������������ ���� ��� ���������� ������� ������. "
					<< "\n ����� ����� ������ �������� �� ������������� ������ ���� (" << player.MaxMana / 2 << ").";
			}
			if (player.Class == "������")
			{
				if (player.Mana >= 20)
				{
					player.Mana -= 20;
					int dealDamage = 2 * player.Damage + player.MagicPower;
					boss.HP -= dealDamage;
					cout << player.Name << " ������� " << boss.Name << " ������ ���������, �������� ��� " << boss.HP << " ��������. ";
					CheckDeath(boss);
					isActed = true;
				}
				else cout << "\n ������������ ���� ��� ���������� ������� ������ (����� ��-������� ���� 20 ����).";
			}
		}
		break;
		case 3:
		{
			cout << "\n\t<-- �������� ������� � ��������� -->";
			for (int i = 0; i < player.Inventory.size(); i++)
				cout << to_string(i + 1) << ". " << player.Inventory.at(i).Name << "\n";
			cout << to_string(player.Inventory.size() + 1) << ". �����";

			Choice = ChoiceCheck(player.Inventory.size() + 1);
			if (player.Inventory.at(Choice).Name == "�����")
			{
				player.HP += 50;
				companion.HP += 50;
				CheckGreaterPoints(player.HP, player.TotalHP);
				CheckGreaterPoints(companion.HP, companion.TotalHP);
				cout << "\n �� ������ �������� �����!";
				isActed = true;
			}
			else cout << "\n �� �� ������ ���� ��������� ���� �������";
		}
		break;
		}
	}
	cout << "\n\n ������� ����� �������, ����� �������� ��� ����������.";
	GetKey();
}

void EnemyTurn(Player& player, Companion& companion, DungeonBoss& boss)
{
	system("cls");
	cout << " \n";
	cout << " ��� ����������...\n";
	Sleep(1000);
	ShowHero(player, companion);

	if (boss.SpecialAbilityCooldown == 0)
	{
		cout << " " << boss.Name << " ��������� ������ \"" << SpecialAbilities[boss.IdSpecialAbility] << "\"!\n";
		switch (boss.IdSpecialAbility)
		{
		case 0:
		{

			if (Random(0, 100) > 50)
			{
				int dmg = DecreaseDmgByDef(boss.Damage * 2, player.Defence);
				player.HP -= dmg;
				cout << " " << boss.Name << " ����������� � ������� " << player.Name << " � ������� " << dmg << " �����.";
				cout << "\n ���� ��������: " << player.HP;
			}
			else
			{
				int dmg = DecreaseDmgByDef(boss.Damage * 2, companion.Defence);
				companion.HP -= dmg;
				cout << " " << boss.Name << " ����������� � ������� " << companion.Name << " � ������� " << dmg << " �����.";
				cout << "\n �������� " << companion.Name << ": " << companion.HP;
			}
			break;
		}
		case 1:
		{
			cout << " " << boss.Name << " �������� ���� ��� �����. �� �������� " << boss.Damage << " �����.";
			player.HP -= boss.Damage;
			companion.HP -= boss.Damage;
			cout << "\n ���� ��������: " << player.HP << ". �������� " << companion.Name << ": " << companion.HP;
			break;
		}
		case 2:
		{
			boss.Damage *= 2;
			cout << " " << boss.Name << " ������������ ��� ������ ���������� ��� ���� �����. ������� ����: " << boss.Damage;
			break;
		}
		case 3:
		{
			if (Random(0, 100) > 50)
			{
				player.HP -= boss.Damage;
				boss.HP += boss.Damage;

				cout << " " << boss.Name << " ���������� " << boss.Damage << " �������� �� " << player.Name;
				cout << "\n ���� ��������: " << player.HP;
				cout << "\n �������� " << boss.Name << ": " << boss.HP;
			}
			else
			{
				companion.HP -= boss.Damage;
				boss.HP += boss.Damage;
				cout << boss.Name << " ���������� " << boss.Damage << " �������� �� " << companion.Name;
				cout << "\n �������� " << companion.Name << ": " << companion.HP;
			}
			break;
		}
		case 4:
		{
			cout << " " << boss.Name << " �������� �� ����� � �������, �������������� ���� 60 ��������";
			boss.HP += 60;
			CheckGreaterPoints(boss.HP, boss.BaseHP);
			break;
		}
		}
		boss.SpecialAbilityCooldown = boss.Max_SpecialAbilityCooldown;
	}
	else
	{
		if (Random(0, 100) > 50)
		{
			int dmg = DecreaseDmgByDef(boss.Damage, player.Defence);
			cout << "\n " << boss.Name << " ������� " << player.Name << " � ������� " << dmg << " �����";
			cout << "\n ���� ��������: " << player.HP;
		}
		else
		{
			int dmg = DecreaseDmgByDef(boss.Damage, companion.Defence);
			cout << "\n " << boss.Name << " ������� " << companion.Name << " � ������� " << dmg << " �����";
			cout << "\n �������� " << companion.Name << ": " << companion.HP;
		}
		boss.SpecialAbilityCooldown--;
	}

	CheckDeath(player);
	CheckDeath(player, companion);
	cout << "\n\n ������� ����� �������, ����� �������� ���� ���.";
	GetKey();
}