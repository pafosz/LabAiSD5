//#include "../include/hash_table.h"

//template<typename K, typename V>
//size_t HashTable<K, V>::hash_function(const K& key) {
//	return key % _size;
//}
//
//template<typename K, typename V>
//HashTable<K, V>::HashTable(): _size(0){}
//
//template<typename K, typename V>
//HashTable<K, V>::HashTable(size_t degree_of_two) : _size(size_t(pow(2, degree_of_two))) {
//	_data = new std::vector<std::pair<K, V>>[_size];
//}
//
//template<typename K, typename V>
//HashTable<K, V>::HashTable(const HashTable& other) {
//	_data = other._data;
//	_size = other._size;
//}
//
//template<typename K, typename V>
//HashTable<K, V>::~HashTable() {
//	delete[] _data;
//}
//
//template<typename K, typename V>
//size_t HashTable<K, V>::get_size() const {
//	return _size;
//}