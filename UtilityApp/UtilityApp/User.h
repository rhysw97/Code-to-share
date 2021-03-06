#pragma once
#include <string>
#include <vector>
namespace  VendingMachine {
	class User
	{
	public:
		//class members
		std::string name; //stores users name
		double userFunds = 0; //stores users funds
		std::vector<std::string> userBasket; //stores items user wants to purchase

		//method declarations
		void getName();
		void userMenu();
		void viewBasket();
	};
}
