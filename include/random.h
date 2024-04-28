#ifndef LAB_5_INCLUDE_RANDOM_H
#define LAB_5_INCLUDE_RANDOM_H

#include <iostream>
#include <random>
#include <type_traits>

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

std::string generate_random_string(size_t min_length, size_t max_length) {
    static const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> length_dis(min_length, max_length);
    std::uniform_int_distribution<size_t> char_dis(0, characters.size() - 1);

    size_t length = length_dis(gen);
    std::string result(length, 0);
    for (size_t i = 0; i < length; ++i) {
        result[i] = characters[char_dis(gen)];
    }
    return result;
}

int generate_random_int(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

double generate_random_double(double min, double max, int numDecimalPlaces) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(min, max);
    double result = dis(gen);
    return static_cast<double>(static_cast<int>(result * std::pow(10, numDecimalPlaces))) / std::pow(10, numDecimalPlaces);
}


//HashTable<int, std::string> generate_random_ht_i_s(size_t degree_of_two) {
//    HashTable<int, std::string> ht(degree_of_two);
//
//}

#endif LAB_5_INCLUDE_HASHTABLE_H

