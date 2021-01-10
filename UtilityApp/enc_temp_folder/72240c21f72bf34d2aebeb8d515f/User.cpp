#include "User.h"
#include <iostream>
#include <ctype.h>
#include <regex>
#include <string>
#include "StringFunctions.h"

//function to get users name
void User::getName() {
	name = getStringName("Please enter your name");
}

