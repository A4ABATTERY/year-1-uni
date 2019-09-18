#include "functions.h"
#include <string>

using std::string;

void printspaces(int c){
	for(int i = 0; i < c; i++)
		std::cout << "\n";
}
pizza* makePizza(int size){
	pizza *p = new pizza[size]; string line;
	std::ifstream f; f.open("menu.txt", std::ifstream::out | std::ifstream::out);
	for(int i = 0; i < size; i++){
		getline(f, line);
		p[i].parsePizza(line);
		// std::cout << p[i].get_Pizza_ingredients()[0] << '\n';
	}f.clear(); f.close();
	return p;
}
employee* makeEmployees(int size){
	employee *e = new employee[size]; string line;
	std::ifstream f; f.open("employee.txt", std::ifstream::out | std::ifstream::in);
	for(int i = 0; i < size; i++){
		getline(f, line);
		parseEmployee(line, e, i);
	}f.clear(); f.close();
	return e;
}
hours* makeWeek(int size){
	hours* h = new hours[size]; string line; int i = 0;
	std::ifstream f; f.open("restaurant_info.txt", std::ifstream::out | std::ifstream::out);
	while (getline(f, line)) {
		i++;
		if (!(i < 5)){
			// std::cout << i -5 << '\n';
			parseHours(line, h, i - 5);
			// std::cout << "seg1" << '\n';
		}
	}
	f.clear(); f.close();
	return h;
}
void parseHours(string line, hours* h, int j){
	// std::cout << "j = " << j <<'\n';
	int i = 0; string temp;
	for(; line[i] != ' '; i++)
		temp += line[i];
	// std::cout << "seg" << '\n';
	h[j].day = temp; temp = "";
	for(i++; line[i] != ' '; i++)
		temp += line[i];
	// std::cout << "seg" << '\n';
	h[j].open_hours = temp; temp = "";
	for(i++; i < line.length(); i++)
		temp += line[i];
	// std::cout << "seg" << '\n';
	h[j].close_hours = temp; temp = "";
}
void parseEmployee(string line, employee *e, int j){
	int i = 0; string temp;
	for(; line[i] != ' '; i++)
		temp += line[i];
	e[j].id = temp; temp = "";
	for(i++; line[i] != ' '; i++)
		temp += line[i];
	e[j].first_name = temp; temp = "";
	for(i++; line[i] != ' '; i++)
		temp += line[i];
	e[j].last_name = temp; temp = "";
	for(i++; i < line.length(); i++)
		temp += line[i];
	e[j].password = temp; temp = "";

}
int countlines(string filename, int offset = 0){
	std::ifstream f; string line;
	int count = 0;
	f.open(filename.c_str(), std::ifstream::out | std::ifstream::out);
	if (f.is_open()){
		while (getline(f, line)) {
			count ++;
		} f.clear(); f.seekg(0, std::ios::beg);
		f.clear(); f.close();
	}if (!(f.is_open()))
		return count - offset;
}
void getResInfo(string*nm, string*ph, string*ad){
	string line; std::ifstream f;
	f.open("restaurant_info.txt", std::ifstream::out | std::ifstream::in);
	getline(f, line); *nm = line;
	getline(f, line); *ph = line;
	getline(f, line); *ad = line;
	f.clear(); f.close();
}
char getUsertype(){
	char user;
	do{
		std::cout << "Are you a (C)ustomer or and (E)mployee? \nplease enter C or E:";
		std::cin >> user;
	} while(!(user == 'C' || user == 'E'));
	return user;
}
string getString(string S){
	std::cout << "Please enter an ingredient you'd like to search by\n";
	std::cout << "(NOTE, search is case sensitive, and spelling sensitive): ";
	std::cin >> S;
	std::cout << '\n';
	return S;
}
string getlogin(string i){
	string line;
	std::cout << "Enter your " << i << ": ";
	std::cin >> line;
	std::cout << '\n';
	std::cin.clear();
	return line;
}
void employeestart(string id, restaurant&R){
	string user = "0"; string runagain; string Str; int bound;
	while (runagain.compare("10") != 0) {

		while(!((user[0] >48 && user[0] < 58)||(user[0] == '1' && user[1] == '0'))){
			user = "";
			printEmployeeOptions();
			std::cin >> user;
		}
		if (user.compare("1") == 0) {
			printspaces(2);
			std::cout << R.get_Menu().get_pizzas() << '\n';
			R.get_Menu().viewmenu();
			printspaces(2);
		} else if (user.compare("2") == 0) {
			printspaces(2);
			std::cout << R.get_name() << " phone number is " << R.get_phone() << '\n';
			printspaces(2);
		}else if (user.compare("3") == 0) {
			printspaces(2);
			std::cout << R.get_name() << " location is " << R.get_address() << '\n';
			printspaces(2);
		}else if (user.compare("4") == 0) {
			R.printhours();
		}else if (user.compare("5") == 0) {
			R.changehours();
		}else if (user.compare("6") == 0) {
			R.vieworders();
		}else if (user.compare("7") == 0) {
			R.removeorder();
		}else if (user.compare("8") == 0) {
			R.get_Menu().AddToMenu();
		}else if (user.compare("9") == 0) {
			R.get_Menu().removeFrmMenu();
		}else if (user.compare("10") == 0) {
			/* code */
		}


		if(user.compare("10") != 0){
			printAgainQ(10);
			std::cin >> runagain;
			user = '0';
		}else if(user.compare("10") == 0){
			break;
		}
	}
}
void employeeinstruction(restaurant&R){
	int i = 0; bool confirmed = 1;
	string IDtemp; string passTemp;
	do {
		IDtemp = getlogin("ID");
		passTemp = getlogin("Password");
		if(R.checklogin(IDtemp, passTemp)){
			confirmed = 0;
			i = 4;
		}else{
			i++;
			std::cout << "you have " << 3 - i  << " attempts left" <<'\n';
		}

	} while(i < 3);
	if (i == 3)
		std::cout << "Program closing, too many failed attempts :(" << '\n';
	else
		employeestart(IDtemp, R);
	std::cout << "Good bye" << '\n';

}
void customerinstruction(restaurant&R){
	char user = '0'; char runagain = 1; string Str; int bound;
	while (runagain != '8') {

		while(!(user >48 && user<57)){
			printCustomerOptions();
			std::cin >> user;
		}
		switch (user) {
			case '1':
				printspaces(2);
				R.get_Menu().viewmenu();
				printspaces(2); break;
			case '2':
				printspaces(2);
				std::cout << R.get_name() << " phone number is " << R.get_phone() << '\n';
				printspaces(2); break;
			case '3':
				printspaces(2);
				std::cout << R.get_name() << " location is " << R.get_address() << '\n';
				printspaces(2); break;
			case '4':
				R.printhours();
			break;
			case '5':
				R.placeorder();
			break;
			case '6':
				Str = getsize(Str); getBound(&bound);
				R.get_Menu().search_by_cost(Str, bound);
			break;
			case '7':
				Str = getString(Str);
				R.get_Menu().search_by_ingredients(Str);
			break;
			case '8':
			break;

		}

		if(user != '8'){
			printAgainQ(8);
			std::cin >> runagain;
			user = '0';
		}else if(user == '8'){
			break;
		}
	}
}
string getsize(string S){
	bool flag = 1;
	string sml = "small"; string sml2 = "Small"; string sml3 = "sml";
	string med = "medium";string med2 = "Medium"; string med3 = "med";
	string lrg = "large"; string lrg2 = "Large"; string lrg3 = "lrg";
	do {
		std::cout << "Enter a prefered size you'd like to search for: ";
		std::cin >> S;
		if ((S).compare(sml) == 0|| (S).compare(sml2) == 0 || (S).compare(sml2) == 0){
			S = "s";
			flag = 0;
		}else if ((S).compare(med) == 0 || (S).compare(med2) == 0 || (S).compare(med3) == 0){
			S = "m";
			flag = 0;
		}else if((S).compare(lrg) == 0|| (S).compare(lrg2) == 0|| (S).compare(lrg3) == 0){
			S = 'l';
			flag = 0;
		}
	} while((flag));
	return S;
}
void getBound(int*inputInt = 0){
	string Str;
	do {
		std::cout << "Enter a bound for the maximum price: ";
		std::cin >> Str;
		std::cout << '\n';
	} while(!(0 < atoi(Str.c_str())));
	*inputInt = atoi(Str.c_str());
}
void printAgainQ(int i) {
	std::cout << "Would you like to do something else?" << '\n';
	std::cout << "Logout                || " << i <<'\n';
	std::cout << "Run again             || Enter Any Key (except " << i << ')' << '\n';
}
void printCustomerOptions(){
	std::cout << "View Menu             || 1" << '\n';
	std::cout << "View Phone            || 2" << '\n';
	std::cout << "View Address          || 3" << '\n';
	std::cout << "View hours            || 4" << '\n';
	std::cout << "Place Order           || 5" << '\n';
	std::cout << "Search by Cost        || 6" << '\n';
	std::cout << "Search by Ingredients || 7" << '\n';
	std::cout << "Logout                || 8" << '\n';
}
void printEmployeeOptions(){
	std::cout << "View Menu             || 1" << '\n';
	std::cout << "View Phone            || 2" << '\n';
	std::cout << "View Address          || 3" << '\n';
	std::cout << "View hours            || 4" << '\n';
	std::cout << "Change Hours          || 5" << '\n';
	std::cout << "View orders           || 6" << '\n';
	std::cout << "Remove orders         || 7" << '\n';
	std::cout << "Add menu item         || 8" << '\n';
	std::cout << "Remove menu item      || 9" << '\n';
	std::cout << "Logout                || 10" << '\n';
}
void parseorder(string line, order* o, int j){
	int i = 0; string temp;
	for(; line[i] != ' '; i++)
		temp += line[i];
	o[j].Order_num = temp; temp = "";
	for(i++; line[i] != ' '; i++)
		temp += line[i];
	o[j].Custormer_Name = temp; temp = "";
	for(i++; line[i] != ' '; i++)
		temp += line[i];
	o[j].Credit_Card = temp; temp = "";
	for(i++; line[i] != ' '; i++)
		temp += line[i];
	o[j].Delivery_Address = temp; temp = "";
	for(i++; line[i] != ' '; i++)
		temp += line[i];
	o[j].Custormer_Phone = temp; temp = "";
	for(i++; line[i] != ' '; i++)
		temp += line[i];
	o[j].Pizza_Name = temp; temp = "";
	for(i++; line[i] != ' '; i++)
		temp += line[i];
	o[j].Pizza_size = temp; temp = "";
	for(i++; i < line.length(); i++){
		temp += line[i];
	}o[j].Repeat = temp;
}
order* getorder(int size){
	order* o = NULL;
	if (size != 0){
		std::ifstream f; o =  new order[size]; string line;
		f.open("orders.txt", std::ifstream::out | std::ifstream::out);
		for(int i = 0; i < size; i++){
			getline(f, line);
			parseorder(line, o, i);
		}f.clear(); f.close();
	}else{
		o = NULL;
	}
	return o;
}
