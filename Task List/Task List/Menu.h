#pragma once
#include <string>
#include "Task.h"
using namespace std;

class Menu
{

	/* All static functions return an integer that determines whether or not the process was successful
	0 - No problem
	1 - There was an issue
	*/
public:

	/*
	Prints out the main menu for the application
	*/
	static int MainMenu();

	/*
	Prints out the menu for creating a new task
	*/
	static int CreateTask();

	/*Changes the importance level of the task*/
	static int ChangeTaskImportanceLevel(Task task);

	/* Prints out the tasks with an option to select a task for editing */
	static int ViewTaskList();

};

