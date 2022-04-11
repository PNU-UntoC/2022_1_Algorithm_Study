#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int myLeft[10] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> myLeft[i];
	}
	int j = 0;
	int order[10] = { 0, };
	int moreTallCount = 0;
	for (int i = 0; i < N; i++) {
		moreTallCount = 0;
		for (j = 0; j < N; j++) {
			if (moreTallCount == myLeft[i]) {
				break;
			}
			if (order[j] == 0) {
				moreTallCount++;
			}
		}
		for (int k = j; k < N; k++) {
			if (order[k] == 0) {
				order[k] = i + 1;
				break;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << order[i] << ' ';
	}
}
