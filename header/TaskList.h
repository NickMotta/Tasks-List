/**
 * Tasklist.h
 * Written by: Nicholas Motta
 *
 *
 *
 */

#ifndef TASKLIST_H
#define TASKLIST_H

#include <list>
#include <iterator>
#include "Task.h"

/*
Function of this class is to create and manage a collection of task objects.
The tasks are stored in a list.
*/


#define TASK_COMPLETE 0
#define TASK_FAILED 1
#define LIST_FILE_NAME "list.txt"

class TaskList
{

private:

	//opens file, reads contents, stores it into the list.
	int initiateListFromFile(string filename);

	//saves the list contents by overriding the existing file.
	int saveListToFile();

public:
	//A list of tasks
	std::list<Task> taskList;
	//An iterator for the list of tasks
	std::list<Task>::iterator it = taskList.begin();
    
	//Default constructor reads default list file name
	TaskList();

	//Constructor takes the task list file name as an argument.
	TaskList(string filename);

	//


	//Iterates through the task lists, and stores all tasks which are completed into one task list, which it returns/
   	 TaskList getCompletedTasks();


	//Iterates through the tasks lists, and stores all the tasks not started onto a task list.
   	 TaskList getIncompletedTasks();

	//Adds a task to the list.
   	 void addTask(Task task);

	//Reads the task list and finds the lighest taskID
	int retrieveLargestTaskID();

	//returns the length of the task list
	int getTaskListLength();

	//print task list
	void printTaskList();

	std::list<Task>::iterator retrieveIterator();

    
	//TODO: Create a function that retrieves a task given an ID

};

#endif
