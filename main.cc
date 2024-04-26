#include <iostream>
#include <string>

#include "../include/hash_table.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	HashTable<int, int> ht(4);
	ht.insert(3, 4567);
	ht.print();
	
	

	return 0;
}