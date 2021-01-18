#include "Vendor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "InputFunctions.h"


//prints welcome message
void VendingMachine::Vendor::welcomeMessage() {
	std::cout << "Hello and welcome to Snackatron " << std::endl;
	std::cout << "Here for all your vending needs" << std::endl << std::endl;
}

//prints out the message for the menu and then gets user Input for their choice and returns it
char VendingMachine::Vendor::mainMenu(){
	std::cout << "Pick one of the following options:" << std::endl;
	std::cout << " 1. Items Menu" << std::endl;
	std::cout << " 2. Basket" << std::endl;
	std::cout << " 3. Funds" << std::endl;
	std::cout << " 4. Options" << std::endl;
	std::cout << " 5. Exit" << std::endl;
	
	char userInput;
	std::cin >> userInput;

	return userInput;		
}

void VendingMachine::Vendor::optionsMenu() {

}

//function to allow user to enter food items to the food map
void VendingMachine::Vendor::addFood() {
	ItemInfo foodInfo;

	//asks user to input the name, stock amount, price and category of the food item that they are adding
	std::string foodName = InputFunctions::getStringName("What is the name of the food item you would like to add?");
	foodInfo.stock = InputFunctions::getIntInput("Please enter the number of " + foodName + "s you would like to the vending machine?");
	foodInfo.price = InputFunctions::getDoubleInput("Please enter the price of a " + foodName);
	foodInfo.category = InputFunctions::getStringName("What is the category of " + foodName + "?");

	//saves the information for the food item that the user has added into the food map 
	food.insert({ foodName, foodInfo });
}

//function to allow user to add drink items to the drink map
void VendingMachine::Vendor::addDrink() {
	ItemInfo drinkInfo;
	//asks user to input the name, stock amount, price and category of the food item that they are adding
	std::string drinkName = InputFunctions::getStringName("What is the name of the drink you would like to add?");
	drinkInfo.stock = InputFunctions::getIntInput("Please enter the number of " + drinkName + "s you are inputting");
	drinkInfo.price = InputFunctions::getDoubleInput("Please enter the price of a " + drinkName);
	drinkInfo.category = InputFunctions::getStringName("What is the category of " + drinkName + "?");
	
	//saves the information for the food item that the user has added into the food map 
	drinks.insert({ drinkName, drinkInfo });
}

//prints out everything in the map passed in
void VendingMachine::Vendor::printMap(std::map < std::string, VendingMachine::Vendor::ItemInfo>& myMap) {
	for (auto& myPair : myMap) {

		std::cout << myPair.first << "\n";

		//prints each value in struct
		std::cout << myPair.second.stock << "\n";
		std::cout << myPair.second.price << "\n";
		std::cout << myPair.second.category << "\n";
	}
}

void VendingMachine::Vendor::itemMenu() {
	//In this I want to ask for opition t go back to main menu, or select food or drinks 
}

void VendingMachine::Vendor::selectCategory() {

	

}

void VendingMachine::Vendor::updateCategories() {

	for (auto& myPair : drinks) {
		if (!(std::find(drinkCategories.begin(), drinkCategories.end(), myPair.second.category) != drinkCategories.end())) {
			drinkCategories.push_back(myPair.second.category);
		}
	}
	
	for (auto& myPair : food) {
		if (!(std::find(foodCategories.begin(), foodCategories.end(), myPair.second.category) != foodCategories.end())) {
			foodCategories.push_back(myPair.second.category);
		}
	}
}

void VendingMachine::Vendor::printItemCategory() {
	
	
	for (int i = 0; i < drinkCategories.size(); i++) {
		std::cout << drinkCategories[i] << "\n";
	}
}