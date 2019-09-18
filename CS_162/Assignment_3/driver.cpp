/******************************************************
** Program: driver.cpp
** Author: Arunav Biswas
** Date: 05/13/2018
** Description:	Driver file for Estate tycoon
** Input:		ust calls on another file/function/class
** Output:		starts game
******************************************************/
#include "Player.h"
#include <string>
#include <cstdlib>

using std::string;

int main(){
	srand(time(NULL));
	std::cout << "\n\nHello :)\n";
	std::cout << "\n\nWelcome to Estate Tycoon\n";
	std::cout << "\nYou will be able to buy and sell property\n";
	std::cout << "\nDon't go bankrupt :)\n\nGood luck!\n\n\n\n";
	int numbuildings = 3;
	House *H_Arr = new House[numbuildings];
	Apartment *A_Arr = new Apartment[numbuildings];
	Business_complex *B_Arr = new Business_complex[numbuildings];
	Player P1;
	P1.setArrays(H_Arr, A_Arr, B_Arr, 3, 3, 3);
	P1.gamestart();
	delete[]H_Arr;delete[]A_Arr;delete[]B_Arr;
}
