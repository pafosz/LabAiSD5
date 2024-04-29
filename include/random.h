#ifndef LAB_5_INCLUDE_RANDOM_H
#define LAB_5_INCLUDE_RANDOM_H

#include <iostream>
#include <random>
#include <type_traits>

#include "../include/hash_table.h"

size_t random(size_t lower_bound, size_t upper_bound);

size_t lcg();

std::string generate_random_string(size_t min_length, size_t max_length);

int generate_random_int(int min, int max);

double generate_random_double(double min, double max, int numDecimalPlaces);


#endif LAB_5_INCLUDE_HASHTABLE_H

