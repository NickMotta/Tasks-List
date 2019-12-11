#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <list>
namespace fs = std::experimental::filesystem;

using namespace std;

class FileParser
{
private:
	/* This is a path object that is part of the filesystem library. */
	string DATA_DIRECTORY;

public:
	FileParser();
	~FileParser();

	/* Get a list of files at the given directory */
	list<string> getListOfFileNames(string directory);

	int getNextTaskId();


};

