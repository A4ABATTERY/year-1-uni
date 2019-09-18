#include "house.h"

House::House(){
	min_startprice = 100000;
	initializeTenant(tenant);
	// std::cout << "House tenants = " << tenant[0].Monthly << '\n';
	value = (rand()%(600000-min_startprice)) + min_startprice;
	mortgage = ((int(value))/120) +1;

}
House::House(person T){
	min_startprice = 100000;
	tenant = T;
}

void House::initializeTenant(person&C){
	C.Monthly = (rand()%4500) + 501;
	C.agree = 4;
	C.rent = C.Monthly/C.agree;
}


House::House(const House&O){
	tenant = O.tenant;
}

void House::printinfo(){
	std::cout << "Property Value:       " << value << '\n';
	std::cout << "Property Location:    ";
	if(location == 1) {std::cout << "North West" << '\n';}
	else if(location == 2) {std::cout << "South West" << '\n';}
	else if(location == 3) {std::cout << "Mid-West" << '\n';}
	else if(location == 4) {std::cout << "South East" << '\n';}
	else if(location == 5) {std::cout << "North East" << '\n';}
	std::cout << "Property Mortgage:    " << mortgage << '\n';

}
const House& House::operator=(const House&O){
	tenant = O.tenant;
}
