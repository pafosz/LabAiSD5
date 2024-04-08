#include <iostream>
#include <vector>
#include <bitset>
#include <random>
#include "../include/hash_table.h"
using namespace std;

int main() {

	HashTable ht(2);
	cout << ht.get_size();
	
	
	
	
	
	
	/*random_device rd;
	mt19937 gen(rd());

	int num;
	
	do {
		num = gen() | 1;
	} while (num >= 0 && num % 2 == 0);
	cout << num << " binary: " << bitset<sizeof(int) * 8>(num);*/
	/*for (size_t i = 0; i < 20; i++) {
		cout << (gen() | 1) << endl;
	}*/

	/*int x = 45987845;
	bitset<sizeof(int) * 8> binary(x);
	cout << "Num " << x << " in binary sistem: " << binary << endl;

	int res = (x >> 8);
	cout << "Shift num x by 2 bits: " << res << " in binary sistem: " << bitset<sizeof(int) * 8>(res); */
	
	return 0;
}