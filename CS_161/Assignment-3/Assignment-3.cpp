/*********************************************************************************
 * Filename		:		Assignment-3.cpp
----------------------------------------------------------------------------------
 * Author		:		Arunav Biswas
----------------------------------------------------------------------------------
 * Description	: 		16 different mini-programs.
 						The mini-programs are split into functions.
----------------------------------------------------------------------------------
 * Input		: 		Varries, strings, ints, floats
----------------------------------------------------------------------------------
 * Output 		: 		Varries, mostly boolean, sometimes int
*********************************************************************************/





#include <string>
#include <iostream>

/******************************************************************************/
/******************************************************************************/
/*					EXTRA FUNCTIONS											  */
/******************************************************************************/
int check_length(std::string str){
	int len = 0;
	while (str[len] != '\0') {
		len++;
	} return len;
}
//basically string.length() function

bool spaceIsSpace(char a){
	if (a == 32) {
		return true;
	} else{
		return false;
	}
}
//just checks if parameter is a spcae (ascii = 32 )

bool isalphabet(char a) {
	if ((('A' >= a) && (a >= 'Z')) || (('a' >= a) && (a >= 'z'))){
		return true;
	} return false;

}
//basically the isalpha() fucntion

long MyPow(int x,int n){
	int i;
	int number = 1;
	for (i = 0; i < n; i++) {
		number *= x;
	}
	return number;
}
double MyPowMins(int x, int n) {
	int i = 0;
	float number = 1.0;
	for (i = 0; i < n; i++) {
		number = number/10.0;
	} //std::cout <<"the number is "<< number << '\n';
	return number;
}
//basically pow() for negative exponents
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/********************************************FUNCTION 1 - check_range()*******/
bool check_range(int a, int b, int c) {
	//SPECIAL CASES INCLUDE:
	//Lower bound is Greater than Upper bound
	if (a>b){
		if ((a>c) && (c>b)) {
	//		std::cout << "True" << '\n';
			return true;
		}
	} else if (a<b){
		if ((b>c) && (c>a)) {
			std::cout << "You entered your bounds wrong, Lower Bound was larger than Upper bound" << '\n';
		//	std::cout << "True" << '\n';
			return true;
		}
	}else if ( (a==c) && (b==c) ){
		std::cout << "True, but this is because the program also handles for your test value being equal to one of your ranges" << '\n';
	//	std::cout << "True" << '\n';
		return true;
	} else {
		return false;
	} return false;
}
/*******************************************FUNCTION 2 - is_int()*************/
bool is_int(std::string a) {
	int numO45 = 0; //The tracks the number of '-' (acii = 45 ) in the string. //if there is more than one then the program will return false
	int numOnums = 0; //tracks the number of letters, symbols, decimals, etc.
	//std::cout << a << '\n';
	int numOuseless;
	for (int i = 0; i <= a.length(); i++) {
		if (a[i] == '-') {
	//		std::cout << "run" << '\n';
			numO45++;
		} else if ((58 > a[i]) && (a[i] > 47)) {
			numOnums++;
		}
	}

	numOuseless = a.length() - (numOnums + numO45);
	if ( (numOuseless == 0) && ((numO45 == 0) || (numO45 == 1)) ) {
	//	std::cout << numO45 << " NumO45" << '\n';
	//	std::cout << numOuseless << " numOuseless"<< '\n';
	//	std::cout << "True" << '\n';
		return true;
	} else {
	//	std::cout << numO45 << " NumO45" << '\n';
	//	std::cout << numOuseless << " numOuseless"<<'\n';
	//std::cout << "False" << '\n';
		return false;
	}

}
/**************************************FUNCTION 3 - is_float()****************/
bool is_float(std::string a) {
	int numO45 = 0; //This tracks the number of '-' (ascii = 45) in the string.
	int numO46 = 0; //This tracks the number of '.' (ascii = 46) in the string.
	int numO47 = 0; //This tracks the number of '/' (ascii = 47) in the string.
	int numOuseless = 0; //tracks the number of letters, symbols, decimals, etc.
	int numOnums = 0; //tracks how many numbers are in the string
	int wheredeci;
	for (int i = 0; i != (a.length());) { //checks for how many '-'
		if (a[i] == '-') {
		//	std::cout << "\nrun -" << '\n';
		//	std::cout << "-i =  "<< i << "\n a[i] = "<< a[i] <<'\n' << '\n'; //just debugging

			numO45 ++;
		} else if (a[i] == '.') { //checks for anything other than 0-9 and decimal points
		//	std::cout << "\nrun else" << '\n';
		//	std::cout << ".i =  "<< i << "\n a[i] = "<< a[i] <<'\n' << '\n'; //just debugging
			wheredeci = i; //records where decimal is
			numO46 ++;
		} else if (a[i] == 47) { //checks for how many decimals
		//	std::cout << "\nrun ." << '\n';
		//	std::cout << "/i =  "<< i << "\n a[i] = "<< a[i] <<'\n' << '\n'; //just debugging
			numO47 ++;

		} else if (!(57 > a[i]) && !(a[i] < 48)) {
		//	std::cout << "ai =  "<< i << "\n a[i] = "<< a[i] <<'\n' << '\n'; //just debugging
			numOuseless++;
		} else {
			numOnums ++;
		//	std::cout << "numOnums = " << numOnums << '\n';
		}
		i++;
	}
	std::string newstr0; std::string newstr1;
	if ( (numOuseless == 0) && ((numO45 == 0) || (numO45 == 1)) && (numO46 == 1) && (numO47 == 0) && (numOnums > 1) ) {
	//	std::cout << numO45 << " numO45" << '\n';
	//	std::cout << numOuseless << " numOuseless"<< '\n';
	//	std::cout << numO46 << " numO46"<<'\n';
	//	std::cout << numO47 << " numO47" << '\n';
	//	std::cout << numOnums << " numOnums" << '\n';
		newstr0 = a[wheredeci + 1];
		newstr1 = a[wheredeci -1];
		if (numOnums > 1) {
			if ((is_int(newstr0)) && (is_int(newstr1))) {
	//			std::cout << numOnums << " numOnums" << '\n';

	//		std::cout << "True" << '\n';
				return true;
			}
		}
	} else {
	//	std::cout << numO45 << " NumO45" << '\n';
	//	std::cout << numOuseless << " numOuseless"<<'\n';
	//	std::cout << numO46 << " numO46" << '\n';
	//	std::cout << numO47 << " numO47" << '\n';
	//	std::cout << "False" << '\n';
		return false;
	}

}
/**************************************FUNCTION 4 - is_capital()**************/
bool is_capital(std::string a) { /*i know that this program is supposed to
								take a char, I took a string so that i
								could error handle better.*/
	if ((91 > a[0]) && (a[0] > 64)) {
		if (check_length(a) > 1) {
			std::cout << "You entered more than one CHAR, only checked the first letter." << '\n';
			return true;
		} else {
		//std::cout << "True, you entered a Capital letter" << '\n';
		return true;
		}
	} else {
		//std::cout << "False, you entered something else" << '\n';
		return false;
	}
}
/**************************************FUNCTION 5 - is_even()*****************/
bool is_even(int a){
	int b = 0;
	b = a%2;
	if (b == 0) {
		return true;
	}else {
		return false;
	}

}
/**************************************FUNCTION 6 - is_odd()******************/
bool is_odd(int a) {
	int b = 0;
	b = a%2;
	if (b == 0) {
		return false;
	} else {
		return true;
	}

}
/**************************************FUNCTION 7 - equality_test()***********/
bool equality_test(int a, int b) {
	if (a == b) {
		return true;
	} else if (a>b) {
		std::cout << "the first number you entered is bigger" << '\n';
		return false;
	} else if (a<b) {
		std::cout << "the second number you entered is bigger" << '\n';
		return false;
	}
}
/**************************************FUNCTION 8 - float_is_equal()**********/
bool float_is_equal(float a, float b) {
	if (a == b) {
		return true;
	} else if (a>b) {
		std::cout << "the first number you entered is bigger" << '\n';
		return false;
	} else if (a<b) {
		std::cout << "the second number you entered is bigger" << '\n';
		return false;
	}
}
/**************************************FUNCTION 9 - numbers_present()*********/
bool numbers_present(std::string a) {
	std::string b;
	for (int i = 0; i  <= check_length(a); i++) {
	//	std::cout << a[i] << '\n';
		b = a[i];
		if (is_int(b)) {
			std::cout << a[i] << '\n';
			return true;
		}

	}
	return false;
}
/**************************************FUNCTION 10 - letters_present()********/
bool letters_present(std::string a){
	for (int i = 0;i  < check_length(a);i ++) { //checks each
		if (((a[i] > 64) && (a[i] < 91)) || ((a[i] > 96) && (a[i] < 123))) {
			return true;
		}

	} return false;
}
/**************************************FUNCTION 11 - contains_sub_string()****/
bool contains_sub_string(std::string a) { //basically if there is more than 1 word it returnes true. LOOK AT word_count()

	//std::cout << "" << '\n';std::cout << "You entered" << a << '\n';

	int numOwords = 0;
	if (isalpha(a[0])) {
		numOwords++;
	} for (int i = 1; i < check_length(a); i++) {
		if ((isalpha(a[i])) && (!isalpha(a[i-1]))) {
			numOwords++;
		}
	} //std::cout << numOwords << '\n';
	if ((numOwords == 1) || (numOwords == 0)) {
		return false;
	} return true;
}
/**************************************FUNCTION 12 - word_count()*************/
int word_count(std::string a) {
	int numOwords = 0;
	if (isalpha(a[0])) { //checks if user entered useless spaces
		numOwords++;
	} for (int i = 1; i < check_length(a); i++) {
		if ((isalpha(a[i])) && (!isalpha(a[i-1]))) { //checks for letters back 1 space and on space
			numOwords++;
		}
	}	//std::cout << a << " -in fucntion"<< '\n';
	return numOwords - 1;
}
/**************************************FUNCTION 13 - to_upper()***************/
std::string to_upper(std::string a) {
	std::string b;

	for (int i = 0; i != a.length(); i++) {
		if ((96 < a[i]) && (a[i] < 123)) {
			//std::cout << char (a[i] - 32) << '\n';
			b += (char ((int (a[i])) - 32)); //substracts 32 to get to proper ascii ranges
		} else {
			b += char (a[i]); //appends string

		}
	}
	return b;
}
/**************************************FUNCTION 14 - to_lower()***************/
std::string to_lower(std::string a) {
	std::string b;
	for (int i = 0; i != a.length(); i++) {
		if ((64 < a[i]) && (a[i] < 91)) {
			//std::cout << char (a[i] - 32) << '\n';
			b += (char ((int (a[i])) + 32)); //just adds 32 to get to proper ascii range
		} else {
			b += char (a[i]); //appends string

		}
	}
	return b;
}
/**************************************FUNCTION 15 -  Get_int()***************/
int Get_int(std::string a) {
	int sign = 1;
	int charOffset, c, num;
	int b = 0;
	if (!(is_int(a))) {
		do {
			std::cout << "try again, you didnt enter an integer: ";
			std::cin >> a;
		} while(!(is_int(a))); //verify if valid
	}
	if (a[0] == '-') {
		sign = -1; //records if there it a negative.
		charOffset = 1; // offset of +1 to account for '-'
	} else {
		sign = 1;
		charOffset = 0;
	}
	num = 0;
	for (int i = charOffset; a[i] != '\0'; i++) {
		num = (num * 10) + (int (a[i])) - 48;// adds number and times 10 to change place of the number.
	}
	return (num * sign);
}
/**************************************FUNCTION 16 - Get_float()**************/
double Get_float(std::string a){
	std::string beforeDeci;
	float numBdeci = 0.0; //number before
	std::string afterDeci;
	float numAdeci = 0.0;

	int deciPlace;
	int Charlen = a.length();
	int LenBdeci = 0;
	int LenAdeci = 0;
	int charOffset = 0;
	int sign = 1;

	if (!(is_float(a))) {
		do {
			std::cout << "try again, you didnt enter a float: ";
			std::cin >> a;
		} while(!(is_float(a))); //verify float
	}
	if (a[0] == '-') {
		charOffset = 1;
		sign = -1; //checks for negative
	}

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '.') {
			deciPlace = i; //checks where decimal place is
		}
	}
	if (sign == -1) { //If the float is negative.
		//std::cout << "ran minus" << '\n';
		//these for loops seperate the float into 2 integer. Before the decimal & After the decimal. ie 12.3 => 12 and 3
		for (int i = charOffset; i < deciPlace; i++) { //i is offset by one so that it accounts for '-'
			beforeDeci += a[i]; //adding char to a new string
		} numBdeci = Get_int(beforeDeci); //feeding new string to get int fucntion
	//	std::cout << numBdeci << '\n';
		for (int i = deciPlace + 1; i < Charlen; i++) { //offset by where the decimal place is, and plus one. ie, for 12.345 => a[i] = '3'
	 		afterDeci += a[i];
		} numAdeci = Get_int(afterDeci);//feeding new string to get int fucntion
	//	std::cout << numAdeci << '\n';

	} else if (sign == 1) {
		//std::cout << "ran positive" << '\n';
		//these for loops seperate the float into 2 integer. Before the decimal & After the decimal. ie 12.3 => 12 and 3
		for (int i = 0; i < deciPlace; i++) {
			beforeDeci += a[i];
		} numBdeci = Get_int(beforeDeci);//feeding new string to get int fucntion
		//std::cout << numBdeci << '\n';

		for (int i = deciPlace + 1; i < Charlen; i++) {
	 		afterDeci += a[i];
		} //std::cout << "afterDeci " << afterDeci <<'\n';
		numAdeci = Get_int(afterDeci);
		//std::cout << numAdeci << '\n';

	//	std::cout << "return 1.1" << '\n';
	}
	LenBdeci = beforeDeci.length();
	LenAdeci = check_length(afterDeci); //used as a power
	float power = MyPowMins(10,LenAdeci);
	//std::cout << "LenAdeci: "<< LenAdeci << '\n ';
	//std::cout << numAdeci << ' power = ' << power << ' ' << numBdeci << '\n';
	float strtodeci = 0.0;
	strtodeci = float (numBdeci) + (float (numAdeci) * power);
	return strtodeci * sign;



}
/******************************************************************************/
/******************************************************************************/
/*									INT MAIN BELOW							  */
/******************************************************************************/

int main() {

	int prognum = 0;//used to select program
	std::string str; //used for string input in functions that use string.
	bool TorF; //used to store TRUE and FALSE values returned from functions
	int intnum1; //used to store integer values for certain functions
	int intnum2; //Used for equality_test()
	float floatnum1, floatnum2; //used for float_is_equal

	std::cout << "Which program would you like to test?" << '\n';

	do {
		std::cout << "1 = check_range\n2 = is_int\n3 = is_float\n4 = is_capital" << '\n';
		std::cout << "5 = is_even\n6 = is_odd\n7 = equality_test\n8 = float_is_equal" << '\n';
		std::cout << "9 = numbers_present\n10 = letters_present\n11 = contains_sub_string" << '\n';
		std::cout << "12 = word_count\n13 = to_upper\n14 = to_lower\n15 = Get_int\n16 = Get_float" << '\n';
		std::cout << "\n0 = EXIT PROGRAM" << '\n';
		std::cin >> prognum;
		switch (prognum) {

			case 0:
			std::cout << "Program has been quit\n" << '\n';
			return 0;
			break;


			case 1: //running check_range()
			std::cout << "Running check_range()" << '\n';
			std::cout << "Enter an upper bound" << '\n';
			int Upper;
			std::cin >> Upper;
			std::cout << "Enter a Lower bound" << '\n';
			int Lower;
			std::cin >> Lower;
			std::cout << "Enter a test" << '\n';
			int test;
			std::cin >> test;
			TorF = check_range(Upper, Lower, test); //runs FUNCTION
			std::cout << "1 = TRUE, 0 = FALSE" << '\n';
			std::cout << '\n' << TorF << '\n' << '\n'; //prints True or false
			break;

			case 2:
			std::cout << "Running is_int()" << '\n';
			std::cout << "enter a string, and the program will check if its an integer" << '\n';
			std::cin >> str;
			TorF = is_int(str); //runs FUNCTION
			std::cout << "1 = TRUE, 0 = FALSE" << '\n';
			std::cout << '\n' << TorF << '\n' << '\n'; //prints True or false
			break;

			case 3:
			std::cout << "Running is_float()" << '\n';
			std::cout << "enter a string, and the program will check if its an float" << '\n';
			std::cin >> str;
			TorF = is_float(str); //runs FUNCTION
			std::cout << "1 = TRUE, 0 = FALSE" << '\n';
			std::cout << '\n' << TorF << '\n' << '\n'; //prints True or false
			break;

			case 4:
			std::cout << "Running is_capital()" << '\n';
			std::cout << "Enter a character" << '\n';
			std::cin >> str;
			TorF = is_capital(str);
			std::cout << "1 = TRUE, 0 = FALSE" << '\n';
			std::cout << '\n' << TorF << '\n' << '\n'; //prints True or false
			break;

			case 5:
			std::cout << "Running is_even()" << '\n';
			std::cout << "Enter an integer" << '\n';
			std::cin >> intnum1;
			TorF = is_even(intnum1);
			std::cout << "1 = TRUE, 0 = FALSE" << '\n';
			std::cout << '\n' << TorF << '\n' << '\n'; //prints True or false
			break;

			case 6:
			std::cout << "Running is_odd()" << '\n';
			std::cout << "Enter an integer" << '\n';
			std::cin >> intnum1;
			TorF = is_odd(intnum1);
			std::cout << "1 = TRUE, 0 = FALSE" << '\n';
			std::cout << '\n' << TorF << '\n' << '\n'; //prints True or false
			break;

			case 7:
			std::cout << "Running equality_test()" << '\n';
			std::cout << "Enter the first integer" << '\n';
			std::cin >> intnum1;
			std::cout << "Enter the second integer" << '\n';
			std::cin >> intnum2;
			TorF = equality_test(intnum1, intnum2);
			std::cout << "1 = TRUE, 0 = FALSE" << '\n';
			std::cout << '\n' << TorF << '\n' << '\n'; //prints True or false
			break;

			case 8:
			std::cout << "Running float_is_equal()" << '\n';
			std::cout << "Enter the first float" << '\n';
			std::cin >> floatnum1;
			std::cout << "Enter the second float" << '\n';
			std::cin >> floatnum2;
			TorF = float_is_equal(floatnum1, floatnum2);
			std::cout << "1 = TRUE, 0 = FALSE" << '\n';
			std::cout << '\n' << TorF << '\n' << '\n'; //prints True or false
			break;

			case 9:
			std::cout << "Running numbers_present()" << '\n';
			std::cout << "Enter a string" << '\n';
			std::cin >> str;
			TorF = numbers_present(str);
			std::cout << "1 = TRUE, 0 = FALSE" << '\n';
			std::cout << '\n' << TorF << '\n' << '\n'; //prints True or false
			break;

			case 10:
			std::cout << "Running letters_present()" << '\n';
			std::cout << "Enter a string" << '\n';
			std::cin >> str;
			TorF = letters_present(str);
			std::cout << "1 = TRUE, 0 = FALSE" << '\n';
			std::cout << '\n' << TorF << '\n' << '\n'; //prints True or false
			break;

			case 11:
			std::cout << "Running contains_sub_string()" << '\n';
			std::cout << "Enter a String" << '\n';
			std::cin.ignore();
			getline(std::cin,str);
			TorF = contains_sub_string(str);
			std::cout << "1 = TRUE, 0 = FALSE" << '\n';
			std::cout << '\n' << TorF << '\n' << '\n'; //prints True or false
			break;

			case 12:
			std::cout << "Running word_count()" << '\n';
			std::cout << "Enter a string" << '\n';
			std::cin.ignore();
			getline(std::cin,str);
			//std::cout << str << " - in main" <<'\n';
			intnum1 = word_count(str);
			std::cout << "\nThere are " << intnum1 + 1 << " words in the string that you entered\n" << '\n';
			break;

			case 13:
			std::cout << "Running to_upper()" << '\n';
			std::cout << "Enter a string" << '\n';
			std::cin.ignore();
			getline(std::cin,str);
			str = to_upper(str);
			std::cout << "Your new string: " << str << '\n';
			break;

			case 14:
			std::cout << "Running to_lower()" << '\n';
			std::cout << "Enter a string" << '\n';
			std::cin.ignore();
			getline(std::cin,str);
			str = to_lower(str);
			std::cout << "Your new string: " << str << '\n';
			break;

			case 15:
			std::cout << "Running Get_int()" << '\n';
			std::cout << "Enter an integer" << '\n';
			std::cin >> str;
			intnum1 = Get_int(str);
			std::cout << "Your number was: " << intnum1 << '\n';
			break;

			case 16:
			std::cout << "Running Get_float()" << '\n';
			std::cout << "Enter a float" << '\n';
			std::cin >> str;
			floatnum1 = Get_float(str);
			std::cout << "Your number was: " << floatnum1 << '\n';
			break;



		}
	} while(prognum > 0);

	return 0;
}
