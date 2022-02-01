#include "Classes.h"

Pulse::Pulse() : Physics()
	{
	};

Pulse::Pulse(double x, double y, double z) : Physics(x,y,z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

bool Pulse::print_info()
{
	cout << "Pulse class" << endl;
	return false;
}

	Pulse Pulse:: operator + (const Pulse& obj)
	{
		return Pulse(this->x + obj.x, this->y + obj.y, this->z + obj.z);
	}

	Pulse Pulse:: operator - (const Pulse& obj)
	{
		return Pulse(this->x - obj.x, this->y - obj.y, this->z - obj.z);
	}

	Pulse Pulse::operator * (const double& scalar)
	{
		return Pulse(this->x * scalar, this->y * scalar, this->z * scalar);
	}

	Energy Pulse::operator * (const Speed& obj)
	{
		return Energy(this->abs() * obj.abs());
	}

	Pulse Pulse::operator / (const double& scalar)
	{
		return Pulse(this->x / scalar, this->y / scalar, this->z / scalar);
	}

	Speed Pulse::operator / (const Mass& obj)
	{
		return Speed(this->x / obj.value, this->y / obj.value, this->z / obj.value);
	}

	/*
	double Pulse::abs() const
	{
		return double(sqrt((this->x) * this->x + this->y * this->y + this->z * this->z));
	}
	*/
	Mass Pulse::operator / (const Speed& obj)
	{
		return Mass(this->abs() / obj.abs());
	}
	/*
	std::istream& operator >> (std::istream& in, Pulse& obj) {
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
	std::ostream& operator << (std::ostream& out, const Pulse& obj)
	{
		out << obj.x << ", " << obj.y << ", " << obj.z << "kgmps";
		return out;
	}
	
	bool PulseABS::print_info()
	{
		cout << "PulseABS class" << endl;
		return false;
	}

	PulseABS:: PulseABS(double pabsvalue) : PhysicsABS(pabsvalue) {
		value = pabsvalue;
	}
	
	/*
	double PulseABS::get_value() const {
		return value;
	}

	auto PulseABS:: operator<=>(const PulseABS& obj) const {
		return value <=> obj.get_value();
	}
	*/
std::ostream& operator << (std::ostream& out, const PulseABS& obj) {
	return out << obj.get_value() << "kgmps";
}

PulseABS operator "" kgmps(long double value) {
	return PulseABS(value);
}