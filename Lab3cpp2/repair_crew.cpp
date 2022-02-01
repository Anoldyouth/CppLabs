#pragma once
#include "Classes.h"

void work_hard(list<Way>& ways, bool& checking)
{
	while (!ways.empty())
	{
		for (auto iter = ways.begin(); iter != ways.end(); iter++)
		{
			mt19937 gen(random_device{}());
			uniform_int_distribution<> urd(1, 10);
			int chanse = urd(gen);
			if (chanse == 1 || chanse == 2) {
				(*iter).set_rate(false);
				printf("                                                                Путь номер %d признан аварийным! Ожидание освобождения пути\n", (*iter).get_number());
				if ((*iter).get_accident_rate() == false)
					while (!(*iter).get_trains().empty()) this_thread::sleep_for(chrono::seconds(1));
				printf("                                                                Путь номер %d закрыт на ремонт\n", (*iter).get_number());
				ways.erase(iter);
				break;
			}
		}
		this_thread::sleep_for(chrono::seconds(1));
	}
	checking = false;
	cout << "Ну, поработали и достаточно" << endl;
}

