#pragma once
#include <string>
using namespace std;

//Класс данжа, куда отправляется игрок
class SomeDungeon {
public:
	string DungType;
	double DungDifficulty;
	int DungFloorsCount;
	int DungCurFloor;
	double isDungBoss;
};