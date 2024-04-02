#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	v.reserve(5);
	v.push_back(1);
	for (auto i : v) {
		cout << i;
	}
	return 0;
}