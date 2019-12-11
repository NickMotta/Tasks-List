#include <list>
#include <iterator>
#include <iostream>
#include "TaskList.h"
#include "Task.h"
#include <stdio.h>

using namespace std;


    std::list<Task> taskList;
    std::list<Task>::iterator it = taskList.begin();
    
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


    TaskList getCompletedTasks(std::list<Task> list)
    {
        list.remove_if(CompletedTasks());
    }
    
    TaskList getOngoingTasks(std::list<Task> list)
    {
        list.remove_if(OngoingTasks());
    }
    
    TaskList getNotStartedTasks(std::list<Task> list)
    {
        list.remove_if(NotStartedTasks());
    }
    
    void TaskList::addTask(Task task, TaskList listName)
    {
        list.insert(list.begin(), task);
    }

 
