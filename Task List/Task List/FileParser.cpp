#include <string>
#include <iostream>
#include <filesystem>
#include <list>
#include <fstream>
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
	//create a list to store the file names.
	list<string> filesInDirectory;

	/* Go through each file name in the given directory. Trim the path name out of the file name, store file name in list */
	for (const auto &entry : fs::directory_iterator(directory)) {
		//gets the current path to the item
		string path = entry.path().string();
		//trims the unecessary characters from it.
		filesInDirectory.push_back(path.substr(path.rfind('\\') + 1));
	}
	
	return filesInDirectory;

}



TaskList FileParser::readTasksFromStorage()
{
	list<string> listOfFileNames = getListOfFileNames(DATA_DIRECTORY);

	//Go through the list
	for (auto const& fileName : listOfFileNames) {

		//open the file
		ifstream infile;
		infile.open(fileName);

		//variables for the object types
		int taskID, taskImportanceLevel, taskStatus;
		time_t dateCreated;
		string taskTitle, taskBody;

		infile >> taskID;
		infile >> dateCreated;
		infile >> taskTitle;
		infile >> taskBody;
		infile >> taskImportanceLevel;
		infile >> taskStatus;
		//theoretically, we're at the end of the file....

		//create the task object
		Task newTask = Task(taskID, dateCreated, taskTitle, taskBody, taskImportanceLevel, taskStatus)
			


	}

	return TaskList();
}// end readTasksFromStorage

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

bool FileParser::saveFile(Task taskToSave)
{



	return false;
}

int FileParser::saveTasks(TaskList listToSave)
{
	//stream object to write
	ofstream file;

	//open the file
	file.open("data.txt");

	//Write to the file type casted to chars
	file.write((char*)&listToSave, sizeof(listToSave));

	//closes the output stream
	file.close();


	return 0;
}

TaskList FileParser::getTaskList()
{
	//Object to read from file
	ifstream file;

	//open file
	file.open("data.txt");

	//Object we're trying to get
	TaskList tasks;
	
	//Read from the file
	file.read((char*)&tasks, sizeof(tasks));

	file.close();

	return tasks;
}
