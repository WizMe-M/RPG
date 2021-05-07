#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include "Helper.h"
using namespace std;

//�������� ������
class Player
{
public:
	string Name;
	string Class;
	int Level = 1;
	int MaxExp = 50;
	int Experience = 0;
	int TotalHP;
	int HP;
	int Damage;
	int MinDamage;
	int Defence;
	int MagicPower;
	int Mana;
	int MaxMana;
	int Gold;
	vector <Item> Inventory;
	int InventoryMaxCapacity;

	int HPperLVL;
	int DMGperLVL;
	int DEFperLVL;
	int MPperLVL;
	int MANAperLVL;
	bool haveCompanion = true;
	int SpecialAbilityCooldown = 0;
	//������� ����������� ������
	Player() {
		cout << " ������� ��� ���������: ";
		cin >> Name;
		cout << "\n �������� ����� ���������: \n\n";

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
		cout << "\n\t<-- ����� ������ --> ";
		
		switch (ChoiceCheck(3))
		{
		case 1:
		{
			//������� �����
			Class = "����";
			TotalHP = 120;
			MinDamage = 15;
			Damage = 20;
			Defence = 35;
			MagicPower = 0;
			Mana = 0;

			//����� �� ���
			HPperLVL = 25;
			DMGperLVL = 9;
			DEFperLVL = 10;
			MPperLVL = 0;
			MANAperLVL = 0;
			break;
		}
		case 2:
		{
			//������� �����
			Class = "������";
			TotalHP = 90;
			MinDamage = 25;
			Damage = 35;
			Defence = 5;
			MagicPower = 0;
			Mana = 25;

			//����� �� ���
			HPperLVL = 14;
			DMGperLVL = 13;
			DEFperLVL = 4;
			MPperLVL = 5;
			MANAperLVL = 10;
			break;
		}
		case 3:
		{
			//������� �����
			Class = "���";
			TotalHP = 80;
			MinDamage = 5;
			Damage = 10;
			Defence = 5;
			MagicPower = 20;
			Mana = 100;

			//����� �� ���
			HPperLVL = 5;
			DMGperLVL = 5;
			DEFperLVL = 0;
			MPperLVL = 15;
			MANAperLVL = 30;
			break;
		}
		}
		HP = TotalHP;
		MaxMana = Mana;
		Gold = 100;
		InventoryMaxCapacity = 10;
		Inventory.push_back(Item("�����", 0, 3));

		system("cls");
		cout << "\n\n\t������ ���������";
		for (int i = 0; i < 3; i++)
		{
			Sleep(600);
			cout << ".";
		}
		Sleep(100);

		system("cls");
		cout << " " << Name << " ��������������: \n";
		cout << " �����: " << Class << "\n";
		cout << " �������: " << Level << "\n";
		cout << " ����: " << Experience << " / " << MaxExp << "\n";
		cout << " ��������: " << HP << " / " << TotalHP << "\n";
		cout << " ����: " << (Damage + MinDamage) / 2 << "\n";
		cout << " ������: " << Defence << "\n";
		cout << " ���������� ����: " << MagicPower << "\n";
		cout << " ����: " << Mana << " / " << MaxMana << "\n";
		cout << " ������: " << Gold << "\n";
		cout << " \n";
		cout << " ������� ����� ������, ����� ����������" << endl;
		GetKey();
		system("cls");
	}
};



Player create();

