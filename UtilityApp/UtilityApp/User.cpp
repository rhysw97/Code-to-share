#include "User.h"
#include <iostream>
#include <ctype.h>
#include <string>
#include "InputFunctions.h"

//function to get users name
void VendingMachine::User::getName() {
	name = InputFunctions::getStringName("Please enter your name");
}