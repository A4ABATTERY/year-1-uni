#include "Player.h"


Player::Player(){
	bank = 500000;
	H_Arr = NULL; numH = 0;
	A_Arr = NULL; numA = 0;
	B_Arr = NULL; numB = 0;
	H_O_Arr = NULL;	numHowned = 0;
	A_O_Arr = NULL; numAowned = 0;
	B_O_Arr = NULL; numBowned = 0;
	subsPerMonth = 0;
}
Player::Player(int m, House*h, Apartment*a, Business_complex*b, House*H, Apartment*A, Business_complex*B, int Ha, int Aa, int Ba, int Ho, int Ao, int Bo){
	bank = m;
	H_Arr = h; numH = 3;
	A_Arr = a; numA = 3;
	B_Arr = b; numB = 3;
	H_O_Arr = H; numHowned = Ho;
	A_O_Arr = A; numAowned = Ao;
	B_O_Arr = B; numBowned = Bo;
	subsPerMonth = 0;
}
Player::~Player(){
	if (numHowned != 0)
		delete[]H_O_Arr;
	if (numAowned != 0)
		delete[]A_O_Arr;
	if (numBowned != 0)
		delete[]B_O_Arr;


}
void Player::setArrays(House*H, Apartment*A, Business_complex*B, int Ha, int Aa, int Ba){
	numH = Ha;
	H_Arr = H;
	numA = Aa;
	A_Arr = A;
	numB = Ba;
	B_Arr = B;

}
void Player::gamestart(){
	int Choice = 0;
	do{
		std::cout << "YOU BANK ACCOUNT = " << bank <<  '\n';
		printoptions();
		Choice = getchoice(0,6);
		switch (Choice) {
			case 1:
				viewProperties();
				break;
			case 2:
				Buyproperty();
				counter();
				break;
			case 3:
				std::cout << "sell property" << '\n';
				counter();
				break;
			case 4:
				viewOwned();
				break;
			case 5:
				std::cout << "Change rent" << '\n';
				counter();
				break;
			case 6:
				std::cout << "Nothing done this month" << '\n';
				counter();
				break;
			case 0:
				break;

		}
		std::cout << "Mortgage Payments = " << subsPerMonth << '\n';

		bank += subsPerMonth;
	}while(!(bankrupt() || Choice == 0));
	if(Choice == 0)
		std::cout << "Game Quit by user" << '\n';
	else
		if(bankrupt())
			std::cout << "Your went bankrupt :(" << '\n';
		else
			std::cout << "You win :)" << '\n';
}

void Player::viewProperties(){

	for(int i = 0; i < numH; i++){
		std::cout << "---------------------------------" << '\n';
		std::cout << "House " << i+1 << "\n";
		H_Arr[i].printinfo();
		std::cout << '\n';
	}
	for(int i = 0; i < numA; i++){
		std::cout << "---------------------------------" << '\n';
		std::cout << "Apartment " << i+1 << "\n";
		A_Arr[i].printinfo();
		std::cout << '\n';
	}for(int i = 0; i < numB; i++){
		std::cout << "---------------------------------" << '\n';
		std::cout << "Busines Complex " << i+1 << "\n";
		B_Arr[i].printinfo();
		std::cout << '\n';
	}
}
bool Player::bankrupt(){
	if(bank == 0)
		return true;
	return false;
}
int Player::getchoice(int L, int U){
	std::string str;
	do{
		std::cout << "Please enter a number " << L << '-' << U <<": ";
		std::cin >> str;
		std::cout << '\n';
	}while(!((L <= atoi(str.c_str()) && atoi(str.c_str()) <= U)));
	return atoi(str.c_str());
}
void Player::printoptions(){
	std::cout << "Quit game:                  0" << '\n';
	std::cout << "View availible properties:  1" << '\n';
	std::cout << "Buy a property:             2" << '\n';
	std::cout << "Sell a property:            3" << '\n';
	std::cout << "View properties you own:    4" << '\n';
	std::cout << "Change rent:                5" << '\n';
	std::cout << "Skip this month:            6" << '\n';
}
std::string Player::getbuildingtype(){
	std::string temp;
	do{
	std::cin >> temp;
	if((temp.compare("House") == 0) || (temp.compare("house") == 0))
		return temp;
	else if((temp.compare("Apartment") == 0) || (temp.compare("apartment") == 0))
		return temp;
	else if((temp.compare("Business") == 0) || (temp.compare("business") == 0))
		return temp;
	else if((temp.compare("Skip") == 0) || (temp.compare("skip") == 0))
		return temp;
	else
		std::cout << "Please make sure you spell the building type correctly: ";
	}while(true);
}
void Player::Buyproperty(){
	viewProperties();
	std::cout << "You may type skip, to skip this month(turn)" << '\n';
	std::cout << "What type of property would you like to buy?: ";
	std::string temp = getbuildingtype(); int choice;
	std::cout << "There are currently 3 " << temp << "\'s" <<'\n';
	std::cout << "For the " << temp << " that you want, ";
	choice = getchoice(1, 3);
	if((temp.compare("House") == 0) || (temp.compare("house") == 0))
		ResizeArrayADD(H_Arr, choice);
	else if((temp.compare("Apartment") == 0) || (temp.compare("apartment") == 0))
		ResizeArrayADD(A_Arr, choice);
	else if((temp.compare("Business") == 0) || (temp.compare("business") == 0))
		ResizeArrayADD(B_Arr, choice);
}
void Player::viewOwned(){
	if(numHowned != 0){
		for(int i = 0; i < numHowned; i++){
			std::cout << "---------------------------------" << '\n';
			std::cout << "House " << i+1 << "\n";
			H_O_Arr[i].printinfo();
			std::cout << '\n';
		}

	}if (numAowned != 0){
		for(int i = 0; i < numAowned; i++){
			std::cout << "---------------------------------" << '\n';
			std::cout << "Apartment " << i+1 << "\n";
			A_O_Arr[i].printinfo();
			std::cout << '\n';
		}
	}if(numBowned != 0){
		for(int i = 0; i < numBowned; i++){
			std::cout << "---------------------------------" << '\n';
			std::cout << "Busines Complex " << i+1 << "\n";
			B_O_Arr[i].printinfo();
			std::cout << '\n';
		}
		std::cout << "\n\n" << '\n';
	}if (numHowned == 0 && numAowned == 0 && numBowned == 0){
		std::cout << "\n\nYou own no properties :(\n " << '\n';
	}

}


void Player::ResizeArrayADD(House*Arr, int i){
	if(H_O_Arr == NULL){
		numHowned++;
		House* temp = new House[numHowned];
		temp[0] = Arr[i];
		H_O_Arr = temp;
	}else if(H_O_Arr != NULL && numHowned != 0){
		House* temp = new House[numHowned+1];
		for(int j = 0 ; j < numHowned; j++){
			temp[j] = H_O_Arr[j];
		}
		numHowned++;
		temp[numHowned-1] = Arr[i];
		delete[]H_O_Arr;
		H_O_Arr = new House[numHowned];
		for(int j = 0; j < numHowned; j++){
			H_O_Arr[j] = temp[j];
		}
		 delete[]temp; temp == NULL;
	}

	subsPerMonth -= Arr[i].getMortgage();
	removefmrMarket(H_Arr, i);

}

void Player::ResizeArrayADD(Apartment*Arr, int i){
	if(A_O_Arr == NULL){
		numAowned++;
		Apartment* temp = new Apartment[numAowned];
		// std::cout << "Seg afte this" << '\n';
		temp[0] = Arr[i];
		A_O_Arr = temp;
		// std::cout << "Seg after thsi" << '\n';
	}else if(A_O_Arr != NULL && numAowned != 0){
		Apartment* temp = new Apartment[numAowned+1];
		// std::cout << "Seg after this1" << '\n';
		for(int j = 0 ; j < numAowned; j++){
			temp[j] = A_O_Arr[j];
		}
		// std::cout << "Seg after thsi" << '\n';
		numAowned++;
		temp[numAowned-1] = Arr[i];
		delete[]A_O_Arr;
		// std::cout << "Seg after this" << '\n';
		A_O_Arr = new Apartment[numAowned];
		for(int j = 0; j < numAowned; j++){
			A_O_Arr[j] = temp[j];
		}
		 delete[]temp; temp == NULL;
	}
	// std::cout << "Seg after thsi" << '\n';

	subsPerMonth -= Arr[i].getMortgage();
	removefmrMarket(A_Arr, i);
}
void Player::ResizeArrayADD(Business_complex*Arr, int i){
	if(B_O_Arr == NULL){
		numBowned++;
		Business_complex* temp = new Business_complex[numBowned];
		temp[0] = Arr[i];
		B_O_Arr = temp;
	}else if(B_O_Arr != NULL && numBowned != 0){
		Business_complex* temp = new Business_complex[numBowned+1];
		for(int j = 0 ; j < numBowned; j++){
			temp[j] = B_O_Arr[j];
		}
		numBowned++;
		temp[numBowned-1] = Arr[i];
		delete[]B_O_Arr;
		B_O_Arr = new Business_complex[numBowned];
		for(int j = 0; j < numBowned; j++){
			B_O_Arr[j] = temp[j];
		}
	 	delete[]temp; temp == NULL;
	}

	subsPerMonth -= Arr[i].getMortgage();
//	removefmrMarket(B_Arr, i);
}
void Player::removefmrMarket(House*Arr, int i){
	House* temp = new House[numH-1];
	for(int j = 0; j < i; j++)
		temp[j] = H_Arr[j];
	for(int j = i; j < numH;j++){
		temp[j] = H_Arr[j+1];}
	delete[]H_Arr;
	numH--;
	if(numH != 0){
	H_Arr = new House[numH];
	for(int j = 0; j < numH; j++)
		H_Arr[j] = temp[j];
	}else{
		numH = 3;
		H_Arr = new House[numH];
	}

}
void Player::removefmrMarket(Apartment*Arr, int i){
	// std::cout << "Ran" << '\n';
	Apartment* temp = new Apartment[numH-1];
	for(int j = 0; j < i; j++)
		temp[j] = A_Arr[j];
	for(int j = i; j < numA;j++){
		temp[j] = A_Arr[j+1];}
	delete[]A_Arr;
	numA--;
	if(numA != 0){
	A_Arr = new Apartment[numH];
	// std::cout << "Seg heres" << '\n';
	for(int j = 0; j < numA; j++)
		A_Arr[j] = temp[j];
	// std::cout << "seg here" << '\n';
	}else{
		numA = 3;
		A_Arr = new Apartment[numH];
	}

}
void Player::removefmrMarket(Business_complex*Arr, int i){
	Business_complex* temp = new Business_complex[numH-1];
	for(int j = 0; j < i; j++)
		temp[j] = B_Arr[j];
	for(int j = i; j < numB;j++){
		temp[j] = B_Arr[j+1];}
	delete[]B_Arr;
	numB--;
	if(numB != 0){
	//	std::cout << "Ran" << '\n';
	B_Arr = new Business_complex[numB];
	for(int j = 0; j < numB; j++)
		B_Arr[j] = temp[j];
	}else{
		numB = 3;
		B_Arr = new Business_complex[numB];
	}
}



void Player::counter(){
	static int count = 0;
	count++;
	std::cout << "\nMonths passed: " << count << '\n';
}
