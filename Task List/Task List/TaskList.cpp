#include <list>
#include <iterator>
#include <iostream>
#include "TaskList.h"
#include <stdio.h>

using namespace std;


    std::list<Task> taskList;
    std::list<Task>::iterator it = taskList.begin();
    
    struct Pred
    {
       bool operator()(const TaskList& item) const
       {
          return item.GetSomething() == 42 && item.GetSomethingElse() == 314159;
       }
    };


    TaskList getCompletedTasks(std::list<Task> list)
    {
        list.remove_if(Task.get);
    }
    
    TaskList getOngoingTasks()
    {
        
    }
    
    TaskList getNotStartedTasks()
    {
        
    }
    
    void TaskList::addTask(Task task, TaskList listName)
    {
        
    }

 
