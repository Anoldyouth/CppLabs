#pragma once
#include "Classes.h"


int main()
{
    int counting = 0;
    setlocale(LC_ALL, "RUS");
    mt19937 gen1(random_device{}());
    uniform_int_distribution<> urd(5, 15);
    int count_of_ways = urd(gen1)/3;
    mt19937 gen2(random_device{}());
    int length_of_ways = urd(gen2) * 105;
    cout << "Количество путей: " << count_of_ways << endl;
    cout << "Длина путей: " << length_of_ways << endl;
    list<Way> ways;
    for(int i = 0; i<count_of_ways; i++) 
    {
        int bro = i + 1;
        Way way(bro, length_of_ways);
        ways.push_back(way);
    }

    bool checking = true;
    thread searching_for_end(work_hard, ref(ways), ref(checking));
    searching_for_end.detach();

    int i = 0;
    while (!ways.empty() && (ways.size() != 1 || ways.back().get_accident_rate()))
    {
        mt19937 gen_train(random_device{}());
        uniform_int_distribution<> count(1, 9);
        mt19937 gen_direction(random_device{}());
        uniform_int_distribution<> direction(0, 1);
        bool direct;
        int random = direction(gen_direction);
        string text;
        if (random == 0) {
            direct = false;
            text = "запад";
        }
        else {
            direct = true;
            text = "восток";
        }
        Trainset* train = new Trainset(i+1, count(gen_train) * 15 + 15, direct);
        printf("Состав создан! Длина: %d, направление: %s, номер: %d\n", train->get_length(), text.c_str(), train->get_number());
        thread trainset(search_of_way, ref(*train), ref(ways), ref(checking), ref(counting));

        trainset.detach();
        i++;
        this_thread::sleep_for(chrono::seconds(1));
    }
    while(checking) this_thread::sleep_for(chrono::seconds(1));
    printf("Все пути на ремонте, конец рабочего дня\n");
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Всего перегнано составов: " << counting << endl;
    return 0;
}
