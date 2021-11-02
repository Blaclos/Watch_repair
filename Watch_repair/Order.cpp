#include "Order.h"
#include <iostream>
#include <string>

using namespace std;


void Order::init(const char* name, const char* surname, int prise, int time)
{
	this->prise = prise;
	this->time = time;
	if (prise < 0)
		throw Error(ErrorCode::NegativePrise);

	if (time < 0)
		throw Error(ErrorCode::NegativeTime);

	int size = strlen(name) + 1;
	this->name = new char[size];
	strcpy_s(this->name, size, name);

	size = strlen(surname) + 1;
	this->surname = new char[size];
	strcpy_s(this->surname, size, surname);
}


Order::Order(const char* name, const char* surname, int prise, int time)
{
	init(name, surname, prise, time);
}

Order::~Order()
{
	delete[] name;
	delete[] surname;
}

Order::Order(const Order& order) : Order(order.name, order.surname, order.prise, order.time) {}

Order& Order::operator=(const Order& order)
{
	if (this == &order)
	{
		return *this;
	}
	delete[] this->name;
	delete[] this->surname;
	init(order.name, order.surname, order.prise, order.time);
	return *this;
}

ostream& Order::operator<<(ostream& out)
{
	return out << "Ім'я і прізвище замовника: " << name << " " << surname << "\nЦіна ремонту : " << prise << "\nЧас роботи(в днях): " << time << endl;
}

ostream& operator<<(ostream& out, Order& order)
{
	return order << cout;
}

void Order::Print()
{
	cout << "Ім'я і прізвище замовника: " << (char)&name << " " << (char)&surname << "\nЦіна ремонту : " << prise << "\nЧас роботи(в днях): " << time << endl;
}

istream& operator>>(istream& in, Order& order)
{
	
	char* name = new char[50];
	char* surname = new char[50];
	int prise;
	int time;

	cout << "Введіть дані:\n";
	cout << "Ім'я замовника: ";
	in >>  name;
	cout << "Прізвище замовника: ";
	in >> surname;
	cout << "Ціна ремонту годинника: ";
	in >> prise;
	cout << "Через скільки днів забрати замовлення: ";
	in >> time;

	order = Order(name, surname, prise, time);

	return in;
}


