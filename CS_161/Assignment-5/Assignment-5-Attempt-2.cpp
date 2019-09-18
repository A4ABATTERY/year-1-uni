/*********************************************************************************
 * Filename		:		Assignment-5.cpp
----------------------------------------------------------------------------------
 * Author		:		Arunav Biswas
----------------------------------------------------------------------------------
 * Description	: 		Farkle game.
----------------------------------------------------------------------------------
 * Input		: 		String numbers, string binary.
----------------------------------------------------------------------------------
 * Output 		: 		Players rolls, which player's turn it is, how much a player
 						can potentially score, if a player wants to reroll.
*********************************************************************************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

/*********************************************************************
** Function: 		UISTUFFS()
** Description:		just prints general UI.
** Parameters: 		takes in an integer, it is hardcoded
** Pre-Condition:	hardcoded positive integer
** Post Condition: 	returns a string
*********************************************************************/
std::string UISTUFFS(int num = 0){
	switch (num) {
		case 1: return "How many players do you want in this game?\n"; break;
		case 2: return "if you'd like to re-roll\nEnter the number of dice you'd like to reroll (1 - 5 dice)\n if you would like to bank your current score enter 0"; break;
		case 3: return "An unreasonable amount of players. Please enter a number from 2 to 8\n";
		case 4: return "Invalid input, please try again";

	}
	return "No valid parameter given";
}
/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Condition:
** Post Condition:
*********************************************************************/
void free_heap_mem(int* pointer, int len = 1){
	delete[]pointer;
	pointer = NULL;
}
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
int Get_int(std::string a = ""){
	std::cin >> a;
	int sign = 1;
	int charOffset, num;
	if (!(is_int(a))) {
		do {
			std::cout << "Please enter a whole number" << '\n';;
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
int checkplayer(int a, bool isValid = 1){
	do{
		if ((a > 1) && (a < 17)){
			return a;
		}
		else{
			std::cout << "Unreasonable amount of players...." << '\n';
			UISTUFFS(3);
			isValid = 0;
			a = Get_int();
		}
	}while(!(isValid));
	std::cout << a << '\n';
	return a;
}
void rolldice(int* diceArray) {
	for (int i = 0; i < 6; i++){
		(diceArray)[i] = ((rand() % 6) + 1);
	}
}
void bubblesort(int* diceArray, int intermediary = 0){
	for (int i = 5; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if ((diceArray)[j] > (diceArray)[j + 1]) {
				intermediary = (diceArray)[j];
				(diceArray)[j] = (diceArray)[j + 1];
				(diceArray)[j + 1] = intermediary;
			}
		}
	}
}
void printroll(int* diceArray, int numOdice = 6) {
	std::cout << "Your roll: ";
	for (int i = 0; i < numOdice; i++) {
		std::cout << " " << diceArray[i];
	}
}
int numOoccur(int* Array, int ArrLen, int searchFor, int count = 0){
	for(int i = 0; i < ArrLen; i++){
		if ((Array)[i] == searchFor){
			count++;
		}
	}return count;
}
bool Checksingles_bool(int* diceArray, int numOdice){
	int occurOones = numOoccur(diceArray, 6, 1);
	int occurOfive = numOoccur(diceArray, 6, 5);
	if (occurOfive == 1 || occurOones == 1 || occurOfive == 2 || occurOones == 2)
		return true;
	return false;
}
bool checktriple_bool(int* diceArray, int numOdice){
	int numOsix, numOfive, numOfour, numOthree, numOtwo, numOone;
	numOsix = numOoccur(diceArray, 6, 6); numOfive = numOoccur(diceArray, 6, 5);
	numOfour = numOoccur(diceArray, 6, 4); numOthree = numOoccur(diceArray, 6, 3);
	numOtwo = numOoccur(diceArray,6, 2); numOone = numOoccur(diceArray,6, 1);
	if 	((numOone == 3) || (numOtwo == 3) || (numOthree == 3) ||
		(numOfour == 3) || (numOfive == 3) || (numOsix == 3)){
			return true;
		} return false;
}
bool checkQuad(int* diceArray, int numOdice){
	int numOsix, numOfive, numOfour, numOthree, numOtwo, numOone;
	numOsix = numOoccur(diceArray, 6, 6); numOfive = numOoccur(diceArray, 6, 5);
	numOfour = numOoccur(diceArray, 6, 4); numOthree = numOoccur(diceArray, 6, 3);
	numOtwo = numOoccur(diceArray,6, 2); numOone = numOoccur(diceArray,6, 1);
	if 	((numOone == 4) || (numOtwo == 4)|| (numOthree == 4) ||
		(numOfour == 4) || (numOfive == 4) || (numOsix == 4)){
			return true;
		} return false;

}
bool checkPenta(int* diceArray, int nunOdice) {
	int numOsix, numOfive, numOfour, numOthree, numOtwo, numOone;
	numOsix = numOoccur(diceArray, 6, 6); numOfive = numOoccur(diceArray, 6, 5);
	numOfour = numOoccur(diceArray, 6, 4); numOthree = numOoccur(diceArray, 6, 3);
	numOtwo = numOoccur(diceArray,6, 2); numOone = numOoccur(diceArray,6, 1);
	if 	((numOone == 5) || (numOtwo == 5) || (numOthree == 5) ||
		(numOfour == 5) || (numOfive == 5) || (numOsix == 5)){
			return true;
		} return false;
}
bool checkstraight(int* diceArray, int numOdice) {
	for(int i = 0; i < 6; i++){
		if ((diceArray)[i] != (i + 1))
			return false;
		}return true;
}



int score_the_roll(int* diceArray, int score = 0, int Choice){
	std::cout << "Choose from your list of combos:" << '\n';
	switch (Choice) {
		case 1:
	}
}


int get_turn(int* diceArray, int* score, char reroll = 'n'){
	//The Do-while loop represents the players first turn.
//	do {
		rolldice(diceArray);
		bubblesort(diceArray);
		printroll(diceArray);
		checkcombo(diceArray);
		*score += score_the_roll(diceArray)
//	} while(score < 500);
	/*std::cout << "Would you like to re-roll (Y/N)" << '\n';
	if ((reroll == 'y') || (reroll == 'Y')) {
		//Get_Re_Roll(diceArray)
	}*/
	return score;
}





void gamestart(){
	std::cout << "How many players are there?" << '\n';
	int numOplayers = checkplayer(Get_int());
	int* playerScore = new int[1];
	int* playerArr = new int[numOplayers];
	int* diceArray = new int[6];
	for (int i = 0; i < numOplayers; i++){
		std::cout << "\n\nIt's player " << (i + 1) << "\'s turn" << '\n';
		*playerScore = get_turn(diceArray, playerScore);
		std::cout << "\nplayer " << (i + 1) << " scored " << *playerScore << '\n';
		(playerArr)[i] = *playerScore;
	}
	free_heap_mem(playerArr, 6); free_heap_mem(diceArray, 6); free_heap_mem(playerScore, 1);
}

int main() {
	srand(time(0));
	std::cout << "Starting Farkle\n\n" << '\n';
	gamestart();
	return 0;
}
