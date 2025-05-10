#include <iostream>
#include <vector>

int bin_searche_left(const std::vector<int>& data, int x) {
	int l = 0;
	int r = data.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (data[m] >= x) {
			r = m - 1;
		}	
		else {
			l = m + 1;
		}
	}
	return l;
}

int bin_searche_right(const std::vector<int>& data, int x) {
	int l = 0;
	int r = data.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (data[m] > x) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return l;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> data(n);
	for (auto& x : data) {
		std::cin >> x;
	}
	int k;
	std::cin >> k;
	for (int i = 0; i < k; ++i) {
		int x;
		std::cin >> x;
		if (n == 0) {
			std::cout << "0 0 0" << '\n';
			continue;
		}
		int first = bin_searche_left(data, x);
		int second = bin_searche_right(data, x);

		if (first < data.size() && data[first] == x) {
			std::cout << 1 << " " << first << " " << second << '\n';
		}
		else {
			std::cout << 0 << " " << first << " " << first << '\n';
		}
	}
	return 0;
}
