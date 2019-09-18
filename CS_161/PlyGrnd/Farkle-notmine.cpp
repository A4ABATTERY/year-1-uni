# include <iostream>
# include <cstdlib>
# include <ctime>
using namespace std;

int rolls[6];
int score = 0, turn = 0, bank = 0, total = 0, option = 1;
int num_of_dice = 6;
string player1, player2;
bool triplez = true;
bool game = true;

void rolldie(int a[]){
srand(time(0));
	for(int i = 0; i < 6; i++){
 		  a[i] = rand() % 6 + 1;
    }
}

void bubblesort(int b[]) {

	for(int j = 5; j >= 0; j--) {
		for(int k= 0; k < j; k++){
			if(rolls[k] > rolls[k + 1]) {
               	int temp = b[k];
			    b[k] = b[k + 1];
			    b[k + 1] = temp;
		    }
		}

	}
}

void print(int c[]) {

	rolldie(rolls);
    bubblesort(rolls);

	for(int i = 0; i< 6; i++){
	    cout << rolls[i];
    }
}

bool singles() {
	for(int i = 0; i < 6; i++) {
		if(rolls[i] == 1){
			score += 100;
			num_of_dice--;
			return true;
		}

		else if (rolls[i] == 5) {
			score += 50;
			num_of_dice--;
			return true;
		}
	}

	return false;
}

bool triples() {
	for(int i = 0; i < 4; i++) {
		if(rolls[i] == rolls[i + 1] && rolls[i + 1] == rolls[i + 2])
					num_of_dice-=3;
					return true;
	}

	return false;
}

bool fourofakind() {
	for(int i = 0; i < 3; i++) {
		if(rolls[i] == rolls[i + 3] )
					return true;
	}

	num_of_dice-=4;
	return false;
}

bool twotriples() {

	if((rolls[0] == rolls[1] && rolls[0] == rolls[2]) && (rolls[3] == rolls[4] && rolls[3] == rolls[5])) {
				 num_of_dice-=6;
				 return true;
    }

	return false;
}

bool threepairs() {
	for(int i = 0; i < 5; i+=2) {
		if(rolls[i] != rolls[i+1]) {
			return false;
	    }
	}

	num_of_dice-=6;
	return true;
}

bool fiveofakind() {

	for(int i = 0; i < 4; i++) {
		if(rolls[i] == rolls[i+1] && rolls[i + 1] == rolls[i + 2]) {
			return true;
	    }
	}
    num_of_dice-=5;
	return false;
}

bool sixofakind() {

	for(int i = 0; i < 5; i++) {
		if(rolls[i] != rolls[i + 1])
			return false;
	}

	num_of_dice-=6;
	return true;
}

bool straight() {
	 for(int i = 0; i < 5; i++) {
	 	if(rolls[i] + 1 != rolls[i + 1])
	 				return false;
	 }

	 num_of_dice-=6;
	 return true;

}
void reset () {
	for(int i = 0; i < 6; i++) {
		rolls[i] == 0;
	}
}

void roll(int a) {

	for(int i = 0; i < a; i++) {
		rolls[i] = rand() % 6 + 1;
        bubblesort(rolls);
		cout << rolls[i];
	}
}

int main() {

	srand(time(0));

	cout << "*********************** Welcome to Farkle *************************\n\n";

    	cout << "You rolled..." << endl;
        print(rolls);
        while(option == 1) {
			cout << "Score: " << score << '\n';

            if(straight() == true) {
         		  	 score += 1500;
                     cout << "\nYou got a straight" << endl;
        			 cout << "You scored " << score << endl;
            }

        	else if(sixofakind() == true) {
         		 score += 3000;
         		 cout << "\nYou got six of a kind" << endl;
          		 cout << "You scored " << score << endl;
            }

        	else if(fiveofakind() == true) {
        	 	 score += 2000;
         		 cout << "\nYou got five of a kind" << endl;
          		 cout << "You scored " << score << endl;
            }

        	else if(threepairs() == true) {
         		 score += 1500;
         		 cout << "\nYou got three pairs" << endl;
          		 cout << "You scored " << score << endl;
            }

        	else if(twotriples() == true) {
         		 score += 2500;
         		 cout << "\nYou got two triples" << endl;
          		 cout << "You scored " << score << endl;
            }

        	else if(fourofakind() == true) {
        		  score += 1000;
          		  cout << "\nYou got four of a kind" << endl;
          		  cout << "You scored " << score << endl;
            }

        	else if(triples() == true) {

        	}
            else if(singles() == true) {
        	 	  cout << "\nYou got singles" << endl;
            }

            cout << "Enter 1 to re-roll or 2 to bank" << endl;
            cin >> option;

          if(option == 1)
	      	    roll(num_of_dice);

        }

		if(option == 2) {
		          total += score;
		          cout << "Your bank has " << total << endl;
		}

    }
