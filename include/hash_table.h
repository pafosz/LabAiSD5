#ifndef LAB_5_INCLUDE_HASHTABLE_H
#define LAB_5_INCLUDE_HASHTABLE_H

#include <iostream>
#include <vector>
#include <cmath>

#define LOAD_FACTOR_THRESHOLD = 0.7
/**
 * @brief  Описание класса
 * @param В конструкторе в качестве размера таблицы задаётся число, которое будет являться степенью двойки
 * 
**/
template<typename K, typename V>
class HashTable {
	struct Pair {
		K key;
		V value;
	};
	std::vector<Pair> _data;
	size_t _size;
	static const size_t w = sizeof(K) * 8;

	size_t hash_function(const K& key) {
		
	}
public:
	HashTable(size_t);
	size_t get_size() const;
	
};

#endif // !LAB_5_INCLUDE_HASHTABLE_H
