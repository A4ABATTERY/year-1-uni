/*****************************************************************************************
Program/File name:	Bee.hpp
Author:				Arunav Biswas
Date				May 29, 2018
Description:		BBee class
Input:				NA
Output:				NA
*****************************************************************************************/

#include "./Bug.hpp"

class Bee : public Bug{
	public:
		Bee(){
			health = 1;
			attack = 1;
			attack_range = 1;
			attack_all = 0;
			visible = 1;
		}
		virtual char Return_type() {return 'B';}
};
