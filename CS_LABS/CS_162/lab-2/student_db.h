#include <iostream>
#include <fstream>
#include <string>

struct student{
	int id;
	std::string first;
	std::string last;
	std::string major;

};
void bubblesort_file(std::string l[], std::string s[]);
void bubblesort_ID_file(int[], std::string[], int, std::ofstream&);
void print_to_file(std::ofstream&,student*, int);
void makeoutput(student*, int);
int countlines(std::fstream&);
void progStart(std::fstream&, int);
student * createstudent(int numofstudents);
void get_student_info(int, std::fstream&);
void delete_student_Arr(student**, int);
void populatestudentArr(std::string, student*, int);
