#include "business.h"

Business_complex::Business_complex(){
		num_business = (rand()%5) +1;
		if (num_business > 5){num_business == 2;}
		BusInComplex = new person[num_business];
		min_startprice = 400000;
		for (int i = 0; i < num_business; i++){
			initializeBusInComplex(BusInComplex[i]);
		}
		value = (rand()%(max_startprice-min_startprice)) + min_startprice;
		mortgage = ((int(value))/120) +1;
		if(num_business > 3) {size == 'B';}
		if(num_business == 3) {size == 'M';}
		if(num_business < 3) {size == 'S';}


}
Business_complex::Business_complex(int n, person*b){
	min_startprice = 400000;
	num_business = n;
	BusInComplex = b;
}

void Business_complex::initializeBusInComplex(person&C){
	C.Monthly = (rand()%4500) + 501;
	C.agree = 4;
	C.rent = C.Monthly/C.agree;
}


void Business_complex::printinfo(){
	std::cout << "Property Value:       " << value << '\n';
	std::cout << "Property Location:    ";
	if(location == 1) {std::cout << "North West" << '\n';}
	else if(location == 2) {std::cout << "South West" << '\n';}
	else if(location == 3) {std::cout << "Mid-West" << '\n';}
	else if(location == 4) {std::cout << "South East" << '\n';}
	else if(location == 5) {std::cout << "North East" << '\n';}
	std::cout << "Property Mortgage:    " << mortgage << '\n';
	std::cout << "Number of Businesses: " << num_business <<'\n';
}
Business_complex::Business_complex(const Business_complex&O){
	size = O.size;
	num_business = O.num_business;
	if (num_business == 0){
		BusInComplex = NULL;
	}else{
		BusInComplex = new person[num_business];
		for(int i = 0; i < num_business; i++){
			BusInComplex[i].agree = O.BusInComplex[i].agree;
			BusInComplex[i].Monthly = O.BusInComplex[i].Monthly;
			BusInComplex[i].rent = O.BusInComplex[i].rent;
		}
	}
}

Business_complex::~Business_complex(){
	if(BusInComplex != NULL)
		delete[]BusInComplex;
	BusInComplex = NULL;
}

const Business_complex& Business_complex::operator=(const Business_complex&O){
	size = O.size;
	// std::cout << "1" << '\n';
	std::cout << num_business << " num_business "<< O.num_business<<'\n';

	num_business = O.num_business;
	std::cout << "num_business"<< O.num_business<<'\n';
// std::cout << "2" << '\n';
	// delete[]BusInComplex;
	// BusInComplex == NULL;
	 if(BusInComplex != NULL){
		 // std::cout << "2.1" << '\n';
		 delete [] BusInComplex;
		 // std::cout << "2.2" << '\n';
	 }
// std::cout << "3" << '\n';
	if(num_business == 0){
		// std::cout << "4" << '\n';
		BusInComplex == NULL;
		// std::cout << "5" << '\n';
	}else{
		// std::cout << "6" << '\n';
	//	delete[]BusInComplex;
		// std::cout << "7" << '\n';
		BusInComplex = new person[num_business];
		// std::cout << "here" << '\n';
		for (int i = 0; i < O.num_business; i++){
			// std::cout << 7+1+i << '\n';
			BusInComplex[i] = O.BusInComplex[i];
		//	BusInComplex[i].agree = O.BusInComplex[i].agree;
			// std::cout << 7+2+i << '\n';

		//	BusInComplex[i].Monthly = O.BusInComplex[i].Monthly;
		//	std::cout << 7+3+i << '\n';

		//	BusInComplex[i].rent = O.BusInComplex[i].rent;
		//	std::cout << 7+4+i << '\n';

		}

	}

	// std::cout << "Seg before this" << '\n';
	return *this;
}
