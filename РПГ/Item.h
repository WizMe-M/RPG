#pragma once
#include <string>

using namespace std;


//����� ��������
class Item {
public:
	string Name;
	int Price;
	int Quantity;
	Item() {
		Name = "�����";
		Price = 0;
		Quantity = 3;
	}
	Item(string name, int price, int quantity) {
		Name = name;
		Price = price;
		Quantity = quantity;
	}
};

