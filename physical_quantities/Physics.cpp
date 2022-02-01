#include "Classes.h"

Physics::Physics()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Physics::Physics(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Physics::Physics(const Physics& obj)
{
	this->x = obj.x;
	this->y = obj.y;
	this->z = obj.z;
}

Physics::Physics(Physics&& obj)
{
	this->x = move(obj).x;
	this->y = move(obj).y;
	this->z = move(obj).z;
}

Physics& Physics::operator=(const Physics& obj)
{
	if (*this == obj) {
		return *this;
	}
	this->x = obj.x;
	this->y = obj.y;
	this->z = obj.z;

	return *this;
}

Physics& Physics::operator=(Physics&& obj)
{

	if (*this == move(obj)) {
		return *this;
	}
	this->x = move(obj).x;
	this->y = move(obj).y;
	this->z = move(obj).z;
	
	return *this;
}

bool Physics::print_info()
{
	cout << "Physics class" << endl;
	return false;
}

bool Physics::operator==(const Physics& obj)
{
	return this->x == obj.x && this->y == obj.y && this->z == obj.z;
}

double Physics::abs() const
{
	return sqrt((this->x) * this->x + this->y * this->y + this->z * this->z);
}


PhysicsABS::PhysicsABS(double abs_acc) {
	value = abs_acc;
}

PhysicsABS::PhysicsABS(const PhysicsABS& obj)
{
	this->value = obj.value;
}

PhysicsABS::PhysicsABS(PhysicsABS&& obj)
{
	this->value = move(obj).value;
}

bool PhysicsABS::operator==(const PhysicsABS& obj)
{
	return this->value == obj.value;
}

bool PhysicsABS::print_info()
{
	cout << "PhysicsABS class" << endl;
	return false;
}

PhysicsABS& PhysicsABS::operator=(const PhysicsABS& obj)
{
	if (*this == obj)
		return *this;
	this->value = obj.value;
	return *this;
}

PhysicsABS& PhysicsABS::operator=(PhysicsABS&& obj)
{
	if (*this == obj)
		return *this;
	this->value = move(obj).value;
	return *this;
}

double PhysicsABS::get_value() const
{
	return value;
}

partial_ordering PhysicsABS::operator<=>(const PhysicsABS& obj) const {
	return value <=> obj.get_value();
}

std::istream& operator >> (std::istream& in, Physics& obj) {
	while (!(in >> obj.x >> obj.y >> obj.z)) {
		in.clear();
		in.ignore(100, '\n');
		std::cout << "Input double number" << std::endl;
	}
	in.clear();
	in.ignore(100, '\n');
	return in;
}

std::istream& operator >> (std::istream& in, PhysicsABS& obj) {
	while (!(in >> obj.value)) {
		in.clear();
		in.ignore(100, '\n');
		std::cout << "Input double number" << std::endl;
	}
	in.clear();
	in.ignore(100, '\n');
	return in;
}

std::shared_ptr<Physics> make_shared_ptr(string strliteral) {
	cmatch m;
	
	regex mpss("(mpss)");
	regex mps("(mps)");
	regex kgmps("(kgmps)");
	regex N("(N)");
	
	shared_ptr<Physics> ptr;
	double x = 10;
	double y = 10;
	double z = 10;
	if (strliteral.empty()) {
		return 0;
	}
	else {
		if (regex_match(strliteral.c_str(), m, mpss)) {
			ptr = make_shared<Acceleration>(x, y, z);
		}
		else if (regex_match(strliteral.c_str(), m, mps)) {
			ptr = make_shared<Speed>(x, y, z);
		}
		else if (regex_match(strliteral.c_str(), m, kgmps)) {
			ptr = make_shared<Pulse>(x, y, z);
		}
		else if (regex_match(strliteral.c_str(), m, N)) {
			ptr = make_shared<Force>(x, y, z);
		}
	}
	return ptr;
}

std::shared_ptr<PhysicsABS> make_shared_ptr1(string strliteral)
{
	cmatch m;
	double x = 10;
	regex mpss("(mpss)");
	regex mps("(mps)");
	regex kgmps("(kgmps)");
	regex N("(N)");
	regex J("(J)");
	regex kg("(kg)");

	shared_ptr<PhysicsABS> ptr;
	if (strliteral.empty()) {
		return 0;
	}
	else {
		if (regex_match(strliteral.c_str(), m, mpss)) {
			ptr = make_shared<AccelerationABS>(x);
		}
		else if (regex_match(strliteral.c_str(), m, mps)) {
			ptr = make_shared<SpeedABS>(x);
		}
		else if (regex_match(strliteral.c_str(), m, kgmps)) {
			ptr = make_shared<PulseABS>(x);
		}
		else if (regex_match(strliteral.c_str(), m, N)) {
			ptr = make_shared<ForceABS>(x);
		}
		else if (regex_match(strliteral.c_str(), m, kg)) {
			ptr = make_shared<Mass>(x);
		}
		else if (regex_match(strliteral.c_str(), m, J)) {
			ptr = make_shared<Energy>(x);
		}
	}
	return ptr;
}


/*
std::ostream& operator << (std::ostream& out, const Physics& obj)
{
	out << obj.x << ", " << obj.y << ", " << obj.z;
	if (strcmp(typeid(obj).name(),"Speed") == 0) {
		out << "mps";
	}
	if (strcmp(typeid(obj).name(), "Acceleration") == 0) {
		out << "mpss";
	}
	if (strcmp(typeid(obj).name(), "Force") == 0) {
		out << "N";
	}
	if (strcmp(typeid(obj).name(), "Pulse") == 0) {
		out << "kgmps";
	}
	return out;
}

std::ostream& operator << (std::ostream& out, const PhysicsABS& obj) {
	out << obj.get_value();
		
	if (strcmp(typeid(obj).name(), "SpeedABS")==0) {
		out << "mps";
	}
	if (strcmp(typeid(obj).name(), "AccelerationABS") == 0) {
		out << "mpss";
	}
	if (strcmp(typeid(obj).name(), "ForceABS") == 0) {
		out << "N";
	}
	if (strcmp(typeid(obj).name(), "PulseABS") == 0) {
		out << "kgmps";
	}
	if (strcmp(typeid(obj).name(), "Mass") == 0) {
		out << "kg";
	}
	if (strcmp(typeid(obj).name(), "Energy") == 0) {
		out << "I";
	}
	return out;
}
*/