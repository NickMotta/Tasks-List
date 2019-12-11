#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::experimental::filesystem;

#include "FileParser.h"



FileParser::FileParser()
{
	//sets the data directory
	this->DATA_DIRECTORY = fs::current_path() / "data";

}


FileParser::~FileParser()
{
}

string * FileParser::getListOfFileNames()
{
	//create an array

	
	int directoryCounter;
	for (auto &p : fs::directory_iterator(this->DATA_DIRECTORY)) {
		directoryCounter+= 1;
	}

	string* listOfFileNames = (string*)malloc( sizeof(string)) * directoryCounter);

	for (auto &p : fs::directory_iterator(this->DATA_DIRECTORY)) {
		//listOfFileNames.append(p.path());
	}

	return nullptr;
}
