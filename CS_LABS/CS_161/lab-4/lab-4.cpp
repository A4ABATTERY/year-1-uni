#include <iostream>
#include <string>

char i_to_a() {
	int x;
	std::cout << "Enter a number" << '\n';
	std::cin >> x;
//	if (((x>64) && (x<91)) || ((x>96) && (x<123))) {
		char y = x;
		return y;
//	} else {
//		return 48;
//	}
}


int a_to_i() {
		char x;
		std::cin >> x;
//		if ((x>47) && (x<58)) {
			return (int(x));
//	}
//5	 return 0;
}


int main() {
	std::cout << "Enter a program to test" << '\n';
	std::cout << "1 = a_to_i()" << '\n';
	std::cout << "2 = i_to_a()" << '\n';
	int choice;
	std::cin >> choice;
	if (choice == 1) {
		std::cout << "Enter some string: "<< '\n';
		std::cout << a_to_i() << '\n';
		return 0;
	} else if (choice == 2) {
		std::cout << i_to_a() << '\n';
		return 0;
	} else {
		std::cout << "You entered something other than 1 or 2. Exit program" << '\n';
		return 0;
	}
}
