#include "MenuMethods.h"
#include "Helper.h"
#include "Combat.h"

#include <direct.h>

using namespace std;

/*Здесь находятся функции, необходимые для организации алгоритма работы программы*/

const char* path = "D:\\saves\\";

void MainMenu(Player& player, Companion& сompanion, Shop& shop)
{
	while (true)
	{
		player.SpecialAbilityCooldown = 0;
		//сохранение
		{
			int _ = _mkdir(path);
			ofstream file;
			file.open(path + player.Name + ".txt");
			if (file.is_open())
			{
				file << player.Class << endl;
				file << player.Level << endl;
				file << player.Experience << " " << player.MaxExp << endl;
				file << player.HP << " " << player.TotalHP << endl;
				file << player.Defence << endl;
				file << player.MinDamage << " " << player.Damage << endl;
				file << player.MagicPower << endl;
				file << player.Mana << " " << player.MaxMana << endl;
				file << player.Gold << endl;
				file << player.HPperLVL << endl;
				file << player.DMGperLVL << endl;
				file << player.DEFperLVL << endl;
				file << player.MPperLVL << endl;
				file << player.MANAperLVL << endl;
				file << player.haveCompanion << endl;
				file << player.EnemiesKilledCount << endl;
				file << player.Inventory.size() << endl;
				if (player.Inventory.size() != 0)
					for (int i = 0; i < player.Inventory.size(); i++)
						file << player.Inventory.at(i).Name << " " << player.Inventory.at(i).Price << " " << player.Inventory.at(i).Quantity << endl;
				file.close();				
			}
		}

		system("cls");
		cout << "\n\t<-- Главное Меню -->\n";
		cout << "\n " << player.Name << ", выберите действие: \n";
		cout << " 1. Посетить таверну.\n";
		cout << " 2. Исследовать подземелье.\n";
		cout << " 3. Характеристики героя\n";
		cout << " 4. Армия героя.\n";
		switch (ChoiceCheck(4))
		{
		case 1:
			Tavern(player, сompanion, shop);
			break;
		case 2:
			Dungeon(player, сompanion);
			break;
		case 3:
			HeroStats(player);
			break;
		case 4:
			HeroArmy(player, сompanion);
			break;
		}
	}
}
void Tavern(Player& player, Companion& companion, Shop& shop)
{
	while (true)
	{
		system("cls");
		cout << "\n\t<-- Таверна -->\n";
		cout << " Хозяин таверны: Добро пожаловать в мою таверну, герой! Здесь для тебя найдется кров, еда и снаряжение.\n\n";
		cout << " 1. Пополнить снаряжение.\n";
		cout << " 2. Нанять людей.\n";
		cout << " 3. Отдохнуть. Полностью восстанавливает здоровье и ману.\n";
		cout << " 4. Вернуться в главное меню\n";
		switch (ChoiceCheck(4))
		{
		case 1: BuyItems(player, shop);
			break;
		case 2:	BuyMercenaries(player, companion, shop);
			break;
		case 3: RestInTavern(player, companion);
			break;
		case 4: return; break;
		}
	}
}
void BuyItems(Player& player, Shop& shop)
{
	system("cls");
	cout << "\n\t<-- Покупка/Продажа Снаряжения -->\n";
	cout << " 1. Купить снаряжение.\n";
	cout << " 2. Продать снаряжение. \n";
	bool isBuying = true;
	switch (ChoiceCheck(2))
	{
	case 1:
		system("cls");
		cout << "\n Лавочник: Здравствуйте и добро пожаловать.\n";
		while (true)
		{
			cout << "\n\t<-- Лавка магических предметов -->\n";
			cout << " Лавочник: Вот, наш ассортимент:\n";
			for (int i = 0; i < shop.Items.size(); i++)
			{
				cout << " " << to_string(i + 1) << ".  Товар: " << shop.Items.at(i).Name
					<< " | Количество: " << shop.Items.at(i).Quantity
					<< " | Цена: " << shop.Items.at(i).Price << "\n";
			}
			cout << "\n " << shop.Items.size() + 1 << ". Выход";

			cout << "\n Лавочник: Желаете что-нибудь прикупить?";
			int Choice = ChoiceCheck(shop.Items.size() + 1) - 1;
			if (Choice == shop.Items.size()) {
				cout << "\n Лавочник: До свидания, заходите ещё!";
				break;
			}

			if (shop.Items.at(Choice).Quantity != 0)
			{
				if (CheckMoney(player.Gold, shop.Items.at(Choice).Price))
				{
					if (player.Inventory.size() != player.InventoryMaxCapacity)
					{
						shop.Items.at(Choice).Quantity--;
						bool alreadyHaveChosenItem = false;
						int itemSlot = 0;
						for (int i = 0; i < player.Inventory.size(); i++)
							if (player.Inventory.at(i).Name == shop.Items.at(Choice).Name)
							{
								alreadyHaveChosenItem = true;
								itemSlot = i;
								break;
							}

						if (alreadyHaveChosenItem)
							player.Inventory.at(itemSlot).Quantity++;
						else
						{
							player.Inventory.push_back(shop.Items.at(Choice));
							player.Inventory.back().Quantity = 1;
							player.Inventory.back().Price /= 2;
						}
						cout << "\n Лавочник: Спасибо за покупку!";
					}
					else cout << "\n Лавочник: Ой-ёй, кажется ваш инвентарь полон! Вы не сможете больше унести";
				}
				else cout << "\n Лавочник: Извините, я не могу дать вам в долг. Возвращайтесь, когда станете чуточку побогаче.";
			}
			else cout << "\n Лавочник: Извините, этот предмет раскуплен, выберите другой.";
		}
		cout << "\n Нажмите любую кнопку, чтобы вернуться в таверну" << endl;
		GetKey();
		break;


	case 2:
		system("cls");
		cout << "\n\t <-- Скупщик мусора -->\n";
		cout << " Скупщик: Здравствуйте. Я - скупщик всего мусора, что ты мне принесёшь. Я готов купить что угодно.";
		Sleep(1000);
		if (player.Inventory.empty())
			cout << "\n Скупщик: ... Ты пришёл с пустыми руками? Серьезно? Проваливай-ка отсюда.";
		else
		{
			while (true)
			{

				cout << "\n Скупщик: Ну-с, посмотрим, что у вас есть...\n";
				for (int i = 0; i < player.Inventory.size(); i++)
					cout << " " << to_string(i + 1) << ". " << player.Inventory.at(i).Name << " | Количество: " << player.Inventory.at(i).Quantity << endl;
				cout << " " << player.Inventory.size() + 1 << ". Выход";

				cout << "\n <-- Выберите предмет на продажу -->";
				int Choice = ChoiceCheck(player.Inventory.size() + 1);
				if (Choice == player.Inventory.size() + 1)
				{
					cout << "\n Скупщик: Прощайте.";
					break;
				}
				cout << "\n Скупщик: Я куплю " << player.Inventory.at(Choice - 1).Name << " за " << player.Inventory.at(Choice - 1).Price << " золотых. Вы согласны?";
				cout << "\n 1. Да";
				cout << "\n 2. Нет";

				if (ChoiceCheck(2) == 1)
				{
					cout << "\n Скупщик: Отлично! Это пополнит мою коллекцию.";
					player.Gold += player.Inventory.at(Choice - 1).Price;
					player.Inventory.at(Choice - 1).Quantity--;
					if (player.Inventory.at(Choice - 1).Quantity == 0)
						player.Inventory.erase(player.Inventory.begin() + Choice - 1);
				}
				else cout << "\n Скупщик: Как скажешь.";


				if (player.Inventory.empty()) {
					cout << "\n Скупщик: Кажется, у тебя закончился мусор на продажу, не правда ли? Можешь валить отсюда и не возвращаться, пока не обзаведёшься новым.";
					break;
				}
			}
		}
		cout << "\n Нажмите любую кнопку, чтобы вернуться в таверну" << endl;
		GetKey();
		break;
	}
}
void BuyMercenaries(Player& player, Companion& companion, Shop& shop)
{
	while (true)
	{
		system("cls");
		cout << "\n\t<-- Найм компаньонов -->\n";
		cout << " Главарь наёмников: Приветствую и бла-бла. Выбирай бойца.\n";
		for (int i = 0; i < shop.Companions.size(); i++)
			cout << " " << to_string(i + 1) << ". " << shop.Companions.at(i).Name << " | Класс: " << shop.Companions.at(i).Class
			<< " | Здоровье: " << shop.Companions.at(i).TotalHP << " | Защита: " << shop.Companions.at(i).Defence
			<< " | Урон: " << shop.Companions.at(i).Damage << " | Количество атак: " << shop.Companions.at(i).MaxAttackCount << "\n";
		cout << "\n " << shop.Companions.size() + 1 << ". Выход\n";

		int Choice = ChoiceCheck(shop.Companions.size() + 1) - 1;
		if (Choice == shop.Companions.size()) return;

		if (!shop.Companions.at(Choice).isSold)
			if (player.haveCompanion)
			{
				cout << "\n У вас уже есть компаньон " << companion.Name << ":\n";
				cout << " Класс: " << companion.Class << " | Здоровье: " << companion.HP << " / " << companion.TotalHP << " | Защита: " << companion.Defence
					<< " | Урон: " << companion.Damage << " | Количество атак: " << companion.CurAttackCount << " / " << companion.MaxAttackCount;
				cout << "\n\n Хотите его заменить?";
				cout << "\n 1. Да";
				cout << "\n 2. Нет";
				if (ChoiceCheck(2) == 1)
				{
					companion = shop.Companions.at(Choice);
					shop.Companions.at(Choice).isSold = true;
					shop.Companions.at(Choice).Name += " (ПРОДАН)";
					return;
				}
			}
			else
			{
				cout << "\n Вы наняли компаньона " << companion.Name;
				companion = shop.Companions.at(Choice);
				shop.Companions.at(Choice).isSold = true;
				shop.Companions.at(Choice).Name += " (ПРОДАН)";
				return;
			}
		else cout << "\n Этот наёмник уже был нанят.";
	}
	cout << "\n Нажмите любую кнопку, чтобы вернуться в таверну" << endl;
	GetKey();
}
void RestInTavern(Player& player, Companion& companion)
{
	system("cls");
	cout << "\n\t<-- Отдых в таверне -->\n";
	int restPrice = (player.TotalHP - player.HP) + (player.MaxMana - player.Mana) +
		(companion.TotalHP - companion.HP) + (companion.MaxAttackCount - companion.CurAttackCount) * 5;
	cout << "\n Хозяин таверны: Цена комнаты для вас составит " << restPrice << " золотых";
	if (restPrice != 0) {
		if (CheckMoney(player.Gold, restPrice))
		{
			player.Gold = player.Gold - restPrice;
			player.HP = player.TotalHP;
			player.Mana = player.MaxMana;
			companion.HP = companion.TotalHP;
			companion.CurAttackCount = companion.MaxAttackCount;
			cout << "\n Вы отдохнули. Ваши здоровье и мана полностью восстановлены.";
			cout << "\n Ваш компаньон отдохнул. Его здоровье и силы полностью восстановлены.";
		}
		else cout << " Хозяин таверны: Возвращайтесь, когда будет золото, уважаемый!";
	}
	else cout << " Вы не нуждаетесь в отдыхе... ";
	cout << endl;
	cout << endl;
	cout << " Нажмите любую кнопку, чтобы вернуться в главное меню" << endl;
	GetKey();
}
void Dungeon(Player& player, Companion& companion)
{
	system("cls");
	int floor = 1;
	cout << "\n\t<-- Поход в Подземелье -->\n";
	cout << " Выберите, куда идти:\n";
	cout << " 1. Лес Павших Гигантов (легко, 5 этажей) \n";
	cout << " 2. Город Нежити (средне, 12 этажей) \n";
	cout << " 3. Цитадель Фаррона (тяжело, 25 этажей) \n" << endl;
	SomeDungeon dungeon;
	switch (ChoiceCheck(3)) {
	case 1:
		dungeon.DungDifficulty = 0.75;
		dungeon.DungFloorsCount = 5;
		dungeon.DungType = "Лес Павших Гигантов";
		dungeon.isDungBoss = 0.0;
		break;
	case 2:
		dungeon.DungDifficulty = 1.5;
		dungeon.DungFloorsCount = 12;
		dungeon.DungType = "Город Нежити";
		dungeon.isDungBoss = 0.5;
		break;
	case 3:
		dungeon.DungDifficulty = 3.0;
		dungeon.DungFloorsCount = 25;
		dungeon.DungType = "Цитадель Фаррона";
		dungeon.isDungBoss = 1.0;
		break;
	}

	for (int i = 1; i <= dungeon.DungFloorsCount; i++) {
		dungeon.DungCurFloor = i;
		if (dungeon.DungCurFloor == dungeon.DungFloorsCount)
			if ((double)Random(0, 100) / 100.0 < dungeon.isDungBoss)
				ChooseRandomBoss(player, companion, dungeon);
		ChooseRandomFloor(player, companion, dungeon);
	}

	system("cls");
	cout << "\n Локация исследована. Вы принимаете решение вернуться в Храм Огня...";
	cout << " Нажмите любую кнопку, чтобы вернуться в главное меню" << endl;
	GetKey();
}
void ChooseRandomFloor(Player& player, Companion& companion, SomeDungeon& dungeon)
{
	if (player.SpecialAbilityCooldown != 0)
		player.SpecialAbilityCooldown--;
	Reward BattleReward;
	//Динамический массив врагов
	vector <Enemy> Enemies;
	int r;
	//UI
	{
		system("cls");
		cout << "\n Локация " << dungeon.DungType << " | Этаж " << dungeon.DungCurFloor << " из " << dungeon.DungFloorsCount << endl;

		cout << "\n " << player.Name << " характеристики: \n";
		cout << " Класс: " << player.Class << "\n";
		cout << " Уровень: " << player.Level << "\n";
		cout << " Опыт: " << player.Experience << " / " << player.MaxExp << "\n";
		cout << " Здоровье: " << player.HP << " / " << player.TotalHP << "\n";
		cout << " Средний урон: " << (player.Damage + player.MinDamage) / 2.0 << "\n";
		cout << " Защита: " << player.Defence << "\n";
		cout << " Магическая сила: " << player.MagicPower << "\n";
		cout << " Мана: " << player.Mana << " / " << player.MaxMana << "\n";
		cout << " Золото: " << player.Gold << "\n";
		cout << " \n\n";
	}

	switch (Random(0, 10))
	{
	default:
	case 0:
	{
		cout << " Вы идёте по тропе, как вдруг на пути замечаете полого, целящегося в вас из арбалета. Ваши действия?\n";
		cout << " 1. Напасть на него\n";
		cout << " 2. Уклониться от стрелы\n";
		cout << " 3. Парировать стрелу\n";
		cout << " 4. Ничего не делать\n";
		Enemies.push_back(Enemy("Полый солдат", 0, 60 * dungeon.DungDifficulty, 33 * dungeon.DungDifficulty, 3));
		switch (ChoiceCheck(4)) {
		case 1:
		{
			player.HP -= Random(Enemies.front().Damage - 5, Enemies.front().Damage + 5);
			Enemies.front().HP -= Random(player.MinDamage, player.Damage);

			cout << "\n Полый попадает в вас стрелой (ваше здоровье: " << player.HP << "), но платится за это своей кровью.";
			if (Enemies.front().HP <= 0) {
				Reward rew = CalculateReward(dungeon.DungDifficulty, Enemies);
				cout << "\n Полый убит. Получено опыта: " << rew.Experience;
				cout << "\n Вы обыскиваете останки и находите немного золота: " << rew.Gold;
				GiveReward(player, rew);
				vector<Enemy>().swap(Enemies);
			}
			else {
				cout << "\n Вы раните полого, оставляя ему " << Enemies.front().HP << " здоровья.\n";
			}
		}
		break;
		case 2:
		{
			int difference = player.InventoryMaxCapacity - player.Inventory.size();
			double hardness = 10 * dungeon.DungDifficulty;
			if (difference > hardness)
				cout << "\n Вы успешно уклонились от стрелы!";
			else
			{
				player.HP -= Random(Enemies.front().Damage - 10, Enemies.front().Damage);
				cout << "\n Что-то затрудняет ваше передвижение - вы не смогли уклониться.";
				cout << "\n Полый ранит вас стрелой и оставляет " << player.HP << " здоровья.\n";
			}
		}
		break;
		case 3:
		{
			double hardness = 100 * dungeon.DungDifficulty;
			if (player.Defence > hardness)
				cout << "\n Вы успешно отразили стрелу!";
			else
			{
				player.HP -= DecreaseDmgByDef(Enemies.front().Damage, player.Defence);
				cout << "\n Ваша защита оставляет желать лучшего - вы не смогли защититься.";
				cout << "\n Полый ранит вас стрелой и оставляет " << player.HP << " здоровья.\n";
			}
		}
		break;
		case 4:
		{
			int dmg = Enemies.front().Damage * 1.5;
			player.HP -= dmg;
			CheckDeath(player);
			cout << "\n Стоящая на месте мишень - отличная цель для стрельбы!!!";
			cout << "\n Полый стреляет по незащищенной части вашего тела и ранит вас на " << dmg;
			cout << ".\n Ваше здоровье: " << player.HP;
		}
		break;
		}
		break;
	}
	case 1:
	{
		cout << "\n Вы исследуете глубины и находите поселение полых крестьян. Они вас не видят.";
		cout << "\n Один из полых проходит буквально рядом с вами. Нужно что-то делать.";
		cout << "\n 1.Ударить полого рядом с собой";
		cout << "\n 2.Тихо уйти";
		cout << "\n 3.Подкрасться к полому сзади и попытаться его убить";
		cout << "\n 4.Выжидать";

		for (int i = 0; i < 5; i++)
			Enemies.push_back(Enemy(" Полый крестьянин [" + to_string(i + 1) + "]", 0, 80 * dungeon.DungDifficulty, 17 * dungeon.DungDifficulty, 2));

		GetKey();
		switch (ChoiceCheck(4)) {
		case 1:
		{
			cout << "\n Вы тихо подкрадываетесь к полому и бьёте его в спину";
			Enemies.at(Random(0, 5)).HP /= 2;
		}
		break;
		case 2:
		{
			cout << "\n Вы пытаетесь тихо уйти, но один из полых замечает вас.";
			cout << "\n Он атакует и...";
			Sleep(2000);
			if (Random(0, 100) > 30)
			{
				cout << " попадает.";
				player.HP -= Enemies.front().Damage;
				cout << "\n Вам нанесли " << Enemies.front().Damage << " урона. Текущее здоровье: " << player.HP;
				CheckDeath(player);
			}
			else cout << " промахивается.";
		}
		break;
		case 3:
		{
			if (Random(0, 100) > 85) {
				cout << "\n Вы подкрадываетесь к полому и наносите ему сокрушающий удар, моментально убивая его.";
				int i = Random(0, 5);
				Enemies.at(i).HP = 0;
			}
			else cout << "\n Вас заметили.";
		}
		break;
		case 4:
		{
			cout << "\n Вы слишком долго выжидали. Вас заметили.";
		}
		break;
		}
		break;
	}
	case 2:
	{
		Enemies.push_back(Enemy("Демон-ворона", 2, Random(80, 100) * dungeon.DungDifficulty, Random(20, 41) * dungeon.DungDifficulty, 4));
		int dmg = Enemies.front().Damage * 2;
		player.HP -= dmg;
		cout << "\n Посещая Нарисованный Мир Ариамиса вам встречается высокая полуженщина-полуворона.";
		cout << "\n Демон-ворона высоко взлетает, разгоняется и пикирует, нанося вам урон (" << dmg << "). Ваше здоровье: " << player.HP;
		CheckDeath(player);
		break;
	}
	case 3:
	{

		for (int i = 0; i < 7; i++)
			Enemies.push_back(Enemy(" Крыса [" + to_string(i + 1) + "]", 7, 50 * dungeon.DungDifficulty, 14 * dungeon.DungDifficulty, 2));

		cout << "\n Вы приходите в Глубины, а точнее в нижние части стоков. На вас бежит стая гигантских Крыс.";
		cout << "\n Ваши действия?";
		cout << "\n 1. Убить одну крысу";
		cout << "\n 2. Напасть на несколько крыс";
		switch (ChoiceCheck(2))
		{
		case 1:
			cout << "\n Метким ударом вы убиваете одну из крыс, набрасывающихся на вас.";
			r = Random(0, 7);
			Enemies.at(r).HP = 0;
			break;
		case 2:
			r = Random(0, 4);
			cout << "\n Вы раните трёх крыс на " << player.Damage;
			for (int i = r; i < r + 3; i++)
				Enemies.at(i).HP -= player.Damage;
			break;
		}
		break;
	}
	case 4:
	{
		cout << "\n Вы проходите через врата и оказываетесь в Крепости Сена.";
		cout << "\n Вдалеке вы можете разглядеть двух змеев, шипящих о чём-то своём. Кажется, они вас не видят.";
		Sleep(1000);
		Enemies.push_back(Enemy("Змей-Солдат [1]", 2, Random(40, 55) * dungeon.DungDifficulty, Random(20, 30) * dungeon.DungDifficulty, 2));
		Enemies.push_back(Enemy("Змей-Маг", 2, Random(30, 36) * dungeon.DungDifficulty, Random(50, 60) * dungeon.DungDifficulty, 3));
		Enemies.push_back(Enemy("Змей-Солдат [2]", 2, Random(40, 55) * dungeon.DungDifficulty, Random(20, 30) * dungeon.DungDifficulty, 2));

		if (player.Defence > 100 * dungeon.DungDifficulty)
			cout << "\n Вы замечаете подкрадывающегося к вам Змея-Солдата.\n Он громко шипит, чем привлекает внимание сородичей.";
		else {
			int dmg = DecreaseDmgByDef(Enemies.front().Damage - 5, player.Defence);
			cout << "\n К вас подкрадывается другой Змей и бьёт огромным мечом наотмашь. Вы ранены на " << dmg << ".";
			player.HP -= dmg;
			cout << "\n Ваше здоровье: " << player.HP;
			cout << "\n Те два змея слышат шум и обращают внимание на вас. Похоже, они настроены агрессивно.";
		}
		break;
	}
	case 5:
	{
		cout << "\n Вы спускаетесь в катакомбы, кишащие скелетами. Без лишних слов вы беретесь за оружие и начинаете сражаться с нежитью.";
		for (int i = 0; i < 12; i++)
			Enemies.push_back(Enemy("Скелет [" + to_string(i + 1) + "]", 3, 20 * dungeon.DungDifficulty, 8 * dungeon.DungDifficulty, 1));
		break;
	}
	case 6:
	{
		cout << "\n Вы приходите к Кристальному Гроту. Здесь ходит пара Кристальных Големов.";
		cout << "\n Рядом с вами проходит тропинка, которая позволит избежать боя с одним из Големов. Хотите по ней пройти?";
		cout << "\n 1. Да \n 2. Нет\n";
		if (ChoiceCheck(2) == 1)
			Enemies.push_back(Enemy("Кристальный Голем", 6, 220 * dungeon.DungDifficulty, Random(20, 30) * dungeon.DungDifficulty, 5));
		else
			for (int i = 0; i < 2; i++)
				Enemies.push_back(Enemy("Кристальный Голем [" + to_string(i + 1) + "]", 6, Random(160, 190) * dungeon.DungDifficulty, 25 * dungeon.DungDifficulty, 6));
		break;
	}
	case 7:
	{
		player.HP -= player.TotalHP / 12;
		if (player.HP <= 0)
			player.HP = 1;
		cout << "\n В ходе скитаний вас заносит в Чумной Город. Здешняя атмосфера пагубно сказывается на вашем здоровье (здоровье: " << player.HP << ").";
		Sleep(1000);
		cout << "\n При проходе по доскам на вас нападают Вурдалак и Снайпер с духовой трубкой.";

		Enemies.push_back(Enemy("Вурдалак", 3, Random(80, 105) * dungeon.DungDifficulty, Random(15, 20) * dungeon.DungDifficulty, 3));
		Enemies.push_back(Enemy("Снайпер с духовой трубкой", 0, Random(20, 45) * dungeon.DungDifficulty, 60 * dungeon.DungDifficulty, 4));
		break;
	}
	case 8:
	{
		cout << "\n Вы посещаете руины Хейда. Море здесь поглотило некогда возвышавшийся здесь замок с высокими башнями.";
		cout << "\n Ваш путь лежит к Огненной Башне Хейда, судя по всему являвшаяся когда-то маяком.";
		cout << "\n Пройти к ней вам мешают три Старых рыцаря, вооруженных мечом и щитом. В стороне от пути сидит Рыцарь Хейда и, кажется, дремлет.";
		cout << "\n Что вы хотите сделать?";
		cout << "\n 1. Избавиться от Рыцаря Хейда";
		cout << "\n 2. Проигнорировать Рыцаря Хейда и напасть сразу на Старых Рыцарей";
		if (ChoiceCheck(2) == 1) {
			Enemies.push_back(Enemy("Рыцарь Хейда", 1, Random(60, 75) * dungeon.DungDifficulty, 50 * dungeon.DungDifficulty, 3));

			cout << "\n\n Вы заносите оружие над Рыцарем Хейда, но тот уворачивается от удара и контратакует.";
			int dmg = DecreaseDmgByDef(Enemies.front().Damage, player.Defence);
			player.HP -= dmg;
			cout << "\n Не ожидав такого отпора, вы пропускаете один удар (" << dmg << " урона)...";
			Sleep(1000);
			CheckDeath(player);
			cout << "\n Рыцарь Хейда не так прост, как казался. Он методичными нападениями и уклонениями привёл вас прямиком к Старым Рыцарям.";
			for (int i = 1; i < 4; i++) {
				Enemies.push_back(Enemy("Старый Рыцарь [" + to_string(i + 1) + "]", 6, Random(90, 105) * dungeon.DungDifficulty, Random(15, 20) * dungeon.DungDifficulty, 2));
				Sleep(100);
			}
			if (Random(0, 100) > 70) {
				cout << "\n Вы ловите момент и раните Рыцаря Хейда.";
				Enemies.front().HP -= player.Damage;
				Sleep(500);
				cout << "\n За это один из рыцарей, целясь в вас, делает резкий выпад копьём.";
				dmg = DecreaseDmgByDef(Enemies.at(1).Damage, player.Defence);
				cout << "\n Вам нанесли: " << dmg << ". Ваше здоровье: " << player.HP;
				CheckDeath(player);
			}
		}
		else {
			cout << "\n\n Вы проходите мимо Рыцаря Хейда. И правильно, потому что вы замечаете, что он провожает вас взлядом.";
			cout << "\n Поняв, что вы направляетесь к Старым Рыцарям он хмыкает и прекращает обращать на вас внимание.";
			cout << "\n Зато Старые Рыцари уже увидели вас и приготовились к битве.";
			for (int i = 0; i < 3; i++)
				Enemies.push_back(Enemy("Старый Рыцарь [" + to_string(i + 1) + "]", 6, Random(90, 105) * dungeon.DungDifficulty, Random(15, 20) * dungeon.DungDifficulty, 2));
		}

		break;
	}
	case 9:
	{
		cout << "\n В своих странствиях вы посещаете Катакомбы. У моста с шипами вы встречаете человека, представившегося \"Лоскутиком\".";
		cout << "\n Лоскутик: Приветствую! Похоже, ты вполне в своем уме! Что ты делаешь в Катакомбах? Ты клирик или что-то в этом духе?";
		cout << "\n 1. Да";
		cout << "\n 2. Нет";
		Enemies.push_back(Enemy("Верный Лоскутик", 1, Random(120, 130) * dungeon.DungDifficulty, 50 * dungeon.DungDifficulty, 6));
		int answer = (ChoiceCheck(2));
		if (answer == 1)
			cout << "\n Лоскутик: Да, так мне и представлялось. Удачи в твоем паломничестве или миссии - и вообще во всех твоих делах. Это опасное место, так что смотри под ноги. Хе-хе-хе.";
		else
			cout << "\n Лоскутик: Нет? Пожалуй, это странно. О, я знаю, в чем дело. Тебе нужны амулеты, правильно? Ну, что бы там ни было... Это опасное место, так что смотри под ноги. Хе-хе-хе.";
		cout << "\n Несмотря на это, Лоскутик рушит мост, по которому вы идёте. Вы решаете встретиться с ним и поговорить ещё раз.";
		if (answer == 1)
			cout << "\n Вы находите Лоскутика. Он ехидно ухмыляется и поднимает своё копьё.\n Лоскутик : Вот теперь - то поговорим, клирик.";
		else
		{
			vector<Enemy>().swap(Enemies);
			cout << "\n Лоскутик: Ай, ой! Так, и как твои дела? Видишь ли, я дернул тот рычаг... Надеюсь, тебе это не доставило лишних неприятностей?";
			cout << "\n 1. Да";
			cout << "\n 2. Нет";
			if (ChoiceCheck(2) == 1) {
				cout << "\n Лоскутик: Точно?! Да, неловко вышло. Мне очень жаль, правда! "
					<< "\n Лоскутик: Но погоди, получается, что это не я тебя сюда уронил? Надо было раньше сказать! Хорошо то, что хорошо кончается! "
					<< "\n Лоскутик: Все делают ошибки. И я не исключение! Я, Верный Лоскутик, единственный и неповторимый! Я знаю! Это должно сработать. "
					<< "\n Лоскутик: Мы на одной стороне! Изгнанные мертвецы! По-моему, дивно. Хе-хе-хе.";
				cout << "\n С Этими словами Лоскутик передаёт вам 100 золотых.";
				player.Gold += 100;
			}
			else {
				cout << "\n Лоскутик: Неужели? Понятно! Значит, все в порядке? Я, Верный Лоскутик, единственный и неповторимый!";
				cout << "\n Лоскутик: Ты и я, просто изгнанные мертвецы, правда, дружище?";
			}
			Sleep(5000);
			goto label;
		}
	}
	}
	if (!Enemies.empty()) {
		cout << "\n Нажмите любую клавишу, чтобы начать бой";
		GetKey();
		Combat(player, companion, Enemies);
		cout << "\n Битва завершена. Вот ваша награда:\n";
		BattleReward = CalculateReward(dungeon.DungDifficulty, Enemies);
		cout << " Опыт: " << BattleReward.Experience << "\t Золото: " << BattleReward.Gold;
		GiveReward(player, BattleReward);
	}
label:
	cout << "\n\n Нажмите любую клавишу, чтобы перейти на следующий этаж. ";
	GetKey();
}
void ChooseRandomBoss(Player& player, Companion& companion, SomeDungeon& dungeon)
{
	DungeonBoss boss = DungeonBoss("КАК????", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	Reward BattleReward;
	system("cls");
	switch (Random(0, 5)) {
	case 0:
	{
		cout << "\n Вы исследуете башни Города Нежити. На одной из стен к вам с башни напротив спрыгивает Демон-Телец.";
		cout << "\n Демон встаёт на четыре лапы и мчится на вас, стремясь протаранить.";
		cout << "\n Ваши действия?";
		cout << "\n 1. Встретить демона атакой";
		cout << "\n 2. Попытаться уклониться";
		boss = DungeonBoss("Демон-Телец", 4,
			Random(300, 500) * dungeon.DungDifficulty,
			Random(40, 60) * dungeon.DungDifficulty,
			70, 5, Random(100, 300) * dungeon.DungDifficulty,
			100 * dungeon.DungDifficulty, 0, 0, 3);
		Sleep(13);

		int dmg = DecreaseDmgByDef(boss.Damage * 1.5, player.Defence);
		switch (ChoiceCheck(2))
		{
		case 1:
			cout << "\n Вы успеваете ранить Демона-Тельца перед тем как он протаранит вас и кинет об башню.\n";
			player.HP -= dmg;
			player.HP -= 10;
			cout << "\n Демон-Телец нанёс вам " << dmg + 10 << " урона. Ваше здоровье: " << player.HP;
			dmg = DecreaseDmgByDef(player.MinDamage, boss.Defence);
			boss.HP -= dmg;
			cout << "\n Вы нанесли Демону-Тельцу " << dmg << " урона. Здоровье Демона-Тельца: " << boss.HP;
			CheckDeath(boss);
			break;
		case 2:
			if (Random(0, 100) > 80)
			{
				cout << "\n Вы успешно уклонились от Демона-Тельца. Он врезается в башню и получает 50 урона.";
				boss.HP -= 50;
			}
			else {
				player.HP -= dmg;
				cout << "\n Демон-Телец таранит вас. Вы получаете " << dmg << " урона. Ваше здоровье: " << player.HP;
			}

			break;
		}
		CheckDeath(player);
	}
	break;
	case 1:
	{
		cout << "\n Пройдя через врата, вы попадайте в разрушенный город, известный в легендах как Изалит.  Путь в город преграждает демон Капра.";
		cout << "\n Замечая вас, он встаёт в боевую стойку и преграждает вам путь, тогда как путь назад отрезает стена из огня. Битвы не избежать.";
		boss = DungeonBoss("Демон Капра", 4,
			500 * dungeon.DungDifficulty,
			Random(10, 20) * dungeon.DungDifficulty,
			-35, 6, Random(150, 300) * dungeon.DungDifficulty,
			150 * dungeon.DungDifficulty, 15, 2, 3);
	}
	break;
	case 2:
	{
		cout << "\n Вы идёте по мосту в сторону Уезда Нежити. Вы видите вдалеке небольшие отряды полых и уже готовитесь к бою...";
		cout << "\n Но внезапно с арки над мостом слетает Красная виверна и поливает огнём отряды полых.";
		cout << "\n Виверна садится на середину моста и идёт по мосту спиной к вам. Не похоже, что она собирается уходить отсюда.";
		cout << "\n Вы решаете воспользоваться моментом и атакуете виверну.";
		boss = DungeonBoss("Красная виверна", 5,
			430 * dungeon.DungDifficulty,
			80 * dungeon.DungDifficulty,
			140, 7, 100 * dungeon.DungDifficulty,
			Random(250, 500) * dungeon.DungDifficulty, 25, 1, 4);
		boss.HP -= (player.Damage + player.MagicPower);
	}
	break;
	case 3:
	{
		cout << "\n Во время посещения древних захоронений, на вас нападает Лич.";
		boss = DungeonBoss("Лич", 3,
			350 * dungeon.DungDifficulty,
			40 * dungeon.DungDifficulty,
			56, 8, Random(300, 500) * dungeon.DungDifficulty,
			Random(250, 400) * dungeon.DungDifficulty, 5, 3, 2);
	}
	break;
	case 4:
	{
		cout << "\n В Крепости Сена, в одной из башен вам встречается человек в доспехах элитного рыцаря.";
		cout << "\n На первый взгляд кажется, что это один из немногих выживших людей, но его поведение говорит о том, что он обращён в полого и полностью выжил из ума.";
		cout << "\n Он выглядит богатым и судя по всему принц, родом из Асторы. Вы решаете, что сможете немного заработать на его смерти.";
		boss = DungeonBoss("Полый принц из Асторы", 2,
			300 * dungeon.DungDifficulty,
			120 * dungeon.DungDifficulty,
			100, 6, Random(500, 1500) * dungeon.DungDifficulty,
			Random(200, 450) * dungeon.DungDifficulty, 35, 4, 3);
	}
	break;
	}
	cout << "\n Начинается бой...";
	Sleep(3000);
	Combat(player, companion, boss);

	cout << "\n Битва с боссом завершена. Вот ваша награда:\n";
	BattleReward = CalculateReward(dungeon.DungDifficulty, boss);
	cout << " Опыт: " << BattleReward.Experience << "\t Золото: " << BattleReward.Gold;
	GiveReward(player, BattleReward);
	cout << "\n\n Нажмите любую клавишу, чтобы покинуть данж и вернуться в главное меню. ";
	GetKey();
}
void HeroStats(Player& player)
{
	system("cls");
	cout << "\n " << player.Name << " характеристики: \n";
	cout << " Класс: " << player.Class << "\n";
	cout << " Уровень: " << player.Level << "\n";
	cout << " Опыт: " << player.Experience << " / " << player.MaxExp << "\n";
	cout << " Здоровье: " << player.HP << " / " << player.TotalHP << "\n";
	cout << " Средний урон: " << (player.Damage + player.MinDamage) / 2.0 << "\n";
	cout << " Защита: " << player.Defence << "\n";
	cout << " Магическая сила: " << player.MagicPower << "\n";
	cout << " Мана: " << player.Mana << " / " << player.MaxMana << "\n";
	cout << " Золото: " << player.Gold << "\n";
	cout << " \n";
	cout << " Инвентарь: \n";

	for (int i = 0; i < player.Inventory.size(); i++)
		cout << " |" << player.Inventory.at(i).Name << " - " << player.Inventory.at(i).Quantity << "| ";

	cout << endl << endl;
	cout << " Нажмите любую кнопку, чтобы вернуться в главное меню" << endl;
	GetKey();
}
void HeroArmy(Player& player, Companion& companion)
{
	system("cls");
	cout << "\n Отряд " << player.Name << ":";
	cout << "\n\n " << player.Name << "\nКласс: " << player.Class << "\tЗдоровье: " << player.HP << " / " << player.TotalHP << "\tЗащита: " << player.Defence << "\tУрон: " << (player.MinDamage + player.Damage) / 2.0;
	cout << "\n\n " << companion.Name << "\nКласс: " << companion.Class << "\tЗдоровье: " << companion.HP << " / " << companion.TotalHP << "\tЗащита: " << companion.Defence << "\tУрон: " << companion.Damage;
	cout << "\n\n Нажмите любую кнопку, чтобы вернуться в главное меню \n";
	GetKey();
}