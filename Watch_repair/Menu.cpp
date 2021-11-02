#include"Menu.h"
#include"Order.h"
#include"Error.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Menu::ShowMenu()
{
	char userInput;

	do {
		showMainMenu();
		cin >> userInput;
		safeHandleUserInput(userInput);

		cout << endl;
	} while (userInput != '0');
}


void Menu::showMainMenu()
{
	cout << "������ ���������:\n������� �����:\n";
	cout << "1 - ������ ���� ����������;\n";
	cout << "2 - ������� �� ����������;\n";
	cout << "3 - �������� ����������;\n";
	cout << "0 - �����.\n";
}


void Menu::showAndHadnleAddOrderMenu()
{
	Order order;

	cin >> order;

	orders.add(order);
	cout << "���������� ������ ������ ;)\n";
}

void Menu::showAndHadnleRemoveOrderMenu()
{
	int idx;
	cout << "������ ����� ���������\n";
	cin >> idx;

	orders.RemoveOrder(idx);
	cout << "���������� ���������\n";
}

void Menu::safeHandleUserInput(char userInput)
{
	try
	{
		handleUserInput(userInput);
	}
	catch (Error& error)
	{
		cout << "������� �������!\n " << error.ToString() << endl;
	}
	catch (...)
	{
		cout << "³������� ������� �������!" << endl;
	}
}

//void Menu::WriteOrderToFile(OrderArr orders)
//{
//	//todo
//
//	ofstream fout;
//	fout.open("Order.txt");
//
//	//fout.write((char*)&order, sizeof(Order));
//	for (int i=0; i<n; i++)
//	fout << orders[i].getname() << "," <
//	fout.close();
//}
//
//void Menu::ReadOrderFromFile()
//{
//	//todo
//	//open file
//	//loop cars from file: AddCar()
//	//close
//	Order order2;
//	ifstream fin;
//	fin.open("Order.txt");
//	fin.read((char*)&order2, sizeof(order2));
//	orders.add(order2);
//	orders.print();
//	fin.close();
//}

void Menu::handleUserInput(char userInput)
{
	switch (userInput)
	{
	case '1':
		showAndHadnleAddOrderMenu();
		break;
	case '2':
		//orders.ReadOrderFromFile();
		orders.print();
		cout << endl;
		break;
	case '3':
		showAndHadnleRemoveOrderMenu();
		break;
	case '4':
		//orders.WriteOrderToFile();
		break;
	case '0':
		break;
	default:
		cout << "������� ����������� �������\n";
		break;
	}
}
