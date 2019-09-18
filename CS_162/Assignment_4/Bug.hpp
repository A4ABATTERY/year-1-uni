/*****************************************************************************************
Program/File name:	Bug.hpp
Author:				Arunav Biswas
Date				May 29, 2018
Description:		Bug partent class
Input:				NA
Output:				NA
*****************************************************************************************/

// #pragma once
#ifndef BUG_HPP
#define BUG_HPP
#include <iostream>
#include <vector>

using std::vector;

class Bug{
	protected:
		int health;
		bool attack;
		int attack_range;
		bool attack_all;
		bool visible;
		char type;
	public:

		Bug(){
			// std::cout << "Construct Bug" << '\n';
			health = 1;
			attack = 0;
			attack_range = 0;
			attack_all = 0;
			visible = 0;
		}

		/*********************************************************************
		** Function:		Return_type()
		** Description:		returns char
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		virtual char Return_type() {return 'z';}
		/*********************************************************************
		** Function:		Attacked()
		** Description:		substract one from health
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void Attacked() {if(visible) health--;}
		/*********************************************************************
		** Function:		Return_type()
		** Description:		substract given in integer
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	substracted health
		*********************************************************************/
		void Attacked(int M) {if(visible) health = health - M;}
		/*********************************************************************
		** Function:		gethealth()
		** Description:		returns health integer
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		int gethealth() {return health;}
		/*********************************************************************
		** Function:		Isvisible
		** Description:		returns if bug is visible or not
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		bool Isvisible() {return visible;}




};
#endif // BUG_HPP
