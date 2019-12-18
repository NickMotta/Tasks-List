#include <list>
#include <iterator>
#include <iostream>
#include "TaskList.h"
#include "Task.h"
#include <stdio.h>

using namespace std;

    
    struct CompletedTasks
    {
       bool operator()(Task& item)
       {
           return item.getTaskStatus() == 2;
       }
    };

    struct OngoingTasks
    {
       bool operator()(Task& item)
       {
           return item.getTaskStatus() == 1;
       }
    };

    struct NotStartedTasks
    {
       bool operator()(Task& item)
       {
           return item.getTaskStatus() == 3;
       }
    };


	TaskList::TaskList()
	{
	}

	TaskList TaskList::getCompletedTasks()
    {
        //list.remove_if(CompletedTasks());
    }
    
    TaskList TaskList::getOngoingTasks()
    {
        //list.remove_if(OngoingTasks());
    }
    
    TaskList TaskList::getNotStartedTasks()
    {
        //list.remove_if(NotStartedTasks());
    }
    
    void TaskList::addTask(Task task)
    {

		this->taskList.push_back(task);
    }

	int TaskList::retrieveLargestTaskID()
	{
		int largestTaskID = 0;
		//iterate through the taskList
		for ( auto const& currTask : this->taskList ) {
			//look for the largest task
			if (currTask.getTaskID > largestTaskID) {
				largestTaskID = currTask.getTaskID;
			}

		}

		return largestTaskID;
	}

 
