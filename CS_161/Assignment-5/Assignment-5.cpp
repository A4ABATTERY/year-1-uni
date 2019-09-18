/*********************************************************************************
 * Filename		:		Assignment-5.cpp
----------------------------------------------------------------------------------
 * Author		:		Arunav Biswas
----------------------------------------------------------------------------------
 * Description	: 		Farkle game.
----------------------------------------------------------------------------------
 * Input		: 		String numbers
----------------------------------------------------------------------------------
 * Output 		: 		Players rolls, which player's turn it is, how much a player
 						can potentially score, if a player wants to reroll.
*********************************************************************************/



#include <iostream>
#include <ctime>
#include <cstdlib>


/*********************************************************************
** Function: 		is_int()
** Description:		verify if string is an integer
** Parameters: 		string number
** Pre-Condition:	a string
** Post Condition: 	bool
*********************************************************************/
bool is_int(std::string a) {
	int numO45 = 0, numOnums = 0, numOuseless;
	for (unsigned int i = 0; i <= a.length(); i++) {
		if (a[i] == '-') {
			numO45++;
		} else if ((58 > a[i]) && (a[i] > 47)) {
			numOnums++;
		}
	}
	numOuseless = a.length() - (numOnums + numO45);
	if ( (numOuseless == 0) && ((numO45 == 0) || (numO45 == 1)) ) {
		return true;
	} else {
		return false;
	}
}
/*********************************************************************
** Function: 		Get_int()
** Description:		converts string number to int
** Parameters: 		string
** Pre-Condition:	technically none needed, function asks for input if
					no parameter is given
** Post Condition: 	int
*********************************************************************/
int Get_int(std::string a = ""){
	std::cin >> a;
	int sign = 1;
	int charOffset, num;
	if (!(is_int(a))) {
		do {
			std::cout << "Please enter an integer" << '\n';;
			std::cin >> a;
		} while(!(is_int(a)));
	}
	if (a[0] == '-') {
		sign = -1;
		charOffset = 1;
	} else {
		sign = 1;
		charOffset = 0;
	}
	num = 0;
	for (int i = charOffset; a[i] != '\0'; i++) {
		num = (num * 10) + (int (a[i])) - 48;
	}
	return (num * sign);
}
/*********************************************************************
** Function: 		array_set_zero_bool()
** Description:		sets value of all elementes in array to zero
** Parameters: 		a boolean pointer, and array length
** Pre-Condition:	valid pointer, with valid array length
** Post Condition: 	none, fucntion is VOID, read description
*********************************************************************/
void array_set_zero_bool(bool *array, int len){
	for(int i = 0; i < len; i++){
		(array)[i] = 0;
	}
}
/*********************************************************************
** Function: 		array_set_zero_bool()
** Description:		sets value of all elementes in array to zero
** Parameters: 		a integer pointer, and array length
** Pre-Condition:	valid pointer, with valid array length
** Post Condition: 	none, fucntion is VOID, read description
*********************************************************************/
void array_set_zero_int(int *array, int len){
	std::cout << "Ran" << '\n';
	for(int i = 0; i < len; i++){
		(array)[i] = 0;
	}
}
/*********************************************************************
** Function: 		get_int_range()
** Description:		gets a value from user within a (hardcoded)range.
** Parameters: 		integer input, lowerbound, upperbound
** Pre-Condition:	valid integer
** Post Condition: 	an integer within range
*********************************************************************/
int get_int_range(int a, int lower, int upper, bool isValid = 1){
	do{
		if ((a > lower) && (a < upper)){
			return a;
		}
		else{
			std::cout << "Please enter valid number" << '\n';;
			isValid = 0;
			a = Get_int();
		}
	}while(!(isValid));
	return a;
}
/*********************************************************************
** Function: 		free_heap_mem()
** Description:		deletes dynamic memory used by int pointers
** Parameters: 		int pointer
** Pre-Condition:	valid int pointer
** Post Condition: 	none, fucntion is VOID, read description
*********************************************************************/
void free_heap_mem(int* pointer){
	delete[]pointer;
	pointer = NULL;
}
/*********************************************************************
** Function: 		free_heap_mem()
** Description:		deletes dynamic memory used by bool pointers
** Parameters: 		bool pointer
** Pre-Condition:	valid bool pointer
** Post Condition: 	none, fucntion is VOID, read description
*********************************************************************/
void free_heap_mem_bool(bool* pointer){
	delete[]pointer;
	pointer = NULL;
}
/*********************************************************************
** Function: 		printScoreBoard()
** Description:		does literally what the funciton decleration says
** Parameters: 		int pointer, int
** Pre-Condition:	valid pointer to an array, length of array
** Post Condition: 	none, fucntion is VOID, read description
*********************************************************************/
void printScoreBoard(int* playerARR,int numOplayers){
	std::cout << "**********SCORE*****BOARD**********" << '\n';
	for(int player = 0; player < numOplayers; player++){
		std::cout << "******PLAYER " << player + 1 << " ***** " << (playerARR)[player] << "**********" << '\n';
	}
}
/*********************************************************************
** Function: 		numOoccur()
** Description:		counts the number of occurances of an element in an
					array
** Parameters: 		int pointer, array length, element being searched for
** Pre-Condition:	valid pointer to an array, length of an array, element
					being searched for
** Post Condition: 	returns the number of occurances of element
*********************************************************************/
int numOoccur(int* Array, int ArrLen, int searchFor, int count = 0){
	for(int i = 0; i < ArrLen; i++){
		if ((Array)[i] == searchFor){
			count++;
		}
	}return count;
}
/*********************************************************************
** Function: 		numOoccur_bool()
** Description:		returns true or false based instances of an element
					that is being searched for. READ numOoccur()
** Parameters: 		int pointer, array length, element being searched for
					and number instances of an element.
** Pre-Condition:	valid pointer to an array, lenth of the array, element
					being searcehd for, number of instances of that element
** Post Condition: 	boolean
*********************************************************************/
bool numOoccur_bool (int *diceArray, int arrLen, int searchFor, int instances){
	if (numOoccur(diceArray, arrLen, searchFor) == instances)
		return true;
	return false;
}
/*********************************************************************
** Function: 		fourofAkind_bool()
** Description:		returns true or false based on the existance of four
					of the same number
** Parameters: 		array of dice rolls
** Pre-Condition:	valid pointer to an array.
** Post Condition: 	bool
*********************************************************************/
bool fourofAkind_bool(int* diceArray){
	if (numOoccur_bool(diceArray,6,1,4)) return true;
	if (numOoccur_bool(diceArray,6,2,4)) return true;
	if (numOoccur_bool(diceArray,6,3,4)) return true;
	if (numOoccur_bool(diceArray,6,4,4)) return true;
	if (numOoccur_bool(diceArray,6,5,4)) return true;
	if (numOoccur_bool(diceArray,6,6,4)) return true;

	return false;
}
/*********************************************************************
** Function: 		fiveofAkind_bool()
** Description:		returns true or false based on the existance of five
					of the same number
** Parameters: 		array of dice rolls
** Pre-Condition:	valid pointer to an array.
** Post Condition: 	bool
*********************************************************************/
bool fiveofAkind_bool(int* diceArray){
	if (numOoccur_bool(diceArray,6,1,5)) return true;
	if (numOoccur_bool(diceArray,6,2,5)) return true;
	if (numOoccur_bool(diceArray,6,3,5)) return true;
	if (numOoccur_bool(diceArray,6,4,5)) return true;
	if (numOoccur_bool(diceArray,6,5,5)) return true;
	if (numOoccur_bool(diceArray,6,6,5)) return true;

	return false;
}
/*********************************************************************
** Function: 		sixofAkind_bool()
** Description:		returns true or false based on the existance of six
					of the same number
** Parameters: 		array of dice rolls
** Pre-Condition:	valid pointer to an array.
** Post Condition: 	bool
*********************************************************************/
bool sixofAkind_bool(int* diceArray){
	if (numOoccur_bool(diceArray,6,1,6)) return true;
	if (numOoccur_bool(diceArray,6,2,6)) return true;
	if (numOoccur_bool(diceArray,6,3,6)) return true;
	if (numOoccur_bool(diceArray,6,4,6)) return true;
	if (numOoccur_bool(diceArray,6,5,6)) return true;
	if (numOoccur_bool(diceArray,6,6,6)) return true;

	return false;
}
/*********************************************************************
** Function: 		straight_bool()
** Description:		returns true or false based on the existance of
					a straight. ie. 1 2 3 4 5 6
** Parameters: 		array of dice rolls
** Pre-Condition:	valid pointer to an array.
** Post Condition: 	bool
*********************************************************************/
bool straight_bool(int* diceArray){
	if ((diceArray)[0] == 1 && (diceArray)[1] == 2 && (diceArray)[2] == 3 &&
		(diceArray)[3] == 4 && (diceArray)[4] == 5 && (diceArray)[5] == 6){
			return true;
		} return false;
}
/*********************************************************************
** Function: 		threePair_bool()
** Description:		returns true or false based on the existance of
					3 pairs in a roll. ie. 1, 1, 2, 2, 3, 3
** Parameters: 		array of dice rolls
** Pre-Condition:	valid pointer to an array.
** Post Condition: 	bool
*********************************************************************/
bool threePair_bool(int* diceArray){
	if ((diceArray)[0] == 0) return false;
	if ((diceArray)[0] == diceArray[1] && (diceArray)[2] == (diceArray[3]) &&
		(diceArray)[4] == (diceArray)[5])
			return true;
	return false;
}
/*********************************************************************
** Function: 		fourAndPair_bool()
** Description:		returns true or false based on the existance of four
					of the same number, and a pair. ie. 1, 1, 1, 1, 2, 2
** Parameters: 		array of dice rolls
** Pre-Condition:	valid pointer to an array.
** Post Condition: 	bool
*********************************************************************/
bool fourAndPair_bool(int* diceArray){
	if ((diceArray)[0] == 0) return false;
	if ((fourofAkind_bool(diceArray) && ((diceArray)[0] == (diceArray)[1])) ||
		(fourofAkind_bool(diceArray) && ((diceArray)[4] == (diceArray)[5])))
			return true;
	return false;
}
/*********************************************************************
** Function: 		twoTriplets_bool()
** Description:		returns true or false based on the existance of two
					tripletes. ie. 2, 2, 2, 5, 5, 5
** Parameters: 		array of dice rolls
** Pre-Condition:	valid pointer to an array.
** Post Condition: 	bool
*********************************************************************/
bool twoTriplets_bool(int* diceArray){
	if ((diceArray)[0] == 0) return false;
	if ((diceArray)[0] == (diceArray)[1] && (diceArray)[1] == (diceArray)[2] &&
		(diceArray)[3] == (diceArray)[4] && (diceArray)[3] == (diceArray)[5])
			return true;
	return false;
}
/*********************************************************************
** Function: 		specialChecks()
** Description:		checks for straights, 3 pairs, four of a kind & pair,
					and two tripletes
** Parameters: 		array of valid choices, array of dice rolls
** Pre-Condition:	valid pointer to both arrays.
** Post Condition: 	VOID, just appends valid choice array
*********************************************************************/
void specialChecks(bool* choiceArr, int* diceArray) {
	if (straight_bool(diceArray)) {std::cout << "A straight = 1500  (14)  ";(choiceArr)[13] = 1;}
	if (threePair_bool(diceArray)) {std::cout << "Three pairs = 1500  (15)  ";(choiceArr)[14] = 1;}
	if (fourAndPair_bool(diceArray)) {std::cout << "Four of a kind and a Pair = 1500  (16)  ";(choiceArr)[15] = 1;}
	if (twoTriplets_bool(diceArray)) {std::cout << "Two triples = 2500 (17)";(choiceArr)[16] = 1;}
}
/*********************************************************************
** Function: 		multiOccurCheck()
** Description:		returns true or false based on the existance of four
					of a kind, five of a kind, or six of a kind
** Parameters: 		array of dice rolls
** Pre-Condition:	valid pointer to an array.
** Post Condition:  VOID, just appends valid choice array
*********************************************************************/
void multiOccurCheck(bool* choiceArr, int* diceArray){
	if (fourofAkind_bool(diceArray)) {std::cout << "Four of a kind = 1500  (11)  ";(choiceArr)[10] = 1;}
	if (fiveofAkind_bool(diceArray)) {std::cout << "Five of a kind = 2000  (12)  ";(choiceArr)[11] = 1;}
	if (sixofAkind_bool(diceArray)) {std::cout << "Six of a kind = 2000  (13)  ";(choiceArr)[12] = 1;}
}
/*********************************************************************
** Function: 		make_choice()
** Description:		asks user to make a choice based on valid combos that
					exist in the roll for that turn.
** Parameters: 		bool pointer, int pointer
** Pre-Condition:	valid pointer to bool array, vaild pointer to dice array
** Post Condition:  returns the number correspoinding to the combo that the
					user picked
*********************************************************************/
int make_choice(bool* choiceArr, int* diceArray, int choice = -1){
	do {
		std::cout << "\n\n To select a combo, Please enter the number brackets next to your selected combo || Enter zero if there are no Combos: ";
		choice = get_int_range(Get_int(), -1, 18);
		if (choice == 0)
			return 0;
	} while(choiceArr[choice - 1] != 1);
	free_heap_mem_bool(choiceArr);
	return choice;

}
/*********************************************************************
** Function: 		checkcombo()
** Description:		checks dice roll for all valid combos present in roll
** Parameters: 		int pointer
** Pre-Condition:	valid pointer to dice array.
** Post Condition:  return the number correspoinding to the combo that the
					user picked
*********************************************************************/
int checkcombo(int* diceArray){
	bool *choiceArr = new bool[17]; array_set_zero_bool(choiceArr, 17);
	std::cout << "\nYour possible Combos are: ";
	if (numOoccur(diceArray, 6, 1) >= 1) {std::cout << "Single 1 = 100  (1)  "; (choiceArr)[0] = 1;}
	if (numOoccur(diceArray, 6, 1) >= 2) {std::cout << "Two 1 = 200  (2)  "; (choiceArr)[1] = 1;}
	if (numOoccur(diceArray, 6, 5) >= 1) {std::cout << "One 5 = 50  (3)  "; (choiceArr)[2] = 1;}
	if (numOoccur(diceArray, 6, 5) >= 2) {std::cout << "Two 5 = 100  (4)  ";(choiceArr)[3] = 1;}
	if (numOoccur(diceArray, 6, 1) >= 3) {std::cout << "Triple 1s = 300  (5)  ";(choiceArr)[4] = 1;}
	if (numOoccur_bool(diceArray, 6, 2, 3)) {std::cout << "Triple 2s = 200  (6)  ";(choiceArr)[5] = 1;}
	if (numOoccur_bool(diceArray, 6, 3, 3)) {std::cout << "Triple 3s = 300  (7)  ";(choiceArr)[6] = 1;}
	if (numOoccur_bool(diceArray, 6, 4, 3)) {std::cout << "Triple 4s = 400  (8)  ";(choiceArr)[7] = 1;}
	if (numOoccur(diceArray, 6, 5) >= 3) {std::cout << "Triple 5s = 500  (9)  ";(choiceArr)[8] = 1;}
	if (numOoccur_bool(diceArray, 6, 6, 3)) {std::cout << "Triple 6s = 600  (10)  ";(choiceArr)[9] = 1;}
	multiOccurCheck(choiceArr, diceArray);
	specialChecks(choiceArr, diceArray);
	return make_choice(choiceArr, diceArray);

}
/*********************************************************************
** Function: 		scoreCombo()
** Description:		applys the score correspoinding to the combo that the
					user picked.
** Parameters:		integer
** Pre-Condition:	valid choice that exists in array
** Post Condition:	retuns the nubmer of points correspoinding with the
					combo
*********************************************************************/
int scoreCombo(int choice){
	switch (choice){case 0: return 0;/*Frkl*/case 1: return 100;
					case 2: return 200;		case 3: return 50;
					case 4: return 100;		case 5: return 300;
					case 6: return 200;		case 7: return 300;
					case 8: return 400;		case 9: return 500;
					case 10: return 600;	case 11: return 1500;
					case 12: return 2000;	case 13: return 2000;
					case 14: return 1500;	case 15: return 1500;
					case 16: return 1500;	case 17: return 2500;

	} return 0;
}
/*********************************************************************
** Function: 		bubblesort()
** Description:		used to sort the dice after they have been rolled
					ie. 1, 4, 2, 5, 6, 1 -----> 1, 1, 2, 4, 5, 6
** Parameters: 		int pointer
** Pre-Condition:	valid pointer to the dice array
** Post Condition:  VOID, just sorts dice, Read Description
*********************************************************************/
void bubblesort(int* diceArray, int temp = 0){
	for (int i = 5; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if ((diceArray)[j] > (diceArray)[j + 1]) {
				temp = (diceArray)[j];
				(diceArray)[j] = (diceArray)[j + 1];
				(diceArray)[j + 1] = temp;
			}
		}
	}
}
/*********************************************************************
** Function: 		roll()
** Description:		literaly what the function header says, just rolls dice
** Parameters: 		int pointer
** Pre-Condition:	valid pointer to dice array, number of dice (optional)
** Post Condition:  VOID, just modifs values in dice array
*********************************************************************/
void Roll(int *diceArray, int numOdice = 6) {
	for (int i = 0;i < numOdice ;i++) {
		(diceArray)[i] = ((rand()%6) + 1);
	}
}
/*********************************************************************
** Function: 		printroll()
** Description:		just prints values in an array
** Parameters: 		int pointer, length of array
** Pre-Condition:	valid pointer to dice array
** Post Condition:  VOID, none
*********************************************************************/
void printroll(int* diceArray, int numOdice = 6) {
	std::cout << "Your roll: ";
	for (int i = 0; i < numOdice; i++) {
		std::cout << " " << diceArray[i];
	}
}

int diceToReroll(int choice, int numOdice) {
	if ((choice > 12) && (choice < 18)) {
		return 6;}
	if ((choice == 1) || (choice == 3)) {
		if ((numOdice - 1) < 0)
			return 0;
		return numOdice - 1;}
	if ((choice == 2) || (choice == 4)) {
		if ((numOdice - 2) < 0)
			return 0;
		return numOdice - 2;}
	if ((choice > 4) && (choice < 11))  {
		if ((numOdice - 3) < 0)
			return 0;
		return numOdice - 3;}
	if (choice == 11){
		if ((numOdice - 4) < 0)
			return 0;
		return numOdice - 4;}
	if (choice == 12){
		if ((numOdice - 5) < 0)
			return 0;
		return numOdice - 5;}
}
/*********************************************************************
** Function: 		re_roll()
** Description:		literally what the funciton header says
** Parameters: 		bool, integer, int pointer, int
** Pre-Condition:	true or false of whether to re-roll or not,
					user choice of combo, valid pointer to dice array,
					integer points of current player.
** Post Condition:  returns total pointer for turn
*********************************************************************/
int re_roll(bool reRoll, int choice, int* diceArray, int firstroll, int temp = 0, int dice = 6, int temp2 = 0){
	std::cout << "Your score so far: " << firstroll << '\n'  << "\n\nWould you like to re-roll again. \n 1 = Yes || 0 = No\n" << '\n';
	reRoll = get_int_range(Get_int(), -1, 2);
	while(reRoll == 1){
		dice = diceToReroll(choice, dice); array_set_zero_int(diceArray, 6);
		Roll(diceArray, dice); bubblesort(diceArray); std::cout << "\n\n";
		printroll(diceArray); std::cout << "\n\n";
		choice = (checkcombo(diceArray));
		temp2 = scoreCombo(choice);
		if (temp2 == 0) {temp = 0; return temp;}
		else if (temp2 > 0){temp += temp2;}
		std::cout << "Your score so far: " << firstroll + temp << '\n'  << "\n\nWould you like to re-roll again. \n 1 = Yes || 0 = No\n" << '\n';
		reRoll = get_int_range(Get_int(), -1, 2);
	}
	return temp + 1;
}
/*********************************************************************
** Function: 		get_first_turn()
** Description:		literally what the function header says
** Parameters: 		int pointer, int
** Pre-Condition:	pointer to dice array, current players score
** Post Condition:  returns points attained by player
*********************************************************************/
int get_first_turn(int* diceArray, int temp, int choice = 0, int temp2 = 0){
		while(temp < 499){
			Roll(diceArray); bubblesort(diceArray); std::cout << "\n\n";
			printroll(diceArray); std::cout << "\n\n";
			choice = (checkcombo(diceArray));
			temp = scoreCombo(choice);
			if (temp == 0){
				std::cout << "Oh Noooo! You Farkeled :( \nYour score for this turn is zero" << '\n';
				temp = 0; return temp;
			}
			temp2 = re_roll(0, choice, diceArray, temp);
			if (temp2 == 0) {std::cout << "You Farkeled :(" << '\n'; temp = 0; return temp;}
			temp+=temp2;
			if ((temp < 499) && (temp != 0) && (temp != 1)) {
				std::cout << "Score too low.....\nRe-Rolling dice" << '\n';
			}
			else if (temp == 0){
				std::cout << "You Farkeled :( \nYour score for this turn is zero" << '\n';
				temp = 0; return temp;
			}
		}
	std::cout << "Your final score for this turn: " << temp -1 << "\n\n\n";
	return temp - 1;
}
/*********************************************************************
** Function: 		check_win()
** Description:		checks if a player has gotten to 10,000 or above
** Parameters: 		int pointer, int
** Pre-Condition:	pointer to array of players, current player
** Post Condition:  boolean
*********************************************************************/
bool check_win(int* playerARR, int player){
	if ((playerARR)[player] >= 10000)
		return true;
	return false;
}
/*********************************************************************
** Function: 		printWinner()
** Description:		determines winner and prints out winner player number
** Parameters: 		int pointer,  int pointer, int
** Pre-Condition:	pointer to dice array, pointer to player array
** Post Condition:  VOID, just cout's whoever won the game
*********************************************************************/
void printWinner(int* diceArray, int* playerARR,int numOplayers, int player = 0, int won = 0){
	printScoreBoard(playerARR, numOplayers);
	for (int i = 0; i < numOplayers; i++){
		if ((playerARR)[player] > (playerARR)[i])
			won = i;
	}
	std::cout << "Player " << player + 1 << " won the game" << '\n';
}
/*********************************************************************
** Function: 		playerFirstTurn()
** Description:		this is the first turn of the player, makes sure player
					makes it on to the score board
** Parameters: 		int pointer, int pointer, int
** Pre-Condition:	pointer to dice array, pointer to player array, current player
** Post Condition:  VOID, modify value in player array
*********************************************************************/
void playerFirstTurn(int* diceArray, int* playerARR, int numOplayers, int player = 0, int temp = 0){
	for (player = 0; player < numOplayers; player++) {
		std::cout << "it's Player " << player + 1 << "\'s turn."<<'\n';
		temp = (playerARR)[player];
		(playerARR)[player] = get_first_turn(diceArray, temp);
	}
}
/*********************************************************************
** Function: 		get_turn()
** Description:		gets turn
** Parameters: 		int pointer, int
** Pre-Condition:	pointer to dice array, current players score
** Post Condition:	returns players new score after turn is done
*********************************************************************/
int get_turn(int* diceArray, int temp, int choice = 0, int temp2 = 0){
		Roll(diceArray); bubblesort(diceArray); std::cout << "\n\n";
		printroll(diceArray); std::cout << "\n\n";
		choice = (checkcombo(diceArray));
		temp = scoreCombo(choice);
		if (temp == 0){
			std::cout << "Oh Noooo! You Farkeled :( \nYour score for this turn is zero" << '\n';
			return 0;
		}
		temp2 = re_roll(0, choice, diceArray, temp);
		if (temp2 == 0) {std::cout << "You Farkeled :(" << '\n'; temp = 0; return temp;}
		temp+=temp2;
		if (temp == 0){
			std::cout << "You Farkeled :( \nYour score for this turn is zero" << '\n';
			return 0;
	}
	std::cout << "Your final score for this turn: " << temp << "\n\n\n";
	return temp - 1;
}
/*********************************************************************
** Function: 		bonusturn()
** Description:		grants a bonus turn to all players excluding the
					player that passed/got-to 10,000
** Parameters: 		int pointer, int pointer, int, int
** Pre-Condition:	pointer to dice array, pointer to player array, which
					player to exclude.
** Post Condition:	VOID, this function only appends the finaly scores of
					players.
*********************************************************************/
void bonusturn(int* diceArray, int* playerARR, int excludePlayer, int numOplayers, int temp = 0){
	std::cout << "Player " << excludePlayer + 1 << " just passed/got-to 10,000\nall other players get 1 last turn" << '\n';
	for(int player = 0; player < numOplayers; player ++){
		if (player != excludePlayer){
			printScoreBoard(playerARR, numOplayers);
			std::cout << "it's Player " << player + 1 << "\'s turn."<<'\n';
			temp = (playerARR)[player];
			(playerARR)[player] += get_turn(diceArray, temp);
		}
	}
}
/*********************************************************************
** Function: 		get_turn()
** Description:		gets turn
** Parameters: 		int pointer, int
** Pre-Condition:	pointer to dice array, current players score
** Post Condition:	returns players new score after turn is done
*********************************************************************/
void Playerturns(int* diceArray, int* playerARR, int numOplayers, int player = 0, int temp = 0, int someone_won = -1){
	do {
		for (player = 0; player < numOplayers; player++){
			printScoreBoard(playerARR, numOplayers);
			std::cout << "it's Player " << player + 1 << "\'s turn."<<'\n';
			temp = (playerARR)[player];
			(playerARR)[player] += get_turn(diceArray, temp);
			if (check_win(playerARR, player)){
				someone_won = player;
				bonusturn(diceArray, playerARR, player, numOplayers);
				printWinner(diceArray, playerARR, numOplayers, player);
				break;
			}
		}
	} while(someone_won == -1);

}
/*********************************************************************
** Function: 		gamestart()
** Description:		handles the flow of the game. This is basically my
					"int main"
** Parameters: 		none
** Pre-Condition:	none
** Post Condition:	VOID. does nothing
*********************************************************************/
void gamestart(){
	srand(time(0));
	int* diceArray = new int[6];
	std::cout << "Enter number of players" << '\n';
	int numOplayers = get_int_range(Get_int(), 1, 9);
	int *playerARR = new int[numOplayers]; array_set_zero_int(playerARR, numOplayers);
	playerFirstTurn(diceArray, playerARR, numOplayers);

	Playerturns(diceArray, playerARR, numOplayers);

	free_heap_mem(diceArray); free_heap_mem(playerARR);

}
int main(){
	std::cout << "*********************Starting Farkle*********************\n\n" << '\n';
	gamestart();
	return 0;
}
