#include "Order.h"
#include "OrderArr.h"
#include <iostream>
#include <Windows.h>
#include"Menu.h"



using namespace std;




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu menu;
	menu.ShowMenu();
	return 0;
}