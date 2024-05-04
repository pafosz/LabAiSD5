#include <iostream>
#include <string>

#include "../include/hash_table.h"
#include "../include/random.h"
#include "../include/task.h"
using namespace std;

template<typename T>
void vprint(const std::vector<T>& vec) {
	for (auto v : vec) {
		cout << v << " ";
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	std::vector<std::pair<size_t, double>> vec = ratio_size_to_number_collisions(list_average_collision_values());
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << "������: " << vec[i].first << ", ��������: " << vec[i].second << endl;
	}
	HashTable<string, size_t> ht(5, true);
	cout << "������ ������� ��� �������� " << ht.get_capacity() << endl;
	ht.insert("Ilya", 86);
	ht.insert("Masha", 34);
	ht.insert("Dasha", 94);
	ht.insert("Sasha", 9);
	cout << "������������� ����� ���������� 4�� " << ht.get_load() << endl;
	ht.insert("Vika", 64);
	ht.insert("Lena", 72);
	cout << "������������� ����� ���������� 6�� " << ht.get_load() << endl 
		<< "������ ������� ����� ���������� 6�� " << ht.get_capacity() << endl;
	ht.insert("Lera", 84);
	ht.insert("Ksusha", 14);
	ht.insert("Nika", 95);
	cout << "���������� �������� " << ht.count_collision() << endl;
	ht.print();

	cout << ht.vcontains(86) << endl << ht.kcontains("Vika") << endl;

	HashTable<string, size_t> ht1(ht);
	cout << "����� ������ �������: " << endl;
	ht1.print();

	ht1.erase("Nika");

	ht1.print();

	HashTable<double, string> ht2(3);
	ht2.insert(2.5, "$");
	ht2.insert(250.23, "p");
	ht2.print();
	
	
	return 0;
}