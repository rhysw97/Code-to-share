#pragma once
#include <string>
#include <map>

//used namespace to prevent name clashes
namespace VendingMachine {
	
	//created a class for the vending maching
	class Vendor
	{
	public:

		//declared a scruct to store item info
		struct ItemInfo {
			int stock = 0;
			double price = 0;
			std::string category;
		};

		//declared a static  bmap to store the drinks name and struct containing the drinks info
		static std::map<std::string, ItemInfo> drinks;

		
		//declared a static map to store the foods info
		static std::map<std::string,  ItemInfo> food;

		//Method Declarations
		void welcomeMessage();
		char mainMenu();
		void addFood();
		void addDrink();

	};
	extern Vendor myVendor;
}