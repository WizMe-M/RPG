#include "Player.h"
#include <iostream>
#include "Windows.h"

using namespace std;

Player create()
{
	Player player;
	bool IsRunning = true;

	cout << " Введите имя персонажа: ";
	cin >> player.PlayerName;

	cout << " \n";

	player.PlayerHP = 100;
	player.PlayerLevel = 1;

	cout << " Выберите класс персонажа: \n\n";

	string ClassesDescription[3] = { " 1. Воин – имеет большое количество здоровья и повышенную защиту, хорошие показатели атаки, но"
		" плохие показатели знаний и отсутствие магической силы.\n\n"
		" 2. Лучник – высокий урон, средние показатели здоровья и знаний, но отсутствует магическая сила и класс имеет плохую защиту.\n\n"
		" 3. Маг – средние показатели здоровья, плохие показатели урона в рукопашном бою и защиты. Однако, класс имеет высокие показатели"
		" магической силы и знаний." };

	for (int i = 0; i < 3; i++)
	{
		cout << ClassesDescription[i] << " \n";
	}

	int Choice = 0;

	cout << " 1 - выбрать класс 'Воин'.\n";
	cout << " 2 - выбрать класс 'Лучник'.\n";
	cout << " 3 - выбрать класс 'Маг'.\n";

	cout << " \n";

	while (Choice < 1 || Choice > 3) 
	{
		cout << " Выбор класса: ";
		cin >> Choice;
	}

	switch (Choice)
	{ 
	case 1: 
	{ 
		player.PlayerClass = "Воин";
	} 
	break;
	case 2: 
	{ 
		player.PlayerClass = "Лучник";
	} 
	break;
	case 3: 
	{ 
		player.PlayerClass = "Маг";
	} 
	break;
	default:
	{
		cout << " Такого класса не существует.";
	}
	break;
	}

	cout << " Класс вашего персонажа - " << player.PlayerClass << ".\n";
	Sleep(3000);

	int Counter = 0;

	system("cls");

	for (int i = 0; i <= Counter; i++) 
	{
		if (i == 0)
			cout << " Создаём персонажа.\n";
		if (i == 1)
			cout << " Создаём персонажа..\n";
		if (i == 2) 
		{
			cout << " Создаём персонажа...\n";
			break;
		}

		Sleep(400);
		system("cls");
		Counter++;
	}

	if (player.PlayerClass == "Воин")
	{
		player.PlayerTotalHP = 120;
		player.PlayerHP = 120;
		player.PlayerMinDamage = 10;
		player.PlayerDamage = 15;
		player.PlayerDefence = 15;
		player.PlayerKnowledge = 10;
		player.PlayerMagicPower = 0;
		player.PlayerMana = 0;
		player.PlayerGold = 100;
		player.CurrentInventoryCapacity = 0;
		player.InventoryMaxCapacity = 15;

	}

	if (player.PlayerClass == "Лучник")
	{
		player.PlayerTotalHP = 90;
		player.PlayerHP = 90;
		player.PlayerMinDamage = 15;
		player.PlayerDamage = 20;
		player.PlayerDefence = 5;
		player.PlayerKnowledge = 20;
		player.PlayerMagicPower = 0;
		player.PlayerMana = 0;
		player.PlayerGold = 100;
		player.CurrentInventoryCapacity = 0;
		player.InventoryMaxCapacity = 15;
	}

	if (player.PlayerClass == "Маг")
	{
		player.PlayerTotalHP = 80;
		player.PlayerHP = 80;
		player.PlayerMinDamage = 2;
		player.PlayerDamage = 5;
		player.PlayerDefence = 5;
		player.PlayerKnowledge = 30;
		player.PlayerMagicPower = 20;
		player.PlayerMana = 100;
		player.PlayerGold = 100;
		player.CurrentInventoryCapacity = 0;
		player.InventoryMaxCapacity = 15;
	}

	system("cls");

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

	Sleep(5000);

	system("cls");

	char Intro[] = " Вы пробудились в тюремной камере, лишённый каких-либо воспоминаний о прошлом и том, как именно вы сюда попали. Рядом с вами"
		" сидит нечто отдалённо напоминающее человека.\n";
	char Intro2[] = " Вступив в диалог с незнакомцем, представившимся Лаврентием, он рассказал, что вы попали"
		" в тюремную камеру вместе, а также поведал вам о ситуации в мире.\n";
	char Intro3[] = " Оказалось, что вы, как и Лаврентий, являйтесь нежитью и вас заточили в тюрьме, находящейся далеко на севере от королевства"
		" Лордран.\n";
	char Intro4[] = " Лаврентий, каким-то образом умудрившийся сохранить память и рассудок, сообщил, что нежить ссылается сюда стражами"
		" королевства, дабы предотвратить атаки обезумевшей полой нежити, потерявшей свою человечность,\n"
		" на обычных граждан.\n";
	char Intro5[] = " Лаврентий объяснил, что нежитью становятся те, кто поражён проклятьем. Люди поражённые проклчтьем отмечены Знаком Тьмы,"
		" а сутью проклятья является бессмертие. Нежить не может умереть, она будет бесконечно\n возрождаться и с каждым своим возрождением терять"
		" человечность. Потеря человечности означает постепенную потерю рассудка, воспоминаний, воли к жизни. В конце концов нежить, у которой"
		" не осталось ни капли\n человечности, становится полой нежитью. Полая нежить не имеет никаких стремлений и целей в жизни, если, конечно,"
		" бодобное бытие можно назвать жизнью. Она лишь бесцельно бродит по тем, территориям, которые\n вызывают в угасающем сознании какой-то"
		" отклик, напоминающий о прошлой жизни, и нападает на тех, кто находится в непосредственной близости к ней.\n"
		" Лаврентий точно не знает природу возникновения проклятья в этом мире, но сокармерник рассказал способ, который может победить проклятье"
		" нежити в этом мире навсегда.\n";
	char Intro6[] = " О способе избавления от проклятья Лаврентий узнал из легенд своей семьи. Легенда гласит о некой избранной нежити,"
		" которая должна позвонить в колокол. Как только это свершится сами боги Анор-Лондо направят\n избранную нежить на путь спасения"
		" всего человечества от проклятья\n";
	char Intro7[] = " Лаврентий предлагает вам бежать из заточения, обрести цель в жизни и исполнить пророчество. Вы соглашайтесь с Лаврентием и"
		" вместе отправляйтесь в опасное путешествие, ибо прошлого и будущего у вас нет, а в\n"
		" исполнении пророчества вы обретайте цель и смысл жизни, а также надежду на спасение всего человеческого рода.\n";
	char Intro8[] = " Выбравшись из камеры, победив единственного стража прибежища в лице демона, вы и Лаврентий благодаря гигансткому ворону,"
		" присланному самими Богами, покидайте Северное прибежище нежити и попадайте в земли\n Лордрана, Город нежити.\n";

	for (int i = 0; i < strlen(Intro); i++, Sleep(100))
		cout << Intro[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro2); i++, Sleep(100))
		cout << Intro2[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro3); i++, Sleep(100))
		cout << Intro3[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro4); i++, Sleep(100))
		cout << Intro4[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro5); i++, Sleep(100))
		cout << Intro5[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro6); i++, Sleep(100))
		cout << Intro6[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro7); i++, Sleep(100))
		cout << Intro7[i];
	Sleep(3000);

	system("cls");

	for (int i = 0; i < strlen(Intro8); i++, Sleep(100))
		cout << Intro8[i];
	Sleep(3000);

	system("cls");

	return player;
}


