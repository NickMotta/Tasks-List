using namespace std;

class task {

    private:
        int taskID;
        DateTime dateCreated;
        String taskTitle;
        String taskBody;
        int taskImportanceLibrary
    public:
        void setTaskId(int taskID);
        int getTaskId();
        void setDateCreated(DateTime dateCreated);
        DateTime getDateCreated();
        void setTaskTitle(String taskTitle);
        String getTaskTitle();
        void setTaskBody(String taskBody);
        String getTaskBody();
        void setTaskImportanceLevel(int taskImportanceLevel);
        int getTaskImportanceLevel();

};
