#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int T;
	cin >> T;
	int res[301] = { 0, };

	int aNum, bNum, cNum;
	int isNormal;
	int aCheck[1000] = { 0, };
	int bCheck[1000] = { 0, };
	int cCheck[1000] = { 0, };
	int j = 0;

	for (int i = 1; i <= a + b + c; i++) {
		res[i] = 2;
	}
	for (int i = 0; i < T; i++) {
		cin >> aNum >> bNum >> cNum >> isNormal;
		if (isNormal) {
			res[aNum] = 1;
			res[bNum] = 1;
			res[cNum] = 1;
		}
		else {
			aCheck[j] = aNum;
			bCheck[j] = bNum;
			cCheck[j] = cNum;
			j++;
		}
	}
	int A, B, C;
	for (int i = 0; i < j; i++) {
		A = res[aCheck[i]];
		B = res[bCheck[i]];
		C = res[cCheck[i]];

		if (A == 2 && B == 1 && C == 1) {
			res[aCheck[i]] = 0;
		}
		else if (A == 1 && B == 2 && C == 1) {
			res[bCheck[i]] = 0;
		}
		else if (A == 1 && B == 1 && C == 2) {
			res[cCheck[i]] = 0;
		}
	}
	for (int i = 1; i <= a + b + c; i++) {
		cout << res[i] << endl;
	}
}
