#pragma once
#include "class-menu.h"
#include "class-restaurant.h"
#include "class-pizza.h"
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "functions.h"

using std::string;

restaurant::restaurant(){
	name = "";
	phone = "";
	address = "";
	week = NULL;
	employees = NULL;
	orders = NULL;
	numOorder = 0;
	numOemp = 0;
	daysopen = 0;


}
restaurant::restaurant(menu m, int nE, employee*e, int d, hours*h, string n, string p, string a, order*o, int no){
	// std::cout << "seg1" << '\n';
	name = n;
	phone = p;
	address = a;
	// std::cout << "seg at h" << '\n';
	daysopen = d;
	week = h;
	numOemp = nE;
	employees = e;
	// std::cout << "seg at m" << '\n';
	Menu = m;
	orders = o;
	numOorder = no;
}
restaurant::~restaurant(){
	delete[]orders;
	delete[]employees;
	delete[]week;
	orders == NULL;
	employees = NULL;
	week = NULL;
	Menu.~menu();
	//delete[]Menu;
	std::cout << "Restaurant Destructed, ";
}
/****************************************************************************************/
/*									  Access - Restaurant 								*/
/****************************************************************************************/
menu restaurant::get_Menu() const {return Menu;}
employee*  restaurant::get_employees() const {return employees;}
hours* restaurant::get_hours() const {return week;}
string restaurant::get_name() const {return name;}
string restaurant::get_phone() const {return phone;}
string restaurant::get_address() const {return address;}
int restaurant::get_numOemp() const {return numOemp;}
/****************************************************************************************/
/*									  Mutate - Restaurant 								*/
/****************************************************************************************/
void restaurant::set_Menu(menu m) {Menu = m;}
void restaurant::set_employees(employee* e) {employees = e;}
void restaurant::set_hours(hours* h) {week = h;}
void restaurant::set_name(string s) {name = s;}
void restaurant::set_phone(string s) {phone= s;}
void restaurant::set_address(string s) {address = s;}
void restaurant::set_numOemp(int e) {numOemp = e;}
void restaurant::set_numOorder(int i) {numOorder = i;}
void restaurant::set_orders(order* o) {orders = o;}
/****************************************************************************************/
/*									  Others - Restaurant 								*/
/****************************************************************************************/
void restaurant::printhours(){
	std::cout << "Day  Opn  Cls" << '\n';
	for(int i = 0; i < daysopen; i++){
		std::cout << " " << week[i].day;
		std::cout << "   " << week[i].open_hours;
		std::cout << "    " << week[i].close_hours;
		std::cout << '\n';
	}
}
void restaurant::placeorder(){
  	numOorder++;
	string On, Cn, Cc, Da, Cp, Pn, Ps, Rp; bool confirm; string confirmStr;
	std::cin.ignore();
	do {
		On =(char (numOorder + 48));

		std::cout << "Please enter your name: "; getline(std::cin, Cn);
		 Cn += " ";
		std::cout << "\nPlease enter your Credit card info: "; getline(std::cin, Cc);
		Cc += " ";
		std::cout << "\nPlease enter the Adress we should deliver to: "; getline(std::cin, Da);
		Da += " ";
		std::cout << "\nPlease enter your phone number: "; getline(std::cin, Cp);
		Cp += " ";
		std::cout << "\nPlease enter the name of the Pizza you'd like to order: "; getline(std::cin, Pn);
		Pn += " ";
		std::cout << "\nPlease enter the size(small, medium, large): "; getline(std::cin, Ps);
		Ps += " ";
		std::cout << "`\nHow many of this type of this order would you like: "; getline(std::cin, Rp);
		Rp += " ";
		std::cout << "\n\nYour order is: " << '\n';
		std::cout << Rp << Ps << Pn << "deliered to " << Da << '\n';
		std::cout << "Enter 0 if you'd like to change your order" << '\n';
		std::cout << "Enter any other key/string if you confirm" << '\n';
		std::cin >> confirmStr;
		if(confirmStr[0] != '0'){
			confirm = 1;
		}else{
			confirm = 0;
			Cn = ""; Cc = ""; Da = ""; Cp = ""; Pn = ""; Ps = ""; Rp = "";
			std::cout << "Repeating the order taking process...\n\n" << '\n';
			std::cin.ignore();
		}
	} while(!(confirm));

	std::ofstream f; f.open("orders.txt", std::ios::app);
	if (f.is_open()){
		f << On << " " << Cn << Cc << Da << Cp << Pn << Ps << Rp << '\n';
		f.flush(); f.close();
	}
	if(orders != NULL){
		delete[]orders;
	} f.flush(); f.close();
	orders = getorder(numOorder);

}
bool restaurant::checklogin(string ID, string PW){
	std::cout << "Password checking not working.... functions are acting weird" << '\n';
	for(int i = 0; i < numOemp; i++){
		if (employees[i].id.compare(ID)){
			if (employees[i].password.compare(PW)) {
				return true;
			}
		}

	}

	return true;
}
void restaurant::vieworders(){
	for (int i = 0; i < numOorder; i++){
		std::cout << orders[i].Order_num;
		std::cout << " " <<orders[i].Custormer_Name;
		std::cout << " " <<orders[i].Credit_Card;
		std::cout << " " <<orders[i].Delivery_Address;
		std::cout << " " <<orders[i].Custormer_Phone;
		std::cout << " " <<orders[i].Pizza_Name;
		std::cout << " " <<orders[i].Pizza_size;
		std::cout << " " <<orders[i].Repeat;
		std::cout << '\n';
		std::cout << "---------------------------------------------------------------------------" << '\n';
	}
}
void restaurant::changehours(){
	delete[]week;
	std::cout << "How many number of days is " << name << " open?";
	std::cin >> daysopen;
	week = new hours[daysopen];
	for(int i = 0; i < daysopen; i++){
		std::cout << "\nWhat day is day " << i+1 <<": ";
		std::cin >> week[i].day;
		std::cout << "\nWhat are the opening hours for day " << i+1 << ": ";
		std::cin >> week[i].open_hours;
		std::cout << "\nWhat are the closing hours for day " << i+1 <<": ";
		std::cin >> week[i].close_hours;
	}
	std::cout << "New working days/week are as follows: " << '\n';
	printhours();

	rewriteResInfo();

}
void restaurant::rewriteResInfo() {
	std::ofstream f;
	f.open("restaurant_info.txt", std::ostream::out | std::ostream::trunc);
	f.close();
	f.open("restaurant_info.txt", std::ios::app);
	if (f.is_open()){
		//f << On << " " << Cn << Cc << Da << Cp << Pn << Ps << Rp << '\n';
		f << name << '\n';
		f << phone << '\n';
		f << address << '\n';
		f << daysopen << '\n';
		for(int i = 0; i < daysopen; i++){
			f << week[i].day << " " << week[i].open_hours << " " << week[i].close_hours << '\n';
		}
		f.flush(); f.close();
	}
}
void restaurant::removeorder(){
	std::cout << "There are " << numOorder << " orders: " << '\n';
	vieworders();
	std::cout << '\n';
	string OrderNumRmv;
	std::cout << "Please enter the \'Order number\' of the order you are trying to remove: ";
	std::cin >> OrderNumRmv;
	int index = 0;
	for(; orders[index].Order_num.compare(OrderNumRmv) != 0; index++){

	}
	numOorder--;
	std::cout << "index at " << index << '\n';
	order* ordesrNew = new order[numOorder];
	for (int j = 0; j < index; j++) {
		ordesrNew[j] = orders[j];
	}
	for(int j = index; j < numOorder; j++){
		ordesrNew[j] = orders[j+1];
	}
	delete[]orders;
	orders = ordesrNew;
	rewriteOrders();
}
void restaurant::rewriteOrders(){
	std::ofstream f;
	f.open("orders.txt", std::ostream::out | std::ostream::trunc);
	f.close();
	f.open("orders.txt", std::ios::app);
	string temp;
	if (f.is_open()){
		for (int i = 0; i < numOorder; i++){
			temp = orders[i].Order_num + " " +orders[i].Custormer_Name + " " + orders[i].Credit_Card + " " +orders[i].Delivery_Address;
			temp = temp + " " + orders[i].Custormer_Phone + " " + orders[i].Pizza_Name + " " + orders[i].Pizza_size + " " + orders[i].Repeat;
			f << temp << '\n';
			temp = "";
		}
		f.flush(); f.close();

	}
}
