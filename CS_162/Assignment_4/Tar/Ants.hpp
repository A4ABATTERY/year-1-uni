/*****************************************************************************************
Program/File name:	Ants.hpp
Author:				Arunav Biswas
Date				May 29, 2018
Description:		Ant childeren
Input:				NA
Output:				NA
*****************************************************************************************/
#include "./Ant.hpp"
#include <iostream>
#include <vector>

using std::vector;

class Harvest : public Ant{
	public:
	Harvest(){
		// std::cout << "Construct called Harvest" << '\n';
		cost = 2;
		produce  = 1;
		visible = 1;
		health  = 1;
	}
	virtual char Return_type() {return 'H';}

};
class Bodyguard : public Ant{
	public:
	Bodyguard(){
		cost = 4;
		visible = 1;
		attack = 1;
		attack_range = 2;
		health = 2;
	}
	virtual char Return_type() {return 'G';}

};
class Wall : public Bodyguard{
	public:
		Wall(){
			health = 4;
			attack = 0;
			visible = 1;
		}
		virtual char Return_type(){return 'W';}

};
class Thrower : public Ant{
	public:
		Thrower(){
			cost = 4;
			visible = 1;
			attack = 1;
			attack_range = 1;
			attack_range = 1;
			health = 1;
		}
		virtual char Return_type(){return 'T';}

};
class Short_Throw : public Thrower{
	public:
		Short_Throw(){
			cost = 3;
			visible = 1;
			attack = 1;
			attack_all = 0;
			attack_range = 3;
			health = 1;
		}
		virtual char Return_type(){return 'S';}
};
class Long_Throw : public Thrower{
	public:
		Long_Throw(){
			cost = 3;
			visible = 1;
			attack_range = 5;
			attack_all = 1;
			health = 1;
		}
		virtual char Return_type(){return 'L';}
};
class Ninja : public Ant{
	public:
		Ninja(){
			cost = 6;
			visible = 0;
			attack = 1;
			attack_all = 0;
			attack_range = 1;
			visible = 0;
			health = 1;
		}
		virtual char Return_type(){return 'N';}

};
class Fire : public Ant{
	public:
		Fire(){
			cost = 4;
			visible = 1;
			health = 1;
			attack_all = 1;
			attack = 0;

		}
		virtual char Return_type() {return 'F';}


};
