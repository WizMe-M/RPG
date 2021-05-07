#pragma once
#include <string>
using namespace std;

//���� �����������
const string Races[8]{ "�����", "�������", "��������", "������", "�����", "������", "�����", "�����" };

//���������, ����������� ������ ������
class Enemy
{
public:
	string Name;
	int RaceType;
	string Race;
	int HP;
	int BaseHP;
	int Damage;
	int Level;
	Enemy(string name, int raceType, int fullhp, int damage, int level) {
		Name = name;
		RaceType = raceType;
		Race = Races[RaceType];
		BaseHP = fullhp;
		HP = fullhp;
		Damage = damage;
		Level = level;
	}
};

