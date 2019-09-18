/*****************************************************************************************
Program/File name:	Function.cpp
Author:				Arunav Biswas
Date				April 15, 2018
Description:		This file contains the code for the function headers in Fucntions.h
Input:				File present in working directory
Output:				Data printed in sorted oreders, OR makes new files
*****************************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "Functions.h"

bool is_valid_arguments(char*cmdline[], int size){
	if ( (cmdline[0][0] == '-') && (cmdline[0][1] == 's') && (cmdline[0][2] == '\0') )
	 	if ( (cmdline[2][0] == '-') && (cmdline[2][1] == 'f') && (cmdline[2][2] == '\0') ){
			return true;
		}
	if ( (cmdline[0][0] == '-') && (cmdline[0][1] == 'f') && (cmdline[0][2] == '\0') )
	 	if ( (cmdline[2][0] == '-') && (cmdline[2][1] == 's') && (cmdline[2][2] == '\0') ) {
			return true;
		}
		std::cout << "Return false" << '\n';
	return false;
}
state *createstate(int numOfStates){
	state* array = new state[numOfStates];
	return array;
}
void get_state_data(state*stateArr, int numOfStates, std::ifstream& f){
	printFYI(); int numOcounties = 0; int state = 0;
	std::string line;
	while (getline(f, line)) {
		if(is_state(line)){
			// std::cout << line << '\n';
			 Populate_state_info(line, stateArr, state);
			 state++;
		}
	}f.clear(); f.seekg(0, std::ios::beg);
}
county* create_counties(int numOcounties){
	county*array = new county[numOcounties];
	return array;
}
void get_county_data(county* countyArr, int counties, std::ifstream& f){
	int numOcities = 0; int i = 0; int cursor = 0;
	std::string line;
	// f.clear(); f.seekg(0, std::ios::beg);
	while (i != counties){
		getline(f, line);

		if (!(is_state(line))) {
			Populate_county_info(line, countyArr, i);
			i++;

		}

	}//f.clear(); f.seekg(0, std::ios::beg);
	std::cout << "\n\n" << '\n';
}
void delete_info(state** array, int numOfStates){

	for(int i = 0; i < numOfStates; i++){
		for(int j = 0; j < (*array)[i].counties; j++){
			delete[](*array)[i].c[j].city;
			(*array)[i].c[j].city = NULL;
		}
		delete[](*array)[i].c;
		(*array)[i].c = NULL;
	}
//	delete[](*array);
//	(*array) = NULL;
}

void printFYI(){
	std::cout << "\n\n\n\n" << '\n';
	std::cout << "Just FYI\n-   Names of states, counties, and cities are not error handled" << '\n';
	std::cout << "    because you can technically enter anything as the name of a state ¯\\_(ツ)_/¯" << '\n';
	std::cout << "-   Only Positive Nubmers are accepted :), No Negativity pls :(" << '\n';
	std::cout << "    oh and zero doesnt count" << '\n';
	std::cout << "\n\n\n\n" << '\n';

}

void bubblesort_file(std::string array[], int size, std::ofstream&OutputFile) {
	bool flag = true; int j, i; std::string temp;
	for(i = 1; i < size; i++){
		for (j = 1; j < size; j++){
			if (strcmp(array[j-1].c_str(), array[j].c_str()) > 0){
				temp = array[j-1];
				array[j-1] = array[j];
				array[j] = temp;
			}
		}
	}
	for(i = 0; i < size; i++){
		OutputFile << array[i] << "  ||  ";
	}OutputFile << "\n" << '\n';
	//delete[]array;
}
void largestpop_file(int tempPopArr[], std::string temp[], int tempInt, std::string tempStr, std::string place, int size, std::ofstream&OutputFile) {
	int i, j;
	for(i  = 1; i < size; i++){
		for (j = 1; j < size; j++){
			if (tempPopArr[j-1] < tempPopArr[j]){
				tempInt = tempPopArr[j-1];		  tempStr = temp[j-1];
				tempPopArr[j-1] = tempPopArr[j] ; temp[j-1] = temp[j];
				tempPopArr[j] = tempInt;		  temp[j] = tempStr;
			}
		}
	}
	OutputFile << temp[0] << " has the largest population at " << tempPopArr[0] <<'\n';
	OutputFile << "\n" << place <<" in order of largest population" << '\n';
	for(i = 0; i < size; i++){
		OutputFile << temp[i] << " at " << tempPopArr[i] << "  ||  ";
	}OutputFile << "\n" << '\n';


}
void avgIncomeNHousehold_file(std::string statename, county* array, int size, std::ofstream&OutputFile){
	int lowerLimit; int avghouseholdcost; std::string str;
	for (int i = 0; i < size; i++) {
		avghouseholdcost += (array[i].avgHouse)/size;
	}
	OutputFile<< "Average house hold cost for state = " << avghouseholdcost << '\n';
	std::cout << "Please enter an income threshhold you'd like to check for: ";
	do{
		std::cin >> str;
	}while((!(atoi(str.c_str()))) || (!(atoi(str.c_str()) > 0)));
	lowerLimit = (atoi(str.c_str()));
	OutputFile << "\n" << '\n';
	OutputFile << "Average income of counties above " << lowerLimit << '\n';
	for(int i = 0; i < size; i++){
		if(lowerLimit < array[i].avgIncome)
			OutputFile << array[i].name << " " << array[i].avgIncome << "  ||  ";
	} OutputFile << "\n" << '\n';

}
void fileStruct(state* array, int states, std::ofstream&OutputFile){
	int size = states; std::string StatesCpy[size];
	//print states sorted
	for(int i = 0; i < size; i++)
		StatesCpy[i] = array[i].name;
	std::cout << OutputFile.tellp() <<'\n';
	OutputFile << "Printing states in a sorted order" << '\n';
	std::cout << OutputFile.tellp() <<'\n';
	bubblesort_file(StatesCpy, size, OutputFile);

	//printing counties sorted
	for(int i = 0; i < states; i++){
		size = array[i].counties;
		std::string CountyCpy[size];
		OutputFile << "Printing counties in sorted order for " << array[i].name << '\n';
		std::cout << OutputFile.tellp() <<'\n';

		for(int j = 0; j < size; j++){
			CountyCpy[j] = array[i].c[j].name;
		} bubblesort_file(CountyCpy, size, OutputFile);
	}
	int tempPopArr[size]; std::string temp[size];int tempInt; std::string tempStr;
	for(int i = 0; i < size; i++){
		tempPopArr[i] = array[i].population;
		temp[i] = array[i].name;
	} largestpop_file(tempPopArr, temp, tempInt, tempStr, "States", states, OutputFile);

	//County with largest population
	for(int i = 0; i < states; i++){
		size = array[i].counties;
		int countyPopArr[array[i].counties]; std::string countyArr[array[i].counties];
		int tempInt = 0;				     std::string tempStr;
		for(int j = 0; j < size; j++){
			countyPopArr[j] = array[i].c[j].population;
			countyArr[j] = array[i].c[j].name;
		}
		OutputFile << "For " << array[i].name << '\n';
		std::cout << OutputFile.tellp() <<'\n';

		largestpop_file(countyPopArr, countyArr, tempInt, tempStr, "Counties", array[i].counties, OutputFile);
	}	std::cout << OutputFile.tellp() <<'\n';

	for(int i = 0; i < states; i++){
		OutputFile << "For " << array[i].name <<'\n';	std::cout << OutputFile.tellp() <<'\n';
		avgIncomeNHousehold_file(array[i].name, array[i].c, array[i].counties, OutputFile);
	}	std::cout << OutputFile.tellp() <<'\n';

}

void print_to_file(state* array, int states){
		std::ofstream OutputFile;
		OutputFile.open("file1.txt", std::ofstream::out);
		if (OutputFile.is_open()){
			OutputFile.flush();
			std::cout << "Made and writing to files" << '\n';
			OutputFile << "writing to file...\n\n\n";
			//OutputFile.close();
			fileStruct(array, states, OutputFile);
			std::cout << "Done..." << '\n';
			std::cout << OutputFile.tellp() <<'\n';
			OutputFile.close();
			exit(0);
		}else{

			std::cout << "File could not be made :(" << '\n';
			exit(-1);
		}




}
void bubblesort_print(std::string array[], int size) {
	bool flag = true; int j, i; std::string temp;
	for(i = 1; i < size; i++){
		for (j = 1; j < size; j++){
			if (strcmp(array[j-1].c_str(), array[j].c_str()) > 0){
				temp = array[j-1];
				array[j-1] = array[j];
				array[j] = temp;
			}
		}
	}
	for(i = 0; i < size; i++){
		std::cout << array[i] << "  ||  ";
	}std::cout << "\n" << '\n';
	//delete[]array;
}
void largestpop_print(int tempPopArr[], std::string temp[], int tempInt, std::string tempStr, std::string place, int size) {
	int i, j;
	for(i  = 1; i < size; i++){
		std::cout << "Seg1" << '\n';
		for (j = 1; j < size; j++){
			std::cout << "Seg2" << '\n';
			if (tempPopArr[j-1] < tempPopArr[j]){
				tempInt = tempPopArr[j-1];		  tempStr = temp[j-1];
				tempPopArr[j-1] = tempPopArr[j] ; temp[j-1] = temp[j];
				tempPopArr[j] = tempInt;		  temp[j] = tempStr;
			}
		}
	}
	std::cout << temp[0] << " has the largest population at " << tempPopArr[0] <<'\n';
	std::cout << "\n" << place <<" in order of largest population" << '\n';
	for(i = 0; i < size; i++){
		std::cout << temp[i] << " at " << tempPopArr[i] << "  ||  ";
	}std::cout << "\n" << '\n';


}
void avgIncomeNHousehold_print(std::string statename, county* array, int size){
	int lowerLimit; int avghouseholdcost; std::string str;
	for (int i = 0; i < size; i++) {
		avghouseholdcost += (array[i].avgHouse)/size;
	}
	std::cout << "Average house hold cost for state = " << avghouseholdcost << '\n';
	std::cout << "Please enter an income threshhold you'd like to check for: ";
	do{
		std::cin >> str;
	}while((!(atoi(str.c_str()))) || (!(atoi(str.c_str()) > 0)));
	lowerLimit = (atoi(str.c_str()));
	std::cout << "\n" << '\n';
	std::cout << "Average income of counties above " << lowerLimit << '\n';
	for(int i = 0; i < size; i++){
		if(lowerLimit < array[i].avgIncome)
			std::cout << array[i].name << " " << array[i].avgIncome << "  ||  ";
	} std::cout << "\n" << '\n';

}
void printStruct(state* array, int states){
	int size = states; std::string StatesCpy[size];
	//print states sorted
	for(int i = 0; i < size; i++)
		StatesCpy[i] = array[i].name;
	std::cout << "Printing states in a sorted order" << '\n';
	bubblesort_print(StatesCpy, size); std::cout << "Seg" << '\n';

	//printing counties sorted
	for(int i = 0; i < states; i++){
		size = array[i].counties;
		std::string CountyCpy[size];
		std::cout << "Printing counties in sorted order for " << array[i].name << '\n';
		for(int j = 0; j < size; j++){
			CountyCpy[j] = array[i].c[j].name;
		}// bubblesort_print(CountyCpy, size);
	}
	int tempPopArr[size]; std::string temp[size];int tempInt; std::string tempStr;
	for(int i = 0; i < size; i++){
		tempPopArr[i] = array[i].population;
		temp[i] = array[i].name;
	} largestpop_print(tempPopArr, temp, tempInt, tempStr, "States", states);

	//County with largest population
	for(int i = 0; i < states; i++){
		size = array[i].counties;
		int countyPopArr[array[i].counties]; std::string countyArr[array[i].counties];
		int tempInt = 0;				     std::string tempStr;
		for(int j = 0; j < size; j++){
			countyPopArr[j] = array[i].c[j].population;
			countyArr[j] = array[i].c[j].name;
		}
		std::cout << "For " << array[i].name << '\n';
		largestpop_print(countyPopArr, countyArr, tempInt, tempStr, "Counties", array[i].counties);
	}
	for(int i = 0; i < states; i++){
		std::cout << "For " << array[i].name <<'\n';
		avgIncomeNHousehold_print(array[i].name, array[i].c, array[i].counties);
	}
	// delete[]tempPopArr; delete[]temp;delete[]StatesCpy;
	//&tempPopArr = NULL; &temp = NULL; &StatesCpy = NULL;
}


std::string* create_cities(int numOcities){
	std::string*array = new std::string[numOcities];
	return array;
}
void get_city_data(std::string line, std::string* cityArr, int numOcities){
 	std::string temp; int m = 0; int end = line.length();
		for(int j = 0; j < numOcities;)
			for(int i = 0; i < end ; i++){
				if((line[i] == ' ') || (i == end - 1)){
					for(int k = m; k <= i; k++)
						temp += line[k];
					cityArr[j] = temp; temp = "";
					// std::cout << cityArr[j] << '\n';
					m = i + 1; j++;
				}
	}
}
void Populate_county_info(std::string line, county* countyArr, int county){
	std::string temp; int i = 0; int end = line.length();
	for(i = 0; line[i] != ' '; i++){
		countyArr[county].name += line[i];
	}
	//std::cout << countyArr[county].name << '\n';
	for(i = i+1; line[i] != ' '; i++){
		temp += line[i];
	} countyArr[county].population = atoi(temp.c_str());
	// std::cout << countyArr[county].population << '\n';
	temp = "";
	for(i = i+1; line[i] != ' '; i++){
		temp += line[i];
	} countyArr[county].avgIncome = atof(temp.c_str());
	// std::cout << countyArr[county].avgIncome << '\n';
	temp = "";
	for(i = i+1; line[i] != ' '; i++){
		temp += line[i];
	} countyArr[county].avgHouse = atof(temp.c_str());
	// std::cout << countyArr[county].avgHouse << '\n';
	temp = "";
	for(i = i+1; line[i] != ' '; i++){
		temp += line[i];
	} countyArr[county].cities = atoi(temp.c_str());
	//std::cout << countyArr[county].cities << '\n';
	temp = "";
	countyArr[county].city = create_cities(countyArr[county].cities);
	for(i = i+1; i < end; i++){
		temp += line[i];
	} get_city_data(temp, countyArr[county].city, countyArr[county].cities);
}
void Populate_state_info(std::string line, state* stateArr, int state){
	int first = 0; int second = 0; int end = line.length();
	std::string stateName; std::string statePop_STR; std::string NumOcounties_STR;

	for(; line[first] != ' '; first++){
		stateName += line[first];
	}stateArr[state].name = stateName;
	// std::cout << stateArr[state].name << '\n';

	for(second = first + 1; line[second] != ' '; second++){
		statePop_STR += line[second];
	}stateArr[state].population = atoi(statePop_STR.c_str());
	// std::cout << stateArr[state].population << '\n';

	for(int i = second + 1; i < end; i++){
		NumOcounties_STR += line[i];
	}stateArr[state].counties = atoi(NumOcounties_STR.c_str());
	// std::cout << stateArr[state].counties << "\n\n\n\n";

	stateArr[state].c = create_counties(stateArr[state].counties);
}
bool is_state(std::string line){
	int numOspaces = 0;
	for(int i = 0; i < line.length(); i++){
		if (line[i] == ' ')
			numOspaces++;
	}
	if (numOspaces == 2){
		return true;
	}return false;
}
int getstates(char*cmdline[]){
	char *str;
	if(cmdline[0][1] == 's'){
		str = cmdline[1];
		if (atoi(str))
			return atoi(str);

	}else if(cmdline[2][1] == 's'){
		str = cmdline[3];
		if (atoi(str))
			return atoi(str);
		}
	return -1;
}
void free_1D_mem(char* array){
	delete[]array;
	array = NULL;
}
char* GetNewFileName(){
	char *temp = new char[256];
	char *str;
	std::cout << "Plese enter a new file name with the file extension \nat the end. i.e. \'filename.txt\': ";
	std::cin >> temp;
	str = temp; free_1D_mem(temp);
	return str;
}
char* check_valid_filename(char* str){
	int len; len = strlen(str) - 1;
	while(!(str[len] == 't' && str[len-1] == 'x' && str[len-2] == 't' && str[len-3] == '.')){
 		str = GetNewFileName();
		len = strlen(str) - 1;
	 }
	return str;
}
char* getfilename(char*cmdline[]){
	char* str;
	if(cmdline[0][1] == 'f'){
		str = cmdline[1];
		return check_valid_filename(str);
	}else if(cmdline[2][1] == 'f'){
		str = cmdline[3];
		str = check_valid_filename(str);
		return str;
		}
		std::cout << "Invalid file name" << '\n';
		exit(-1);

}
void RunProgram(char*cmdline[]){
	int numOfStates = getstates(&cmdline[0]);
	char* Filename = getfilename(&cmdline[0]);
	std::string YN;
	std::cout << "File name is = "<<Filename << '\n';
	if (numOfStates <= 0) {std::cout << "Error in -s Argument. ERROR -1 :(" << '\n'; exit(-1);}
	std::ifstream f;
	f.open (Filename, std::ifstream::out | std::ifstream::in);
	if (f.is_open()){
		state* stateArr = createstate(numOfStates);
		get_state_data(stateArr, numOfStates, f);
		f.seekg(0, std::ios::beg);
		for(int state = 0; state < numOfStates; state++){
			get_county_data(stateArr[state].c, stateArr[state].counties, f);
		}
		std::cout << "Default - Print All contents to screen" << '\n';
		do {
			std::cout << "Would you like to print to a file(Y/N): ";
			std::cin >> YN;
		} while(!(YN == "Y" || YN == "N"));
		if(YN == "N"){
			f.close();
			printStruct(stateArr, numOfStates);
			//std::cout << "Print" << '\n';
		}else if(YN == "Y"){
			f.close();
			print_to_file(stateArr, numOfStates);

			//std::cout << "Dont print" << '\n';

			}delete_info(&stateArr, numOfStates);

		}else{
			std::cout << "File not found" << '\n';
			std::cout << "Program ending...\n Please make sure the file exists :(" << '\n';
			exit(-1);
	}

}
