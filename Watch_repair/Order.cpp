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
	return out << "��'� � ������� ���������: " << name << " " << surname << "\nֳ�� ������� : " << prise << "\n��� ������(� ����): " << time << endl;
}

ostream& operator<<(ostream& out, Order& order)
{
	return order << cout;
}

void Order::Print()
{
	cout << "��'� � ������� ���������: " << (char)&name << " " << (char)&surname << "\nֳ�� ������� : " << prise << "\n��� ������(� ����): " << time << endl;
}

istream& operator>>(istream& in, Order& order)
{
	
	char* name = new char[50];
	char* surname = new char[50];
	int prise;
	int time;

	cout << "������ ���:\n";
	cout << "��'� ���������: ";
	in >>  name;
	cout << "������� ���������: ";
	in >> surname;
	cout << "ֳ�� ������� ���������: ";
	in >> prise;
	cout << "����� ������ ��� ������� ����������: ";
	in >> time;

	order = Order(name, surname, prise, time);

	return in;
}


