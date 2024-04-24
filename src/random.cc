#include "../include/random.h"

size_t Random::random(size_t lower_bound, size_t upper_bound) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<size_t> dist(lower_bound, upper_bound);

	return dist(gen);
}