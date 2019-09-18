#include<cctype>
#include <string>
#include <iostream>
using namespace std;

int main() {
string expression = "5+104-32/5";
string operators[10];
string terms[20];
int term_counter=0;
int op_counter=0;
for(int i=0; i<expression.size(); i++)
{
	 if(expression[i] == '+' || expression[i] == '-' ||
		expression[i] == '*' || expression[i] == '/')
	 {
		  //extract all operators (in sequential order)
		  operators[op_counter] = expression[i];
		  op_counter++;
		  term_counter++;
	 }
	 else if(isdigit(expression[i]))
	 {
		  //Extract terms into individial 'string' containers
		  terms[term_counter] += expression[i];
	 }
	 cout << "expression: " << expression<< '\n';
	 cout << "op_counter = " << op_counter <<'\n';
	 cout << "term_counter = " << term_counter << '\n';

}std::cout << "terms: " << terms <<'\n';
std::cout << "operators: " << operators << '\n';
return 0;
}
