//
//  Task.cpp
//  
//
//  Created by Zachary Rich on 12/7/19.
//
#include "Task.h"
#include <stdio.h>
#include <time.h>
#include <string>
using namespace std;
    /**
     Constructors
     */
    Task::Task()
    {
		this->taskID = 500;
        //taskID = fileParser.getSetting('next_task_id');
		this->dateCreated = clock();
		this->taskTitle = ' ';
		this->taskBody = ' ';
		this->taskImportanceLevel = 0;
		this->taskStatus = 0;
    }
    
    Task::Task(int taskID, time_t dateCreated, string taskTitle, string taskBody, int taskImportanceLevel, int taskStatus)
    {
        //this->taskID = fileParser.getSetting('next_task_id');
        this->dateCreated = dateCreated;
        this->taskTitle = taskTitle;
        this->taskBody = taskBody;
        this->taskImportanceLevel = taskImportanceLevel;
		this->taskStatus = taskStatus;
    }
    
    /**
     Set and Get methods
     */
    
    void Task::setTaskID(int taskID)
    {
        this->taskID = taskID;
    }
    
    int Task::getTaskID()
    {
        return taskID;
    }
    
    void Task::setDateCreated(time_t dateCreated)
    {
        this->dateCreated = dateCreated;
    }
    
    time_t Task::getDateCreated()
    {
        return dateCreated;
    }
    
    void Task::setTaskTitle(string taskTitle)
    {
        this->taskTitle = taskTitle;
    }
    
    string Task::getTaskTitle()
    {
        return taskTitle;
    }
    
    void Task::setTaskBody(string taskBody)
    {
        this->taskBody = taskBody;
    }
    
    string Task::getTaskBody()
    {
        return taskBody;
    }
    
    void Task::setTaskImportanceLevel(int taskImportanceLevel)
    {
        this->taskImportanceLevel = taskImportanceLevel;
    }
    
    int Task::getTaskImportanceLevel()
    {
        return taskImportanceLevel;
    }

    void Task::setTaskStatus(int taskStatus)
    {
		this->taskStatus = taskStatus;
    }

    int Task::getTaskStatus()
    {
        return taskStatus;
    }

