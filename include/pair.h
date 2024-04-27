#ifndef LAB_5_INCLUDE_PAIR_H
#define LAB_5_INCLUDE_PAIR_H

template<typename K, typename V>
struct Pair {
	K key;
	V value;
	bool not_empty;	

	Pair() : key(NULL), value(NULL), not_empty(false) { }
	Pair(const K& key, const V& value) : key(key), value(value), not_empty(true) { }

	const K& get_key() const { return key; }
	const V& get_value() const { return value; }

	bool operator==(const Pair& other) {
		return key == other.key;
	}

	bool operator!=(const Pair& other) {
		return key != other.key;
	}

};

#endif LAB_5_INCLUDE_PAIR_H