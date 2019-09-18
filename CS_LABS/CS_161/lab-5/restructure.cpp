#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getvalueofint() {
	float res, val;
	string input;
	bool flag;
	do{
		cout << "Please provide the amount of time in years between the current offer and future offer: ";
		getline(cin, input);
		flag = false;
		int count = 0;
		for(int i=0; i<input.length(); i++){
			if (input[i] < '0' || input[i] > '9') {
				flag = true;
			}
		}
	} while (flag);

	for(int i = (input.length()-1); i >= 0; i--) {
		val = ((int) input[i]) - 48;
		res +=  val * pow(10,(input.length() - i -1));
	}
	return res;
}
float getvalueoffloat() {
	string input;
	bool flag;
	float res, val, decimal;
	int i, count;
	do{
		cout << "Please provide the current offer amount: ";
		getline(cin, input);
		flag = false;
		int count = 0;
		for(int i=0; i<input.length(); i++){
			if (input[i] < '0' || input[i] > '9') {
				if (input[i] == '.') {
					count++;
					if (count > 1) {
						flag = true;
					}
				}
				else {
					flag = true;
				}
			}
		}
	} while (flag);

	for(i = 0; i < input.length(); i++) {
		if (input[i] == '.')
			break;
	}
	res = 0;
	val = 0;
	for(int j = i-1; j >= 0; j--) {
		val = ((int) input[j]) -48;
		res += val * pow(10, (i - 1 - j));
	}
	decimal = 0;
	count = 1;
	for(int k = i+1; k < input.length(); k++) {
		val = ((int) input[k]) - 48;
		decimal += val * pow(10, (-count));
		count++;
	}
	return res + decimal;
}
float valueofoffer(float offer, float ir, float m, float n){
	return offer*(pow((1+(ir/m)),(n*m)));
}
string finalreturn(float current_offer,float future_offer , float ir, float m, float n) {
	string curoffer = "Take the current offer\n";
	string furoffer = "Take the future offer\n";
	string eitheroffer = "choose which ever\n";
	if (valueofoffer(current_offer,ir,m,n) > valueofoffer(future_offer,ir,m,n)) {
		return curoffer;
	}
	else if(valueofoffer(current_offer,ir,m,n) < valueofoffer(future_offer,ir,m,n)) {
		return furoffer;
	}
	else {
		return eitheroffer;
	}
}


int main() {
	float current_offer = 0, future_offer = 0, ir = 0, m = 1, n = 0;
	cout << "It looks like you have two offers. Let's calculate which one is worth more." << endl;
	cout << "Please provide the current offer amount: ";
	current_offer = getvalueoffloat();
	cout << "Please provide the future offer amount: ";
	future_offer = getvalueoffloat();
	cout << "Please provide the interest rate: ";
	ir = getvalueoffloat();
	cout << "Please provide the amount of time in years between the current offer and future offer: ";
	cin >> n;
	n = getvalueofint();
	cout << finalreturn(current_offer, future_offer, ir, m, n);

	return 0;
}
