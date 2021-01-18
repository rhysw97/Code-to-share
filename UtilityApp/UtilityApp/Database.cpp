#include "Database.h"
#include "sqlite/sqlite3.h"
#include <iostream>
#include <map>
#include <string>
#include "Vendor.h"

//Static Map Declarations
std::map<std::string, VendingMachine::Vendor::ItemInfo> VendingMachine::Vendor::drinks;
std::map<std::string, VendingMachine::Vendor::ItemInfo> VendingMachine::Vendor::food;

void VendingMachine::Database::createStockTables() {

	//list of chars for error 
	char* err;
	//sqlite3 object 
	sqlite3* db;

	//opens the file Stock.db or creates if it doesn't exist
	sqlite3_open("Stock.db", &db);
	//creates a table for drinks within the database
	int drinks = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS drinks('name TEXT NOT NULL', 'stock INT NOT NULL', 'price REAL NOT NULL', 'category TEXT NOT NULL'); ", NULL, 0, &err);
	
	//checks for error when creating drinks table
	if (drinks != SQLITE_OK) {
		std::cout << "error: " << err;
	}

	else {
		std::cout << "Table created successfully\n";
	}

	//creates a table for food within the database
	int food = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS food('name TEXT NOT NULL', 'stock INT NOT NULL', 'price REAL NOT NULL', 'category TEXT NOT NULL'); ", NULL, 0, &err);

	//checks for error when creating food table
	if (food != SQLITE_OK) {
		std::cout << "error: " << err;
	}

	else {
		std::cout << "Table created successfully\n";
	}

	
}

//function to add a the information within the map declared in Vendor.h into to the table whos name is passed info the function
void VendingMachine::Database::addMapToTable(std::map < std::string, VendingMachine::Vendor::ItemInfo>& myMap, std::string tableName) {
	
	//declared to store error message
	char* errorMessage;
	int returnMessage;

	sqlite3* db;
	sqlite3_open("Stock.db", &db);

	//loops through keys in the map
	for (auto const& myPair : myMap) {
		//saves key to itemname
		std::string itemName = myPair.first;

		//Declared and initatlised variables to store the information within the maps structs (The maps values)
		std::string itemStock = std::to_string(myPair.second.stock);
		std::string itemPrice = std::to_string(myPair.second.price);
		std::string itemCategory = myPair.second.category;

		//query created to add map information into stock database
		std::string query = "INSERT INTO "
			+ tableName
			+ " VALUES("
			+ "'" + itemName + "'"
			+ ", '" + itemStock + "'"
			+ ", '" + itemPrice + "'"
			+ ", '" + itemCategory + "');";

		//adds the information into the database
		returnMessage = sqlite3_exec(db, query.c_str(), NULL, 0, &errorMessage);
	}
}

//call back function required to retrive data from SQLite
int VendingMachine::Database::drinksCallback(void* data, int argc, char** argv, char** azColName) {
	VendingMachine::Vendor::ItemInfo itemInfo; 
	std::string name = argv[0];
	itemInfo.stock = std::stoi(argv[1]);
	itemInfo.price = std::stod(argv[2]);
	itemInfo.category = argv[3];
	
	VendingMachine::Vendor::drinks.insert({ name, itemInfo });
	 
	return 0;
	
}


int VendingMachine::Database::foodCallback(void* data, int argc, char** argv, char** azColName) {
	
	
	VendingMachine::Vendor::ItemInfo items;
	std::string name = argv[0];
	items.stock = std::stoi(argv[1]);
	items.price = std::stod(argv[2]);
	items.category = argv[3];
	

	VendingMachine::Vendor::food.insert({ name, items });

	return 0;

}

void VendingMachine::Database::saveTableToMap(std::string tableName ) {
	

	
	
	int returnMessage;
	 
	
	//declared to store error message
	char* errorMessage;

	//SQLite Object
	sqlite3* db;

	//opens stock database
	sqlite3_open("Stock.db", &db);

	//delcared stuct to hold items information such as stock, price and category
	

	//retrieves everything from the table which is passed into the function
	std::string query = "SELECT * FROM " + tableName + ";";
	if (tableName == "drinks") {
		 returnMessage = sqlite3_exec(db, query.c_str(), drinksCallback, NULL, &errorMessage);
	}

	if (tableName == "food") {
		returnMessage = sqlite3_exec(db, query.c_str(), foodCallback, NULL, &errorMessage);
	}
	//int stuff = sqlite3_prepare(db, query.c_str(), query.length(), NULL, &errorMessage);

}