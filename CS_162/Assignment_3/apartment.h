/******************************************************
** Program: apartment.h / apartment.cpp
** Author: Arunav Biswas
** Date: 05/13/2018
** Description:	holds apartment class
** Input:		NONE
** Output:		NONE
******************************************************/
#include "building.h"


class Apartment : public Building{
	private:
		person* tenants;
		int num_tenants;
		/*******************************************************************************************
		Function:			initializeTenant()
		Description:		does literally what it says its going to do. uses rand() to assign random monthly_max for tenenat, then calculates agreeabilty and rent based off of that.
		parameters:			type person
		Pre-condition:		type person
		Post-condition:		initialize Tenant
		********************************************************************************************/
		void initializeTenant(person&);

	public:
		Apartment();
		/*******************************************************************************************
		Function:			Apartment(const Apartment&)
		Description:		Copy constructor
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		Makes copy
		********************************************************************************************/
		Apartment(const Apartment&);
		~Apartment();
		/*******************************************************************************************
		Function:			printinfo()
		Description:		print info stored in class
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		noen
		********************************************************************************************/
		void printinfo();
		Apartment(person* T, int t);
		/*******************************************************************************************
		Function:			const Business_complex& operator=(const Business_complex&)
		Description:		Makes deep-copy
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		Adds functionality to assignment operator.
		********************************************************************************************/
		const Apartment& operator=(const Apartment&);


};
