#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <mutex>
#include <list>
#include <thread>

using namespace std;

class Trainset;
class Way;

class Trainset
{
	int number;
	int length;
	bool direction; //true - восток, false - запад
	int distance_traveled;

public:
	Trainset(int number,const int& length_value, const bool& direction_value);

	Trainset(const Trainset& train);

	int get_number() const;
	
	int get_length() const;
	
	int get_distance_traveled() const;

	bool get_direction() const;

	void set_number(const int& number_value);

	void set_length(const int& length_value);

	void set_distanse_traveled(const int& distanse_value);

	void set_direction(const bool& direction_value);

	bool operator==(const Trainset& train);
	
};

int search_of_way(Trainset &train, list<Way>& ways, bool& checking, int& counting);

class Way
{
	int number_of_way;
	int length_of_way;
	list<Trainset*> trains;
	bool accident_rate; //true - рабочий, false - на ремонте

public:
	mutex check;

	Way(const Way& way);
	Way(int& number_of_way_value, int& length);

	int get_number() const;

	int get_length_of_way() const;

	bool get_accident_rate() const;

	list<Trainset*> get_trains() const;

	void set_number(const int& number);

	void set_length(const int& length);

	void set_trains(const list<Trainset*>& trains_value);

	void set_rate(const bool& rate);

	bool start_ride(Trainset& train, int & counting);

	list<Trainset*> removing(Trainset& train);
};

bool operator==(const Trainset& train1, const Trainset& train2);

void work_hard(list<Way>& ways, bool& checking);