#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "Player.h"
#include "Combat.h"

class Shop
{
public:
	string BuyItemName[5];
	int ItemPrice[5];
	int ItemQuantity[5];
};

int Random(int min, int max);
bool CheckDeath(Enemy& newEnemy, int i);
int ChoiceCheck(int max);
void MainMenu(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop);
bool CheckMoney(int gold, int price);
void Tavern(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop);
void BuyItems(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop);
void BuyMercenaries(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop);
void Dungeon(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop);
void HeroStats(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop);
void HeroArmy(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop);
void Inventory(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop);
void RestInTavern(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop);




