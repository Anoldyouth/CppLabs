#pragma once
#include "Classes.h"

void ride(Trainset& train, Way &way, int& counting)
{
	int full_way = way.get_length_of_way() - train.get_length();
	while (train.get_distance_traveled() < full_way)
	{
		train.set_distanse_traveled(train.get_distance_traveled() + 15);
		this_thread::sleep_for(chrono::milliseconds(50));
	}
	printf("Поезд номер %d на пути %d закончил поездку\n", train.get_number(), way.get_number());
	way.check.lock();
	counting++;
	way.set_trains(way.removing(train));
	way.check.unlock();
}

Way::Way(const Way& way)
{
	number_of_way = way.number_of_way;
	length_of_way = way.length_of_way;
	accident_rate = way.accident_rate;
}

Way::Way(int& number_of_way_value, int& length)
{
	number_of_way = number_of_way_value;
	length_of_way = length;
	accident_rate = true;
}

int Way::get_number() const
{
	return number_of_way;
}

int Way::get_length_of_way() const
{
	return length_of_way;
}

bool Way::get_accident_rate() const
{
	return accident_rate;
}

list<Trainset*> Way::get_trains() const
{
	return trains;
}

void Way::set_number(const int& number)
{
	number_of_way = number;
}

void Way::set_length(const int& length)
{
	length_of_way = length;
}

void Way::set_trains(const list<Trainset*>& trains_value)
{
	trains.clear();
	for (Trainset* train : trains_value)
	{
		trains.push_back(train);
	}
}

void Way::set_rate(const bool& rate)
{
	accident_rate = rate;
}


bool Way::start_ride(Trainset& train, int &counting)
{
	check.lock();
	if (trains.empty() || ((train.get_direction() == trains.back()->get_direction()) && (trains.back()->get_distance_traveled() > train.get_length())))
	{
		trains.push_back(&train);
		printf("Поезд поехал! Состав номер %d, путь номер %d\n", train.get_number(), this->get_number());
		thread riding(ride, ref(train), ref(*this), ref(counting));
		riding.detach();
		check.unlock();
		return true;
	}
	check.unlock();
	return false;
}

list<Trainset*> Way::removing(Trainset& train_value)
{
	list<Trainset*> new_list;
	for (Trainset* train : trains)
	{
		if (!(*train == train_value)) new_list.push_back(train);
	}
	return new_list;
}


