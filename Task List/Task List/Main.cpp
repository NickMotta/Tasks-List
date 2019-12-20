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
FileParser fp = FileParser();

/* 
 
Function returns a status code that can be interpreted where it's called */
int createTask() {
	
	//variables that are needed to create a task
	string taskTitle, taskBody;
	int taskImportanceLevel;

	cout << "==== Create Task ===" << endl;
	cout << "Enter Task Title: " << endl;
	cout << "--> ";
	cin >> taskTitle;
	cout << "Enter Task Body: " << endl;
	cout << "--> ";
	cin >> taskBody;
	cout << "Enter Task Importance Level ( 0-2 )." << endl;
	cout << "--> ";
	cin >> taskImportanceLevel;

	//create the object
	cout << "Creating the task..." << endl;
	Task newTask = Task(taskList.retrieveLargestTaskID() + 1, taskTitle, taskBody, taskImportanceLevel);
	taskList.addTask(newTask);
	fp.writeTask(newTask);


	return 0;	//no fault
}	//end createTask

/*  */
int viewTasks() {

	int choice;

	cout << "==== View Tasks ====" << endl;
	cout << "Enter which task list you would like to see:" << endl;
	cout << "1 - All Tasks\t 2 - Not Started\t3 - Ongoing\t4 Completed" << endl;
	cout << "--> ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		taskList.printTaskSummary();
		break;
	case 2:
		taskList.getNotStartedTasks().printTaskSummary();
		break;
	case 3:
		taskList.getOngoingTasks().printTaskSummary();
		break;
	case 4:
		taskList.getCompletedTasks().printTaskSummary();
		break;
	default:
		cout << "Something went wrong!" << endl;
	}

	return 0;
}

/* Function returns a status code that can be interpreted where it's callled

0 - DEFAULT, no errors
1 - ERROR
*/
int MainMenu() {


	string menuOptions = "1 - create task\t\t2 - view task list\t3 - Exit";
	int choice;

	cout << "Main Menu" << endl;
	cout << menuOptions << endl;
	cout << "--> ";
	cin >> choice;

	int result;
	switch (choice)
	{
	case 1:
		result = createTask();
		if (result == 0) break;
		else cout << "Result code: " << result << endl;
		break;
	case 2:
		result = viewTasks();
		if (result == 0) break;
		else cout << "Result code: " << result << endl;
		break;

	case 0:
		return 0;
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

	bool continueProgram = true;
	//program loop
	while (continueProgram) {
		int res = MainMenu();
		if (res == 0) {
			continueProgram = false;
		}

	}



}