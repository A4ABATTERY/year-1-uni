/*****************************************************************************************
Program/File name:	Ant.hpp
Author:				Arunav Biswas
Date				May 29, 2018
Description:		Ant partent class
Input:				NA
Output:				NA
*****************************************************************************************/
#include "./Bug.hpp"
#include <iostream>
#include <vector>

using std::vector;

class Ant : public Bug{
	protected:
		int cost;
		int produce;
	public:

		Ant(){
			// std::cout << "Construct Ant" << '\n';
			cost = 0;
			produce  = 0;
		}
		virtual char Return_type() {return 'a';}

		int getcost() {return cost;}
		int getproduce(){return produce;}
};
