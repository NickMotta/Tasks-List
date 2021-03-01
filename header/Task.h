/**
 * Class name: Task.h
 * Purpose: Object that represents a task.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */


#ifndef TASK_H
#define TASK_H

#include <string>
#include <ctime>
#include <fstream>


using namespace std;

class Task
{

    private:

		//The title of the task
		string taskTitle;
		//Whether the task has been completed or not.
		int taskId;
		//changes the status variable
		Task();
    public:


		//default constructor for a task.
		Task(string taskTitle, int taskId);

		//Sets the task title
		void setTaskTitle(string taskTitle);

		void setTaskId(int taskId);
		
		//Returns the task title
		string getTaskTitle();

		//Returns the task Id
		int getTaskId();

		//generates a string representation of the task
		string toString();

};
#endif
