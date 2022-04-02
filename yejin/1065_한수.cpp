#include <iostream>

bool func(int x);	// 한수 판별 함수

int main() {
	int N;
	std::cin >> N;

	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (func(i)) count++;
	}

	std::cout << count;

	return 0;
}

bool func(int x) {
	int diff, diff_b;	// diff, diff before
	bool first = true;

	while (x / 10 != 0) {
		int a = x % 10;
		int b = (x / 10) % 10;
		diff = a - b;

		if (!first && diff != diff_b) return false;	// 한수가 아니므로 함수 종료

		diff_b = diff;
		x /= 10;

		if (first) first = false;
	}

	return true;
}
