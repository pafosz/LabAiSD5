#include <iostream>
#include <vector>
#include <bitset>
#include <random>

#include "../include/hash_table.h"
using namespace std;



int main() {

	HashTable<int, int> ht(5);
	cout << ht.get_hash(7);


	return 0;
}