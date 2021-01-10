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

//prints out the message for the menu 
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

//function to allow user to enter food items to the food map
void VendingMachine::Vendor::addFood() {

	std::string foodName = InputFunctions::getStringName("What is the name of the food item you would like to add");
	int foodStock = InputFunctions::getIntInput("Please enter the number of " + foodName + "s you would like to the vending machine");
	double foodPrice = InputFunctions::getDoubleInput("Please enter the price of a " + foodName);
	std::string foodCategory = InputFunctions::getStringName("What is the category of the drink you would like to add");

	Food.insert({foodName, (FoodInfo{ foodStock, foodPrice, foodCategory })});
}

//function to allow user to add drink items to the drink map
void VendingMachine::Vendor::addDrink() {

	std::string drinkName = InputFunctions::getStringName("What is the name of the drink you would like to add");
	int drinkStock = InputFunctions::getIntInput("Please enter the number of " + drinkName + "s you would like to the vending machine");
	double drinkPrice = InputFunctions::getDoubleInput("Please enter the price of a " + drinkName);
	std::string drinkCategory = InputFunctions::getStringName("What is the category of the drink you would like to add");
	
	Drinks.insert({ drinkName, (DrinkInfo{ drinkStock, drinkPrice, drinkCategory })});
}