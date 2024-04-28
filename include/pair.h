#ifndef LAB_5_INCLUDE_PAIR_H
#define LAB_5_INCLUDE_PAIR_H

template<typename K, typename V>
struct Pair {

	K key;
	V value;
	bool not_empty;	

	Pair() : not_empty(false) { }
	Pair(const K& key, const V& value) : key(key), value(value), not_empty(true) { }

	bool operator==(const Pair& other) {
		return key == other.key;
	}

	bool operator!=(const Pair& other) {
		return key != other.key;
	}
};

#endif LAB_5_INCLUDE_PAIR_H