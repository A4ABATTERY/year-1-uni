#include <iostream>
#include "Functions.h"



int main(int argc, char* argv[] = '\0'){
	std::cout << "\n" << '\n';
	bool flags = 0; int args = 0;
		if ( (argc == 5) && (is_valid_arguments(&argv[1], 2)) ){
			RunProgram(&argv[1]);
		}else if(argc > 5){
			std::cout << "Too many arguments :( \n" << '\n';
			std::cout << "Quitting time... Run again with correct arguments\n" << '\n';

		}else if(argc < 5){
			std::cout << "Too few arguments :( \n" << '\n';
			std::cout << "Quitting time... Run again with correct arguments\n" << '\n';

		}else{
			std::cout << "Invalid Arguments\n" << '\n';
			std::cout << "Quitting time... Run again with correct arguments\n" << '\n';

		}
	//}

	return 0;
}
