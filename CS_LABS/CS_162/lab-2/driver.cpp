#include <iostream>
#include <fstream>
#include "student_db.h"
// using std::fstream;



int main(){
	std::fstream DataBase;
	DataBase.open("input.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	if(DataBase.is_open()){
		std::cout << "File open :)" << '\n';
		progStart(DataBase, 0);
	}
	DataBase.close();
	if(!(DataBase.is_open())){
		std::cout << "File is closed" << '\n';}

	return 0;


}
