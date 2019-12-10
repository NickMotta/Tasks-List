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

};
