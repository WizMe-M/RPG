#pragma once
#include <vector>
#include "Companion.h"
#include "Item.h"

using namespace std;

//Класс магазина в таверне
class Shop
{
public:
	vector <Item> Items;
	vector <Companion> Companions;
};
