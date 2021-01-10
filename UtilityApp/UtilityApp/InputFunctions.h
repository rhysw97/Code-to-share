#include <string>
#ifndef INPUT_FUNCTIONS_H
#define INPUT_FUNCTIONS_H

//created namespace InputFunctions to prevent name clashes
namespace InputFunctions{
	//function declarations
	std::string getStringName(std::string inputMessage);
	int getIntInput(std::string inputMessage);
	double getDoubleInput(std::string text);
}
#endif // !INPUT_FUNCTIONS_H
