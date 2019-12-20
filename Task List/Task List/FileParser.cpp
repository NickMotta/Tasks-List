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
	TaskList listToReturn = TaskList();
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
		Task newTask = Task(taskID, dateCreated, taskTitle, taskBody, taskImportanceLevel, taskStatus);

		//push the new task into the task list.
		listToReturn.addTask(newTask);

	}	//end for loop

	return listToReturn;
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


int FileParser::writeTasksToStorage(TaskList taskList)
{
	list<string> listOfFileNames = getListOfFileNames(DATA_DIRECTORY);


	for (std::list<Task>::iterator iterator = taskList.taskList.begin(); iterator != taskList.taskList.end(); iterator++) {
		//create a file with the read option in truncate form
		Task myTask = *iterator;
		ofstream offile;
		offile.open(myTask.getTaskID() + ".txt");

		if (offile.is_open()) {

			//push info into file
			offile << myTask.getTaskID();
			offile << myTask.getDateCreated();
			offile << myTask.getTaskTitle();
			offile << myTask.getTaskBody();
			offile << myTask.getTaskImportanceLevel();
			offile << myTask.getTaskStatus();

			//close the file
			offile.close();
		}
		else {
			return 1;
		}
	}

	return 0;

}


int FileParser::writeTask(Task task)
{
    //open the file
    ofstream offile;
    offile.open(task.getTaskID() + ".txt");
        
	if (offile.is_open()) {
		offile << task.getTaskID();
		offile << task.getDateCreated();
		offile << task.getTaskTitle();
		offile << task.getTaskBody();
		offile << task.getTaskImportanceLevel();
		offile << task.getTaskStatus();

		offile.close();
	}

    return 0;
}
