#include <string>
#include <iostream>
#include <filesystem>
#include <list>
namespace fs = std::experimental::filesystem;

#include "FileParser.h"



FileParser::FileParser()
{
	//sets the data directory

	fs::path directory = fs::current_path() / "data";
	string test = (fs::current_path() / "data" ).string();


}


FileParser::~FileParser()
{
}

list<string>FileParser::getListOfFileNames(string directory)
{
	//create an array
	list<string> filesInDirectory;
	
	int directoryCounter;
	for (auto &p : fs::directory_iterator(directory)) {
		cout << p << endl;
	}

	return filesInDirectory;

}

int FileParser::getNextTaskId()
{
	/*
	1) grab the list of file names from the data directory
	2) go through the directory list
		2a) If the string contains 'task' then grab the int at the end of the '_'
	*/

	list<string> fileList = getListOfFileNames(this->DATA_DIRECTORY);
	list<string>::iterator iterator;
	for (iterator = fileList.begin(); iterator != fileList.end(); ++iterator) {
		cout << *iterator << endl;
	}

	return 0;
}
