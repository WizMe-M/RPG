#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include <vector>
#include "Helper.h"
using namespace std;

//Combat. Выводит отряд игрока
void ShowHero(Player player, Companion companion);

//Combat. Выводит отряд противников (живых и мёртвых)
void ShowEnemies(vector<Enemy> Enemies, vector<Enemy> DeadEnemies);

//Combat. Выводит статы босса
void ShowBoss(DungeonBoss boss);

//Dungeon. Главный метод ведения боя против рядовых противников
void Combat(Player& player, Companion& companion, vector<Enemy>& Enemies);

//Combat. Ход игрока и компаньона против рядовых противников
void PlayerTurn(Player& player, Companion& companion, vector<Enemy>& Enemies, vector<Enemy>& DeadEnemies);

//Combat. Ход рядовых противников 
void EnemyTurn(Player& player, Companion& companion, vector<Enemy>& Enemies);

//Dungeon. Главный метод ведения боя против босса
void Combat(Player& player, Companion& companion, DungeonBoss& boss);

//Combat. Ход игрока против босса
void PlayerTurn(Player& player, Companion& companion, DungeonBoss& boss);

//Combat. Ход босса 
void EnemyTurn(Player& player, Companion& companion, DungeonBoss& boss);
