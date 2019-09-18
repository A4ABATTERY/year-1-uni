#include "class-pizza.h"
// #include "class-menu.h"
// #include "class-restaurant.h"
#include <string>
#include <cstdlib>
#include <iostream>

using std::string;

int pizza::makeint(string l){
	return atoi(l.c_str());
}
void pizza::makeIngredientsArr(string line){
	ingredients = new string[get_num_ingredients_PIzza()];
	string temp;
	int j = -1;
	for(int i = 0; i < get_num_ingredients_PIzza(); i++){
		for(j++; (line[j] != ' ') && (j != line.length()); j++)
			temp += line[j];
		ingredients[i] = temp; temp = "";
	}
}

pizza::pizza(){
	 // std::cout << "made pizza" << '\n';
	name = "";
	small_price = 0;
	med_price = 0;
	large_price = 0;
	num_ingredients = 0;
	ingredients = NULL;
}
pizza::pizza(string n, int s, int m, int l, int ni, string* i){
	// std::cout << "made pizza w values" << '\n';
	name = n;		small_price = s;		med_price = m;
	large_price = l;num_ingredients = ni;	ingredients = i;

}
pizza::pizza(const pizza &copy){
	 // std::cout << "copy pizza" << '\n';
	name = copy.name;
	small_price = copy.small_price;
	med_price = copy.med_price;
	large_price = copy.large_price;
	num_ingredients = copy.num_ingredients;
	if (num_ingredients == 0){
		ingredients = NULL;
	}else {
		ingredients = new string[num_ingredients];
		for (int i = 0; i < num_ingredients; i++)
			ingredients[i] = copy.ingredients[i];
	}
}
pizza::~pizza(){
	delete[]ingredients;
	ingredients = NULL;
	// std::cout << "delete pizza" << '\n';
	// std::cout << "Pizza Destructed :(, ";
}
const pizza& pizza::operator=( pizza&copy){
	 // std::cout << "Op PIzza" << '\n';
	name = copy.name;
	small_price = copy.small_price;
	med_price = copy.med_price;
	large_price = copy.large_price;
	num_ingredients = copy.num_ingredients;
	// std::cout << "Seg" << '\n';
	if (ingredients != NULL)
		delete[]ingredients;
	if (num_ingredients == 0){
		ingredients = NULL;
	}else{
		ingredients = new string[num_ingredients];
		for (int i = 0; i < num_ingredients; i++){
			ingredients[i] = copy.ingredients[i];
		}
	}//std::cout << "done op pizza" << '\n';
	return *this;
}


/****************************************************************************************/
/*									  Access - Pizza 									*/
/****************************************************************************************/
string pizza::get_Pizza_Name() const {return name;}
int pizza::get_price_Small_Pizza() const {return small_price;}
int pizza::get_med_Price_Pizza() const {return med_price;}
int pizza::get_large_Price_Pizza() const {return large_price;}
int pizza::get_num_ingredients_PIzza() const {return num_ingredients;}
string* pizza::get_Pizza_ingredients() const {return ingredients;}
/****************************************************************************************/
/*									  Mutate - Pizza 									*/
/****************************************************************************************/
void pizza::set_Pizza_Name(string n) {name = n;}
void pizza::set_Small_price_Pizza(string p) {small_price = makeint(p);}
void pizza::set_med_Price_Pizza(string p) {med_price = makeint(p);}
void pizza::set_large_Price_Pizza(string p) {large_price = makeint(p);}
void pizza::set_num_ingredients_PIzza(string i) {num_ingredients = makeint(i);}
void pizza::set_Small_price_Pizza(int p) {small_price = p;}
void pizza::set_med_Price_Pizza(int p) {med_price = p;}
void pizza::set_large_Price_Pizza(int p) {large_price = p;}
void pizza::set_num_ingredients_PIzza(int i) {num_ingredients = i;}
void pizza::set_Pizza_ingredients(string* s) {ingredients = s;}
void pizza::parsePizza(string line){
	int i = 0; string temp;
	for(; line[i] != ' '; i++){
		temp += line[i];
	}set_Pizza_Name(temp); temp = "";
	for(i++; line[i] != ' '; i++){
		temp += line[i];
	}set_Small_price_Pizza(temp); temp = "";
	for(i++; line[i] != ' '; i++){
		temp += line[i];
	}set_med_Price_Pizza(temp); temp = "";
	for(i++; line[i] != ' '; i++){
		temp += line[i];
	}set_large_Price_Pizza(temp); temp = "";
	for(i++; line[i] != ' '; i++){
		temp += line[i];
	}set_num_ingredients_PIzza(temp); temp = "";
	for(i++; i < line.length(); i++)
		temp += line[i];
	makeIngredientsArr(temp);
}
void pizza::printPizzaInfo(){
  //std::cout << "The menu includes: PIZA " << " SML " << " MED " << " LRG " << '\n';
	std::cout << "                   " << name << " ";
	std::cout << " " << small_price;
	if(small_price < 10) { std::cout << " ";}
	std::cout << "   " << med_price;
	if(med_price < 10) { std::cout << " ";}
	std::cout << "  " << large_price << '\n';


}
