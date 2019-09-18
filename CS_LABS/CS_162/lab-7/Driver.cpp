#include "Class.h"

int main(){
	srand(time(NULL));
	Apartment P1;
	Apartment P2;
	if (P1 > P2)
		std::cout << "Apartment 1 is bigger and more costly than Apartment 2" << '\n';
	else if (P1 < P2)
		std::cout << "Apartment 1 is smaller and less costly than Apartment 2\n";
	else
		std::cout << "They are equal " << '\n';

	Rectangle Rec1;
	Circle Circle1;
	Rec1.CalcArea();
	Circle1.CalcArea();
	if(Rec1.getArea() > Circle1.getArea())
		std::cout << "Rec is bigger than Cir" << '\n';
	else
		std::cout << "Rec is smaller than Cir" << '\n';

		shape * p = 
}
