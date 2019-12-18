#pragma once
#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include "Task.h"
#include "TaskList.h"
namespace fs = std::experimental::filesystem;

using namespace std;

class FileParser
{
private:
	/* This is a path object that is part of the filesystem library. */
	string DATA_DIRECTORY;

public:
	//Constructor for the file parser. It is the default constructur
	FileParser();
	//destructor for the fileParser.
	~FileParser();

	/* Get a list of files at the given directory */
	list<string> getListOfFileNames(string directory);


	/* Builds a list of tasks by retrieving the list of file names,
	reading them one by one, and creating objects from the files.
	steps:
	1. get a list of files in the directory
	2. iterate through the list
	3. open the file, extract the contents, and build a new task object with it.
	*/
	TaskList readTasksFromStorage();


	int getNextTaskId();

	//Retrieves the task object stored in memory.
	Task retrieveFile(string filename);

	//Saves the task to the data directory. Replaces a task saved with the current name.
	bool saveFile(Task taskToSave);


	//=========================================================

	int saveTasks(TaskList listToSave);

	TaskList getTaskList();
};

