#include <string>
#include <ctime>
using namespace std;

class Task {

    private:
        int taskID;
        time_t dateCreated;
        string taskTitle;
        string taskBody;
		int taskImportanceLevel;
         /**
          taskStatus = 0 NOT STARTED
          taskStatus = 1 IN PROGRESS
          taskStatus = 2 COMPLETED
          */
        int taskStatus;
    public:
        Task();
        Task(int taskID, time_t dateCreated, string taskTitle, string taskBody, int taskImportanceLevel);
        void setTaskID(int taskID);
        int getTaskID();
        void setDateCreated(time_t dateCreated);
        time_t getDateCreated();
        void setTaskTitle(string taskTitle);
        string getTaskTitle();
        void setTaskBody(string taskBody);
        string getTaskBody();
        void setTaskImportanceLevel(int taskImportanceLevel);
        int getTaskImportanceLevel();
        void setTaskStatus(int taskStatus);
        int getTaskStatus();

};
