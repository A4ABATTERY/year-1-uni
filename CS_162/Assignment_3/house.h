/******************************************************
** Program: house.h / house.cpp
** Author: Arunav Biswas
** Date: 05/13/2018
** Description:	Holds hous class
** Input:		NONE
** Output:		print to sceen
******************************************************/
#include "building.h"

class House : public Building{
	private:
		person tenant;
		/*******************************************************************************************
		Function:			initializeTenant()
		Description:		does literally what it says its going to do. uses rand() to assign random monthly_max for tenenat, then calculates agreeabilty and rent based off of that.
		parameters:			type person
		Pre-condition:		type person
		Post-condition:		initialize Tenant
		********************************************************************************************/
		void initializeTenant(person&);

	public:
		/*******************************************************************************************
		Function:			House()
		Description:		initialize House class
		parameters:			none
		Pre-condition:		none
		Post-condition:		initialize house class
		********************************************************************************************/
		House();
		/*******************************************************************************************
		Function:			House(const House&)
		Description:		Copy constructor
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		Makes copy
		********************************************************************************************/
		House(const House&);
		/*******************************************************************************************
		Function:			printinfo()
		Description:		print info stored in class
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		noen
		********************************************************************************************/
		void printinfo();
		/*******************************************************************************************
		Function:			const House& operator=(const House&)
		Description:		Makes deep-copy
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		Adds functionality to assignment operator.
		********************************************************************************************/
		const House& operator=(const House&);
};
