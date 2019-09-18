#include <string.h>
#include <iostream>
#include <cstdlib>

struct employee{
	std::string password;
	std::string employee_names;
};
struct hours{
	char day;
	int open_time;
	int close_time;
};




/****************************************************************************************/
/*									  Construct - ALL									*/
/****************************************************************************************/
restaurant::restaurant(){
	name = "";
	phone = "";
	address = "";
	week = NULL;
	employees = NULL;
	Menu = menu();
}
restaurant::restaurant(menu m, employee* e, hours* h,
					   std::string n, std::string p, std::string a){
	name = n; 			phone = p; 			address = a;
	week = h; 			employees = e;		Menu = m;
}
menu::menu(){
	num_pizzas = 0;
	pizzas = NULL;
}
menu::menu(int np, pizza* p){
	num_pizzas = np;	pizzas = p;
}
pizza::pizza(){
	name = "";
	small_price = 0;
	med_price = 0;
	large_price = 0;
	num_ingredients = 0;
	ingredients = NULL;
}
pizza::pizza(std::string n, int s, int m, int l, int ni, std::string* i){
	name = n;		small_price = s;		med_price = m;
	large_price = l;num_ingredients = ni;	ingredients = i;

}
/****************************************************************************************/
/*									  Access - Restaurant 								*/
/****************************************************************************************/
menu restaurant::get_Menu() const {return Menu;}
employee* restaurant::get_employees() const {return employees;}
hours* restaurant::get_hours() const {return week;}
std::string restaurant::get_name() const {return name;}
std::string restaurant::get_phone() const {return phone;}
std::string restaurant::get_address() const {return address;}
/****************************************************************************************/
/*									  Mutate - Restaurant 								*/
/****************************************************************************************/
void restaurant::set_Menu(menu m) {Menu = m;}
void restaurant::get_employees(employee*e) {employees = e;}
void restaurant::set_hours(hours* h) {week = h;}
void restaurant::set_name(std::string s) {name = s;}
void restaurant::set_phone(std::string s) {phone= s;}
void restaurant::set_address(std::string s) {adress = s;}

/****************************************************************************************/
/*									  Access - Menu 									*/
/****************************************************************************************/
int menu::get_num_of_pizzas() const {return num_pizzas;}
pizza* menu::get_pizzas() const {return pizzas;}
/****************************************************************************************/
/*									  Mutate - Menu 									*/
/****************************************************************************************/
void menu::set_num_of_pizzas(int n) {num_pizzas = n;}
void menu::set_pizzas(int n){pizzas = new pizza[n];}
/****************************************************************************************/
/*									  Access - Pizza 									*/
/****************************************************************************************/
std::string pizza::get_Pizza_Name() const {return name;}
int pizza::get_price_Small_Pizza() const {return small_price;}
int pizza::get_med_Price_Pizza() const {return med_price;}
int pizza::get_large_Price_Pizza() const {return large_price;}
int pizza::get_num_ingredients_PIzza() const {return num_ingredients;}
/****************************************************************************************/
/*									  Mutate - Pizza 									*/
/****************************************************************************************/
void pizza::set_Pizza_Name(std::string n) {name = n;}
void pizza::set_Small__price_Pizza(int p) {small_price = p;}
void pizza::set_med_Price_Pizza(int p) {med_price = p;}
void pizza::set_large_Price_Pizza(int p) {large_price = p;}
