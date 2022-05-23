#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;

	int DP[11];
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	for (int i = 4; i < 11; i++) {
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	}

	int n;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << DP[n] << endl;
	}
}
