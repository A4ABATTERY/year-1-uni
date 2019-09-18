/******************************************************
** Program: class-restaurant.h / class-restaurant.cpp
** Author: Arunav Biswas
** Date: 05/01/2018
** Description:	Holds Restaurant Class
** Input:		Mostly strings parsed to ints, sometimes
				kept as strings
** Output:		Maipulates fileIO, prints stuff to screen
******************************************************/
#pragma once

#include <string>
#include <fstream>
#include "class-menu.h"

using std::string;

struct order{
	string Order_num;
	string Custormer_Name;
	string Credit_Card;
	string Delivery_Address;
	string Custormer_Phone;
	string Pizza_Name;
	string Pizza_size;
	string Repeat;
};
struct employee{
	string id;
	string first_name;
	string last_name;
	string password;
};
struct hours{
	string day;
	string open_hours;
	string close_hours;
};


class restaurant{
	private:
		menu Menu;
		employee* employees;
		int numOemp;
		hours* week;
		int daysopen;
		order* orders;
		int numOorder;
		string name;
		string phone;
		string address;
		/*******************************************************************************************
		Function:			rewriteResInfo()
		Description:		Does not change any values in the class. Just open up Restaurant_info.txt
							and overwrites everything.
		parameters:			None
		Pre-condition:		none
		Post-condition:		Resized and appended array
		********************************************************************************************/
		void rewriteResInfo();
		/*******************************************************************************************
		Function:			rewriteOrders()
		Description:		Does not change any values in the class. Just open up orders.txt
							and overwrites everything.
		parameters:			None
		Pre-condition:		none
		Post-condition:		Resized and appended array
		********************************************************************************************/
		void rewriteOrders();
	public:
		//Access////////////////////////////////////////////////////////////////////////////////////
		/*******************************************************************************************
		All Accessors:	- DO NOT MANIPULATE ANYTHING.
						- They return their own return type
						- Have no pre-condition
						- Have basically no post condition, just returns data in Class
		********************************************************************************************/
		menu get_Menu() const;
		employee*  get_employees() const;
		hours* get_hours() const;
		string get_name() const;
		string get_phone() const;
		string get_address() const;
		int get_numOemp() const;
		//Mutate////////////////////////////////////////////////////////////////////////////////////
		/*******************************************************************************************
		All MUTATORS:	- Do what they say they are going to do.... ie set_menu(menu m) will takes
						Menu (defined in the class) and set it equal to m (the varibale passed to it)
						Menu = m;
						- Given, menu class, employee struct, hours struct, strings, ints, order struct
						- Sets variables in class.
		********************************************************************************************/
		void set_Menu(menu m);
		void set_employees(employee* e);
		void set_hours(hours* h);
		void set_name(string s);
		void set_phone(string s);
		void set_address(string s);
		void set_numOemp(int e);
		void set_numOorder(int i);
		void set_orders(order*);
		/*******************************************************************************************
		Default Constructor:	- Sets everything to Zero for integers, "" for strings, and NULL for
								  pointers.
								- Have no pre-condition or post-condition
		********************************************************************************************/
		restaurant();
		/*******************************************************************************************
		Non-Default Constructor:	- basically if you mashed up all the mutator functions in to one
									- Sets/initiallises all values in class to whatever it is passed
									- pre-condition: All vars must be of matching type
									- post-condition: All vars in class are initialised
		********************************************************************************************/
		restaurant(menu m, int nE, employee* e, int d, hours* h, string n, string p, string a, order*o, int no);
		//Destruct//////////////////////////////////////////////////////////////////////////////////
		/*******************************************************************************************
		DESTRUCTOR:		- Free's memomory on the heap
						- No pre-condition
						- post-condition... no memory leaks.
		********************************************************************************************/
		~restaurant();
		//Others
		/*******************************************************************************************
		Function:			printhours()
		Description:		Prints out hours struct
		parameters:			none
		Pre-condition:		hours array must be populated
		Post-condition:		none
		********************************************************************************************/
		void printhours();
		/*******************************************************************************************
		Function:			placeorder()
		Description:		This is technically a MUTATOR. resize array to plus-one of old size. Then
							prompts user for string input of what to put inside the extra(empty) array
							container.
		parameters:			None
		Pre-condition:		none
		Post-condition:		Resized and appended array
		********************************************************************************************/
		void placeorder();
		/*******************************************************************************************
		Function:			placeorder()
		Description:		This is technically a MUTATOR. resize array to plus-one of old size. Then
							prompts user for string input of what to put inside the extra(empty) array
							container.
		parameters:			None
		Pre-condition:		none
		Post-condition:		Resized and appended array
		********************************************************************************************/
		bool checklogin(string, string);
		void vieworders();
		void changehours();

		void removeorder();
};
