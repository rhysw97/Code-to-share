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

	stockDb.createStockTables();
	//prints welcome message
	vendingMachine.welcomeMessage();
	
	//first ask for name,
	user.getName();
	bool isValid;
	do{
		isValid = true;
		//prints out main menu and gets user input
		char userInput  = vendingMachine.mainMenu();
		//asks user to select an option
		
		
		switch (userInput) {
			//Items Menu
		case '1':
			//function call for items menu
			break;

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
			//function call for options
			break;

		case '5':
			//function call for exit
			break;

		default:
			std::cout << "Invalid input" << std::endl;
			isValid = false;
		}
			
	}while (!isValid);

	return 0;
}