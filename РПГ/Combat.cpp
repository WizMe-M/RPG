#include "Combat.h"
#include <iostream>
#include "Windows.h"
#include "Player.h"
#include "Helper.h"

using namespace std;

using std::string;

int Combat(Squad& newSquad, Unit& newUnit, Enemy& newEnemy, Player& player)
{
	system("cls");

	newUnit.UntiHP[1] = player.PlayerHP;

	cout << " " << player.PlayerName << " характеристики: \n";
	cout << " Класс: " << player.PlayerClass << "\n";
	cout << " Здоровье: " << player.PlayerHP << "\n";
	cout << " Урон: " << (player.PlayerDamage + player.PlayerMinDamage) / 2 << "\n";
	cout << " Защита: " << player.PlayerDefence << "\n";
	cout << " Интеллект: " << player.PlayerKnowledge << "\n";
	cout << " Магическая сила: " << player.PlayerMagicPower << "\n";
	cout << " Мана: " << player.PlayerMana << "\n";
	cout << " Золото: " << player.PlayerGold << "\n";

	cout << " \n";

	cout << " Ваши противники: \n";

	for (int i = 0; i < newEnemy.EnemyQuantity; i++) 
	{
		cout << newEnemy.EnemyName[i] << "  HP: " << newEnemy.EnemyHP[i] << " \n";
	}

	int Choice = 0;
	int RandEnemy = 0;
	int UnitUnderAttack = 0;
	int RandEnemyAttack = 0;
	bool isAccept = false;

	Sleep(3000);

	while (newEnemy.LastQuantity != 0)
	{
		system("cls");

		cout << " \n";

		cout << " Отряд противника: \n";

		cout << " Количество противников: " << newEnemy.LastQuantity << "\n";
		for (int i = 0; i < newEnemy.EnemyQuantity; i++) 
		{
			cout << newEnemy.EnemyName[i] + " HP:  " << newEnemy.EnemyHP[i] << " | ";
		}

		cout << " \n";
		cout << " \n";

		cout << " Ваш ход, выберите атакующего члена отряда: \n";

		for (int i = 0; i < newSquad.SquadQuantity; i++)
		{
			cout << newSquad.SquadNames[i] << "  HP:  " << newUnit.UntiHP[i] << "/" << newUnit.UnitTotalHP[i] << " | ";
		}

		cout << "\n 6. Выпить эстус.";
		cout << "\n 7. Использовать особый удар.";

		cout << " \n";

		cout << "\n Выбор: ";
		cin >> Choice;

		cout << " \n";

		cout << "\n Номер противника для атаки:";
		cin >> RandEnemyAttack;
		RandEnemyAttack = RandEnemyAttack - 1;

		if (Choice == 1)
		{
			if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ") 
			{
				newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(10, newUnit.UntiDamage[0]);
				cout << newUnit.UnitName[0] << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " и оставляет ему "
					<< newEnemy.EnemyHP[RandEnemyAttack] << " здоровья. ";

				if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
				{ 
					newEnemy.LastQuantity--; 
					newEnemy.EnemyName[RandEnemyAttack] = "МЁРТВ";
				};
			}
			else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ")
			{ 
				cout << newUnit.UnitName[0] << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " и промахивается ";
			}
			else 
			{ 
				cout << " Противник слишком далеко, вы переключаетесь на другого."; 
			}
		}

		if (Choice == 2) 
		{

			if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ")
			{
				newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(player.PlayerMinDamage, player.PlayerDamage);
				cout << player.PlayerName << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " и оставляет ему "
					<< newEnemy.EnemyHP[RandEnemyAttack] << " здоровья. ";
				if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
				{ 
					newEnemy.LastQuantity--; 
					newEnemy.EnemyName[RandEnemyAttack] = "МЁРТВ";
				};
			}
			else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ") 
			{ 
				cout << newUnit.UnitName[1] << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " и промахивается ";
			}
			else 
			{ 
				cout << " Противник слишком далеко, вы переключаетесь на другого."; 
			}
		}

		if (Choice == 3)
		{
			if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ") 
			{
				newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(10, newUnit.UntiDamage[2]);
				cout << newUnit.UnitName[2] << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " и оставляет ему "
					<< newEnemy.EnemyHP[RandEnemyAttack] << " здоровья. ";

				if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
				{
					newEnemy.LastQuantity--; 
					newEnemy.EnemyName[RandEnemyAttack] = "МЁРТВ";
				};
			}
			else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ") 
			{ 
				cout << newUnit.UnitName[2] << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " и промахивается ";
			}
			else 
			{ 
				cout << " Противник слишком далеко, вы переключаетесь на другого."; 
			}
		}

		if (Choice == 4)
		{
			if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ") 
			{
				newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(10, newUnit.UntiDamage[3]);
				cout << newUnit.UnitName[3] << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " и оставляет ему "
					<< newEnemy.EnemyHP[RandEnemyAttack] << " здоровья. ";

				if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
				{ 
					newEnemy.LastQuantity--; 
					newEnemy.EnemyName[RandEnemyAttack] = "МЁРТВ";
				};
			}
			else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ") 
			{ 
				cout << newUnit.UnitName[3] << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " и промахивается ";
			}
			else 
			{ 
				cout << " Противник слишком далеко, вы переключаетесь на другого."; 
			}
		}

		if (Choice == 5)
		{
			if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ")
			{
				newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(10, newUnit.UntiDamage[4]);
				cout << newUnit.UnitName[4] << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " и оставляет ему "
					<< newEnemy.EnemyHP[RandEnemyAttack] << " здоровья. ";

				if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
				{ 
					newEnemy.LastQuantity--; 
					newEnemy.EnemyName[RandEnemyAttack] = "МЁРТВ";
				};
			}
			else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ") 
			{ 
				cout << newUnit.UnitName[4] << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " и промахивается ";
			}
			else 
			{ 
				cout << " Проотивник слишком далеко, вы переключаетесь на другого."; 
			}
		}

		if (Choice == 6)
		{
			isAccept = false;
			int i = 0;

			for (int i = 0; i < player.CurrentInventoryCapacity; i++)
			{
				if (player.Inventory[i] == "Эстус" && player.Inventory[i] != "Пусто")
				{
					player.Inventory[i] = "Пусто";

					isAccept = true;
					break;
				}
			}

			if (isAccept == true) 
			{
				for (int i = 0; i < newSquad.SquadQuantity; i++)
				{
					newUnit.UntiHP[i] = newUnit.UntiHP[i] + 20.0;

					if (newUnit.UntiHP[i] > newUnit.UnitTotalHP[i]) { newUnit.UntiHP[i] = newUnit.UnitTotalHP[i]; }
				}

				cout << "\n Вы выпили целебный эстус!"; 
				Sleep(2000);
			}
			else 
			{
				cout << "\n У вас в инвентаре нет эстуса!"; 
				Sleep(2000);
			}
		}

		if (Choice == 7) 
		{
			if (player.PlayerClass == "Воин")
			{
				if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ") 
				{
					newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(player.PlayerMinDamage, player.PlayerDamage);
					cout << player.PlayerName << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " рассекающим ударом и оставляет ему "
						<< newEnemy.EnemyHP[RandEnemyAttack] << " здоровья. ";
					if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
					{ 
						newEnemy.LastQuantity--;
						newEnemy.EnemyName[RandEnemyAttack] = "МЁРТВ"; 
					};
				}
				else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ") 
				{ 
					cout << newUnit.UnitName[1] << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " и промахивается ";
				}
				else 
				{ 
					cout << " Противник слишком далеко, вы переключаетесь на другого."; 
				}
			}

			if (player.PlayerClass == "Маг")
			{
				if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ") 
				{
					newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(player.PlayerMinDamage, player.PlayerDamage);
					cout << player.PlayerName << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " огненным шаром и оставляет ему "
						<< newEnemy.EnemyHP[RandEnemyAttack] << " здоровья. ";
					if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
					{ 
						newEnemy.LastQuantity--; 
						newEnemy.EnemyName[RandEnemyAttack] = "МЁРТВ";
					};
				}
				else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ") 
				{ 
					cout << newUnit.UnitName[1] << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " и промахивается ";
				}
				else 
				{ 
					cout << " Противник слишком далеко, вы переключаетесь на другого."; 
				}
			}

			if (player.PlayerClass == "Лучник")
			{
				if (Random(1, 10) > 2 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ") 
				{
					newEnemy.EnemyHP[RandEnemyAttack] = newEnemy.EnemyHP[RandEnemyAttack] - Random(player.PlayerMinDamage, player.PlayerDamage);
					cout << player.PlayerName << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " выстрелом  "
						<< newEnemy.EnemyHP[RandEnemyAttack] << " здоровья. ";
					if (CheckDeath(newEnemy, RandEnemyAttack) == true) 
					{ 
						newEnemy.LastQuantity--; 
						newEnemy.EnemyName[RandEnemyAttack] = "МЁРТВ";
					};
				}
				else if (Random(1, 10) < 3 && newEnemy.EnemyName[RandEnemyAttack] != "МЁРТВ") 
				{ 
					cout << newUnit.UnitName[1] << " атакует " << newEnemy.EnemyName[RandEnemyAttack] << " и промахивается ";
				}
				else 
				{ 
					cout << " Противник слишком далеко, вы переключаетесь на другого."; 
				}
			}
		}

		cout << " \n";

		cout << " Ход противника...\n";

		RandEnemy = Random(0, newEnemy.EnemyQuantity);
		UnitUnderAttack = Random(0, newSquad.SquadQuantity);

		if ((Random(1, 10) >= 4) && (newEnemy.EnemyName[RandEnemy] != "МЁРТВ") && (newUnit.UnitName[UnitUnderAttack] != "Убит"))
		{
			newUnit.UntiHP[UnitUnderAttack] = newUnit.UntiHP[UnitUnderAttack] - newEnemy.EnemyDamage[RandEnemy];
			cout << newEnemy.EnemyName[RandEnemy] << " атакует " << newUnit.UnitName[UnitUnderAttack] << " и оставляет ему "
				<< newUnit.UntiHP[UnitUnderAttack] << " здоровья.";

			if (newUnit.UntiHP[UnitUnderAttack] < 1)
			{
				newSquad.SquadTotalNumber--;
				newUnit.UnitName[UnitUnderAttack] = "Убит";
			}
		}
		else if (Random(1, 10) < 4 && newEnemy.EnemyName[RandEnemy] != "МЁРТВ") 
		{ 
			cout << newEnemy.EnemyName[RandEnemy] << " атакует " << newUnit.UnitName[UnitUnderAttack] << " и промахивается ";
		}
		else cout << " Противник пропускает ход, так как ближайший к вам враг мёртв.";

		Sleep(3000);
	}

	system("cls");

	if (newEnemy.EnemyQuantity == 0 && newEnemy.EnemyClass[0] == "Демон")
	{
		int Gold = Random(50, 100);
		player.PlayerGold = player.PlayerGold + Gold;
		player.PlayerLevel = player.PlayerLevel + 0.5;

		cout << " \n";

		cout << " Победа!. Награда: " << Gold << " золота.\n ";
		cout << " Опыт: " << player.PlayerLevel << "\n";
		cout << " Общее количество золота: " << player.PlayerGold;

		cout << " \n";

		Sleep(3000);

		return 1;
	}
	else if (newEnemy.EnemyQuantity == 0 && newEnemy.EnemyClass[0] == "Человек")
	{
		int Gold = Random(100, 150);
		player.PlayerGold = player.PlayerGold + Gold;
		player.PlayerLevel = player.PlayerLevel + 0.5;

		cout << " \n";

		cout << " Победа!. Награда: " << Gold << " золота.\n ";
		cout << " Опыт: " << player.PlayerLevel << "\n";
		cout << " Общее количество золота: " << player.PlayerGold;

		cout << " \n";

		Sleep(3000);

		return 1;
	}
	else if (newSquad.SquadTotalNumber == 0)
	{
		system("cls");

		cout << " Поражение! Вы погибли вместе с отрядом.";
	}
	else 
	{
		int Gold = Random(20, 50);
		player.PlayerGold = player.PlayerGold + Gold;
		player.PlayerLevel = player.PlayerLevel + 0.5;

		cout << " \n";

		cout << " Победа! Награда: " << Gold << " золота.\n ";
		cout << " Опыт: " << player.PlayerLevel << "\n";
		cout << " Общее количество золота: " << player.PlayerGold;

		cout << " \n";

		Sleep(3000);

		return 1;
	}
}
