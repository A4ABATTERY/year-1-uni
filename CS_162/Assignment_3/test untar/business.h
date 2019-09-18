/******************************************************
** Program: building.h / building.cpp
** Author: Arunav Biswas
** Date: 05/13/2018
** Description:	Holds business class
** Input:		NONE
** Output:		print to screen
******************************************************/
#include "building.h"



class Business_complex : public Building{
	private:
		char size;
		int num_business;
		person* BusInComplex;

		/*******************************************************************************************
		Function:			initializeBusInComplex()
		Description:		does literally what it says its going to do. uses rand() to assign random monthly_max for tenenat, then calculates agreeabilty and rent based off of that.
		parameters:			type person
		Pre-condition:		type person
		Post-condition:		initialize Tenant
		********************************************************************************************/
		void initializeBusInComplex(person&);

	public:
		/*******************************************************************************************
		Function:			Business_complex
		Description:		Initialzes class with random values
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		initialize class
		********************************************************************************************/
		Business_complex();
		/*******************************************************************************************
		Function:			~Business_complex()
		Description:		Free memory
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		NA
		********************************************************************************************/
		~Business_complex();
		Business_complex(int, person*);
		/*******************************************************************************************
		Function:			printinfo()
		Description:		print info stored in class
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		noen
		********************************************************************************************/
		void printinfo();
		/*******************************************************************************************
		Function:			Business_complex(const Business_complex&)
		Description:		Copy constructor
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		Makes copy
		********************************************************************************************/
		Business_complex(const Business_complex&);
		/*******************************************************************************************
		Function:			const Business_complex& operator=(const Business_complex&)
		Description:		Makes deep-copy
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		Adds functionality to assignment operator.
		********************************************************************************************/
		const Business_complex& operator=(const Business_complex&);



};
