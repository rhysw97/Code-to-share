#include "Database.h"
#include "sqlite/sqlite3.h"
#include <iostream>
#include <map>
#include <string>

void VendingMachine::Database::createStockTables() {

	//list of chars for error 
	char* err;
	//sqlite3 object 
	sqlite3* db;

	//opens the file Stock.db or creates if it doesn't exist
	sqlite3_open("Stock.db", &db);
	//creates a table for drinks within the database
	int drinks = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS drinks (name TEXT stock INT, price REAL, category TEXT); ", NULL, NULL, &err);
	
	//checks for error when creating drinks table
	if (drinks != SQLITE_OK) {
		std::cout << "error: " << err;
	}

	//creates a table for food within the database
	int food = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS food (name TEXT, stock INT, price REAL, category TEXT); ", NULL, NULL, &err);

	//checks for error when creating food table
	if (food != SQLITE_OK) {
		std::cout << "error: " << err;
	}

	//closes the stock database
	sqlite3_close(db);
}

//function to add map passed into to the table passed in 
void VendingMachine::Database::addMapToTable(std::map<std::string, struct VendingMachine::MyStruct> & myMap, std::string tableName) {
	
	//
	char* errorMessage;
	int32_t returnMessage;
	sqlite3* db;
	
	//opens stock data base
	sqlite3_open("Stock.db", &db);

	for (auto &myPair : myMap) {
		std::string itemName = myPair.first;
		std::string itemStock = std::to_string(myPair.second.stock);
		std::string itemPrice = std::to_string(myPair.second.price);
		std::string itemCategory = myPair.second.category;
		std::string query = "INSERT INTO "
							+ tableName 
							+  "(name, stock, price, category) VALUES (" 
							+ "'" + itemName + "'"
							+ ", '" + itemStock + "'"
							+", ''" + itemPrice + "'"
							+", '" + itemCategory + "');" ;
		
		returnMessage = sqlite3_exec(db, query.c_str(), NULL, NULL, &errorMessage);
	}
	sqlite3_close(db);
}






