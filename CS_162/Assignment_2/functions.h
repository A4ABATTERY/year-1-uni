/******************************************************
** Program: 	Functions.h / Functions.cpp
** Author: 		Arunav Biswas
** Date:		05/01/2018
** Description: Holds functions that contorl the flow
				of the program
** Input:		Mostly just chars that are parsed to string
				or to integers. Sometimes there are strings
				be inputted by the user.
** Output:		Varried, manipulates FileIO.
******************************************************/
#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "class-pizza.h"
#include "class-menu.h"
#include "class-restaurant.h"
using std::string;
/*******************************************************************************************
Function:			printspaces
Description:		printspaces
parameters:			integer, for how many spaces to be printed
Pre-condition:		none
Post-condition:		noen
********************************************************************************************/
void printspaces(int);
/*******************************************************************************************
Function:			makePizza()
Description:		Makes and populates pizza pointer
parameters:			size of pizza pointer (number of pizzas in menu)
Pre-condition:		given positive integer
Post-condition:		makes array, and passes back
********************************************************************************************/
pizza* makePizza(int);
/*******************************************************************************************
Function:			makeEmployees()
Description:		makes and populates employee pointer
parameters:			number of employees
Pre-condition:		positive integer
Post-condition:		makes arrray, and passes back
********************************************************************************************/
employee* makeEmployees(int);
/*******************************************************************************************
Function:			makeWeek()
Description:		makes and populates hours pointer
parameters:			number of employees
Pre-condition:		positive integer
Post-condition:		makes arrray, and passes back
********************************************************************************************/
hours* makeWeek(int);
/*******************************************************************************************
Function:			parseEmployee()
Description:		read txt file and pull out information to put into employee pointer
parameters:			line being read in file, employee pointer, index for emplyee;
Pre-condition:		positive integer
Post-condition:		populates array
********************************************************************************************/
void parseEmployee(string, employee *, int );
/*******************************************************************************************
Function:			getResInfo()
Description:		Pulls out usefull info from file for restaurant.
parameters:			passed in 3 string pointers
Pre-condition:		string pointers point to string on MAIN stack
Post-condition:		NONE, void
********************************************************************************************/
void getResInfo(string*, string*, string*);
/*******************************************************************************************
Function:			parsehours()
Description:		read txt file and pull out information to put into hours pointer
parameters:			line being read in file, hours pointer, index for emplyee;
Pre-condition:		positive integer
Post-condition:		populates array
********************************************************************************************/
void parseHours(string, hours*, int);
/*******************************************************************************************
Function:			countlines()
Description:		read txt file and count lines
parameters:			string, int
Pre-condition:		file name as a string, offset to be substracted on return value.
Post-condition:		returns number of lines in file
********************************************************************************************/
int countlines(string, int);
/*******************************************************************************************
Function:			getUsertype()
Description:		get if user is Customer or Employee
parameters:			noen
Pre-condition:		none
Post-condition:		passed back C or E
********************************************************************************************/
char getUsertype();
/*******************************************************************************************
Function:			customerinstruction()
Description:		users can pick what they want to do in the program
parameters:			none
Pre-condition:		none
Post-condition:		none
********************************************************************************************/
void customerinstruction(restaurant&);
/*******************************************************************************************
Function:			getsize()
Description:		gets size of pizza from user
parameters:			string
Pre-condition:		passed empty string
Post-condition:		passed back user entered string
********************************************************************************************/
string getsize(string);
/*******************************************************************************************
Function:			getBound()
Description:		modifies interger pointer that it is passed
parameters:			int pointer
Pre-condition:		get an int pointer
Post-condition:		user entered value is put into the pointer
********************************************************************************************/
void getBound(int*);
/*******************************************************************************************
Function:			printAgainQ()
Description:		Asks if you want to run again
parameters:			none
Pre-condition:		none
Post-condition:		none
********************************************************************************************/
void printAgainQ(int);
/*******************************************************************************************
Function:			printEmployeeOptions()
Description:		prints options for employees
parameters:			none
Pre-condition:		none
Post-condition:		none
********************************************************************************************/
void printCustomerOptions();
/*******************************************************************************************
Function:			getString()
Description:		gets string...
parameters:			none
Pre-condition:		none
Post-condition:		none
********************************************************************************************/
string getString();
/*******************************************************************************************
Function:			parseorders()
Description:		read txt file and pull out information to put into order pointer
parameters:			line being read in file, order pointer, index for order;
Pre-condition:		positive integer
Post-condition:		populates array
********************************************************************************************/
void parseorder(string, order*, int);
/*******************************************************************************************
Function:			getorder()
Description:		makes and populates order pointer
parameters:			number of order
Pre-condition:		positive integer
Post-condition:		makes arrray, and passes back
********************************************************************************************/
order* getorder(int);
/*******************************************************************************************
Function:			employeeinstruction()
Description:		takes in instructions from employee instructions
parameters:			restaurant R passed in as reference
Pre-condition:		valid pointer that is populated
Post-condition:		NONE, void
********************************************************************************************/
void employeeinstruction(restaurant&);
/*******************************************************************************************
Function:			printEmployeeOptions()
Description:		prints options for employees
parameters:			none
Pre-condition:		none
Post-condition:		none
********************************************************************************************/
void printEmployeeOptions();
