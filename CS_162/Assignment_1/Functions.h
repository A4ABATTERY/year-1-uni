/*****************************************************************************************
Program/File name:	Function.h
Author:				Arunav Biswas
Date				April 15, 2018
Description:		This file contains all the fucntions headers and their descriptions
Input:				NONE
Output:				NONE
*****************************************************************************************/

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>

struct county{
	std::string name;
	std::string *city;
	int population;
	int cities;
	float avgIncome;
	float avgHouse;
};
struct state{
	std::string name;
	struct county *c;/*
		countyname
		city
			city names
		cities
		avgIncome
		avgHouse*/
	int counties;
	int population;
};
/****************************************************************************************/
/****************************************************************************************/
/* 			       			   FUNCTION REQUIRED BY ASSIGNMENT 					       */
/****************************************************************************************/
/****************************************************************************************/
/*********************************************************************
** Function:		Populate_state_info
** Description:		get the names of states and puts it in the array
** Parameters:		line from ifstream, pointer to state array, numbe
					of states.
** Pre-Condition:	command line arg, and size
** Post Condition:	bool, if is txt
*********************************************************************/
bool is_valid_arguments(char*[], int);
/*********************************************************************
** Function:		createstate
** Description:		create states array
** Parameters:		number of states
** Pre-Condition:	valid vars
** Post Condition:	void, make array
*********************************************************************/
state *createstate(int);
/*********************************************************************
** Function:		get_state_data
** Description:		gets state name
** Parameters:		state array, int state, line of ifstreawm.
** Pre-Condition:	valid vars
** Post Condition:	void, makes array, populates it
*********************************************************************/
void get_state_data(state*, int, std::ifstream&);
/*********************************************************************
** Function:		create_counties
** Description:		creates county array
** Parameters:		number of counties
** Pre-Condition:	int
** Post Condition:	passes back county pointe
*********************************************************************/
county* create_counties(int);
/*********************************************************************
** Function:		get_county_data
** Description:		gets names of counties
** Parameters:		county arra, number of counties, and ifstream
** Pre-Condition:	valid vars
** Post Condition:	void, populates array
*********************************************************************/
void get_county_data(county*, int,  std::ifstream&);
/*********************************************************************
** Function:		deletes array
** Description:		free meme
** Parameters:		state array, number of states
** Pre-Condition:	valid vars
** Post Condition:	void
*********************************************************************/
void delete_info(state**, int);
/****************************************************************************************/
/****************************************************************************************/
/* 					 	               OTHER FUNCTIONS				          	        */
/****************************************************************************************/
/****************************************************************************************/

/*********************************************************************
** Function:		printFYI()
** Description:		Prints 'for your information' stuffs
** Parameters:		none
** Pre-Condition:	none
** Post Condition:  none
*********************************************************************/
void printFYI();
/*********************************************************************
** Function:		bubblesort_file
** Description:		Sorts names by name and prints to file in alphabetical
					order
** Parameters:		string array, size of array, output stream
** Pre-Condition:	arrays are filled with correct values
** Post Condition:	void
*********************************************************************/
void bubblesort_file(std::string array[], int size, std::ofstream&OutputFile);
/*********************************************************************
** Function:		largestpop_file
** Description:		sorts counties/states based on number associated with the name.
					prints to files
** Parameters:		int array, string array, int, string, string, int
** Pre-Condition:	int array, string array, tempInt var, tempStr var, county/state, size
** Post Condition: 	void
*********************************************************************/
void largestpop_file(int tempPopArr[], std::string temp[], int tempInt, std::string tempStr, std::string place, int size, std::ofstream&OutputFile);
/*********************************************************************
** Function:		avgIncomeNHousehold_file
** Description:		prints to file, average household cost of states, and
					incomes above certain threshhold.
** Parameters:		string, county array, size of array, output  stream
** Pre-Condition:	All valid vars, output stream present
** Post Condition:	void prints out stuff
*********************************************************************/
void avgIncomeNHousehold_file(std::string statename, county* array, int size, std::ofstream&OutputFile);
/*********************************************************************
** Function:			fileStruct
** Description:			Oraganizes files and temporary arrays and then calls
						prints functions that print to files.
** Parameters:			state array, number of states, output stream
** Pre-Condition:		all valid vars
** Post Condition:		void, calls other functiosn
*********************************************************************/
void fileStruct(state* array, int states, std::ofstream&OutputFile);
/*********************************************************************
** Function:			print_to_file
** Description:			calls on output stream and calls fileStruct()
** Parameters:			state array, number of states
** Pre-Condition:		valid array, and var
** Post Condition:		void calls on another function
*********************************************************************/
void print_to_file(state* array, int states);
/*********************************************************************
** Function:		bubblesort_file
** Description:		Sorts names by name and prints to screen in alphabetical
					order
** Parameters:		string array, size of array, output stream
** Pre-Condition:	arrays are filled with correct values
** Post Condition:	void
*********************************************************************/
void bubblesort_print(std::string array[], int size);
/*********************************************************************
** Function:		largestpop_file
** Description:		sorts counties/states based on number associated with the name.
					prints to screen
** Parameters:		int array, string array, int, string, string, int
** Pre-Condition:	int array, string array, tempInt var, tempStr var, county/state, size
** Post Condition: 	void
*********************************************************************/
void largestpop_print(int tempPopArr[], std::string temp[], int tempInt, std::string tempStr, std::string place, int size);
/*********************************************************************
** Function:		avgIncomeNHousehold_file
** Description:		prints to screen, average household cost of states, and
					incomes above certain threshhold.
** Parameters:		string, county array, size of array, output  stream
** Pre-Condition:	All valid vars, output stream present
** Post Condition:	void prints out stuff
*********************************************************************/
void avgIncomeNHousehold_print(std::string statename, county* array, int size);
/*********************************************************************
** Function:			fileStruct
** Description:			Oraganizes files and temporary arrays and then calls
						prints functions that print to screen.
** Parameters:			state array, number of states, output stream
** Pre-Condition:		all valid vars
** Post Condition:		void, calls other functiosn
*********************************************************************/
void printStruct(state* array, int states);
/*********************************************************************
** Function:		create_cities
** Description:		creates city arrays
** Parameters:		number of cities
** Pre-Condition:	valid positive integer
** Post Condition:	passes back pointer to string array
*********************************************************************/
std::string* create_cities(int numOcities);
/*********************************************************************
** Function:			get_city_data
** Description:			string line, city array, number of cities
** Parameters:			line that has been read in the ifstream
						pointer to string array, size of array
** Pre-Condition:		valid variables
** Post Condition:		void, just appends array
*********************************************************************/
void get_city_data(std::string line, std::string* cityArr, int numOcities);
/*********************************************************************
** Function:		Populate_state_info
** Description:		get the names of counties and puts it in the array
** Parameters:		line from ifstream, pointer to county array, number
					of counties
** Pre-Condition:	valid vars
** Post Condition:	void, appends array
*********************************************************************/
void Populate_county_info(std::string line, county* countyArr, int county);
/*********************************************************************
** Function:		Populate_state_info
** Description:		get the names of states and puts it in the array
** Parameters:		line from ifstream, pointer to state array, numbe
					of states.
** Pre-Condition:	valid vars
** Post Condition:	void, populates array
*********************************************************************/
void Populate_state_info(std::string line, state* stateArr, int state);
/*********************************************************************
** Function:			is_state
** Description:			checks if line is a state
** Parameters:			string line
** Pre-Condition:		valid line
** Post Condition:		bool, t/f
*********************************************************************/
bool is_state(std::string line);
/*********************************************************************
** Function:		getsstate
** Description:		gets filename, and number of states from command line
** Parameters:		command line argument from main
** Pre-Condition:	valid command line arg
** Post Condition:	returns number of states
*********************************************************************/
int getstates(char*cmdline[]);
/*********************************************************************
** Function:		free_1D_mem
** Description:		free mem
** Parameters:		1 d char array
** Pre-Condition:	valid pointer
** Post Condition:	void
*********************************************************************/
void free_1D_mem(char* array);
/*********************************************************************
** Function:		GetNewFileName
** Description:		gets new file name if one given doesnt end in txt
** Parameters:		none
** Pre-Condition:	none
** Post Condition:	returns char pointer to c-style string
*********************************************************************/
char* GetNewFileName();
/*********************************************************************
** Function:		check_valid_filename
** Description:		gets filename
** Parameters:		commandline args
** Pre-Condition:	valid vars
** Post Condition:	checks files name, returns file name if valid
*********************************************************************/
char* check_valid_filename(char* str);
/*********************************************************************
** Function:		\getfilename
** Description:		gets file name from command line args
** Parameters:		command line arg
** Pre-Condition:	valid command line arg
** Post Condition:	c-style string
*********************************************************************/
char* getfilename(char*cmdline[]);
/*********************************************************************
** Function:		RunProgram
** Description:		Dictates flow of program
** Parameters:		commandline arguments
** Pre-Condition:	valid command line arg
** Post Condition:	void
*********************************************************************/
void RunProgram(char*cmdline[]);
