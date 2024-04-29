#include "../include/task.h"

double average_value_number_collisions(size_t size) {
	int sum_collision = 0;
	for (size_t i = 0; i < EXPERIMENTS; ++i) {
		HashTable<int, int> electronic_magazine(size);
		for (size_t j = 0; j < NUM_PEOPLES_IN_GROUP; ++j) {
			electronic_magazine.insert(j, generate_random_int(1, 5));
		}
		sum_collision += electronic_magazine.count_collision();
		electronic_magazine.clear();
	}
	return sum_collision / static_cast<double>(EXPERIMENTS);
}

std::vector<double> list_average_collision_values() {
	std::vector<double> list_aver;
	for (size_t i = 0; i < SIZES.size(); ++i) {
		list_aver.push_back(average_value_number_collisions(SIZES[i]));
	}
	return list_aver;
}

std::vector<std::pair<size_t, double>> ratio_size_to_number_collisions(const std::vector<size_t>& size_table, const std::vector<double>& num_collision) {
	std::vector<std::pair<size_t, double>> ratios(size_table.size());
	for (size_t i = 0; i < size_table.size(); ++i) {
		ratios[i].first = pow(2, size_table[i]);
		ratios[i].second = num_collision[i];
	}
	return ratios;
}