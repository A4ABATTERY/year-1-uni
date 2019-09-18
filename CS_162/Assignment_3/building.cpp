

#include "building.h"


/********************************************************
class Building{
	protected:
		float value;
		int location;
		float mortgage;
		static float tax;
		int num_tenants;
		person *tenants;
	public:
		Building();

		static void initializeTax();

		float getValue();
		int getLocation();
		float getMortgage();


		void setValue(int);
		// void setLocation(int);
		void setMortgage(int);
		void setNumTenants(int);
		void setTenants(person*);

		Building(const Building&);
		~Building();
		const Building& operator=(const Building&);



};
*******************************************************/
Building::Building(){
	max_startprice = 600000;
	// value = (rand()%(max_startprice - min_startprice)) + min_startprice + 1;
	location = (rand()%5 + 1); //1= NW, 2= SW, 3=MidW, 4= SE, 5 = NE
	 // std::cout << "Value: " << value << '\n';
	 // std::cout << "location: " << location <<'\n';
	 // std::cout << "mortgage: " << mortgage << '\n';
	tax = 0.015;
	owned = false;

}



float Building::getValue() {return value;}
int Building::getLocation() {return location;}
float Building::getMortgage() {return mortgage;}
float Building::getTax() {return tax;}

void Building::setValue(int i) {value = i;}
void Building::setMortgage(int i) {mortgage = i;}

Building::Building(const Building&O){
	value = O.value;
	location = O.location;
	mortgage = O.mortgage;

}

const Building& Building::operator=(const Building&O){
	value = O.value;
	location = O.location;
	mortgage = O.mortgage;
	value = O.value;
	location = O.location;
	mortgage = O.location;
	owned = O.owned;
	return *this;
}
