#include "Classes.h"




Mass::Mass(double mass) : PhysicsABS(mass)
	{
		this->value = mass;
	}

	Mass Mass:: operator +(const Mass& obj)
	{
		return Mass(this->value + obj.value);
	}

	Mass Mass:: operator -(const Mass& obj)
	{
		return Mass(this->value - obj.value);
	}

	Mass Mass:: operator *(const double& scalar)
	{
		return Mass(this->value * scalar);
	}

	Force Mass:: operator *(const Acceleration& obj)
	{
		return Force(this->value * obj.x, this->value * obj.y, this->value * obj.z);
	}

	Pulse Mass:: operator *(const Speed& obj)
	{
		return Pulse(this->value * obj.x, this->value * obj.y, this->value * obj.z);
	}

	Mass Mass:: operator /(const double& scalar)
	{
		return Mass(this->value / scalar);
	}

	bool Mass::print_info()
	{
		cout << "Mass class" << endl;
 		return false;
	}

	/*
	double Mass::get_value() const {
		return mass;
	}

	std::istream& operator >> (std::istream& in, Mass& obj) {
		while (!(in >> obj.mass)) {
			in.clear();
			in.ignore(100, '\n');
			std::cout << "Input double number" << std::endl;
		}
		in.clear();
		in.ignore(100, '\n');
		return in;
	}

	partial_ordering Mass:: operator <=>(const Mass& obj) const {
		return mass <=> obj.get_value();
	}
	*/
std::ostream& operator << (std::ostream& out, const Mass& obj) {
	return out << obj.get_value() << "kg";
}

Mass operator "" kg(long double value) {
	return Mass(value);
}