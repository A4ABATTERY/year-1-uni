/*********************************************************************************
 * Filename		:		Assignment-4.cpp
----------------------------------------------------------------------------------
 * Author		:		Arunav Biswas
----------------------------------------------------------------------------------
 * Description	: 		4 different calculators.
 						Grade calculator (Averages grades, then weights average)
						Binary to decimal (takes binary string and converts it
						to decimal)
						Decimal to binary (takes decimal string and converts it
						to binary)
						simple calculator (takes a string expresion, which is a
						2 number operation, and gives the answer as a float/int)
----------------------------------------------------------------------------------
 * Input		: 		string
----------------------------------------------------------------------------------
 * Output 		: 		Outputs float/int for everything except for Decimal to binary
 						decimal to binary outputs string.
*********************************************************************************/
#include <iostream>
#include <string>



int check_length(std::string str){
	int len = 0;
	while (str[len] != '\0') {
		len++;
	} return len;
}
bool spaceIsSpace(char a){
	if (a == 32) {
		return true;
	} else{
		return false;
	}
}
bool isalphabet(char a) {
	if ((('A' >= a) && (a >= 'Z')) || (('a' >= a) && (a >= 'z'))){
		return true;
	} return false;

}
bool is_number(const std::string a){
    std::string::const_iterator it = a.begin();
    while (it != a.end() && std::isdigit(*it)) ++it;
    return !a.empty() && it == a.end();
}
bool is_posi_int(std::string a) {
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
	if ( (numOuseless == 0) && (numO45 == 0) ) {
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
long MyPow(int x,int n){
	int i;
	float number = 1.0;
	if (n == 0) {return 1;}
	for (i = 0; i < n; i++) {
		number *= (float (x));
	}
	return number;
}
double MyPowMins(int x, int n) {
	int i = 0;
	float number = 1.0;
	if (n == 0) {return 1;}

	for (i = 0; i < n; i++) {
		number *= x;
	} //std::cout <<"the number is "<< number << '\n';
	return (float (1/number));
}
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
bool is_float(std::string a) {
	int numO45 = 0; //This tracks the number of '-' (ascii = 45) in the string.
	int numO46 = 0; //This tracks the number of '.' (ascii = 46) in the string.
	int numO47 = 0; //This tracks the number of '/' (ascii = 47) in the string.
	int numOuseless = 0; //tracks the number of letters, symbols, decimals, etc.
	int numOnums = 0; //tracks how many numbers are in the string
	int wheredeci;
	for (int i = 0; i != (a.length());) { //checks for how many '-'
		if (a[i] == '-') {
			numO45 ++;
		} else if (a[i] == '.') {
			wheredeci = i;
			numO46 ++;
		} else if (a[i] == 47) {
			numO47 ++;

		} else if (!(57 > a[i]) && !(a[i] < 48)) {
			numOuseless++;
		} else {
			numOnums ++;
		}
		i++;
	}
	std::string newstr0; std::string newstr1;
	if ( (numOuseless == 0) && ((numO45 == 0) || (numO45 == 1)) && (numO46 == 1) && (numO47 == 0) && (numOnums > 1) ) {
		newstr0 = a[wheredeci + 1];
		newstr1 = a[wheredeci -1];
		if (numOnums > 1) {
			if ((is_int(newstr0)) && (is_int(newstr1))) {

				return true;
			}
		}
	} else {
		return false;
	}
}
bool is_capital(std::string a) {
	if ((91 > a[0]) && (a[0] > 64)) {
		if (check_length(a) > 1) {
			std::cout << "You entered more than one CHAR, only checked the first letter." << '\n';
			return true;
		} else {
		return true;
		}
	} else {
		return false;
	}
}
bool is_even(int a){
	int b = 0;
	b = a%2;
	if (b == 0) {
		return true;
	}else {
		return false;
	}

}
bool is_odd(int a) {
	int b = 0;
	b = a%2;
	if (b == 0) {
		return false;
	} else {
		return true;
	}

}
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
bool numbers_present(std::string a) {
	std::string b;
	for (int i = 0; i  <= check_length(a); i++) {
		b = a[i];
		if (is_int(b)) {
			std::cout << a[i] << '\n';
			return true;
		}

	}
	return false;
}
bool letters_present(std::string a){
	for (int i = 0;i  < check_length(a);i ++) { //checks each
		if (((a[i] > 64) && (a[i] < 91)) || ((a[i] > 96) && (a[i] < 123))) {
			return true;
		}

	} return false;
}
bool contains_sub_string(std::string a) {
	int numOwords = 0;
	if (isalpha(a[0])) {
		numOwords++;
	} for (int i = 1; i < check_length(a); i++) {
		if ((isalpha(a[i])) && (!isalpha(a[i-1]))) {
			numOwords++;
		}
	}
	if ((numOwords == 1) || (numOwords == 0)) {
		return false;
	} return true;
}
int word_count(std::string a) {
	int i;
	int numOwords = 1;
	for (i = 1; i < a.length(); i++){
		if ((a[i] == ' ') && (a[i - 1] != ' ')){
			numOwords++;
		}
	}
	return numOwords;
}
std::string to_upper(std::string a) {
	std::string b;
	for (int i = 0; i != a.length(); i++) {
		if ((96 < a[i]) && (a[i] < 123)) {
			b += (char ((int (a[i])) - 32));
		} else {
			b += char (a[i]);
		}
	}
	return b;
}
std::string to_lower(std::string a) {
	std::string b;
	for (int i = 0; i != a.length(); i++) {
		if ((64 < a[i]) && (a[i] < 91)) {
			b += (char ((int (a[i])) + 32));
		} else {
			b += char (a[i]);

		}
	}
	return b;
}
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
		num = num * 10 + a[i] - '0';// adds number and times 10 to change place of the number.
	}
	return (num * sign);
}
double Get_float(std::string a){
	std::string beforeDeci;
	float numBdeci = 0.0;
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
	if (sign == -1) {
		for (int i = charOffset; i < deciPlace; i++) {
			beforeDeci += a[i];
		} numBdeci = Get_int(beforeDeci);
		for (int i = deciPlace + 1; i < Charlen; i++) {
	 		afterDeci += a[i];
		} numAdeci = Get_int(afterDeci);
	} else if (sign == 1) {
		for (int i = 0; i < deciPlace; i++) {
			beforeDeci += a[i];
		} numBdeci = Get_int(beforeDeci);
		for (int i = deciPlace + 1; i < Charlen; i++) {
	 		afterDeci += a[i];
		}
		numAdeci = Get_int(afterDeci);
	}
	LenBdeci = beforeDeci.length();
	LenAdeci = check_length(afterDeci);
	float power = MyPowMins(10,LenAdeci);
	float strtodeci = 0.0;
	strtodeci = float (numBdeci) + (float (numAdeci) * power);
	return strtodeci * sign;
}
float get_number_posi(std::string a){
	bool isValid = 0;
	do {
		if ((is_int(a)) == 1){
			std::cout << "Running if (in get number)" << '\n';

			if (Get_int(a) > -1) {
				return Get_int(a);
			}else {
				std::cout << "Please try again, You entered invalid input" << '\n';
				isValid = 1;
				a = "1";
				std::cin >> a;
			}
		}else if ((is_float(a)) == 1 ){
			std::cout << "Running else if (in get number)" << '\n';

			if (Get_float(a) > -1) {
				return Get_float(a);
			} else {
				std::cout << "Please try again, You entered invalid input" << '\n';
				isValid = 1;
				a = "";
				std::cin >> a;
			}
		} else {
			std::cout << "Running else (in get number)" << '\n';
			std::cout << "the string is: " << a<< '\n';
			a += 'a';
			std::cout << "the sting is:" << a <<'\n';
			std::cout << "Please try again, You entered invalid input" << '\n';
			isValid = 1;
			a = "";
			std::cin >> a;
		}
	} while(isValid);
}
float get_number(std::string a){
	bool isValid = 0;
	do {
		if ((is_int(a)) == 1){
				return Get_int(a);

		}else if ((is_float(a)) == 1 ){
			return Get_float(a);

		} else {
			std::cout << "Please try again, You entered invalid input" << '\n';
			isValid = 1;
			a = "";
			std::cin >> a;
		}
	} while(isValid);
}
bool is_bool(){
	std::cout << "Enter 1 or 0\n1 = Yes  ||  0 = No" << '\n';
	std::string mybool_STR = "";
	bool isValid = 0;
	int mybool = 0;
	do {
		std::cin >> mybool_STR;
		if (is_int(mybool_STR)){
			mybool = Get_int(mybool_STR);
			if (mybool == 0){
				isValid = 0;
				return 0;
			} else if (mybool == 1){
				isValid = 0;
				return 1;
			}else{
				std::cout << "You didn't enter a valid value." << '\n';
				std::cout << "Please enter 1 or 0\n1 = Yes  ||  0 = No" << '\n';
				isValid = 1;
			}
		} else {
			isValid = 1;
			std::cout << "You didn't enter a valid value." << '\n';
			std::cout << "Please enter 1 or 0\n1 = Yes  ||  0 = No" << '\n';
			mybool_STR = "";
		}
	} while(isValid);
}

/*^^^^^^^^*ADDITIONAL FUNCTIONS & FUCNTIONS FROM ASSIGNMENT 3*^^^^^^*/
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*vvvvvvvvv*ASSIGNMENT 4 FUCNTIONS AND INT MAIN BELOW*vvvvvvvvvvvvvv*/




/*********************************************************************************
 * Filename		:		Assignment-4.cpp
----------------------------------------------------------------------------------
 * Author		:		Arunav Biswas
----------------------------------------------------------------------------------
 * Description	: 		4 different calculators.
 						Grade calculator (Averages grades, then weights average)
						Binary to decimal (takes binary string and converts it
						to decimal)
						Decimal to binary (takes decimal string and converts it
						to binary)
						simple calculator (takes a string expresion, which is a
						2 number operation, and gives the answer as a float/int)
----------------------------------------------------------------------------------
 * Input		: 		string
----------------------------------------------------------------------------------
 * Output 		: 		Outputs float/int for everything except for Decimal to binary
 						decimal to binary outputs string.
*********************************************************************************/


/*********************************************************************
** Function: 		weight_the_average()
** Description:		Takes the average grade given by average_grade
					and apply a weight supplied by the user
** Parameters: 		Takes in a float, average_grade
** Pre-Condition:	average_grade is a number (float or int)
** Post Condition: 	final weighted average_grade is given.
*********************************************************************/
float weight_the_average(float average_grade){
	bool isValid = 0;
	float theWeight = 0.0;
	std::string theWeight_STR = "";
	std::cout << "Please enter the weight as a percent i.e. 87\% => 87.0 ENTER AS A FLOAT" << '\n';
	std::cout << "What weight would you like to apply: ";
	do {
		theWeight_STR = "";
		std::cin >> theWeight_STR;
		float theWeight = ((Get_float(theWeight_STR)));
	//	std::cout << "theWeight: " << theWeight <<'\n';
		if ((100 >= theWeight) || (theWeight <= 0)) {
			isValid = 0;
	//		std::cout << "theWeight: " << theWeight <<'\n';
			return ( ((float (average_grade)) * theWeight) / 100.0 );
		}else {
			std::cout << "Your weight was greater than 100 percent, less than zero, or zero itself. Please try again" << '\n';
			isValid = 1;
		}
	} while (isValid);
}
/*********************************************************************
** Fucntion: 		average_grade
** Description: 	averages the sum of grades by the numer of grades.
					passes on to another fucntion (weight_the_average) if
					average needs to be weighted.
** Parameters: 		float grades (sum of grades)
					int numOgrades (number of grades)
					bool weighted (= 1 if weighed, = 0 if not weighted)
** Pre-Condition:	Grades is a float, number of grades in an integer
					weather to weight the grade or not is a Boolean.
** Post-Condition:	returns a float average_grade
*********************************************************************/
float average_the_grades(float grades, int numOgrades, bool weighted) {
	float average_grade = grades/numOgrades;
	if (weighted){
		return weight_the_average(average_grade);
	}
	return average_grade;
}
/*********************************************************************
** Fucntion: 		get_grade()
** Description:		Takes in grades and creates a summation of all
					of them.
** Parameters:		int numOgrades (the number of grades)
					bool wegithed (=1 if weighted, =0 if not weighted)
** Pre-Condition:	numOgrades is a valid integer. weighted is a valid
					boolean.
** Post-Condition:	returns a float summation of all the values that
					the user entered.
*********************************************************************/
float get_grade(int numOgrades, bool weighted) {
	std::string grade_STR;
	float grade = 0.0;
	for (int i = 0; i < numOgrades; i++){
		std::cout << "Enter grade " << i + 1 << ": ";
		grade_STR = "";
		std::cin >> grade_STR;
		grade += get_number_posi(grade_STR);
		std::cout << '\n';
	}
	//std::cout  << "grade: " << grade << '\n';
	return average_the_grades(grade, numOgrades, weighted);
}
/*********************************************************************
** Fucntion:		grade_calc()
** Description:		Takes in the number of grades. Takes in whether
					the grades need to be weighted or not.
** Parameters:		none
** Pre-Condition:	none, the program just has to chosen to run (in
					int main() )
** Post-Condition: 	passes on number of grades to be entered, and if
					they are weighted at the end.
*********************************************************************/
float grade_calc() {
	std::cout << "How many grades would you like: ";
	std::string numOgrades_STR;
	std::cin >> numOgrades_STR;
	int numOgrades = get_number_posi(numOgrades_STR);
	std::cout << "would you like to weight the average grade? " << '\n';
	bool weighted = is_bool();
	return get_grade(numOgrades, weighted);
}
/********************************************************************/
/********************************************************************/
/********************************************************************/
/*********************************************************************
** Fucntion:		convert_to_Dec()
** Description:		converts a binary string to a decimal.
** Parameters:		string a (this string is the binary number
					in string form)
** Pre-Condition:	Needs to be passed a string of 1s and 0s with
					absolutely nothing else.
** Post-Condition: 	Returns decimal value according to the binary
					provided
*********************************************************************/
int convert_to_Dec(std::string a) {
 	int num = 0;
	if (a.length() >= 32) {std::cout << "OVERFLOW, RETURN -1" << '\n'; return -1;}
	for (int i = a.length() - 1; i >= 0; i--) {
		num += MyPow(2,i) * ( (int (a[i])) - 48 );
	}
	return num;
}
/*********************************************************************
** Fucntion:		binValid()
** Description:		Checks if string provided by user is valid
** Parameters:		string a (This is a the binary number in string
					form). It will be checked
** Pre-Condition:	Passed a string
** Post-Condition: 	Returns true if the string only continas 1s and 0s
					returns false if the string contains anything else
*********************************************************************/
bool binValid(std::string a){
	int i = 0;
	int b = 0;
	for (; i < a.length(); i++) {
		if ( (a[i] == 48) || (a[i] == 49) )
		 {b += 1;}
	}
	if (b == (a.length())) {
		return true;
	}
	else{
		return false;
	}
}
/*********************************************************************
** Fucntion:		get_bin()
** Description:		Takses string input from user, and then calls on
					another function to convert the string to a
					decimal. then returns decimal value.
** Parameters:		bool isValid = 0 (just used for error handling)
					string a (stores the binary string)
** Pre-Condition:	conditions supplied by binValid() funciton.
** Post-Condition: 	Returns decimal value provided by another funciton
*********************************************************************/
int get_bin(bool isValid = 0,std::string a = ""){
	std::cout << "Enter the binary that you'd like to convert: ";
	std::cin.ignore();
	getline(std::cin, a);
	do {
		if (binValid(a)) {
			isValid = 0;
		} else {
			a = "";
			std::cout << "You entered an invalid Binary number." << '\n';
			std::cout << "Please try again." << '\n';
			getline(std::cin,a);
			isValid = 1;
		}
	} while(isValid);
	return convert_to_Dec(a);
}
/********************************************************************/
/********************************************************************/
/********************************************************************/
/*********************************************************************
** Fucntion:		revers_str()
** Description:		reverses a string. i.e. "reverse" => "esrever"
** Parameters:		std::string a (the string that is passed)
					std::string b = "", empty. Just use as a
					declatation.
** Pre-Condition:	supplied a string
** Post-Condition: 	returns the string in reverse order.
*********************************************************************/
std::string revers_str(std::string a, std::string b = ""){
	for (int i = a.length() -1;i >= 0;i--){
		b += char (a[i]);
	}return b;
}
/*********************************************************************
** Fucntion:		convert_to_Bin()
** Description:		converts an integer to a binary string
** Parameters:		int a, an integer that is passed.
					std::string b = "", empty. Just use as a
					declatation.
** Pre-Condition:	supplied a positive integer.
** Post-Condition: 	returns a string of 1s and 0s, it has to be reversed
					to equal to the decimal value that the user entered
*********************************************************************/
std::string convert_to_Bin(int a, std::string b = ""){
	do {
		if (is_even(a)){
			a /= 2;
			b += '0';
		} else if (is_odd(a)){
			a -= 1; a /= 2;
			b += '1';
		}
	} while(a > 0);
	return revers_str(b);
}
/*********************************************************************
** Fucntion:		get_dec()
** Description:		gets a valid decimal value. get a positive integer
** Parameters:		bool isValid = 0, just used as a decleration
					std::string a, just used as a declatation.
** Pre-Condition:	supplied a positive integer.
** Post-Condition: 	returns a string of 1s and 0s, it has to be reversed
					to equal to the decimal value that the user entered
*********************************************************************/
std::string get_dec(bool isValid = 0, std::string a = ""){
	std::cout << "Enter a positive integer that you'd like to convert: ";
	std::cin.ignore();
	getline(std::cin, a);
	do {
		if ((is_int(a)) && (is_posi_int(a)) && ((Get_int(a)) >= 0)){
			isValid = 0;
		}else {
			a = "";
			std::cout << "You didnt enter a positive integer." << '\n';
			std::cout << "Please try again." << std::endl;
			getline(std::cin,a);
			isValid = 1;
		}
	} while(isValid);
 return convert_to_Bin(Get_int(a));
}
/********************************************************************/
/********************************************************************/
/********************************************************************/
/*********************************************************************
** Fucntion:		RemoveSpacesSTR()
** Description:		Due to my implementation of the simple calc. I have
					to deal with an 'off by one' error. There is a space
					at the end of the of the string that is passed on.
					i.e.  "234 "  => "234"
** Parameters:		string a (Just any string)
					string b (is just an empty string that gets added
					on to)
** Pre-Condition:	Needs to be passed a string
** Post-Condition: 	Returns a string without the last character
*********************************************************************/
std::string RemoveSpacesSTR(std::string a, std::string b = ""){
	for (int i = 0; i < a.length() - 1; i++) {
		b += a[i];
	}
   return b;
}
/*********************************************************************
** Fucntion:		fin_calc()
** Description:		Finaly calulation step, just simple swith statements.
					They return a value based on the 'int operation'
					parameter
** Parameters:		float a, and float b are values that are operated on
					int operation is the ASCII value for the operations
					'+', '-', '*', or '/'. There is also a special case 254.
					The special case is an ERROR case, it menas that there
					was an invalid operator.
					string b (is just an empty string that gets added
					on to)
** Pre-Condition:	needs to be passed valid floats (a, b)
** Post-Condition: 	Returns sum
					returns difference
					returns multiplication
					return division
					returns ERROR 254, -1.
*********************************************************************/
float fin_calc(float a, float b, int operation){
	switch (operation) {
		case 43:
		return float(a) + float(b);
		break;
		case 45:
		return float(a) - float(b);
		break;
		case 42:
		return float(a) * float(b);
		break;
		case 47:
		return float(a) / float(b);
		break;
		case 254:
		std::cout << "ERROR 254. You probably entered a weird operator.\n return -1" << '\n';
		return -1;
		break;
	}
}
/*********************************************************************
** Fucntion:		extractOpp()
** Description:		Extracts the Operator from string.
					i.e. '1 + 2'  =>  '+'
** Parameters:		string a (a valid string expression)
					int space1 (the space before the operator
					i.e. 1_+ 2)
					int space2 (the space after the opertor
					i.e. 1 +_2)
** Pre-Condition:	Needs to be passed a string, needs valid integers
** Post-Condition: 	Returns the Ascii decimal value of the operator
*********************************************************************/
int extractOpp(std::string a, int space1, int space2){
	if ((a[space1 + 1] == '+') || (a[space1 +1] == '-') || (a[space1 + 1] == '*') || (a[space1 + 1] == '/')){
		if (a[space1 + 2] == a[space2]){
			return a[space1 + 1];
		}else{
			std::cout << "ERROR, you entered something werid :(\nYou will be taken back to the main screen.\nPlease enter correct input" << '\n';
		} return 254;
	}else{
		std::cout << "ERROR, you entered something werid :(\nYou will be taken back to the main screen.\nPlease enter correct input" << '\n';
	}
	return 254;
}
/*********************************************************************
** Fucntion:		findspace
** Description:		This program locates the spaces in the string
					expression
** Parameters:		string a (just needs to have spaces)
					int i (used as a point to start checking through string)
** Pre-Condition:	needs valid string
					not necessary to have an int i value.
** Post-Condition: 	position of where the space is in the string.
*********************************************************************/
int findspace(std::string a, int i = 0){
	for (; i < a.length(); i++) {
		if (a[i] == ' '){
			return i;
		}
	}
}
/*********************************************************************
** Fucntion:		extractnum()
** Description:		extracts operands from string based on parameters
** Parameters:		string a (the string expression),
					int i (dictates where funciton will start scanning
					for a value.)
					string b (a string used for storage of the new
					string that will be returned, the extracted number)
** Pre-Condition:	string expression with spcaes
					not necessary to have a value for int i
** Post-Condition: 	a string number that has been removed from the rest
					of the string expression
*********************************************************************/
std::string extractnum(std::string a, int i = 0, std::string b = ""){
	for (;i < a.length(); i++) {
		b += a[i];
		if (a[i] == ' '){
			return b;
		}
	}
}
/*********************************************************************
** Fucntion:		calc_expression()
** Description:		collates all the values necessary for calculation
** Parameters:		string a (just the validated string expression)
** Pre-Condition:	string a (string expresion)
** Post-Condition: 	passes on extracted numbers and operators for final
					cal
*********************************************************************/
float calc_expression(std::string a){
	a += char (32); a += char (46);
	float num1 = get_number(RemoveSpacesSTR(extractnum(a)));
	int space1 = findspace(a);
	int space2 = findspace(a, (space1+1));
	int oprtr = extractOpp(a, space1, space2);
	float num2 = get_number(RemoveSpacesSTR(extractnum(a, space2 + 1)));
	return fin_calc(num1, num2, oprtr);
}
/*********************************************************************
** Fucntion:		Valid_expression()
** Description:		Checks more on the validity of the expression
					mainly checks for invalid characters
** Parameters:		bool isValid = 0 (just used for error handling)
					string expression (the string that is checked)
** Pre-Condition:	a string expression
** Post-Condition: 	passes back a vaild string expression
*********************************************************************/
std::string Valid_expression(std::string expression, bool isValid = 0){
	do {
		for (int i = 0; i < expression.length(); i++) {
			if (((41 < expression[i]) && (expression[i] < 58) && (expression[i] != 44)) || (expression[i] == ' ')){
				isValid = 0;
			}else{
				isValid = 1;
			}
			if (isValid){
				std::cout << "You entered something weird\nPlease try again" << '\n';
				expression = "";
				//std::cin.ignore();
				getline(std::cin,expression);
			}
		}
	} while(isValid);
	return expression;
}
/*********************************************************************
** Fucntion:		simple_calc()
** Description:		This is the funciton that dictates the UI of the
					sub-program (simple calculator). this fucntion also
					takes in an input and makes sure that it is within
					the bounds of what is handled for
** Parameters:		bool isValid = 0 (just used for error handling)
					string expression = "" (string used to store
					expression)
** Pre-Condition:	none
** Post-Condition: 	returns a float handed from another fucntion.
*********************************************************************/
float simple_calc(bool isValid = 0, std::string expression = ""){
	std::cout << "Please enter a simple math equation. Put a space between each number/operator" << '\n';
	std::cout << "This calculator is only handled for 1 operator and 2 numbers per equation" << '\n';
	std::cout << "Does not accept more than 2 numbers." << '\n';
	std::cout << "i.e. \'3+5\' should be written as \'3 + 5\'" << '\n';
	std::cout << "The operators are:" << '\n';
	std::cout << "+ addition  ||  - substraction  ||  * multiplication  ||  / division" << '\n';
	std::cin.ignore();
	do {
		std::cout << "Pleae enter your number now: ";
		getline(std::cin,expression);
		if (3 == word_count(expression)){
			isValid = 0;
		}else {
		isValid = 1;
		}
	} while(isValid);

	 return calc_expression(Valid_expression(expression));
}
/********************************************************************/
/******************       INT MAIN STARTS HERE	   ******************/
/********************************************************************/

std::string UISTUFFS(int a){
	switch (a) {
		case 1:
		return "\nWant to do another calculation?\nEnter one of the following \nnumbers to run a particular Calculator\n";
		break; case 2:
		return "Enter which program you'd like to run\n";
		break; case 3:
		return "1 = Grade Calculator\n2 = binary to decimal\n3 = decimal to binary\n4 = simple Calculator\n0 = Quit Program\nEnter which program you'd like to run: ";

	}
}

int main() {

	int prognum = 0;
	std::cout << UISTUFFS(2) << '\n';
	do {
		std::cout << UISTUFFS(3);
		std::string prognum_STR;
		std::cin >> prognum_STR;
		prognum = Get_int(prognum_STR);
		std::cout << '\n'; //just making interface look nice.
		switch (prognum) {
			case 1:
			std::cout << "Running grade_calc()" << '\n';
			std::cout << "The average grade is: "<< grade_calc() << '\n';
			std::cout << UISTUFFS(1) << '\n';
			break;
			case 2:
			std::cout << "Running Bin_to_Dec()" << '\n';
			std::cout << "Your number is: " << get_bin() <<'\n';
			std::cout << UISTUFFS(1) << '\n';
			break;
			case 3:
			std::cout << "Running Dec_to_Bin()" << '\n';
			std::cout << "Your binary is: " << get_dec() <<'\n';
			std::cout << UISTUFFS(1) << '\n';
			break;
			case 4:
			std::cout << "Running std_calc()" << '\n';
			std::cout << "The answer is: " << simple_calc() << '\n';
			std::cout << UISTUFFS(1) << '\n';
			break;
			case 0:
			std::cout << "Ending program" << '\n';
			break;

		}
	} while(prognum > 0);
}
