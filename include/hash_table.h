#ifndef LAB_5_INCLUDE_HASHTABLE_H
#define LAB_5_INCLUDE_HASHTABLE_H

#include <iostream>
#include <vector>

template<typename K, typename V>
class HashTable {
	struct Pair {
		K key;
		V value;
	};
	std::vector<Pair> _data;
	size_t _size;
	static const int LOAD_FACTOR_THRESHOLD = 0.7;

	size_t hash_function(const K& key) {
		const int a;
	}
public:
	HashTable(size_t);
};
#endif // !LAB_5_INCLUDE_HASHTABLE_H
