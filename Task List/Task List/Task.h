#pragma once
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

class Task
{

    private:
		//The task's ID
        int taskID;

		//an integral value representing the number of seconds elapsed since 00:00 hours, Jan 1, 1970 UTC (i.e., a unix timestamp).
        time_t dateCreated;

		//The title of the task
        string taskTitle;

		//The body of the task, this is where the details of the task are stored.
        string taskBody;

		/**
		An integer representing the importance of the task.
		Lower integers mean lower priority, meaning the higher the importance, the higher the integer.
		 0 = LOW IMPORTANCE
		 1 = MED IMPORTANCE
		 2 = HIGH IMPORTANCE
		*/
		int taskImportanceLevel;

         /**
		 An integer representing the current status of the task
          taskStatus = 0 NOT STARTED
          taskStatus = 1 IN PROGRESS
          taskStatus = 2 COMPLETED
          */
        int taskStatus;

    public:
		//default constructor for a task.
		Task();

		//Constructor for task object that takes arguments for each element of the task. Assigns a status default of 0
        Task(int taskID, time_t dateCreated, string taskTitle, string taskBody, int taskImportanceLevel, int taskStatus);

		//Sets the task ID of the task
        void setTaskID(int taskID);

		//Returns the task's ID
        int getTaskID();

		//Sets the date the task was created.
        void setDateCreated(time_t dateCreated);

		//Returns the date the task was created
        time_t getDateCreated();

		//Sets the task title
        void setTaskTitle(string taskTitle);

		//Returns the task title
        string getTaskTitle();

		//Sets the task body
        void setTaskBody(string taskBody);

		//Returns the task body.
        string getTaskBody();

		//Sets the task importance level. Checks to see that the importance level is within "range"
        void setTaskImportanceLevel(int taskImportanceLevel);

		//Returns the task importance level
        int getTaskImportanceLevel();

		//Sets the task status
        void setTaskStatus(int taskStatus);

		//returns the task status.
        int getTaskStatus();

		/*This function overrides the << operator to write into the stream object*/
		friend std::ostream & operator << (std::ostream &out, const Task &task);




};
