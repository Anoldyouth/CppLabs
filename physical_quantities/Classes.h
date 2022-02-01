#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cmath>
#include <compare> 
#include <fstream>
#include <string>
#include <regex>
#include <memory>

class Physics;
class PhysicsABS;
class Acceleration;
class Force;
class Speed;
class Pulse;
class Energy;
class Mass;
class AccelerationABS;
class SpeedABS;
class ForceABS;
class PulseABS;

using namespace std;


class Physics {
public: 
	double x, y, z;
	Physics();
	Physics(double x, double y, double z);
	Physics(const Physics& obj);
	Physics(Physics&& obj);

	Physics& operator = (const Physics& obj);
	Physics& operator = (Physics&& obj);

	virtual	bool print_info();
	bool operator == (const Physics& obj);
	double abs() const;
};
std::shared_ptr<Physics> make_shared_ptr(string literal);

std::shared_ptr<PhysicsABS> make_shared_ptr1(string literal);

class PhysicsABS {
public:
	double value;
	double get_value() const;
	PhysicsABS(double abs_val);

	PhysicsABS(const PhysicsABS& obj);
	PhysicsABS(PhysicsABS&& obj);

	bool operator == (const PhysicsABS& obj);
	virtual	bool print_info();
	PhysicsABS& operator = (const PhysicsABS& obj);
	PhysicsABS& operator = (PhysicsABS&& obj);

	partial_ordering operator <=>(const PhysicsABS& obj) const;
};

class Acceleration : public Physics
{
public:
	
	Acceleration();
	Acceleration(double x, double y, double z);
	Acceleration(const Acceleration& obj);

	virtual	bool print_info();

	Acceleration operator + (const Acceleration& obj);
	Acceleration operator - (const Acceleration& obj);
	Acceleration operator * (const double& scalar);
	
	Force operator * (const Mass& mmass);
	
	Acceleration operator / (const double& scalar);
	

	//double abs() const;
	
};

std::ostream& operator << (std::ostream& out, const Acceleration& obj);

std::istream& operator >> (std::istream& in, Physics& obj);

//std::ostream& operator << (std::ostream& out, const Physics& obj);

class AccelerationABS : public PhysicsABS {
public:
	//double value;
	virtual	bool print_info();
	AccelerationABS(double abs_acc);
	//double get_value() const;
	//auto operator <=>(const AccelerationABS& obj) const;
};

//std::ostream& operator << (std::ostream& out, const PhysicsABS& obj);

std::ostream& operator << (std::ostream& out, const AccelerationABS& obj);

AccelerationABS operator "" mpss(long double value);

class Mass : public PhysicsABS
{
public:

	//double mass;

	
	Mass(double mass);

	Mass operator +(const Mass& obj);
	Mass operator -(const Mass& obj);
	Mass operator *(const double& scalar);
	Force operator *(const Acceleration& obj);
	Pulse operator *(const Speed& obj);
	Mass operator /(const double& scalar);
	virtual	bool print_info();
	//double get_value() const; 
	// 
	//partial_ordering operator<=>(const Mass& obj) const;
};


std::ostream& operator << (std::ostream& out, const Mass& obj);

Mass operator "" kg(long double value);

class Speed : public Physics
{
public:
	//double x, y, z;

	Speed();
	Speed(double x, double y, double z);

	Speed operator + (const Speed& obj);
	Speed operator - (const Speed& obj);
	Speed operator * (const double& scalar);
	Pulse operator * (const Mass& mass);
	Energy operator * (const Pulse& pulse);
	Speed operator / (const double& scalar);
	//double abs() const;
	virtual	bool print_info();
};
//std::istream& operator >> (std::istream& in, Speed& obj);
std::ostream& operator << (std::ostream& out, const Speed& obj);

class SpeedABS : public PhysicsABS {
public:
	//double value;
	virtual	bool print_info();
	SpeedABS(double sp_value);
	//double get_value() const;
	//std::partial_ordering operator <=> (const SpeedABS& obj) const;
		
};

std::ostream& operator << (std::ostream& out, const SpeedABS& obj);

SpeedABS operator "" mps(long double value);

class Force : public Physics
{
public:
	//double x, y, z;
	virtual	bool print_info();
	Force();
	Force(double x, double y, double z);

	Force operator + (const Force& obj);
	Force operator - (const Force& obj);
	Force operator * (const double& scalar);
	Force operator / (const double& scalar);
	Acceleration operator / (const Mass& obj);
	//double abs() const;
	Mass operator / (const Acceleration& obj);
	
};
//std::istream& operator >> (std::istream& in, Force& obj);

std::ostream& operator << (std::ostream& out, const Force& obj);

class ForceABS : public PhysicsABS
{
public:
	//double value;
	ForceABS(double fabsvalue);
	//~ForceABS();
	virtual	bool print_info();
	//double get_value() const;
	//auto operator<=>(const ForceABS& obj) const;
};


std::ostream& operator << (std::ostream& out, const ForceABS& obj);

ForceABS operator "" N(long double value);


class Pulse : public Physics
{
public:
	//double x, y, z;

	Pulse();
	Pulse(double x, double y, double z);
	virtual	bool print_info();
	Pulse operator + (const Pulse& obj);
	Pulse operator - (const Pulse& obj);
	Pulse operator * (const double& scalar);
	Energy operator * (const Speed& obj);
	Pulse operator / (const double& scalar);
	Speed operator / (const Mass& obj);
	//double abs() const;
	Mass operator / (const Speed& obj);

	
};
//std::istream& operator >> (std::istream& in, Pulse& obj);

std::ostream& operator << (std::ostream& out, const Pulse& obj);

class PulseABS : public PhysicsABS {
public:
	//double value;
	virtual	bool print_info();
	PulseABS(double pabsvalue);
	//~PulseABS();
	//double get_value() const;
	//auto operator<=>(const PulseABS& obj) const;
};

std::ostream& operator << (std::ostream& out, const PulseABS& obj);

PulseABS operator "" kgmps(long double value);

class Energy : public PhysicsABS
{
public:
	//double energy;
	virtual	bool print_info();
	//Energy();

	Energy(double energy);

	Energy operator +(const Energy& obj);

	Energy operator -(const Energy& obj);

	Energy operator *(const double& scalar);
	Energy operator /(const double& scalar);

	PulseABS operator / (const Speed& obj);

	SpeedABS operator / (const Pulse& obj);

	//double get_value() const;
	
	//auto operator<=>(const Energy& obj) const;
};
//std::istream& operator >> (std::istream& in, Energy& obj);

std::ostream& operator << (std::ostream& out, const Energy& obj);

Energy operator "" J(long double value);
