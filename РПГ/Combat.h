#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include <vector>
#include "Helper.h"
using namespace std;

//Combat. ������� ����� ������
void ShowHero(Player player, Companion companion);

//Combat. ������� ����� ����������� (����� � ������)
void ShowEnemies(vector<Enemy> Enemies, vector<Enemy> DeadEnemies);

//Combat. ������� ����� �����
void ShowBoss(DungeonBoss boss);

//Dungeon. ������� ����� ������� ��� ������ ������� �����������
void Combat(Player& player, Companion& companion, vector<Enemy>& Enemies);

//Combat. ��� ������ � ���������� ������ ������� �����������
void PlayerTurn(Player& player, Companion& companion, vector<Enemy>& Enemies, vector<Enemy>& DeadEnemies);

//Combat. ��� ������� ����������� 
void EnemyTurn(Player& player, Companion& companion, vector<Enemy>& Enemies);

//Dungeon. ������� ����� ������� ��� ������ �����
void Combat(Player& player, Companion& companion, DungeonBoss& boss);

//Combat. ��� ������ ������ �����
void PlayerTurn(Player& player, Companion& companion, DungeonBoss& boss);

//Combat. ��� ����� 
void EnemyTurn(Player& player, Companion& companion, DungeonBoss& boss);
