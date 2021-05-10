#pragma once
#include <string>
#include <windows.h>
#include <iostream>

#include "Boss.h"
#include "Reward.h"
#include "Enemy.h"
#include "Player.h"
#include "Companion.h"


//Combat. Подсчитывает награду за убитых противников
Reward CalculateReward(double difficulty, vector<Enemy>& deadEnemies);
//Combat. Подсчитывает награду за босса
Reward CalculateReward(double difficulty, DungeonBoss boss);

//ChooseRandomGloor. Приплюсовывает игроку награду за этаж  
void GiveReward(Player& player, Reward reward);
//GiveReward. Если игроку достаточно опыта, запускается алгоритм повышения уровня
void LevelUp(Player& player);

//Combat. Срезает наносимый урон по формуле
int DecreaseDmgByDef(int damage, int defence);

//Helper. Рандом от числа (включительно) до другого числа (не включительно)
int Random(int min, int max);

//Combat. Проверяет "смерть" противника, устанавливает некоторые его параметры как мёртвого, уменьшает количество "живых" противников
void CheckDeath(vector<Enemy>& Enemies, vector<Enemy>& DeadEnemies, int id);
//Combat. Проверяет жив ли игрок и если нет, выводит статистику и завершает игру
void CheckDeath(Player player);
//Combat. Проверяет жив ли компаньон игрока
void CheckDeath(Player& p, Companion& c);
//Combat. Проверяет жив ли игрок и если нет, выводит статистику и завершает игру
void CheckDeath(DungeonBoss& boss);



//Helper. Проверяет число на превышение некого значения
void CheckGreaterPoints(int& points, int max_points);

//Helper. Проверяет достаточно ли золота на покупку
bool CheckMoney(int gold, int price);

