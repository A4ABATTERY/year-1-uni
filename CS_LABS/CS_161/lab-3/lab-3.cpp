/* lab 3, password creator */



#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

char addChar(int chartype, int adder, int random = rand()) {
	char x = ((random%chartype) + adder);
	return x;
}

int main() {
int Passlen, numOupper, numOlower, numOnums;
int letter = 25;
int numbers = 9;
int upperCASE = 65;
int lOWERCASE = 97;
int numberadder = 48;
int x = 1;
std::string GndPass = "";
char YorN;
std::cout << "would you like to make a password y/n: " << '\n';
std::cin >> YorN; //yes or no
while ((YorN == 121) || (YorN == 89)) {

		std::cout << "How many characters would you like your password to have?" << '\n';
		std::cin >> Passlen;
		std::cout << "\nHow many upper case letters would you like in your password?" << '\n';
		std::cin >> numOupper;
		std::cout << "\nHow many lower case letters would you like in your password?" << '\n';
		std::cin >> numOlower;
		std::cout << "How many numbers would you like in your password?" << '\n';
		std::cin >> numOnums;

		if (Passlen == (numOnums + numOlower + numOupper)) {
			GndPass = "";
			for (int i = 0; i < numOlower; i++) {
				GndPass += addChar(letter, lOWERCASE);
			}
			for (int i = 0; i < numOnums; i++) {

				GndPass += addChar(numbers, numberadder);
			}
			for (int i = 0; i < numOupper; i++) {

				GndPass += addChar(letter, upperCASE);
			}
			std::cout << "\nYour password is: " << GndPass << '\n';
			return 0;
		} else {
			std::cout << "You entered weird numbers that dont match up" << '\n';
			return 0;
		}

	}
return 0;
}
