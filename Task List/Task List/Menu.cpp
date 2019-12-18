#include <string>
#include <stdlib.h>
#include <iostream>
#include "Menu.h"
#include "TaskList.h"
#include "Task.h"

using namespace std;

Menu::Menu() {

}

int Menu::MainMenu() {


	string menuOptions = "1 - create task\t2 - view task list";
	int choice;

	cout << "Main Menu" << endl;
	cout << menuOptions << endl;
	cout << "--> ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		this->CreateTask();
		break;
	case 2:
		//this->ViewTaskList();
		break;
	}

	return 0;
}


int Menu::CreateTask()
{
	/*
		Creating tasks implement the following steps:

		1) create a new task object
		2) use FileParser to store the task in the data directory
		3) add the task object to the TaskList.

	*/

	//input variables
	string taskTitle, taskBody, taskImportanceLevel;

	cout << "==== Create Task ===" << endl;
	cout << "Enter Task Title: " << endl;
	cout << "--> ";
	cin >> taskTitle;
	cout << "Enter Task Body: " << endl;
	cout << "-->";
	cin >> taskBody;

	//get the next task id from the file system


	return 0;
}
