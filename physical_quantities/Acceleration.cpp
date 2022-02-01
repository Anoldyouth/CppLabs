#include "Classes.h"

Acceleration::Acceleration() :Physics(){}


Acceleration::Acceleration(double x , double y, double z): Physics(x,y,z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

bool Acceleration::print_info()
{
	cout << "Acceleration class" << endl;
	return false;
}

Acceleration Acceleration:: operator + (const Acceleration& obj)
{
	return Acceleration(this->x + obj.x, this->y + obj.y, this->z + obj.z);
}

Acceleration Acceleration:: operator - (const Acceleration& obj)
{
	return Acceleration(this->x - obj.x, this->y - obj.y, this->z - obj.z);
}

Acceleration Acceleration:: operator * (const double& scalar)
{
	return Acceleration(this->x * scalar, this->y * scalar, this->z * scalar);
}

Force Acceleration::operator * (const Mass& mmass)
{
	return Force(this->x * mmass.value, this->y * mmass.value, this->z * mmass.value);
}

Acceleration Acceleration:: operator / (const double& scalar)
{
	return Acceleration(this->x / scalar, this->y / scalar, this->z / scalar);
}


/*
std::istream& operator >> (std::istream& in, Acceleration& obj) {
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
std::ostream& operator << (std::ostream& out, const Acceleration& obj)
{
	out << obj.x << ", " << obj.y << ", " << obj.z << "mpss";;
	return out;
}



std::ostream& operator << (std::ostream& out, const AccelerationABS& obj) {
	return out << obj.get_value() << "mpss";
}


AccelerationABS operator "" mpss(long double value) {
	return AccelerationABS(value);
}

bool AccelerationABS::print_info()
{
	cout << "AccelerationABS class" << endl;
	return false;
}

AccelerationABS::AccelerationABS(double v) : PhysicsABS(v) {
	value = v;
}