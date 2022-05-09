#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	int m = 1, n = 1;
	while (n <= x) {
		n += m;
		m++;
	}

	int diff = n - x;

	int numerator = m - diff;
	int denominator = diff;
	if (m % 2 == 0) {
		numerator = diff;
		denominator = m - diff;
	}

	cout << numerator << "/" << denominator;

	return 0;
}
