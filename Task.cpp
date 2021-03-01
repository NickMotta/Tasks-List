//
//  Task.cpp
//  
//
//  Created by Zachary Rich on 12/7/19.
//

#include "./header/Task.h"
#include <string>


Task::Task(string taskTitle, int taskId) {
    this->setTaskTitle(taskTitle);
    this->setTaskId(taskId);
}

void Task::setTaskTitle(string taskTitle) {
    this->taskTitle = taskTitle;
}

void Task::setTaskId(int taskId) {
    this->taskId = taskId;
}

string Task::getTaskTitle() {
    return this->taskTitle;
}

int Task::getTaskId() {
    return this->taskId;
}

string Task::toString() {
    return this->taskId + "" + this->taskTitle + "\n";
}
