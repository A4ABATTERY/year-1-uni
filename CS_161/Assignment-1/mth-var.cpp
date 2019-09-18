/***************************************************************************************************
 * Filename:	 mth-var.cpp
 *
 * author: 	Arunav Sen Biswas
 *
 * Date: 	Jan 10th, 2018
 *
 * Description: CS 161, Assignment 1, Learn how to use cmath, use variables, and print to screen
 *
 * input:	None, program runs by itself
 *
 * output:	Print statements showing answers to math problemens.
 ***************************************************************************************************/

//Program Start
#include <cmath> //Brought in the cmath library to solve math.
#include <iostream> //Using Iostream to print things to screen.
#define pi 3.1415
using namespace std; //Using the standard namespace, makes writing the code easier.

int main()
{
	
	//all the problems are going to have some sort of a decimal componenet. Hence, i used Float as my data type

	double prob1, prob_2, prob2, prob3, prob4, prob5, arb1;

	//just an arbitrary number 2/3
	arb1 = 0.6666666;
	
	//all the calculations
	prob1 = cos(arb1);
	prob_2 = sin(arb1);
	 /*C++ was being weird, hence the variable arb1 and the weird calculation for problem 2. It said
 	   sin(2/3)*2 = 1, and  cos(2/3) = 1... so i just started trying other ways of doing those same problems */
	prob2 = prob_2 * 2;
	prob3 = tan(-0.75);
	prob4 = log10(55);
	prob5 = log(60);

	//printing all statements.	
	cout << "\nProblem 1\nCosine of two over three\ncos(2/3) = "<< prob1 << endl;

	cout << "Problem 2\nTwo times the sine of two over three\n2sin(2/3) = " << prob2 << endl;

	cout << "Problem 3\nTangent of negative three over four\ntan(-3/4) = " << prob3 << endl;

	cout << "Problem 3\nLog of 55\nlog(55) = " << prob4 << endl;

	cout << "Problem 5\nNatural log of 60\nln(60) = " << prob5 << endl;
	 
	return 0;

}
