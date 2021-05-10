#pragma once
#include "Player.h"
#include <conio.h>
using namespace std;
Player create()
{
	Player player;
	cout << "\n\t<-- ������� ��� ��������� -->\n ";
	do {
		getline(cin, player.Name);

	} while (player.Name.empty());

	cout << "\n\n\t<-- �������� ����� ��������� -->\n\n";

	string ClassesDescription =
		" 1. ���� � ����� ������� ���������� �������� � ���������� ������, ������� ���������� �����, �� ��������� ����������� ���������� ����.\n\n"
		" 2. ������ � ������� ����, ������� ���������� ��������, ������ � ���������� ����, ������ ������� ������ ����.\n\n"
		" 3. ��� � ������ ���������� ��������, ������� ���������� ����� � ���������� ��� � ������, ������ �����"
		" ����� ������� ���������� ���������� ���� � �������� ������ ������� ����.\n\n";
	cout << ClassesDescription << " \n";


	int Choice = 0;

	cout << " 1 - ������� ����� '����'.\n";
	cout << " 2 - ������� ����� '������'.\n";
	cout << " 3 - ������� ����� '���'.\n";
	cout << " \n\n";

	cout << " <-- ����� ������ --> ";
	switch (ChoiceCheck(3))
	{
	case 1:
	{
		//������� �����
		player.Class = "����";
		player.TotalHP = 120;
		player.MinDamage = 15;
		player.Damage = 20;
		player.Defence = 35;
		player.MagicPower = 0;
		player.Mana = 0;

		//����� �� ���
		player.HPperLVL = 25;
		player.DMGperLVL = 9;
		player.DEFperLVL = 10;
		player.MPperLVL = 0;
		player.MANAperLVL = 0;
		break;
	}
	case 2:
	{
		//������� �����
		player.Class = "������";
		player.TotalHP = 90;
		player.MinDamage = 25;
		player.Damage = 35;
		player.Defence = 5;
		player.MagicPower = 0;
		player.Mana = 25;

		//����� �� ���
		player.HPperLVL = 14;
		player.DMGperLVL = 13;
		player.DEFperLVL = 4;
		player.MPperLVL = 5;
		player.MANAperLVL = 10;
		break;
	}
	case 3:
	{
		//������� �����
		player.Class = "���";
		player.TotalHP = 80;
		player.MinDamage = 5;
		player.Damage = 10;
		player.Defence = 5;
		player.MagicPower = 20;
		player.Mana = 100;

		//����� �� ���
		player.HPperLVL = 5;
		player.DMGperLVL = 5;
		player.DEFperLVL = 0;
		player.MPperLVL = 15;
		player.MANAperLVL = 30;
		break;
	}
	}
	player.HP = player.TotalHP;
	player.MaxMana = player.Mana;
	player.Gold = 100;
	player.InventoryMaxCapacity = 10;
	player.Inventory.push_back(Item("�����", 0, 3));
	player.haveCompanion = true;
	player.SpecialAbilityCooldown = 0;
	player.EnemiesKilledCount = 0;
	player.Level = 1;
	player.Experience = 0;
	player.MaxExp = 50;
	system("cls");
	cout << "\n\n\t������ ���������";
	for (int i = 0; i < 3; i++)
	{
		Sleep(600);
		cout << ".";
	}
	Sleep(100);
	system("cls");
	cout << " " << player.Name << " ��������������: \n";
	cout << " �����: " << player.Class << "\n";
	cout << " �������: " << player.Level << "\n";
	cout << " ����: " << player.Experience << " / " << player.MaxExp << "\n";
	cout << " ��������: " << player.HP << " / " << player.TotalHP << "\n";
	cout << " ����: " << (player.Damage + player.MinDamage) / 2 << "\n";
	cout << " ������: " << player.Defence << "\n";
	cout << " ���������� ����: " << player.MagicPower << "\n";
	cout << " ����: " << player.Mana << " / " << player.MaxMana << "\n";
	cout << " ������: " << player.Gold << "\n";
	cout << " \n";
	cout << " ������� ����� ������, ����� ����������" << endl;
	GetKey();
	system("cls");

	{
		//	char Intro[] = " �� ����������� � �������� ������, �������� �����-���� ������������ � ������� � ���, ��� ������ �� ���� ������. ����� � ����"
		//		" ����� ����� �������� ������������ ��������.\n";
		//	char Intro2[] = " ������� � ������ � �����������, ��������������� ����������, �� ���������, ��� �� ������"
		//		" � �������� ������ ������, � ����� ������� ��� � �������� � ����.\n";
		//	char Intro3[] = " ���������, ��� ��, ��� � ���������, ��������� ������� � ��� �������� � ������, ����������� ������ �� ������ �� �����������"
		//		" �������.\n";
		//	char Intro4[] = " ���������, �����-�� ������� ������������ ��������� ������ � ��������, �������, ��� ������ ��������� ���� ��������"
		//		" �����������, ���� ������������� ����� ����������� ����� ������, ���������� ���� ������������,\n"
		//		" �� ������� �������.\n";
		//	char Intro5[] = " ��������� ��������, ��� ������� ���������� ��, ��� ������ ����������. ���� ��������� ���������� �������� ������ ����,"
		//		" � ����� ��������� �������� ����������. ������ �� ����� �������, ��� ����� ����������\n ������������ � � ������ ����� ������������ ������"
		//		" ������������. ������ ������������ �������� ����������� ������ ��������, ������������, ���� � �����. � ����� ������ ������, � �������"
		//		" �� �������� �� �����\n ������������, ���������� ����� �������. ����� ������ �� ����� ������� ���������� � ����� � �����, ����, �������,"
		//		" �������� ����� ����� ������� ������. ��� ���� ��������� ������ �� ���, �����������, �������\n �������� � ��������� �������� �����-��"
		//		" ������, ������������ � ������� �����, � �������� �� ���, ��� ��������� � ���������������� �������� � ���.\n"
		//		" ��������� ����� �� ����� ������� ������������� ��������� � ���� ����, �� ����������� ��������� ������, ������� ����� �������� ���������"
		//		" ������ � ���� ���� ��������.\n";
		//	char Intro6[] = " � ������� ���������� �� ��������� ��������� ����� �� ������ ����� �����. ������� ������ � ����� ��������� ������,"
		//		" ������� ������ ��������� � �������. ��� ������ ��� ��������� ���� ���� ����-����� ��������\n ��������� ������ �� ���� ��������"
		//		" ����� ������������ �� ���������\n";
		//	char Intro7[] = " ��������� ���������� ��� ������ �� ���������, ������� ���� � ����� � ��������� �����������. �� ������������ � ���������� �"
		//		" ������ ������������� � ������� �����������, ��� �������� � �������� � ��� ���, � �\n"
		//		" ���������� ����������� �� ��������� ���� � ����� �����, � ����� ������� �� �������� ����� ������������� ����.\n";
		//	char Intro8[] = " ���������� �� ������, ������� ������������� ������ ��������� � ���� ������, �� � ��������� ��������� ����������� ������,"
		//		" ����������� ������ ������, ��������� �������� ��������� ������ � ��������� � �����\n ��������, ����� ������.\n";

		//	for (int i = 0; i < strlen(Intro); i++, Sleep(80))
		//		cout << Intro[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro2); i++, Sleep(80))
		//		cout << Intro2[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro3); i++, Sleep(80))
		//		cout << Intro3[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro4); i++, Sleep(80))
		//		cout << Intro4[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro5); i++, Sleep(80))
		//		cout << Intro5[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro6); i++, Sleep(80))
		//		cout << Intro6[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro7); i++, Sleep(80))
		//		cout << Intro7[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro8); i++, Sleep(80))
		//		cout << Intro8[i];
		//	Sleep(3000);
	}
	return player;
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
	} while (!input.find_first_not_of("0123456789") || input.empty());
	return stoi(input);
}
void GetKey() {
	int i = _getch();
}