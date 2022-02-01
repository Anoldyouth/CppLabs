#include "Classes.h"


Speed::Speed() : Physics()
	{
	};

Speed::Speed(double x, double y, double z) : Physics(x,y,z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Speed Speed:: operator + (const Speed& obj)
	{
		return Speed(this->x + obj.x, this->y + obj.y, this->z + obj.z);
	}

	Speed Speed::operator - (const Speed& obj)
	{
		return Speed(this->x - obj.x, this->y - obj.y, this->z - obj.z);
	}

	Speed Speed::operator * (const double& scalar)
	{
		return Speed(this->x * scalar, this->y * scalar, this->z * scalar);
	}

	Pulse Speed::operator * (const Mass& mass)
	{
		return Pulse(this->x * mass.value, this->y * mass.value, this->z * mass.value);
	}

	Energy Speed::operator*(const Pulse& obj)
	{
		return Energy(this->abs() * obj.abs() / 2);
	}

	Speed Speed::operator / (const double& scalar)
	{
		return Speed(this->x / scalar, this->y / scalar, this->z / scalar);
	}

	bool Speed::print_info()
	{
		cout << "Speed class" << endl;
		return false;
	}
	
	std::ostream& operator << (std::ostream& out, const Speed& obj)
	{
		out << obj.x << ", " << obj.y << ", " << obj.z << "mps";
		return out;
	}
	/*
	double Speed::abs() const
	{
		return double(sqrt((this->x) * this->x + this->y * this->y + this->z * this->z));
	}

	std::istream& operator >> (std::istream& in, Speed& obj) {
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

	bool SpeedABS::print_info()
	{
		cout << "SpeedABS class" << endl;
		return false;
	}

	SpeedABS:: SpeedABS(double sp_value): PhysicsABS(sp_value)  {
		value = sp_value;
	}
	 /*
	double SpeedABS:: get_value() const {
		return value;
	}

	std::partial_ordering SpeedABS::operator<=>(const SpeedABS& obj) const 
	{
		std::partial_ordering test = value <=> obj.get_value();
		return test;
	}
	*/
std::ostream& operator << (std::ostream& out, const SpeedABS& obj) {
	return out << obj.get_value() << "mps";
}


SpeedABS operator "" mps(long double value) {
	return SpeedABS(value);
}