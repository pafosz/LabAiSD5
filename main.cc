#include <iostream>
#include <string>

#include "../include/hash_table.h"
#include "../include/random.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	HashTable<int, int> ht(8);
	for (size_t i = 0; i < 20; ++i) {
		ht.insert(lcg(), generate_random_int(1, 10));
	}
	
	ht.print();
	cout << ht.count_collision();
	

	
	
	
	return 0;
}