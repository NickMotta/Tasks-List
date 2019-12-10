#include <string>
using namespace std;


struct ConfigSetting {
	string name;
	 attribute;

};

class ConfigParser
{
private:
	//variables
	// searches for a setting in the list of settings, returns the setting strut.
	ConfigSetting searchForSetting();

public:
	ConfigParser();
	~ConfigParser();
	// Loads the config files into an array
	void loadSettings();
	// Adds a new setting to the config file
	void addNewSetting();
	// Returns the setting that the user searched for
	configSetting getSetting();
};

