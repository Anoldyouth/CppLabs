#include "Classes.h"


bool Force::print_info()
{
	cout << "Force class" << endl;
	return false;
}

Force::Force() : Physics()
	{
	};

	Force::Force(double x, double y, double z) : Physics(x,y,z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Force Force:: operator + (const Force& obj)
	{
		return Force(this->x + obj.x, this->y + obj.y, this->z + obj.z);
	}

	Force Force:: operator - (const Force& obj)
	{
		return Force(this->x - obj.x, this->y - obj.y, this->z - obj.z);
	}

	Force Force:: operator * (const double& scalar)
	{
		return Force(this->x * scalar, this->y * scalar, this->z * scalar);
	}

	Force Force:: operator / (const double& scalar)
	{
		return Force(this->x / scalar, this->y / scalar, this->z / scalar);
	}

	Acceleration Force:: operator / (const Mass& obj)
	{
		return Acceleration(this->x / obj.value, this->y / obj.value, this->z / obj.value);
	}

	/*
	double Force::abs() const
	{
		return double(sqrt((this->x) * this->x + this->y * this->y + this->z * this->z));
	}
	*/
	Mass Force:: operator / (const Acceleration& obj)
	{
		return Mass(this->abs() / obj.abs());
	}
	/*
	std::istream& operator >> (std::istream& in, Force& obj) {
		while (!(in >> obj.x >> obj.y >> obj.z)) {
			in.clear();
			in.ignore(100, '\n');
			std::cout << "Input double number" << std::endl;
		}
		in.clear();
		in.ignore(100, '\n');
		return in;
	}
	*/
	std::ostream& operator << (std::ostream& out, const Force& obj)
	{
		out << obj.x << ", " << obj.y << ", " << obj.z << "N";
		return out;
	}
	
	ForceABS:: ForceABS(double fabsvalue) : PhysicsABS(fabsvalue) {
		value = fabsvalue;
	}
	bool ForceABS::print_info()
	{
		cout << "ForceABS class" << endl;
		return false;
	}
	/*
	double ForceABS:: get_value() const {
		return value;
	}

	auto ForceABS:: operator<=>(const ForceABS& obj) const {
		return value <=> obj.get_value();
	}
	*/
std::ostream& operator << (std::ostream& out, const ForceABS& obj) {
	return out << obj.get_value() << "N";
}

ForceABS operator "" N(long double value) {
	return ForceABS(value);
}
