#ifndef LAB_5_INCLUDE_HASHTABLE_H
#define LAB_5_INCLUDE_HASHTABLE_H

#include <iostream>
#include <vector>

#include "../include/random.h"
#include "../include/pair.h"

const double LOAD_FACTOR_THRESHOLD = 0.7;

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

	void clear();

	size_t get_capacity() const;

	size_t get_load() const;

	size_t get_hash(const K& key);

	void print();

	void grow();

	void insert(const K& key, const V& value);

	void insert_or_assign(const K& key, const V& value);

	bool vcontains(const V& value) const;

	bool kcontains(const K& key);

	V* search(const K& key);

	bool erase(const K& key);

	int count_collision();
};

template<typename K, typename V>
int HashTable<K, V>::count_collision() {
	if (!_size) return 0;
	int collision = 0;
	for (size_t i = 0; i < _data.size(); ++i) {
		if (_data[i].not_empty) {
			size_t index = hash_function(_data[i].key);
			size_t start = index;

			do {
				if (index == i) index = (index + 1) % get_capacity();
				if (_data[index].not_empty && (get_hash(_data[index].key) == start)) {
					collision++;
					index = (index + 1) % get_capacity();
				}
				else break;
			} while (index != start);
		}
	}
	return collision;
}

template<typename K, typename V>
size_t HashTable<K, V>::_a = (random(0, static_cast<size_t>(pow(2, _w))) | 1);

template<typename K, typename V>
size_t HashTable<K, V>::_w = sizeof(K) * 8;

template<typename K, typename V>
HashTable<K, V>::HashTable(size_t degree_of_two) : _degree_of_two(degree_of_two) {
	_data.resize((size_t(pow(2, _degree_of_two))));
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
void HashTable<K, V>::clear() {
	_data.clear();
	_size = 0;
	_degree_of_two = 0;
}

template<typename K, typename V>
HashTable<K, V>::~HashTable() {
	clear();
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
	return ((std::hash<K>{}(key) * _a) % size_t(pow(2, _w))) >> (_w - _degree_of_two);
}

template<typename K, typename V>
V* HashTable<K, V>::search(const K& key) {
	if (!_size) throw std::invalid_argument("[search] the table is empty");
	size_t index = hash_function(key);
	size_t start = index;
	do {
		if (_data[index].key == key) return &_data[index].value;
		index = (index + 1) % get_capacity();
	} while (_data[index].not_empty && index != start);
	return nullptr;	
}

template<typename K, typename V>
bool HashTable<K, V>::vcontains(const V& value) const {
	if (!_size) return false;
	for (const auto& pair : _data) {
		if (pair.value == value) {
			return true;
		}
	}
	return false;
}

template<typename K, typename V>
bool HashTable<K, V>::kcontains(const K& key) {
	if (!_size) return false;
	size_t index = hash_function(key);
	size_t start = index;
	do {
		if (_data[index].key == key) return true;
		index = (index + 1) % get_capacity();
	} while (_data[index].not_empty && index != start);
	return false;
}

template<typename K, typename V>
void HashTable<K, V>::grow() {
	std::vector<Pair<K, V>> old_table = _data;
	_data.clear();
	_data.resize(get_capacity() * 2, Pair<K, V>());
	_degree_of_two++;
	_size = 0;
	for (const auto& pair : old_table) {
		if (pair.not_empty) {
			insert(pair.key, pair.value);
		}
	}
}

template<typename K, typename V>
void HashTable<K, V>::insert(const K& key, const V& value) {
	if ((static_cast<double>(_size) / get_capacity()) > LOAD_FACTOR_THRESHOLD)
		grow();
	size_t index = hash_function(key);
	size_t start = index;	
	
	do {
		if (kcontains(key)) throw std::invalid_argument("[insert] Insertion using an existing key is not possible");
		if (!_data[index].not_empty) {
			_data[index] = Pair<K, V>(key, value);
			_size++;
			return;
		}
		index = (index + 1) % get_capacity();
	} while (index != start);	
}

template<typename K, typename V>
void HashTable<K, V>::insert_or_assign(const K& key, const V& value) {
	if (!kcontains(key)) {
		insert(key, value);
		return;
	}
	V* old_value = search(key);
	*old_value = value;	
}

template<typename K, typename V>
bool HashTable<K, V>::erase(const K& key) {
	if (!_size) return false;
	if (!kcontains(key)) return false;
	size_t index = hash_function(key);
	size_t start = index;
	do {		
		if (_data[index].key == key) {
			if (!_data[index + 1].not_empty) {
				_data[index] = Pair<K, V>();
				return true;
			}
			_data[index].value = -1;
			_data[index].key = -1;
			return true;
		}
		index = (index + 1) % get_capacity();
	} while (_data[index].not_empty && index != start);
	return false;
}

template<typename K, typename V>
void HashTable<K, V>::print() {
	if (!_size) throw std::invalid_argument("[print] hash table is empty");
	std::cout << "Хэш-таблица" << std::endl;
	for (size_t i = 0; i < _data.size(); ++i) {
		std::cout << "Хэш " << i << ": ";
		if (!_data[i].not_empty) std::cout << "Null" << std::endl;
		else std::cout << "Ключ: " << _data[i].key << ", значение: " << _data[i].value << std::endl;
	}
	std::cout << std::endl;
}

#endif // !LAB_5_INCLUDE_HASHTABLE_H
