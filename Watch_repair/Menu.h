#pragma once
#include"OrderArr.h"

class Menu
{
public:
	void ShowMenu();
private:
	OrderArr orders;
	void showMainMenu();
	void showAndHadnleAddOrderMenu();
	void showAndHadnleRemoveOrderMenu();
	void handleUserInput(char userInput);
	void safeHandleUserInput(char userInput);
	//void WriteOrderToFile(Order order);
	//void ReadOrderFromFile();
};