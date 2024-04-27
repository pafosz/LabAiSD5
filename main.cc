#include <iostream>
#include <string>

#include "../include/hash_table.h"
#include "../include/random.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	HashTable<int, int> ht(4);
	for (size_t i = 0; i < 10000; ++i) {
		ht.insert_or_assign(lcg(), lcg());
	}
	ht.print();



	return 0;
}