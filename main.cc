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
	std::vector<std::pair<size_t, double>> vec = ratio_size_to_number_collisions(SIZES, list_average_collision_values());
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << "Размер: " << vec[i].first << ", коллизий: " << vec[i].second << endl;
	}
	
	
	
	return 0;
}