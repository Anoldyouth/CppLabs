#include "Classes.h"

bool Energy::print_info()
{
	cout << "Energy class" << endl;
	return false;
}

Energy::Energy(double energy) : PhysicsABS(energy)
	{
		this->value = energy;
	}

	Energy Energy:: operator +(const Energy& obj)
	{
		return Energy(this->value + obj.value);
	}

	Energy Energy::operator -(const Energy& obj)
	{
		return Energy(this->value - obj.value);
	}

	Energy Energy::operator *(const double& scalar)
	{
		return Energy(this->value * scalar);
	}

	Energy Energy::operator /(const double& scalar)
	{
		return Energy(this->value / scalar);
	}

	PulseABS Energy:: operator / (const Speed& obj)
	{
		return PulseABS(2 * this->value / obj.abs());
	}

	SpeedABS Energy:: operator / (const Pulse& obj)
	{
		return SpeedABS(2 * this->value / obj.abs());
	}

	/*
	double Energy::get_value() const {
		return value;
	}

	std::istream& operator >> (std::istream& in, Energy& obj) {
		while (!(in >> obj.energy)) {
			in.clear();
			in.ignore(100, '\n');
			std::cout << "Input double number" << std::endl;
		}
		in.clear();
		in.ignore(100, '\n');
		return in;
	}

	auto Energy:: operator<=>(const Energy& obj) const {
		return energy <=> obj.get_value();
	}
*/
std::ostream& operator << (std::ostream& out, const Energy& obj) {
	return out << obj.get_value() << "J";
}


Energy operator "" J(long double value) {
	return Energy(value);
}