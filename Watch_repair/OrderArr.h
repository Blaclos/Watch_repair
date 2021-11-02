#pragma once
#include "Order.h"
#include "OrderRepository.h"


class OrderArr
{
	OrderRepository orderRepository;
public:
	void add(Order& person);
	void print();
	void RemoveOrder(int idx);

	OrderArr(int maxCapacity = 100);
	~OrderArr();

	/*Order& operator[](int idx);
	void ReadOrderFromFile();
	void WriteOrderToFile();*/

};