/******************************************************
** Program: Player.h / Player.cpp
** Author: Arunav Biswas
** Date: 05/13/2018
** Description:	Holds player class
** Input:		Uses Chars to operate
** Output:		plays game
******************************************************/
#pragma once
#include "house.h"
#include "business.h"
#include "apartment.h"

class Player{
	private:
		int bank;
		int numH;
		House* H_Arr;
		int numA;
		Apartment* A_Arr;
		int numB;
		Business_complex* B_Arr;
		int numHowned;
		House* H_O_Arr;
		int numAowned;
		Apartment* A_O_Arr;
		int numBowned;
		Business_complex* B_O_Arr;
		int subsPerMonth;
	public:

		/*******************************************************************************************
		Function:			Player()
		Description:		Initialzes player arrays with NULL and or values passed to it
		parameters:			Arrays and sizes passed to it or NOTHING at all
		Pre-condition:		un-initialized
		Post-condition:		initialized
		********************************************************************************************/
		Player();
		Player(int, House*, Apartment*, Business_complex*, House*, Apartment*, Business_complex*, int, int, int, int, int, int);
		void gamestart();
		/*******************************************************************************************
		Function:			~player()
		Description:		Free memory
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		VOID
		********************************************************************************************/
		~Player();
		/*******************************************************************************************
		Function:			bankrupt()
		Description:		checks if user bank is 0 or below
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		returns true or false
		********************************************************************************************/
		bool bankrupt();
		/*******************************************************************************************
		Function:			setArrays()
		Description:		Sets arrays
		parameters:			Passes arrays and their sizes
		Pre-condition:		initialized arrays, and correct sizes
		Post-condition:		VOID, just sets arrays in player class
		********************************************************************************************/
		void setArrays(House*, Apartment*, Business_complex*, int, int, int);
		/*******************************************************************************************
		Function:			getbuildingtype()
		Description:		Gets valid building type string
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		returns either "Business", "House", or "Apartment"
		********************************************************************************************/
		std::string getbuildingtype();
		/*******************************************************************************************
		Function:			getchoice()
		Description:		Gets a value between an upper and lower bound
		parameters:			int lowerbound, int upperbound
		Pre-condition:		Bounds must be passed to it
		Post-condition:		returnes integer between the bounds
		********************************************************************************************/
		int getchoice(int, int);
		/*******************************************************************************************
		Function:			printoptions()
		Description:		Just prints UI
		parameters:			NA
		Pre-condition:		none
		Post-condition:		VOID
		********************************************************************************************/
		void printoptions();
		/*******************************************************************************************
		Function:			viewProperties()
		Description:
		parameters:			House, Apartment or Business_complex arrays, and an index to tell the function what to remove;
		Pre-condition:		Just removes index value from array
		Post-condition:		VOID
		********************************************************************************************/
		/*******************************************************************************************
		Function:			viewProperties()
		Description:		Just prints properties on market
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		VOID
		********************************************************************************************/
		void viewProperties();
		/*******************************************************************************************
		Function:			viewOwned()
		Description:		Just prints properties that are owned
		parameters:			NA
		Pre-condition:		NA
		Post-condition:		VOID
		********************************************************************************************/
		void viewOwned();
		/*******************************************************************************************
		Function:			Buyproperty()
		Description:		Allows user to buy property
		parameters:			none
		Pre-condition:		House, Apartment, and Business_complex Arrays must be populated
		Post-condition:		VOID
		********************************************************************************************/
		void Buyproperty();
		/*******************************************************************************************
		Function:			removefmrMarket()
		Description:		Supposed to remove property from market
		parameters:			House, Apartment or Business_complex arrays, and an index to tell the function what to remove;
		Pre-condition:		Just removes index value from array
		Post-condition:		VOID
		********************************************************************************************/
		void removefmrMarket(House*, int);
		void removefmrMarket(Apartment*, int);
		void removefmrMarket(Business_complex*, int);
		/*******************************************************************************************
		Function:			ResizeArrayADD()
		Description:		Adds 1 to array size of owned properties
		parameters:			Array, and index of what to add
		Pre-condition:		valid array, and index
		Post-condition:		Adds property to owned properties
		********************************************************************************************/
		void ResizeArrayADD(House*, int);
		void ResizeArrayADD(Apartment*, int);
		void ResizeArrayADD(Business_complex*, int);
		/*******************************************************************************************
		Function:			counter()
		Description:		Counts number of turns passed
		parameters:			none
		Pre-condition:		none
		Post-condition:		adds one to static int count
		********************************************************************************************/
		void counter();


};
