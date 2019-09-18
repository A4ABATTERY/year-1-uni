/*********************************************************************************
 * Filename		:		Checkers.cpp
----------------------------------------------------------------------------------
 * Author		:		Arunav Biswas
----------------------------------------------------------------------------------
 * Description	: 		Checkers board game
----------------------------------------------------------------------------------
 * Input		: 		C-style strings, in the form of coordinates
 						i.e. H8, J10, L12 are correct inputs
							 h8, 10j, wasd are wront inputs
----------------------------------------------------------------------------------
 * Output 		: 		A game of checkers that uses 2 players.
 						Alternates between each players turn
						A winning player at the end.
*********************************************************************************/

#include <iostream>
/********************************************************************************
** Function: 		Get_int()
** Description:		Gets an integer from user. this function is called if
					no command line Argv is given, or is invalid.
** Parameters: 		NONE
** Pre-Condition:	NONE
** Post Condition: 	returns positive integer
********************************************************************************/
int Get_int();
/********************************************************************************
** Function: 		CheckArg()
** Description:		checks if given command line argument is valid
** Parameters: 		takens in two chars from argv[1]
					(takes in argv[1][0], and argv[1][1])
** Pre-Condition:	takes in two characters
** Post Condition: 	returns positive integer
********************************************************************************/
int CheckArg(char, char);
/********************************************************************************
** Function: 		free_1D_mem()
** Description:		Frees memory in the heap for Character pointers, and
					integer pointers
** Parameters: 		ONLY 1 PARAMETER PER FUNCTION CALL.
					can either be Character pointer, OR integer pointer
** Pre-Condition:	pointer (char XOR array)
** Post Condition: 	VOID, just frees memory
********************************************************************************/
void free_1D_mem(int* array); void free_1D_mem(char* array);
/********************************************************************************
** Function: 		isPosiInt_COOR()
** Description:		checks if y-coordinate is positive
** Parameters: 		takes in a Character array (POINTER)
** Pre-Condition:	valid pointer to char array
** Post Condition: 	returns boolean
********************************************************************************/
bool isPosiInt_COOR(char*);
/********************************************************************************
** Function: 		COOR_token_valid()
** Description:		Checks if the Token that is chosen to move is correct for
					that player. ie player 1 can only pick 'o' or 'O'
** Parameters: 		int Player (player 1 or player 2), int* coordinate
					char** board, int, int
** Pre-Condition:	Given a player (1 or 2), given pointer to coordinate,
 					Double pointer to board
** Post Condition: 	a Boolean
********************************************************************************/
bool COOR_token_valid(int, int*, char**, int, int);
/********************************************************************************
** Function: 		Plot_the_move()
** Description:		Plots the finalised and valid move on board
** Parameters: 		int* to-coordinate, int* from-coordinate,
					double pointer to board.
** Pre-Condition:	valid pointers
** Post Condition: 	always returns true;
********************************************************************************/
bool Plot_the_move(int*, int*, char**);
/********************************************************************************
** Function: 		KingsMove()
** Description:		This function is specific to Kings. it makes the move and
					make captures in diagonals in all directions
** Parameters: 		double pointer to board, int x-Coordinate-TO,
					int y-coordinate-TO, int x-Coordinate-FROM,
					int y-coordinate-FROM, int* To-coordinate,
					int* from-coordinate, char Kings-Token, char, char
** Pre-Condition:	all valid parameters
** Post Condition: 	returns boolean
********************************************************************************/
bool KingsMove(char**,int, int, int, int, int*, int*, char, char, char);
/********************************************************************************
** Function: 		PlayerOneMove(), AND PlayerTwoMove()
** Description:		BOTH FUNCTIONS ARE IDENTICAL. the only difference is that they
					each only modify the token that adheres to a particular player

					These functions validate if a peice can be moved to a given
					coordinate. only modifies normal tokens.
					PlayerOneMove 'a'
					PlayerTwoMove 'o'
** Parameters: 		double pointer to board, int x-Coordinate-TO,
					int y-coordinate-TO, int x-Coordinate-FROM,
					int y-coordinate-FROM, int* To-coordinate,
					int* from-coordinate
** Pre-Condition:	char** board, xto, yto, xfrom, xto, int* toCOOR, int* fromCOOR
** Post Condition:	boolean
********************************************************************************/
bool PlayerOneMove(char**, int, int, int, int, int*, int*); bool PlayerTwoMove(char**, int, int, int, int, int*, int*);
/********************************************************************************
** Function:		COOR_valid_Move()
** Description:		Checks if coordinate chosen is valid to move to
** Parameters:		int* from-coordinate, int* to-coordinate,
					char** board, int rows, int player
** Pre-Condition:	valid pointers and values.
** Post Condition:	returns boolean
********************************************************************************/
bool COOR_valid_Move(int*, int*, char**, int, int);
/********************************************************************************
** Function: 		getCoordinate_from()
** Description:		Gets the first coordinate from the user.
					i.e. Which token do you want to move: G3
** Parameters: 		int* pointer, char* string, int rows,
					char** board, int player, bool
** Pre-Condition:	Technically this function only needs to be passed the Player
					and the board. There are empty pointers being passed to be
					assinged a value
** Post Condition: 	VOID, modifies pointers
********************************************************************************/
void getCoordinate_from(int*, char*, int, char**, int, bool);
/********************************************************************************
** Function: 		getCoordinate_to()
** Description:		gets the second coordinate from user.
					ie. Where would you like to move this token to: F4
** Parameters: 		int*, char*, int rows, char** board, int* First-Coordinate,
					int player, bool
** Pre-Condition:	needs to be passed the first coordinate, player, board, and rows
					other things are empty pointers
** Post Condition: 	VOID, modifies pointers
********************************************************************************/
void getCoordinate_to(int*, char*, int, char**, int*, int, bool);
/********************************************************************************
** Function: 		winner()
** Description:		Checks if someone has won
** Parameters: 		char** board, int rows, int cols
** Pre-Condition:	needs board, rows and cols
** Post Condition: 	boolean
********************************************************************************/
bool winner(char**, int, int);
/********************************************************************************
** Function: 		checkCapture_present()
** Description:		checks if captures are present
** Parameters: 		char** board, int* from-coordinate, int player
** Pre-Condition:	needs the board, first coordinate, and which player is
					taking the turn.
** Post Condition: 	boolean
********************************************************************************/
bool checkCapture_present(char**, int*, int);
/********************************************************************************
** Function: 		moves_present()
** Description:		checks if moves are present()
** Parameters: 		char** board, int* from-coordinate, int player, int rows
** Pre-Condition:	need the board, first coordinate, and which player is
					taking the turn and rows
** Post Condition: 	boolean
********************************************************************************/
bool moves_present(char**, int*, int*, int);
/********************************************************************************
** Function: 		Take_turn
** Description:		takes the turn for player. also checks if moves are present
					using other fucntion.
** Parameters: 		int player, char** board, int rows, int cols, char* dynSTR,
					int* fromCOOR, bool
** Pre-Condition:	needs player taking turn, board, rows, cols, char* empty-string,
					int* from coordinate
** Post Condition: 	VOID, modifies pointers
********************************************************************************/
void Take_turn(int, char**, int, int , char*, int*, bool);
/********************************************************************************
** Function: 		counter()
** Description:		counts the number of occurances a character appears in a 2D
					array
** Parameters: 		char** board, int rows, int cols, char Char-being-searched-for
** Pre-Condition:	needs all the above parameters
** Post Condition: 	returns number of occurances (integer)
********************************************************************************/
int counter(char**, int, int, char);
/********************************************************************************
** Function: 		set_board()
** Description:		sets all tokens for player one and player two on board
** Parameters: 		char** board, int rows, int cols
** Pre-Condition:	needs all the above parameters
** Post Condition: 	VOID, modifies 2d array
********************************************************************************/
void set_board(char**, int, int);
/********************************************************************************
** Function: 		gamestart()
** Description:		Starts the games, alternates between player one and two
** Parameters: 		char** board, int rows, int cols
** Pre-Condition:	needs all the above parameters
** Post Condition:	VOID
********************************************************************************/
void gamestart(char**, int, int);
/********************************************************************************
** Function: 		free_2D_mem()
** Description:		Frees memory on heap used by 2d arrays
** Parameters: 		char**, int rows
** Pre-Condition:	needs double pointer and rows
** Post Condition: 	void
********************************************************************************/
void free_2D_mem(char**, int);
/********************************************************************************
** Function: 		evaluate_board()
** Description:		Evaluates if there are any normal tokens can be made into Kings
					tokens
** Parameters: 		char**board, int rows, int cols
** Pre-Condition:	needs all the above parameters
** Post Condition: 	VOID, modifies 2d array
********************************************************************************/
void evaluate_board(char**, int, int);
/********************************************************************************
** Function: 		Print_board()
** Description:		prints board
** Parameters: 		char** board, int rows, int cols
** Pre-Condition:	needs all the above paramenters
** Post Condition: 	VOID, just prints
********************************************************************************/
void Print_Board(char**, int, int);
/********************************************************************************
** Function: 		Make_board()
** Description:		makes the 2d array. makes the 2d array and assignes it
					to the pointer passed to it
** Parameters: 		char*** array, int rows, int cols
** Pre-Condition:	needs all the above parameters
** Post Condition: 	returns Char**
********************************************************************************/
char**Make_board(char***, int, int);

int main(int argc, char* argv[] = '\0') {
	int rows; int cols;
	if (argc == 2)
		rows = CheckArg(argv[1][0], argv[1][1]);
	else
		rows = Get_int();
	cols = rows;
	char **board;
	board = Make_board(&board, rows, cols);
	for (int i = 0; i < 50; i++)
		std::cout << '\n';
	gamestart(board, rows, cols);
	std::cout << "End of game :) Have a nice holiday" << '\n';
	free_2D_mem(board, rows); //free_1D_mem(*argv);

}
int Get_int(){
	char array[3]; int isvalid; int number = 0;
	do {
		isvalid = 0;
		std::cout << "Enter a and even number greater than 3 \nthis game theoretically scales up to infinty. Provided your window is big enough and text small enough" << '\n';
		std::cout << "Please enter 8, 10, or 12 (or whatever you want, works best with even numbers): ";
		std::cin.getline(array, 10);
		for (int i = 0; array[i] != '\0' ; i++){
			if (!('0' <= array[0] && array[0] <= '9')){
				isvalid = 0; break;}
			if (('0' <= array[i]) && (array[i] <= '9'))
				isvalid++;
			else
				isvalid--;
			}for (int i = 0; i < isvalid; i++) {
				number = (number * 10) + (int (array[i]) - 48);
			} if(!(number > 3)){
				isvalid = 0; number = 0;}
	} while(isvalid  > 1);

	return number;
}
int CheckArg(char tens, char ones){
	std::cout << tens << ones << '\n';
	if (tens == '8')
		return 8;
	else if ((tens == '1') && (ones == '0'))
		return 10;
	else if ((tens == '1') && (ones == '2'))
		return 12;
	else
		return Get_int();
}
void free_1D_mem(int* array){
	delete[]array;
	array = NULL;
}
void free_1D_mem(char* array){
	delete[]array;
	array = NULL;
}
bool isPosiInt_COOR(char* Array){
	for(int i = 1; Array[i] != '\0'; i++)
		if ( !( (Array[i] <= '9') && (Array[i] >= '0') ) ){
			return false;
		}
	return true;
}
bool COOR_token_valid(int player, int* coordinate, char** board, int x = 0, int y = 0){
	x = coordinate[0]; y = coordinate[1];
	if (player == 1){
		if ( (board[x][y] == 'o') || (board[x][y] == 'O') ){
			return true;}
	} if (player == 2){
		if ( (board[x][y] == 'a') || (board[x][y] == 'A') ){
			return true;}
	}return false;
}
bool Plot_the_move(int* toCOOR, int*fromCOOR, char** board){
	int xTo = toCOOR[0]; int yTo = toCOOR[1];
	int xFr = fromCOOR[0]; int yFr = fromCOOR[1];

	board[xTo][yTo] = board[xFr][yFr];
	board[xFr][yFr] = ' ';

	return true;
}
bool KingsMove(char** board, int xTo, int yTo, int xFr, int yFr, int* toCOOR, int* fromCOOR, char KingToken, char EnemyToken = 0, char EnemyKing = 0){
	if 		(KingToken == 'O'){	  EnemyKing = 'A';	 EnemyToken = 'a';}

	else if (KingToken == 'A'){  EnemyKing = 'O';	 EnemyToken = 'o';}
	std::cout << "King Token = " << KingToken << '\n';
	std::cout << "Enemy Token = " << EnemyToken << '\n';
	std::cout << "Enemy King = " << EnemyKing << '\n';
	std::cout << "xFr - 2 = " << xFr -2 << "||" <<xTo << '\n';
	std::cout << "xFr + 2 = " << xFr +2 << "||" <<xTo << '\n';
	std::cout << "yFr - 2 = " << yFr -2 << "||" <<yTo << '\n';
	std::cout << "yFr + 2 = " << yFr +2 << "||" <<yTo << '\n';



	if ((board[xTo][yTo] == ' ' && (yFr + 1 == yTo) && (xFr + 1 == xTo)) ||//Left up
		(board[xTo][yTo] == ' ' && (yFr + 1 == yTo) && (xFr - 1 == xTo)) || //Left down
		 (board[xTo][yTo] == ' ' && (yFr - 1 == yTo) && (xFr + 1 == xTo)) || //Right up
		 (board[xTo][yTo] == ' ' && (yFr - 1 == yTo) && (xFr - 1 == xTo)))  {  //Right down
			 return Plot_the_move(toCOOR, fromCOOR, board);

	}else if  (board[xTo][yTo] == ' ' && (xFr + 2 == xTo) && (yFr + 2 == yTo)){// 2 left, 2 up
		std::cout << "X+, y+" << '\n';
		if ((board[xFr + 1][yFr + 1] == EnemyToken) || (board[xFr + 1][yFr + 1] == EnemyKing)){
				board[xFr + 1][yFr + 1] = ' '; return Plot_the_move(toCOOR, fromCOOR, board);

		}
	}else if  (board[xTo][yTo] == ' ' && (xFr - 2 == xTo) && (yFr + 2 == yTo)){ // 2 right,  up
		std::cout << "X-, y+" << '\n';
		if ((board[xFr - 1][yFr + 1] == EnemyToken) || (board[xFr - 1][yFr + 1] == EnemyKing)){
				board[xFr - 1][yFr + 1] = ' '; return Plot_the_move(toCOOR, fromCOOR, board);
		}
	}else if  (board[xTo][yTo] == ' ' && (xFr + 2 == xTo) && (yFr - 2 == yTo)){ // 2 left, 2 down
		std::cout << "x+, y-" << '\n';
		if ((board[xFr + 1][yFr - 1] == EnemyToken) || (board[xFr + 1][yFr - 1]) == EnemyKing){
				board[xFr + 1][yFr - 1] = ' '; return Plot_the_move(toCOOR, fromCOOR, board);
		}
	}else if  (board[xTo][yTo] == ' ' && (xFr - 2 == xTo) && (yFr - 2 == yTo)){ // 2 right, 2 down
		std::cout << "x-, y-" << '\n';
		if ((board[xFr - 1][yFr - 1] == EnemyToken) || (board[xFr - 1][yFr - 1]) == EnemyKing){
				board[xFr - 1][yFr - 1] = ' '; return Plot_the_move(toCOOR, fromCOOR, board);
		}
	} std::cout << "Return false" << '\n';return false;
	//Technically the large conditional in the first 'if statement' is one line.
	//I have it split up in 3 lines so that it is easier to read.
}
bool PlayerOneMove(char** board, int xTo, int yTo, int xFr, int yFr, int* toCOOR, int* fromCOOR){

	if ((board[xTo][yTo] == ' ') && (yFr + 1 == yTo || yFr - 1 == yTo) && (xFr + 1 == xTo)){
		Plot_the_move(toCOOR, fromCOOR, board);
		return true;
	}if ((board[xTo][yTo] == ' ') && (yFr + 2 == yTo) && (xFr + 2 == xTo)) { //Right
		if ((board[xFr + 1][yFr + 1] == 'a') || (board[xFr + 1][yFr + 1] == 'A')){
			board[xFr + 1][yFr + 1] = ' ';
			return Plot_the_move(toCOOR, fromCOOR, board);

		}
	}if ((board[xTo][yTo] == ' ') && (yFr - 2 == yTo) && (xFr + 2 == xTo)) { //Left
		if ((board[xFr + 1][yFr - 1] == 'a') || (board[xFr + 1][yFr - 1] == 'A')){
			board[xFr + 1][yFr - 1] = ' ';
			return Plot_the_move(toCOOR, fromCOOR, board);

		}
	}
	return false;
}
bool PlayerTwoMove(char** board, int xTo, int yTo, int xFr, int yFr, int* toCOOR, int* fromCOOR){

		if ((board[xTo][yTo] == ' ') && (yFr + 1 == yTo || yFr - 1 == yTo) && (xFr - 1 == xTo)){
			return Plot_the_move(toCOOR, fromCOOR, board);

		}if ((board[xTo][yTo] == ' ') && (yFr + 2 == yTo) && (xFr - 2 == xTo)) { //Right
			if ((board[xFr - 1][yFr + 1] == 'o') || (board[xFr - 1][yFr + 1] == 'O')){
				board[xFr - 1][yFr + 1] = ' ';
				return Plot_the_move(toCOOR, fromCOOR, board);
			}
		}if ((board[xTo][yTo] == ' ') && (yFr - 2 == yTo) && (xFr - 2 == xTo)) { //Left
			if ((board[xFr - 1][yFr - 1] == 'o') || (board[xFr - 1][yFr - 1] == 'O')){
				board[xFr - 1][yFr - 1] = ' ';
				return Plot_the_move(toCOOR, fromCOOR, board);

			}
		}
		return false;
	}
void array_set_null(char* string, int len){
	for (int i = 0; i < len; i++)
		string[i] = '\0';
}
bool COOR_valid_Move(int* fromCOOR, int* toCOOR, char** board, int rows, int player){
	int xTo = toCOOR[0]; int yTo = toCOOR[1]; int xFr = fromCOOR[0]; int yFr = fromCOOR[1];
	if (board[xTo][yTo] == ' '){
			if (player == 1) {
				if (board[xFr][yFr] == 'O'){
					return KingsMove(board, xTo, yTo, xFr, yFr, toCOOR, fromCOOR, 'O'); //King
				}if (board[xFr][yFr] == 'o'){
					return PlayerOneMove(board, xTo, yTo, xFr, yFr, toCOOR, fromCOOR); //normal token
				}
			}else if (player == 2){
				if (board[xFr][yFr] == 'A'){
					return KingsMove(board, xTo, yTo, xFr, yFr, toCOOR, fromCOOR, 'A'); //King
				}if (board[xFr][yFr] == 'a'){
					std::cout << "running PlayerTwoMove" << '\n';
					return PlayerTwoMove(board, xTo, yTo, xFr, yFr, toCOOR, fromCOOR);//normal token
				}
			}
	}
	return false;

}
void getCoordinate_from(int* coordinate, char* dynSTR, int rows, char** board, int player, bool isnotvalid = 0){
	int xnumber, ynumber;
	do {std::cout << "\nPlease enter your the coordinate of the token you'd like to move: ";
		array_set_null(dynSTR, 4); xnumber = 0; ynumber = 0;
		std::cin.getline(dynSTR, 50);
		if  ( 65 <= (int (dynSTR[0]) )  && (int (dynSTR[0]) <= (65 + rows)) ){
			xnumber = (int (dynSTR[0])) - 65;
		}else {isnotvalid = 0; continue;}
		if (isPosiInt_COOR(dynSTR)){
			ynumber = (ynumber * 10) + (int (dynSTR[1])) - 48;
			if (!((dynSTR[2] == '\0') || (dynSTR[2] == ' ')))
				ynumber = (ynumber * 10) + (int (dynSTR[2])) - 48;
			ynumber -= 1;
		}else { isnotvalid = 0; }
		if ((-1 < ynumber) && (ynumber < rows)){
		coordinate[1] = xnumber; coordinate[0] = ynumber;
		isnotvalid = COOR_token_valid(player, coordinate, board);
		}
	} while(!(isnotvalid));
}
void getCoordinate_to(int* coordinate, char* dynSTR, int rows, char** board, int* fromCOOR, int player, bool isnotvalid = 0){
	int xnumber, ynumber;
	do {std::cout << "\nPlease enter the coordinate you'd like to move this Token to:  ";
			array_set_null(dynSTR, 4); xnumber = 0; ynumber = 0;
		   std::cin.getline(dynSTR, 50);
		   if ( 65 <= (int (dynSTR[0]) )  && (int (dynSTR[0]) <= (65 + rows)) ){
			   xnumber = (int (dynSTR[0])) - 65;
		   }else {
			   isnotvalid = 0; continue;
		   }
		   if (isPosiInt_COOR(dynSTR)){
			   ynumber = (ynumber * 10) + (int (dynSTR[1])) - 48;
			   if (!((dynSTR[2] == '\0') || (dynSTR[2] == ' ')))
				   ynumber = (ynumber * 10) + (int (dynSTR[2])) - 48;
			   ynumber -= 1;
		   }else{
			  isnotvalid = 0;
		  }
		   if ((-1 < ynumber) && (ynumber < rows)){
		   coordinate[1] = xnumber; coordinate[0] = ynumber;
		isnotvalid = COOR_valid_Move(fromCOOR, coordinate, board, rows, player);
		}
	} while(!(isnotvalid));
}
bool winner(char** board, int rows, int cols){
	int A = counter(board, rows, cols, 'a'); int O = counter(board, rows, cols, 'o');
	A+= counter(board, rows, cols, 'A'); O+= counter(board, rows, cols, 'O');
	if ( A == O ){
		std::cout << "Currently tied  ||  " << A  << " - " << O<< '\n';
		return false;
	}else if ( A > O ){
		std::cout << "Player 2 is winning  ||  " <<  A << " - " << O << '\n';
		if ( O == 0){
			std::cout << "Player 2 won :)" << '\n';
			return true;
		}return false;
	}else if ( A < O ){
		std::cout << "Player 1 is winning  ||  " <<  O << " - " << A << '\n';
		if ( A == 0 ) {
			std::cout << "Player 1 won :)" << '\n';
			return true;
		} return false;
	}
	return false;
}
bool checkCapture_present(char** board, int* fromCOOR, int player){
	int x = fromCOOR[0]; int y = fromCOOR[1];
	if (player == 1) {
		if (board[x][y] == 'o'){ //How normal tokens move
			if (board[x+2][y+2] == ' ' || board[x+2][y-2] == ' ' &&  (board[x+1][y+1] == 'a' || board[x+1][y-1] == 'a' || board[x+1][y+1] == 'A' ||
			board[x+1][y-1] == 'A'))
			return true;

		}else if (board[x][y] == 'O'){ //How kings move
			if ( (board[x-2][y+2] == ' ' || board[x+2][y+2] == ' ' || board[x-2][y-2] == ' ' || board[x+2][y-2] == ' ')  && // check empty spaces
			  	(board[x-1][y+1] == 'a' || board[x+1][y+1] == 'a' || board[x-1][y-1] == 'a' || board[x+1][y-1] == 'a'  || //check for normal tokens
			  	board[x-1][y+1] == 'A' || board[x+1][y+1] == 'A' || board[x-1][y-1] == 'A' || board[x+1][y-1] == 'A' )){ //check kings
				return true;
			}
		}
	} else if (player == 2) {
		if (board[x][y] == 'a'){
			if (board[x-2][y+2] == ' ' || board[x-2][y-2] == ' ' &&  (board[x-1][y+1] == 'o' || board[x-1][y-1] == 'o' || board[x-1][y+1] == 'O' ||
			board[x-1][y-1] == 'O'))
			return true;

		}else if ( board[x][y] == 'A' ){
			if ( (board[x-2][y+2] == ' ' || board[x+2][y+2] == ' ' || board[x-2][y-2] == ' ' || board[x+2][y-2] == ' ')  && // check empty spaces
			  	(board[x-1][y+1] == 'o' || board[x+1][y+1] == 'o' || board[x-1][y-1] == 'o' || board[x+1][y-1] == 'o'  || //check for normal tokens
			  	board[x-1][y+1] == 'O' || board[x+1][y+1] == 'O' || board[x-1][y-1] == 'O' || board[x+1][y-1] == 'O') ){ //Check for kings
				return true;
			}//Technically, the large conditionals in the 'if statements' are one line.
			// I just wanted to make it easier to read, Hence it is split into 3  lines
		}
	} std::cout << "Testing return false" << '\n';return false;
}
bool moves_present(char** board, int* fromCOOR, int player, int rows){
		int x = fromCOOR[0] ; int y = fromCOOR[1];
		if (player == 1){
			if (board[x][y] == 'o'){
				if  ((x + 1 < rows && y + 1 < rows) || (x + 1 < rows && y - 1 > -1)){
					return true;
				}
			}else if (board[x][y] == 'O'){
				if (((x - 1 > -1)&&(y + 1 < rows)) || ((x + 1 < rows)&&(y + 1 < rows)) || ((x - 1 > -1)&&(y - 1 > -1)) || ((x - 1 > -1)&&(y - 1 > -1))){
					return true;
				}
			}
		}else if(player == 2){
			if (board[x][y] == 'a'){
				if  ((x - 1 > -1 && y + 1 < rows) || (x - 1 > -1 && y - 1 > -1)){
					return true;
				}
			}else if (board[x][y] == 'A'){
				if (((x - 1 > -1)&&(y + 1 < rows)) || ((x + 1 < rows)&&(y + 1 < rows)) || ((x - 1 > -1)&&(y - 1 > -1)) || ((x - 1 > -1)&&(y - 1 > -1))){
					return true;
				}
			}
		}
		return checkCapture_present(board, fromCOOR, player);

}
void Take_turn(int player, char** board, int rows, int cols, char* dynSTR, int* fromCOOR, bool isvalid = 1) {
	int* toCOOR = new int[2]; int PlayerChar; int i; int j;
	if(player == 1) {PlayerChar = 'o';}
	else {PlayerChar = 'a';}
	std::cout << "It\'s player " << player << "\'s turn"<<'\n';
	do {
		if ((counter(board, rows, cols, PlayerChar) != 0)){
			getCoordinate_from(fromCOOR, dynSTR, rows, board, player);
			getCoordinate_to(toCOOR, dynSTR, rows, board, fromCOOR, player);
			isvalid = 0;
		}else{isvalid = 0;}{

		}
	} while(isvalid); free_1D_mem(toCOOR);

}
int counter(char** board, int rows, int cols, char searchFor){
	 int numOoccur = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (board[i][j] == searchFor)
				numOoccur++;

	return numOoccur;
}
void set_board(char** board, int rows, int cols){
	for (int i = 0; i < rows; i++) {
		if (( i + 1  != rows / 2 ) && ( i + 1 != ((rows / 2) + 1) ))
			for(int j = 0; j < cols; j++){
				if ((i % 2 == 1)&& (j % 2 == 1))	  {
						if( i < (rows/2)){  // Player one
							board[i][j] = 'o';  // BLACK
						}else if (i > (rows/2)) {
							board[i][j] = 'a';
						}
					}
				else if ((i % 2 == 0) && (j % 2 == 0)) {
						if( i < (rows/2)){  // Player one
							board[i][j] = 'o';  // BLACK
						}else if (i > (rows/2)) {
							board[i][j] = 'a';
						}
					}
				}
			}
}
void gamestart(char**board, int rows, int cols) {
		int numOplayer = 2; char* dynSTR = new char[4];
		int *dynCoordinate = new int[2];
		set_board(board, rows, cols);
		while (!(winner(board, rows, cols))){
			for (int player = 1; player <= numOplayer; player++){
				evaluate_board(board, rows, cols);
				Print_Board(board, rows, cols);
				Take_turn(player, board, rows, cols, dynSTR, dynCoordinate);
				for (int i = 0; i < 50; i++)
					std::cout << '\n';
			}

		}
			free_1D_mem(dynCoordinate); free_1D_mem(dynSTR);
}
void free_2D_mem(char** array, int rows) {
	for(int i = 0; i < rows; i++){
		delete[](array)[i];
		(*array) = NULL;
	}
	delete[]array;
	array = NULL;
}
void evaluate_board(char** board, int rows, int cols){
	for(int j = 0; j < cols; j++){
		if (board[0][j] == 'a')
			board[0][j] = 'A'; //king for player two is the greek symbol Alpha
		if(board[rows - 1][j] == 'o')
			board[rows - 1][j] = 'O'; //king for player one is the greek symbol Omega
	}
}
void Print_Board(char **board,int rows,int cols){
	std::cout << "    ";
	for(int i = 0; i  < cols; i++){
	   std::cout << "__" <<char (65 + i) << "__";
   }std::cout << '\n';
	for (int i = 0; i < rows; i++){
		std::cout << i + 1 << "  ";  if (i + 1 < 10) std::cout << " ";
		for (int j = 0; j < cols; j++){
			if ((i%2 == 0) && (j%2 == 0))
				std::cout << "|\033[0m " << board[i][j] << ' ';
			else if ((i%2 == 1) && (j%2 == 1))
				std::cout << "|\033[0m " << board[i][j] << ' ';
			else
				std::cout << "| \033[30;47m " << board[i][j];
			std::cout << "\033[0m ";
		}std::cout << "\033[0m| " << '\n' << "----";
		for (int k = 0; k < cols; k++) {
			std::cout << "|----";
		} std::cout << "|" << '\n';
	}
}
char** Make_board(char*** array, int rows, int cols){
	*array = new char*[rows];
	for (int i = 0; i < rows; i++)
	 	(*array)[i] = new char[cols];

	for (int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			(*array)[i][j] = ' ';
	return *array;
}
