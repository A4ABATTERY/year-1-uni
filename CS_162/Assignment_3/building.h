/******************************************************
** Program: building.h / building.cpp
** Author: Arunav Biswas
** Date: 05/13/2018
** Description:	Holds building class  (parent)
** Input:		NONE
** Output:		NONE
******************************************************/
#pragma once
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

struct person{
	int agree;
	int Monthly;
	int rent;
};
class Building{
	protected:

		float value;
		int location;
		float mortgage;

		float tax;
		bool owned;
		int min_startprice;
		int max_startprice;

	public:
		Building();

		/*******************************************************************************************
		Function:			Get functions
		Description:		all these functions return what they say theyre going to return. ie. getvalue() returns value
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		returns what it says its going to return...
		********************************************************************************************/
		float getValue();
		int getLocation();
		float getMortgage();
		float getTax();

		/*******************************************************************************************
		Function:			set funcitons
		Description:		all these functions set the value in its name(function prototype) to the value passed to it
		parameters:			integers..
		Pre-condition:		Old-value
		Post-condition:		sets to value passed to it.
		********************************************************************************************/
		void setValue(int);
		void setMortgage(int);

		/*******************************************************************************************
		Function:			Building(const Building&)
		Description:		Copy constructor
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		Makes copy
		********************************************************************************************/
		Building(const Building&);
		/*******************************************************************************************
		Function:			const Building& operator=(const Building&)
		Description:		Makes deep-copy
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		Adds functionality to assignment operator.
		********************************************************************************************/
		const Building& operator=(const Building&);

};
