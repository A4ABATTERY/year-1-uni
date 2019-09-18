/******************************************************
** Program: class-pizza.h / class-pizza.cpp
** Author: Arunav Biswas
** Date: 05/01/2018
** Description:	Holds Pizza Class
** Input:		No user input, only takes input through
				parameters
** Output:		None
******************************************************/
#pragma once
#include <string>

using std::string;

class pizza{
	private:
		string name;
		int small_price;
		int med_price;
		int large_price;
		int num_ingredients;
		string* ingredients;

		/*******************************************************************************************
		Function:			makeint()
		Description:		Takes a string and performs atoi on it. then returns the value
		parameters:			string number
		Pre-condition:		passed in a string number, otherwise it returns -1
		Post-condition:		returns some number
		********************************************************************************************/
		int makeint(string l);
		/*******************************************************************************************
		Function:			makeIngredientsArr
		Description:		Makes an array of string so that it can be populated with ingredients
		parameters:			given the end snippet from line from menu.txt (just the part with
							ingredients)
		Pre-condition:		valid string (num_ingredients ingredient1 ingredient2 ingredient3... etc.)
		Post-condition:		makes and populates string array for pizza
		********************************************************************************************/
		void makeIngredientsArr(string line);
	public:
		//Construct/////////////////////////////////////////////////////////////////////////////////
		/*******************************************************************************************
		Default Constructor:	- Sets everything to Zero for integers, "" for strings, and NULL for
								  pointers.
								- Have no pre-condition or post-condition
		********************************************************************************************/
		pizza();
		/*******************************************************************************************
		Non-Default Constructor:	- basically if you mashed up all the mutator functions in to one
									- Sets/initiallises all values in class to whatever it is passed
									- pre-condition: All vars must be of matching type
									- post-condition: All vars in class are initialised
		********************************************************************************************/
		pizza(string, int, int, int, int, string*);
		//Access////////////////////////////////////////////////////////////////////////////////////
		/*******************************************************************************************
		All Accessors:	- DO NOT MANIPULATE ANYTHING.
						- They return their own return type
						- Have no pre-condition
						- Have basically no post condition, just returns data in Class
		********************************************************************************************/
		string get_Pizza_Name() const;
		int get_price_Small_Pizza() const;
		int get_med_Price_Pizza() const;
		int get_large_Price_Pizza() const;
		int get_num_ingredients_PIzza() const;
		string* get_Pizza_ingredients() const;
		//Mutate////////////////////////////////////////////////////////////////////////////////////
		/*******************************************************************************************
		All MUTATORS:	- Do what they say they are going to do.... ie set_Pizza_Name(), will set
						  'string name' inside the class to whatever string it is given
						- Some funciton prototypes are overloaded...
							- When passed a string, the string is passed to a checkint funciton(
							  basically a glorified atoi(str) )
							- When passed an int, varible being manipulated is simply set to the varible
							  passed to it.
						- Given string or integers
						- Sets variables in class.
		********************************************************************************************/
		void set_Pizza_Name(string);
		void set_Small_price_Pizza(string);
		void set_med_Price_Pizza(string);
		void set_large_Price_Pizza(string);
		void set_num_ingredients_PIzza(string);
		void set_Small_price_Pizza(int);
		void set_med_Price_Pizza(int);
		void set_large_Price_Pizza(int);
		void set_num_ingredients_PIzza(int);
		void set_Pizza_ingredients(string*);
		/*******************************************************************************************
		Function:			parsePizza()
		Description:		Parses through a string that is passed to it. this function extracts
							data from the string and sets variables in the class to the data it
							extracts;
		parameters:			Passed in a valid string line
		Pre-condition:		valid string line from file
		Post-condition:		Sets vars in class.
		********************************************************************************************/
		void parsePizza(string line);
		//Copy Construct////////////////////////////////////////////////////////////////////////////
		/*******************************************************************************************
		CONSTRUCTOR:	- Does not chage values.
						- sets a copy's values to the values of the class itself.
		********************************************************************************************/
		pizza(const pizza&);
		//Destruct//////////////////////////////////////////////////////////////////////////////////
		/*******************************************************************************************
		DESTRUCTOR:		- Free's memomory on the heap
						- No pre-condition
						- post-condition... no memory leaks.
		********************************************************************************************/
		~pizza();
		//Overload//////////////////////////////////////////////////////////////////////////////////
		/*******************************************************************************************
		OPERATOR OVERLOAD:		- Makes a deep copy
								- No pre-condition
								- basically Cut and paste on a computer.
								- Frees memory makes sure there are no leaks
		********************************************************************************************/
		const pizza& operator=( pizza&);
		//Others////////////////////////////////////////////////////////////////////////////////////
		/*******************************************************************************************
		Function:			printPizzaInfo()
		Description:		Cout(s) information of the pizza class
		parameters:			none
		Pre-condition:		none
		Post-condition:		none
		********************************************************************************************/
		void printPizzaInfo();
};
