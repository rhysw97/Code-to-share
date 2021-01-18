#include <iostream>
#include "User.h"
#include "Vendor.h"
#include "Database.h"


int main() {
	//create user object
	VendingMachine::User user;

	//created vendor object
	VendingMachine::Vendor vendingMachine;
	VendingMachine::Database stockDb;
	//#########
	//DEBUGGING

	//creates stock tables if they haven't been created
	stockDb.createStockTables();
	


	//prints welcome message
	stockDb.saveTableToMap("drinks");
	stockDb.saveTableToMap("food");
	//#########
	vendingMachine.printMap(vendingMachine.drinks);
	vendingMachine.printMap(vendingMachine.food);
	vendingMachine.welcomeMessage();
	
	vendingMachine.printItemCategory();
	//first ask for name,
	user.getName();
	bool isValid = true;
	do{
		isValid = true;
		//prints out main menu and gets user input
		char userInput  = vendingMachine.mainMenu();
		//asks user to select an option
		
		
		switch (userInput) {
			//Items Menu
		case '1':
			//function call for items menu
			

			//Basket
		case '2':
			//function call for basket
			break;

			//Funds
		case '3':
			//function call for funds
			break;

			//Options
		case '4':
			vendingMachine.addDrink();
			vendingMachine.addFood();
			//function call for options
			break;

		case '5':
			//function call for exit
			break;

		default:
			std::cout << "Invalid input" << std::endl;
			isValid = false;
		}
			
	}while (!isValid); //loops back through if user doesnt enter a valid input 

	return 0;
}