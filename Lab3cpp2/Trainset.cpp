#pragma once
#include "Classes.h"

Trainset::Trainset(int number_value, const int& length_value, const bool& direction_value)
{
	number = number_value;
	length = length_value;
	direction = direction_value;
	distance_traveled = 0;
}

Trainset::Trainset(const Trainset& train)
{
	number = train.number;
	length = train.length;
	direction = train.direction;
	distance_traveled = train.distance_traveled;
}

int Trainset::get_number() const
{
	return number;
}

int Trainset::get_length() const
{
	return length;
}

int Trainset::get_distance_traveled() const
{
	return distance_traveled;
}

bool Trainset::get_direction() const
{
	return direction;
}

void Trainset::set_number(const int& number_value)
{
	number = number_value;
}

void Trainset::set_length(const int& length_value)
{
	length = length_value;
}

void Trainset::set_distanse_traveled(const int& distanse_value)
{
	distance_traveled = distanse_value;
}

void Trainset::set_direction(const bool& direction_value)
{
	direction = direction_value;
}


bool Trainset::operator==(const Trainset& train)
{
	return((number == train.number));
}

int search_of_way(Trainset &train, list<Way> &ways, bool& checking, int &counting)
{
	while (checking)
	{
		for (auto iter = ways.begin(); iter != ways.end(); iter++)
		{
			if ((*iter).get_accident_rate())
			{
				if ((*iter).start_ride(ref(train), ref(counting)))
				{
					return 0;
				}
			}
		}
		this_thread::sleep_for(chrono::seconds(2));
	}
	return 0;
}

bool operator==(const Trainset& train1, const Trainset& train2)
{
	return((train1.get_number() == train2.get_number()));
}
