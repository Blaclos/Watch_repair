#pragma once
#include "Error.h"
#include <cstring>
#include <iostream>
using namespace std;

class Order
{
public:
	Order(const char* name = "", const char* surname = "",int prise = 0, int time = 0);
	Order(const Order& order);
	~Order();
	void Print();

	Order& operator=(const Order& order);


	ostream& operator<<(ostream& out);

	friend ostream& operator<<(ostream& out, Order& order);

	friend istream& operator>>(istream& in, Order& order);



private:
	char* name;
	char* surname;
	int prise;
	int time;

	void init(const char* name, const char* surname, int prise, int time);

};