#ifndef LAB_5_INCLUDE_RANDOM_H
#define LAB_5_INCLUDE_RANDOM_H

#include <iostream>
#include <random>

namespace Random {

	size_t random(size_t lower_bound, size_t upper_bound) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<size_t> dist(lower_bound, upper_bound);

		return dist(gen);
	}
}


#endif LAB_5_INCLUDE_HASHTABLE_H

