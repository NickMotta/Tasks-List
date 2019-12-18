#include <string>
#include <iostream>
#include <filesystem>
#include <typeinfo>
#include "Task.h"
#include "TaskList.h"
#include "FileParser.h"
namespace fs = std::experimental::filesystem;
using namespace std;

TaskList taskList;

/* 
 
Function returns a status code that can be interpreted where it's called */
int createTask(int taskID) {
	
	//variables that are needed to create a task
	string taskTitle, taskBody;
	int taskImportanceLevel;

	cout << "==== Create Task ===" << endl;
	cout << "Enter Task Title: " << endl;
	cout << "--> ";
	cin >> taskTitle;
	cout << "Enter Task Body: " << endl;
	cout << "-->";
	cin >> taskBody;
	cout << "Enter Task Importance Level. Leave empty for default (low)." << endl;
	cout << "-->";
	cin >> taskImportanceLevel;

	//create the object
	cout << "Creating the task..." << endl;
	Task newTask = Task();
	


	return 0;	//no fault
}	//end createTask


/* Function returns a status code that can be interpreted where it's callled

0 - DEFAULT, no errors
1 - ERROR
*/
int MainMenu() {


	string menuOptions = "1 - create task\t2 - view task list";
	int choice;

	cout << "Main Menu" << endl;
	cout << menuOptions << endl;
	cout << "--> ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		CreateTask();
		break;
	case 2:
		//this->ViewTaskList();
		break;
	}

	return 0;
}





/*
Function creates a directory 'data' if there is none, and loads all tasks present into a taskList object.
*/
void startupProcedure() {




}


int main()
{

	Task test = Task();
	test.setTaskTitle("YEET1");
	Task test1 = Task();
	Task test2 = Task();
	TaskList taskList = TaskList();
	taskList.addTask(test);
	taskList.addTask(test1);
	taskList.addTask(test2);
	FileParser fileParser = FileParser();

	fileParser.saveTasks(taskList);

	TaskList readList = fileParser.getTaskList();

	system("pause");



	string DIRECTORY_PATH = fs::current_path().string();
	DIRECTORY_PATH += "\\data\\";

	for (const auto &entry : fs::directory_iterator(fs::current_path().string() + "\\data\\")) {
		string path = entry.path().string();
		cout << path.substr(path.rfind('\\') + 1) << endl;
	}

	//string test = system("dir");

	system("pause");


	//program loop
	while (true) {
		//menu.MainMenu();


	}



	//fs::path path = fs::current_path();
	//path /= "data";
	//std::cout << fs::current_path() << std::endl;

	//for (auto & p : fs::directory_iterator(path))
	//	std::cout << p << std::endl;

	//int directoryCounter;
	//for (auto &p : fs::directory_iterator(path)) {
	//	directoryCounter += 1;
	//}

	//std::cout << directoryCounter << std::endl;
	//system("pause");
}