#include <iostream>
#include <cmath>

template <typename T>
T cos(T x, int ts) {
	T res = 0;
	T t = 1;

	for (int n = 1; n <= ts; ++n) {
		res += t;

		t *= -(x * x) / ((2 * n - 1)*(2 * n));
	}
	return res;
}

template <typename T>
T sin(T x, int ts) {
	T res = 0;
	T t = x;

	for (int n = 1; n <= ts; ++n) {
		res += t;

		t *= -(x * x) / ((2 * n) * (2 * n + 1));
	}
	return res;
}

int main() {
	int ts = 15;
	float x = 3.0;
	std::cout << cos(x, ts) << std::endl;
	std::cout << sin(x, ts) << std::endl;
	std::cout << cos(x) << std::endl;
	std::cout << sin(x) << std::endl;
	return 0;
}