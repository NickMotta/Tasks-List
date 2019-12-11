#include <list>
#include <iterator>
#include "Task.h"

class TaskList
{
public:
    std::list<Task> taskList;
    std::list<Task>::iterator it = taskList.begin();
    
    TaskList getCompletedTasks();
    TaskList getOngoingTasks();
    TaskList getNotStartedTasks();
    void addTask(Task task, TaskList listName);
    
};
