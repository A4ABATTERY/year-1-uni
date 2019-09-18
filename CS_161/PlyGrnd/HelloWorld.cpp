#include <iostream>


// Part 1
/*int main() {
  std::cout << "Hello World!" << std::endl;

  return 0;
}*/

// Part 2

int main() {
	int num;

	std::cout << "Hello World" << std::endl; //part 1

	std::cout << "Enter an whole number: "; std::cin >> num;   //ask and take input

	std::cout << "Your number was " << num << "." << std::endl; //print input to console

	return 0;

}


/****************************************************************************************
 * Answers to questions
 * 1)
 * A compile error. The Semi-Colon is the identifier for the 'end of a line/command'.
 * The compiler will continue reading, and it won't be able to make sense of two lines
 * put together. (Its kind of like a run on sentence when you leave it out.)
 *
 * 2)
 * The compiler cannot find the commands ('cout', 'cin', etc) being used. 'Iostream' is
 * supposedly (im taking a guess, havent read through the documentation) for taking
 * in inputs and putting out outputs. Hence I(nput)-O(utput)-stream.
 *
 * 3)
 * The command isnt declared? The error feedback in C is confusing. As a newbie to C,
 * it has to do something with declerations, and that the library of the command
 * needs to be called on first (iostream), then that same command needs to be called
 * upon by the standard (std) library. Thats just how C works i guess.
 *
 * 4)
 * The first program only gives out a pre-determined output, the second one gives
 * the output of the first as well as a user-determined output. (second one takes
 * and input and output)
 *
 * 5)
 * Another compile error. I guess the direction of the arrows is supposed to show
 * wheather or not the program is supposed to look to the user or its own code to
 * know what to do next.
 *
 * 6)
 * The variable (num, in my case) is a placeholder for any values. You can't
 * have values just floating about in your program.
 *
 *
 * *************************************************************************************/
