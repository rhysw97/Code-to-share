#pragma once
#include <string>
#include <map>
namespace VendingMachine {
	class Database
	{
	public:
		void createStockTables();
		void addMapToTable(std::map<std::string, struct MyStruct> & myMap, std::string tableName);
	};
}
