#pragma once
#include <string>
#include "Enemy.h"

using namespace std;


//Абилки боссов
const string SpecialAbilities[5]{ "Таран", "Огненное дыхание", "Зачарование оружия", "Высасывание жизни", "Восстановление здоровья" };

//Босс последнего этажа с уникальными умениями
class DungeonBoss {
public:
	string Name;
	int RaceType;
	string Race;
	int HP;
	int BaseHP;
	int Damage;
	int Defence;
	int Level;
	int Gold;
	int Exp;
	int EvasionChance;
	bool isDead;
	int IdSpecialAbility;
	int SpecialAbilityCooldown;
	int Max_SpecialAbilityCooldown;
	DungeonBoss(string name, int raceType, int fullhp, int damage, int defence, int level, int gold, int exp, int evasion, int abilityId, int max_cd) {
		Name = name;
		RaceType = raceType;
		Race = Races[RaceType];
		BaseHP = fullhp;
		HP = fullhp;
		Damage = damage;
		Defence = defence;
		Level = level;
		Gold = gold;
		Exp = exp;
		EvasionChance = evasion;
		IdSpecialAbility = abilityId;
		Max_SpecialAbilityCooldown = max_cd;
		SpecialAbilityCooldown = 0;
		isDead = false;
	}
};
