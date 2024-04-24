#ifndef LAB_5_INCLUDE_HASHTABLE_H
#define LAB_5_INCLUDE_HASHTABLE_H

#include <iostream>
#include <vector>

#include "../include/random.h"
#include "../include/pair.h"

#define LOAD_FACTOR_THRESHOLD = 0.7

template<typename K, typename V>
class HashTable {
	
	std::vector<Pair<K, V>> _data;
	size_t _size;
	size_t _degree_of_two;
	
	int hash_function(const K& key);

	static size_t _a;
	static size_t _w;

public:
	
	HashTable(size_t degree_of_two);

	HashTable(const HashTable& other);

	HashTable& operator=(const HashTable& other);

	~HashTable();

	size_t get_capacity() const;

	size_t get_load() const;

	int get_hash(const K& key);

	void print() const;

	void grow();

	void insert(const K& key, const V& value);

	void insert_or_assign(const K& key, const V& value);

	bool contains(const V& value) const;

	const Pair<K, V>* search(const K& key) const;

	//Pair* find(const K& key) const;

	bool erase(const K& key);

	int count(const K& key) const; //возвращает количество элементов по соответствующему ключу
};

template<typename K, typename V>
size_t HashTable<K, V>::_a = (Random::random(0, pow(2, _w)) | 1);

template<typename K, typename V>
size_t HashTable<K, V>::_w = sizeof(K) * 8;

template<typename K, typename V>
HashTable<K, V>::HashTable(size_t degree_of_two) : _degree_of_two(degree_of_two) {
	_data.reserve((size_t(pow(2, _degree_of_two))));
	_size = 0;	
}

template<typename K, typename V>
HashTable<K, V>::HashTable(const HashTable& other) {
	_data = other._data;
	_size = other._size;
	_degree_of_two = other._degree_of_two;
}

template<typename K, typename V>
HashTable<K, V>& HashTable<K, V>::operator=(const HashTable& other) {
	if (this == &other) return *this;
	_data = other._data;
	_size = other._size;
	_degree_of_two = other._degree_of_two;
}

template<typename K, typename V>
HashTable<K, V>::~HashTable() {
	_data.clear();
	_size = 0;
	_degree_of_two = 0;
}

template<typename K, typename V>
size_t HashTable<K, V>::get_capacity() const {
	return _data.capacity();
}

template<typename K, typename V>
size_t HashTable<K, V>::get_load() const {
	return _size;
}

template<typename K, typename V>
int HashTable<K, V>::get_hash(const K& key) {
	return hash_function(key);
}

template<typename K, typename V>
int HashTable<K, V>::hash_function(const K& key) {
	return ((key * _a) % size_t(pow(2, _w))) >> (_w - _degree_of_two);
}

template<typename K, typename V>
const Pair<K, V>* HashTable<K, V>::search(const K& key) const {
	if (!_size) return nullptr;
	size_t index = hash_function(key);
	if (_data[index].not_empty && _data[index].key == key) {
		return &_data[index];
	}
	return nullptr;
}

//template<typename K, typename V>
//HashTable<K, V>::Pair* HashTable<K, V>::find(const K& key) const {
//	if (!_size) return nullptr;
//	size_t index = hash_function(key);
//	if (_data[index])
//}

template<typename K, typename V>
void HashTable<K, V>::grow() {
	
}

template<typename K, typename V>
void HashTable<K, V>::insert(const K& key, const V& value) {

}

#endif // !LAB_5_INCLUDE_HASHTABLE_H
