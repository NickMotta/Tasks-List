#pragma once
#include <string>
#include "Task.h"
using namespace std;

class Menu
{



public:

	/*
	Prints out the main menu for the application
	*/
	int MainMenu();

	/*
	Prints out the menu for creating a new task
	*/
	int CreateTask();

	/*Changes the importance level of the task*/
	static int ChangeTaskImportanceLevel(Task task);

	/* Prints out the tasks with an option to select a task for editing */
	int ViewTaskList();

};

