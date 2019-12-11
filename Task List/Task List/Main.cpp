#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::experimental::filesystem;

int main()
{
	std::cout << fs::current_path() << std::endl;
	//std::string path = "C:\\";
	//for (auto & p : fs::directory_iterator(path))
	//	std::cout << p << std::endl;
	system("pause");
}