#include "../include/hash_table.h"

template<typename K, typename V>
HashTable<K, V>::HashTable(size_t size) : _size(size) {
	_data.reserve(size);
}