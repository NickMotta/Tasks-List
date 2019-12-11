#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::experimental::filesystem;
using namespace std;

int main()
{

	//program loop
	while (true) {



	}



	fs::path path = fs::current_path();
	path /= "data";
	std::cout << fs::current_path() << std::endl;

	for (auto & p : fs::directory_iterator(path))
		std::cout << p << std::endl;

	int directoryCounter;
	for (auto &p : fs::directory_iterator(path)) {
		directoryCounter += 1;
	}

	std::cout << directoryCounter << std::endl;
	system("pause");
}