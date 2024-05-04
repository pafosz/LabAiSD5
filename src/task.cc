#include "../include/task.h"

double average_value_number_collisions(size_t size) {
	int sum_collision = 0;
	for (size_t i = 0; i < EXPERIMENTS; ++i) {
		HashTable<std::string, int> electronic_magazine(size, true);
		for (int j = 0; j < NUM_PEOPLES_IN_GROUP; ++j) {
			electronic_magazine.insert(PEOPLES[j], generate_random_int(1, 5));
		}
		sum_collision += electronic_magazine.count_collision();
		electronic_magazine.clear();
	}
	return sum_collision / (EXPERIMENTS);
}

std::vector<double> list_average_collision_values() {
	std::vector<double> list_aver;
	for (int i = 25; i <= 475; i+=50) {
		list_aver.push_back(average_value_number_collisions(i));
	}
	return list_aver;
}

std::vector<std::pair<size_t, double>> ratio_size_to_number_collisions(const std::vector<double>& num_collision) {
	std::vector<std::pair<size_t, double>> ratios(num_collision.size());
	size_t size = 25;
	for (size_t i = 0; i < num_collision.size(); ++i) {
		ratios[i].first = size;
		ratios[i].second = num_collision[i];
		size += 50;
	}
	return ratios;
}