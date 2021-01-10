//loops through a string and checks if the string is a word an int or neither
#include "InputFunctions.h"
#include <string>
#include <regex>
#include <iostream>

//checks if string user input matches the regex pattern otherwise it gets input again
std::string InputFunctions::getStringName(std::string inputMessage) {
	//regex pattern to check if input matches a name
	std::regex re("[A-Za-z ,.'-]+");
	std::string name;
	//loops back through while input doesn't match the regex pattern
	do {
		//asks user to enter their name
		std::cout << inputMessage <<"\n> ";
		getline(std::cin, name);
		std::cout << std::endl;

		//if user input doesn't match regex patten then prints Invalid input
		if (!(std::regex_match(name, re))) {
			std::cout << std::endl << "Invalid input" << std::endl;
		}

	} while (!(std::regex_match(name, re))); //loops back through function asking for name if user hasn't entered a valid input
	return name;
}

//checks whether user has input a number greater than 0 and if they haven't then it asks for input again.
int InputFunctions::getIntInput(std::string inputMessage) {
	int userInput;
	do {
		
		std::cout << inputMessage << "\n> ";
		std::cin >> userInput;

		//if input fails or users input is less than or equal to 0 clear input and print error message
		if (std::cin.fail() || userInput <= 0) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid Input" << std::endl;
			std::cout << "Please enter a number greater than 0";
		}

	} while (std::cin.fail() || userInput <= 0); //loops back through when user enters string or number 0 or lower

	return userInput;
}

//checks if input is a double
double InputFunctions::getDoubleInput(std::string inputMessage) {
	double userInput;

	do {
		//prints input message passed into function and then gets the user input
		std::cout << inputMessage << "\n> ";
		std::cin >> userInput;

		//if input fails or users input is less than or equal to 0 clear input and print error message
		if (std::cin.fail() || userInput <= 0) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Invalid Input" << std::endl;
			std::cout << "Please enter a number greater than 0";
		}

	} while (std::cin.fail() || userInput <= 0); //loops back through when user enters string or number 0 or lower

	return userInput;
}