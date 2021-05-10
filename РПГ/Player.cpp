#pragma once
#include "Player.h"
#include <conio.h>
using namespace std;
Player create()
{
	Player player;
	cout << "\n\t<-- Введите имя персонажа -->\n ";
	do {
		getline(cin, player.Name);

	} while (player.Name.empty());

	cout << "\n\n\t<-- Выберите класс персонажа -->\n\n";

	string ClassesDescription =
		" 1. Воин – имеет большое количество здоровья и повышенную защиту, хорошие показатели атаки, но полностью отсутствуют магические силы.\n\n"
		" 2. Лучник – высокий урон, средние показатели здоровья, защиты и магической силы, крайне скудные запасы маны.\n\n"
		" 3. Маг – низкие показатели здоровья, ужасные показатели урона в рукопашном бою и защиты, однако класс"
		" имеет высокие показатели магической силы и обладает больши запасом маны.\n\n";
	cout << ClassesDescription << " \n";


	int Choice = 0;

	cout << " 1 - выбрать класс 'Воин'.\n";
	cout << " 2 - выбрать класс 'Лучник'.\n";
	cout << " 3 - выбрать класс 'Маг'.\n";
	cout << " \n\n";

	cout << " <-- Выбор класса --> ";
	switch (ChoiceCheck(3))
	{
	case 1:
	{
		//базовые статы
		player.Class = "Воин";
		player.TotalHP = 120;
		player.MinDamage = 15;
		player.Damage = 20;
		player.Defence = 35;
		player.MagicPower = 0;
		player.Mana = 0;

		//статы за лвл
		player.HPperLVL = 25;
		player.DMGperLVL = 9;
		player.DEFperLVL = 10;
		player.MPperLVL = 0;
		player.MANAperLVL = 0;
		break;
	}
	case 2:
	{
		//базовые статы
		player.Class = "Лучник";
		player.TotalHP = 90;
		player.MinDamage = 25;
		player.Damage = 35;
		player.Defence = 5;
		player.MagicPower = 0;
		player.Mana = 25;

		//статы за лвл
		player.HPperLVL = 14;
		player.DMGperLVL = 13;
		player.DEFperLVL = 4;
		player.MPperLVL = 5;
		player.MANAperLVL = 10;
		break;
	}
	case 3:
	{
		//базовые статы
		player.Class = "Маг";
		player.TotalHP = 80;
		player.MinDamage = 5;
		player.Damage = 10;
		player.Defence = 5;
		player.MagicPower = 20;
		player.Mana = 100;

		//статы за лвл
		player.HPperLVL = 5;
		player.DMGperLVL = 5;
		player.DEFperLVL = 0;
		player.MPperLVL = 15;
		player.MANAperLVL = 30;
		break;
	}
	}
	player.HP = player.TotalHP;
	player.MaxMana = player.Mana;
	player.Gold = 100;
	player.InventoryMaxCapacity = 10;
	player.Inventory.push_back(Item("Эстус", 0, 3));
	player.haveCompanion = true;
	player.SpecialAbilityCooldown = 0;
	player.EnemiesKilledCount = 0;
	player.Level = 1;
	player.Experience = 0;
	player.MaxExp = 50;
	system("cls");
	cout << "\n\n\tСоздаём персонажа";
	for (int i = 0; i < 3; i++)
	{
		Sleep(600);
		cout << ".";
	}
	Sleep(100);
	system("cls");
	cout << " " << player.Name << " характеристики: \n";
	cout << " Класс: " << player.Class << "\n";
	cout << " Уровень: " << player.Level << "\n";
	cout << " Опыт: " << player.Experience << " / " << player.MaxExp << "\n";
	cout << " Здоровье: " << player.HP << " / " << player.TotalHP << "\n";
	cout << " Урон: " << (player.Damage + player.MinDamage) / 2 << "\n";
	cout << " Защита: " << player.Defence << "\n";
	cout << " Магическая сила: " << player.MagicPower << "\n";
	cout << " Мана: " << player.Mana << " / " << player.MaxMana << "\n";
	cout << " Золото: " << player.Gold << "\n";
	cout << " \n";
	cout << " Нажмите любую кнопку, чтобы продолжить" << endl;
	GetKey();
	system("cls");

	{
		//	char Intro[] = " Вы пробудились в тюремной камере, лишённый каких-либо воспоминаний о прошлом и том, как именно вы сюда попали. Рядом с вами"
		//		" сидит нечто отдалённо напоминающее человека.\n";
		//	char Intro2[] = " Вступив в диалог с незнакомцем, представившимся Лаврентием, он рассказал, что вы попали"
		//		" в тюремную камеру вместе, а также поведал вам о ситуации в мире.\n";
		//	char Intro3[] = " Оказалось, что вы, как и Лаврентий, являйтесь нежитью и вас заточили в тюрьме, находящейся далеко на севере от королевства"
		//		" Лордран.\n";
		//	char Intro4[] = " Лаврентий, каким-то образом умудрившийся сохранить память и рассудок, сообщил, что нежить ссылается сюда стражами"
		//		" королевства, дабы предотвратить атаки обезумевшей полой нежити, потерявшей свою человечность,\n"
		//		" на обычных граждан.\n";
		//	char Intro5[] = " Лаврентий объяснил, что нежитью становятся те, кто поражён проклятьем. Люди поражённые проклчтьем отмечены Знаком Тьмы,"
		//		" а сутью проклятья является бессмертие. Нежить не может умереть, она будет бесконечно\n возрождаться и с каждым своим возрождением терять"
		//		" человечность. Потеря человечности означает постепенную потерю рассудка, воспоминаний, воли к жизни. В конце концов нежить, у которой"
		//		" не осталось ни капли\n человечности, становится полой нежитью. Полая нежить не имеет никаких стремлений и целей в жизни, если, конечно,"
		//		" бодобное бытие можно назвать жизнью. Она лишь бесцельно бродит по тем, территориям, которые\n вызывают в угасающем сознании какой-то"
		//		" отклик, напоминающий о прошлой жизни, и нападает на тех, кто находится в непосредственной близости к ней.\n"
		//		" Лаврентий точно не знает природу возникновения проклятья в этом мире, но сокармерник рассказал способ, который может победить проклятье"
		//		" нежити в этом мире навсегда.\n";
		//	char Intro6[] = " О способе избавления от проклятья Лаврентий узнал из легенд своей семьи. Легенда гласит о некой избранной нежити,"
		//		" которая должна позвонить в колокол. Как только это свершится сами боги Анор-Лондо направят\n избранную нежить на путь спасения"
		//		" всего человечества от проклятья\n";
		//	char Intro7[] = " Лаврентий предлагает вам бежать из заточения, обрести цель в жизни и исполнить пророчество. Вы соглашайтесь с Лаврентием и"
		//		" вместе отправляйтесь в опасное путешествие, ибо прошлого и будущего у вас нет, а в\n"
		//		" исполнении пророчества вы обретайте цель и смысл жизни, а также надежду на спасение всего человеческого рода.\n";
		//	char Intro8[] = " Выбравшись из камеры, победив единственного стража прибежища в лице демона, вы и Лаврентий благодаря гигансткому ворону,"
		//		" присланному самими Богами, покидайте Северное прибежище нежити и попадайте в земли\n Лордрана, Город нежити.\n";

		//	for (int i = 0; i < strlen(Intro); i++, Sleep(80))
		//		cout << Intro[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro2); i++, Sleep(80))
		//		cout << Intro2[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro3); i++, Sleep(80))
		//		cout << Intro3[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro4); i++, Sleep(80))
		//		cout << Intro4[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro5); i++, Sleep(80))
		//		cout << Intro5[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro6); i++, Sleep(80))
		//		cout << Intro6[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro7); i++, Sleep(80))
		//		cout << Intro7[i];
		//	Sleep(3000);

		//	system("cls");

		//	for (int i = 0; i < strlen(Intro8); i++, Sleep(80))
		//		cout << Intro8[i];
		//	Sleep(3000);
	}
	return player;
}

int ChoiceCheck(int max)
{
	int Choice = 0;
	while (Choice > max || Choice <= 0)
	{
		cout << "\n Выбор: ";
		Choice = InputStringToInt();
	}
	return Choice;
}
int InputStringToInt() {
	string input;
	do {
		getline(cin, input);
	} while (!input.find_first_not_of("0123456789") || input.empty());
	return stoi(input);
}
void GetKey() {
	int i = _getch();
}