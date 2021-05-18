#pragma once
#include <string>
#include <windows.h>
#include <iostream>

#include "Boss.h"
#include "Reward.h"
#include "Enemy.h"
#include "Player.h"
#include "Companion.h"


//Combat. ������������ ������� �� ������ �����������
Reward CalculateReward(double difficulty, vector<Enemy>& deadEnemies);
//Combat. ������������ ������� �� �����
Reward CalculateReward(double difficulty, DungeonBoss boss);

//ChooseRandomGloor. �������������� ������ ������� �� ����  
void GiveReward(Player& player, Reward reward);
//GiveReward. ���� ������ ���������� �����, ����������� �������� ��������� ������
void LevelUp(Player& player);

//Combat. ������� ��������� ���� �� �������
int DecreaseDmgByDef(int damage, int defence);

//Helper. ������ �� ����� (������������) �� ������� ����� (�� ������������)
int Random(int min, int max);

//Combat. ��������� "������" ����������, ������������� ��������� ��� ��������� ��� �������, ��������� ���������� "�����" �����������
bool CheckDeath(vector<Enemy>& Enemies, vector<Enemy>& DeadEnemies, int id);
//Combat. ��������� ��� �� ����� � ���� ���, ������� ���������� � ��������� ����
void CheckDeath(Player player);
//Combat. ��������� ��� �� ��������� ������
void CheckDeath(Player& p, Companion& c);
//Combat. ��������� ��� �� ����� � ���� ���, ������� ���������� � ��������� ����
bool CheckDeath(DungeonBoss& boss);



//Helper. ��������� ����� �� ���������� ������ ��������
void CheckGreaterPoints(int& points, int max_points);

//Helper. ��������� ���������� �� ������ �� �������
bool CheckMoney(int gold, int price);

