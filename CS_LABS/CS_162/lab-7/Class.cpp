#include "Class.h"

/*class Property{
	protected:
		int price;
		int mortgage;
		char size;
		int numberOfRestrooms;
		int numberOfRooms;
	public:
		Property();
		virtual bool operator>(const Property&, const Property&);
		virtual bool operator<(const Property&, const Property&);
};*/
Property::Property(){
	price = rand()%20000;
	mortgage = price/60;
	int temp = rand()%3;
	if(temp == 0){
		size = 'S';
		numberOfRooms = 2;
		numberOfRestrooms = 1;
	}else if(temp == 1){
		size = 'M';
		numberOfRooms = (rand()%2) + 3; //3 or 4 rooms
		numberOfRestrooms = (rand()%2) + 2;  // 2 or 3 restrooms
	}else if(temp == 2){
		numberOfRooms = 4;
		numberOfRestrooms = 5;
		size = 'L';
	}
}





/*class Apartment : public Property{
	private:
		int floor;
	public:
		Apartment();
		bool operator>(const Apartment&, const Apartment&);
		bool operator<(const Apartment&, const Apartment&);
}*/
Apartment::Apartment(){
	floor = (rand()%20) + 1;
}
bool Apartment::operator>( const Apartment&C){
	std::cout << "Price 1 = " << price << '\n';
	std::cout << "Price 2 = " << C.price << '\n';

	if(price > C.price){
		if (( int (size) ) < ( int (C.size) )){
			return true;
			//L = 76, M = 77, S = 83
		}
	}
	return false;

}
bool Apartment::operator<(const Apartment&C){
	std::cout << "Price 1 = " << price << '\n';
	std::cout << "Price 2 = " << C.price << '\n';
	std::cout << "Size 1 = " << (int (size)) << '\n';
	std::cout << "Size 2 = " <<  (int (C.size))<< '\n';
	if(price < C.price){
		if (( int (size) ) > ( int (C.size) )){
			return true;//L = 76, M = 77, S = 83
		}
	}
	return false;
}



/*class shape{
	private:
		string name;
		string color;
	public:
		string getName();
		string getColor();
		string setName(string s);
		string setColor(string s);

}*/
string shape::getName(){return name;}
string shape::getColor(){return color;}
int shape::getArea(){return area;}
void shape::setName(string s){name = s;}
void shape::setColor(string s){color = s;}

void shape::setArea(int i){area = i;}


Circle::Circle(){
	radius = (rand()%1000) +1;

}
void Circle::CalcArea(){
	int temp;
	float pi = 3.14;
	temp = ((float(radius))) * ((float(radius))) * pi;
	setArea(temp);
}
Rectangle::Rectangle(){
	x = (rand()%1000) +1;
	y = (rand()%1000) +1;
}
void Rectangle::CalcArea(){
	int temp;
	temp = (float(x)) * (float(y));
	setArea(temp);
}
