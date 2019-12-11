#pragma once
#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::experimental::filesystem;

using namespace std;

class FileParser
{
private:
	static string DATA_DIRECTORY;

public:
	FileParser();
	~FileParser();

	/* Get a list of files at the base directory */
	string* getBaseDirFiles();


};

