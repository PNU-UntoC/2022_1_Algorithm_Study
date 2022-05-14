#include <iostream>
#include <algorithm>
using namespace std;

int health[21];
int joy[21];
int DP[21][100];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> health[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> joy[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 99; j++) {
			if (j - health[i] >= 0) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - health[i]] + joy[i]);
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}
	cout << DP[N][99] << endl;
	return 0;
}
