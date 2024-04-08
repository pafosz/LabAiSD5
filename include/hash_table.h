#ifndef LAB_5_INCLUDE_HASHTABLE_H
#define LAB_5_INCLUDE_HASHTABLE_H

#include <iostream>
#include <vector>
#include <cmath>
#include <random>

size_t random(size_t lower_bound, size_t upper_bound) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<size_t> dist(lower_bound, upper_bound);

	return dist(gen);
}

#define LOAD_FACTOR_THRESHOLD = 0.7

template<typename K, typename V>
class HashTable {
	struct Pair {
		K key;
		V value;
		bool not_empty;
		Pair(const K& key, const V& value) : key(key), value(value), not_empty(false) {}
	};
	std::vector<Pair> _data;
	size_t _size;
	size_t _degree_of_two;
	static const size_t w = sizeof(K) * 8;
	inline static size_t a = (random(0, pow(2, w)) | 1);


	static size_t random(size_t lower_bound, size_t upper_bound) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<size_t> dist(lower_bound, upper_bound);

		return dist(gen);
	}

	size_t hash_function(const K& key) {
		return ((key * a) % size_t(pow(2, w))) >> (w - _degree_of_two);
	}

public:

	HashTable() : _data(NULL), _size(0) { }

	HashTable(size_t degree_of_two) : _degree_of_two(degree_of_two) {
		_data.reserve((size_t(pow(2, _degree_of_two))));
		_size = 0;
	}
	HashTable(const HashTable& other) {
		_data = other._data;
		_size = other._size;
	}
	~HashTable() {
		_data.clear();
	}

	size_t get_capacity() const {
		return _data.capacity();
	}

	size_t get_load() const {
		return _size;
	}

	size_t get_hash(const K& key) {
		return hash_function(key);
	}

};

#endif // !LAB_5_INCLUDE_HASHTABLE_H
