#include <iostream>
using namespace std;

int main() {
	int input;
	cin >> input;

	int x = input, count = 0;
	do {
		int a = x / 10;
		int b = x % 10;
		int c = (a + b) % 10;
		x = 10 * b + c;

		count++;
	} while (x != input);

	cout << count;
	return 0;
}
