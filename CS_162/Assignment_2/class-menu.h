#pragma once
#include "class-pizza.h"
#include <string>

using std::string;

class menu{
	private:
		pizza *pizzas;
		int num_pizzas;

	public:
		menu();
		menu(int, pizza*);

		int get_num_of_pizzas() const;
		pizza* get_pizzas() const;

		void set_num_of_pizzas(int);
		void set_pizzas(pizza*);

		void viewmenu();
		void search_by_cost(string, int);
		void search_by_ingredients(string);
		void removeFrmMenu();
		void AddToMenu();
		void rewritemenu();


		menu(const menu&);
		~menu();
		const menu& operator=(const menu&);
};
