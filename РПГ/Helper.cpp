#include "Helper.h"
#include "Player.h"
#include "Combat.h"
#include "Windows.h"
#include <conio.h>
#include <ctime>
#include <iostream>

using namespace std;
using std::string;

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

bool CheckDeath(Enemy& newEnemy, int i) 
{
	if (newEnemy.EnemyHP[i] < 0) 
	{
		return true;
	}
	return false;
}

int ChoiceCheck(int max) 
{
	int Choice = 0;

	while (Choice > max || Choice <= 0) 
	{
		cout << " \n";

		cout << " �����: ";
		cin >> Choice;
	}

	return Choice;
}

bool CheckMoney(int Gold, int price) 
{
	if (Gold >= price) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BuyItems(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	cout << " 1. ������ ����������.\n";
	cout << " 2. ������� ����������. \n";

	bool isBuying = true;
	
	cout << " \n";

	switch (ChoiceCheck(2))
	{
	case 1: 
	{
		while (isBuying == true)
		{
			system("cls");

			cout << " ��������� ������: \n";

			int k = 1;

			for (int i = 0; i < 5; i++) 
			{
				cout << " " << std::to_string(k) + ".  �����: " << newShop.BuyItemName[i] << " | ����������: " << newShop.ItemQuantity[i]
					<< " | ����: " << newShop.ItemPrice[i] << "\n";
				k++;
			}

			cout << " \n";

			cout << " 6. ��������� � �������\n";

			switch (ChoiceCheck(6))
			{
			case 1: 
			{
				if (newShop.ItemQuantity[0] > 0) {
					if (CheckMoney(player.PlayerGold, 300) == true)
					{
						if (player.CurrentInventoryCapacity < player.InventoryMaxCapacity)
						{
							player.Inventory[player.CurrentInventoryCapacity] = " �����";
							player.CurrentInventoryCapacity++;

							newShop.ItemQuantity[0] = newShop.ItemQuantity[0] - 1;

							cout << "\n ����� ������."; 
							Sleep(2000);
						}
						else 
						{
							cout << " ������������ ����� � ���������."; 
							break;  
							Sleep(2000);
						}
					}
					else 
					{
						cout << " ������������ ������!"; Sleep(2000);
					}
				}
				else 
				{ 
					cout << " ������ �������: �� ������� ���������� ���� �����, ������� �����!"; 
					Sleep(2000); 
				}
			} 
			break;
			case 2: 
			{
				if (newShop.ItemQuantity[0] > 0)
				{
					if (CheckMoney(player.PlayerGold, 1500) == true)
					{
						if (player.CurrentInventoryCapacity < player.InventoryMaxCapacity)
						{
							player.CurrentInventoryCapacity++;
							player.Inventory[player.CurrentInventoryCapacity] = " ������";

							newShop.ItemQuantity[0] = newShop.ItemQuantity[0] - 1;

							cout << "\n ����� ������."; Sleep(2000);
						}
						else 
						{
							cout << " ������������ ����� � ���������."; 
							Sleep(2000);
						}
					}
					else 
					{
						cout << " ������������ ������!"; 
						Sleep(2000);
					}
				}
				else 
				{ 
					cout << " ������ �������: �� ������� ���������� ���� �����, ������� �����!"; 
					Sleep(2000); 
				}
			} 
			break;
			case 3: 
			{
				if (newShop.ItemQuantity[2] > 0)
				{
					if (CheckMoney(player.PlayerGold, 1000) == true)
					{


						if (player.CurrentInventoryCapacity < player.InventoryMaxCapacity)
						{
							player.CurrentInventoryCapacity++;
							player.Inventory[player.CurrentInventoryCapacity] = " ������";

							newShop.ItemQuantity[2] = newShop.ItemQuantity[2] - 1;

							cout << "\n ����� ������."; 
							Sleep(2000);
						}
						else
						{
							cout << " ������������ ����� � ���������.";
							Sleep(2000);
						}
					}
					else 
					{
						cout << " ������������ ������!"; 
						Sleep(2000);
					}
				}
				else 
				{ 
					cout << " ������ �������: �� ������� ���������� ���� �����, ������� �����!"; 
					Sleep(2000); 
				}
			} 
			break;
			case 4: 
			{
				if (newShop.ItemQuantity[3] > 0)
				{
					if (CheckMoney(player.PlayerGold, newShop.ItemPrice[3]) == true)
					{
						if (player.CurrentInventoryCapacity < player.InventoryMaxCapacity)
						{
							player.CurrentInventoryCapacity++;
							player.Inventory[player.CurrentInventoryCapacity] = " ����������";

							newShop.ItemQuantity[0] = newShop.ItemQuantity[0] - 1;

							cout << "\n ����� ������."; 
							Sleep(2000);
						}
						else 
						{
							cout << " ������������ ����� � ���������."; 
							Sleep(2000);
						}
					}
					else 
					{
						cout << " ������������ ������!"; 
						Sleep(2000);
					}
				}
				else 
				{ 
					cout << " ������ �������: �� ������� ���������� ���� �����, ������� �����!"; 
					Sleep(2000); 
				}
			} 
			break;
			case 5: 
			{
				if (newShop.ItemQuantity[4] > 0)
				{
					if (CheckMoney(player.PlayerGold, newShop.ItemPrice[4]) == true)
					{
						if (player.CurrentInventoryCapacity < player.InventoryMaxCapacity)
						{
							player.CurrentInventoryCapacity++;
							player.Inventory[player.CurrentInventoryCapacity] = " �����";

							newShop.ItemQuantity[0] = newShop.ItemQuantity[0] - 1;

							cout << "\n ����� ������."; 
							Sleep(2000);
						}
						else 
						{
							cout << " ������������ ����� � ���������."; 
							Sleep(2000);
						}
					}
					else 
					{
						cout << " ������������ ������!"; 
						Sleep(2000);
					}
				}
				else 
				{ 
					cout << " ������ �������: �� ������� ���������� ���� �����, ������� �����!"; 
					Sleep(2000); 
				}
			} 
			break;
			case 6: 
			{ 
				Tavern(player, newUnit, newSquad, newShop);
				isBuying = false;
			} 
			break;
			}
		}
	} 
	break;
	}
}

void BuyMercenaries(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	bool isBuying = true;
	string naem[3] = { "�����", "�����", "������" };

	while (isBuying == true)
	{
		system("cls");

		for (int i = 0; i < 3; i++) 
		{
			if (naem[i] != "�������") 
			{
				cout << " " << naem[i];
				if (naem[i] == "�����") 
				{ 
					cout << "- 1000 ������\n"; 
				}
				else if (naem[i] == "�����") 
				{ 
					cout << "- 2000 ������\n"; 
				}
				else if (naem[i] == "������") 
				{ 
					cout << "- 5000 ������\n"; 
				}
			}
		}

		cout << " \n";

		cout << " 4. �����\n";

		cout << " �����: ";
		int Choice = 0;
		cin >> Choice;

		switch (Choice) 
		{
		case 1:
		{
			if (naem[0] != "�������" && CheckMoney(player.PlayerGold, 1000) == true)
			{
				cout << " �� ��������� ������� �� 1000 ������.";
				player.PlayerGold = player.PlayerGold - 1000;
				naem[0] = "�������";

				newUnit.UnitName[2] = "�����";
				newUnit.UnitTotalHP[2] = 200;
				newUnit.UntiDamage[2] = 20.0;
				newUnit.UntiHP[2] = 200;
				newUnit.UnitClass[2] = "������";

				newSquad.SquadQuantity = newSquad.SquadQuantity + 1;
				newSquad.SquadTotalNumber = newSquad.SquadTotalNumber + 1;
				newSquad.SquadNames[2] = "�����";
			}
			else 
			{
				cout << " ������������ ������ ��� ������ ��� �����."; 
				Sleep(3000);
				Tavern(player, newUnit, newSquad, newShop);
			}
		}
		break;
		case 2:
		{
			if (naem[1] != "�������" && CheckMoney(player.PlayerGold, 1000) == true)
			{
				cout << " �� ��������� ������ �� 2000 ������.";
				player.PlayerGold = player.PlayerGold - 2000;
				naem[1] = "�������";

				newUnit.UnitName[3] = "�����";
				newUnit.UnitTotalHP[3] = 200;
				newUnit.UntiDamage[3] = 20.0;
				newUnit.UntiHP[3] = 300;
				newUnit.UnitClass[3] = "������";

				newSquad.SquadQuantity = newSquad.SquadQuantity + 1;
				newSquad.SquadTotalNumber = newSquad.SquadTotalNumber + 1;
				newSquad.SquadNames[3] = "�����";
			}
			else 
			{
				cout << " ������������ ������ ��� ������ ��� �����."; 
				Sleep(3000);  
				Tavern(player, newUnit, newSquad, newShop);
			}
		} 
		break;
		case 3:
		{
			if (naem[2] != "�������" && CheckMoney(player.PlayerGold, 1000) == true) {
				cout << " �� ��������� ������� �� 5000 ������.";
				player.PlayerGold = player.PlayerGold - 5000;
				naem[2] = "�������";

				newUnit.UnitName[4] = "������";
				newUnit.UnitTotalHP[4] = 200;
				newUnit.UntiDamage[4] = 50.0;
				newUnit.UntiHP[4] = 200;
				newUnit.UnitClass[4] = "���";

				newSquad.SquadQuantity = newSquad.SquadQuantity + 1;
				newSquad.SquadTotalNumber = newSquad.SquadTotalNumber + 1;
				newSquad.SquadNames[4] = "������";
			}
			else 
			{ 
				cout << " ������������ ������ ��� ������ ��� �����."; 
				Sleep(3000);  
				Tavern(player, newUnit, newSquad, newShop); }
		} 
		break;
		case 4:
		{
			isBuying = false; MainMenu(player, newUnit, newSquad, newShop);
		} 
		break;
		}
	}
}

void Dungeon(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	switch (Random(1, 3)) 
	{
	case 1:
	{
		cout << " � ������� ������� ���������� ������� �����. ����� ��������, ��� �� ���������. ���� ��������?\n";
		cout << " 1. ���������\n";
		cout << " 2. ������\n";

		cout << " \n";

		switch (ChoiceCheck(2))
		{
		case 1: 
		{
			player.PlayerHP = player.PlayerHP - Random(5, 10);
			cout << "\n ����� ��������� � ������� � ������ ����� �� ���!. ��� ����� ��� � ��������� ���: " << player.PlayerHP << ".\n";
		} 
		break;
		case 2:
		{
			cout << "\n �� ������ ����������� ��������.";
		} 
		break;
		}

		cout << "\n �� ���������� ������� � �������� ��������� �����. ���������� ���..."; 
		Sleep(3000);

		Enemy newEnemy;
		newEnemy.LastQuantity = 5;
		newEnemy.EnemyQuantity = 5;
		int k = 1;

		for (int i = 0; i < newEnemy.EnemyQuantity; i++) {

			string names = " �����(" + std::to_string(k) + ")";
			newEnemy.EnemyName[i] = names;
			newEnemy.EnemyClass[i] = "�������";
			newEnemy.EnemyHP[i] = 20.0;
			newEnemy.EnemyDamage[i] = 7.0;
			k++;
		}

		Combat(newSquad, newUnit, newEnemy, player);
	} 
	break;
	case 2:
	{
		cout << "\n �� ���������� ������� ������. �� ��������� ����������� �����, �������� ���� �������� ������-������. ���������� ���..."; 
		Sleep(3000);

		Enemy newEnemy;
		newEnemy.LastQuantity = 2;
		newEnemy.EnemyQuantity = 2;
		int k = 1;

		for (int i = 0; i < newEnemy.EnemyQuantity; i++) 
		{

			string names = " �����-�����(" + std::to_string(k) + ")";
			newEnemy.EnemyName[i] = names;
			newEnemy.EnemyClass[i] = "�����";
			newEnemy.EnemyHP[i] = 80.0;
			newEnemy.EnemyDamage[i] = 4.0;
			k++;
		}
		Combat(newSquad, newUnit, newEnemy, player);
	} 
	break;
	case 3:
	{
		cout << "\n ������ ����� �����, �� ��������� � ����������� �����, ��������� � �������� ��� ������.  ���� � ����� ����������� �����-������."
			" ���������� ���..."; 
		Sleep(3000);

		Enemy newEnemy;
		newEnemy.LastQuantity = 2;
		newEnemy.EnemyQuantity = 2;
		int k = 1;

		for (int i = 0; i < newEnemy.EnemyQuantity; i++) {

			string names = " �����-�����(" + std::to_string(k) + ")";
			newEnemy.EnemyName[i] = names;
			newEnemy.EnemyClass[i] = "�����";
			newEnemy.EnemyHP[i] = 50.0;
			newEnemy.EnemyDamage[i] = 8.0;
			k++;
	}
		Combat(newSquad, newUnit, newEnemy, player);
	} 
	break;
	}

	system("cls");
	cout << "\n ������ ����� ��������� �������, ����������� �����. ��� ������� ������. �� ���������� ������� ��������� � �����.";
	Sleep(3000);

	MainMenu(player, newUnit, newSquad, newShop);
}

void HeroArmy(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	cout << " ����� " << player.PlayerName << ": ";

	cout << " \n";

	for (int i = 0; i < newSquad.SquadQuantity; i++) {
		cout << " ���: " << newUnit.UnitName[i] << " | ��������: " << newUnit.UntiHP[i] << "/" << newUnit.UnitTotalHP[i]
			<< " | ����: " << newUnit.UntiDamage[i] << " | �����: " << newUnit.UnitClass[i] << "\n";
		cout << " \n";
	}

	cout << " 1. ����������. \n";

	cout << " �����: ";
	int Choice = 0;
	cin >> Choice;

	switch (Choice) 
	{
	case 1: 
	{
		MainMenu(player, newUnit, newSquad, newShop); 
	} 
	break;
	}
}

void HeroStats(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	cout << " �������������� " << player.PlayerName << ": \n";
	cout << " �����: " << player.PlayerClass << "\n";
	cout << " �������: " << player.PlayerLevel << "\n";
	cout << " ��������: " << player.PlayerHP << "\n";
	cout << " ����: " << player.PlayerDamage << "\n";
	cout << " ������: " << player.PlayerDefence << "\n";
	cout << " ���������: " << player.PlayerKnowledge << "\n";
	cout << " ���������� ����: " << player.PlayerMagicPower << "\n";
	cout << " ����: " << player.PlayerMana << "\n";
	cout << " ������: " << player.PlayerGold << "\n";

	cout << " \n";

	cout << " 1. ����������. \n";

	cout << " �����: ";
	int Choice = 0;
	cin >> Choice;
	switch (Choice) 
	{
	case 1: 
	{
		MainMenu(player, newUnit, newSquad, newShop); 
	}
	break;
	}
}

void Inventory(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	cout << " ���������: \n";

	for (int i = 0; i < player.CurrentInventoryCapacity; i++)
	{
		cout << player.Inventory[i] << " |";
	}

	switch (ChoiceCheck(1))
	{
	case 1: 
	{
		MainMenu(player, newUnit, newSquad, newShop); 
	}
	break;
	}
}

void RestInTavern(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	if (CheckMoney(player.PlayerGold, 10) == true) 
	{
		player.PlayerGold = player.PlayerGold - 10;
		player.PlayerHP = player.PlayerTotalHP;
		cout << " �� ���������.";
	}
	else
	{
		cout << " ������ �������: �������������, ����� ����� ������, ���������!";
	}

	cout << " \n";

	switch (ChoiceCheck(1))
	{
	case 1: 
	{
		MainMenu(player, newUnit, newSquad, newShop); 
	} 
	break;
	}
}

void Tavern(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop) 
{
	system("cls");

	cout << " ������ �������: ����� ���������� � ��� �������, �����! ����� ��� ���� �������� ����, ��� � ����������.\n";
	cout << " 1. ��������� ����������.\n";
	cout << " 2. ������ �����.\n";
	cout << " 3. ��������� (10 ������, ��������������� ��������).\n";
	cout << " 4. ��������� � ������� ����";
	
	cout << " \n";

	switch (ChoiceCheck(4))
	{
	case 1: 
	{ 
		BuyItems(player, newUnit, newSquad, newShop); 
	} 
	break;
	case 2: 
	{ 
		BuyMercenaries(player, newUnit, newSquad, newShop);  
	} 
	break;
	case 3: 
	{ 
		RestInTavern(player, newUnit, newSquad, newShop); 
	}
	break;
	case 4: 
	{ 
		MainMenu(player, newUnit, newSquad, newShop); 
	} 
	break;
	}
}

void MainMenu(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	cout << " " << player.PlayerName << ", �������� ��������: \n";
	cout << " 1. �������� �������.\n";
	cout << " 2. ����������� ����������.\n";
	cout << " 3. �������������� �����\n";
	cout << " 4. ����� �����.\n";
	cout << " 5. ���������.\n";

	cout << " \n";

	cout << " �����: ";
	int Choice = 0;
	cin >> Choice;

	switch (Choice)
	{
	case 1: 
	{ 
		Tavern(player, newUnit, newSquad, newShop);  
	} 
	break;
	case 2: 
	{ 
		Dungeon(player, newUnit, newSquad, newShop);  
	} 
	break;
	case 3: 
	{ 
		HeroStats(player, newUnit, newSquad, newShop); 
	} 
	break;
	case 4: 
	{ 
		HeroArmy(player, newUnit, newSquad, newShop);  
	} 
	break;
	case 5: 
	{ 
		Inventory(player, newUnit, newSquad, newShop);
	}
	break;
	}
}
