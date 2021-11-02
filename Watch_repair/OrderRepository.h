#pragma once
#include"Repository.h"
#include"Order.h"
#include<string>
using namespace std;

class OrderRepository : public Repository<Order>
{
protected:
	string GetFileName() { return "Order.txt"; }
	string GetTitle() { return "Замовлення: "; }
public:
	OrderRepository(int max) : Repository(max) {}

	~OrderRepository()
	{
		WriteToFile();
	}
};
