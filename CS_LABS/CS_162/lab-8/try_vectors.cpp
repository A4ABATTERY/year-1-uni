#include "./vectors.hpp"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't
//be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector
   vector<int> test;
   //Compare operation of our vector to std
   v.push_back(23);
   ////////////////////////////////////////////////////////////
   test.push_back(34); test.push_back(54); test.push_back(345);
   ////////////////////////////////////////////////////////////
   stdv.push_back(24);

   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;
//////////////////////////////////////////////////////////////////
   cout << "Our vector before Overload: " << v.getindex(0) << '\n';
   v = test;
   cout << "Our vector after Overload: ";
   for(int i = 0; i < v.size(); i++){
	   cout << v.getindex(i) << " ";

   }
   cout << endl;
///////////////////////////////////////////////////////////////////
	
   return 0;
}
