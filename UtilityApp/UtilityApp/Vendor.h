#pragma once
#include <string>
#include <map>

//used namespace to prevent name clashes
namespace VendingMachine {

	//created a class for the vending maching
	class Vendor
	{
	public:

		//declared a scruct to store drinks info
		struct DrinkInfo {
			int stock;
			double price;
			std::string category;
		};

		//declared a map to store the drinks name and struct containing the drinks info
		std::map<std::string, Vendor::DrinkInfo> Drinks;

		//declared a scruct to store food info
		struct FoodInfo {
			int stock;
			double price;
			std::string category;
		};

		//declared a map to store the foods info
		std::map<std::string, Vendor::FoodInfo> Food;

		//Method Declarations
		void welcomeMessage();
		char mainMenu();
		void addFood();
		void addDrink();

	};
}

