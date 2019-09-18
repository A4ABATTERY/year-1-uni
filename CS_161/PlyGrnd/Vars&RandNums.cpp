#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main () {
	int x; /*var to hold rand int*/
	srand(time(NULL)); /*seeds rand int generator */
	/*with one of these functions the numbers were large INTs (32 bit numbs? ). 
 * 	it was random each time. */
	x = rand();
	cout << "x = " << x << endl;	
	
	srand(time(NULL)); /*added second rand generator as per assignment instructions*/	
	
	x = rand(); //after the second Srand function was called, this COUT prints the same as the first
	cout << "x = " << x << endl;
	
	x = x%6;
	cout << "rand num: " << x << endl;

return 0;

}
