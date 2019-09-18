#include "functions.h"
#include <cstdlib>
#include <iostream>
#include <string>

using std::string;

void progStart(restaurant &R){
	std::cout << "Hi there! Welcome to " << R.get_name() <<'\n';
	char user = getUsertype();
	if (user ==  'C') {
		customerinstruction(R);
	} else if (user == 'E') {
		employeeinstruction(R);
	}


}

int main(){
	printspaces(10);
	int numOpizzzas = countlines("menu.txt", 0); //count number of pizzas
	pizza *p = makePizza(numOpizzzas); //Make pizza Array
	menu M = menu(numOpizzzas, p); //Call non Def Construct for Menu, made menu
	int numOemploy = countlines("employee.txt", 0); //count number of employees
	int numOdaysOpn = countlines("restaurant_info.txt", 4);
	employee* e = makeEmployees(numOemploy);
	hours* w = makeWeek(numOdaysOpn);
	int NumOders = countlines("orders.txt", 0);
	order*o = getorder(NumOders);
	string nm, ph, ad;
	getResInfo(&nm, &ph, &ad);
	//std::cout << NumOders << '\n';
	restaurant R = restaurant(M, numOemploy, e, numOdaysOpn, w, nm, ph, ad, o, NumOders);
	progStart(R);
	// std::cout << "Hi" << '\n';
	printspaces(10);
	std::cout << "done" << '\n';
	return 0;

}
