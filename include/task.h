#ifndef LAB_5_INCLUDE_TASK_H
#define LAB_5_INCLUDE_TASK_H

#include "../include/hash_table.h"

const std::vector<size_t> SIZES = { 5, 6, 7, 8, 9 };
const size_t EXPERIMENTS = 100;
const std::vector<std::string> PEOPLES = { "Ilya Mantrov", "Alyona Maslova", "Anna Starceva", "Anna Verhovaya", "Sonya Shalan", 
"Maxim Shamenkov", "Misha Nasonov", "Sasha Kinzer", "Andrey Kruglov", "Misha Barsukov", "Vlad Jirnov", "Amir Baymukashev",
"Denis Litvinov", "Vova Koscov", "Quang Min", "Van Quok", "Nikita Kudashev", "Sasha Artanov", "Polina Gololobova", "Lexa Belov" };
const size_t NUM_PEOPLES_IN_GROUP = PEOPLES.size();

double average_value_number_collisions(size_t size);

std::vector<double> list_average_collision_values();

std::vector<std::pair<size_t, double>> ratio_size_to_number_collisions(const std::vector<size_t>& size_table, const std::vector<double>& num_collision);
#endif // LAB_5_INCLUDE_ADDITIONAL_TASK_H
