#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "littlelog.hpp"

//int main() {
//	std::string message = "Writing this to a file.";
//	LOG(message);
//	return 0;
//}

void LOG(std::string message)
{
	std::time_t start = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::string startTimeString = std::ctime(&start);
	startTimeString.erase(startTimeString.find('\n', 0), 1);
	std::ofstream myfile;
	myfile.open ("output.log", std::fstream::app);
	myfile << startTimeString;
	myfile << " ";
	myfile << message;
	myfile << "\n";
	myfile.close();
}