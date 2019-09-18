#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]){
	cout << "Enter a string: ";

	char input[50];
	int i = 0;
	cin >> input;
	for(i = strlen(input)-1; i >= 0; i--){
	 	cout << input[i];
	}
	cout << endl;
	#ifdef DEBUG
	cout << "\n\nHiden by #ifdef DEBUG\n" << '\n';
	#endif
	return 0;
}
