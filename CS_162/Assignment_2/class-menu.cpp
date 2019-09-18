#include "class-menu.h"
#include "class-pizza.h"
#include "class-restaurant.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

using std::string;

menu::menu(){
	num_pizzas = 0;
	pizzas = NULL;
}
menu::menu(int np, pizza* p){
	num_pizzas = np;
	pizzas = p;
}
menu::menu(const menu& copy){
	// std::cout << "seg" << '\n';
	num_pizzas = copy.num_pizzas;
	// std::cout << "seg" << '\n';
	if (num_pizzas == 0){
		pizzas = NULL;
		// std::cout << "seg if" << '\n';
	}else{
		// std::cout << "seg else" << '\n';
		pizzas = new pizza[num_pizzas];
		for (int i = 0; i < num_pizzas; i++){
			// std::cout << "Seg for" << '\n';
			pizzas[i] = copy.pizzas[i];  // SEG FAULT HERE
			//std::cout << "seg for" << '\n';
		}
	} //std::cout << "seg cc complete" << '\n';
}
menu::~menu(){
	delete[]pizzas;
	pizzas = NULL;
	// std::cout << "called Menu destruct" << '\n';
	// std::cout << "Menu Destructed, " << '\n';

}
const menu& menu::operator=(const menu& copy){
	num_pizzas = copy.num_pizzas;
	if (pizzas != NULL){
		delete[]pizzas;
	}
	if(num_pizzas == 0){
		pizzas = NULL;
	}else{
		pizzas = new pizza[num_pizzas];
		for(int i = 0; i < copy.num_pizzas; i++){
			pizzas[i] = copy.pizzas[i];
		}
	} return *this;

}

/****************************************************************************************/
/*									  Access - Menu 									*/
/****************************************************************************************/
int menu::get_num_of_pizzas() const {return num_pizzas;}
pizza* menu::get_pizzas() const {return pizzas;}
/****************************************************************************************/
/*									  Mutate - Menu 									*/
/****************************************************************************************/
void menu::set_num_of_pizzas(int n) {num_pizzas = n;}
void menu::set_pizzas(pizza* p){pizzas = p;}
/****************************************************************************************/
/*									  Other - Menu  									*/
/****************************************************************************************/
void menu::viewmenu(){
	std::cout << "pizzas " << pizzas <<'\n';
	std::cout << "num_pizzas = " << num_pizzas << '\n';
	std::cout << "The menu includes: ";
	std::cout << " PIZA " << " SML " << " MED " << " LRG " << '\n';
		for(int i = 0; i < num_pizzas; i++){
			pizzas[i].printPizzaInfo();
		}
}
void menu::search_by_cost(string size, int bound){
	for(int i = 0; i < num_pizzas; i++){
			if(size.compare("s") == 0){
				if (pizzas[i].get_price_Small_Pizza() <= bound)
					std::cout << pizzas[i].get_Pizza_Name() << " at " << pizzas[i].get_price_Small_Pizza() << " dollars" << '\n';
			}else if(size.compare("m") == 0){
				if (pizzas[i].get_med_Price_Pizza() <= bound)
					std::cout << pizzas[i].get_Pizza_Name() << " at " << pizzas[i].get_med_Price_Pizza() << " dollars" << '\n';
			}else if(size.compare("l") == 0)
				if (pizzas[i].get_large_Price_Pizza() <= bound)
					std::cout << pizzas[i].get_Pizza_Name() << " at " << pizzas[i].get_large_Price_Pizza() << " dollars"<< '\n';
	}
}
void menu::search_by_ingredients(string Str){
	int noi;
	for(int i = 0; i < num_pizzas; i++){
		noi = pizzas[i].get_num_ingredients_PIzza();
		for(int j = 0; j < noi; j++)
			if(Str.compare(pizzas[i].get_Pizza_ingredients()[j]) == 0){
				std::cout << pizzas[i].get_Pizza_Name()<< " has " << Str << '\n';


				break;
			}
	}

}
void menu::AddToMenu(){
	string Nname, nSprice, nMprice, nLprice, nNumI;
	string * nI;
	num_pizzas++;
	pizza *newP = new pizza[num_pizzas];
	for(int i = 0; i < num_pizzas - 1; i++){
		newP[i] = pizzas[i];
	}
	std::cout << "Enter the name of the new pizza: ";
	std::cin >> Nname;
	std::cout << "Enter the price for a small "<< Nname << ": ";
	std::cin >> nSprice;
	std::cout << "Enter the price for a medium "<< Nname << ": ";
	std::cin >> nMprice;
	std::cout << "Enter the price for a large "<< Nname << ": ";
	std::cin >> nLprice;
	std::cout << "Enter the number of ingredients used in this pizza: ";
	std::cin >> nNumI;
	int num = atoi(nNumI.c_str());
	nI = new string[num];
	for(int i = 0; i < num; i++){
		std::cout << "What is ingredient " << i + 1 << ": ";
		std::cin >> nI[i];
		std::cout << '\n';
	}
	num = num_pizzas;
	std::cout << '\n';
	newP[num-1].set_Pizza_Name(Nname); newP[num-1].set_Small_price_Pizza(nSprice);
	newP[num-1].set_med_Price_Pizza(nMprice); newP[num-1].set_large_Price_Pizza(nLprice);
	newP[num-1].set_num_ingredients_PIzza(nNumI); newP[num-1].set_Pizza_ingredients(nI);
	delete[]pizzas;
	pizzas = new pizza[num_pizzas];
	for (int i = 0; i < num_pizzas; i++){
		pizzas[i] = newP[i];
	}
	delete[]newP;
	viewmenu();
	rewritemenu();

}
void menu::removeFrmMenu(){
	string searchfor;
	viewmenu();
	std::cout << "Enter the name of the Pizza you'd like to remove: ";
	std::cin >> searchfor;
	int i = 0;
	for(; pizzas[i].get_Pizza_Name().compare(searchfor) != 0; i++){}
	// std::cout << "index = " << i <<'\n';
	pizza* temp = new pizza[num_pizzas - 1];
	for(int j = 0; j < i; j++){
			temp[j] = pizzas[j];
	}
	for(int j = i; j < num_pizzas -1; j++){
		temp[j] = pizzas[j+1];
	}
	delete[]pizzas;
	num_pizzas--;
	pizzas = new pizza[num_pizzas];
	for (i = 0; i < num_pizzas; i++) {
		pizzas[i] = temp[i];
	}
	viewmenu();
	rewritemenu();
	delete[]temp;
}
void menu::rewritemenu(){
	std::ofstream f;
	f.open("menu.txt", std::ostream::out | std::ostream::trunc);
	f.close();
	f.open("menu.txt", std::ios::app);
	string temp;
	for(int i = 0; i < num_pizzas;i++){
		f << pizzas[i].get_Pizza_Name() << " " << pizzas[i].get_price_Small_Pizza() << " ";
		f << pizzas[i].get_med_Price_Pizza() << " " << pizzas[i].get_large_Price_Pizza() << " ";
		f << pizzas[i].get_num_ingredients_PIzza() << " ";
		for(int j = 0 ;j < pizzas[i].get_num_ingredients_PIzza(); j++){
			f << pizzas[i].get_Pizza_ingredients()[j] << " ";
		}
		f << '\n';

	}
}
