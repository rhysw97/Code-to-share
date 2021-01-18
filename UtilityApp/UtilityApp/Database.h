#pragma once
#include <string>
#include <map>
#include "Vendor.h"

namespace VendingMachine {
	class Database
	{
	
	
	public:
		

		void createStockTables();
		void addMapToTable(std::map < std::string, VendingMachine::Vendor::ItemInfo>& myMap, std::string tableName);
		void saveTableToMap(std::string);
		static int drinksCallback(void *data, int argc, char** argv, char** azColName);
		static int foodCallback(void* data, int argc, char** argv, char** azColName);
	};
}