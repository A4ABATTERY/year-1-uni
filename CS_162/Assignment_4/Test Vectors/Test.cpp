#include "./testbugger.hpp"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;


int main(){
	vector < vector<Bug> > M( 10, vector<Bug>(5) );
	vector<Bug>::iterator jtr; // hehehehe jiterator :'D
	vector< vector<Bug> >::iterator itr; // iterator
	M[8][2].Attacked();
	for(itr = M.begin(); itr != M.end(); itr++){
		for(jtr = itr->begin(); jtr != itr->end(); jtr++)
			std::cout << jtr->gethealth() << " ";
		std::cout << '\n';
	}
	std::cout << '\n';






}
