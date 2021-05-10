#include "Combat.h"
using namespace std;

void ShowEnemies(vector<Enemy> Enemies, vector<Enemy> DeadEnemies)
{
	system("cls");
	if (!DeadEnemies.empty())
	{
		cout << "\n\t<-- Мёртвые враги -->\n";
		for (Enemy en : DeadEnemies)
			cout << " |" << en.Name << "(Уровень: " << en.Level << ")|\t";
	}

	cout << "\n\n\t<-- Отряд противника -->";
	cout << "\n Количество противников: " << Enemies.size() << "\n";
	for (int i = 0; i < Enemies.size(); i++) {
		cout << " " << to_string(i + 1) << ". " << Enemies.at(i).Name
			<< " | Уровень: " << Enemies.at(i).Level
			<< " | Раса: " << Enemies.at(i).Race
			<< " | Здоровье: " << Enemies.at(i).HP << "/" << Enemies.at(i).BaseHP
			<< " | Урон: " << Enemies.at(i).Damage << "\n";
	}
	cout << "\n\n";
}

void ShowBoss(DungeonBoss boss) {
	system("cls");
	cout << "\n\t<-- Отряд противника -->";
	cout << "\n Босс \"" << boss.Name << "\" Уровень: " << boss.Level << "\n";
	cout << " Раса: " << boss.Race
		<< " | Здоровье: " << boss.HP << "/" << boss.BaseHP
		<< " | Урон: " << boss.Damage;
	cout << "\n\n";
}

void ShowHero(Player player, Companion companion) {
	cout << "\n\t <-- Отряд " << player.Name << " -->";
	cout << "\n\n |" << player.Name << "|\n Класс: " << player.Class << " |\tЗдоровье: " << player.HP << " / " << player.TotalHP << " |\tЗащита: " << player.Defence << " |\tСредний урон: " << (player.MinDamage + player.Damage) / 2.0;
	cout << "\n\n |" << companion.Name << "|\n Класс: " << companion.Class << " |\tЗдоровье: " << companion.HP << " / " << companion.TotalHP << " |\tЗащита: " << companion.Defence << " |\t\tУрон: " << companion.Damage;
	cout << "\n\n";
}

void Combat(Player& player, Companion& companion, vector<Enemy>& Enemies)
{
	vector<Enemy> DeadEnemies;
	for (int i = 0; i < Enemies.size(); i++)
		if (Enemies.at(i).HP <= 0) {
			DeadEnemies.push_back(Enemies.at(i));
			Enemies.erase(Enemies.begin() + i);
		}

	while (Enemies.size() != 0)
	{
		PlayerTurn(player, companion, Enemies, DeadEnemies);
		if (Enemies.size() == 0) break;
		EnemyTurn(player, companion, Enemies);
	}
	system("cls");
	Enemies.swap(DeadEnemies);
}

void PlayerTurn(Player& player, Companion& companion, vector<Enemy>& Enemies, vector<Enemy>& DeadEnemies)
{
	bool isActed = false;
	int Choice = 0;
	if (player.SpecialAbilityCooldown != 0)
		player.SpecialAbilityCooldown--;
	while (!isActed)
	{
		ShowEnemies(Enemies, DeadEnemies);
		ShowHero(player, companion);

		cout << "\n";
		cout << "\n 1 --|====>\tАтаковать противника.";
		cout << "\n 2 --|====>\tИспользовать особый удар.";
		cout << "\n 3 --|====>\tПрименить предмет из инвентаря.";
		cout << " \n";

		cout << "\n <-- Выберите действие -->\n";
		switch (ChoiceCheck(3)) {
		case 1:
		{
			cout << "\n <-- Выберите противника для атаки -->\n";
			Choice = ChoiceCheck(Enemies.size() + 1) - 1;

			Enemies.at(Choice).HP -= (Random(player.MinDamage, player.Damage) + player.MagicPower);
			cout << " " << player.Name << " атакует " << Enemies.at(Choice).Name << " и оставляет ему " << Enemies.at(Choice).HP << " здоровья.\n";
			CheckDeath(Enemies, DeadEnemies, Choice);

			Sleep(1000);
			if (companion.CurAttackCount != 0 && Enemies.size() != 0)
			{
				int RandAttack;
				if (Enemies.size() == 1) RandAttack = 0;
				else RandAttack = Random(0, Enemies.size());

				Enemies.at(RandAttack).HP -= companion.Damage;
				cout << " " << companion.Name << " атакует " << Enemies.at(RandAttack).Name << " и оставляет ему "
					<< Enemies.at(RandAttack).HP << " здоровья. ";
				companion.CurAttackCount--;
				CheckDeath(Enemies, DeadEnemies, RandAttack);
			}
			isActed = true;
			break;
		}
		case 2:
		{
			if (player.SpecialAbilityCooldown == 0)
			{
				if (player.Class == "Воин")
				{
					cout << "\n <-- Выберите противника для атаки -->\n";
					Choice = ChoiceCheck(Enemies.size()) - 1;

					Enemies.at(Choice).HP -= 2 * player.Damage;
					cout << "\n\n" << player.Name << " атакует \"" << Enemies.at(Choice).Name << "\" рассекающим ударом и оставляет " << Enemies.at(Choice).HP << " здоровья. ";
					CheckDeath(Enemies, DeadEnemies, Choice);
					isActed = true;
					player.SpecialAbilityCooldown = 2;
					cout << "\n Ваша способность уходит на перезарядку (" << player.SpecialAbilityCooldown << ").";
				}
				if (player.Class == "Маг")
				{
					if (player.Mana >= player.MaxMana / 2) {
						cout << "\n\n " << player.Name << " колдует огненный шар и атакует им всех противников. ";
						player.Mana -= player.MaxMana / 2;
						for (int i = 0; i < Enemies.size(); i++)
						{
							Enemies.at(i).HP -= 3 * (player.MagicPower + player.Damage);
							cout << "\n " << player.Name << " наносит " << 3 * (player.MagicPower + player.Damage) << " урона противнику "
								<< Enemies.at(i).Name << " и оставляет ему" << Enemies.at(i).HP << " здоровья. ";
							CheckDeath(Enemies, DeadEnemies, i);
						}
						isActed = true;
						player.SpecialAbilityCooldown = 4;
						cout << "\n Ваша способность уходит на перезарядку (" << player.SpecialAbilityCooldown << ").";
					}
					else cout << "\n Недостаточно маны для применения способности. "
						<< "\n Нужно иметь больше половины от максимального запаса маны (" << player.MaxMana / 2 << ").";
				}
				if (player.Class == "Лучник")
				{
					if (player.Mana >= 20)
					{
						cout << "\n <-- Выберите противника для атаки -->\n";
						Choice = ChoiceCheck(Enemies.size()) - 1;
						player.Mana -= 20;
						int dealDamage = 3 * player.Damage;
						Enemies.at(Choice).HP -= dealDamage;
						cout << player.Name << " ранит " << Enemies.at(Choice).Name << " метким выстрелом, оставляя ему "
							<< Enemies.at(Choice).HP << " здоровья. ";
						CheckDeath(Enemies, DeadEnemies, Choice);
						isActed = true;
						player.SpecialAbilityCooldown = 3;
						cout << "\n Ваша способность уходит на перезарядку (" << player.SpecialAbilityCooldown << ").";
					}
					else cout << "\n Недостаточно маны для применения особого умения (нужно по-крайней мере 20 маны).";
				}
			}
			else cout << "\n Ваша способность ещё на перезарядке!";
		}
		break;
		case 3:
		{
			cout << "\n\t<-- Выберите предмет в инвентаре -->\n";
			for (int i = 0; i < player.Inventory.size(); i++)
				cout << to_string(i + 1) << ". " << player.Inventory.at(i).Name << "\n";
			cout << to_string(player.Inventory.size() + 1) << ". Назад";

			Choice = ChoiceCheck(player.Inventory.size() + 1) - 1;
			if (player.Inventory.at(Choice).Name == "Эстус")
			{
				player.HP += 50;
				companion.HP += 50;
				CheckGreaterPoints(player.HP, player.TotalHP);
				CheckGreaterPoints(companion.HP, companion.TotalHP);
				cout << "\n Вы выпили целебный эстус! Ваш отряд восстановил 50 здоровья!";
				player.Inventory.at(Choice).Quantity--;
				if (player.Inventory.at(Choice).Quantity == 0)
					player.Inventory.erase(player.Inventory.begin() + Choice);
				isActed = true;
			}
			else cout << "\n Вы не можете пока применить этот предмет";
		}
		break;
		}
	}
	cout << "\n\n Нажмите любую клавишу, чтобы передать ход противнику.";
	GetKey();
}

void EnemyTurn(Player& player, Companion& companion, vector<Enemy>& Enemies)
{
	system("cls");
	cout << " \n";
	cout << " Ход противника...\n";
	Sleep(1000);
	ShowHero(player, companion);

	for (int i = 0; i < Enemies.size(); i++) {
		Sleep(300);
		//создаём шаблон цели для атаки (нужно, чтобы удобно было работать с рандомом между игроком и компаньоном). по умолчанию это игрок
		Target newTarget = Target(player.Name, "Игрок", player.HP, player.Defence);

		//даём возможность компаньону стать целью для атаки
		if (player.haveCompanion)
		{
			if (companion.Class == "Воин") {
				if (Random(0, 100) > 50) newTarget = Target(companion.Name, "Компаньон", companion.HP, companion.Defence);
			}
			else if (Random(0, 100) > 85) newTarget = Target(companion.Name, "Компаньон", companion.HP, companion.Defence);
		}

		int dmg = DecreaseDmgByDef(Enemies.at(i).Damage, newTarget.Defence);

		cout << "\n " << Enemies.at(i).Name << " атакует " << newTarget.Name;
		if (Random(0, 100) > 17) {
			cout << " и наносит ему " << dmg << ".";
			newTarget.HP -= dmg;
			cout << " Здоровье " << newTarget.Name << ": " << newTarget.HP;
		}
		else cout << " и промахивается.";

		if (newTarget.Type == "Игрок") {
			player.HP = newTarget.HP;
			CheckDeath(player);
		}
		else 
		{
			companion.HP = newTarget.HP;
			CheckDeath(player, companion);
		}
		Sleep(12);
	}
	cout << "\n\n Нажмите любую клавишу, чтобы получить свой ход.";
	GetKey();
}

void Combat(Player& player, Companion& companion, DungeonBoss& boss)
{
	while (!boss.isDead)
	{
		PlayerTurn(player, companion, boss);
		if (boss.isDead) break;
		EnemyTurn(player, companion, boss);
	}
	system("cls");
}

void PlayerTurn(Player& player, Companion& companion, DungeonBoss& boss)
{
	bool isActed = false;
	int Choice = 0;
	if (player.SpecialAbilityCooldown != 0)
		player.SpecialAbilityCooldown--;
	while (!isActed) {
		ShowBoss(boss);
		ShowHero(player, companion);

		cout << "\n";
		cout << "\n 1 --|====>\tАтаковать босса.";
		cout << "\n 2 --|====>\tИспользовать особый удар.";
		cout << "\n 3 --|====>\tПрименить предмет из инвентаря.";
		cout << " \n";

		cout << "\n <-- Выберите действие -->\n";
		switch (ChoiceCheck(3)) {
		case 1:
		{
			if (Random(0, 100) > boss.EvasionChance)
			{
				boss.HP -= (Random(player.MinDamage, player.Damage) + player.MagicPower);
				cout << " " << player.Name << " атакует " << boss.Name << " и оставляет ему " << boss.HP << " здоровья. ";
				CheckDeath(boss);
			}
			else cout << " " << boss.Name << " уклоняется от атаки " << player.Name << ".\n";

			Sleep(1000);
			if (companion.CurAttackCount != 0)
			{
				if (Random(0, 100) > boss.EvasionChance)
				{
					boss.HP -= companion.Damage;
					cout << " " << companion.Name << " атакует " << boss.Name << " и оставляет ему " << boss.HP << " здоровья. ";
					companion.CurAttackCount--;
					CheckDeath(boss);
				}
				else cout << " " << boss.Name << " уклоняется от атаки " << companion.Name << ".\n";
			}
		}
		break;
		case 2:
		{
			if (player.SpecialAbilityCooldown == 0) 
			{
				if (player.Class == "Воин")
				{
					boss.HP -= 2 * player.Damage;
					cout << "\n\n " << player.Name << " атакует \"" << boss.Name << "\" рассекающим ударом и оставляет ему " << boss.HP << " здоровья. ";
					CheckDeath(boss);
					isActed = true;
					player.SpecialAbilityCooldown = 2;
					cout << "\n Ваша способность уходит на перезарядку (" << player.SpecialAbilityCooldown << ").";
				}
				if (player.Class == "Маг")
				{
					if (player.Mana >= player.MaxMana / 2) {

						cout << "\n";
						cout << "\n " << player.Name << " колдует огненный шар и атакует им \"" << boss.Name << "\".\n";
						Sleep(300);
						player.Mana -= player.MaxMana / 2;
						boss.HP -= 3 * (player.MagicPower + player.Damage);
						cout << " " << player.Name << " наносит " << (player.MagicPower + player.Damage) << " урона \"" << boss.Name << "\" и оставляет ему " << boss.HP << " здоровья. ";
						CheckDeath(boss);
						isActed = true;
						player.SpecialAbilityCooldown = 4;
						cout << "\n Ваша способность уходит на перезарядку (" << player.SpecialAbilityCooldown << ").";
					}
					else cout << "\n Недостаточно маны для применения особого умения. "
						<< "\n Нужно иметь больше половины от максимального запаса маны (" << player.MaxMana / 2 << ").";
				}
				if (player.Class == "Лучник")
				{
					if (player.Mana >= 20)
					{
						player.Mana -= 20;
						int dealDamage = 2 * player.Damage + player.MagicPower;
						boss.HP -= dealDamage;
						cout << " " << player.Name << " атакует \"" << boss.Name << "\" метким выстрелом, оставляя ему " << boss.HP << " здоровья. ";
						CheckDeath(boss);
						isActed = true;
						player.SpecialAbilityCooldown = 3;
						cout << "\n Ваша способность уходит на перезарядку (" << player.SpecialAbilityCooldown << ").";
					}
					else cout << "\n Недостаточно маны для применения особого умения (нужно по-крайней мере 20 маны).";
				}
			}
			else cout << "\n Ваша способность ещё на перезарядке!";
		}
		break;
		case 3:
		{
			cout << "\n\t<-- Выберите предмет в инвентаре -->";
			for (int i = 0; i < player.Inventory.size(); i++)
				cout << " " << to_string(i + 1) << ". " << player.Inventory.at(i).Name << "\n";
			cout << " " << player.Inventory.size() + 1 << ". Назад";

			Choice = ChoiceCheck(player.Inventory.size() + 1) - 1;
			if (Choice == ChoiceCheck(player.Inventory.size())) break;
			if (player.Inventory.at(Choice).Name == "Эстус")
			{
				player.HP += 50;
				companion.HP += 50;
				CheckGreaterPoints(player.HP, player.TotalHP);
				CheckGreaterPoints(companion.HP, companion.TotalHP);
				cout << "\n Вы выпили целебный эстус! Ваш отряд восстановил 50 здоровья!";
				isActed = true; 
				player.Inventory.at(Choice).Quantity--;
				if (player.Inventory.at(Choice).Quantity == 0)
					player.Inventory.erase(player.Inventory.begin() + Choice);
			}
			else cout << "\n Вы не можете пока применить этот предмет";
		}
		break;
		}
	}
	cout << "\n\n Нажмите любую клавишу, чтобы передать ход противнику.";
	GetKey();
}

void EnemyTurn(Player& player, Companion& companion, DungeonBoss& boss)
{
	system("cls");
	cout << " \n";
	cout << " Ход противника...\n";
	Sleep(1000);
	ShowHero(player, companion);

	if (boss.SpecialAbilityCooldown == 0)
	{
		cout << " " << boss.Name << " применяет умение \"" << SpecialAbilities[boss.IdSpecialAbility] << "\"!\n";
		switch (boss.IdSpecialAbility)
		{
		case 0:
		{

			if (Random(0, 100) > 50)
			{
				int dmg = DecreaseDmgByDef(boss.Damage * 2, player.Defence);
				player.HP -= dmg;
				cout << " " << boss.Name << " разгоняется и таранит " << player.Name << " и наносит " << dmg << " урона.";
				cout << "\n Ваше здоровье: " << player.HP;
			}
			else
			{
				int dmg = DecreaseDmgByDef(boss.Damage * 2, companion.Defence);
				companion.HP -= dmg;
				cout << " " << boss.Name << " разгоняется и таранит " << companion.Name << " и наносит " << dmg << " урона.";
				cout << "\n Здоровье " << companion.Name << ": " << companion.HP;
			}
			break;
		}
		case 1:
		{
			cout << " " << boss.Name << " поливает огнём ваш отряд. Вы получили " << boss.Damage << " урона.";
			player.HP -= boss.Damage;
			companion.HP -= boss.Damage;
			cout << "\n Ваше здоровье: " << player.HP << ". Здоровье " << companion.Name << ": " << companion.HP;
			break;
		}
		case 2:
		{
			boss.Damage *= 2;
			cout << " " << boss.Name << " зачаровывает своё оружие увеличивая его урон вдвое. Текущий урон: " << boss.Damage;
			break;
		}
		case 3:
		{
			if (Random(0, 100) > 50)
			{
				player.HP -= boss.Damage;
				boss.HP += boss.Damage;

				cout << " " << boss.Name << " высасывает " << boss.Damage << " здоровья из " << player.Name;
				cout << "\n Ваше здоровье: " << player.HP;
				cout << "\n Здоровье " << boss.Name << ": " << boss.HP;
			}
			else
			{
				companion.HP -= boss.Damage;
				boss.HP += boss.Damage;
				cout << boss.Name << " высасывает " << boss.Damage << " здоровья из " << companion.Name;
				cout << "\n Здоровье " << companion.Name << ": " << companion.HP;
			}
			break;
		}
		case 4:
		{
			cout << " " << boss.Name << " выпивает из фляги с эстусом, восстанавливая себе 60 здоровья";
			boss.HP += 60;
			CheckGreaterPoints(boss.HP, boss.BaseHP);
			break;
		}
		}
		boss.SpecialAbilityCooldown = boss.Max_SpecialAbilityCooldown;
	}
	else
	{
		if (Random(0, 100) > 50)
		{
			int dmg = DecreaseDmgByDef(boss.Damage, player.Defence);
			cout << "\n " << boss.Name << " атакует " << player.Name << " и наносит " << dmg << " урона";
			cout << "\n Ваше здоровье: " << player.HP;
		}
		else
		{
			int dmg = DecreaseDmgByDef(boss.Damage, companion.Defence);
			cout << "\n " << boss.Name << " атакует " << companion.Name << " и наносит " << dmg << " урона";
			cout << "\n Здоровье " << companion.Name << ": " << companion.HP;
		}
		boss.SpecialAbilityCooldown--;
	}

	CheckDeath(player);
	CheckDeath(player, companion);
	cout << "\n\n Нажмите любую клавишу, чтобы получить свой ход.";
	GetKey();
}