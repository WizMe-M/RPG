#include "Combat.h"
#include <iostream>
#include "Windows.h"
#include "Player.h"
#include "Helper.h"

using namespace std;

using std::string;

int Combat(Squad& newSquad, Unit& newUnit, Enemy& newEnemy, Player& player)
{
	system("cls");

	newUnit.UntiHP[1] = player.PlayerHP;

	cout << " " << player.PlayerName << " ��������������: \n";
	cout << " �����: " << player.PlayerClass << "\n";
	cout << " ��������: " << player.PlayerHP << "\n";
	cout << " ����: " << (player.PlayerDamage + player.PlayerMinDamage) / 2 << "\n";
	cout << " ������: " << player.PlayerDefence << "\n";
	cout << " ���������: " << player.PlayerKnowledge << "\n";
	cout << " ���������� ����: " << player.PlayerMagicPower << "\n";
	cout << " ����: " << player.PlayerMana << "\n";
	cout << " ������: " << player.PlayerGold << "\n";

	cout << " \n";

	cout << " ���� ����������: \n";

	for (int i = 0; i < newEnemy.EnemyQuantity; i++) 
	{
		cout << newEnemy.EnemyName[i] << "  HP: " << newEnemy.EnemyHP[i] << " \n";
	}

	int Choice = 0;
	int RandEnemy = 0;
	int UnitUnderAttack = 0;
	int RandEnemyAttack = 0;
	bool isAccept = false;

	Sleep(3000);

	while (newEnemy.LastQuantity != 0)
	{
		system("cls");

		cout << " \n";

		cout << " ����� ����������: \n";

		cout << " ���������� �����������: " << newEnemy.LastQuantity << "\n";
		for (int i = 0; i < newEnemy.EnemyQuantity; i++) 
		{
			cout << newEnemy.EnemyName[i] + " HP:  " << newEnemy.EnemyHP[i] << " | ";
		}

		cout << " \n";
		cout << " \n";

		cout << " ��� ���, �������� ���������� ����� ������: \n";

		for (int i = 0; i < newSquad.SquadQuantity; i++)
		{
			cout << newSquad.SquadNames[i] << "  HP:  " << newUnit.UntiHP[i] << "/" << newUnit.UnitTotalHP[i] << " | ";
		}

		cout << "\n 6. ������ �����.";
		cout << "\n 7. ������������ ������ ����.";

		cout << " \n";

		cout << "\n �����: ";
		cin >> Choice;

		cout << " \n";

		cout << "\n ����� ���������� ��� �����:";
		cin >> RandEnemyAttack;
		RandEnemyAttack = RandEnemyAttack - 1;

		if (Choice == 1)
		{
			if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "̨���") 
			{
				newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(10, newUnit.UntiDamage[0]);
				cout << newUnit.UnitName[0] << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " � ��������� ��� "
					<< newEnemy.EnemyHP[RandEnemyAttack] << " ��������. ";

				if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
				{ 
					newEnemy.LastQuantity--; 
					newEnemy.EnemyName[RandEnemyAttack] = "̨���";
				};
			}
			else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "̨���")
			{ 
				cout << newUnit.UnitName[0] << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " � ������������� ";
			}
			else 
			{ 
				cout << " ��������� ������� ������, �� �������������� �� �������."; 
			}
		}

		if (Choice == 2) 
		{

			if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "̨���")
			{
				newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(player.PlayerMinDamage, player.PlayerDamage);
				cout << player.PlayerName << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " � ��������� ��� "
					<< newEnemy.EnemyHP[RandEnemyAttack] << " ��������. ";
				if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
				{ 
					newEnemy.LastQuantity--; 
					newEnemy.EnemyName[RandEnemyAttack] = "̨���";
				};
			}
			else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "̨���") 
			{ 
				cout << newUnit.UnitName[1] << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " � ������������� ";
			}
			else 
			{ 
				cout << " ��������� ������� ������, �� �������������� �� �������."; 
			}
		}

		if (Choice == 3)
		{
			if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "̨���") 
			{
				newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(10, newUnit.UntiDamage[2]);
				cout << newUnit.UnitName[2] << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " � ��������� ��� "
					<< newEnemy.EnemyHP[RandEnemyAttack] << " ��������. ";

				if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
				{
					newEnemy.LastQuantity--; 
					newEnemy.EnemyName[RandEnemyAttack] = "̨���";
				};
			}
			else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "̨���") 
			{ 
				cout << newUnit.UnitName[2] << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " � ������������� ";
			}
			else 
			{ 
				cout << " ��������� ������� ������, �� �������������� �� �������."; 
			}
		}

		if (Choice == 4)
		{
			if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "̨���") 
			{
				newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(10, newUnit.UntiDamage[3]);
				cout << newUnit.UnitName[3] << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " � ��������� ��� "
					<< newEnemy.EnemyHP[RandEnemyAttack] << " ��������. ";

				if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
				{ 
					newEnemy.LastQuantity--; 
					newEnemy.EnemyName[RandEnemyAttack] = "̨���";
				};
			}
			else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "̨���") 
			{ 
				cout << newUnit.UnitName[3] << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " � ������������� ";
			}
			else 
			{ 
				cout << " ��������� ������� ������, �� �������������� �� �������."; 
			}
		}

		if (Choice == 5)
		{
			if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "̨���")
			{
				newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(10, newUnit.UntiDamage[4]);
				cout << newUnit.UnitName[4] << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " � ��������� ��� "
					<< newEnemy.EnemyHP[RandEnemyAttack] << " ��������. ";

				if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
				{ 
					newEnemy.LastQuantity--; 
					newEnemy.EnemyName[RandEnemyAttack] = "̨���";
				};
			}
			else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "̨���") 
			{ 
				cout << newUnit.UnitName[4] << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " � ������������� ";
			}
			else 
			{ 
				cout << " ���������� ������� ������, �� �������������� �� �������."; 
			}
		}

		if (Choice == 6)
		{
			isAccept = false;
			int i = 0;

			for (int i = 0; i < player.CurrentInventoryCapacity; i++)
			{
				if (player.Inventory[i] == "�����" && player.Inventory[i] != "�����")
				{
					player.Inventory[i] = "�����";

					isAccept = true;
					break;
				}
			}

			if (isAccept == true) 
			{
				for (int i = 0; i < newSquad.SquadQuantity; i++)
				{
					newUnit.UntiHP[i] = newUnit.UntiHP[i] + 20.0;

					if (newUnit.UntiHP[i] > newUnit.UnitTotalHP[i]) { newUnit.UntiHP[i] = newUnit.UnitTotalHP[i]; }
				}

				cout << "\n �� ������ �������� �����!"; 
				Sleep(2000);
			}
			else 
			{
				cout << "\n � ��� � ��������� ��� ������!"; 
				Sleep(2000);
			}
		}

		if (Choice == 7) 
		{
			if (player.PlayerClass == "����")
			{
				if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "̨���") 
				{
					newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(player.PlayerMinDamage, player.PlayerDamage);
					cout << player.PlayerName << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " ����������� ������ � ��������� ��� "
						<< newEnemy.EnemyHP[RandEnemyAttack] << " ��������. ";
					if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
					{ 
						newEnemy.LastQuantity--;
						newEnemy.EnemyName[RandEnemyAttack] = "̨���"; 
					};
				}
				else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "̨���") 
				{ 
					cout << newUnit.UnitName[1] << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " � ������������� ";
				}
				else 
				{ 
					cout << " ��������� ������� ������, �� �������������� �� �������."; 
				}
			}

			if (player.PlayerClass == "���")
			{
				if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "̨���") 
				{
					newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(player.PlayerMinDamage, player.PlayerDamage);
					cout << player.PlayerName << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " �������� ����� � ��������� ��� "
						<< newEnemy.EnemyHP[RandEnemyAttack] << " ��������. ";
					if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
					{ 
						newEnemy.LastQuantity--; 
						newEnemy.EnemyName[RandEnemyAttack] = "̨���";
					};
				}
				else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "̨���") 
				{ 
					cout << newUnit.UnitName[1] << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " � ������������� ";
				}
				else 
				{ 
					cout << " ��������� ������� ������, �� �������������� �� �������."; 
				}
			}

			if (player.PlayerClass == "������")
			{
				if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "̨���") 
				{
					newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(player.PlayerMinDamage, player.PlayerDamage);
					cout << player.PlayerName << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " ���������  "
						<< newEnemy.EnemyHP[RandEnemyAttack] << " ��������. ";
					if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
					{ 
						newEnemy.LastQuantity--; 
						newEnemy.EnemyName[RandEnemyAttack] = "̨���";
					};
				}
				else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "̨���") 
				{ 
					cout << newUnit.UnitName[1] << " ������� " << newEnemy.EnemyName[RandEnemyAttack] << " � ������������� ";
				}
				else 
				{ 
					cout << " ��������� ������� ������, �� �������������� �� �������."; 
				}
			}
		}

		cout << " \n";

		cout << " ��� ����������...\n";

		RandEnemy = Random(0, newEnemy.EnemyQuantity);
		UnitUnderAttack = Random(0, newSquad.SquadQuantity);

		if ((Random(1, 10) >= 4) && (newEnemy.EnemyName[RandEnemy] != "̨���") && (newUnit.UnitName[UnitUnderAttack] != "����"))
		{
			newUnit.UntiHP[UnitUnderAttack] = newUnit.UntiHP[UnitUnderAttack] - newEnemy.EnemyDamage[RandEnemy];
			cout << newEnemy.EnemyName[RandEnemy] << " ������� " << newUnit.UnitName[UnitUnderAttack] << " � ��������� ��� "
				<< newUnit.UntiHP[UnitUnderAttack] << " ��������.";

			if (newUnit.UntiHP[UnitUnderAttack] < 1)
			{
				newSquad.SquadTotalNumber--;
				newUnit.UnitName[UnitUnderAttack] = "����";
			}
		}
		else if (Random(1, 10) < 4 && newEnemy.EnemyName[RandEnemy] != "̨���") 
		{ 
			cout << newEnemy.EnemyName[RandEnemy] << " ������� " << newUnit.UnitName[UnitUnderAttack] << " � ������������� ";
		}
		else cout << " ��������� ���������� ���, ��� ��� ��������� � ��� ���� ����.";

		Sleep(3000);
	}

	system("cls");

	if (newEnemy.EnemyQuantity == 0 && newEnemy.EnemyClass[0] == "�����")
	{
		int Gold = Random(50, 100);
		player.PlayerGold = player.PlayerGold + Gold;
		player.PlayerLevel = player.PlayerLevel + 0.5;

		cout << " \n";

		cout << " ������!. �������: " << Gold << " ������.\n ";
		cout << " ����: " << player.PlayerLevel << "\n";
		cout << " ����� ���������� ������: " << player.PlayerGold;

		cout << " \n";

		Sleep(3000);

		return 1;
	}
	else if (newEnemy.EnemyQuantity == 0 && newEnemy.EnemyClass[0] == "�������")
	{
		int Gold = Random(100, 150);
		player.PlayerGold = player.PlayerGold + Gold;
		player.PlayerLevel = player.PlayerLevel + 0.5;

		cout << " \n";

		cout << " ������!. �������: " << Gold << " ������.\n ";
		cout << " ����: " << player.PlayerLevel << "\n";
		cout << " ����� ���������� ������: " << player.PlayerGold;

		cout << " \n";

		Sleep(3000);

		return 1;
	}
	else if (newSquad.SquadTotalNumber == 0)
	{
		system("cls");

		cout << " ���������! �� ������� ������ � �������.";
	}
	else 
	{
		int Gold = Random(20, 50);
		player.PlayerGold = player.PlayerGold + Gold;
		player.PlayerLevel = player.PlayerLevel + 0.5;

		cout << " \n";

		cout << " ������! �������: " << Gold << " ������.\n ";
		cout << " ����: " << player.PlayerLevel << "\n";
		cout << " ����� ���������� ������: " << player.PlayerGold;

		cout << " \n";

		Sleep(3000);

		return 1;
	}
}
