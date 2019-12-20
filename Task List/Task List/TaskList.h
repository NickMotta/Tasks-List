#pragma once
#include <list>
#include <iterator>
#include "Task.h"

/*
Function of this class is to create and manage a collection of task objects.
The tasks are stored in a list.
*/
class TaskList
{
private:




public:
	//A list of tasks
	std::list<Task> taskList;
	//An iterator for the list of tasks
	std::list<Task>::iterator it = taskList.begin();
    
	//Default constructor
	TaskList();

	//Iterates through the task lists, and stores all tasks which are completed into one task list, which it returns/
    TaskList getCompletedTasks();

	//Iterates through the task lists, and stores all the tasks which are ongoing into one task list
    TaskList getOngoingTasks();

	//Iterates through the tasks lists, and stores all the tasks not started onto a task list.
    TaskList getNotStartedTasks();

	//Adds a task to the list.
    void addTask(Task task);

	//Reads the task list and finds the lighest taskID
	int retrieveLargestTaskID();

	//returns the length of the task list
	int getTaskListLength();

	//print tasks summary
	void printTaskSummary();

	std::list<Task>::iterator retrieveIterator();

    
	//TODO: Create a function that retrieves a task given an ID

};
