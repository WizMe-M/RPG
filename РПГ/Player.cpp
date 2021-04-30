#include "Player.h"
#include <iostream>
#include "Windows.h"

using namespace std;

Player create()
{
	Player player;
	bool IsRunning = true;

	cout << " ������� ��� ���������: ";
	cin >> player.PlayerName;

	cout << " \n";

	player.PlayerHP = 100;
	player.PlayerLevel = 1;

	cout << " �������� ����� ���������: \n\n";

	string ClassesDescription[3] = { " 1. ���� � ����� ������� ���������� �������� � ���������� ������, ������� ���������� �����, ��"
		" ������ ���������� ������ � ���������� ���������� ����.\n\n"
		" 2. ������ � ������� ����, ������� ���������� �������� � ������, �� ����������� ���������� ���� � ����� ����� ������ ������.\n\n"
		" 3. ��� � ������� ���������� ��������, ������ ���������� ����� � ���������� ��� � ������. ������, ����� ����� ������� ����������"
		" ���������� ���� � ������." };

	for (int i = 0; i < 3; i++)
	{
		cout << ClassesDescription[i] << " \n";
	}

	int Choice = 0;

	cout << " 1 - ������� ����� '����'.\n";
	cout << " 2 - ������� ����� '������'.\n";
	cout << " 3 - ������� ����� '���'.\n";

	cout << " \n";

	while (Choice < 1 || Choice > 3) 
	{
		cout << " ����� ������: ";
		cin >> Choice;
	}

	switch (Choice)
	{ 
	case 1: 
	{ 
		player.PlayerClass = "����";
	} 
	break;
	case 2: 
	{ 
		player.PlayerClass = "������";
	} 
	break;
	case 3: 
	{ 
		player.PlayerClass = "���";
	} 
	break;
	default:
	{
		cout << " ������ ������ �� ����������.";
	}
	break;
	}

	cout << " ����� ������ ��������� - " << player.PlayerClass << ".\n";
	Sleep(3000);

	int Counter = 0;

	system("cls");

	for (int i = 0; i <= Counter; i++) 
	{
		if (i == 0)
			cout << " ������ ���������.\n";
		if (i == 1)
			cout << " ������ ���������..\n";
		if (i == 2) 
		{
			cout << " ������ ���������...\n";
			break;
		}

		Sleep(400);
		system("cls");
		Counter++;
	}

	if (player.PlayerClass == "����")
	{
		player.PlayerTotalHP = 120;
		player.PlayerHP = 120;
		player.PlayerMinDamage = 10;
		player.PlayerDamage = 15;
		player.PlayerDefence = 15;
		player.PlayerKnowledge = 10;
		player.PlayerMagicPower = 0;
		player.PlayerMana = 0;
		player.PlayerGold = 100;
		player.CurrentInventoryCapacity = 0;
		player.InventoryMaxCapacity = 15;

	}

	if (player.PlayerClass == "������")
	{
		player.PlayerTotalHP = 90;
		player.PlayerHP = 90;
		player.PlayerMinDamage = 15;
		player.PlayerDamage = 20;
		player.PlayerDefence = 5;
		player.PlayerKnowledge = 20;
		player.PlayerMagicPower = 0;
		player.PlayerMana = 0;
		player.PlayerGold = 100;
		player.CurrentInventoryCapacity = 0;
		player.InventoryMaxCapacity = 15;
	}

	if (player.PlayerClass == "���")
	{
		player.PlayerTotalHP = 80;
		player.PlayerHP = 80;
		player.PlayerMinDamage = 2;
		player.PlayerDamage = 5;
		player.PlayerDefence = 5;
		player.PlayerKnowledge = 30;
		player.PlayerMagicPower = 20;
		player.PlayerMana = 100;
		player.PlayerGold = 100;
		player.CurrentInventoryCapacity = 0;
		player.InventoryMaxCapacity = 15;
	}

	system("cls");

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

	Sleep(5000);

	system("cls");

	char Intro[] = " �� ����������� � �������� ������, �������� �����-���� ������������ � ������� � ���, ��� ������ �� ���� ������. ����� � ����"
		" ����� ����� �������� ������������ ��������.\n";
	char Intro2[] = " ������� � ������ � �����������, ��������������� ����������, �� ���������, ��� �� ������"
		" � �������� ������ ������, � ����� ������� ��� � �������� � ����.\n";
	char Intro3[] = " ���������, ��� ��, ��� � ���������, ��������� ������� � ��� �������� � ������, ����������� ������ �� ������ �� �����������"
		" �������.\n";
	char Intro4[] = " ���������, �����-�� ������� ������������ ��������� ������ � ��������, �������, ��� ������ ��������� ���� ��������"
		" �����������, ���� ������������� ����� ����������� ����� ������, ���������� ���� ������������,\n"
		" �� ������� �������.\n";
	char Intro5[] = " ��������� ��������, ��� ������� ���������� ��, ��� ������ ����������. ���� ��������� ���������� �������� ������ ����,"
		" � ����� ��������� �������� ����������. ������ �� ����� �������, ��� ����� ����������\n ������������ � � ������ ����� ������������ ������"
		" ������������. ������ ������������ �������� ����������� ������ ��������, ������������, ���� � �����. � ����� ������ ������, � �������"
		" �� �������� �� �����\n ������������, ���������� ����� �������. ����� ������ �� ����� ������� ���������� � ����� � �����, ����, �������,"
		" �������� ����� ����� ������� ������. ��� ���� ��������� ������ �� ���, �����������, �������\n �������� � ��������� �������� �����-��"
		" ������, ������������ � ������� �����, � �������� �� ���, ��� ��������� � ���������������� �������� � ���.\n"
		" ��������� ����� �� ����� ������� ������������� ��������� � ���� ����, �� ����������� ��������� ������, ������� ����� �������� ���������"
		" ������ � ���� ���� ��������.\n";
	char Intro6[] = " � ������� ���������� �� ��������� ��������� ����� �� ������ ����� �����. ������� ������ � ����� ��������� ������,"
		" ������� ������ ��������� � �������. ��� ������ ��� ��������� ���� ���� ����-����� ��������\n ��������� ������ �� ���� ��������"
		" ����� ������������ �� ���������\n";
	char Intro7[] = " ��������� ���������� ��� ������ �� ���������, ������� ���� � ����� � ��������� �����������. �� ������������ � ���������� �"
		" ������ ������������� � ������� �����������, ��� �������� � �������� � ��� ���, � �\n"
		" ���������� ����������� �� ��������� ���� � ����� �����, � ����� ������� �� �������� ����� ������������� ����.\n";
	char Intro8[] = " ���������� �� ������, ������� ������������� ������ ��������� � ���� ������, �� � ��������� ��������� ����������� ������,"
		" ����������� ������ ������, ��������� �������� ��������� ������ � ��������� � �����\n ��������, ����� ������.\n";

	for (int i = 0; i < strlen(Intro); i++, Sleep(100))
		cout << Intro[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro2); i++, Sleep(100))
		cout << Intro2[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro3); i++, Sleep(100))
		cout << Intro3[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro4); i++, Sleep(100))
		cout << Intro4[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro5); i++, Sleep(100))
		cout << Intro5[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro6); i++, Sleep(100))
		cout << Intro6[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro7); i++, Sleep(100))
		cout << Intro7[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro8); i++, Sleep(100))
		cout << Intro8[i];
	Sleep(3000);

	system("cls");

	return player;
}


