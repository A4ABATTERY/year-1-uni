#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main() {
		
// part 1 starts here
	cout << "Signed int max: " << INT_MAX << endl;
	cout << "Signed int min: " << INT_MIN << endl;
	cout << "Unsigned int max: " << UINT_MAX << endl;
	cout << "Unsigned int min: 0" << endl;
	cout << "Signed short max: " << SHRT_MAX << endl;
	cout << "Signed short min: " << SHRT_MIN << endl;	
	cout << "Unsigned short max: " << USHRT_MAX << endl;
	cout << "Unsigned short min: 0" << endl;
	cout << "Signed long max: " << LONG_MAX << endl;
	cout << "Signed long min: " << LONG_MIN << endl;
	cout << "Unsigned long max: " << ULONG_MAX << endl;
	cout << "Unsigned long min: 0\n" << endl;
// part 2 starts here
	int bit;
	cout << "Enter the number of bytes you would like to test" << endl;
	cin >> bit;
	int maxbit = pow(2, bit);
	cout << "For" << bit << "number of bytes you can store:\n " << maxbit - 1 << " as a max\n" <<(maxbit*-1) << "as a min" << endl;
	cout << "the max unsigned value is: " << (maxbit + maxbit) << endl;



return 0;

}
