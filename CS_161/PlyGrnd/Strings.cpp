#include <iostream>
//these are the two funcitons needed to use strings
#include <string>
#include <istream>

//If namespace is not defined YOU ARE GOING TO HAVE TO USE
//std:: literally before everything you type

int main() {
	std::string test = "";
	std::cout << "Enter stuff: ";
	std::getline(std::cin, test);
	
	std::cout << "\nYou entered: " << test << "\n\n";

}
