/*********************************************************************************
 * Filename		:		Assignment-2.cpp
----------------------------------------------------------------------------------
 * Author		:		Arunav Biswas
----------------------------------------------------------------------------------
 * Description	: 		A story, with 5 choices.
----------------------------------------------------------------------------------
 * Input		: 		1 or 2, user picks between two choices. Or enter a number
 						The user can make 5 different choices to make in total
----------------------------------------------------------------------------------
 * Output 		: 		A story about going to Mcdonalds with a random variable
 						in it
*********************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>

int main () {
	int randnum;
	srand(time(NULL));
	randnum = rand()%2; //random number one or zero used as two options.
	//std::cout << "\nThe number is: " << randnum << '\n';

	int looper = 1; //this var helps with handle errors, It is used to check the validity of the loop.
	char choice1, choice2;
	int choice3;

	while (looper == 1) {
		/*ask for first choice*/
		std::cout << "\n\nSo, this story is about you (the player) going to Mcdonalds.\n";
		std::cout << "Sadly the menu only has McGriddles and McPick2s :( \n";3
		std::cout << "Enter 1 for McGriddles\nEnter 2 for McPick2s.\n";
		std::cin >> choice1;
		if (choice1 == 49) { //McGriddles
			looper = 2; //Looper validity changed to 2
			//std::cout << "Layer 1_1" << '\n';
			std::cout << "\nAt this point, you as the player are very hungry" << '\n';
			std::cout << "So you feel the only logical thing to do one of two things" << '\n';
			std::cout << "How many would you like?" << '\n';
			while (looper == 2) {//Mcgriddle layer || this loop uses 'looper' = 2 as a condition
				//asks for second choice
				while (!(std::cin>>choice3)){
					std::cin.clear();
					std::cin.ignore();
					std::cout << "\nSo you either entered a REALLY crazy amount of Mcgriddles" << '\n';
					std::cout << "OR" << '\n';
					std::cout << "You just wanted to mess with the program :') " << '\n';
				}
					std::cout << "\nYou picked to eat "<< choice3 << " McGriddles" << '\n';
					looper = 0;
					//Used random num (0 or a 1) to determine fate
					if (randnum == 1) { //you get the food
						std::cout << "You got your food\nYou are happy and content now " << '\n';
					} else { //you dont get the food
						std::cout << "They didnt have McGriddles... and they ran out of McPick2s as well" << '\n';
						std::cout << "Better luck next time" << '\n';
					}
			}
		} else if (choice1 == 50) { //McPick2s
			looper = 2;
			std::cout << "At this point, you as the player are very hungry" << '\n';
			std::cout << "However the cashier gives you only two options " << '\n';
			std::cout << "Enter 1 for Pancakes and a McChicken" << '\n';
			std::cout << "Enter 2 for a Breakfast Burrito and a Saussage McMuffin" << '\n';
			while (looper == 2) {//McPick2s || this loop uses 'looper' = 2 as a condition
				//asks for second choice
				std::cin >> choice2;
				if (choice2 == 49) { //entered 1
					std::cout << "You opted to get Pancakes and a McChicken" << '\n';
					looper = 0;
					if (randnum == 1) {
						std::cout << "You got your food\nYou are happy and content now :)" << '\n';
					} else {
						std::cout << "You dropped your McChicken while you were eating it :( " << '\n';
						std::cout << "At least you got Pancakes  ¯\\_(ツ)_/¯" << '\n';
					}
				} else if (choice2 == 50) { //entered 2
					std::cout << "You opted to get the Breakfast Burrito and a Saussage McMuffin" << '\n';
					looper = 0;
					if (randnum == 1) {
						std::cout << "You got your food\nYou are happy and content now :)" << '\n';
					} else {
						std::cout << "They ran out of Breakfast Burritos :( But thankfully, they gave you Pancakes instead :) " << '\n';
					}
				} else {
					looper = 2; //restarts loop because the user entered something weird
					std::cout << "You entered something werid :(, try again (loop 2_2)" << '\n';
				}
			}
		} else {
			std::cout << "You entered something weird :(, try again. (loop 1)" << '\n';
			looper = 1; //resarts loop because the user entered something weird.
		}

	}
return 0;
}
