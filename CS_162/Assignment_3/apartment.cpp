#include "apartment.h"
/*
class Apartment : public Building{
	private:

	public:
		Apartment();
		Apartment(float val, int loc,float mort,int numT, person* T);

};*/
void Apartment::initializeTenant(person&C){
	C.Monthly = (rand()%4500) + 501;
	C.agree = 4;
	C.rent = C.Monthly/C.agree;
}
Apartment::Apartment(){
	min_startprice = 300000;
	num_tenants = ((rand())%10) +1;
	tenants = new person[num_tenants];
	// std::cout << "numTen DefConstr/uct " << num_tenants<< '\n';
	for (int i = 0; i < num_tenants; i++){
		initializeTenant(tenants[i]);
	}
	value = (rand()%(max_startprice-min_startprice)) + min_startprice;
	mortgage = ((int(value))/120) +1;


	// std::cout << num_tenants << '\n';
	// std::cout << tenants[1].Monthly << '\n';
}
Apartment::Apartment(person* T, int t){
	tenants = T;
	num_tenants = t;
}


Apartment::Apartment(const Apartment&O){
	value = O.value;
	location = O.location;
	mortgage = O.mortgage;
	value = O.value;
	location = O.location;
	mortgage = O.location;
	owned = O.owned;
	num_tenants = O.num_tenants;
	if(num_tenants == 0){
		tenants = NULL;
	}else{
		tenants = new person[num_tenants];
		for(int i = 0; i < num_tenants; i++){
			tenants[i].agree = O.tenants[i].agree;
			tenants[i].Monthly = O.tenants[i].Monthly;
			tenants[i].rent = O.tenants[i].rent;
		}
	}
}
Apartment::~Apartment(){
	if(tenants != NULL)
		delete[]tenants;
	tenants = NULL;

}
void Apartment::printinfo(){
	std::cout << "Property Value:       " << value << '\n';
	std::cout << "Property Location:    ";
	if(location == 1) {std::cout << "North West" << '\n';}
	else if(location == 2) {std::cout << "South West" << '\n';}
	else if(location == 3) {std::cout << "Mid-West" << '\n';}
	else if(location == 4) {std::cout << "South East" << '\n';}
	else if(location == 5) {std::cout << "North East" << '\n';}
	std::cout << "\nProperty Mortgage:    " << mortgage << '\n';
	std::cout << "Number of Tenants:    " << num_tenants <<'\n';
}
const Apartment& Apartment::operator=(const Apartment&O){
	// std::cout << "Called Apart overload" << '\n';
	num_tenants = O.num_tenants;
	if(tenants != NULL)
		delete[]tenants;
	if(num_tenants == 0){
		tenants = NULL;
	}else{
		tenants = new person[O.num_tenants];
		// std::cout << "for 0 " << '<'<< num_tenants << "OR"<< O.num_tenants<< '\n';
		for(int i = 0; i < O.num_tenants; i++){
			tenants[i] = O.tenants[i];
		}
	}
}
