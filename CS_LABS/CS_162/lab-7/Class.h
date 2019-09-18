#include <iostream>
#include <cstdlib>
#include <string>

using std::string;

class Property{
	protected:
		int price;
		int mortgage;
		char size;
		int numberOfRestrooms;
		int numberOfRooms;
	public:
		Property();
		// virtual bool operator>(const Property&);
		// virtual bool operator<(const Property&);
};
class Apartment : public Property{
	private:
		int floor;
	public:
		Apartment();
		bool operator>(const Apartment&);
		bool operator<(const Apartment&);
};

class shape{
	private:
		string name;
		string color;
		int area;
	public:
		string getName();
		string getColor();
		int getArea();
		void setName(string s);
		void setColor(string s);
		void setArea(int i);
		virtual void CalcArea() = 0;
};
class Circle : public shape{
	private:
		int radius;
		int area;
	public:
		Circle();
		void CalcArea();

};
class Rectangle : public shape{
	private:
		int x, y;
		int area;
	public:
		Rectangle();
		void CalcArea();
};
