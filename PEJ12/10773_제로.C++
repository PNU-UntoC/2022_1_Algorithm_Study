#include <iostream>
using namespace std;

int main(void) {
	int size;
	cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}
	for (int i = 0; i < size; i++) {
		if (array[i] == 0) {
			for (int j = i - 1; j >= 0; j--) {
				if (array[j] != 0) {
					array[j] = 0;
					break;

				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	cout << sum;
	return 0;
}
