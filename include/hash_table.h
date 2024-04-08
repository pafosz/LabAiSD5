#ifndef LAB_5_INCLUDE_HASHTABLE_H
#define LAB_5_INCLUDE_HASHTABLE_H

#include <iostream>
#include <vector>
#include <cmath>

#define LOAD_FACTOR_THRESHOLD = 0.7

//template<typename K, typename V>
//struct Pair {
//	K key;
//	V value;
//	Pair(const K& key, const V& value): key(key), value(value){}
//};

//template<typename K, typename V>
class HashTable {
	
	std::vector<std::pair<int, int>> *_data;
	size_t _size;
	static const size_t w = sizeof(int) * 8;

	size_t hash_function(const int&);
public:
	HashTable();
	HashTable(size_t);
	HashTable(const HashTable&);
	~HashTable();
	
	size_t get_size() const;
	
};

#endif // !LAB_5_INCLUDE_HASHTABLE_H
