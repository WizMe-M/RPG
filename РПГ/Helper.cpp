#include "Helper.h"
#include "Player.h"
#include "Combat.h"
#include "Windows.h"
#include <conio.h>
#include <ctime>
#include <iostream>

using namespace std;
using std::string;

int Random(int min, int max) 
{
	srand(time(NULL));

	if (min > 0)
	{
		return min + rand() % (max - min);
	}
	else
	{
		return min + rand() % (abs(min) + max);
	}
}

bool CheckDeath(Enemy& newEnemy, int i) 
{
	if (newEnemy.EnemyHP[i] < 0) 
	{
		return true;
	}
	return false;
}

int ChoiceCheck(int max) 
{
	int Choice = 0;

	while (Choice > max || Choice <= 0) 
	{
		cout << " \n";

		cout << " Выбор: ";
		cin >> Choice;
	}

	return Choice;
}

bool CheckMoney(int Gold, int price) 
{
	if (Gold >= price) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BuyItems(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	cout << " 1. Купить снаряжение.\n";
	cout << " 2. Продать снаряжение. \n";

	bool isBuying = true;
	
	cout << " \n";

	switch (ChoiceCheck(2))
	{
	case 1: 
	{
		while (isBuying == true)
		{
			system("cls");

			cout << " Доступные товары: \n";

			int k = 1;

			for (int i = 0; i < 5; i++) 
			{
				cout << " " << std::to_string(k) + ".  Товар: " << newShop.BuyItemName[i] << " | Количество: " << newShop.ItemQuantity[i]
					<< " | Цена: " << newShop.ItemPrice[i] << "\n";
				k++;
			}

			cout << " \n";

			cout << " 6. Вернуться в таверну\n";

			switch (ChoiceCheck(6))
			{
			case 1: 
			{
				if (newShop.ItemQuantity[0] > 0) {
					if (CheckMoney(player.PlayerGold, 300) == true)
					{
						if (player.CurrentInventoryCapacity < player.InventoryMaxCapacity)
						{
							player.Inventory[player.CurrentInventoryCapacity] = " Эстус";
							player.CurrentInventoryCapacity++;

							newShop.ItemQuantity[0] = newShop.ItemQuantity[0] - 1;

							cout << "\n Товар куплен."; 
							Sleep(2000);
						}
						else 
						{
							cout << " Недостаточно места в инвентаре."; 
							break;  
							Sleep(2000);
						}
					}
					else 
					{
						cout << " Недостаточно золота!"; Sleep(2000);
					}
				}
				else 
				{ 
					cout << " Хозяин таверны: На складке закончился этот товар, приходи позже!"; 
					Sleep(2000); 
				}
			} 
			break;
			case 2: 
			{
				if (newShop.ItemQuantity[0] > 0)
				{
					if (CheckMoney(player.PlayerGold, 1500) == true)
					{
						if (player.CurrentInventoryCapacity < player.InventoryMaxCapacity)
						{
							player.CurrentInventoryCapacity++;
							player.Inventory[player.CurrentInventoryCapacity] = " Оружие";

							newShop.ItemQuantity[0] = newShop.ItemQuantity[0] - 1;

							cout << "\n Товар куплен."; Sleep(2000);
						}
						else 
						{
							cout << " Недостаточно места в инвентаре."; 
							Sleep(2000);
						}
					}
					else 
					{
						cout << " Недостаточно золота!"; 
						Sleep(2000);
					}
				}
				else 
				{ 
					cout << " Хозяин таверны: На складке закончился этот товар, приходи позже!"; 
					Sleep(2000); 
				}
			} 
			break;
			case 3: 
			{
				if (newShop.ItemQuantity[2] > 0)
				{
					if (CheckMoney(player.PlayerGold, 1000) == true)
					{


						if (player.CurrentInventoryCapacity < player.InventoryMaxCapacity)
						{
							player.CurrentInventoryCapacity++;
							player.Inventory[player.CurrentInventoryCapacity] = " Кольца";

							newShop.ItemQuantity[2] = newShop.ItemQuantity[2] - 1;

							cout << "\n Товар куплен."; 
							Sleep(2000);
						}
						else
						{
							cout << " Недостаточно места в инвентаре.";
							Sleep(2000);
						}
					}
					else 
					{
						cout << " Недостаточно золота!"; 
						Sleep(2000);
					}
				}
				else 
				{ 
					cout << " Хозяин таверны: На складке закончился этот товар, приходи позже!"; 
					Sleep(2000); 
				}
			} 
			break;
			case 4: 
			{
				if (newShop.ItemQuantity[3] > 0)
				{
					if (CheckMoney(player.PlayerGold, newShop.ItemPrice[3]) == true)
					{
						if (player.CurrentInventoryCapacity < player.InventoryMaxCapacity)
						{
							player.CurrentInventoryCapacity++;
							player.Inventory[player.CurrentInventoryCapacity] = " Скрытность";

							newShop.ItemQuantity[0] = newShop.ItemQuantity[0] - 1;

							cout << "\n Товар куплен."; 
							Sleep(2000);
						}
						else 
						{
							cout << " Недостаточно места в инвентаре."; 
							Sleep(2000);
						}
					}
					else 
					{
						cout << " Недостаточно золота!"; 
						Sleep(2000);
					}
				}
				else 
				{ 
					cout << " Хозяин таверны: На складке закончился этот товар, приходи позже!"; 
					Sleep(2000); 
				}
			} 
			break;
			case 5: 
			{
				if (newShop.ItemQuantity[4] > 0)
				{
					if (CheckMoney(player.PlayerGold, newShop.ItemPrice[4]) == true)
					{
						if (player.CurrentInventoryCapacity < player.InventoryMaxCapacity)
						{
							player.CurrentInventoryCapacity++;
							player.Inventory[player.CurrentInventoryCapacity] = " Броня";

							newShop.ItemQuantity[0] = newShop.ItemQuantity[0] - 1;

							cout << "\n Товар куплен."; 
							Sleep(2000);
						}
						else 
						{
							cout << " Недостаточно места в инвентаре."; 
							Sleep(2000);
						}
					}
					else 
					{
						cout << " Недостаточно золота!"; 
						Sleep(2000);
					}
				}
				else 
				{ 
					cout << " Хозяин таверны: На складке закончился этот товар, приходи позже!"; 
					Sleep(2000); 
				}
			} 
			break;
			case 6: 
			{ 
				Tavern(player, newUnit, newSquad, newShop);
				isBuying = false;
			} 
			break;
			}
		}
	} 
	break;
	}
}

void BuyMercenaries(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	bool isBuying = true;
	string naem[3] = { "Солер", "Логан", "Григгс" };

	while (isBuying == true)
	{
		system("cls");

		for (int i = 0; i < 3; i++) 
		{
			if (naem[i] != "ПРОДАНО") 
			{
				cout << " " << naem[i];
				if (naem[i] == "Солер") 
				{ 
					cout << "- 1000 золота\n"; 
				}
				else if (naem[i] == "Логан") 
				{ 
					cout << "- 2000 золота\n"; 
				}
				else if (naem[i] == "Григгс") 
				{ 
					cout << "- 5000 золота\n"; 
				}
			}
		}

		cout << " \n";

		cout << " 4. Выход\n";

		cout << " Выбор: ";
		int Choice = 0;
		cin >> Choice;

		switch (Choice) 
		{
		case 1:
		{
			if (naem[0] != "ПРОДАНО" && CheckMoney(player.PlayerGold, 1000) == true)
			{
				cout << " Вы нанимаете Солерая за 1000 золота.";
				player.PlayerGold = player.PlayerGold - 1000;
				naem[0] = "ПРОДАНО";

				newUnit.UnitName[2] = "Солер";
				newUnit.UnitTotalHP[2] = 200;
				newUnit.UntiDamage[2] = 20.0;
				newUnit.UntiHP[2] = 200;
				newUnit.UnitClass[2] = "Бандит";

				newSquad.SquadQuantity = newSquad.SquadQuantity + 1;
				newSquad.SquadTotalNumber = newSquad.SquadTotalNumber + 1;
				newSquad.SquadNames[2] = "Солер";
			}
			else 
			{
				cout << " Недостаточно золота или наёмник уже нанят."; 
				Sleep(3000);
				Tavern(player, newUnit, newSquad, newShop);
			}
		}
		break;
		case 2:
		{
			if (naem[1] != "ПРОДАНО" && CheckMoney(player.PlayerGold, 1000) == true)
			{
				cout << " Вы нанимаете Логана за 2000 золота.";
				player.PlayerGold = player.PlayerGold - 2000;
				naem[1] = "ПРОДАНО";

				newUnit.UnitName[3] = "Логан";
				newUnit.UnitTotalHP[3] = 200;
				newUnit.UntiDamage[3] = 20.0;
				newUnit.UntiHP[3] = 300;
				newUnit.UnitClass[3] = "Убийца";

				newSquad.SquadQuantity = newSquad.SquadQuantity + 1;
				newSquad.SquadTotalNumber = newSquad.SquadTotalNumber + 1;
				newSquad.SquadNames[3] = "Логан";
			}
			else 
			{
				cout << " Недостаточно золота или наёмник уже нанят."; 
				Sleep(3000);  
				Tavern(player, newUnit, newSquad, newShop);
			}
		} 
		break;
		case 3:
		{
			if (naem[2] != "ПРОДАНО" && CheckMoney(player.PlayerGold, 1000) == true) {
				cout << " Вы нанимаете Григгса за 5000 золота.";
				player.PlayerGold = player.PlayerGold - 5000;
				naem[2] = "ПРОДАНО";

				newUnit.UnitName[4] = "Григгс";
				newUnit.UnitTotalHP[4] = 200;
				newUnit.UntiDamage[4] = 50.0;
				newUnit.UntiHP[4] = 200;
				newUnit.UnitClass[4] = "Маг";

				newSquad.SquadQuantity = newSquad.SquadQuantity + 1;
				newSquad.SquadTotalNumber = newSquad.SquadTotalNumber + 1;
				newSquad.SquadNames[4] = "Григгс";
			}
			else 
			{ 
				cout << " Недостаточно золота или наёмник уже нанят."; 
				Sleep(3000);  
				Tavern(player, newUnit, newSquad, newShop); }
		} 
		break;
		case 4:
		{
			isBuying = false; MainMenu(player, newUnit, newSquad, newShop);
		} 
		break;
		}
	}
}

void Dungeon(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	switch (Random(1, 3)) 
	{
	case 1:
	{
		cout << " С потолка свисает непонятный сгусток слизи. Такое ощущение, что он двигается. Ваши действия?\n";
		cout << " 1. Атаковать\n";
		cout << " 2. Обойти\n";

		cout << " \n";

		switch (ChoiceCheck(2))
		{
		case 1: 
		{
			player.PlayerHP = player.PlayerHP - Random(5, 10);
			cout << "\n Слизь срывается с потолка и падает прямо на вас!. Она ранит вас и оставляет вам: " << player.PlayerHP << ".\n";
		} 
		break;
		case 2:
		{
			cout << "\n Вы обошли неизвестное существо.";
		} 
		break;
		}

		cout << "\n Вы исследуете глубины и находите поселение полых. Начинается бой..."; 
		Sleep(3000);

		Enemy newEnemy;
		newEnemy.LastQuantity = 5;
		newEnemy.EnemyQuantity = 5;
		int k = 1;

		for (int i = 0; i < newEnemy.EnemyQuantity; i++) {

			string names = " Полый(" + std::to_string(k) + ")";
			newEnemy.EnemyName[i] = names;
			newEnemy.EnemyClass[i] = "Человек";
			newEnemy.EnemyHP[i] = 20.0;
			newEnemy.EnemyDamage[i] = 7.0;
			k++;
		}

		Combat(newSquad, newUnit, newEnemy, player);
	} 
	break;
	case 2:
	{
		cout << "\n Вы ислледуете глубины дальше. Вы замечайте неизвестные врата, стражами врат являются демоны-тельцы. Начинается бой..."; 
		Sleep(3000);

		Enemy newEnemy;
		newEnemy.LastQuantity = 2;
		newEnemy.EnemyQuantity = 2;
		int k = 1;

		for (int i = 0; i < newEnemy.EnemyQuantity; i++) 
		{

			string names = " Демон-телец(" + std::to_string(k) + ")";
			newEnemy.EnemyName[i] = names;
			newEnemy.EnemyClass[i] = "Демон";
			newEnemy.EnemyHP[i] = 80.0;
			newEnemy.EnemyDamage[i] = 4.0;
			k++;
		}
		Combat(newSquad, newUnit, newEnemy, player);
	} 
	break;
	case 3:
	{
		cout << "\n Пройдя через врата, вы попадайте в разрушенный город, известный в легендах как Изалит.  Путь в город преграждают капра-демоны."
			" Начинается бой..."; 
		Sleep(3000);

		Enemy newEnemy;
		newEnemy.LastQuantity = 2;
		newEnemy.EnemyQuantity = 2;
		int k = 1;

		for (int i = 0; i < newEnemy.EnemyQuantity; i++) {

			string names = " Капра-демон(" + std::to_string(k) + ")";
			newEnemy.EnemyName[i] = names;
			newEnemy.EnemyClass[i] = "Демон";
			newEnemy.EnemyHP[i] = 50.0;
			newEnemy.EnemyDamage[i] = 8.0;
			k++;
	}
		Combat(newSquad, newUnit, newEnemy, player);
	} 
	break;
	}

	system("cls");
	cout << "\n Изалит кишит полчищами демонов, захвативших город. Они слишком опасны. Вы принимаете решение вернуться в город.";
	Sleep(3000);

	MainMenu(player, newUnit, newSquad, newShop);
}

void HeroArmy(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	cout << " Отряд " << player.PlayerName << ": ";

	cout << " \n";

	for (int i = 0; i < newSquad.SquadQuantity; i++) {
		cout << " Имя: " << newUnit.UnitName[i] << " | Здоровье: " << newUnit.UntiHP[i] << "/" << newUnit.UnitTotalHP[i]
			<< " | Урон: " << newUnit.UntiDamage[i] << " | Класс: " << newUnit.UnitClass[i] << "\n";
		cout << " \n";
	}

	cout << " 1. Продолжить. \n";

	cout << " Выбор: ";
	int Choice = 0;
	cin >> Choice;

	switch (Choice) 
	{
	case 1: 
	{
		MainMenu(player, newUnit, newSquad, newShop); 
	} 
	break;
	}
}

void HeroStats(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	cout << " Характеристики " << player.PlayerName << ": \n";
	cout << " Класс: " << player.PlayerClass << "\n";
	cout << " Уровень: " << player.PlayerLevel << "\n";
	cout << " Здоровье: " << player.PlayerHP << "\n";
	cout << " Урон: " << player.PlayerDamage << "\n";
	cout << " Защита: " << player.PlayerDefence << "\n";
	cout << " Интеллект: " << player.PlayerKnowledge << "\n";
	cout << " Магическая сила: " << player.PlayerMagicPower << "\n";
	cout << " Мана: " << player.PlayerMana << "\n";
	cout << " Золото: " << player.PlayerGold << "\n";

	cout << " \n";

	cout << " 1. Продолжить. \n";

	cout << " Выбор: ";
	int Choice = 0;
	cin >> Choice;
	switch (Choice) 
	{
	case 1: 
	{
		MainMenu(player, newUnit, newSquad, newShop); 
	}
	break;
	}
}

void Inventory(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	cout << " Инвентарь: \n";

	for (int i = 0; i < player.CurrentInventoryCapacity; i++)
	{
		cout << player.Inventory[i] << " |";
	}

	switch (ChoiceCheck(1))
	{
	case 1: 
	{
		MainMenu(player, newUnit, newSquad, newShop); 
	}
	break;
	}
}

void RestInTavern(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	if (CheckMoney(player.PlayerGold, 10) == true) 
	{
		player.PlayerGold = player.PlayerGold - 10;
		player.PlayerHP = player.PlayerTotalHP;
		cout << " Вы отдохнули.";
	}
	else
	{
		cout << " Хозяин таверны: Возвращайтесь, когда будет золото, уважаемый!";
	}

	cout << " \n";

	switch (ChoiceCheck(1))
	{
	case 1: 
	{
		MainMenu(player, newUnit, newSquad, newShop); 
	} 
	break;
	}
}

void Tavern(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop) 
{
	system("cls");

	cout << " Хозяин таверны: Добро пожаловать в мою таверну, герой! Здесь для тебя найдется кров, еда и снаряжение.\n";
	cout << " 1. Пополнить снаряжение.\n";
	cout << " 2. Нанять людей.\n";
	cout << " 3. Отдохнуть (10 золота, восстанавливает здоровье).\n";
	cout << " 4. Вернуться в главное меню";
	
	cout << " \n";

	switch (ChoiceCheck(4))
	{
	case 1: 
	{ 
		BuyItems(player, newUnit, newSquad, newShop); 
	} 
	break;
	case 2: 
	{ 
		BuyMercenaries(player, newUnit, newSquad, newShop);  
	} 
	break;
	case 3: 
	{ 
		RestInTavern(player, newUnit, newSquad, newShop); 
	}
	break;
	case 4: 
	{ 
		MainMenu(player, newUnit, newSquad, newShop); 
	} 
	break;
	}
}

void MainMenu(Player& player, Unit& newUnit, Squad& newSquad, Shop& newShop)
{
	system("cls");

	cout << " " << player.PlayerName << ", выберите действие: \n";
	cout << " 1. Посетить таверну.\n";
	cout << " 2. Исследовать подземелье.\n";
	cout << " 3. Характеристики героя\n";
	cout << " 4. Армия героя.\n";
	cout << " 5. Инвентарь.\n";

	cout << " \n";

	cout << " Выбор: ";
	int Choice = 0;
	cin >> Choice;

	switch (Choice)
	{
	case 1: 
	{ 
		Tavern(player, newUnit, newSquad, newShop);  
	} 
	break;
	case 2: 
	{ 
		Dungeon(player, newUnit, newSquad, newShop);  
	} 
	break;
	case 3: 
	{ 
		HeroStats(player, newUnit, newSquad, newShop); 
	} 
	break;
	case 4: 
	{ 
		HeroArmy(player, newUnit, newSquad, newShop);  
	} 
	break;
	case 5: 
	{ 
		Inventory(player, newUnit, newSquad, newShop);
	}
	break;
	}
}
