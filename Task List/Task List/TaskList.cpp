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
		return TaskList();
        //list.remove_if(CompletedTasks());
    }
    
    TaskList TaskList::getOngoingTasks()
    {
		return TaskList();
        //list.remove_if(OngoingTasks());
    }
    
    TaskList TaskList::getNotStartedTasks()
    {
        //list.remove_if(NotStartedTasks());

		return TaskList();

    }
    
    void TaskList::addTask(Task task)
    {

		this->taskList.push_back(task);
    }

	int TaskList::retrieveLargestTaskID()
	{
		int largestTaskID = 0;
		//iterate through the taskList
		for ( auto &currTask : this->taskList ) {
			//look for the largest task
			if (currTask.getTaskID() > largestTaskID) {
				largestTaskID = currTask.getTaskID();
			}

		}

		return largestTaskID;
	}

	int TaskList::getTaskListLength()
	{
		return taskList.size();
	}

	void TaskList::printTaskSummary()
	{
		cout << "Task List Summary" << endl;
		cout << "Task ID\t" << "Task Title\t" << "Task Importance" << endl;
		for (auto &task : taskList) {
			cout << task.getTaskID() << "\t" << task.getTaskTitle() << "\t";
			switch (task.getTaskImportanceLevel()) {
			case 0:
				cout << "LOW" << endl;
				break;
			case 1:
				cout << "MED" << endl;
				break;
			case 2:
				cout << "HIGH" << endl;
				break;
			default :
				cout << "OOPS!" << endl;
				break;
			}
		}

	}

	std::list<Task>::iterator TaskList::retrieveIterator()
	{
		return this->it;
	}

 
