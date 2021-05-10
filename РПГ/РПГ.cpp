#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
#include "MenuMethods.h"
#include "Player.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	COORD coord;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	cout << "\n\tУ вас есть созданный персонаж?";
	cout << "\n\t1. Да";
	cout << "\n\t2. Нет\n";
	if (ChoiceCheck(2) == 1) {
		cout << "\n\tВведите имя персонажа:\n\t";
		string name;
		getline(cin, name);
		cout << "\n";
		string path = "D:\\saves\\" + name + ".txt";
		ifstream a;
		string f;
		int n;
		Companion c;
		Shop s;
		Player p;
		p.Name = name;
		a.open(path);

		if (a.is_open())
		{
			a >> p.Class;
			a >> p.Level; 
			a >> p.Experience;
			a >> p.MaxExp;
			a >> p.HP;
			a >> p.TotalHP;
			a >> p.Defence;
			a >> p.MinDamage;
			a >> p.Damage;
			a >> p.MagicPower;
			a >> p.Mana;
			a >> p.MaxMana;
			a >> p.Gold;
			a >> p.HPperLVL;
			a >> p.DMGperLVL;
			a >> p.DEFperLVL;
			a >> p.MPperLVL;
			a >> p.MANAperLVL;
			a >> p.haveCompanion;
			a >> p.EnemiesKilledCount;
			int n; a >> n;
			if (n != 0)
				for (int i = 0; i < n; i++) {
					Item item;
					a >> item.Name;
					a >> item.Price;
					a >> item.Quantity;
					p.Inventory.push_back(item);
				}

			a >> c.Name;
			a >> c.Class;
			a >> c.HP;
			a >> c.TotalHP;
			a >> c.Defence;
			a >> c.CurAttackCount;
			a >> c.MaxAttackCount;
			a >> c.Damage;

			a >> n;
			if (n != 0);
			for (int i = 0; i < n; i++) {
				Companion comp;
				a >> comp.Name;
				a >> comp.Class;
				a >> comp.HP;
				a >> comp.TotalHP;
				a >> comp.Defence;
				a >> comp.CurAttackCount;
				a >> comp.MaxAttackCount;
				a >> comp.Damage;
				a >> comp.Price;
				a >> comp.isSold;
				s.Companions.push_back(comp);
			}
			
			a >> n;
			if (n != 0);
			for (int i = 0; i < n; i++) {
				Item item;
				a >> item.Name;
				a >> item.Price;
				a >> item.Quantity;
				s.Items.push_back(item);
			}
			a.close();

			MainMenu(p, c, s);

		}
		else
		{
			cout << "\n\tПерсонаж с таким именем не существует.";
			Sleep(2000);
		}
	}
	system("cls");
	Player player = create();

	Companion companion("Лаврентий", "Воин", 160, 120, 35, 10, 20, 40, true, 0);
	Shop shop;
	shop.Companions.push_back(Companion("Лоскутик", "Воин", 200, 200, 49, 30, 30, 60, false, 500));
	shop.Items.push_back(Item("Эстус", 100, 50));

	MainMenu(player, companion, shop);
}