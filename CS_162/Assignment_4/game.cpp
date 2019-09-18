
#include "./game.h"

using std::vector;

Game::Game(){
	food = 50;

}
Game::~Game(){
	for(int i  = 0; i <  10; i++){
		// M[i].erase(M[i].begin(), M[i].end());
		// M[i].clear();
		if(M[i].size() != 0)
			for(int j = 0; j < M[i].size(); j++){
				if(M[i][j] != NULL){
					delete[]((M[i][j]));
					(M[i][j]) = NULL;
				}
				// M[i].erase(M[i].begin(), M[i].end());
				// M[i].clear();
			}
	}

}
void Game::setBoard(vector< vector <Bug*> > M){
	this->M = M;
}
void Game::printBoard(){
	std::cout << "\n\n";
	std::cout << "-----Food - " << food << "-----" <<'\n';
	for(int i  = 0; i <  10; i++){
		if(i < 9) {std::cout << " ";}
		std::cout << i + 1 << " |  ";
		if(M[i].size() != 0){
			for(int j = 0; j < M[i].size(); j++){
				std::cout << M[i][j]->Return_type();
				std::cout << " | ";
			}
		}
		std::cout << '\n';
	}
	std::cout << "\n\n\n";
}
bool Game::lose(){
	vector<Bug*> ::iterator jtr;
	vector<Bug*> ::iterator jtrBEG;
	vector<Bug*> ::iterator jtrEND;

	vector< vector<Bug*> > ::iterator itr;
	int countB = 0;
	itr = M.end();
	jtrBEG = (*itr).begin();
	// std::cout << "seg1" << '\n';
	jtrEND = (*itr).end();
	for(int i = 0; i < M[9].size(); i++)
			if(M[9].at(i)->Return_type() == 'B')
				countB++;



	// std::cout << "countB = " << countB << '\n';

	if(countB > 0)
		return true;

	return false;

}
bool Game::win(){
	vector<Bug*> ::iterator jtr;
	vector< vector<Bug*> > ::iterator itr;
	int countA = 0;
	itr = M.begin();
	for(int i = 0; i < M[0].size(); i++)
			if(M[0].at(i)->Return_type() != 'B')
				countA++;
	// std::cout << "CountA" << countA << '\n';
	// printBoard();
	if(countA > 0)
		return true;

	return false;

}
void Game::printoptions(){
	std::cout << "Option | Ant               | Cost " << '\n';
	std::cout << "1      | Harvester Ant     | 2" << '\n';
	std::cout << "2      | Bodyguard Ant     | 4" << '\n';
	std::cout << "3      | Wall Ant          | 4" << '\n';
	std::cout << "4      | Thrower Ant       | 4" << '\n';
	std::cout << "5      | Short Thrower Ant | 3" << '\n';
	std::cout << "6      | Long Thrower Ant  | 3" << '\n';
	std::cout << "7      | Ninja Ant         | 6" << '\n';
	std::cout << "8      | Fire Ant          | 4" << '\n';
	std::cout << "To skip this turn enter 9" << '\n';
}
bool Game::checkifBlock(int ant, int place){
	if(M[place].size() == 0){
		return false;
	}else if(M[place].size() > 0){
		for(int i = 0; i < M[place].size(); i++)
			if(M[place][i]->Return_type() == 'B'){
				std::cout << "Can't place an ant where there is a Bee" << '\n';
				return true;}
	}if(ant == 2 && M[place].size() > 0){
		for(int i = 0; i < M[place].size(); i++)
			if(M[place][i]->Return_type() == 'G' || M[place][i]->Return_type() == 'B'){
				std::cout << "Cant place two Bodyguard Ants on the same block" << '\n';
				return true;}
	}
}

int Game::getinput(int L, int U){
	char input[10];
	do{
		std::cout << "Enter a number: ";
		std::cin >> input;
	}while(!(L <=  atoi(input) && atoi(input) <= U));
	return atoi(input);
}
void Game::placeAnt(int ant, int place){
	if(ant == 1){
		Harvest *H = new Harvest; M[place].push_back(H);

	}else if(ant == 2){
		Bodyguard *G = new Bodyguard; M[place].push_back(G);

	}else if(ant == 3){
		Wall *W = new Wall; M[place].push_back(W);

	}else if(ant == 4){
		Thrower *T = new Thrower; M[place].push_back(T);

	}else if(ant == 5){
		Short_Throw *S = new Short_Throw; M[place].push_back(S);

	}else if(ant == 6){
		Long_Throw *L = new Long_Throw; M[place].push_back(L);

	}else if(ant == 7){
		Ninja *N = new Ninja; M[place].push_back(N);

	}else if(ant == 8){
		Fire *F = new Fire; M[place].push_back(F);

	}
}
bool Game::checkFoodCost(int choice){
	int cost = 0;
	if(choice == 1) cost = 2;
	else if (choice == 2) cost = 4;
	else if (choice == 3) cost = 4;
	else if (choice == 4) cost = 4;
	else if (choice == 5) cost = 3;
	else if (choice == 6) cost = 3;
	else if (choice == 7) cost = 6;
	else if (choice == 8) cost = 4;
	if(food-cost >= 0){
		food -= cost;
		return true;
	}return false;
}
void Game::getAnt(){
	// Harvest *A1 = new Harvest;
	printoptions();
	std::cout << "Which ant would you like to pick?" << '\n';
	int input; int input2;
	do {
		input = getinput(1,9);
	} while(!(checkFoodCost(input)));
	std::cout << "Where would you like to place this ant?" << '\n';
	if(input != 9){
		do{
			input2 = getinput(1, 10);
			input2--;
			// std::cout << "Ant " << input2 << '\n';
			// std::cout << "Place " << input <<'\n';
		}while((checkifBlock(input, input2) == true));
		placeAnt(input, input2);
	}else{
		std::cout << "You skipped this turn :(" << '\n';
	}


}
void Game::makebee(){
	Bee *B1 = new Bee;
	M[0].push_back(B1);

}
void Game::movebee(){
	vector<Bug*>::iterator jitr;
	int countA = 0;
	int countB = 0;
	for(int i = M.size()-1; i > -1; i--){
		for(int k = 0; k < M[i].size(); k++)
			if(M[i].at(k)->Return_type() == 'B'){
				countB++;
			}else if(M[i].at(k)->Return_type() != 'B' && M[i].at(k)->Isvisible()){
				countA++;
			}
		if(countA == 0 && countB > 0){
			for(int j = 0; j < M[i].size(); j++){
				if(M[i].at(j)->Return_type() == 'B'){
					if(i < 10){
						Bee *B1 =  new Bee;
						M[i+1].push_back(B1);
						delete[](M[i][j]); M[i][j] = NULL;
						M[i].erase((M[i].begin() + j));
					}
				}
			}
		}
			countA = 0; countB = 0;
	}
}
bool Game::OneRangeAttackALL(int i){
	bool attackdone = 0;
	for(int j = 0; j < M[i].size(); j++){
		if(M[i][j]->Return_type() == 'B'){
			std::cout << "Called for "<< M[i][j]->Return_type() <<  " at M[" << i << "]["<< j << "]" <<'\n';
			M[i][j]->Attacked(1);
			attackdone = 1;
		}
	}
	return attackdone;
}
bool Game::OneRangeAttack(int i){
	bool attackdone = 0;
	for(int j = 0; j < M[i].size(); j++){
		if(M[i][j]->Return_type() == 'B'){
			std::cout << "Called for "<< M[i][j]->Return_type() <<  " at M[" << i << "]["<< j << "]" <<'\n';
			M[i][j]->Attacked(1);
			attackdone = 1;
			break;
		}
	}
	return attackdone;
}
void Game::TwoRangeAttack(int i){
	bool attackdone = 0;
	attackdone = OneRangeAttackALL(i);
	if( (!(attackdone)) && (i - 1 > 0))
		attackdone = OneRangeAttackALL(i-1);
	else if( (!(attackdone)) && (i-2 > 0))
		attackdone = OneRangeAttackALL(i-2);
}
void Game::FourRangeAttack(int i){
	bool attackdone = 0;
	attackdone = OneRangeAttack(i);
	if( (!(attackdone)) && (i -1 > 0))
		attackdone = OneRangeAttack(i-1);
	else if( (!(attackdone)) && (i-2 > 0))
		attackdone = OneRangeAttack(i-2);
	if( (!(attackdone)) && (i-3 >  0))
		attackdone = OneRangeAttack(i-3);
	else if( (!(attackdone)) && (i - 4 > 0))
		attackdone = OneRangeAttack(i-4);
}
void Game::AntBlowsUp(int i, int j){
		for(int k = 0; k < M[i].size(); k++)
			if(M[i][k]->Return_type() == 'B'){
				M[i][k]->Attacked(500);
			}
}
void Game::ProtectedAttack(int i, int j){
	std::cout << "BodyGuard makes peice attack on death" << '\n';
	if(M[i][j]->gethealth() <= 0)
	for(int i = 0; i < M.size(); i++){
		if(M[i].size() != 0){
			for(int j = 0; j < M[i].size(); j++){
				char temp = M[i][j]->Return_type();
				if(temp != 'B' && temp != 'H' && temp != 'W'){
					if(temp == 'T' || temp == 'N')
						OneRangeAttack(i);
					else if(temp == 'S')
						TwoRangeAttack(i);
					else if(temp == 'L')
						FourRangeAttack(i);
					else if(temp == 'F')
						AntBlowsUp(i, j);
				}
			}
		}
	}
}
void Game::AntActions(){
	for(int i = 0; i < M.size(); i++){
		if(M[i].size() != 0){
			for(int j = 0; j < M[i].size(); j++){
				char temp = M[i][j]->Return_type();
				if(temp != 'B'){
					if(temp == 'T' || temp == 'N')
						OneRangeAttack(i);
					else if(temp == 'S')
						TwoRangeAttack(i);
					else if(temp == 'L')
						FourRangeAttack(i);
					else if(temp == 'H')
						food++;
				}
			}
		}
	}
}
bool Game::checkforbodyguard(int i){
	std::cout << "Ran" << '\n';
	for(int j = 0; j < M[i].size(); j++)
		if(M[i][j]->Return_type() == 'G')
			return true;
	return false;

}
void Game::BeeAttack(){
	int countA = 0;
	int countB = 0;
	bool foundBodyguard = 0;
	for(int i = 0; i < M.size(); i++){
		if(M[i].size() != 0){
			for(int j = 0; j < M[i].size(); j++){
				if(M[i][j]->Return_type() == 'B')
					countB++;
				else
					countA++;
			}
			//Counted up number of Bees and Ants
			// int k;
			if(countA > 0 && countB > 0){
				for(int k = 0; k < M[i].size(); k++){
					if(M[i][k]->Return_type() == 'B'){
						foundBodyguard = checkforbodyguard(i);
						for(int l = 0; l < M[i].size(); l++){
							// M[i][l]->Attacked();
							if(M[i][l]->Return_type() == 'G'){
								M[i][l]->Attacked();
								// break;
							}else if(M[i][l]->Return_type() != 'B' && M[i][l]->Return_type() != 'G'
									 && !(foundBodyguard)){
								M[i][l]->Attacked();
								// break;
							}

						}
					}
				}
			}
		}
	}
}
void Game::EvaluateBugs(){
	for(int i = 0; i < M.size(); i++)
		if(M[i].size() != 0)
			for(int j = 0; j < M[i].size(); j++){
				// std::cout << M[i][j]->Return_type() << M[i][j]->gethealth() << '\n';
				if(M[i][j]->gethealth() <= 0){
					char temp = M[i][j]->Return_type();
					if(temp == 'G')
						ProtectedAttack(i, j);
					else if (temp = 'F')
						AntBlowsUp(i, j);

					delete[](M[i][j]); M[i][j] = NULL;
					M[i].erase((M[i].begin() + j));
				}
			}
}
void Game::PrintEmptySpaces(int count){
	for (int i = 0; i < count; i++) {
		std::cout << '\n';
	}
}
void Game::playgame(int x){
	// Harvest *A1 = new Harvest;
	// Ninja *A2 = new Ninja;
	// Long_Throw *A3 = new Long_Throw;
	// Long_Throw *A4 = new Long_Throw;
	// Bodyguard *A5 = new Bodyguard;
	// Fire *A6 = new Fire;
	// Bodyguard *A7 = new Bodyguard;
	// M[8].push_back(A2);
	// M[8].push_back(A3);
	// M[9].push_back(A4);
	// M[6].push_back(A5);
	// M[6].push_back(A6);
	// M[6].push_back(A7);
	// M[6].push_back(A1);
	printBoard();
	char xit; int i = 0; int easymode = 1 + x;
	while (!(win())){
		EvaluateBugs();
		getAnt(); i++;
		movebee();
		if(i%easymode == 0){makebee();}
		BeeAttack();
		AntActions();
		std::cout << "Enter 0 to exit" << '\n';
		std::cin >> xit;
		if (xit == '0')
			break;
		 if(lose()){
			printBoard();
			std::cout << "\n\nYou lose :(\n" << '\n';
			break;}
		// PrintEmptySpaces(35);
		printBoard();
	}
	if(win()){ std::cout << "\n\nYou win :)\n" << '\n';}

}
