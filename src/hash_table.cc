#include "../include/hash_table.h"

template<typename K, typename V>
HashTable<K, V>::HashTable(size_t degree_of_two) : _size(size_t(pow(2, degree_of_two))) {
	_data.reserve(size_t(pow(2, degree_of_two)));	
}

template<typename K, typename V>
size_t HashTable<K, V>::get_size() const {
	return _size;
}