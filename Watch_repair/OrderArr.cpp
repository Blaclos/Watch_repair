#include "OrderArr.h"
#include "Order.h"
#include "Error.h"
#include <iostream>
#include <fstream>
using namespace std;



OrderArr::OrderArr(int maxCapacity): orderRepository(maxCapacity){}

OrderArr::~OrderArr(){}

void OrderArr::add(Order& order)
{
	orderRepository.Add(order);
}

void OrderArr::RemoveOrder(int idx)
{
	orderRepository.Remove(idx);
}

void OrderArr::print()
{
	orderRepository.Print();
}


/*
void OrderArr::add(Order& order)
{
	if (currentSize >= maxSize)
	{
		throw Error(ErrorCode::MaxSizeReached);
	}
	orderArr[currentSize++] = order;
}

void OrderArr::print()
{
	for (int i = 0; i < currentSize; i++)
	{
		cout << "\nЗамовлення №" << i+1 << endl << orderArr[i] << endl;
	}
}

OrderArr::OrderArr(int size)
{
	orderArr = new Order[size];
	this->maxSize = size;
}

OrderArr::~OrderArr()
{
	delete[] orderArr;
}

Order& OrderArr::operator[](int idx)
{
	return this->orderArr[idx];
}

void OrderArr::RemoveOrder(int idx)
{
	if (idx < 1 || idx > currentSize)
		throw Error(ErrorCode::IdxOutsideLimit);

	for (int i = idx-1; i < (currentSize - 1); i++)
		orderArr[i] = orderArr[i + 1];

	currentSize--;
}

void OrderArr::ReadOrderFromFile()
{
	Order order;
	ifstream fin;
	fin.open("Order.txt");
	//while (fin.read((char*)&order, sizeof(order)))
	//{
	//	cout << '5';
	//	//order.Print();

	//}
	fin.read((char*)&order, sizeof(order));
	fin.close();
	
}

void OrderArr::WriteOrderToFile()
{
	ofstream fout;         
	fout.open("Order.txt");
	//ofstream fout("Order.txt");
	for (int i = 0; i < currentSize; i++)
	{
		fout.write((char*)&orderArr[i], sizeof(Order));
	}
	fout.close();
}
*/