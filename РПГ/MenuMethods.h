#pragma once
#include "Helper.h"
#include "Shop.h"
#include "Dungeon.h"

//������� ���� ����, ���� ����� ��������� ������������ ����� ������ � ����
void MainMenu(Player& player, Companion& companion, Shop& shop);
//MainMenu. ����� ���� ������ �������� � �������
void Tavern(Player& player, Companion& companion, Shop& shop);
//Tavern. �����-������� ���������
void BuyItems(Player& player, Shop& shop);
//Tavern. ���� ����������� � �����
void BuyMercenaries(Player& player, Companion& companion, Shop& shop);
//MainMenu. ����� � ���� (����� ��������� � ��������� ����� ������)
void Dungeon(Player& player, Companion& �ompanion);
//MainMenu. ����� ������������� ������
void HeroStats(Player& player);
//MainMenu. ����� ������ ������
void HeroArmy(Player& player, Companion& �ompanion);
//Tavern. �������������� �������� � ���� ������
void RestInTavern(Player& player, Companion& companion);
//Helper. �������, ����������� � ���� ������ �����
int InputStringToInt();
//Dungeon. ����� ���������� ����� ����� (������� �� ���� �������)
void ChooseRandomFloor(Player& player, Companion& companion, SomeDungeon& dungeon);
//Dungeon. ����� ��������� �� ��������� ����� �����
void ChooseRandomBoss(Player& player, Companion& companion, SomeDungeon& dungeon);