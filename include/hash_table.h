#ifndef LAB_5_INCLUDE_HASHTABLE_H
#define LAB_5_INCLUDE_HASHTABLE_H

#include <iostream>
#include <vector>

#include "../include/random.h"
#include "../include/pair.h"

template<typename K, typename V>
class HashTable {
	
	std::vector<Pair<K, V>> _data;
	size_t _size;
	size_t _degree_of_two;
	
	size_t hash_function(const K& key);

	static size_t _a;
	static size_t _w;

public:
	
	HashTable(size_t degree_of_two);

	HashTable(const HashTable& other);

	HashTable& operator=(const HashTable& other);

	~HashTable();

	size_t get_capacity() const;

	size_t get_load() const;

	size_t get_hash(const K& key);

	void print() const;

	void grow();

	void insert(const K& key, const V& value);

	void insert_or_assign(const K& key, const V& value);

	bool contains(const V& value) const;

	const Pair<K, V>& search(const K& key) const;

	//Pair* find(const K& key) const;

	bool erase(const K& key);

	int count(const K& key) const; //возвращает количество элементов по соответствующему ключу
};

template<typename K, typename V>
size_t HashTable<K, V>::_a = (Random::random(0, static_cast<size_t>(pow(2, _w))) | 1);

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
size_t HashTable<K, V>::get_hash(const K& key) {
	return hash_function(key);
}

template<typename K, typename V>
size_t HashTable<K, V>::hash_function(const K& key) {
	return ((key * _a) % size_t(pow(2, _w))) >> (_w - _degree_of_two);
}

template<typename K, typename V>
const Pair<K, V>& HashTable<K, V>::search(const K& key) const {
	if (!_size) return nullptr;
	size_t index = hash_function(key);
	size_t start = index;
	do {
		if (_data[index].not_empty && _data[index].key == key) {
			return &_data[index];
		}
		index = (index + 1) % get_capacity();
	} while (_data[index].not_empty && index != start);
	
	return nullptr;
}

template<typename K, typename V>
void HashTable<K, V>::grow() {
	std::vector<Pair<K, V>> old_table = _data;
	_data.clear();
	_data.resize(get_capacity() * 2, Pair<K, V>());
	_size = 0;
	for (const auto& pair : old_table) {
		if (pair.not_empty) {
			insert(pair.get_key(), pair.get_value());
		}
	}
}

template<typename K, typename V>
void HashTable<K, V>::insert(const K& key, const V& value) {
	const double LOAD_FACTOR_THRESHOLD = 0.7;
	if ((static_cast<double>(_size) / get_capacity()) > LOAD_FACTOR_THRESHOLD)
		grow();
	size_t index = hash_function(key);
	size_t start = index;	
	
	do {
		if (search(key) != nullptr) throw std::invalid_argument("[insert] Insertion using an existing key is not possible");
		if (!_data[index].not_empty) {
			_data[index] = Pair<K, V>(key, value);
			_size++;
			return;
		}
		index = (index + 1) % get_capacity();
	} while (_data[index].not_empty && index != start);	
}

template<typename K, typename V>
void HashTable<K, V>::print() const {
	if (!_size) throw std::invalid_argument("[print] hash table is empty");
	for (const auto& pair : _data) {
		if (pair.not_empty) {
			std::cout << "Ключ: " << pair.get_key() << ", значение: " << pair.get_value() << std::endl;
		}
	}
	std::cout << std::endl;
}

#endif // !LAB_5_INCLUDE_HASHTABLE_H
