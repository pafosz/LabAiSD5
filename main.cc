#include <iostream>
#include <string>

#include "../include/hash_table.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	HashTable<int, string> ht(4);
	int key = 3;
	cout << "���������������: " << ht.get_capacity() << endl 
		<< "������: " << ht.get_load() << endl 
		<< "��� ��� ����� " << key << " = " << ht.get_hash(key) << endl;
	
	

	return 0;
}