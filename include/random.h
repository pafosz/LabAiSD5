#ifndef LAB_5_INCLUDE_RANDOM_H
#define LAB_5_INCLUDE_RANDOM_H

#include <iostream>
#include <random>
#include "../include/hash_table.h"


size_t random(size_t lower_bound, size_t upper_bound) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<size_t> dist(lower_bound, upper_bound);

	return dist(gen);
}

size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}





#endif LAB_5_INCLUDE_HASHTABLE_H

