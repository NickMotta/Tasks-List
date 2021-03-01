/**
 * Task List
 * 
 * A program that displays a to-do list
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include "./header/Task.h"
#include <list>
#define LIST_NAME "tasklist.txt"

using namespace std;

//method declarations
void printSplashScreen();
void viewTaskList();
void addToTaskList();
void deleteTaskList();
void loadTaskFromFile();
void addToTaskList();
void saveList();
void saveListToFile();
void deleteTask(int taskToDelete);

//the task list in memory.
list<Task> taskList;

/**
 * Main Function.
 * Starts program loop and processes main menu.
 * If option outside of given bounds is given by user, retry for an option.
 * 
 * See link below for the reasoning behind the two cin function calls at the end of the while loop.
 * https://en.cppreference.com/w/cpp/io/basic_istream/ignore
 * 
 */
int main(int argc, char* argv[])
{
	#ifdef __linux__
		bool validState = true;
		while (validState) {
			//prepare console
			system("clear");

			//prints splash screen
			printSplashScreen();

			//print options
			printf("====== MENU =====\n");
			printf("1 ... View Task List\n");
			printf("2 ... Add Task to List\n");
			printf("3 ... Delete Task List\n");
			printf("4 ... Exit\n");
			printf("-> ");

			//retrieve user choice
			int usrChoice;
			cin >> usrChoice;

			//process user choice
			switch (usrChoice) {
				case 1:
					viewTaskList();
					break;
				case 2:
					addToTaskList();
					break;
				case 3:
					deleteTaskList();
					break;
				case 4:
					validState = false;
					break;
				default :
					break;
			}
			//frees allocation
			cin.clear();
			cin.ignore(1000, '\n'); //discard input
		}

		return 0;
	#else
		cerr << "Unsupported OS!" << endl;
	#endif
	
}


/**
 * Tries to display the task list onto the terminal
 * First we check to see if the task list has been loaded to memory yet.
 * If the task list hasn't been loaded yet, try to load it from the file.
 * If the file doesn't exist, create a file, and leave the list empty.
 * 
 * Possibly checks to see if the list exists every time this is called regardless of
 * whether or not a change has been made.
 * TODO: Optimization in this area required.
 */
void viewTaskList() {
	//check for existing task list
	cout << "Loading task list..." << endl;

	// if the list is empty, try to load it from memory.
	if (taskList.empty()) {
		cout << "List not initialized, retrieving from file..." << endl;
		loadTaskFromFile();
	}

	//menu loop
	bool validState = true;
	do {
		//print task list menu options
		//display the lists
		//system("clear");
		printSplashScreen();
		cout << " # | Task" << endl;
		for (list<Task>::iterator i = taskList.begin(); i != taskList.end(); i++) {
			cout << "[" << i->getTaskId() << "] " << i->getTaskTitle() << endl;
		}

		int usrChoice;
		cout << endl << "===== Menu =====" << endl
		<< "1 ... Add Task" << endl
		<< "2 ... Delete Task" << endl
		<< "3 ... Return to main menu." << endl
		<< "-> ";

		cin >> usrChoice;
		cin.clear();
		cin.ignore();
		//cin.ignore(1000, '\n'); //discard input
		switch (usrChoice) {
			case 1:
				//adds a task to the task list
				addToTaskList();
				break;
			case 2:
				int taskToDelete;
				cout << "Enter task ID to delete:" << endl << "-> ";
				cin >> taskToDelete;
				cin.clear();
				cin.ignore();
				deleteTask(taskToDelete);
				break;
			case 3:
				//return to menu
				saveListToFile();
				validState = false;
				break;
			default:
				break;
		} 

	} while (validState);


}

//loads the task list from memory
void loadTaskFromFile() {
	//tries to open a stream
	try {
		ifstream ifs (LIST_NAME);
		string line;
		if (ifs.is_open()) {
			cout << "file stream opened" << endl;
			while (getline(ifs, line)) {
				cout << "DEBUG - line: " + line;
				if (line != "") {
					//first four characters are integers
					int taskId = stoi(line.substr(0, 4));
					//create new object
					Task newTask(line.substr(5,line.length()), taskId);
					taskList.push_back(newTask);
				}
			}
		} else {
			cout << "File does not exist. List empty." << endl;
		}

		//close stream
		ifs.close();
	} catch (const std::invalid_argument& e) {
		cerr << "Invalid argument thrown!" << endl;
		cerr << e.what() << endl;

	}

}

/**
 * Adds a task to the task list
 */
void addToTaskList() {
	string newTaskTitle;

	//print display
	cout << "===== ADD =====" << endl
	<< "Enter the new task below..." << endl
	<< "-> ";

	//get user input
	getline(cin, newTaskTitle);

	//process user input
	//add to list
	if (taskList.empty()) {
		Task newTask(newTaskTitle, 1);
		taskList.push_back(newTask);
	} else {
		Task newTask(newTaskTitle, taskList.back().getTaskId() + 1);
		taskList.push_back(newTask);
	}

	system("clear");
}

void deleteTaskList() {
	//get confirmation that user wants to delete task list completely
	bool validCondition = true;

	do {
		char usrChoice;
		
		cout << "\t***Warning!***" << endl
		<< "Are you sure you want to delete your task list?" << endl
		<< "There is no undoing this action.(y/n)" << endl;

		cin >> usrChoice;
		switch (usrChoice) {
			case 'y':
				if (remove(LIST_NAME) != 0) perror("File deletion failed!");
				else cout << "List deleted." << endl;
				break;
			case 'n':
				validCondition = false;
				break;
			default :
				break;
		}
		cin.clear();
		cin.ignore(1000, '\n'); //discard input
	} while (validCondition);

	system("clear");
}

void deleteTask(int taskId) {

	
	//find task in list
	for (list<Task>::iterator i = taskList.begin(); i != taskList.end(); i++) {
		//find the task
		if (i->getTaskId() == taskId) {
			//found task to delete
			//confirm that the user wants to delete the task
			char usrChoice;
			cout << "Are you sure you want to delete this task? (y/n)" << endl
			<< "-> ";
			cin >> usrChoice;
			switch (usrChoice) {
				case 'y':
					//remove task from list
					taskList.erase(i);
					break;
				case 'n':
					cout << "Action canceled." << endl;
					break;
				default :
					cout << "Action canceled." << endl;
					break;
			}
			break;
			cin.clear();
			cin.ignore(1000, '\n'); //discard input
		}

	}
}

//splash screen

/**
 * Prints out a splash screen.
 */ 
void printSplashScreen() {
	cout << endl
		<< "  _______        _      _      _     _   " << endl
		<< " |__   __|      | |    | |    (_)   | |  " << endl
		<< "    | | __ _ ___| | __ | |     _ ___| |_ " << endl
		<< "    | |/ _` / __| |/ / | |    | / __| __|" << endl
		<< "    | | (_| \\__ \\   <  | |____| \\__ \\ |_ " << endl
		<< "    |_|\\__,_|___/_|\\_\\ |______|_|___/\\__|" << endl << endl
		<< "           By Zach Rich & Nick Motta" << endl << endl;

}

void saveListToFile() {
	//dumps contents of list onto file.
	cout << "Saving list to storage...";
	ofstream ofs(LIST_NAME, ofstream::trunc);
	if (ofs.is_open()) {
		for (list<Task>::iterator i = taskList.begin(); i != taskList.end(); i++) {
			ofs << i->toString();
		}
		ofs.close();
		cout << " Done!" ;
	} else {
		cerr << "Task list could not be saved!" << endl;
	}
}

/**
 * Asks the user if they would like to save the list onto a file
 * or to discard the changes.
 */
void saveList() {

	bool validState = true;
	while (validState) {
		char usrChoice;
		cout << "Save list to file? (y/n)" << endl
			<< "-> ";
		cin >> usrChoice;

		switch(usrChoice) {
			case 'y' :
				saveListToFile();
				break;
			case 'n' :
				//move on.
				validState = false;
				break;
		}

	}

}
