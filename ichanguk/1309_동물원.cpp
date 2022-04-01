#include <iostream>
using namespace std;

#define MOD 9901
int cage[100001][3] = { 0, };

int main()
{
	int N;
	cin >> N;
	cage[0][0] = 1;
	
	for (int i = 1; i <= N; i++) {
		cage[i][0] = (cage[i - 1][0] + cage[i - 1][1] + cage[i - 1][2]) % MOD;
		cage[i][1] = (cage[i - 1][0] + cage[i - 1][2]) % MOD;
		cage[i][2] = (cage[i - 1][0] + cage[i - 1][1]) % MOD;
	}
	cout << (cage[N][0] + cage[N][1] + cage[N][2]) % MOD << endl;
	return 0;
}
