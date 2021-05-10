#pragma once
#include "Helper.h"
#include "Shop.h"
#include "Dungeon.h"

//Главное меню игры, куда игрок постоянно возвращается после похода в Данж
void MainMenu(Player& player, Companion& companion, Shop& shop);
//MainMenu. Вывод меню выбора действий в таверне
void Tavern(Player& player, Companion& companion, Shop& shop);
//Tavern. Купля-продажа предметов
void BuyItems(Player& player, Shop& shop);
//Tavern. Найм компаньонов в битву
void BuyMercenaries(Player& player, Companion& companion, Shop& shop);
//MainMenu. Поход в данж (выбор сложности и цикличный вызов этажей)
void Dungeon(Player& player, Companion& сompanion);
//MainMenu. Вывод характеристик игрока
void HeroStats(Player& player);
//MainMenu. Вывод отряда игрока
void HeroArmy(Player& player, Companion& сompanion);
//Tavern. Восстановление здоровья и маны игрока
void RestInTavern(Player& player, Companion& companion);
//Helper. Функция, принимающая в ввод только цифры
int InputStringToInt();
//Dungeon. Выбор случайного этажа данжа (события из пула событий)
void ChooseRandomFloor(Player& player, Companion& companion, SomeDungeon& dungeon);
//Dungeon. Выбор минибосса на последнем этаже данжа
void ChooseRandomBoss(Player& player, Companion& companion, SomeDungeon& dungeon);