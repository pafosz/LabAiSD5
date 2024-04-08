#include "../include/hash_table.h"

//template<typename K, typename V>
size_t HashTable::hash_function(const int& key) {
	return key % _size;
}

//template<typename K, typename V>
HashTable::HashTable(): _data(nullptr), _size(0){}

//template<typename K, typename V>
HashTable::HashTable(size_t degree_of_two) : _size(size_t(pow(2, degree_of_two))) {
	_data = new std::vector<std::pair<int, int>>[_size];
}

//template<typename K, typename V>
HashTable::HashTable(const HashTable& other) {
	_data = other._data;
	_size = other._size;
}

//template<typename K, typename V>
HashTable::~HashTable() {
	delete[] _data;
}

//template<typename K, typename V>
size_t HashTable::get_size() const {
	return _size;
}