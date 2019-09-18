#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include "student_db.h"



void delete_student_Arr(student** a, int size){
	delete [] (*a);
	a = NULL;
}
int countlines(std::fstream&DataBase){
	int numOlines = 0;
	std::string temp;
	while (getline(DataBase, temp))
			numOlines++;
	return numOlines;
}
void progStart(std::fstream& DataBase, int students = 0){
	students = countlines(DataBase);
	get_student_info(students, DataBase);


}
student * createstudent(int numofstudents){
	student* array = new student[numofstudents];
	return array;
}
void get_student_info(int students, std::fstream& DataBase){
	std::string temp; int run = 0; int i = 0;
	DataBase.clear();
	DataBase.seekg(0 , std::ios::beg);
	student* studArr;
	studArr = createstudent(students);
	while (getline(DataBase, temp)) {
		populatestudentArr(temp, studArr, i);
		i++;
	}DataBase.close();
	makeoutput(studArr, students);
	}
void bubblesort_ID_file(int a[], std::string s[], int size, std::ofstream&OutputFile) {
	int i, j; std::string tempStr; int tempInt;
	for(i = 1; i < size; i++)
		for(j = 1; j < size; j++)
			if(a[j-1] < a [j]){
				tempInt = a[j-1]; 	tempStr = s[j-1];
				a[j-1] = a[j]; 		s[j-1] = s[j];
				a[j] = tempInt;		s[j] = tempStr;
			}
		OutputFile << "Sorted by ID number:\n";
	for (int i = 0; i < size; i++) {
		OutputFile << a[i] << ' ' << s[i] << '\n';
	}OutputFile << "\n\n";
}
void bubblesort_file(std::string l[], std::string s[], int size, std::ofstream&OutputFile){
	int i, j; std::string tempStr; std::string tempStrOne;
	for(i = 1; i < size; i++)
		for(j = 1; j < size; j++)
			if((strcmp(l[j-1].c_str(), l[j].c_str()) > 0)){
				tempStrOne = l[j-1]; 	tempStr = s[j-1];
				l[j-1] = l[j]; 			s[j-1] = s[j];
				l[j] = tempStrOne;		s[j] = tempStr;
			}
		OutputFile << "Sorted by ID last name:\n";
	for (int i = 0; i < size; i++) {
		OutputFile << l[i] << ' ' << s[i] << '\n';
	}std::cout << "\n\n";
	OutputFile << "\n\n";
}
void Unique_Majors(std::string a[], int size, std::ofstream&OutputFile){
	int UniqueMajors = size;
	for (int i = 1; i < size; i++) {
		if (a[i-1] == a[i])
			UniqueMajors--;
	}
	OutputFile << "\n\nThere are " << UniqueMajors << " unique majors" << '\n';
}
void print_to_file(std::ofstream&OutputFile, student*arr, int size){
	int tempID[size]; std::string tempSTR[size];
	std::string lastname[size];
	for (int i = 0; i < size; i++) {
		tempID[i] = arr[i].id;
		tempSTR[i] = "";
		tempSTR[i] += arr[i].first; tempSTR[i] += ' ';
		tempSTR[i] += arr[i].last; tempSTR[i] += ' ';
		tempSTR[i] += arr[i].major;
	}bubblesort_ID_file(tempID, tempSTR, size, OutputFile);

	for(int i = 0; i < size; i++){
		lastname[i] = arr[i].last;
		tempSTR[i] = "";
		tempSTR[i] += arr[i].first; tempSTR[i] += ' ';
		tempSTR[i] += (arr[i].id); tempSTR[i] += ' ';
		tempSTR[i] += arr[i].major;
	}bubblesort_file(lastname, tempSTR, size, OutputFile);

	for(int i = 0; i < size; i++){
		tempSTR[i] = " ";
		tempSTR[i] = arr[i].major;
	}Unique_Majors(tempSTR, size, OutputFile);



}
void makeoutput(student* arr, int size) {
	std::ofstream OutputFile("OutPutFile.txt");
	if (OutputFile.is_open()){
		OutputFile.flush();
		std::cout << "Writing to file..." << '\n';
		print_to_file(OutputFile, arr, size);
		OutputFile.flush();
		std::cout << "All done :) " << '\n';
		OutputFile.close();
		delete_student_Arr(&arr, size);
		exit(0);
	}
}
void populatestudentArr(std::string line, student* array, int j){
	std::string temp; int i = 0; int end = line.length();
	for(; line[i] != ' '; i++)
		temp += line[i];
	array[j].id = atoi(temp.c_str());

	for(i++; line[i] != ' '; i++)
		array[j].first += line[i];

	for(i++; line[i] != ' '; i++)
		array[j].last += line[i];

	for(i++; i < end; i++){
		array[j].major += line[i];
	}

//	std::cout << array[j].id << ' ' << array[j].first << ' ';
//	std::cout << array[j].last << ' ' << array[j].major << '\n';


}
