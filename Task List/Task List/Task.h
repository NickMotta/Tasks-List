#include <string>
#include <ctime>
using namespace std;

class task {

    private:
        int taskID;
        DateTime dateCreated;
        string taskTitle;
        string taskBody;
        int taskImportanceLibrary
    public:
        void setTaskId(int taskID);
        int getTaskId();
        void setDateCreated(DateTime dateCreated);
        DateTime getDateCreated();
        void setTaskTitle(string taskTitle);
        string getTaskTitle();
        void setTaskBody(string taskBody);
        string getTaskBody();
        void setTaskImportanceLevel(int taskImportanceLevel);
        int getTaskImportanceLevel();

};
