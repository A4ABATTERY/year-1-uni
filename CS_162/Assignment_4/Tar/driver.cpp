#include "game.h"

int main(){
		vector < vector<Bug*> > M(10);
		Game game;
		char input;
		do {
			std::cout << "Would you like to play in Easy Mode?" << '\n';
			std::cout << "Enter 1 for Easy, 0 for Hard: ";
			std::cin >> input;
		} while(!(input == '0' || input == '1'));
		game.setBoard(M);
		game.playgame(input-48);

}
